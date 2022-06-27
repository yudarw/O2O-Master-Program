#pragma once

namespace OfflineProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for HapticSettingForm
	/// </summary>
	public ref class HapticSettingForm : public System::Windows::Forms::Form
	{
	public:
		HapticSettingForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void btn_apply();
		void stiffness_adjust();
		void impedance_adjust();
		void on_init();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~HapticSettingForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:





	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::GroupBox^  groupBox13;
	private: System::Windows::Forms::ComboBox^  comboTeleMethod;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  tb_stiffness;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TextBox^  tb_impedance;

	private: System::Windows::Forms::TrackBar^  trackBar2;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(HapticSettingForm::typeid));
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox13 = (gcnew System::Windows::Forms::GroupBox());
			this->comboTeleMethod = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tb_stiffness = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->tb_impedance = (gcnew System::Windows::Forms::TextBox());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->groupBox13->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			this->SuspendLayout();
			// 
			// trackBar1
			// 
			this->trackBar1->BackColor = System::Drawing::SystemColors::Control;
			this->trackBar1->Location = System::Drawing::Point(10, 30);
			this->trackBar1->Maximum = 100;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(195, 56);
			this->trackBar1->TabIndex = 1;
			this->trackBar1->TickFrequency = 10;
			this->trackBar1->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->trackBar1->Value = 50;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &HapticSettingForm::trackBar1_Scroll);
			// 
			// groupBox13
			// 
			this->groupBox13->Controls->Add(this->comboTeleMethod);
			this->groupBox13->Location = System::Drawing::Point(12, 12);
			this->groupBox13->Name = L"groupBox13";
			this->groupBox13->Size = System::Drawing::Size(310, 66);
			this->groupBox13->TabIndex = 0;
			this->groupBox13->TabStop = false;
			this->groupBox13->Text = L"METHOD:";
			// 
			// comboTeleMethod
			// 
			this->comboTeleMethod->FormattingEnabled = true;
			this->comboTeleMethod->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"DEFAULT MODE", L"DIRECT HAPTIC CONTROL MODE",
					L"IMPEDANCE MODE"
			});
			this->comboTeleMethod->Location = System::Drawing::Point(10, 26);
			this->comboTeleMethod->Name = L"comboTeleMethod";
			this->comboTeleMethod->Size = System::Drawing::Size(289, 26);
			this->comboTeleMethod->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button1->Location = System::Drawing::Point(203, 302);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(119, 47);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Apply";
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &HapticSettingForm::button1_Click);
			// 
			// tb_stiffness
			// 
			this->tb_stiffness->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_stiffness->Location = System::Drawing::Point(211, 41);
			this->tb_stiffness->Name = L"tb_stiffness";
			this->tb_stiffness->Size = System::Drawing::Size(88, 27);
			this->tb_stiffness->TabIndex = 7;
			this->tb_stiffness->Text = L"0.005";
			this->tb_stiffness->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tb_stiffness);
			this->groupBox1->Controls->Add(this->trackBar1);
			this->groupBox1->Location = System::Drawing::Point(12, 84);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(310, 96);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"STIFFNESS:";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->tb_impedance);
			this->groupBox3->Controls->Add(this->trackBar2);
			this->groupBox3->Location = System::Drawing::Point(12, 186);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(310, 96);
			this->groupBox3->TabIndex = 8;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"IMPEDANCE:";
			// 
			// tb_impedance
			// 
			this->tb_impedance->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_impedance->Location = System::Drawing::Point(211, 41);
			this->tb_impedance->Name = L"tb_impedance";
			this->tb_impedance->Size = System::Drawing::Size(88, 27);
			this->tb_impedance->TabIndex = 7;
			this->tb_impedance->Text = L"0.005";
			this->tb_impedance->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// trackBar2
			// 
			this->trackBar2->BackColor = System::Drawing::SystemColors::Control;
			this->trackBar2->Location = System::Drawing::Point(10, 30);
			this->trackBar2->Maximum = 100;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(195, 56);
			this->trackBar2->TabIndex = 1;
			this->trackBar2->TickFrequency = 10;
			this->trackBar2->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->trackBar2->Value = 50;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &HapticSettingForm::trackBar2_Scroll);
			// 
			// HapticSettingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(331, 358);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox13);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"HapticSettingForm";
			this->Text = L"CONFIG";
			this->Load += gcnew System::EventHandler(this, &HapticSettingForm::HapticSettingForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->groupBox13->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		btn_apply();
	}
private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
	stiffness_adjust();
}
private: System::Void trackBar2_Scroll(System::Object^  sender, System::EventArgs^  e) {
	impedance_adjust();
}
private: System::Void HapticSettingForm_Load(System::Object^  sender, System::EventArgs^  e) {
	on_init();
}
};
}
