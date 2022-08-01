#include "GlobalVariable.h"

double standby_pos[6] = { 610, 153, 35, 90, 85 };
double home_pos[6] = { 377, -8, 182, 179, 0, 0 };

typedef struct {
	float km, bm, ks, bs, kim, kfpm, kfps, kfis;
	MatrixXd Km, Bm, Ks, Bs, Kim, Kfpm, Kfps, Kfis;
}Param;

Param mSetting;
double alpha = 0.2;

bool doTeleoperation = false;
bool teleoperationIsActive = false;
bool applyGuidance = false;
bool haptic_jog_mode = false;
bool trajectoryIsRunning = false;
Vector3d haptic_start_pos;

// ====================================================== //
//	Prototype Function
// ====================================================== //
void thread_simTeleoperation(void *);
void gravity_compensation(dataPos pos, float __Fe[6], float __Fm[6]);
double low_pass_filter(double x, double prev_y, double alpha);
MatrixXd getDiagMatrix(Vector3d vec);

// ////////////////////////////////////////////////////////////////////
dataPos arrayToDatapos(double pos[6]) {
	dataPos newpos;
	newpos.X = pos[0];
	newpos.Y = pos[1];
	newpos.Z = pos[2];
	newpos.W = pos[3];
	newpos.P = pos[4];
	newpos.R = pos[5];
	newpos.TOOL = 8;
	newpos.TYPE = 1;
	return newpos;
}


// -- load configuration file --
void load_config_file() {
	string line;
	ifstream file("config.ini");
	if (file.is_open()) {

		cout << ">>> Load configuration files:" << endl;
		// First Line
		getline(file, line);
		trajectory_file_path = line;
		trajectory_file_name = trajectory_file_path;
		cout << line << endl;

		// Second line
		getline(file, line);
		yaskawa_ip = line;
		cout << "YASKAWA IP Address: " << line << endl;

		// Third line
		getline(file, line);
		roboguide_ip = line;
		cout << "Roboguide IP Address: " << line << endl;

		// Serial COM (F/T Sensor)
		getline(file, line);
		serialComPort = line;
		cout << "Serial COM Port: " << line << endl;

		// Stiffness value
		getline(file, line);
		stiffness_val = stof(line);
		cout << "Impedance value:" << line << endl;
		// Impedance value
		getline(file, line);
		impedance_val = stof(line);
		cout << "Impedance value:" << line << endl << endl;

	
	}
	else {
		printf("Failed to open the file!\n");
	}
}

// -- save configuration file --
void save_config_file() {
	ofstream file("config.ini");
	if (file.is_open()) {
		file << trajectory_file_path << endl;
		file << yaskawa_ip << endl;
		file << roboguide_ip << endl;
		file << serialComPort << endl;
		file << stiffness_val << endl;
		file << impedance_val << endl;
	}
	else {
		printf("Failed to open the file! \n");
	}
}


// -- Thread for updating the robot data --
void thread_update_robot_data(void *) {
	while (1) {
		if (yrc.isConnected && !haptic_jog_mode) {
			//yw_global_pos = yrc.read_cartesianPos(0);
		}
		if (wacoh_isConnected) {
			WacohRead(global_robot_force);
		}
		Sleep(100);
	}
}


// -- Load Trajectory File --
vector<pos_t> load_trajectory(string filepath) {
	vector<pos_t> loaded_data;
	pos_t pos;
	const char * delim = ",";
	string line;
	float posVar[12];
	ifstream file(filepath);
	if (file.is_open()) {
		while (getline(file, line)) {
			char *token = strtok(const_cast<char*>(line.c_str()), delim);
			int index = 0;
			while (token != nullptr) {
				posVar[index] = stof(token);
				token = strtok(nullptr, delim);
				index++;
			}
			pos.X = posVar[0];
			pos.Y = posVar[1];
			pos.Z = posVar[2];
			pos.W = posVar[3];
			pos.P = posVar[4];
			pos.R = posVar[5];
			loaded_data.push_back(pos);
		}
		file.close();
	}
	return loaded_data;
}

// -- Print the trajectory data -- 
void print_trajectory(vector<pos_t> pos) {
	int max = pos.size();
	printf("\n>Print trajectory data: \n");
	for (int i = 0; i < max; i++) {
		printf("Position [%d] = %.3f   %.3f   %.3f   %.3f   %.3f   %.3f\n",
			i, pos[i].X, pos[i].Y, pos[i].Z, pos[i].W, pos[i].P,pos[i].R);
	}
}

// Convertion data:
pos_t ConvertToPost(dataPos ywpos) {
	pos_t pos;
	pos.X = ywpos.X;
	pos.Y = ywpos.Y;
	pos.Z = ywpos.Z;
	pos.W = ywpos.W;
	pos.P = ywpos.P;
	pos.R = ywpos.R;
	return pos;
}

// -- Convert pos_t to dataPos
dataPos ConvertToDataPos(pos_t pos) {
	dataPos datapos;
	datapos.X = pos.X;
	datapos.Y = pos.Y;
	datapos.Z = pos.Z;
	datapos.W = pos.W;
	datapos.P = pos.P;
	datapos.R = pos.R;
	datapos.TYPE = 1;
	datapos.TOOL = 8;
	return datapos;
}

// Convertion data:
pos_t rgConvertToPost(DataPos ywpos) {
	pos_t pos;
	pos.X = ywpos.X;
	pos.Y = ywpos.Y;
	pos.Z = ywpos.Z;
	pos.W = ywpos.W;
	pos.P = ywpos.P;
	pos.R = ywpos.R;
	return pos;
}



// -- Trajectory Calibration -- //
// Normalize the recorded trajectory to get the (0,0) origin:
vector<pos_t> trajectory_setToZero(vector<pos_t> pos) {
	vector<pos_t> new_pos;
	Vector3d P1, Pn, Pn_prime;
	P1[0] = pos[0].X;
	P1[1] = pos[0].Y;
	P1[2] = pos[0].Z;
	int pos_size = pos.size();
	for (int i = 0; i < pos_size; i++) {
		Pn[0] = pos[i].X;
		Pn[1] = pos[i].Y;
		Pn[2] = pos[i].Z;
		Pn_prime = Pn - P1;
		pos_t temp = pos[i];
		temp.X = Pn_prime[0];
		temp.Y = Pn_prime[1];
		temp.Z = Pn_prime[2];
		new_pos.push_back(temp);
	}
	return new_pos;
}


// -- Calibrate Trajectory -- //
vector<pos_t> calibrate_trajectory(vector<pos_t> pos) {
	int pSize = pos.size();
	vector<pos_t> calibrated_pos;
	//int org_index = 0;
	
	// Get the origin point from the origin register:
	Vector3d Pab(origin[org_index].data.X, origin[org_index].data.Y, origin[org_index].data.Z);
	Vector3d Rab(origin[org_index].data.W, origin[org_index].data.P, origin[org_index].data.R);
	
	Vector3d P_centerOffset(origin[org_index].centerpos_offset.X, origin[org_index].centerpos_offset.Y, origin[org_index].centerpos_offset.Z);
	
	/*
	for (int i = 0; i < pSize; i++) {
		Vector3d Pbc(pos[i].X, pos[i].Y, pos[i].Z);
		Vector3d Rbc(pos[i].W, pos[i].P, pos[i].R);
		// Solve rotation matrix
		MatrixXd T_Org = getRotationMatrix(Rbc);
		MatrixXd T_Diff = getRotationMatrix(Rab);
		MatrixXd T_new = T_Diff * T_Org;
		Vector3d new_angle = getRotationAngle(T_new);
		// Solve the translation
		Vector3d Pac = Pab + (T_Diff * Pbc);

		pos_t newPos = pos[i];
		newPos.X = Pac[0];
		newPos.Y = Pac[1];
		newPos.Z = Pac[2];
		newPos.W = new_angle[0];
		newPos.P = new_angle[1];
		newPos.R = new_angle[2];

		calibrated_pos.push_back(newPos);
	}
	*/

	// New Calibration Method:
	Vector3d angle_AB(Rab[0], Rab[1], Rab[2]);		// Sudut user frame yg diperoleh dari hasil kalibrasi
	MatrixXd R_AB = getRotationMatrix(angle_AB);
	Vector3d P_AB(Pab[0], Pab[1], Pab[2]);			// Posisi center user frame
	MatrixXd TAB = get4x4TransformMatrix(R_AB, P_AB);

	// Offset from center of the user frame:
	Vector3d angle_CD(0, 0, 0);						// No orientation error only translation
	MatrixXd RCD = getRotationMatrix(angle_CD);
	Vector3d PCD(P_centerOffset[0], P_centerOffset[1], P_centerOffset[2]);					// Let say the error of the translation is (100, -100)
	MatrixXd TCD = get4x4TransformMatrix(RCD, PCD);

	for (int i = 0; i < pSize; i++) {
		
		Vector3d Pbc(pos[i].X, pos[i].Y, pos[i].Z);
		Vector3d Rbc(pos[i].W, pos[i].P, pos[i].R);
		
		// Retrieve the normalized trajectory data:
		Vector3d angle_BC(Rbc[0], Rbc[1], Rbc[2]);
		MatrixXd R_BC = getRotationMatrix(angle_BC);
		Vector3d P_BC(Pbc[0], Pbc[1], Pbc[2]);
		MatrixXd TBC = get4x4TransformMatrix(R_BC, P_BC);

		MatrixXd TAC = matrix_mul(TAB, TBC);
		MatrixXd TAD = matrix_mul(TAC, TCD);

		MatrixXd R_AD = extract_rot_matrix(TAD);
		Vector3d angle_AD = getRotationAngle(R_AD);
		Vector3d P_AD = extract_pos_vector(TAD);
		
		pos_t newPos = pos[i];
		newPos.X = P_AD[0];
		newPos.Y = P_AD[1];
		newPos.Z = P_AD[2];
		newPos.W = angle_AD[0];
		newPos.P = angle_AD[1];
		newPos.R = angle_AD[2];

		calibrated_pos.push_back(newPos);	 
	}

	return calibrated_pos;
}

// -- Save Trajectory into CSV file -- //
void save_trajectory(string filepath, vector<pos_t> pos) {
	char str[128];
	int n = pos.size();
	ofstream file(filepath);
	if (file.is_open()) {
		cout << "> Save trajectory file to: " << filepath << endl;
		for (int i = 0; i < n; i++) {
			sprintf(str, "%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%d,%d,%d,%d,%d,%d",
				pos[i].X, pos[i].Y, pos[i].Z, pos[i].W, pos[i].P, pos[i].R, 1, 8);
			file << str << endl;
		}
		file.close();
	}
	else {
		cout << "> Error when opening the CSV file." << endl;
	}
}



// -- Save Origin Data -- // 
void save_origin_data() {
	char str[256];
	int n = 10;
	ofstream file("origin.ini");
	if (file.is_open()) {
		cout << "> Save origin data " << endl;
		for (int i = 0; i < n; i++) {
			if (origin[i].comment == "") {
				origin[i].comment = "___";
			}
			sprintf(str, "%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%s",
				origin[i].data.X, origin[i].data.Y, origin[i].data.Z, origin[i].data.W, origin[i].data.P, origin[i].data.R,
				origin[i].centerpos.X, origin[i].centerpos.Y, origin[i].centerpos.Z,
				origin[i].xpos.X, origin[i].xpos.Y, origin[i].xpos.Z,
				origin[i].ypos.X, origin[i].ypos.Y, origin[i].ypos.Z,
				origin[i].centerpos_offset.X, origin[i].centerpos_offset.Y, origin[i].centerpos_offset.Z,
				origin[i].comment.c_str()
				);
			file << str << endl;
		}
		file.close();
	}
	else {
		cout << "> Error when opening the CSV file." << endl;
	}
}

// -- Load Origin Data --
void load_origin_data() {
	vector<pos_t> loaded_data;
	pos_t data, centerpos, xpos, ypos;
	origin_t org;
	string comment;
	const char * delim = ",";
	string line;
	float temp[18];
	int step = 0;
	ifstream file("origin.ini");
	if (file.is_open()) {
		while (getline(file, line)) {
			char *token = strtok(const_cast<char*>(line.c_str()), delim);
			for (int i = 0; i < 18; i++) {
				temp[i] = stof(token);
				token = strtok(nullptr, delim);
			}

			if (token == nullptr)
				org.comment = "___";
			else
				org.comment = token;

			token = strtok(nullptr, delim);
			// Assign the data to register:
			org.data.X = temp[0];
			org.data.Y = temp[1];
			org.data.Z = temp[2];
			org.data.W = temp[3];
			org.data.P = temp[4];
			org.data.R = temp[5];
			org.centerpos.X = temp[6];
			org.centerpos.Y = temp[7];
			org.centerpos.Z = temp[8];
			org.xpos.X = temp[9];
			org.xpos.Y = temp[10];
			org.xpos.Z = temp[11];
			org.ypos.X = temp[12];
			org.ypos.Y = temp[13];
			org.ypos.Z = temp[14];
			org.centerpos_offset.X = temp[15];
			org.centerpos_offset.Y = temp[16];
			org.centerpos_offset.Z = temp[17];
			
			origin[step] = org;
			step++;
		}
		file.close();
	}
}


// Sequence Programming
// -- Save Trajectory into CSV file -- //
void save_sequence_program(string filepath) {
	char str[128];
	ofstream file(filepath);
	int n = tab.program_data.size();
	if (file.is_open()) {
		for (int i = 0; i < n; i++) {
			int cmd = tab.program_data[i].command;
			int moveType = tab.program_data[i].moveType;
			int wait = tab.program_data[i].wait;
			int posRegNum =tab.program_data[i].posRegNum;
			double speed = tab.program_data[i].speed;
			string datastring = tab.program_data[i].dataString;
			sprintf(str, "#%d,%d,%d,%d,%.2f,%s", cmd, moveType, wait, posRegNum, speed, datastring.c_str());
			file << str << endl;
		}
		for (int i = 0; i < tab.pos_register.size(); i++) {
			pos_t pos = tab.pos_register[i];
			sprintf(str, "@%.3f,%.3f,%.3f,%.3f,%.3f,%.3f", pos.X, pos.Y, pos.Z, pos.W, pos.P, pos.R);
			file << str << endl;
		}

		file.close();
	}
	else {
		cout << "> Error when opening the CSV file." << endl;
	}
}

// -- load sequence program --
int load_sequence_program(string filepath) {
	const char * delim = ",";
	float temp[5];
	string line, id, data;
	ifstream file(filepath);
	Sequence seq;
	pos_t pos;
	tab.program_data.clear();
	tab.pos_register.clear();

	if (file.is_open()) {
		while (getline(file, line)) {
			id = line.substr(0, 1);
			if (id == "#") {
				data = line.substr(1);
				char *token = strtok(const_cast<char*>(data.c_str()), delim);
				for (int i = 0; i < 5; i++) {
					temp[i] = stof(token);
					token = strtok(nullptr, delim);
				}
				seq.command = int(temp[0]);
				seq.moveType = int(temp[1]);
				seq.wait = int(temp[2]);
				seq.posRegNum = int(temp[3]);
				seq.speed = double(temp[4]);
				if (token == nullptr)
					seq.dataString = "";
				else
					seq.dataString = token;

				tab.program_data.push_back(seq);
			}

			if (id == "@") {
				data = line.substr(1);
				char *token = strtok(const_cast<char*>(data.c_str()), delim);
				for (int i = 0; i < 5; i++) {
					temp[i] = stof(token);
					token = strtok(nullptr, delim);
				}
				pos.X = temp[0];
				pos.Y = temp[1];
				pos.Z = temp[2];
				pos.W = temp[3];
				pos.P = temp[4];
				pos.R = temp[5];
				tab.pos_register.push_back(pos);
			}
			
		}
		return 1;
	}
	else {
		printf("Failed to open program file!");
		return 0;
	}
}






// ////////////////////////////////////////////////////////////////////////////////
// -- Teleoperation Controller Funtion --
// ////////////////////////////////////////////////////////////////////////////////

// Save controller parameter setting 
void save_controller_parameter() {
	ofstream file("ImpedanceConfig.ini");
	if (file.is_open()) {
		file << "Km=" << mSetting.km << endl;
		file << "Bm=" << mSetting.bm << endl;                                             
		file << "Ks=" << mSetting.ks << endl;
		file << "Bs=" << mSetting.bs << endl;
		file << "Kim=" << mSetting.kim << endl;
		file << "Kfpm=" << mSetting.kfpm << endl;
		file << "Kfps=" << mSetting.Kfps << endl;
		file << "Kfis=" << mSetting.kfis << endl;
	}
	file.close();
	cout << "Save configuration file is done" << endl;
}

// -- Load PID parameter settings --
Param load_controller_parameter() {
	Param param;
	string line, token;
	ifstream file("ImpedanceConfig.ini");
	vector<string> point;
	dataPos pos;
	if (file.is_open()) {
		while (getline(file, line)) {
			token = line.substr(0, line.find("="));
			if (token == "Km") {
				token = line.substr(line.find("=") + 1);
				param.km = stof(token);
			}
			else if (token == "Bm") {
				token = line.substr(line.find("=") + 1);
				param.bm = stof(token);
			}
			else if (token == "Ks") {
				token = line.substr(line.find("=") + 1);
				param.ks = stof(token);
			}
			else if (token == "Bs") {
				token = line.substr(line.find("=") + 1);
				param.bs = stof(token);
			}
			else if (token == "Kim") {
				token = line.substr(line.find("=") + 1);
				param.kim = stof(token);
			}
			else if (token == "Kfpm") {
				token = line.substr(line.find("=") + 1);
				param.kfpm = stof(token);
			}
			else if (token == "Kfps") {
				token = line.substr(line.find("=") + 1);
				param.kfps = stof(token);
			}
			else if (token == "Kfis") {
				token = line.substr(line.find("=") + 1);
				param.kfis = stof(token);
			}
		}
		// Set the diagonal matrix
		param.Km = getDiagMatrix(Vector3d(param.km, param.km, param.km));
		param.Bm = getDiagMatrix(Vector3d(param.bm, param.bm, param.bm));
		param.Ks = getDiagMatrix(Vector3d(param.ks, param.ks, param.ks));
		param.Bs = getDiagMatrix(Vector3d(param.bs, param.bs, param.bs));
		param.Kim = getDiagMatrix(Vector3d(param.kim, param.kim, param.kim));
		param.Kfpm = getDiagMatrix(Vector3d(param.kfpm / 3, param.kfpm / 3, param.kfpm));
		param.Kfps = getDiagMatrix(Vector3d(param.kfps, param.kfps, param.kfps));
		param.Kfis = getDiagMatrix(Vector3d(param.kfis, param.kfis, param.kfis));
		file.close();
	}
	else {
		cout << "Failed to open configuration file!!!" << endl;
	}
	return param;
}

// -- Get Diagonal Matrix Value --
MatrixXd getDiagMatrix(Vector3d vec) {
	Matrix3d M;
	M << vec[0], 0, 0,
		0, vec[1], 0,
		0, 0, vec[2];
	return M;
}

// -- Set diagonal matrix --
void get_parameter_config() {
	mSetting.Km = getDiagMatrix(Vector3d(mSetting.km, mSetting.km, mSetting.km));
	mSetting.Bm = getDiagMatrix(Vector3d(mSetting.bm, mSetting.bm, mSetting.bm));
	mSetting.Ks = getDiagMatrix(Vector3d(mSetting.ks, mSetting.ks, mSetting.ks));
	mSetting.Bs = getDiagMatrix(Vector3d(mSetting.bs, mSetting.bs, mSetting.bs));
	mSetting.Kim = getDiagMatrix(Vector3d(mSetting.kim, mSetting.kim, mSetting.kim));
	mSetting.Kfpm = getDiagMatrix(Vector3d(mSetting.kfpm, mSetting.kfpm, mSetting.kfpm));
	mSetting.Kfps = getDiagMatrix(Vector3d(mSetting.kfps, mSetting.kfps, mSetting.kfps));
	mSetting.Kfis = getDiagMatrix(Vector3d(mSetting.kfis, mSetting.kfis, mSetting.kfis));

}

// -- Set Haptic Feedback Force -- //
void setHapticForces(Vector3d fh) {
	float f[3] = { fh[0], fh[1], fh[2] };
	haptic.setForces(f);
}

// -- Set Robot Position -- //
void setRobotPosition(Vector3d pos, Vector3d rot) {
	dataPos goalPos;
	goalPos.X = pos[0];
	goalPos.Y = pos[1];
	goalPos.Z = pos[2];
	goalPos.W = rot[0];
	goalPos.P = rot[1];
	goalPos.R = rot[2];
	goalPos.TOOL = 8;
	goalPos.TYPE = 1;
	yrc.moveL(goalPos, 30);
}

// -- Bilateral Teleoperation Method --
// ======================================================
// Mode 0 : Default Teleoperation Mode

void thread_simTeleoperation(void *) {
	// Load the controller parameter
	mSetting = load_controller_parameter();

	bool orientationIsLocked = true;
	applyGuidance = false;
	double dT = 100;		// ms
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

	get_parameter_config();

	cout << "\nStart teleoperation...\n";
	while (haptic_jog_mode) {
		// Get position and force data of the robot and haptic device
		haptic.getPosition(hapticPos);
		dataPos pos = yrc.read_cartesianPos(0);
		//WacohRead(robotForce);
		//gravity_compensation(pos, global_robot_force, Fcal);

		// Get robot position and acceleration:
		Xr		<< pos.X, pos.Y, pos.Z;
		Xr_rot	<< pos.W, pos.P, pos.R;
		Xh		<< hapticPos[0], hapticPos[1], hapticPos[2];
		Xh_rot	<< hapticPos[3], hapticPos[4], hapticPos[5];
		Fe		<< Fcal[0], Fcal[1], Fcal[2];
		Taue	<< Fcal[3], Fcal[4], Fcal[5];
		Xm_vel	= (Xh - prev_Xh) / Ts;
		Xs_vel	= (Xr - prev_Xr) / Ts;

		Param param = mSetting;
		MatrixXd param_stiffness = getDiagMatrix(Vector3d(stiffness_val, stiffness_val, stiffness_val));
		MatrixXd param_damping = getDiagMatrix(Vector3d(0.0004, 0.0004, 0.0004));
		MatrixXd param_impedance = getDiagMatrix(Vector3d(0.02, 0.02, 0.02));

		if (wacoh_isConnected == false) Fe.setZero();
		
		// Apply Filter
		//FeFiltered(0) = low_pass_filter(Fe(0), prev_FeFiltered(0), 0.05);
		//FeFiltered(1) = low_pass_filter(Fe(1), prev_FeFiltered(1), 0.05);
		//FeFiltered(2) = low_pass_filter(Fe(2), prev_FeFiltered(2), 0.2);

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

		// Start teleoperation
		if (teleoperationIsActive) {
			// Teleoperation Control:
			Xm = Xs0 + (Xh - Xh0);		// Master robot position
			Xs = Xr;					// Slave  robot position

			// -- Guidance force controller --
			double Kg = 0.08;
			double Bg = 0.0001;
			Vector3d Xd(-149, 607, -346);
			//refPosError = Xd - Xs;
			refPosError = Xh0 - Xh;
			derivativeRefPosError = (refPosError - last_refPosError) / Ts;
			Vector3d gudianceOut = (refPosError * Kg) + (derivativeRefPosError * Bg);

			// -- Compute the master teleoperation controller --
			Vector3d master_pos_error = Xs - Xm;
			master_sum_integral += master_pos_error * Ts;
			//master_position_control = (param.Km * (Xs - Xm)) + (param.Bm * (Xs_vel - Xm_vel)) + param.Kim * master_sum_integral;
			//master_force_control = (param.Kfpm * FeFiltered) + (((FeFiltered - prev_FeFiltered) / Ts) * 0.0001);
			master_position_control = (param_impedance * (Xs - Xm)) + (param_damping * (Xs_vel - Xm_vel));
			//Fcm = master_position_control + master_force_control;
			Fcm = master_position_control;

			/*
			if (applyGuidance)
				Fcm = gudianceOut;
			else
				Fcm = master_position_control + master_force_control;
				*/
			// -- Compute the slave teleoperation controller --
			// Slave Position controller:

			//slave_position_control = (param.Ks * (Xm - Xs)) + (param.Bs * (Xm_vel - Xs_vel));

			slave_position_control = (param_stiffness * (Xm - Xs)) + (param_damping * (Xm_vel - Xs_vel));
			Vector3d Fd(0, 0, 0);
			Vector3d force_error = Fd - Fe;
			slave_force_integral += force_error * Ts;
			slave_force_control = (param.Kfps * force_error) + (param.Kfis * slave_force_integral);
			//Fcs = slave_position_control - slave_force_control;
			Fcs = slave_position_control;

			// Output of the slave Cartesian Controller:
			Xcs = Xs + Fcs;

			//set_graph_data(Fcm[0], Fcm[1], Fcm[2], "Fx", "Fy", "Fz");

			// Action controller
			setHapticForces(Fcm);
			if (orientationIsLocked) Xcs_rot = Xr_rot;
			else Xcs_rot = Xh_rot;
			setRobotPosition(Xcs, Xcs_rot);

			haptic_feedback_force = Fcm;
		}

		// Print data preview:
		printf("%.3f,%.3f,%.3f\n", Fe[2], FeFiltered[2], Fcm[2]);

		// Update Graph Data
		// ============================================
		// Show Graph 1
		//lineGraph[0] = Fe[0];
		//lineGraph[1] = Fe[1];
		//lineGraph[2] = Fe[2];
		// Show Graph 2
		//lineGraph2[0] = Fcm[0];
		//lineGraph2[1] = Fcm[1];
		//lineGraph2[2] = Fcm[2];
		// Show Graph 3
		//lineGraph3[0] = refPosError[0];
		//lineGraph3[1] = refPosError[1];
		//lineGraph3[2] = refPosError[2];

		// update the (t - 1) variables for next iteration:
		prev_Xh = Xh;
		prev_Xr = Xr;
		prev_Fe = Fe;
		prev_FeFiltered = FeFiltered;
		last_refPosError = refPosError;
		Sleep(dT); // Sampling rate
	}
}

// -- Gravity compensation method --
void gravity_compensation(dataPos pos, float __Fe[6], float __Fm[6]) {
	double mass = 1.75;			//kg
	double g = 9.8;
	double l = 0.070;
	double w = mass * g;
	//double w = 14.66;
	//Vector3d offset(6.9, 2.164, 0);
	Vector3d offset(8, 2.164, -1);
	Vector3d _Fe(__Fe[0], __Fe[1], __Fe[2]);
	Vector3d Fe = _Fe - offset;
	Vector3d tau_e(__Fe[3], __Fe[4], __Fe[5]);
	Vector3d base_rot(pos.W, pos.P, pos.R);
	//Vector3d base_rot = euler2rot(euler);
	MatrixXd R_bs = getRotationMatrix(base_rot);
	MatrixXd R_sb = R_bs.transpose();
	Vector3d Fg(0, 0, -w);
	Vector3d F_predict = R_sb * Fg;
	Vector3d Fm = Fe - F_predict;
	Matrix3d p;
	p << 0, -l, 0,
		l, 0, 0,
		0, 0, 0;
	Vector3d tau_predict = p * R_sb * Fg;
	Vector3d tau_m = tau_e - tau_predict;
	// norm to base:
	Vector3d euler_angle = getEulerAngle(R_bs);
	MatrixXd R_euler = getEulerMatrix(euler_angle);
	Vector3d Fm_calibrated = R_euler * Fm;
	Vector3d tau_calibrated = R_euler * tau_m;
	for (int i = 0; i < 3; i++) {
		__Fm[i] = Fm_calibrated[i];
		__Fm[i + 3] = tau_calibrated[i];
	}
}

// -- Exernal force filter --
double low_pass_filter(double x, double prev_y, double alpha) {
	double max = 35;		// We bound the force at 35N
							//double _alpha = alpha;
	double out = (alpha * x) + ((1 - alpha) * prev_y);
	// Set constrain:
	if (out > max) out = max;
	if (out < -max) out = -max;
	return out;
}












// -- Teleoperation Method 1 - Default --
void thread_simTeleoperation_default(void*) {
	// Load the controller parameter
	mSetting = load_controller_parameter();

	bool orientationIsLocked = true;
	applyGuidance = false;
	double dT = 100;		// ms
	double Ts = dT / 1000;	// s
	double hapticPos[6];
	float  robotPos[6];
	float  robotForce[6];
	float  Fcal[6];
	Vector3d Xr, Xh, Xs, Xm, Xs0, Xh0, Xcs;
	Vector3d Xr_rot, Xh_rot, Xcs_rot;
	Vector3d Xs_refOri, Xh_refOri;
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

	get_parameter_config();

	cout << "\nStart teleoperation...\n";
	while (haptic_jog_mode) {
		// Get position and force data of the robot and haptic device
		haptic.getPosition(hapticPos);
		dataPos pos = yrc.read_cartesianPos(0);

		// Get robot position and acceleration:
		Xr << pos.X, pos.Y, pos.Z;
		Xr_rot << pos.W, pos.P, pos.R;
		Xh << hapticPos[0], hapticPos[1], hapticPos[2];
		Xh_rot << hapticPos[3], hapticPos[4], hapticPos[5];
		Fe << Fcal[0], Fcal[1], Fcal[2];
		Taue << Fcal[3], Fcal[4], Fcal[5];
		Xm_vel = (Xh - prev_Xh) / Ts;
		Xs_vel = (Xr - prev_Xr) / Ts;

		Param param = mSetting;
		MatrixXd param_stiffness = getDiagMatrix(Vector3d(stiffness_val, stiffness_val, stiffness_val));
		MatrixXd param_damping = getDiagMatrix(Vector3d(0.0004, 0.0004, 0.0004));
		MatrixXd param_impedance = getDiagMatrix(Vector3d(0.02, 0.02, 0.02));

		if (wacoh_isConnected == false) Fe.setZero();

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
				Xs_refOri = Xr;
				Xh_refOri = Xh;
			}
			else {
				orientationIsLocked = false;
			}
		}

		// Start teleoperation
		if (teleoperationIsActive) {
			// Teleoperation Control:
			Xm = Xs0 + (Xh - Xh0);		// Master robot position
			Xs = Xr;					// Slave  robot position

			double Km, Bm, Ks, Bs;

			Km = 0.05;
			Bm = 0.00015;

			Ks = 0.2;
			Bs = 0.00025;

			// -- Compute the master teleoperation controller --
			Fcm = ((Xs - Xm) * Km) + ((Xs_vel - Xm_vel) * Bm);
			Fcs = ((Xm - Xs) * Ks) + ((Xm_vel - Xs_vel) * Bs);

			// Output of the slave Cartesian Controller:
			Xcs = Xs + Fcs;

			// Orientation Lock: The orientation is the same with current robot orientation
			if (orientationIsLocked) { 
				Xcs_rot = Xr_rot; 
				setHapticForces(Fcm);
				setRobotPosition(Xcs, Xcs_rot);
			}
			else {
				// Displacement of the haptic
				Vector3d posShift = Xh - Xh_refOri;
				printf("Position shift: %.2f  %.2f  %.2f \n", posShift[0], posShift[1], posShift[2]);
				Xcs_rot = Xh_rot;
				setHapticForces(Fcm);
				setRobotPosition(Xcs, Xcs_rot);
			}

			haptic_feedback_force = Fcm;
		}

		// Print data preview:
		//printf("General Teleoperation Method: Fcs = %.2f, %.2f, %.2f \n", Fcs[0], Fcs[1], Fcs[2]);

		// update the (t - 1) variables for next iteration:
		prev_Xh = Xh;
		prev_Xr = Xr;
		prev_Fe = Fe;
		prev_FeFiltered = FeFiltered;
		last_refPosError = refPosError;
		Sleep(dT); // Sampling rate->Text
	}



}

// -- Teleoperation Method 2 --
// ///////////////////////////////////////////////////////////////////////
void thread_simTeleoperation_2(void *) {
	// Load the controller parameter
	mSetting = load_controller_parameter();
	bool orientationIsLocked = true;
	applyGuidance = false;
	double dT = 100;			// ms
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

	get_parameter_config();

	while (haptic_jog_mode) {
		// Get position and force data of the robot and haptic device
		haptic.getPosition(hapticPos);
		dataPos pos = yrc.read_cartesianPos(0);
		//WacohRead(robotForce);
		gravity_compensation(pos, global_robot_force, Fcal);

		// Get robot position and acceleration:
		Xr << pos.X, pos.Y, pos.Z;
		Xr_rot << pos.W, pos.P, pos.R;
		Xh << hapticPos[0], hapticPos[1], hapticPos[2];
		Xh_rot << hapticPos[3], hapticPos[4], hapticPos[5];
		Fe << Fcal[0], Fcal[1], Fcal[2];
		Taue << Fcal[3], Fcal[4], Fcal[5];
		Xm_vel = (Xh - prev_Xh) / Ts;
		Xs_vel = (Xr - prev_Xr) / Ts;
		Param param = mSetting;

		MatrixXd param_stiffness = getDiagMatrix(Vector3d(stiffness_val, stiffness_val, stiffness_val));
		MatrixXd param_damping = getDiagMatrix(Vector3d(0.0004, 0.0004, 0.0004));
		MatrixXd param_impedance = getDiagMatrix(Vector3d(0.05, 0.05, 0.05));

		// Apply Filter
		FeFiltered(0) = low_pass_filter(Fe(0), prev_FeFiltered(0), 0.05);
		FeFiltered(1) = low_pass_filter(Fe(1), prev_FeFiltered(1), 0.05);
		FeFiltered(2) = low_pass_filter(Fe(2), prev_FeFiltered(2), 0.2);

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
			Xm = Xs0 + (Xh - Xh0);		// Master robot position
			Xs = Xr;					// Slave  robot position

			master_position_control = (param_stiffness * (Xs - Xm));
			//Fcm = master_position_control + master_force_control;
			Fcm = master_position_control;
			setHapticForces(Fcm);

			if (orientationIsLocked) Xcs_rot = Xr_rot;
			else Xcs_rot = Xh_rot;
			setRobotPosition(Xm, Xcs_rot);
		}

		Sleep(dT);
	}
}





void thread_impedance(void *) {
	double hpos[6];
	float f[3];
	while (haptic_jog_mode) {
		haptic.getPosition(hpos);
		if (teleoperationIsActive) {
			//double Kg = 0.15;
			double Kg = impedance_val;
			double Ke = 0.04;
			//Vector3d Xd(23, -31, 59);
			Vector3d Xd = haptic_start_pos;
			Vector3d Xh(hpos[0], hpos[1], hpos[2]);
			Vector3d Xe = (Xd - Xh) * Kg;
			Vector3d P = Xe * Ke;
			//printf("> Xe = %.3f,%.3f,%.3f\n", Xe(0), Xe(1), Xe(2));
			f[0] = Xe(0);
			f[1] = Xe(1);
			f[2] = Xe(2);
			haptic.setForces(f);

		}
		else {
			f[0] = 0;
			f[1] = 0;
			f[2] = 0;
			haptic.setForces(f);
		}


		haptic_feedback_force[0] = f[0];
		haptic_feedback_force[1] = f[1];
		haptic_feedback_force[2] = f[2];

		if (abs(haptic_feedback_force[0]) < 0.6) haptic_feedback_force[0] = 0;
		if (abs(haptic_feedback_force[1]) < 0.6) haptic_feedback_force[1] = 0;
		if (abs(haptic_feedback_force[2]) < 0.6) haptic_feedback_force[2] = 0;

		//set_graph_data(f[0], f[1], f[2], "Fx", "Fy", "Fz");
		Sleep(1);
	}
}

// -- Teleoperation Method 3 --
void thread_simTeleoperation_3(void *) {
	_beginthread(thread_impedance, 0, NULL);
	// Load the controller parameter
	mSetting = load_controller_parameter();
	bool orientationIsLocked = true;
	applyGuidance = false;
	double dT = 50;			// ms
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
	// Get configuration
	get_parameter_config();

	while (haptic_jog_mode) {
		// Get position and force data of the robot and haptic device
		haptic.getPosition(hapticPos);
		dataPos pos = yrc.read_cartesianPos(0);
		gravity_compensation(pos, global_robot_force, Fcal);

		// Get robot position and acceleration:
		Xr << pos.X, pos.Y, pos.Z;
		Xr_rot << pos.W, pos.P, pos.R;
		Xh << hapticPos[0], hapticPos[1], hapticPos[2];
		Xh_rot << hapticPos[3], hapticPos[4], hapticPos[5];
		Fe << Fcal[0], Fcal[1], Fcal[2];
		Taue << Fcal[3], Fcal[4], Fcal[5];
		Xm_vel = (Xh - prev_Xh) / Ts;
		Xs_vel = (Xr - prev_Xr) / Ts;
		Param param = mSetting;

		// Apply Filter
		FeFiltered(0) = low_pass_filter(Fe(0), prev_FeFiltered(0), 0.05);
		FeFiltered(1) = low_pass_filter(Fe(1), prev_FeFiltered(1), 0.05);
		FeFiltered(2) = low_pass_filter(Fe(2), prev_FeFiltered(2), 0.2);

		// Check button state
		int haptic_button = haptic.getButtonState();
		if (haptic_button == 2) {
			Sleep(300);
			if (teleoperationIsActive == false) {
				teleoperationIsActive = true;
				Xs0 = Xr;
				Xh0 = Xh;
				haptic_start_pos = Xh;
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

		// Start teleoperation
		if (teleoperationIsActive) {
			// Teleoperation Control:
			Xm = Xs0 + (Xh - Xh0);		// Master robot position
			Xs = Xr;					// Slave  robot position

			// -- Compute the slave teleoperation controller --
			// Slave Position controller:
			slave_position_control = (param.Ks * (Xm - Xs)) + (param.Bs * (Xm_vel - Xs_vel));
			Vector3d Fd(0, 0, 0);
			Vector3d force_error = Fd - Fe;
			slave_force_integral += force_error * Ts;
			slave_force_control = (param.Kfps * force_error) + (param.Kfis * slave_force_integral);
			Fcs = slave_position_control - slave_force_control;
			// Output of the slave Cartesian Controller:
			Xcs = Xs + Fcs;

			//set_graph_data(Fcm[0], Fcm[1], Fcm[2], "Fx", "Fy", "Fz");

			// Action controller
			if (orientationIsLocked) Xcs_rot = Xr_rot;
			else Xcs_rot = Xh_rot;
			setRobotPosition(Xcs, Xcs_rot);
		}

		// Print data preview:
		// printf("> Teleooperation Impedance: %.3f", Fe[2]);

		// update the (t - 1) variables for next iteration:
		prev_Xh = Xh;
		prev_Xr = Xr;
		prev_Fe = Fe;
		prev_FeFiltered = FeFiltered;
		last_refPosError = refPosError;
		Sleep(dT); // Sampling rate
	}
}





// ///////////////////////////////////////////////////////////////////////

void run_trajectory_non_threated() {
	pos_t pos;
	DataPos rgPos;
	int max, i;
	
	printf(">>> Run trajectory in ROBOGUIDE \n");
	
	// Check the Roboguide connection
	if (roboguide.connected)
		printf("Roboguide is connected. \n");
	
	max = tab2.data.size();
	trajectoryIsRunning = true;
	
	i = 0;
	while (trajectoryIsRunning && (i < max)) {
		// Refresh roboguide data:
		roboguide.refresh();
		roboguide.read_currentPos();
		
		pos = tab2.data[i];

		rgPos = roboguide.current_pos;

		rgPos.X = pos.X;
		rgPos.Y = pos.Y;
		rgPos.Z = pos.Z;
		rgPos.W = pos.W;
		rgPos.P = pos.P;
		rgPos.R = pos.R;

		roboguide.moveL(rgPos, 100, CNT);

		printf("> Move Position [%d] = %.3f,%.3f,%.3f,%.3f,%.3f,%.3f\n",
			i, pos.X, pos.Y, pos.Z, pos.W, pos.P, pos.R);
		
		tab2.selected_index = i;

		i++;
		Sleep(50);
	}

	trajectoryIsRunning = false;
}


void run_trajectory(void *) {

	if (!yrc.servoIsActive) yrc.SVON();
	
	pos_t pos;
	trajectoryIsRunning = true;
	int max = tab2.data.size();

	int i = 0;
	while (trajectoryIsRunning && (i < max)) {
		pos = tab2.data[i];
		yrc.moveL(ConvertToDataPos(pos), 35, true);
		printf("> Move Position [%d] = %.3f,%.3f,%.3f,%.3f,%.3f,%.3f\n",
			i, pos.X, pos.Y, pos.Z, pos.W, pos.P, pos.R);
		tab2.selected_index = i;
		i++;
	}
	trajectoryIsRunning = false;

	//dataPos start_pos = arrayToDatapos(standby_pos);
	//yrc.moveL(start_pos, 90, true);
	//dataPos cmd_pos = arrayToDatapos(home_pos);
	//yrc.moveL(cmd_pos, 90, true);
	//yrc.SVOFF();
}

void sequence_run_trajectory(string path, double speed, int wait) {
	vector<pos_t> posdata;
	posdata = load_trajectory(path);
	int max = posdata.size();
	printf("\n> Run trajectory:\n");
	for (int i = 0; i < max; i++) {
		dataPos pos = ConvertToDataPos(posdata[i]);
		printf("> MoveL Position [%d]:%.3f,%.3f,%.3f,%.3f,%.3f,%.3f  Speed:%.1f  Wait:%d\n", i, pos.X, pos.Y, pos.Z, pos.W, pos.P, pos.R, speed, wait);
		yrc.moveL(pos, speed, wait);
	}
}

// Test the program line by line:
void execute_program_line(int i) {
	double speed;
	bool wait;
	dataPos pos;
	int moveType;
	int posRegNum;
	// 1. Add move point command:
	// =======================================================================
	if (tab.program_data[i].command == CMD_ADD_MOVE_POINT) {

		moveType = tab.program_data[i].moveType;
		speed = tab.program_data[i].speed;
		posRegNum = tab.program_data[i].posRegNum;
		pos = ConvertToDataPos(tab.pos_register[posRegNum]);
		if (tab.program_data[i].wait) wait = false;
		else wait = true;

		if (moveType == 0) {
			printf("%d: MoveL Position:%.3f,%.3f,%.3f,%.3f,%.3f,%.3f  Speed:%.1f  Wait:%d\n", i, pos.X, pos.Y, pos.Z, pos.W, pos.P, pos.R, speed, wait);
			

			robot_speed = calibrate_speed(speed_ratio, speed);
			yrc.moveL(pos, robot_speed, wait);
		}

		else if (moveType == 1) {
			printf("%d: MoveJ Position:%.3f,%.3f,%.3f,%.3f,%.3f,%.3f  Speed:%.1f  Wait:%d\n", i, pos.X, pos.Y, pos.Z, pos.W, pos.P, pos.R, speed, wait);

			robot_speed = calibrate_speed(speed_ratio, speed);
			yrc.moveJ(pos, robot_speed);
		}
	}

	// 2. Add trajectory command:
	// =======================================================================
	if (tab.program_data[i].command == CMD_ADD_OFFLINE_TRAJECTORY) {
		printf("%d: CALL_TRAJECTORY [%s]   V=%.1f  Wait=%s",
			i,
			tab.program_data[i].dataString.c_str(),
			tab.program_data[i].speed,
			str_wait[tab.program_data[i].wait].c_str());

		if (tab.program_data[i].wait) wait = false;
		else wait = true;
		speed = tab.program_data[i].speed;

		string path("./Trajectory/" + tab.program_data[i].dataString);
		sequence_run_trajectory(path, tab.program_data[i].speed, wait);
	}
}

// Run the sequence program:
void thread_run_sequence_program(void *) {
	char str[128];
	int size = tab.program_data.size();
	string s_type[2] = { "MOVEL", "MOVEJ" };
	string s_wait[2] = { "TRUE", "FALSE" };

	if (!yrc.servoIsActive) yrc.SVON();
	Sleep(500);

	printf("\n");
	for (int i = 0; i < size; i++) {
		execute_program_line(i);

		if (program_isRunning == false) return;
	}
}


// Run the sequence program:
void print_program_data() {
	char str[128];
	int size = tab.program_data.size();
	string s_type[2] = { "MOVEL", "MOVEJ" };
	string s_wait[2] = { "TRUE", "FALSE" };

	double speed;
	bool wait;
	dataPos pos;
	int moveType;
	int posRegNum;

	printf("\n>>> Load program data: \n");
	for (int i = 0; i < size; i++) {

		// 0. Empty line:
		if (tab.program_data[i].command == CMD_ADD_EMPTY_LINE) {
			printf("%d: \n", i);
		}

		// 1. Add move point command:
		// =======================================================================
		if (tab.program_data[i].command == CMD_ADD_MOVE_POINT) {

			moveType = tab.program_data[i].moveType;
			speed = tab.program_data[i].speed;
			posRegNum = tab.program_data[i].posRegNum;
			pos = ConvertToDataPos(tab.pos_register[posRegNum]);
			if (tab.program_data[i].wait) wait = false;
			else wait = true;

			if (moveType == 0) {
				printf("%d: MoveL Position:%.3f,%.3f,%.3f,%.3f,%.3f,%.3f  Speed:%.1f  Wait:%d\n", i, pos.X, pos.Y, pos.Z, pos.W, pos.P, pos.R, speed, wait);
				//yrc.moveL(pos, speed, wait);
			}

			else if (moveType == 1) {
				printf("%d: MoveJ Position:%.3f,%.3f,%.3f,%.3f,%.3f,%.3f  Speed:%.1f  Wait:%d\n", i, pos.X, pos.Y, pos.Z, pos.W, pos.P, pos.R, speed, wait);
				//yrc.moveJ(pos, speed);
			}
		}

		// 2. Add trajectory command:
		// =======================================================================
		if (tab.program_data[i].command == CMD_ADD_OFFLINE_TRAJECTORY) {
			printf("%d: CALL_TRAJECTORY [%s]   V=%.1f  Wait=%s \n",
				i,
				tab.program_data[i].dataString.c_str(),
				tab.program_data[i].speed,
				str_wait[tab.program_data[i].wait].c_str());
		}
	}
}

double calibrate_speed(int sp_ratio, double sp_in) {
	double sp_out = ((double)sp_ratio / 100) * sp_in;
	return sp_out;
}

//TEST