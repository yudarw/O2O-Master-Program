#pragma once

namespace OfflineProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RecordForm
	/// </summary>
	public ref class RecordForm : public System::Windows::Forms::Form
	{
	public:
		RecordForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void btn_record_roboguide();
		void btn_record_yaskawa();
		void on_timer();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RecordForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox8;
	private: System::Windows::Forms::Button^  btnRg;
	private: System::Windows::Forms::TextBox^ tbSamplingTime;
	protected:



	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btnYw;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RecordForm::typeid));
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->btnYw = (gcnew System::Windows::Forms::Button());
			this->tbSamplingTime = (gcnew System::Windows::Forms::TextBox());
			this->btnRg = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox8->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->label2);
			this->groupBox8->Controls->Add(this->textBox2);
			this->groupBox8->Controls->Add(this->btnYw);
			this->groupBox8->Controls->Add(this->tbSamplingTime);
			this->groupBox8->Controls->Add(this->btnRg);
			this->groupBox8->Controls->Add(this->label1);
			this->groupBox8->Location = System::Drawing::Point(12, 12);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(268, 313);
			this->groupBox8->TabIndex = 7;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"TRAJECTORY RECORD";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(49, 172);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 15);
			this->label2->TabIndex = 8;
			this->label2->Text = L"JOB NAME:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(52, 190);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(178, 21);
			this->textBox2->TabIndex = 8;
			this->textBox2->Text = L"TES-PROGRAM";
			// 
			// btnYw
			// 
			this->btnYw->BackColor = System::Drawing::Color::Transparent;
			this->btnYw->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnYw->ForeColor = System::Drawing::Color::Black;
			this->btnYw->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnYw.Image")));
			this->btnYw->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnYw->Location = System::Drawing::Point(52, 217);
			this->btnYw->Name = L"btnYw";
			this->btnYw->Size = System::Drawing::Size(178, 64);
			this->btnYw->TabIndex = 17;
			this->btnYw->Text = L"Record Yaskawa";
			this->btnYw->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnYw->UseVisualStyleBackColor = false;
			this->btnYw->Click += gcnew System::EventHandler(this, &RecordForm::btnYw_Click);
			// 
			// tbSamplingTime
			// 
			this->tbSamplingTime->BackColor = System::Drawing::Color::White;
			this->tbSamplingTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbSamplingTime->Location = System::Drawing::Point(151, 32);
			this->tbSamplingTime->Name = L"tbSamplingTime";
			this->tbSamplingTime->Size = System::Drawing::Size(79, 21);
			this->tbSamplingTime->TabIndex = 1;
			this->tbSamplingTime->Text = L"50";
			this->tbSamplingTime->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// btnRg
			// 
			this->btnRg->BackColor = System::Drawing::Color::Transparent;
			this->btnRg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRg->ForeColor = System::Drawing::Color::Black;
			this->btnRg->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnRg.Image")));
			this->btnRg->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnRg->Location = System::Drawing::Point(52, 59);
			this->btnRg->Name = L"btnRg";
			this->btnRg->Size = System::Drawing::Size(178, 64);
			this->btnRg->TabIndex = 16;
			this->btnRg->Text = L"Record Roboguide";
			this->btnRg->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnRg->UseVisualStyleBackColor = false;
			this->btnRg->Click += gcnew System::EventHandler(this, &RecordForm::button20_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(49, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(94, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Sampling Time:";
			// 
			// timer1
			// 
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &RecordForm::timer1_Tick);
			// 
			// RecordForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(290, 337);
			this->Controls->Add(this->groupBox8);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"RecordForm";
			this->Text = L"RecordForm";
			this->Load += gcnew System::EventHandler(this, &RecordForm::RecordForm_Load);
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button20_Click(System::Object^  sender, System::EventArgs^  e) {
		btn_record_roboguide();
	}
private: System::Void btnYw_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_record_yaskawa();
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	on_timer();
}
private: System::Void RecordForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}
