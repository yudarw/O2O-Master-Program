#include "AddCommentForm.h"
#include "MainForm.h"
#include "GlobalVariable.h"

using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace OfflineProgram;

void AddCommentForm::btn_insert() {
	string comment = marshal_as<string>(textBox1->Text);
	MainForm::instance->tabel->Rows[tab.index]->Cells[1]->Value = textBox1->Text;
	this->Close();
}

