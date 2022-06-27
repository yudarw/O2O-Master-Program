#include "TrajectoryCalibrationForm.h"
#include "GlobalVariable.h"

using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace OfflineProgram;

void TrajectoryCalibrationForm::update_data(){

	tbPosX->Text = origin[org_index].data.X.ToString("N3");
	tbPosY->Text = origin[org_index].data.Y.ToString("N3");
	tbPosZ->Text = origin[org_index].data.Z.ToString("N3");
	tbPosW->Text = origin[org_index].data.W.ToString("N3");
	tbPosP->Text = origin[org_index].data.P.ToString("N3");
	tbPosR->Text = origin[org_index].data.R.ToString("N3");

	tbSetX->Text = origin[org_index].data.X.ToString("N3");
	tbSetY->Text = origin[org_index].data.Y.ToString("N3");
	tbSetZ->Text = origin[org_index].data.Z.ToString("N3");
	tbSetW->Text = origin[org_index].data.W.ToString("N3");
	tbSetP->Text = origin[org_index].data.P.ToString("N3");
	tbSetR->Text = origin[org_index].data.R.ToString("N3");
	labelComment->Text = gcnew String(origin[org_index].comment.c_str());
	tbComment1->Text   = gcnew String(origin[org_index].comment.c_str());
	tbComment2->Text   = gcnew String(origin[org_index].comment.c_str());

	// Update offset data:
	tbOffsetX->Text = origin[org_index].centerpos_offset.X.ToString("N3");
	tbOffsetY->Text = origin[org_index].centerpos_offset.Y.ToString("N3");
	tbOffsetZ->Text = origin[org_index].centerpos_offset.Z.ToString("N3");

	char str[128];
	sprintf(str, "%d,%d,%d", int (origin[org_index].centerpos.X), int(origin[org_index].centerpos.Y), int(origin[org_index].centerpos.Z));
	label_center->Text = gcnew String(str);
	sprintf(str, "%d,%d,%d", int(origin[org_index].xpos.X), int(origin[org_index].xpos.Y), int(origin[org_index].xpos.Z));
	label_xpos->Text = gcnew String(str);
	sprintf(str, "%d,%d,%d", int(origin[org_index].ypos.X), int(origin[org_index].ypos.Y), int(origin[org_index].ypos.Z));
	label_ypos->Text = gcnew String(str);
}

void TrajectoryCalibrationForm::on_init() {
	org_index = 0;
	comboSelect->SelectedIndex = org_index;
	comboMethod->SelectedIndex = org_index;
	update_data();
}

void TrajectoryCalibrationForm::on_timer() {
	//update_data();
}

void TrajectoryCalibrationForm::update_origin() {
	org_index = comboSelect->SelectedIndex;
	update_data();
}

void TrajectoryCalibrationForm::update_method() {
	
	if (comboMethod->SelectedItem == "DIRECT_ENTRY") {
		groupBox3->Visible = true;
		groupBox1->Visible = false;
	}
	else if (comboMethod->SelectedItem == "THREE_POINT") {
		groupBox3->Visible = false;
		groupBox1->Visible = true;
	}
}


// -- Three Point Method Calibration -- //
// //////////////////////////////////////////////////////////
pos_t three_point_calibration(pos_t p0, pos_t p1, pos_t p2) {
	pos_t pos;

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
	*/

	// New three-point-calculation:
	Vector3d pos1(p0.X, p0.Y, p0.Z);
	Vector3d pos2(p1.X, p1.Y, p1.Z);
	Vector3d pos3(p2.X, p2.Y, p2.Z);

	//Vector3d pos1(414.4, -100.6, -0.9);
	//Vector3d pos2(734.4, -25.3, 88.7);
	//Vector3d pos3(344.7, 311.5, -64.7);


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

	// Apply calibration result
	pos.X = pos1[0];
	pos.Y = pos1[1];
	pos.Z = pos1[2];
	pos.W = psi * (180 / 3.14);
	pos.P = tetha * (180 / 3.14);
	pos.R = phi * (180 / 3.14);

	// Print calibration data:
	printf("\n");
	printf(">>> Three point calibration method: \n");
	printf("Center position   : %.3f, %.3f, %.3f \n", pos1[0], pos1[1], pos1[2]);
	printf("Point in X        : %.3f, %.3f, %.3f \n", pos2[0], pos2[1], pos2[2]);
	printf("Point in Y        : %.3f, %.3f, %.3f \n", pos3[0], pos3[1], pos3[2]);
	printf(">>> Calibration results: \n");
	printf("Calibrated frame  : %.3f, %.3f, %.3f, %.3f, %.3f, %.3f \n", pos.X, pos.Y, pos.Z, pos.W, pos.P, pos.R);

	return pos;
}


void TrajectoryCalibrationForm::btn_apply() {
	pos_t pos;
	if (comboMethod->SelectedItem == "DIRECT_ENTRY") {
		pos_t pos;
		pos.X = Convert::ToDouble(tbSetX->Text);
		pos.Y = Convert::ToDouble(tbSetY->Text);
		pos.Z = Convert::ToDouble(tbSetZ->Text);
		pos.W = Convert::ToDouble(tbSetW->Text);
		pos.P = Convert::ToDouble(tbSetP->Text);
		pos.R = Convert::ToDouble(tbSetR->Text);
		string comment = marshal_as<string>(tbComment1->Text);

		origin[org_index].data = pos;
		origin[org_index].comment = comment;
		
		update_data();
		save_origin_data();
	}
	else if (comboMethod->SelectedItem == "THREE_POINT") {
		pos = three_point_calibration(origin[org_index].centerpos, origin[org_index].xpos, origin[org_index].ypos);

		string comment = marshal_as<string>(tbComment2->Text);
		origin[org_index].data = pos;
		origin[org_index].comment = comment;
		update_data();
		save_origin_data();
	}

	//save_origin_data();
}


void TrajectoryCalibrationForm::set_center_pos(){
	bool robot_connection;

	if (selected_robot == ROBOGUIDE) {
		if (roboguide.connected) robot_connection = true;
		else robot_connection = false;
	}
	else if (selected_robot == YASKAWA) {
		if (yrc.isConnected) robot_connection = true;
		else robot_connection = false;
	}

	if (robot_connection == false) {
		System::Windows::Forms::MessageBox::Show(
			"Record centerpos Error!!! Robot is not connected",
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
		return;
	}

	// If haptic doesn't run, update the position of the robot
	if (!haptic_jog_mode) yrc.read_cartesianPos(0);

	pos_t pos;
	if (selected_robot == ROBOGUIDE) pos = rgConvertToPost(rg_global_pos);
	if (selected_robot == YASKAWA) pos = ConvertToPost(yrc.global_pos);
	origin[org_index].centerpos = pos;

	update_data();
}

void TrajectoryCalibrationForm::set_x_pos(){
	bool robot_connection;

	if (selected_robot == ROBOGUIDE) {
		if (roboguide.connected) robot_connection = true;
		else robot_connection = false;
	}
	else if (selected_robot == YASKAWA) {
		if (yrc.isConnected) robot_connection = true;
		else robot_connection = false;
	}

	if (robot_connection == false) {
		System::Windows::Forms::MessageBox::Show(
			"Record centerpos Error!!! Robot is not connected",
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
		return;
	}

	// If haptic doesn't run, update the position of the robot
	if (!haptic_jog_mode) yrc.read_cartesianPos(0);

	pos_t pos;
	if (selected_robot == ROBOGUIDE) pos = rgConvertToPost(rg_global_pos);
	if (selected_robot == YASKAWA) pos = ConvertToPost(yrc.global_pos);
	origin[org_index].xpos = pos;

	update_data();
}
void TrajectoryCalibrationForm::set_y_pos(){
	bool robot_connection;

	if (selected_robot == ROBOGUIDE) {
		if (roboguide.connected) robot_connection = true;
		else robot_connection = false;
	}
	else if (selected_robot == YASKAWA) {
		if (yrc.isConnected) robot_connection = true;
		else robot_connection = false;
	}

	if (robot_connection == false) {
		System::Windows::Forms::MessageBox::Show(
			"Record centerpos Error!!! Robot is not connected",
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
		return;
	}
	
	// If haptic doesn't run, update the position of the robot
	if (!haptic_jog_mode) yrc.read_cartesianPos(0);

	pos_t pos;
	if (selected_robot == ROBOGUIDE) pos = rgConvertToPost(rg_global_pos);
	if (selected_robot == YASKAWA) pos = ConvertToPost(yrc.global_pos);
	origin[org_index].ypos = pos;

	update_data();
}


void TrajectoryCalibrationForm::btn_read_current_pos() {
	if (!yrc.isConnected) {
		System::Windows::Forms::MessageBox::Show(
			"Record Pos Error!!! Robot is not connected",
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
		return;
	}

	// If haptic doesn't run, update the position of the robot
	if (!haptic_jog_mode) yrc.read_cartesianPos(0);

	pos_t pos = ConvertToPost(yrc.global_pos);
	tbSetX->Text = pos.X.ToString("N3");
	tbSetY->Text = pos.Y.ToString("N3");
	tbSetZ->Text = pos.Z.ToString("N3");
	tbSetW->Text = pos.W.ToString("N3");
	tbSetP->Text = pos.P.ToString("N3");
	tbSetR->Text = pos.R.ToString("N3");
}

void TrajectoryCalibrationForm::btn_move_to_origin() {
	if (!yrc.isConnected) {
		System::Windows::Forms::MessageBox::Show(
			"Move robot failed!!! Robot is not connected",
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
		return;
	}

	int index = comboSelect->SelectedIndex;
	pos_t pos = origin[index].data;
	dataPos curpos = yrc.global_pos;
	curpos.X = pos.X;
	curpos.Y = pos.Y;
	curpos.Z = pos.Z;

	if (!yrc.servoIsActive) yrc.SVON();
	yrc.moveL(curpos, 50, true);
	
	yrc.SVOFF();
}

void TrajectoryCalibrationForm::btn_apply_offset() {
	pos_t pos;
	pos.X = Convert::ToDouble(tbOffsetX->Text);
	pos.Y = Convert::ToDouble(tbOffsetY->Text);
	pos.Z = Convert::ToDouble(tbOffsetZ->Text);
	printf(">>> Offset user frame to the center: %.3f, %.3f, %.3f \n", pos.X, pos.Y, pos.Z);

	origin[org_index].centerpos_offset = pos;
}