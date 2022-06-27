#pragma once

namespace OfflineProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GPIOForm
	/// </summary>
	public ref class GPIOForm : public System::Windows::Forms::Form
	{
	public:
		GPIOForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void btn_apply();
		void write_io_ON();
		void write_io_OFF();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GPIOForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  btn_on;
	private: System::Windows::Forms::Button^  btn_off;


	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  cb_select_io;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::NumericUpDown^  tb_portnum_write;

	private: System::Windows::Forms::TextBox^  tb_val;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::NumericUpDown^  tb_port_number;
	private: System::Windows::Forms::Button^  btn_read;


	private: System::Windows::Forms::TextBox^  tb_val_write;

	private: System::Windows::Forms::Label^  label5;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(GPIOForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btn_read = (gcnew System::Windows::Forms::Button());
			this->tb_val_write = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->cb_select_io = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tb_portnum_write = (gcnew System::Windows::Forms::NumericUpDown());
			this->btn_on = (gcnew System::Windows::Forms::Button());
			this->btn_off = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tb_val = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tb_port_number = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tb_portnum_write))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tb_port_number))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button1->Location = System::Drawing::Point(114, 330);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(134, 53);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Apply";
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &GPIOForm::button1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btn_read);
			this->groupBox1->Controls->Add(this->tb_val_write);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->cb_select_io);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->tb_portnum_write);
			this->groupBox1->Location = System::Drawing::Point(12, 171);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(236, 153);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"READ I/O";
			// 
			// btn_read
			// 
			this->btn_read->Location = System::Drawing::Point(84, 110);
			this->btn_read->Name = L"btn_read";
			this->btn_read->Size = System::Drawing::Size(101, 34);
			this->btn_read->TabIndex = 18;
			this->btn_read->Text = L"Read";
			this->btn_read->UseVisualStyleBackColor = true;
			// 
			// tb_val_write
			// 
			this->tb_val_write->Location = System::Drawing::Point(156, 76);
			this->tb_val_write->Name = L"tb_val_write";
			this->tb_val_write->Size = System::Drawing::Size(72, 21);
			this->tb_val_write->TabIndex = 15;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(67, 79);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(48, 15);
			this->label5->TabIndex = 14;
			this->label5->Text = L"VALUE:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(15, 21);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(77, 15);
			this->label4->TabIndex = 17;
			this->label4->Text = L"SELECT I/O :";
			// 
			// cb_select_io
			// 
			this->cb_select_io->FormattingEnabled = true;
			this->cb_select_io->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"NETWORK INPUT SIGNAL", L"0001-ROBOT GENERAL OUTPUT SIGNAL",
					L"1001-ROBOT GENERAL INPUT SIGNAL", L"2001-EXTERNAL INPUT SIGNAL", L"2701-NETWOEK INPUT SIGNAL", L"3001-EXTERNAL OUTPUT  SIGNAL"
			});
			this->cb_select_io->Location = System::Drawing::Point(98, 18);
			this->cb_select_io->Name = L"cb_select_io";
			this->cb_select_io->Size = System::Drawing::Size(130, 23);
			this->cb_select_io->TabIndex = 16;
			this->cb_select_io->SelectedIndexChanged += gcnew System::EventHandler(this, &GPIOForm::comboBox1_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(15, 49);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 15);
			this->label3->TabIndex = 15;
			this->label3->Text = L"PORT NUMBER:";
			// 
			// tb_portnum_write
			// 
			this->tb_portnum_write->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_portnum_write->Location = System::Drawing::Point(156, 47);
			this->tb_portnum_write->Name = L"tb_portnum_write";
			this->tb_portnum_write->Size = System::Drawing::Size(72, 23);
			this->tb_portnum_write->TabIndex = 14;
			this->tb_portnum_write->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// btn_on
			// 
			this->btn_on->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn_on->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_on->ForeColor = System::Drawing::Color::Transparent;
			this->btn_on->Location = System::Drawing::Point(39, 100);
			this->btn_on->Name = L"btn_on";
			this->btn_on->Size = System::Drawing::Size(79, 42);
			this->btn_on->TabIndex = 8;
			this->btn_on->Text = L"ON";
			this->btn_on->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_on->UseVisualStyleBackColor = false;
			this->btn_on->Click += gcnew System::EventHandler(this, &GPIOForm::btn_on_Click);
			// 
			// btn_off
			// 
			this->btn_off->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn_off->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_off->ForeColor = System::Drawing::Color::White;
			this->btn_off->Location = System::Drawing::Point(124, 100);
			this->btn_off->Name = L"btn_off";
			this->btn_off->Size = System::Drawing::Size(79, 42);
			this->btn_off->TabIndex = 7;
			this->btn_off->Text = L"OFF";
			this->btn_off->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_off->UseVisualStyleBackColor = false;
			this->btn_off->Click += gcnew System::EventHandler(this, &GPIOForm::btn_off_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tb_val);
			this->groupBox2->Controls->Add(this->btn_on);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->btn_off);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->tb_port_number);
			this->groupBox2->Location = System::Drawing::Point(12, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(236, 153);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"WRITE I/O";
			// 
			// tb_val
			// 
			this->tb_val->Location = System::Drawing::Point(147, 61);
			this->tb_val->Name = L"tb_val";
			this->tb_val->Size = System::Drawing::Size(56, 21);
			this->tb_val->TabIndex = 13;
			this->tb_val->Text = L"0";
			this->tb_val->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(93, 64);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 15);
			this->label2->TabIndex = 12;
			this->label2->Text = L"VALUE:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(41, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 15);
			this->label1->TabIndex = 11;
			this->label1->Text = L"PORT NUMBER:";
			// 
			// tb_port_number
			// 
			this->tb_port_number->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_port_number->Location = System::Drawing::Point(147, 32);
			this->tb_port_number->Name = L"tb_port_number";
			this->tb_port_number->Size = System::Drawing::Size(72, 23);
			this->tb_port_number->TabIndex = 10;
			this->tb_port_number->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// GPIOForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(259, 396);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"GPIOForm";
			this->Text = L"GPIO";
			this->Load += gcnew System::EventHandler(this, &GPIOForm::GPIOForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tb_portnum_write))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tb_port_number))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void GPIOForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		btn_apply();
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void btn_on_Click(System::Object^  sender, System::EventArgs^  e) {
	write_io_ON();
}
private: System::Void btn_off_Click(System::Object^  sender, System::EventArgs^  e) {
	write_io_OFF();
}
};
}
