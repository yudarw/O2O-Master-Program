#include "RecordForm.h"
#include "MainForm.h"
#include "GlobalVariable.h"

using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace OfflineProgram;


bool rgIsRecording = false;
bool ywIsRecording = false;
pos_t pos;
int step_record = 0;

void thread_record_roboguide(void *);

// -- Button Record Roboguide Event --
void RecordForm::btn_record_roboguide(){

	if (!roboguide.connected) {
		int hr = roboguide.connect(roboguide_ip.c_str());
		if (!hr) {
			System::Windows::Forms::MessageBox::Show("Fanuc robot connection failed!", "Connection error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		System::Windows::Forms::MessageBox::Show("Fanuc robot connection success!", "Roboguide Connection", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	if (!rgIsRecording) {
		rgIsRecording = true;
		tab2.data.clear();

		btnRg->Text = "Stop Recording";
		// triger the IO pin:
		roboguide.set_sdo(2, ON);
		timer1->Interval = 100;
		timer1->Enabled = true;
		timer1->Start();
	}
	else {
		rgIsRecording = false;
		btnRg->Text = "Record Roboguide";
	}
	//_beginthread(thread_record_roboguide, 0, NULL);
}

// -- Btn Record Yaskawa Event --
void RecordForm::btn_record_yaskawa() {
	if (!ywIsRecording) {
		ywIsRecording = true;
		btnYw->Text = "Stop Recording";
	}
	else {
		ywIsRecording = false;
		btnYw->Text = "Record Yaskawa";
	}
}


void thread_record_roboguide(void *) {
	pos_t pos;
	int n = 0;
	while (rgIsRecording) {
		pos.X = rg_global_pos.X;
		pos.Y = rg_global_pos.Y;
		pos.Z = rg_global_pos.Z;
		pos.W = rg_global_pos.W;
		pos.P = rg_global_pos.P;
		pos.R = rg_global_pos.R;
		
		// Save the current pos to register:
		recorded_pos.push_back(pos);

		printf("> Recorded Position [%d]: %.3f,%.3f,%.3f,%.3f,%.3f,%.3f\n", 
			n, pos.X, pos.Y, pos.Z, pos.W, pos.P, pos.R);

		if (rg_trigger_state == ON) rgIsRecording = false;
		n++;
		Sleep(50);
	}
}

// -- On Timer Program --
void RecordForm::on_timer() {
	if (rgIsRecording) {
		pos.X = rg_global_pos.X;
		pos.Y = rg_global_pos.Y;
		pos.Z = rg_global_pos.Z;
		pos.W = rg_global_pos.W;
		pos.P = rg_global_pos.P;
		pos.R = rg_global_pos.R;

		// Save the current pos to register:
		tab2.data.push_back(pos);

		printf("> Recorded Position [%d]: %.3f,%.3f,%.3f,%.3f,%.3f,%.3f\n",
			step_record, pos.X, pos.Y, pos.Z, pos.W, pos.P, pos.R);

		// Display the data in table2:
		MainForm::instance->tabel2->Rows->Add();
		MainForm::instance->tabel2->Rows[step_record]->Cells[0]->Value = step_record;
		MainForm::instance->tabel2->Rows[step_record]->Cells[1]->Value = pos.X.ToString("N3");
		MainForm::instance->tabel2->Rows[step_record]->Cells[2]->Value = pos.Y.ToString("N3");
		MainForm::instance->tabel2->Rows[step_record]->Cells[3]->Value = pos.Z.ToString("N3");
		MainForm::instance->tabel2->Rows[step_record]->Cells[4]->Value = pos.W.ToString("N3");
		MainForm::instance->tabel2->Rows[step_record]->Cells[5]->Value = pos.P.ToString("N3");
		MainForm::instance->tabel2->Rows[step_record]->Cells[6]->Value = pos.R.ToString("N3");

		if (rg_trigger_state == ON) { 
			timer1->Stop();
			rgIsRecording = false; 
		}
		step_record++;
	}
}