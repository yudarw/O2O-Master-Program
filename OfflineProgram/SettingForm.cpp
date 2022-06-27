#include "SettingForm.h"
#include "MainForm.h"
#include "GlobalVariable.h"

using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace OfflineProgram;

void SettingForm::on_init() {
	tb_yaskawa_ip->Text = gcnew String(yaskawa_ip.c_str());
	tb_roboguide_ip->Text = gcnew String(roboguide_ip.c_str());
	tb_com->Text = gcnew String(serialComPort.c_str());
	detect_serialPort();
	
	for (int i = 0; i < 10; i++) {
		if (serialPortList[i] != "") {
			String ^ _str = gcnew String(serialPortList[i].c_str());
			tb_com->Items->Add(_str);
		}
	}
	

}

void SettingForm::btn_apply() {
	yaskawa_ip = marshal_as<string>(tb_yaskawa_ip->Text);
	roboguide_ip = marshal_as<string>(tb_roboguide_ip->Text);
	serialComPort = marshal_as<string>(tb_com->Text);

	// Debug
	cout << "Yaskawa IP: " << yaskawa_ip << endl;
	cout << "Roboguide IP: " << roboguide_ip << endl;
	cout << "Serial COM : " << serialComPort << endl;

	// Save configuration:
	save_config_file();

	this->Close();
} 