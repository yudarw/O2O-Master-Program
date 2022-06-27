#include "StatusForm.h"
#include "GlobalVariable.h"
using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace OfflineProgram;

pos_t rgpos2post(DataPos pos) {
	pos_t newpos;
	newpos.X = pos.X;
	newpos.Y = pos.Y;
	newpos.Z = pos.Z;
	newpos.W = pos.W;
	newpos.P = pos.P;
	newpos.R = pos.R;
	return newpos;
}

void StatusForm::on_timer() {
	pos_t pos;
	if (selected_robot == ROBOGUIDE) pos = rgpos2post(rg_global_pos);
	else if (selected_robot == YASKAWA)  pos = ConvertToPost(yrc.global_pos);
	tbPosX->Text = pos.X.ToString("N3");
	tbPosY->Text = pos.Y.ToString("N3");
	tbPosZ->Text = pos.Z.ToString("N3");
	tbPosW->Text = pos.W.ToString("N3");
	tbPosP->Text = pos.P.ToString("N3");
	tbPosR->Text = pos.R.ToString("N3");

	if (yrc.isMoving) labelMoving->Text = "TRUE";
	else labelMoving->Text = "FALSE";

	if (radioButton1->Checked) {
		//gravity_compensation()
		tbFx->Text = calibrated_robot_force[0].ToString("N3");
		tbFy->Text = calibrated_robot_force[1].ToString("N3");
		tbFz->Text = calibrated_robot_force[2].ToString("N3");
		tbMx->Text = calibrated_robot_force[3].ToString("N3");
		tbMy->Text = calibrated_robot_force[4].ToString("N3");
		tbMz->Text = calibrated_robot_force[5].ToString("N3");
	}
	else if (radioButton2->Checked) {
		tbFx->Text = global_robot_force[0].ToString("N3");
		tbFy->Text = global_robot_force[1].ToString("N3");
		tbFz->Text = global_robot_force[2].ToString("N3");
		tbMx->Text = global_robot_force[3].ToString("N3");
		tbMy->Text = global_robot_force[4].ToString("N3");
		tbMz->Text = global_robot_force[5].ToString("N3");
	}

	if (haptic.connected) {
		double hpos[6];
		haptic.getPosition(hpos);
		tbHposX->Text = hpos[0].ToString("N3");
		tbHposY->Text = hpos[1].ToString("N3");
		tbHposZ->Text = hpos[2].ToString("N3");
		tbHposW->Text = hpos[3].ToString("N3");
		tbHposP->Text = hpos[4].ToString("N3");
		tbHposR->Text = hpos[5].ToString("N3");
	}
}


pos_t cmdpos;
void _setpos(void *) {
	if (!yrc.isConnected) return;
	if (!yrc.servoIsActive) yrc.SVON();
	yrc.moveL(ConvertToDataPos(cmdpos), 100, true);
}

// -- Set Position --
void StatusForm::btn_setPosition() {
	pos_t pos;
	cmdpos.X = Convert::ToDouble(tbSetX->Text);
	cmdpos.Y = Convert::ToDouble(tbSetY->Text);
	cmdpos.Z = Convert::ToDouble(tbSetZ->Text);
	cmdpos.W = Convert::ToDouble(tbSetW->Text);
	cmdpos.P = Convert::ToDouble(tbSetP->Text);
	cmdpos.R = Convert::ToDouble(tbSetR->Text);
	_beginthread(_setpos, 0, NULL);
}

// -- Copy the Position --
void StatusForm::btn_copyPos() {
	tbSetX->Text = tbPosX->Text;
	tbSetY->Text = tbPosY->Text;
	tbSetZ->Text = tbPosZ->Text;
	tbSetW->Text = tbPosW->Text;
	tbSetP->Text = tbPosP->Text;
	tbSetR->Text = tbPosR->Text;
}