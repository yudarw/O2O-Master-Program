#include "CoppeliaForm1.h"

using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace OfflineProgram;

float ur10_pos[6];
void coppeliasim_teleoperation(void *);
void tool_calibration(float pos[6], float new_pos[6]);

void CoppeliaForm::coppelia_connect(){
	bool state = sim.connect(19999);
	if (state) {
		ur10.init("UR10");
		Sleep(100);
		ur10.readPosition(ur10_pos);
		printf("\nCoppeliaSim Connection Success!!! \n");
		printf("Robot position = %.3f,%.3f,%.3f,%.3f,%.3f,%.3f \n", ur10_pos[0], ur10_pos[1], ur10_pos[2], ur10_pos[3], ur10_pos[4], ur10_pos[5]);
	}

	if (!haptic.connected) {
		haptic.init();
	}
}

void CoppeliaForm::start_teleoperation() {
	_beginthread(coppeliasim_teleoperation, 0, NULL);
}

void CoppeliaForm::btn_tcp_calibration() {
	float current_pos[6];
	float calibrated_pos[6];
	
	ur10.readPosition(current_pos);

	tool_calibration(current_pos, calibrated_pos);
}

float goal_pos[6];
// -- Teleoperation Method 2 --
// ///////////////////////////////////////////////////////////////////////
void coppeliasim_teleoperation(void *) {
	printf("oke\n");
	// Load the controller parameter
	bool orientationIsLocked = true;
	double dT = 20;			// ms
	double Ts = dT / 1000;	// s
	double hapticPos[6];
	float  robotPos[6];
	float  robotForce[6];
	float  Fcal[6];
	Vector3d Xr, Xh, Xs, Xm, Xs0, Xh0, Xcs;
	Vector3d Xr_rot, Xh_rot, Xcs_rot;
	Vector3d Xm_vel, Xs_vel, Xm_prev, prev_Xr, Xr_prev, prev_Xh;
	Vector3d Fcs, Fcm, Fe, Fext, prev_Fe;
	Vector3d master_position_control;
	Vector3d master_force_control;
	Vector3d master_sum_integral;
	Vector3d slave_position_control;
	Vector3d slave_force_control;
	Vector3d slave_force_integral;
	Vector3d FeFiltered, prev_FeFiltered;
	Vector3d Taue;
	Vector3d refPosError, last_refPosError, derivativeRefPosError;

	//Set initial value
	prev_Xh.setZero();
	prev_Xr.setZero();
	Xm_prev.setZero();
	Xr_prev.setZero();
	prev_Fe.setZero();
	master_sum_integral.setZero();
	slave_force_integral.setZero();
	prev_FeFiltered.setZero();
	last_refPosError.setZero();

	ur10.setSpeed(100);

	haptic_jog_mode = true;
	while (haptic_jog_mode) {
		// Get position and force data of the robot and haptic device
		haptic.getPosition(hapticPos);
		ur10.readPosition(ur10_pos);

		float new_pos[6];
		tool_calibration(ur10_pos, new_pos);
		//dataPos pos = yrc.read_cartesianPos(0);
		//WacohRead(robotForce);
		//gravity_compensation(pos, global_robot_force, Fcal);

		// Get robot position and acceleration:
		Xr << new_pos[0], new_pos[1], new_pos[2];
		Xr_rot << new_pos[3], new_pos[4], new_pos[5];
		Xh << hapticPos[0], hapticPos[1], hapticPos[2];
		Xh_rot << hapticPos[3], hapticPos[4], hapticPos[5];
		Fe << Fcal[0], Fcal[1], Fcal[2];
		Taue << Fcal[3], Fcal[4], Fcal[5];
		Xm_vel = (Xh - prev_Xh) / Ts;
		Xs_vel = (Xr - prev_Xr) / Ts;

		MatrixXd param_stiffness = getDiagMatrix(Vector3d(stiffness_val, stiffness_val, stiffness_val));
		MatrixXd param_damping = getDiagMatrix(Vector3d(0.0004, 0.0004, 0.0004));
		MatrixXd param_impedance = getDiagMatrix(Vector3d(0.05, 0.05, 0.05));


		// Check button state
		int haptic_button = haptic.getButtonState();
		if (haptic_button == 2) {
			Sleep(300);
			if (teleoperationIsActive == false) {
				teleoperationIsActive = true;
				Xs0 = Xr;
				Xh0 = Xh;
			}
			else {
				teleoperationIsActive = false;
				setHapticForces(Vector3d(0, 0, 0));
			}
		}
		else if (haptic_button == 1) {
			Sleep(300);
			if (orientationIsLocked == false) {
				orientationIsLocked = true;
			}
			else {
				orientationIsLocked = false;
			}
		}

		// -- If teleoperation is active --
		if (teleoperationIsActive) {
			// Teleoperation Control:
			Xm = Xs0 + ((Xh - Xh0) * 3);		// Master robot position
			Xs = Xr;					// Slave  robot position


			refPosError = (Xs - Xm);

			master_position_control = (0.025 * (Xs - Xm));
			//Fcm = master_position_control + master_force_control;
			Fcm = master_position_control;
			setHapticForces(Fcm);

			if (orientationIsLocked) Xcs_rot = Xr_rot;
			else Xcs_rot = Xh_rot;
			//setRobotPosition(Xm, Xcs_rot);

			// Convert the orientation:
			Vector3d ur10_rotation = rot2euler(Xh_rot);

			goal_pos[0] = Xm[0];
			goal_pos[1] = Xm[1];
			goal_pos[2] = Xm[2];
			goal_pos[3] = ur10_rotation[0];
			goal_pos[4] = ur10_rotation[1];
			goal_pos[5] = ur10_rotation[2];
			ur10.setPosition(goal_pos, false);
		}

		prev_Xh = Xh;
		prev_Xr = Xr;
		printf("oke\n");
		Sleep(dT);
	}
}


void tool_calibration(float pos[6], float new_pos[6]) {
	Vector3d offset_pos(0, 0, 80);
	Vector3d offset_ori(0, 0, 0);
	Vector3d EE_pos(pos[0], pos[1], pos[2]);
	Vector3d EE_rot(pos[3], pos[4], pos[5]);
	Vector3d EE_rot2 = euler2rot(EE_rot);

	// Rotation of Tool relative to End-Effector:
	MatrixXd R_TE = getRotationMatrix(offset_ori);
	// Transformation matrix of Tool relative to End-Effector:
	MatrixXd T_TE = get4x4TransformMatrix(R_TE, offset_pos);

	// Rotation of EE relative to Base:
	MatrixXd R_EB = getRotationMatrix(EE_rot2);
	MatrixXd T_EB = get4x4TransformMatrix(R_EB, EE_pos);
	
	// Print Matrix:
	cout << "Original Position: " << endl<< EE_pos << endl << endl;
	cout << "Original Orientation: " << endl << EE_rot << endl << endl;
	cout << "Transformation matrix of the TOOL:" << endl << T_TE << endl << endl;
	cout << "Transformation matrix of the TCP:" << endl << T_EB << endl;

	MatrixXd new_mat = matrix_mul(T_EB, T_TE);
	MatrixXd new_rot_mat = extract_rot_matrix(new_mat);
	Vector3d new_pos2 = extract_pos_vector(new_mat);
	Vector3d new_ori = getRotationAngle(new_rot_mat);
	Vector3d new_ori_euler = rot2euler(new_ori);
	cout << "Result after calibration:" << endl << new_ori_euler << endl << new_pos2 << endl;

	new_pos[0] = new_pos2[0];
	new_pos[1] = new_pos2[1];
	new_pos[2] = new_pos2[2];
	new_pos[3] = new_ori_euler[0];
	new_pos[4] = new_ori_euler[1];
	new_pos[5] = new_ori_euler[2];
}

void thread_control_targetPos(void *) {

	while (1) {
		float targetPos[6], workpiecePos[6];
		ur10.readObjectPosition("/UR10/targetPos2", targetPos);
		ur10.readObjectPosition("/Workpiece", workpiecePos);
		printf("Target Pos    : %.3f,%.3f,%.3f,%.3f,%.3f,%.3f\n", targetPos[0], targetPos[1], targetPos[2], targetPos[3], targetPos[4], targetPos[5]);
		printf("Workpiece Pos : %.3f,%.3f,%.3f,%.3f,%.3f,%.3f\n", workpiecePos[0], workpiecePos[1], workpiecePos[2], workpiecePos[3], workpiecePos[4], workpiecePos[5]);
		ur10.setPosition(targetPos, false);
		Sleep(50);
	}
}

void CoppeliaForm::btn_test_program() {
	_beginthread(thread_control_targetPos, 0, NULL);
}
















// ========================================================= //
//		Interface to Connect with Roboguide					 //
// ========================================================= //

vector<pos_t> ref_pos;

void CoppeliaForm::btn_roboguide_connect() {
	roboguide.connect("127.0.0.1");
}


void CoppeliaForm::btn_record_center_user_frame() {
	roboguide.refresh();
	DataPos pos = roboguide.read_currentPos();
	printf("Current robot pos: %.3f, %.3f, %.3f, %.3f, %.3f, %.3f \n", pos.X, pos.Y, pos.Z, pos.W, pos.P, pos.R);
	
	tbX->Text = pos.X.ToString("N3");
	tbY->Text = pos.Y.ToString("N3");
	tbZ->Text = pos.Z.ToString("N3");
	tbW->Text = pos.W.ToString("N3");
	tbP->Text = pos.P.ToString("N3");
	tbR->Text = pos.R.ToString("N3");
}


void generate_trajectory();



// Calibration:
void CoppeliaForm::btn_test_calibration() {
	/*
	double px = p0.X;
	double py = p0.Y;
	double pz = p0.Z;
	double xr2 = p1.X;
	double yr2 = p1.Y;
	double zr2 = p1.Z;
	double xr3 = p2.X;
	double yr3 = p2.Y;
	double zr3 = p2.Z;
	// Compute Orientation
	double phi = atan2(yr2 - py, xr2 - px);
	double tetha = atan2(pz - zr2, (yr2 - py) / sin(phi));
	double psi = 0.000;
	// Apply calibration result
	pos.X = px;
	pos.Y = py;
	pos.Z = pz;
	pos.W = psi * (180 / 3.14);
	pos.P = tetha * (180 / 3.14);
	pos.R = phi * (180 / 3.14);
	*/

	// New three-point-calculation:
	//Vector3d pos1(p0.X, p0.Y, p0.Z);
	//Vector3d pos2(p1.X, p1.Y, p1.Z);
	//Vector3d pos3(p2.X, p2.Y, p2.Z);

	Vector3d pos1(414.4, -100.6, -0.9);
	Vector3d pos2(734.4, -25.3, 88.7);
	Vector3d pos3(344.7, 311.5, -64.7);


	double phi = atan2(pos2[1] - pos1[1], pos2[0] - pos1[0]);
	double tetha = atan2(pos1[2] - pos2[2], (pos2[1] - pos1[1]) / Math::Sin(phi));

	double angle_phi = phi * (180 / 3.14);
	double angle_tetha = tetha * (180 / 3.14);

	Vector3d v1 = pos2 - pos1;
	double sum_sqrt = sqrt(v1[0] * v1[0] + v1[1] * v1[1] + v1[2] * v1[2]);
	v1 /= sum_sqrt;

	Vector3d v2 = pos3 - pos1;
	sum_sqrt = sqrt(v2[0] * v2[0] + v2[1] * v2[1] + v2[2] * v2[2]);
	v2 /= sum_sqrt;

	Vector3d v3;
	v3[0] = v1[1] * v2[2] - v2[1] * v1[2];
	v3[1] = v1[2] * v2[0] - v2[2] * v1[0];
	v3[2] = v1[0] * v2[1] - v2[0] * v1[1];
	sum_sqrt = sqrt(v3[0] * v3[0] + v3[1] * v3[1] + v3[2] * v3[2]);
	v3 /= sum_sqrt;

	if (v3[2] < 0) v3 *= -1;

	Vector3d v4;
	v4[0] = v3[1] * v1[2] - v1[1] * v3[2];
	v4[1] = v3[2] * v1[0] - v1[2] * v3[0];
	v4[2] = v3[0] * v1[1] - v1[0] * v3[1];
	sum_sqrt = sqrt(v4[0] * v4[0] + v4[1] * v4[1] + v4[2] * v4[2]);
	v4 /= sum_sqrt;

	double Z1dotZ0 = v3[2];
	double Y1dotZ0 = v4[2];
	double X1dotZ0 = v1[2];
	double sin_psi = Y1dotZ0 / cos(tetha);
	double psi = asin(sin_psi);

	//printf("%.3f, %.3f, %.3f \n", v4[0], v4[1], v4[2]);
	printf("%.3f, %.3f, %.3f\n", phi, tetha, psi);


}


void compute_transformation() {

	// Generate the TAB:
	// Sudut R-AB merupakan sudut pada workpiece, bisa diperoleh dari hasil calibrasi.
	Vector3d angle_AB(0, 0, 0);					// Sudut user frame yg diperoleh dari hasil kalibrasi
	MatrixXd R_AB = getRotationMatrix(angle_AB);
	Vector3d P_AB(279, -337.6, 63);			// Posisi center user frame
											// Generate transformation matrix from A to B:
	MatrixXd TAB = get4x4TransformMatrix(R_AB, P_AB);

	cout << "Transformation matrix TAB:" << endl;
	cout << TAB << endl << endl;

	// Data posisi dan orientasi yang diperoleh disini adalah dari
	// data yg ke-record di reference trajectory
	// =======================================================================
	// Generate the TBC:
	Vector3d angle_BC(-180, 0, 0);
	MatrixXd R_BC = getRotationMatrix(angle_BC);
	Vector3d P_BC(100.0, 100.0, 0);
	MatrixXd TBC = get4x4TransformMatrix(R_BC, P_BC);


	// Posisi ini merupakan offset dari center of calibration plane ke robot object
	// Hanya translasi, perubahan orientasi = 0
	// =======================================================================
	// Generate the TBC:
	Vector3d angle_CD(0, 0, 0);
	MatrixXd RCD = getRotationMatrix(angle_CD);
	Vector3d PCD(100.0, -100.0, 0);
	MatrixXd TCD = get4x4TransformMatrix(RCD, PCD);

	MatrixXd TAC = matrix_mul(TAB, TBC);
	MatrixXd TAD = matrix_mul(TAC, TCD);

	cout << "Transformation Matrix TAC: " << endl;
	cout << TAD << endl << endl;

	MatrixXd RAD = extract_rot_matrix(TAD);
	Vector3d angle_AD = getRotationAngle(RAD);
	cout << "Final angle: " << endl << angle_AD << endl;

}

pos_t set_data_pos(double x, double y, double z, double w, double p, double r) {
	pos_t pos;
	pos.X = x;
	pos.Y = y;
	pos.Z = z;
	pos.W = w;
	pos.P = p;
	pos.R = r;
	return pos;
}

void generate_trajectory() {
	pos_t pos;
	pos = set_data_pos(0, 0, 0, -180, 0, 45);
	ref_pos.push_back(pos);
	pos = set_data_pos(0, 100, 0, -180, 0, 45);
	ref_pos.push_back(pos);
	pos = set_data_pos(100, 100, 0, -180, 0, 45);
	ref_pos.push_back(pos);
	pos = set_data_pos(100, 0, 0, -180, 0, 45);
	ref_pos.push_back(pos);

	for (int i = 0; i < ref_pos.size(); i++) {
		printf("Trajectory=%.3f,%.3f,%.3f\n", ref_pos[i].X, ref_pos[i].Y, ref_pos[i].Z);
	}
}