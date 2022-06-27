#include "AddNewProgram.h"
#include "MainForm.h"
#include "GlobalVariable.h"

using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace OfflineProgram;

// -- Create New Program --
void AddNewProgram::btn_create() {
	System::Windows::Forms::DialogResult res = System::Windows::Forms::MessageBox::Show(
		"Creating new program. Save current project?",
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

	program_file_name = marshal_as<string>(textBox1->Text);

	printf("Create new program: %s \n", program_file_name.c_str());

	string path(".//Program/" + program_file_name + ".txt");
	save_sequence_program(path);

	MainForm::instance->tabel->Rows->Clear();
	MainForm::instance->tabel->DataSource = nullptr;
	tab.program_data.clear();
	tab.pos_register.clear();
	this->Close();
}