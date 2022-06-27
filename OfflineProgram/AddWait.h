#pragma once

namespace OfflineProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddWait
	/// </summary>
	public ref class AddWait : public System::Windows::Forms::Form
	{
	public:
		AddWait(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void btn_apply();
		void on_init();
	
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddWait()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  cb_constant;
	protected:

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  tb_value;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ComboBox^  cb_io;
	private: System::Windows::Forms::TextBox^  tb_num;


	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ComboBox^  comboBox3;

	private: System::Windows::Forms::Button^  button1;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AddWait::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cb_constant = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tb_value = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cb_io = (gcnew System::Windows::Forms::ComboBox());
			this->tb_num = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(33, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"TYPE";
			this->label1->Click += gcnew System::EventHandler(this, &AddWait::label1_Click);
			// 
			// cb_constant
			// 
			this->cb_constant->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cb_constant->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cb_constant->FormattingEnabled = true;
			this->cb_constant->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"CONSTANT", L"I/O" });
			this->cb_constant->Location = System::Drawing::Point(88, 26);
			this->cb_constant->Name = L"cb_constant";
			this->cb_constant->Size = System::Drawing::Size(136, 28);
			this->cb_constant->TabIndex = 1;
			this->cb_constant->Text = L"CONSTANT";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(23, 63);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"VALUE";
			// 
			// tb_value
			// 
			this->tb_value->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_value->Location = System::Drawing::Point(88, 63);
			this->tb_value->Name = L"tb_value";
			this->tb_value->Size = System::Drawing::Size(85, 27);
			this->tb_value->TabIndex = 3;
			this->tb_value->Text = L"0";
			this->tb_value->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(43, 102);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(39, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"I/O";
			// 
			// cb_io
			// 
			this->cb_io->Enabled = false;
			this->cb_io->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cb_io->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cb_io->FormattingEnabled = true;
			this->cb_io->Location = System::Drawing::Point(89, 99);
			this->cb_io->Name = L"cb_io";
			this->cb_io->Size = System::Drawing::Size(136, 28);
			this->cb_io->TabIndex = 6;
			this->cb_io->Text = L"SDO";
			// 
			// tb_num
			// 
			this->tb_num->Enabled = false;
			this->tb_num->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_num->Location = System::Drawing::Point(88, 133);
			this->tb_num->Name = L"tb_num";
			this->tb_num->Size = System::Drawing::Size(85, 27);
			this->tb_num->TabIndex = 8;
			this->tb_num->Text = L"0";
			this->tb_num->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(43, 136);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(39, 20);
			this->label4->TabIndex = 7;
			this->label4->Text = L"NUM";
			this->label4->Click += gcnew System::EventHandler(this, &AddWait::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(23, 169);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(59, 20);
			this->label5->TabIndex = 9;
			this->label5->Text = L"STATE";
			// 
			// comboBox3
			// 
			this->comboBox3->BackColor = System::Drawing::Color::White;
			this->comboBox3->Enabled = false;
			this->comboBox3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->comboBox3->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"ON", L"OFF" });
			this->comboBox3->Location = System::Drawing::Point(88, 166);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(136, 28);
			this->comboBox3->TabIndex = 10;
			this->comboBox3->Text = L"ON";
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &AddWait::comboBox3_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button1->Location = System::Drawing::Point(59, 216);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(140, 56);
			this->button1->TabIndex = 29;
			this->button1->Text = L"   ADD";
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &AddWait::button1_Click);
			// 
			// AddWait
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(256, 296);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->tb_num);
			this->Controls->Add(this->cb_constant);
			this->Controls->Add(this->cb_io);
			this->Controls->Add(this->tb_value);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"AddWait";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Text = L"Wait";
			this->Load += gcnew System::EventHandler(this, &AddWait::AddWait_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		btn_apply();
	}
private: System::Void comboBox3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void AddWait_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
