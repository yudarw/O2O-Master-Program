#include "ModifyPointForm.h"
#include "MainForm.h"
#include "GlobalVariable.h"

using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace OfflineProgram;


void ModifyPointForm::on_init() {
	char str[32];
	pos_t pos = tab2.data[tab2.selected_index];
	sprintf(str, "%.3f", pos.X); tbX->Text = gcnew String(str);
	sprintf(str, "%.3f", pos.Y); tbY->Text = gcnew String(str);
	sprintf(str, "%.3f", pos.Z); tbZ->Text = gcnew String(str);
	sprintf(str, "%.3f", pos.W); tbW->Text = gcnew String(str);
	sprintf(str, "%.3f", pos.P); tbP->Text = gcnew String(str);
	sprintf(str, "%.3f", pos.R); tbR->Text = gcnew String(str);
}

void ModifyPointForm::btn_apply() {
	pos_t pos;
	pos.X = Convert::ToDouble(tbX->Text);
	pos.Y = Convert::ToDouble(tbY->Text);
	pos.Z = Convert::ToDouble(tbZ->Text);
	pos.W = Convert::ToDouble(tbW->Text);
	pos.P = Convert::ToDouble(tbP->Text);
	pos.R = Convert::ToDouble(tbR->Text);
	MainForm::instance->tabel2->Rows[tab2.selected_index]->Cells[1]->Value = pos.X.ToString("N3");
	MainForm::instance->tabel2->Rows[tab2.selected_index]->Cells[2]->Value = pos.Y.ToString("N3");
	MainForm::instance->tabel2->Rows[tab2.selected_index]->Cells[3]->Value = pos.Z.ToString("N3");
	MainForm::instance->tabel2->Rows[tab2.selected_index]->Cells[4]->Value = pos.W.ToString("N3");
	MainForm::instance->tabel2->Rows[tab2.selected_index]->Cells[5]->Value = pos.P.ToString("N3");
	MainForm::instance->tabel2->Rows[tab2.selected_index]->Cells[6]->Value = pos.R.ToString("N3");
	tab2.data[tab2.selected_index] = pos;
	this->Close();
}