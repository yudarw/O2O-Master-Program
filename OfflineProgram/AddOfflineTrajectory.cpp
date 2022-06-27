#include "AddOfflineTrajectory.h"
#include "MainForm.h"
#include "GlobalVariable.h"
#include "_dirent.h"

using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace OfflineProgram;

// -- Load data on Initialization --
void AddOfflineTrajectory::on_init() {
	char str[32];
	refresh_filelist();
	if (editing_mode == LINE_EDIT) {
		// show current speed:
		sprintf(str, "%.1f", tab.program_data[tab.selected_index].speed);
		tb_speed->Text = gcnew String(str);
		combo_wait->SelectedIndex = tab.program_data[tab.selected_index].wait;
		comboBox1->Text = gcnew String(tab.program_data[tab.selected_index].dataString.c_str());
	}
	else if (editing_mode == LINE_ADD) {		
	}
}

// -- Add Trajectory Routine --
void AddOfflineTrajectory::btn_apply() {
	char str[128];
	Sequence newProg;
	// Get trajectory filename:
	String ^ filename = comboBox1->Text;
	string path = marshal_as<string>(filename);
	// Get Configuration:
	newProg.command = CMD_ADD_OFFLINE_TRAJECTORY;
	newProg.speed = Convert::ToDouble(tb_speed->Text);
	newProg.wait = combo_wait->SelectedIndex;
	newProg.dataString = path;

	sprintf(str, "CALL_TRAJECTORY [%s]   V=%.1f  Wait=%s",
		newProg.dataString.c_str(),
		newProg.speed,
		str_wait[newProg.wait].c_str());

	if (editing_mode == LINE_ADD) {	
		//tab.program_data.push_back(newProg);
		tab.program_data.insert(tab.program_data.begin() + tab.index, newProg);
		MainForm::instance->tabel->Rows->Insert(tab.index);
		MainForm::instance->tabel->Rows[tab.index]->Cells[1]->Value = gcnew String(str);

		int num = MainForm::instance->tabel->RowCount;
		for (int i = 0; i < num; i++)
			MainForm::instance->tabel->Rows[i]->Cells[0]->Value = i;

		tab.index++;
	}
	else if (editing_mode = LINE_EDIT) {
		MainForm::instance->tabel->Rows[tab.selected_index]->Cells[0]->Value = tab.selected_index;
		MainForm::instance->tabel->Rows[tab.selected_index]->Cells[1]->Value = gcnew String(str);
		tab.program_data[tab.selected_index] = newProg;
	}
	this->Close();
}


// -- Refresh Filelist --
void AddOfflineTrajectory::refresh_filelist() {
	struct dirent *d;
	DIR *dr;
	dr = opendir("./Trajectory");
	int n = 0;
	comboBox1->Items->Clear();
	if (dr != NULL)
	{
		cout << "List of Files & Folders: \n";
		for (d = readdir(dr); d != NULL; d = readdir(dr))
		{
			if (n > 1) {
				cout << d->d_name << endl;
				String ^ filename = gcnew String(d->d_name);
				comboBox1->Items->Add(filename);
			}
			n++;
		}
		closedir(dr);
	}
	else
		cout << "\nError Occurred!";
	cout << endl;
}
