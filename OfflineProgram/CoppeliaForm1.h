#pragma once
#include "GlobalVariable.h"

namespace OfflineProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CoppeliaForm
	/// </summary>
	public ref class CoppeliaForm : public System::Windows::Forms::Form
	{
	public:
		CoppeliaForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void coppelia_connect();
		void start_teleoperation();
		void btn_tcp_calibration();
		void btn_test_program();
		void btn_test_calibration();
		void btn_roboguide_connect();
		void btn_record_center_user_frame();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CoppeliaForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  tbR;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  tbP;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  tbW;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  tbZ;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  tbY;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  tbX;

	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbR = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tbP = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tbW = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tbZ = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tbY = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tbX = (gcnew System::Windows::Forms::TextBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Connect";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &CoppeliaForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(93, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(290, 239);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(154, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Teleoperation";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &CoppeliaForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(290, 210);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(154, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Tool Calibration";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &CoppeliaForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(290, 181);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(154, 23);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Test Program";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &CoppeliaForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(290, 100);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(154, 23);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Coordinate Calibration";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &CoppeliaForm::button5_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->tbR);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->tbP);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->tbW);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->tbZ);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->tbY);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->tbX);
			this->groupBox1->Controls->Add(this->button6);
			this->groupBox1->Location = System::Drawing::Point(12, 51);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(234, 182);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"User Frame Calibration";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(121, 131);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(13, 13);
			this->label5->TabIndex = 17;
			this->label5->Text = L"r:";
			// 
			// tbR
			// 
			this->tbR->Location = System::Drawing::Point(145, 128);
			this->tbR->Name = L"tbR";
			this->tbR->Size = System::Drawing::Size(68, 20);
			this->tbR->TabIndex = 18;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(121, 105);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(16, 13);
			this->label6->TabIndex = 15;
			this->label6->Text = L"p:";
			// 
			// tbP
			// 
			this->tbP->Location = System::Drawing::Point(145, 102);
			this->tbP->Name = L"tbP";
			this->tbP->Size = System::Drawing::Size(68, 20);
			this->tbP->TabIndex = 16;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(121, 79);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(18, 13);
			this->label7->TabIndex = 13;
			this->label7->Text = L"w:";
			// 
			// tbW
			// 
			this->tbW->Location = System::Drawing::Point(145, 76);
			this->tbW->Name = L"tbW";
			this->tbW->Size = System::Drawing::Size(68, 20);
			this->tbW->TabIndex = 14;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(21, 131);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(12, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"z";
			// 
			// tbZ
			// 
			this->tbZ->Location = System::Drawing::Point(42, 128);
			this->tbZ->Name = L"tbZ";
			this->tbZ->Size = System::Drawing::Size(68, 20);
			this->tbZ->TabIndex = 12;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(21, 105);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(12, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"y";
			// 
			// tbY
			// 
			this->tbY->Location = System::Drawing::Point(42, 102);
			this->tbY->Name = L"tbY";
			this->tbY->Size = System::Drawing::Size(68, 20);
			this->tbY->TabIndex = 10;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(21, 79);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(12, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"x";
			// 
			// tbX
			// 
			this->tbX->Location = System::Drawing::Point(42, 76);
			this->tbX->Name = L"tbX";
			this->tbX->Size = System::Drawing::Size(68, 20);
			this->tbX->TabIndex = 8;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(36, 32);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(154, 23);
			this->button6->TabIndex = 7;
			this->button6->Text = L"Record User Frame Center";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &CoppeliaForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(290, 17);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(154, 23);
			this->button7->TabIndex = 19;
			this->button7->Text = L"Roboguide Connect";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &CoppeliaForm::button7_Click);
			// 
			// CoppeliaForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(456, 274);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"CoppeliaForm";
			this->Text = L"CoppeliaForm";
			this->Load += gcnew System::EventHandler(this, &CoppeliaForm::CoppeliaForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void CoppeliaForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		coppelia_connect();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		start_teleoperation();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		btn_tcp_calibration();
	}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_test_program();
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_test_calibration();
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_roboguide_connect();
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_record_center_user_frame();
}
};
}
