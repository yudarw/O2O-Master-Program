#include "GPIOForm.h"
#include "GlobalVariable.h"
using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace OfflineProgram;

int port_number;
int val;

void GPIOForm::btn_apply() {
	
	this->Close();
}

void GPIOForm::write_io_ON() {
	port_number = Convert::ToInt16(tb_port_number->Text);
	val = Convert::ToInt16(tb_val->Text);
	printf("Write GPIO -> ON   Port Num:%d    Value:%d \n", port_number, val);
	yrc.writeIO(port_number, val);
}

void GPIOForm::write_io_OFF() {
	port_number = Convert::ToInt16(tb_port_number->Text);
	val = Convert::ToInt16(tb_val->Text);
	printf("Write GPIO -> ON   Port Num:%d    Value:%d \n", port_number, val);
}