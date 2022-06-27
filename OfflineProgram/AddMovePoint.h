#pragma once
#include "MainForm.h"

namespace OfflineProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddMovePoint
	/// </summary>
	public ref class AddMovePoint : public System::Windows::Forms::Form
	{
	public:
		AddMovePoint(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void btn_ok();
		void on_init();
		void update_pos_reg_index();
		void on_timer();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddMovePoint()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  combo_type;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  tb_speed;
	private: System::Windows::Forms::TextBox^  tbX;
	private: System::Windows::Forms::TextBox^  tbY;




	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  tbRx;

	private: System::Windows::Forms::TextBox^  tbZ;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  tbRy;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  tbRz;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::ComboBox^  combo_wait;

	private: System::Windows::Forms::Label^  label9;

	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::ComboBox^  cb_posReg;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::TextBox^  tbComment;

	private: System::Windows::Forms::Label^  label11;
	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AddMovePoint::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->combo_type = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tb_speed = (gcnew System::Windows::Forms::TextBox());
			this->tbX = (gcnew System::Windows::Forms::TextBox());
			this->tbY = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tbRx = (gcnew System::Windows::Forms::TextBox());
			this->tbZ = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tbRy = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->tbRz = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->combo_wait = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->cb_posReg = (gcnew System::Windows::Forms::ComboBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->tbComment = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(28, 351);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(135, 54);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Cancel";
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button1->UseVisualStyleBackColor = false;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Transparent;
			this->button2->ForeColor = System::Drawing::Color::Black;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->Location = System::Drawing::Point(181, 351);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(136, 54);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Insert";
			this->button2->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &AddMovePoint::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(22, 204);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 18);
			this->label1->TabIndex = 2;
			this->label1->Text = L"TYPE";
			// 
			// combo_type
			// 
			this->combo_type->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->combo_type->FormattingEnabled = true;
			this->combo_type->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"MOVL", L"MOVJ" });
			this->combo_type->Location = System::Drawing::Point(115, 200);
			this->combo_type->Name = L"combo_type";
			this->combo_type->Size = System::Drawing::Size(202, 26);
			this->combo_type->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(22, 238);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 18);
			this->label2->TabIndex = 4;
			this->label2->Text = L"SPEED";
			// 
			// tb_speed
			// 
			this->tb_speed->Location = System::Drawing::Point(115, 237);
			this->tb_speed->Name = L"tb_speed";
			this->tb_speed->Size = System::Drawing::Size(202, 24);
			this->tb_speed->TabIndex = 5;
			// 
			// tbX
			// 
			this->tbX->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbX->Location = System::Drawing::Point(46, 34);
			this->tbX->Name = L"tbX";
			this->tbX->Size = System::Drawing::Size(99, 17);
			this->tbX->TabIndex = 6;
			this->tbX->Text = L"000.000";
			this->tbX->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbY
			// 
			this->tbY->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbY->Location = System::Drawing::Point(46, 65);
			this->tbY->Name = L"tbY";
			this->tbY->Size = System::Drawing::Size(99, 17);
			this->tbY->TabIndex = 7;
			this->tbY->Text = L"000.000";
			this->tbY->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(20, 34);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(18, 18);
			this->label3->TabIndex = 8;
			this->label3->Text = L"X";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(20, 69);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(17, 18);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Y";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(155, 37);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(26, 18);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Rx";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(20, 97);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(17, 18);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Z";
			// 
			// tbRx
			// 
			this->tbRx->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbRx->Location = System::Drawing::Point(187, 34);
			this->tbRx->Name = L"tbRx";
			this->tbRx->Size = System::Drawing::Size(99, 17);
			this->tbRx->TabIndex = 11;
			this->tbRx->Text = L"000.000";
			this->tbRx->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbZ
			// 
			this->tbZ->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbZ->Location = System::Drawing::Point(46, 97);
			this->tbZ->Name = L"tbZ";
			this->tbZ->Size = System::Drawing::Size(99, 17);
			this->tbZ->TabIndex = 10;
			this->tbZ->Text = L"000.000";
			this->tbZ->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(155, 69);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(26, 18);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Ry";
			// 
			// tbRy
			// 
			this->tbRy->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbRy->Location = System::Drawing::Point(187, 65);
			this->tbRy->Name = L"tbRy";
			this->tbRy->Size = System::Drawing::Size(99, 17);
			this->tbRy->TabIndex = 14;
			this->tbRy->Text = L"000.000";
			this->tbRy->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(155, 100);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(27, 18);
			this->label8->TabIndex = 17;
			this->label8->Text = L"Rz";
			// 
			// tbRz
			// 
			this->tbRz->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbRz->Location = System::Drawing::Point(187, 97);
			this->tbRz->Name = L"tbRz";
			this->tbRz->Size = System::Drawing::Size(99, 17);
			this->tbRz->TabIndex = 16;
			this->tbRz->Text = L"000.000";
			this->tbRz->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tbRz);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->tbX);
			this->groupBox1->Controls->Add(this->tbY);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->tbRy);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->tbZ);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->tbRx);
			this->groupBox1->Location = System::Drawing::Point(14, 14);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(303, 132);
			this->groupBox1->TabIndex = 18;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"POSITION";
			// 
			// combo_wait
			// 
			this->combo_wait->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->combo_wait->FormattingEnabled = true;
			this->combo_wait->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"TRUE", L"FALSE" });
			this->combo_wait->Location = System::Drawing::Point(115, 269);
			this->combo_wait->Name = L"combo_wait";
			this->combo_wait->Size = System::Drawing::Size(202, 26);
			this->combo_wait->TabIndex = 20;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(22, 272);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(44, 18);
			this->label9->TabIndex = 19;
			this->label9->Text = L"WAIT";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(22, 169);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(77, 18);
			this->label10->TabIndex = 22;
			this->label10->Text = L"POS REG";
			// 
			// cb_posReg
			// 
			this->cb_posReg->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cb_posReg->FormattingEnabled = true;
			this->cb_posReg->Location = System::Drawing::Point(115, 165);
			this->cb_posReg->Name = L"cb_posReg";
			this->cb_posReg->Size = System::Drawing::Size(202, 26);
			this->cb_posReg->TabIndex = 24;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &AddMovePoint::timer1_Tick);
			// 
			// tbComment
			// 
			this->tbComment->Location = System::Drawing::Point(115, 301);
			this->tbComment->Name = L"tbComment";
			this->tbComment->Size = System::Drawing::Size(202, 24);
			this->tbComment->TabIndex = 26;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(22, 302);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(87, 18);
			this->label11->TabIndex = 25;
			this->label11->Text = L"COMMENT";
			// 
			// AddMovePoint
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(330, 419);
			this->Controls->Add(this->tbComment);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->cb_posReg);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->combo_wait);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->tb_speed);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->combo_type);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"AddMovePoint";
			this->Text = L"AddMovePoint";
			this->Load += gcnew System::EventHandler(this, &AddMovePoint::AddMovePoint_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AddMovePoint_Load(System::Object^  sender, System::EventArgs^  e) {
		on_init();
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_ok();
}
private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	update_pos_reg_index();
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	on_timer();
}
};
}
