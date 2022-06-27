// Add new line command
//TEST~
#include "MainForm.h"
#include "AddWait.h"
#include "AddMovePoint.h"
#include "StatusForm.h"
#include "RecordForm.h"
#include "ModifyPointForm.h"
#include "AddNewProgram.h"
#include "AddCommentForm.h"
#include "SettingForm.h"
#include "GPIOForm.h"
#include "HapticTeleoperationForm.h"
#include "HapticSettingForm.h"
#include "TrajectoryCalibrationForm.h"
#include "AddOfflineTrajectory.h"
#include "CoppeliaForm1.h"
#include "GlobalVariable.h"


using namespace System;
using namespace System::IO;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace OfflineProgram;

int n;

string trajectory_file_name; 
string trajectory_file_path;

string program_file_name;
string program_file_path;

string yaskawa_ip;
string roboguide_ip;
string serialComPort;

int teleoperation_method;
double stiffness_val;
double impedance_val;
int speed_ratio = 50;

// -- Initialization Program -- //
// ==========================================================
void MainForm::on_init() {
	yrc.global_pos.X = 300.067;
	yrc.global_pos.Y = 001.987;
	yrc.global_pos.Z = -18.876;
	yrc.global_pos.W = 178.001;
	yrc.global_pos.P = 000.040;
	yrc.global_pos.R = -60.321;
	// Initialize the selected device
	selected_robot = ROBOGUIDE;
	load_origin_data();

	// -- Update Haptic Mode Selection --
	//comboTeleMethod->SelectedIndex = 2;

	// -- Load configuration file --
	load_config_file();
	update_initialization_data();
	teleoperation_method = 2;

//	_beginthread(show_3d_force, 0, NULL);
}

void MainForm::update_initialization_data() {
	char str[128];
	tab2.data = load_trajectory(trajectory_file_path);
	tab2.total_index = tab2.data.size();

	if (tab2.total_index != 0)
		show_trajectory_table(tab2.data);

	//load_sequence_program(program_file_path);
	//print_program_data();
	//show_program_data();

	//update_tab2_line_number();
	dataGridView1->Rows->Add();

	// -- Program name --
	sprintf(str, "%s [%d/%d]", trajectory_file_name.c_str(), tab2.selected_index, tab2.total_index);
	groupBox4->Text = gcnew String(str);

}

// ========================================================= // 
//							ON TIMER						 //
// ========================================================= //
void MainForm::on_timer() {
	char str[128];

	// -- Updata Roboguide Data --
	if (roboguide.connected) {
		roboguide.refresh();
		rg_global_pos = roboguide.read_currentPos();
		rg_trigger_state = roboguide.read_sdo(1);
	}

	if (trajectoryIsRunning) {
		if (tab2.selected_index > 1) {
			dataGridView2->Rows[tab2.selected_index - 1]->Selected = false;
			dataGridView2->Rows[tab2.selected_index]->Selected = true;
			dataGridView2->FirstDisplayedScrollingRowIndex = tab2.selected_index;
		}
	}

	// -- Update Haptic Teleoperation Button --
	if (haptic_jog_mode)
		btn_hapticTeleoperation->BackColor = System::Drawing::Color::Lime;
	else 
		btn_hapticTeleoperation->BackColor = System::Drawing::Color::FromArgb(0, 192, 192);

	// -- Update the indicator --
	// Robot
	if (yrc.isConnected) indicator_robot->BackColor = System::Drawing::Color::FromArgb(0, 192, 0);
	else indicator_robot->BackColor = System::Drawing::Color::Maroon;
	// Haptic
	if (haptic.connected) indicator_haptic->BackColor = System::Drawing::Color::FromArgb(0, 192, 0);
	else indicator_haptic->BackColor = System::Drawing::Color::Maroon;
	// Sensor
	if (wacoh_isConnected) indicator_ftsensor->BackColor = System::Drawing::Color::FromArgb(0, 192, 0);
	else indicator_ftsensor->BackColor = System::Drawing::Color::Maroon;
	// Alarm
	if (yrc.status[m_Alarm] == 1) indicator_alarm->BackColor = System::Drawing::Color::Red;
	else indicator_alarm->BackColor = System::Drawing::Color::DarkGray;

	// -- Update the Speed Ratio --
	label_speed_ratio->Text = "" + speed_ratio + "%";
}


void MainForm::update_line_number() {
	char str[128];
	tab.index = dataGridView1->CurrentRow->Index;
	tab.total_index = tab.program_data.size();
	sprintf(str, "%s [%d/%d]", program_file_name.c_str(), tab.index, tab.total_index);
	tabel1_name->Text = gcnew String(str);
}

bool MainForm::isFormOpened(String ^ form_name) {
	FormCollection ^ fc = System::Windows::Forms::Application::OpenForms;
	for each (Form ^ form in fc) {
		if (form->Name == form_name)
			return true;
	}
	return false;
}


// ////////////////////////////////////////////////////////////////////
//							MAIN CONTROL BUTTON						 //
// ////////////////////////////////////////////////////////////////////
void MainForm::show_robot_status_form(){
	if (isFormOpened("StatusForm") == false) {
		StatusForm ^ form = gcnew StatusForm;
		form->Show(this);
	}
}

// -- Button Haptic Teleoperation Clicked --
void MainForm::btn_haptic_teleoperation() {
	
	btn_resetConnection();
	
	if (!yrc.isConnected) {
		System::Windows::Forms::MessageBox::Show("Robot is not connected", "Teleoperation error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	if (!haptic.connected) {
		System::Windows::Forms::MessageBox::Show("Haptic is not connected", "Teleoperation error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	if (!haptic_jog_mode) {
		haptic_jog_mode = true;
		if(!yrc.servoIsActive) yrc.SVON();

		printf(">>> Start Teleoperation. Teleoperation Mode=%d \n", teleoperation_method);

		if (teleoperation_method == 0)
			_beginthread(thread_simTeleoperation, 0, NULL);

		else if (teleoperation_method == 1)
			_beginthread(thread_simTeleoperation_2, 0, NULL);

		else if (teleoperation_method == 2)
			_beginthread(thread_simTeleoperation_3, 0, NULL);

	}
	else {
		haptic_jog_mode = false;
		yrc.SVOFF();
	}
}

void MainForm::btn_run_trajectory() {

	run_trajectory_non_threated();
	return;

	if (!trajectoryIsRunning) {
		if (!yrc.isConnected) {
			System::Windows::Forms::MessageBox::Show("Robot is not connected", "Run trajectory error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (tab2.data.size() == 0) {
			System::Windows::Forms::MessageBox::Show("File is empty", "Run trajectiry error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
	
		_beginthread(run_trajectory, 0, NULL);
		save_config_file();

		btnRunTrajectory->Text = "STOP TRAJECTORY";
		btnRunTrajectory->BackColor = System::Drawing::Color::Lime;
	}

	else {
		trajectoryIsRunning = false;
		btnRunTrajectory->Text = "RUN TRAJECTORY";
		btnRunTrajectory->BackColor = System::Drawing::Color::FromArgb(192, 192, 0);
	}

}

void MainForm::save_configuration() {
	save_config_file();
}


// ////////////////////////////////////////////////////////////////////
//					TAB 1: PROGRAM EDITOR							 //
// ////////////////////////////A////////////////////////////////////////

// -- Add move point --
void MainForm::btn_add_move_point() {
	if (isFormOpened("AddMovePoint") == false) {
		editing_mode = LINE_ADD;
		AddMovePoint ^ addForm = gcnew AddMovePoint;
		addForm->Show(this);
	}
}

// -- Add offline trajectory -- 
void MainForm::btn_add_offline_trajectory() {
	if (isFormOpened("AddOfflineTrajectory") == false) {
		editing_mode = LINE_ADD;
		AddOfflineTrajectory ^ form = gcnew AddOfflineTrajectory;
		form->Show(this);
	}
}

// -- Add wait --
void MainForm::btn_add_wait() {
	if (isFormOpened("AddWait") == false) {
		editing_mode = LINE_ADD;
		AddWait ^ form = gcnew AddWait;
		form->Show(this);
	}
}

// -- Add Comment --
void MainForm::btn_add_comment() {
	if (isFormOpened("AddCommentForm") == false) {
		AddCommentForm ^ form = gcnew AddCommentForm;
		form->Show(this);
	}
}

// -- Edit program line by Double Click the Cells -- //
void MainForm::btn_edit_program() {
	if (dataGridView1->RowCount == 0) return;

	tab.selected_index = dataGridView1->CurrentRow->Index;
	editing_mode = LINE_EDIT;
	if (tab.program_data[tab.selected_index].command == CMD_ADD_MOVE_POINT) {
		if (isFormOpened("AddMovePoint") == false) {
			AddMovePoint ^ addForm = gcnew AddMovePoint;
			addForm->Show();
		}
	}
	else if (tab.program_data[tab.selected_index].command == CMD_ADD_OFFLINE_TRAJECTORY) {
		if (isFormOpened("AddOfflineTrajectory") == false) {
			AddOfflineTrajectory ^ form = gcnew AddOfflineTrajectory;
			form->Show(this);
		}
	}
}


// -- Save the Sequence Program --
void MainForm::btn_save_sequence_program() {
	string path;
	saveFileDialog1->Filter = "O2O program file (*.txt)|*.txt";
	saveFileDialog1->Title = "Save Trajectory File";
	saveFileDialog1->InitialDirectory = ".//Trajectory";
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		String ^ filepath = saveFileDialog1->FileName;
		path = marshal_as<string>(filepath);
		save_sequence_program(path);

		String ^ name = Path::GetFileName(filepath);
		program_file_name = marshal_as<string>(name);
		update_line_number();
	}
}


// -- Load the sequence program file --
void MainForm::btn_load_sequence_program() {
	//load_sequence_program("Program.txt");
	string path;
	openFileDialog1->Filter = "O2O program file (*.txt)|*.txt";
	openFileDialog1->Title = "Open Trajectory File";
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		String ^ filepath = openFileDialog1->FileName;
		program_file_path = marshal_as<string>(filepath);
		String ^ names = openFileDialog1->SafeFileName;
		program_file_name = marshal_as<string>(names);

		load_sequence_program(program_file_path);
		print_program_data();
		show_program_data();
		update_line_number();
		/*
		trajectory_file_path = path;
		String ^ names = openFileDialog1->SafeFileName;
		trajectory_file_name = marshal_as<string>(names);
		tab2.data = load_trajectory(path);
		tab2.total_index = tab2.data.size();
		show_trajectory_table(tab2.data);
		update_tab2_line_number();
		*/
	}
}

// -- Show program data on table 1 --
void MainForm::show_program_data() {
	char str[128];
	string s_type[2] = { "MOVE L", "MOVE J" };
	string s_wait[2] = { "TRUE", "FALSE" };

	int command;
	int moveType;
	int wait;
	int posRegNum;
	double speed;
	string comment;
	string dataString;

	int max = tab.program_data.size();
	dataGridView1->Rows->Clear();
	dataGridView1->DataSource = nullptr;
	dataGridView1->Rows->Add(max);
	for (int row = 0; row < max; row++) {
		// Update program data variable
		command = tab.program_data[row].command;
		moveType = tab.program_data[row].moveType;
		wait = tab.program_data[row].wait;
		posRegNum = tab.program_data[row].posRegNum;
		speed = tab.program_data[row].speed;

		// 0. Empy space:
		if (command == CMD_ADD_EMPTY_LINE) {
			dataGridView1->Rows[row]->Cells[0]->Value = row;
		}

		// 1. Add move point:
		else if (command == CMD_ADD_MOVE_POINT) {
			sprintf(str, "%s P[%d]   V=%.1f   Wait=%s",
				s_type[moveType].c_str(), posRegNum, speed, s_wait[wait].c_str());

			dataGridView1->Rows[row]->Cells[0]->Value = row;
			dataGridView1->Rows[row]->Cells[1]->Value = gcnew String(str);
			dataGridView1->Rows[row]->Cells[2]->Value = gcnew String(tab.program_data[row].dataString.c_str());
		}

		else if (command == CMD_ADD_OFFLINE_TRAJECTORY) {
			sprintf(str, "CALL_TRAJECTORY [%s]   V=%.1f  Wait=%s",
				tab.program_data[row].dataString.c_str(), speed, str_wait[wait].c_str());

			dataGridView1->Rows[row]->Cells[0]->Value = row;
			dataGridView1->Rows[row]->Cells[1]->Value = gcnew String(str);
		}

	}
	dataGridView1->Rows->Add();
}

// -- Add New Program File --
void MainForm::btn_add_new_program() {
	/*
	if (isFormOpened("AddNewProgram") == false) {
		AddNewProgram ^ addForm = gcnew AddNewProgram;
		addForm->Show(this);
	}
	*/
	System::Windows::Forms::DialogResult res = System::Windows::Forms::MessageBox::Show(
		"Creating new program. Save current project?",
		"Create new file",
		MessageBoxButtons::YesNoCancel,
		MessageBoxIcon::Information);

	if (res == System::Windows::Forms::DialogResult::Yes) {
		printf("Save current file \n");
		btn_save_sequence_program();
	}

	else if (res == System::Windows::Forms::DialogResult::Cancel) {
		return;
	}

	dataGridView1->Rows->Clear();
	dataGridView1->DataSource = nullptr;
	dataGridView1->Rows->Add();
	tab.program_data.clear();
	tab.pos_register.clear();
	trajectory_file_name = "";
	trajectory_file_path = "";

	char str[128];
	sprintf(str, "NEW_PROJECT.TXT (UNSAVED) [0/0]");
	tabel1_name->Text = gcnew String(str);
}

void MainForm::btn_print() {

	if (dataGridView1->RowCount == 0) return;
	if (!yrc.isConnected) return;
	
	if (!program_isRunning) {
		program_isRunning = true;
		btnRunProgram->BackColor = System::Drawing::Color::Lime;
		btnRunProgram->Text = "STOP PROGRAM";
		_beginthread(thread_run_sequence_program, 0, NULL);
	}
	else {
		program_isRunning = false;
		btnRunProgram->BackColor = System::Drawing::Color::FromArgb(192, 0, 0);
		btnRunProgram->Text = "RUN_PROGRAM";
	}
}



// -- Delete program line --
void MainForm::btn_sequence_delete() {
	if (dataGridView1->RowCount > 0) {
		dataGridView1->Rows->RemoveAt(tab.index);
		tab.program_data.erase(tab.program_data.begin() + tab.index);
		int n = dataGridView1->RowCount;
		for (int i = 0; i < n; i++) {
			dataGridView1->Rows[i]->Cells[0]->Value = i;
		}
	}
}

// -- Insert program line --
void MainForm::btn_sequence_insert() {
	Sequence seq;
	seq.command = 0;
	seq.speed = 0;
	seq.wait = 0;
	seq.moveType = 0;

	dataGridView1->Rows->Insert(tab.index);
	tab.program_data.insert(tab.program_data.begin() + tab.index, seq);
	// Update Line Number
	int num = dataGridView1->RowCount;
	for (int i = 0; i < num; i++) {
		dataGridView1->Rows[i]->Cells[0]->Value = i;
	}
	tab.index++;
	
}

// -- Modify program line --
void MainForm::btn_sequence_modify() {

}

// -- Test program line: --
void MainForm::btn_move_to_program_line() {
	int index = tab.index;
	printf("Index: %d\n", tab.index);
	if (yrc.isConnected == false) {
		printf("> Move robot failed! Robot is not connected! \n");
		return;
	}
	execute_program_line(index);
}


void MainForm::btn_test_io() {
	if (isFormOpened("GPIOForm") == false) {
		GPIOForm ^ form = gcnew GPIOForm;
		form->Show(this);
	}
	//yrc.writeIO();
}



// -- Increase the Speed Ratio --
void MainForm::btn_increase_speed() {
	speed_ratio += 10;
	if (speed_ratio > 100) speed_ratio = 100;

	int speed = calibrate_speed(speed_ratio, 500);
	printf("> Commanded speed: %d \n", speed);
}

void MainForm::btn_decrease_speed() {
	speed_ratio -= 10;
	if (speed_ratio < 10) speed_ratio = 10;

	int speed = calibrate_speed(speed_ratio, 500);
	printf("> Commanded speed: %d \n", speed);
}

//////////////////////////////////////////////////////////////////////////












// ////////////////////////////////////////////////////////////////////////
//							TAB 2: TRAJECTORY EDITOR
// ////////////////////////////////////////////////////////////////////////

// -- Load Trajectory File --
void MainForm::btn_load_trajectory() {
	string path;
	openFileDialog1->Filter = "CSV file (*.CSV)|*.CSV";
	openFileDialog1->Title = "Open Trajectory File";
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		String ^ filepath = openFileDialog1->FileName;
		path = marshal_as<string>(filepath);
		trajectory_file_path = path;
		String ^ names = openFileDialog1->SafeFileName;
		trajectory_file_name = marshal_as<string>(names);
		tab2.data = load_trajectory(path);
		tab2.total_index = tab2.data.size();
		show_trajectory_table(tab2.data);
		update_tab2_line_number();
	}
}

// -- Show data pos in DataGridView Table --
void MainForm::show_trajectory_table(vector<pos_t> pos) {
	char str[32];
	int max_pos = pos.size();
	dataGridView2->DataSource = nullptr;
	dataGridView2->Rows->Clear();
	dataGridView2->Rows->Add(max_pos);
	for (int row = 0; row < max_pos; row++) {
		dataGridView2->Rows[row]->Cells[0]->Value = row;
		sprintf(str, "%.3f", pos[row].X);
		dataGridView2->Rows[row]->Cells[1]->Value = gcnew String (str);
		sprintf(str, "%.3f", pos[row].Y);
		dataGridView2->Rows[row]->Cells[2]->Value = gcnew String(str);
		sprintf(str, "%.3f", pos[row].Z);
		dataGridView2->Rows[row]->Cells[3]->Value = gcnew String(str);
		sprintf(str, "%.3f", pos[row].W);
		dataGridView2->Rows[row]->Cells[4]->Value = gcnew String(str);
		sprintf(str, "%.3f", pos[row].P);
		dataGridView2->Rows[row]->Cells[5]->Value = gcnew String(str);
		sprintf(str, "%.3f", pos[row].R);
		dataGridView2->Rows[row]->Cells[6]->Value = gcnew String(str);
	}
}


// -- Create New Trajetcory File --
void MainForm::btn_new_trajectory_file() {

	System::Windows::Forms::DialogResult res = System::Windows::Forms::MessageBox::Show(
		"Creating new trajectory file. Save current project?",
		"Create new file",
		MessageBoxButtons::YesNoCancel,
		MessageBoxIcon::Information);

	if (res == System::Windows::Forms::DialogResult::Yes) {
		printf("Save current file \n");
		// Put your save code here 
		// ...
		// ...
	}

	else if (res == System::Windows::Forms::DialogResult::Cancel) {
		return;
	}

	printf("Create new file \n");
	dataGridView2->DataSource = nullptr;
	dataGridView2->Rows->Clear();
	tab2.data.clear();

}

// -- Add new trajectory point --
void MainForm::btn_add_new_point(){
	pos_t pos;

	if (!yrc.isConnected) {
		System::Windows::Forms::MessageBox::Show("Robot is not connected!");
		return;
	}

	if (selected_robot == ROBOGUIDE) pos = rgConvertToPost(rg_global_pos);
	if (selected_robot == YASKAWA) pos = ConvertToPost(yrc.global_pos);

	// Table
	dataGridView2->Rows->Insert(tab2.selected_index);
	dataGridView2->Rows[tab2.selected_index]->Cells[1]->Value = pos.X.ToString("N3");
	dataGridView2->Rows[tab2.selected_index]->Cells[2]->Value = pos.Y.ToString("N3");
	dataGridView2->Rows[tab2.selected_index]->Cells[3]->Value = pos.Z.ToString("N3");
	dataGridView2->Rows[tab2.selected_index]->Cells[4]->Value = pos.W.ToString("N3");
	dataGridView2->Rows[tab2.selected_index]->Cells[5]->Value = pos.P.ToString("N3");
	dataGridView2->Rows[tab2.selected_index]->Cells[6]->Value = pos.R.ToString("N3");
	
	// Register
	tab2.data.insert(tab2.data.begin() + tab2.selected_index, pos);

	update_tab2_line_number();
	print_trajectory(tab2.data);
}

// -- Delete the selected point --
void MainForm::btn_delete_point(){
	if (dataGridView2->RowCount > 0) {
		tab2.data.erase(tab2.data.begin() + tab2.selected_index);
		dataGridView2->Rows->RemoveAt(tab2.selected_index);
		update_tab2_line_number();
		//print_trajectory(tab2.data);
	}
}

// -- Modify the selected point --
void MainForm::btn_modify_point(){
	if (isFormOpened("ModifyPointForm") == false) {
		ModifyPointForm ^ form = gcnew ModifyPointForm;
		form->Show(this);
	}
}

// -- Replace the selected point with current position -- 
void MainForm::btn_replace_current_pos() {

	if (!yrc.isConnected) {
		System::Windows::Forms::MessageBox::Show("Robot is not connected!");
		return;
	}

	pos_t pos;
	pos = ConvertToPost(yrc.global_pos);
	dataGridView2->Rows[tab2.selected_index]->Cells[1]->Value = pos.X.ToString("N3");
	dataGridView2->Rows[tab2.selected_index]->Cells[2]->Value = pos.Y.ToString("N3");
	dataGridView2->Rows[tab2.selected_index]->Cells[3]->Value = pos.Z.ToString("N3");
	dataGridView2->Rows[tab2.selected_index]->Cells[4]->Value = pos.W.ToString("N3");
	dataGridView2->Rows[tab2.selected_index]->Cells[5]->Value = pos.P.ToString("N3");
	dataGridView2->Rows[tab2.selected_index]->Cells[6]->Value = pos.R.ToString("N3");
	tab2.data[tab2.selected_index] = pos;
	print_trajectory(tab2.data);
}

void MainForm::update_tab2_line_number() {
	if (dataGridView2->RowCount > 0) {
		char str[512];
		tab2.selected_index = dataGridView2->CurrentRow->Index;
		tab2.total_index = dataGridView2->RowCount;
		sprintf(str, "%s [%d/%d]", trajectory_file_name.c_str(), tab2.selected_index, tab2.total_index);
		groupBox4->Text = gcnew String(str);
		for (int i = 0; i < dataGridView2->RowCount; i++) {
			dataGridView2->Rows[i]->Cells[0]->Value = i;
		}
	}
}


// -- Move to selected point -- // 
void MainForm::btn_move_to_selected_position() {
	
	btn_resetConnection();

	if (!yrc.isConnected) {
		System::Windows::Forms::MessageBox::Show("Robot is not connected", "Set Position error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	
	if (dataGridView2->RowCount == 0) {
		System::Windows::Forms::MessageBox::Show("Trajectory is not loaded", "Set Position error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	if (!yrc.servoIsActive) {
		yrc.SVON();
		Sleep(300);
	}

	if (haptic_jog_mode) haptic_jog_mode = false;
	Sleep(200);

	dataPos pos = ConvertToDataPos(tab2.data[tab2.selected_index]);

	robot_speed = calibrate_speed(speed_ratio, fast_speed);
	yrc.moveL(pos, robot_speed);
	printf("> Move to position [%d] \n", tab2.selected_index);
}

// -- Move to next position -- //
void MainForm::btn_move_to_next() {
	if (!yrc.isConnected) {
		System::Windows::Forms::MessageBox::Show("Robot is not connected", "Set Position error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	if (!yrc.servoIsActive) {
		System::Windows::Forms::MessageBox::Show("Servo is OFF", "Set Position error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	if (dataGridView2->RowCount == 0) {
		System::Windows::Forms::MessageBox::Show("Trajectory is not loaded", "Set Position error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	if (tab2.selected_index < tab2.total_index) tab2.selected_index++;
	dataPos pos = ConvertToDataPos(tab2.data[tab2.selected_index]);
	yrc.moveL(pos, 30);
	printf("> Move to position [%d] \n", tab2.selected_index);
}

// -- Move to prev position -- //
void MainForm::btn_move_to_prev() {
	if (!yrc.isConnected) {
		System::Windows::Forms::MessageBox::Show("Robot is not connected", "Set Position error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	if (!yrc.servoIsActive) {
		System::Windows::Forms::MessageBox::Show("Servo is OFF", "Set Position error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	if (dataGridView2->RowCount == 0) {
		System::Windows::Forms::MessageBox::Show("Trajectory is not loaded", "Set Position error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	if (tab2.selected_index > 0) tab2.selected_index--;
	dataPos pos = ConvertToDataPos(tab2.data[tab2.selected_index]);
	yrc.moveL(pos, 30);
	printf("> Move to position [%d] \n", tab2.selected_index);

}

// -- Show Trajectory Calibration Form --
void MainForm::btn_open_calibration_form() {
	if (isFormOpened("TrajectoryCalibrationForm") == false) {
		TrajectoryCalibrationForm ^ form = gcnew TrajectoryCalibrationForm;
		form->Show(this);
	}	
}

// -- Show Trajectory Record Form --
void MainForm::show_trajectory_record_form() {
	if (isFormOpened("RecordForm") == false) {
		RecordForm ^ form = gcnew RecordForm;
		form->Show(this);
	}
}

// -- Save trajectory file --
void MainForm::btn_save_trajectory() {
	string path;
	saveFileDialog1->Filter = "CSV file (*.CSV)|*.CSV";
	saveFileDialog1->Title = "Save Trajectory File";
	saveFileDialog1->InitialDirectory = "../Trajectory";
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		String ^ filepath = saveFileDialog1->FileName;
		path = marshal_as<string>(filepath);
		save_trajectory(path, tab2.data);
		trajectory_file_name = marshal_as<string>(filepath);
		update_tab2_line_number();
	}
}

// -- Apply Calibration -- //
void MainForm::btn_apply_trajectory_calibration() {
	System::Windows::Forms::DialogResult res = System::Windows::Forms::MessageBox::Show(
		"Generate calibration file. Save current project?",
		"Calibrate Trajectory",
		MessageBoxButtons::YesNoCancel,
		MessageBoxIcon::Information);

	if (res == System::Windows::Forms::DialogResult::Yes) {
		printf("Save current file \n");
		save_trajectory(trajectory_file_path, tab2.data);
	}

	if (res == System::Windows::Forms::DialogResult::Cancel) {
		return;
	}

	vector<pos_t> normPos = trajectory_setToZero(tab2.data);
	tab2.data = calibrate_trajectory(normPos);
	show_trajectory_table(tab2.data);
}

///////////////////////////////////////////////////////////////////////////




// ////////////////////////////////////////////////////////////////////////
//							TAB 3: SETTINGS
// ////////////////////////////////////////////////////////////////////////

// -- Hardware initialization --
void MainForm::btn_initDevice() {
	// Connect to yaskawa
	if (!yrc.isConnected) {
		if (yrc.tcp_connect(yaskawa_ip) == 0) {
			System::Windows::Forms::MessageBox::Show("Communication failed", "Communication Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		yrc.send_command("CONNECT Robot_access Keep-Alive:50000\r", yrc.pRecv);
	}
	
	// Connect the haptic device
	if (!haptic.connected) {
		if (haptic.init() == -1) {
			System::Windows::Forms::MessageBox::Show(
				"Haptic connection failed!",
				"Connection error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}
	}

	 
	// Connect the force sensor
	
	if (!wacoh_isConnected) {
		if (serial_connect(serialComPort) == -1) {
			System::Windows::Forms::MessageBox::Show(
				"Wacoh connection failed!",
				"Connection error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
		}
	}

	// Activate the thread update data:
	//_beginthread(thread_update_robot_data, 0, NULL);

	System::Windows::Forms::MessageBox::Show(
		"Device connection success!",
		"Initialization",
		MessageBoxButtons::OK,
		MessageBoxIcon::Information
	);
	
}

void MainForm::btn_roboguide_connect() {
	if (!roboguide.connected) { 
		int hr = roboguide.connect(roboguide_ip.c_str());
		if (!hr) {
			System::Windows::Forms::MessageBox::Show("Fanuc robot connection failed!", "Connection error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		System::Windows::Forms::MessageBox::Show("Fanuc robot connection success!", "Roboguide Connection", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}



void thread_tool_calibration(void *) {
	

}
void MainForm::btn_tool_calibration() {
	

}


// -- Move to Home Position --
void MainForm::btn_moveTo_home_pos() {
	
	btn_resetConnection();

	if (!yrc.isConnected) return;
	if (!yrc.servoIsActive)
		yrc.SVON();

	dataPos pos = arrayToDatapos(home_pos);
	robot_speed = calibrate_speed(speed_ratio, fast_speed);
	yrc.moveL(pos, robot_speed, true);
}

// -- Move to Standby Position --
void MainForm::btn_moveTo_standby_pos() {
	
	btn_resetConnection();

	if (!yrc.isConnected) return;
	if (!yrc.servoIsActive)
		yrc.SVON();

	dataPos pos = arrayToDatapos(standby_pos);
	robot_speed = calibrate_speed(speed_ratio, fast_speed);
	yrc.moveL(pos, robot_speed, true);
}

// -- Show the graph data --
void MainForm::btn_show_graph() {

}

// -- Set Servo Power --
void MainForm::btn_servo() {
	if (!yrc.isConnected) return;

	if (!yrc.servoIsActive) {
		yrc.SVON();
		btnServo->Text = "Servo OFF";
	}
	else {
		yrc.SVOFF();
		btnServo->Text = "Servo ON";
	}

}


// -- Reset Yaskawa Connection --
void MainForm::btn_resetConnection() {
	if (yrc.isConnected) {
		yrc.disconnect();
		Sleep(500);
		yrc.tcp_connect(yaskawa_ip);
		yrc.send_command("CONNECT Robot_access Keep-Alive:50000\r", yrc.pRecv);
	}
	else {
		yrc.tcp_connect(yaskawa_ip);
		yrc.send_command("CONNECT Robot_access Keep-Alive:50000\r", yrc.pRecv);
	}
}

void show_3d_force(void *) {
	while (1) {
		ofstream file("Fcm.txt");
		file << "X_value,Y_value,Z_value" << endl;
		file << haptic_feedback_force[0] << "," << haptic_feedback_force[1] << "," << haptic_feedback_force[2] << endl;
		file.close();

		cout << haptic_feedback_force[0] << "," << haptic_feedback_force[1] << "," << haptic_feedback_force[2] << endl;
		Sleep(100);
	}
}

void MainForm::show_3d_plot() {
	_beginthread(show_3d_force, 0, NULL);
}


// -- Open Robot Setting Form --
void MainForm::btn_open_robot_settings() {
	if (isFormOpened("SettingForm") == false) {
		SettingForm ^ form = gcnew SettingForm;
		form->Show(this);
	}
}

void MainForm::btn_haptic_setting_form() {
	if (isFormOpened("HapticSettingForm") == false) {
		HapticSettingForm ^ form = gcnew HapticSettingForm;
		form->Show(this);
	}
}

void read_position(void *) {
	for (int i = 0; i < 40; i++) {
		dataPos pos = yrc.read_cartesianPos(0);
		printf("Pos[%d]=%.3f, %.3f, %.3f \n", i, pos.X, pos.Y, pos.Z);
		Sleep(100);
	}
}

void MainForm::btn_test() {
	if (!yrc.servoIsActive) yrc.SVON();
	yrc.job_start_2("YUDATEST");
	_beginthread(read_position, 0, NULL);
}

void MainForm::show_coppeliasim() {
	if (isFormOpened("CoppeliaForm1") == false) {
		CoppeliaForm ^ form = gcnew CoppeliaForm;
		form->Show(this);
	}
}