#include "HapticSettingForm.h"
#include "MainForm.h"
#include "GlobalVariable.h"

using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace OfflineProgram;


// -- initialization program --
void HapticSettingForm::on_init() {
	comboTeleMethod->SelectedIndex = teleoperation_method;
	trackBar1->Value = stiffness_val * 100;
	trackBar2->Value = impedance_val * 100;
	tb_stiffness->Text = stiffness_val.ToString("N3");
	tb_impedance->Text = impedance_val.ToString("N3");
}

// -- apply settings --
void HapticSettingForm::btn_apply() {
	
	teleoperation_method = comboTeleMethod->SelectedIndex;
	stiffness_val = Convert::ToDouble(tb_stiffness->Text);
	impedance_val = Convert::ToDouble(tb_impedance->Text);

	// -- Haptic Config -- 
	cout << ">>> Haptic configuration:" << endl;
	cout << "Teleoperation mode: " << teleoperation_method <<endl;
	cout << "Stiffness val: " << stiffness_val << endl;
	cout << "Impedance val: " << impedance_val << endl << endl;

	save_config_file();

	this->Close();
}

void HapticSettingForm::stiffness_adjust() {
	double max = 0.3;
	double val = trackBar1->Value;
	val = (val / 100) * max;
	tb_stiffness->Text = val.ToString("N3");
}

void HapticSettingForm::impedance_adjust() {
	double max = 0.3;
	double val = trackBar2->Value;
	val = (val / 100) * max;
	tb_impedance->Text = val.ToString("N3");
}