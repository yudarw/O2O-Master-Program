#pragma once

namespace OfflineProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddOfflineTrajectory
	/// </summary>
	public ref class AddOfflineTrajectory : public System::Windows::Forms::Form
	{
	public:
		AddOfflineTrajectory(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void btn_apply();
		void on_init();
		void refresh_filelist();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddOfflineTrajectory()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^  comboBox1;
	protected:
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::ComboBox^  combo_wait;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  tb_speed;
	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::GroupBox^  groupBox2;

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
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->combo_wait = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->tb_speed = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"FRONT_SIDE_SSD", L"LEFT_SIDE_SSD", L"TOP_SIDE_SSD" });
			this->comboBox1->Location = System::Drawing::Point(12, 21);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(235, 24);
			this->comboBox1->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(257, 58);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Select Offline Trajectory";
			// 
			// combo_wait
			// 
			this->combo_wait->FormattingEnabled = true;
			this->combo_wait->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"TRUE", L"FALSE" });
			this->combo_wait->Location = System::Drawing::Point(81, 59);
			this->combo_wait->Name = L"combo_wait";
			this->combo_wait->Size = System::Drawing::Size(100, 24);
			this->combo_wait->TabIndex = 26;
			this->combo_wait->Text = L"TRUE";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(9, 62);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(42, 17);
			this->label9->TabIndex = 25;
			this->label9->Text = L"WAIT";
			// 
			// tb_speed
			// 
			this->tb_speed->Location = System::Drawing::Point(109, 21);
			this->tb_speed->Name = L"tb_speed";
			this->tb_speed->Size = System::Drawing::Size(72, 22);
			this->tb_speed->TabIndex = 24;
			this->tb_speed->Text = L"30.0";
			this->tb_speed->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(97, 17);
			this->label2->TabIndex = 23;
			this->label2->Text = L"SPEED(mm/s)";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(51, 184);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(186, 50);
			this->button1->TabIndex = 28;
			this->button1->Text = L"ADD";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &AddOfflineTrajectory::button1_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->combo_wait);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->tb_speed);
			this->groupBox2->Location = System::Drawing::Point(12, 76);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(257, 106);
			this->groupBox2->TabIndex = 27;
			this->groupBox2->TabStop = false;
			// 
			// AddOfflineTrajectory
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(280, 246);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"AddOfflineTrajectory";
			this->Text = L"AddOfflineTrajectory";
			this->Load += gcnew System::EventHandler(this, &AddOfflineTrajectory::AddOfflineTrajectory_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		btn_apply();
	}

private: System::Void AddOfflineTrajectory_Load(System::Object^  sender, System::EventArgs^  e) {
	on_init();
}
};
}
