#pragma once

namespace OfflineProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ModifyPointForm
	/// </summary>
	public ref class ModifyPointForm : public System::Windows::Forms::Form
	{
	public:
		ModifyPointForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void on_init();
		void btn_apply();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ModifyPointForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::TextBox^  tbY;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  tbZ;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  tbR;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  tbP;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  tbW;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  tbX;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  button1;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ModifyPointForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->tbY = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tbZ = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tbR = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tbP = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbW = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tbX = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 39);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(19, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"X";
			// 
			// button14
			// 
			this->button14->BackColor = System::Drawing::Color::Transparent;
			this->button14->ForeColor = System::Drawing::Color::Black;
			this->button14->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button14.Image")));
			this->button14->Location = System::Drawing::Point(224, 155);
			this->button14->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(145, 59);
			this->button14->TabIndex = 15;
			this->button14->Text = L"  Apply";
			this->button14->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button14->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button14->UseVisualStyleBackColor = false;
			this->button14->Click += gcnew System::EventHandler(this, &ModifyPointForm::button14_Click);
			// 
			// tbY
			// 
			this->tbY->Location = System::Drawing::Point(179, 35);
			this->tbY->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tbY->Name = L"tbY";
			this->tbY->Size = System::Drawing::Size(102, 27);
			this->tbY->TabIndex = 17;
			this->tbY->Text = L"000.000";
			this->tbY->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(150, 39);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(19, 20);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Y";
			// 
			// tbZ
			// 
			this->tbZ->Location = System::Drawing::Point(317, 35);
			this->tbZ->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tbZ->Name = L"tbZ";
			this->tbZ->Size = System::Drawing::Size(102, 27);
			this->tbZ->TabIndex = 19;
			this->tbZ->Text = L"000.000";
			this->tbZ->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(289, 39);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(19, 20);
			this->label3->TabIndex = 18;
			this->label3->Text = L"Z";
			// 
			// tbR
			// 
			this->tbR->Location = System::Drawing::Point(317, 70);
			this->tbR->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tbR->Name = L"tbR";
			this->tbR->Size = System::Drawing::Size(102, 27);
			this->tbR->TabIndex = 25;
			this->tbR->Text = L"000.000";
			this->tbR->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(289, 74);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(19, 20);
			this->label4->TabIndex = 24;
			this->label4->Text = L"R";
			// 
			// tbP
			// 
			this->tbP->Location = System::Drawing::Point(179, 70);
			this->tbP->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tbP->Name = L"tbP";
			this->tbP->Size = System::Drawing::Size(102, 27);
			this->tbP->TabIndex = 23;
			this->tbP->Text = L"000.000";
			this->tbP->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(150, 74);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(19, 20);
			this->label5->TabIndex = 22;
			this->label5->Text = L"P";
			// 
			// tbW
			// 
			this->tbW->Location = System::Drawing::Point(43, 70);
			this->tbW->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tbW->Name = L"tbW";
			this->tbW->Size = System::Drawing::Size(99, 27);
			this->tbW->TabIndex = 21;
			this->tbW->Text = L"000.000";
			this->tbW->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(15, 74);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(19, 20);
			this->label6->TabIndex = 20;
			this->label6->Text = L"W";
			// 
			// tbX
			// 
			this->tbX->Location = System::Drawing::Point(43, 35);
			this->tbX->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tbX->Name = L"tbX";
			this->tbX->Size = System::Drawing::Size(99, 27);
			this->tbX->TabIndex = 1;
			this->tbX->Text = L"000.000";
			this->tbX->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->tbR);
			this->groupBox1->Controls->Add(this->button14);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->tbX);
			this->groupBox1->Controls->Add(this->tbP);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->tbY);
			this->groupBox1->Controls->Add(this->tbW);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->tbZ);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(15, 15);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Size = System::Drawing::Size(436, 221);
			this->groupBox1->TabIndex = 26;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Position";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(60, 155);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(145, 59);
			this->button1->TabIndex = 26;
			this->button1->Text = L"Cancel";
			this->button1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &ModifyPointForm::button1_Click);
			// 
			// ModifyPointForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(468, 249);
			this->Controls->Add(this->groupBox1);
			this->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"ModifyPointForm";
			this->Text = L"Point Modification";
			this->Load += gcnew System::EventHandler(this, &ModifyPointForm::ModifyPointForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ModifyPointForm_Load(System::Object^  sender, System::EventArgs^  e) {
		on_init();
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_apply();
}
};
}
