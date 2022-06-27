#include "AddMovePoint.h"
#include "GlobalVariable.h"

using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace OfflineProgram;


void AddMovePoint::on_timer() {
	if (editing_mode == LINE_ADD) {
		pos_t pos = ConvertToPost(yrc.global_pos);
		tbX->Text = pos.X.ToString("N3");
		tbY->Text = pos.Y.ToString("N3");
		tbZ->Text = pos.Z.ToString("N3");
		tbRx->Text = pos.W.ToString("N3");
		tbRy->Text = pos.P.ToString("N3");
		tbRz->Text = pos.R.ToString("N3");
	}
}

void AddMovePoint::on_init() {
	char str[32];
	int n = tab.pos_register.size();
	for (int i = 0; i < n; i++) {
		sprintf(str, "P[%d]", i);
		cb_posReg->Items->Add(gcnew String(str));
	}

	if (editing_mode == LINE_ADD) {
		tb_speed->Text = "" + 50.00;
		combo_type->SelectedIndex = 0;
		combo_wait->SelectedIndex = 0;
		sprintf(str, "P[%d]", tab.pos_reg_index);
		cb_posReg->Text = gcnew String(str);
	}

	else if (editing_mode == LINE_EDIT) {
		Sequence _prog = tab.program_data[tab.index];
		tb_speed->Text = _prog.speed.ToString("N2");
		combo_type->SelectedIndex = _prog.moveType;
		combo_wait->SelectedIndex = _prog.wait;
		sprintf(str, "P[%d]", _prog.posRegNum);
		cb_posReg->Text = gcnew String(str);
		tbComment->Text = gcnew String(_prog.dataString.c_str());

		tbX->Text = tab.pos_register[_prog.posRegNum].X.ToString("N3");
		tbY->Text = tab.pos_register[_prog.posRegNum].Y.ToString("N3");
		tbZ->Text = tab.pos_register[_prog.posRegNum].Z.ToString("N3");
		tbRx->Text = tab.pos_register[_prog.posRegNum].W.ToString("N3");
		tbRy->Text = tab.pos_register[_prog.posRegNum].P.ToString("N3");
		tbRz->Text = tab.pos_register[_prog.posRegNum].R.ToString("N3");
	}
}

//  -- Button Apply --
void AddMovePoint::btn_ok(){
	char str[128];
	string s_type[2] = { "MOVE L", "MOVE J" };
	string s_wait[2] = { "TRUE", "FALSE" };
	Sequence newProg;
	pos_t  pos;

	// Position:
	pos.X = Convert::ToDouble(tbX->Text);
	pos.Y = Convert::ToDouble(tbY->Text);
	pos.Z = Convert::ToDouble(tbZ->Text);
	pos.W = Convert::ToDouble(tbRx->Text);
	pos.P = Convert::ToDouble(tbRy->Text);
	pos.R = Convert::ToDouble(tbRz->Text);
	newProg.command = CMD_ADD_MOVE_POINT;
	newProg.moveType = combo_type->SelectedIndex;
	newProg.speed = Convert::ToDouble(tb_speed->Text);
	newProg.wait = combo_wait->SelectedIndex;
	newProg.pos  = pos;
	newProg.posRegNum = Convert::ToDouble(cb_posReg->SelectedIndex);
	newProg.dataString = marshal_as<string>(tbComment->Text);
	
	if (editing_mode == LINE_ADD) {
		// String to display:
		sprintf(str, "%s P[%d]   V=%.1f   Wait=%s",
			s_type[newProg.moveType].c_str(),
			tab.pos_register.size(),
			newProg.speed,
			s_wait[newProg.wait].c_str());

		newProg.posRegNum = tab.pos_reg_index;
		tab.pos_register.push_back(pos);
		//tab.program_data.push_back(newProg);
		tab.program_data.insert(tab.program_data.begin() + tab.index, newProg);
		MainForm::instance->tabel->Rows->Insert(tab.index);
		MainForm::instance->tabel->Rows[tab.index]->Cells[1]->Value = gcnew String(str);
		MainForm::instance->tabel->Rows[tab.index]->Cells[2]->Value = gcnew String(newProg.dataString.c_str());

		int num = MainForm::instance->tabel->RowCount;
		for(int i = 0; i < num; i++)
			MainForm::instance->tabel->Rows[i]->Cells[0]->Value = i;
		

		tab.index++;
		tab.pos_reg_index++;
	}

	else if (editing_mode == LINE_EDIT) {
		tab.program_data[tab.selected_index] = newProg;
		tab.pos_register[tab.program_data[tab.selected_index].posRegNum] = pos;
		// String to display:
		sprintf(str, "%s P[%d]   V=%.1f   Wait=%s",
			s_type[newProg.moveType].c_str(),
			tab.program_data[tab.selected_index].posRegNum,
			newProg.speed,
			s_wait[newProg.wait].c_str());
		MainForm::instance->tabel->Rows[tab.selected_index]->Cells[0]->Value = tab.selected_index;
		MainForm::instance->tabel->Rows[tab.selected_index]->Cells[1]->Value = gcnew String(str);
		MainForm::instance->tabel->Rows[tab.selected_index]->Cells[2]->Value = gcnew String(newProg.dataString.c_str());
	}

	this->Close();
}


void AddMovePoint::update_pos_reg_index() {
	char str[128];
	pos_t pos;
	//int max = tab.pos_register.size();
	//tab.selected_pos_reg = Convert::ToUInt16(numericUpDown1->Value);
	//if (tab.selected_pos_reg > max) tab.selected_pos_reg = max;
	//pos = tab.pos_register[tab.selected_pos_reg];
	//sprintf(str, "%.3f", pos.X); tbX->Text = gcnew String(str);
	//sprintf(str, "%.3f", pos.Y); tbY->Text = gcnew String(str);
	//sprintf(str, "%.3f", pos.Z); tbZ->Text = gcnew String(str);
	//sprintf(str, "%.3f", pos.W); tbRx->Text = gcnew String(str);
	//sprintf(str, "%.3f", pos.P); tbRy->Text = gcnew String(str);
	//sprintf(str, "%.3f", pos.R); tbRz->Text = gcnew String(str);
}