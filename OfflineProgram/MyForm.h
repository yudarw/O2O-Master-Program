#pragma once
#include <iostream>

#define CUSTOM_COLOR_PINK 245,99,100
#define CUSTOM_COLOR_GRAY 78, 89, 111
#define CUSTOM_COLOR_DEFAULT (36,42,56)

namespace OfflineProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:

	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label1;




	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button11;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Panel^  panel10;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Panel^  panel9;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Panel^  panel8;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Panel^  panel7;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::Label^  label7;




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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->panel10->SuspendLayout();
			this->panel9->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(42)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->panel1->Controls->Add(this->button11);
			this->panel1->Controls->Add(this->button10);
			this->panel1->Controls->Add(this->button9);
			this->panel1->Controls->Add(this->button8);
			this->panel1->Controls->Add(this->button7);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(200, 612);
			this->panel1->TabIndex = 0;
			// 
			// button11
			// 
			this->button11->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->button11->FlatAppearance->BorderSize = 0;
			this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button11->ForeColor = System::Drawing::Color::White;
			this->button11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button11.Image")));
			this->button11->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button11->Location = System::Drawing::Point(0, 552);
			this->button11->Name = L"button11";
			this->button11->Padding = System::Windows::Forms::Padding(15, 0, 0, 0);
			this->button11->Size = System::Drawing::Size(200, 60);
			this->button11->TabIndex = 9;
			this->button11->Text = L"           Exit";
			this->button11->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button11->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button11->UseVisualStyleBackColor = true;
			// 
			// button10
			// 
			this->button10->Dock = System::Windows::Forms::DockStyle::Top;
			this->button10->FlatAppearance->BorderSize = 0;
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button10->ForeColor = System::Drawing::Color::White;
			this->button10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button10.Image")));
			this->button10->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button10->Location = System::Drawing::Point(0, 375);
			this->button10->Name = L"button10";
			this->button10->Padding = System::Windows::Forms::Padding(15, 0, 0, 0);
			this->button10->Size = System::Drawing::Size(200, 60);
			this->button10->TabIndex = 8;
			this->button10->Text = L"    Settings";
			this->button10->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button10->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button10->UseVisualStyleBackColor = true;
			this->button10->MouseEnter += gcnew System::EventHandler(this, &MyForm::button10_MouseEnter);
			this->button10->MouseLeave += gcnew System::EventHandler(this, &MyForm::button10_MouseLeave);
			// 
			// button9
			// 
			this->button9->Dock = System::Windows::Forms::DockStyle::Top;
			this->button9->FlatAppearance->BorderSize = 0;
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button9->ForeColor = System::Drawing::Color::White;
			this->button9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button9.Image")));
			this->button9->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button9->Location = System::Drawing::Point(0, 315);
			this->button9->Name = L"button9";
			this->button9->Padding = System::Windows::Forms::Padding(15, 0, 0, 0);
			this->button9->Size = System::Drawing::Size(200, 60);
			this->button9->TabIndex = 7;
			this->button9->Text = L"    Manual Control";
			this->button9->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button9->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button9->UseVisualStyleBackColor = true;
			this->button9->MouseEnter += gcnew System::EventHandler(this, &MyForm::button9_MouseEnter);
			this->button9->MouseLeave += gcnew System::EventHandler(this, &MyForm::button9_MouseLeave);
			// 
			// button8
			// 
			this->button8->Dock = System::Windows::Forms::DockStyle::Top;
			this->button8->FlatAppearance->BorderSize = 0;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->ForeColor = System::Drawing::Color::White;
			this->button8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button8.Image")));
			this->button8->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button8->Location = System::Drawing::Point(0, 255);
			this->button8->Name = L"button8";
			this->button8->Padding = System::Windows::Forms::Padding(15, 0, 0, 0);
			this->button8->Size = System::Drawing::Size(200, 60);
			this->button8->TabIndex = 6;
			this->button8->Text = L"    Robot Status";
			this->button8->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button8->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button8->UseVisualStyleBackColor = true;
			this->button8->MouseEnter += gcnew System::EventHandler(this, &MyForm::button8_MouseEnter);
			this->button8->MouseLeave += gcnew System::EventHandler(this, &MyForm::button8_MouseLeave);
			// 
			// button7
			// 
			this->button7->Dock = System::Windows::Forms::DockStyle::Top;
			this->button7->FlatAppearance->BorderSize = 0;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->ForeColor = System::Drawing::Color::White;
			this->button7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button7.Image")));
			this->button7->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button7->Location = System::Drawing::Point(0, 195);
			this->button7->Name = L"button7";
			this->button7->Padding = System::Windows::Forms::Padding(15, 0, 0, 0);
			this->button7->Size = System::Drawing::Size(200, 60);
			this->button7->TabIndex = 5;
			this->button7->Text = L"    Calibration";
			this->button7->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button7->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button7->UseVisualStyleBackColor = true;
			this->button7->MouseEnter += gcnew System::EventHandler(this, &MyForm::button7_MouseEnter);
			this->button7->MouseLeave += gcnew System::EventHandler(this, &MyForm::button7_MouseLeave);
			// 
			// button2
			// 
			this->button2->Dock = System::Windows::Forms::DockStyle::Top;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->Location = System::Drawing::Point(0, 135);
			this->button2->Name = L"button2";
			this->button2->Padding = System::Windows::Forms::Padding(15, 0, 0, 0);
			this->button2->Size = System::Drawing::Size(200, 60);
			this->button2->TabIndex = 4;
			this->button2->Text = L"    Trajectory Editor";
			this->button2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->MouseEnter += gcnew System::EventHandler(this, &MyForm::button2_MouseEnter);
			this->button2->MouseLeave += gcnew System::EventHandler(this, &MyForm::button2_MouseLeave);
			// 
			// button1
			// 
			this->button1->Dock = System::Windows::Forms::DockStyle::Top;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->Location = System::Drawing::Point(0, 75);
			this->button1->Name = L"button1";
			this->button1->Padding = System::Windows::Forms::Padding(15, 0, 0, 0);
			this->button1->Size = System::Drawing::Size(200, 60);
			this->button1->TabIndex = 3;
			this->button1->Text = L"    Program";
			this->button1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseEnter += gcnew System::EventHandler(this, &MyForm::button1_MouseEnter);
			this->button1->MouseLeave += gcnew System::EventHandler(this, &MyForm::button1_MouseLeave);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->panel4->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel4->Location = System::Drawing::Point(0, 70);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(200, 5);
			this->panel4->TabIndex = 2;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->panel2->Controls->Add(this->label1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(200, 70);
			this->panel2->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(61, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"MENU";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->tableLayoutPanel1->ColumnCount = 4;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->Controls->Add(this->button6, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->button5, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->button4, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->button3, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->tableLayoutPanel1->Location = System::Drawing::Point(200, 552);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(808, 60);
			this->tableLayoutPanel1->TabIndex = 2;
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(78)), static_cast<System::Int32>(static_cast<System::Byte>(89)),
				static_cast<System::Int32>(static_cast<System::Byte>(111)));
			this->button6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button6->FlatAppearance->BorderSize = 0;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->ForeColor = System::Drawing::Color::White;
			this->button6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button6.Image")));
			this->button6->Location = System::Drawing::Point(606, 0);
			this->button6->Margin = System::Windows::Forms::Padding(0);
			this->button6->Name = L"button6";
			this->button6->Padding = System::Windows::Forms::Padding(15, 0, 0, 0);
			this->button6->Size = System::Drawing::Size(202, 60);
			this->button6->TabIndex = 3;
			this->button6->Text = L"     Run Program";
			this->button6->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			this->button6->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::button6_MouseDown);
			this->button6->MouseEnter += gcnew System::EventHandler(this, &MyForm::button6_MouseEnter);
			this->button6->MouseLeave += gcnew System::EventHandler(this, &MyForm::button6_MouseLeave);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(78)), static_cast<System::Int32>(static_cast<System::Byte>(89)),
				static_cast<System::Int32>(static_cast<System::Byte>(111)));
			this->button5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->ForeColor = System::Drawing::Color::White;
			this->button5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.Image")));
			this->button5->Location = System::Drawing::Point(404, 0);
			this->button5->Margin = System::Windows::Forms::Padding(0);
			this->button5->Name = L"button5";
			this->button5->Padding = System::Windows::Forms::Padding(15, 0, 0, 0);
			this->button5->Size = System::Drawing::Size(202, 60);
			this->button5->TabIndex = 2;
			this->button5->Text = L"     Run Trajectory";
			this->button5->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button5->UseVisualStyleBackColor = false;
			this->button5->MouseEnter += gcnew System::EventHandler(this, &MyForm::button5_MouseEnter);
			this->button5->MouseLeave += gcnew System::EventHandler(this, &MyForm::button5_MouseLeave);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(78)), static_cast<System::Int32>(static_cast<System::Byte>(89)),
				static_cast<System::Int32>(static_cast<System::Byte>(111)));
			this->button4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->ForeColor = System::Drawing::Color::White;
			this->button4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.Image")));
			this->button4->Location = System::Drawing::Point(202, 0);
			this->button4->Margin = System::Windows::Forms::Padding(0);
			this->button4->Name = L"button4";
			this->button4->Padding = System::Windows::Forms::Padding(15, 0, 0, 0);
			this->button4->Size = System::Drawing::Size(202, 60);
			this->button4->TabIndex = 1;
			this->button4->Text = L"     Haptic Control";
			this->button4->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->MouseEnter += gcnew System::EventHandler(this, &MyForm::button4_MouseEnter);
			this->button4->MouseLeave += gcnew System::EventHandler(this, &MyForm::button4_MouseLeave);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(78)), static_cast<System::Int32>(static_cast<System::Byte>(89)),
				static_cast<System::Int32>(static_cast<System::Byte>(111)));
			this->button3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.Image")));
			this->button3->Location = System::Drawing::Point(0, 0);
			this->button3->Margin = System::Windows::Forms::Padding(0);
			this->button3->Name = L"button3";
			this->button3->Padding = System::Windows::Forms::Padding(15, 0, 0, 0);
			this->button3->Size = System::Drawing::Size(202, 60);
			this->button3->TabIndex = 0;
			this->button3->Text = L"     Initialization";
			this->button3->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->MouseEnter += gcnew System::EventHandler(this, &MyForm::button3_MouseEnter);
			this->button3->MouseLeave += gcnew System::EventHandler(this, &MyForm::button3_MouseLeave);
			// 
			// label2
			// 
			this->label2->Dock = System::Windows::Forms::DockStyle::Right;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(705, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(103, 70);
			this->label2->TabIndex = 0;
			this->label2->Text = L"100%";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(42)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->panel3->Controls->Add(this->tableLayoutPanel2);
			this->panel3->Controls->Add(this->label2);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel3->Location = System::Drawing::Point(200, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(808, 70);
			this->panel3->TabIndex = 3;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel2->Controls->Add(this->panel10, 2, 1);
			this->tableLayoutPanel2->Controls->Add(this->panel9, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->panel8, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->panel7, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->panel6, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->panel5, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Right;
			this->tableLayoutPanel2->Location = System::Drawing::Point(460, 0);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(245, 70);
			this->tableLayoutPanel2->TabIndex = 1;
			// 
			// panel10
			// 
			this->panel10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel10->Controls->Add(this->label4);
			this->panel10->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel10->Location = System::Drawing::Point(165, 38);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(77, 29);
			this->panel10->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(0, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(77, 29);
			this->label4->TabIndex = 1;
			this->label4->Text = L"HAPTIC";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel9
			// 
			this->panel9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel9->Controls->Add(this->label5);
			this->panel9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel9->Location = System::Drawing::Point(84, 38);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(75, 29);
			this->panel9->TabIndex = 4;
			// 
			// label5
			// 
			this->label5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(0, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(75, 29);
			this->label5->TabIndex = 1;
			this->label5->Text = L"SENSOR";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel8->Controls->Add(this->label8);
			this->panel8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel8->Location = System::Drawing::Point(3, 38);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(75, 29);
			this->panel8->TabIndex = 3;
			// 
			// label8
			// 
			this->label8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label8->ForeColor = System::Drawing::Color::White;
			this->label8->Location = System::Drawing::Point(0, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(75, 29);
			this->label8->TabIndex = 1;
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel7->Controls->Add(this->label3);
			this->panel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel7->Location = System::Drawing::Point(165, 3);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(77, 29);
			this->panel7->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::LimeGreen;
			this->label3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(0, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 29);
			this->label3->TabIndex = 0;
			this->label3->Text = L"ROBOT";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel6->Controls->Add(this->label6);
			this->panel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel6->Location = System::Drawing::Point(84, 3);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(75, 29);
			this->panel6->TabIndex = 1;
			// 
			// label6
			// 
			this->label6->BackColor = System::Drawing::Color::Red;
			this->label6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(0, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(75, 29);
			this->label6->TabIndex = 1;
			this->label6->Text = L"ALARM";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel5->Controls->Add(this->label7);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel5->Location = System::Drawing::Point(3, 3);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(75, 29);
			this->panel5->TabIndex = 0;
			// 
			// label7
			// 
			this->label7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(0, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(75, 29);
			this->label7->TabIndex = 1;
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1008, 612);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->panel1);
			this->ForeColor = System::Drawing::Color::White;
			this->IsMdiContainer = true;
			this->MinimumSize = System::Drawing::Size(1024, 576);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->panel10->ResumeLayout(false);
			this->panel9->ResumeLayout(false);
			this->panel8->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}
	private: System::Void button6_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	
	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		button1->BackColor = Color::FromArgb(CUSTOM_COLOR_PINK);
	}
	private: System::Void button1_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		button1->BackColor = Color::FromArgb(CUSTOM_COLOR_DEFAULT);
	}
	private: System::Void button2_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		button2->BackColor = Color::FromArgb(CUSTOM_COLOR_PINK);
	}
	private: System::Void button2_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		button2->BackColor = Color::FromArgb(CUSTOM_COLOR_DEFAULT);
	}
	private: System::Void button7_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		button7->BackColor = Color::FromArgb(CUSTOM_COLOR_PINK);
	}
	private: System::Void button7_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		button7->BackColor = Color::FromArgb(CUSTOM_COLOR_DEFAULT);
	}
	private: System::Void button8_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		button8->BackColor = Color::FromArgb(CUSTOM_COLOR_PINK);
	}
	private: System::Void button8_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		button8->BackColor = Color::FromArgb(CUSTOM_COLOR_DEFAULT);
	}
	private: System::Void button3_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		button3->BackColor = Color::FromArgb(CUSTOM_COLOR_PINK);
	}
	private: System::Void button3_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		button3->BackColor = Color::FromArgb(CUSTOM_COLOR_GRAY);
	}
	private: System::Void button4_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		button4->BackColor = Color::FromArgb(CUSTOM_COLOR_PINK);
	}
	private: System::Void button4_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		button4->BackColor = Color::FromArgb(CUSTOM_COLOR_GRAY);
	}
	private: System::Void button5_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		button5->BackColor = Color::FromArgb(CUSTOM_COLOR_PINK);
	}
	private: System::Void button5_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		button5->BackColor = Color::FromArgb(CUSTOM_COLOR_GRAY);
	}
	private: System::Void button6_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		button6->BackColor = Color::FromArgb(CUSTOM_COLOR_PINK);
	}
	private: System::Void button6_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		button6->BackColor = Color::FromArgb(CUSTOM_COLOR_GRAY);
	}
	private: System::Void button9_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		button9->BackColor = Color::FromArgb(CUSTOM_COLOR_PINK);
	}
	private: System::Void button9_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		button9->BackColor = Color::FromArgb(CUSTOM_COLOR_DEFAULT);
	}
	private: System::Void button10_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		button10->BackColor = Color::FromArgb(CUSTOM_COLOR_PINK);
	}
	private: System::Void button10_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		button10->BackColor = Color::FromArgb(CUSTOM_COLOR_DEFAULT);
	}
};
}
