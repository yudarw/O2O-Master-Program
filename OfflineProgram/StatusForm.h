#pragma once

namespace OfflineProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StatusForm
	/// </summary>
	public ref class StatusForm : public System::Windows::Forms::Form
	{
	public:
		StatusForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void on_timer();
		void btn_setPosition();
		void btn_copyPos();


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StatusForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  tbPosR;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  tbPosZ;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  tbPosP;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  tbPosY;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  tbPosW;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  tbPosX;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::ProgressBar^  progressBar5;
	private: System::Windows::Forms::ProgressBar^  progressBar6;
	private: System::Windows::Forms::ProgressBar^  progressBar3;
	private: System::Windows::Forms::ProgressBar^  progressBar4;
	private: System::Windows::Forms::ProgressBar^  progressBar2;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::TextBox^  tbMz;

	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TextBox^  tbMy;

	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::TextBox^  tbMx;

	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  tbFz;

	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  tbFy;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  tbFx;

	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::TextBox^  tbHposR;

	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::TextBox^  tbHposZ;

	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::TextBox^  tbHposP;

	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::TextBox^  tbHposY;

	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::TextBox^  tbHposW;

	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::TextBox^  tbHposX;

	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  labelMoving;
	private: System::Windows::Forms::Label^  label23;
private: System::Windows::Forms::GroupBox^  groupBox1;
private: System::Windows::Forms::TextBox^  tbSetR;

private: System::Windows::Forms::Label^  label34;
private: System::Windows::Forms::TextBox^  tbSetP;

private: System::Windows::Forms::Label^  label35;
private: System::Windows::Forms::TextBox^  tbSetW;

private: System::Windows::Forms::Label^  label36;
private: System::Windows::Forms::TextBox^  tbSetZ;

private: System::Windows::Forms::Label^  label33;
private: System::Windows::Forms::TextBox^  tbSetY;

private: System::Windows::Forms::Label^  label32;
private: System::Windows::Forms::TextBox^  tbSetX;

private: System::Windows::Forms::Label^  label31;
private: System::Windows::Forms::Button^  button32;
private: System::Windows::Forms::Button^  button1;
	private: System::ComponentModel::IContainer^  components;

	protected:






































































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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(StatusForm::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button32 = (gcnew System::Windows::Forms::Button());
			this->tbSetR = (gcnew System::Windows::Forms::TextBox());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->tbSetP = (gcnew System::Windows::Forms::TextBox());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->tbSetW = (gcnew System::Windows::Forms::TextBox());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->tbSetZ = (gcnew System::Windows::Forms::TextBox());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->tbSetY = (gcnew System::Windows::Forms::TextBox());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->tbSetX = (gcnew System::Windows::Forms::TextBox());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->labelMoving = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tbPosR = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbPosZ = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tbPosP = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tbPosY = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tbPosW = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tbPosX = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->progressBar5 = (gcnew System::Windows::Forms::ProgressBar());
			this->progressBar6 = (gcnew System::Windows::Forms::ProgressBar());
			this->progressBar3 = (gcnew System::Windows::Forms::ProgressBar());
			this->progressBar4 = (gcnew System::Windows::Forms::ProgressBar());
			this->progressBar2 = (gcnew System::Windows::Forms::ProgressBar());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->tbMz = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->tbMy = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->tbMx = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->tbFz = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->tbFy = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->tbFx = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->tbHposR = (gcnew System::Windows::Forms::TextBox());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->tbHposZ = (gcnew System::Windows::Forms::TextBox());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->tbHposP = (gcnew System::Windows::Forms::TextBox());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->tbHposY = (gcnew System::Windows::Forms::TextBox());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->tbHposW = (gcnew System::Windows::Forms::TextBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->tbHposX = (gcnew System::Windows::Forms::TextBox());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Alignment = System::Windows::Forms::TabAlignment::Bottom;
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabControl1->ItemSize = System::Drawing::Size(120, 40);
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Multiline = true;
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(711, 466);
			this->tabControl1->SizeMode = System::Windows::Forms::TabSizeMode::Fixed;
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::White;
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Controls->Add(this->labelMoving);
			this->tabPage1->Controls->Add(this->label23);
			this->tabPage1->Controls->Add(this->label8);
			this->tabPage1->Controls->Add(this->label7);
			this->tabPage1->Controls->Add(this->tbPosR);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->tbPosZ);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->tbPosP);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->tbPosY);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->tbPosW);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->tbPosX);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Location = System::Drawing::Point(4, 4);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(703, 418);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"POSITION";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->button32);
			this->groupBox1->Controls->Add(this->tbSetR);
			this->groupBox1->Controls->Add(this->label34);
			this->groupBox1->Controls->Add(this->tbSetP);
			this->groupBox1->Controls->Add(this->label35);
			this->groupBox1->Controls->Add(this->tbSetW);
			this->groupBox1->Controls->Add(this->label36);
			this->groupBox1->Controls->Add(this->tbSetZ);
			this->groupBox1->Controls->Add(this->label33);
			this->groupBox1->Controls->Add(this->tbSetY);
			this->groupBox1->Controls->Add(this->label32);
			this->groupBox1->Controls->Add(this->tbSetX);
			this->groupBox1->Controls->Add(this->label31);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(8, 241);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(685, 161);
			this->groupBox1->TabIndex = 16;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"SET POSITION";
			// 
			// button32
			// 
			this->button32->BackColor = System::Drawing::Color::Transparent;
			this->button32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button32->ForeColor = System::Drawing::Color::Black;
			this->button32->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button32.Image")));
			this->button32->Location = System::Drawing::Point(553, 55);
			this->button32->Name = L"button32";
			this->button32->Size = System::Drawing::Size(101, 76);
			this->button32->TabIndex = 29;
			this->button32->Text = L"Set Position";
			this->button32->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button32->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->button32->UseVisualStyleBackColor = false;
			this->button32->Click += gcnew System::EventHandler(this, &StatusForm::button32_Click);
			// 
			// tbSetR
			// 
			this->tbSetR->BackColor = System::Drawing::Color::White;
			this->tbSetR->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbSetR->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbSetR->Location = System::Drawing::Point(245, 114);
			this->tbSetR->Name = L"tbSetR";
			this->tbSetR->Size = System::Drawing::Size(116, 30);
			this->tbSetR->TabIndex = 28;
			this->tbSetR->Text = L"000.000";
			this->tbSetR->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label34->ForeColor = System::Drawing::Color::Black;
			this->label34->Location = System::Drawing::Point(205, 118);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(34, 22);
			this->label34->TabIndex = 27;
			this->label34->Text = L"R:";
			// 
			// tbSetP
			// 
			this->tbSetP->BackColor = System::Drawing::Color::White;
			this->tbSetP->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbSetP->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbSetP->Location = System::Drawing::Point(245, 78);
			this->tbSetP->Name = L"tbSetP";
			this->tbSetP->Size = System::Drawing::Size(116, 30);
			this->tbSetP->TabIndex = 26;
			this->tbSetP->Text = L"000.000";
			this->tbSetP->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label35->ForeColor = System::Drawing::Color::Black;
			this->label35->Location = System::Drawing::Point(205, 82);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(34, 22);
			this->label35->TabIndex = 25;
			this->label35->Text = L"P:";
			// 
			// tbSetW
			// 
			this->tbSetW->BackColor = System::Drawing::Color::White;
			this->tbSetW->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbSetW->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbSetW->Location = System::Drawing::Point(245, 42);
			this->tbSetW->Name = L"tbSetW";
			this->tbSetW->Size = System::Drawing::Size(116, 30);
			this->tbSetW->TabIndex = 24;
			this->tbSetW->Text = L"000.000";
			this->tbSetW->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label36->ForeColor = System::Drawing::Color::Black;
			this->label36->Location = System::Drawing::Point(205, 46);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(34, 22);
			this->label36->TabIndex = 23;
			this->label36->Text = L"W:";
			// 
			// tbSetZ
			// 
			this->tbSetZ->BackColor = System::Drawing::Color::White;
			this->tbSetZ->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbSetZ->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbSetZ->Location = System::Drawing::Point(67, 114);
			this->tbSetZ->Name = L"tbSetZ";
			this->tbSetZ->Size = System::Drawing::Size(116, 30);
			this->tbSetZ->TabIndex = 22;
			this->tbSetZ->Text = L"000.000";
			this->tbSetZ->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label33->ForeColor = System::Drawing::Color::Black;
			this->label33->Location = System::Drawing::Point(27, 118);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(34, 22);
			this->label33->TabIndex = 21;
			this->label33->Text = L"Z:";
			// 
			// tbSetY
			// 
			this->tbSetY->BackColor = System::Drawing::Color::White;
			this->tbSetY->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbSetY->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbSetY->Location = System::Drawing::Point(67, 78);
			this->tbSetY->Name = L"tbSetY";
			this->tbSetY->Size = System::Drawing::Size(116, 30);
			this->tbSetY->TabIndex = 20;
			this->tbSetY->Text = L"000.000";
			this->tbSetY->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label32->ForeColor = System::Drawing::Color::Black;
			this->label32->Location = System::Drawing::Point(27, 82);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(34, 22);
			this->label32->TabIndex = 19;
			this->label32->Text = L"Y:";
			// 
			// tbSetX
			// 
			this->tbSetX->BackColor = System::Drawing::Color::White;
			this->tbSetX->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbSetX->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbSetX->Location = System::Drawing::Point(67, 42);
			this->tbSetX->Name = L"tbSetX";
			this->tbSetX->Size = System::Drawing::Size(116, 30);
			this->tbSetX->TabIndex = 18;
			this->tbSetX->Text = L"000.000";
			this->tbSetX->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label31->ForeColor = System::Drawing::Color::Black;
			this->label31->Location = System::Drawing::Point(27, 46);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(34, 22);
			this->label31->TabIndex = 17;
			this->label31->Text = L"X:";
			// 
			// labelMoving
			// 
			this->labelMoving->AutoSize = true;
			this->labelMoving->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelMoving->ForeColor = System::Drawing::Color::Black;
			this->labelMoving->Location = System::Drawing::Point(150, 179);
			this->labelMoving->Name = L"labelMoving";
			this->labelMoving->Size = System::Drawing::Size(58, 22);
			this->labelMoving->TabIndex = 15;
			this->labelMoving->Text = L"TRUE";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->ForeColor = System::Drawing::Color::Black;
			this->label23->Location = System::Drawing::Point(37, 179);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(94, 22);
			this->label23->TabIndex = 14;
			this->label23->Text = L"MOVING:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Black;
			this->label8->Location = System::Drawing::Point(557, 25);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(94, 22);
			this->label8->TabIndex = 13;
			this->label8->Text = L"TOOL: 8";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Black;
			this->label7->Location = System::Drawing::Point(30, 25);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(178, 22);
			this->label7->TabIndex = 12;
			this->label7->Text = L"ROBOT POSITION";
			// 
			// tbPosR
			// 
			this->tbPosR->BackColor = System::Drawing::Color::White;
			this->tbPosR->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPosR->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPosR->Location = System::Drawing::Point(506, 116);
			this->tbPosR->Name = L"tbPosR";
			this->tbPosR->Size = System::Drawing::Size(125, 23);
			this->tbPosR->TabIndex = 11;
			this->tbPosR->Text = L"0.0";
			this->tbPosR->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Black;
			this->label5->Location = System::Drawing::Point(461, 116);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(34, 22);
			this->label5->TabIndex = 10;
			this->label5->Text = L"R:";
			// 
			// tbPosZ
			// 
			this->tbPosZ->BackColor = System::Drawing::Color::White;
			this->tbPosZ->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPosZ->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPosZ->Location = System::Drawing::Point(506, 83);
			this->tbPosZ->Name = L"tbPosZ";
			this->tbPosZ->Size = System::Drawing::Size(125, 23);
			this->tbPosZ->TabIndex = 9;
			this->tbPosZ->Text = L"0.0";
			this->tbPosZ->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Black;
			this->label6->Location = System::Drawing::Point(461, 83);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(34, 22);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Z:";
			// 
			// tbPosP
			// 
			this->tbPosP->BackColor = System::Drawing::Color::White;
			this->tbPosP->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPosP->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPosP->Location = System::Drawing::Point(310, 116);
			this->tbPosP->Name = L"tbPosP";
			this->tbPosP->Size = System::Drawing::Size(126, 23);
			this->tbPosP->TabIndex = 7;
			this->tbPosP->Text = L"0.0";
			this->tbPosP->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(266, 116);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(34, 22);
			this->label3->TabIndex = 6;
			this->label3->Text = L"P:";
			// 
			// tbPosY
			// 
			this->tbPosY->BackColor = System::Drawing::Color::White;
			this->tbPosY->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPosY->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPosY->Location = System::Drawing::Point(310, 83);
			this->tbPosY->Name = L"tbPosY";
			this->tbPosY->Size = System::Drawing::Size(126, 23);
			this->tbPosY->TabIndex = 5;
			this->tbPosY->Text = L"0.0";
			this->tbPosY->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(266, 83);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(34, 22);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Y:";
			// 
			// tbPosW
			// 
			this->tbPosW->BackColor = System::Drawing::Color::White;
			this->tbPosW->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPosW->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPosW->Location = System::Drawing::Point(117, 116);
			this->tbPosW->Name = L"tbPosW";
			this->tbPosW->Size = System::Drawing::Size(125, 23);
			this->tbPosW->TabIndex = 3;
			this->tbPosW->Text = L"0.0";
			this->tbPosW->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(72, 116);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(34, 22);
			this->label2->TabIndex = 2;
			this->label2->Text = L"W:";
			// 
			// tbPosX
			// 
			this->tbPosX->BackColor = System::Drawing::Color::White;
			this->tbPosX->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPosX->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPosX->Location = System::Drawing::Point(117, 83);
			this->tbPosX->Name = L"tbPosX";
			this->tbPosX->Size = System::Drawing::Size(125, 23);
			this->tbPosX->TabIndex = 1;
			this->tbPosX->Text = L"0.0";
			this->tbPosX->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(72, 83);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(34, 22);
			this->label1->TabIndex = 0;
			this->label1->Text = L"X:";
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->tabPage2->Controls->Add(this->label22);
			this->tabPage2->Controls->Add(this->radioButton2);
			this->tabPage2->Controls->Add(this->radioButton1);
			this->tabPage2->Controls->Add(this->progressBar5);
			this->tabPage2->Controls->Add(this->progressBar6);
			this->tabPage2->Controls->Add(this->progressBar3);
			this->tabPage2->Controls->Add(this->progressBar4);
			this->tabPage2->Controls->Add(this->progressBar2);
			this->tabPage2->Controls->Add(this->progressBar1);
			this->tabPage2->Controls->Add(this->label21);
			this->tabPage2->Controls->Add(this->label15);
			this->tabPage2->Controls->Add(this->label16);
			this->tabPage2->Controls->Add(this->label17);
			this->tabPage2->Controls->Add(this->label18);
			this->tabPage2->Controls->Add(this->label19);
			this->tabPage2->Controls->Add(this->label20);
			this->tabPage2->Controls->Add(this->tbMz);
			this->tabPage2->Controls->Add(this->label13);
			this->tabPage2->Controls->Add(this->tbMy);
			this->tabPage2->Controls->Add(this->label14);
			this->tabPage2->Controls->Add(this->tbMx);
			this->tabPage2->Controls->Add(this->label11);
			this->tabPage2->Controls->Add(this->tbFz);
			this->tabPage2->Controls->Add(this->label12);
			this->tabPage2->Controls->Add(this->tbFy);
			this->tabPage2->Controls->Add(this->label9);
			this->tabPage2->Controls->Add(this->tbFx);
			this->tabPage2->Controls->Add(this->label10);
			this->tabPage2->Location = System::Drawing::Point(4, 4);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(703, 418);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"FORCE";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label22->ForeColor = System::Drawing::Color::Black;
			this->label22->Location = System::Drawing::Point(591, 18);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(70, 22);
			this->label22->TabIndex = 31;
			this->label22->Text = L"COM 7";
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Checked = true;
			this->radioButton2->ForeColor = System::Drawing::Color::Black;
			this->radioButton2->Location = System::Drawing::Point(304, 68);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(190, 24);
			this->radioButton2->TabIndex = 30;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"CALIBRATED FORCE";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->ForeColor = System::Drawing::Color::Black;
			this->radioButton1->Location = System::Drawing::Point(65, 68);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(170, 24);
			this->radioButton1->TabIndex = 29;
			this->radioButton1->Text = L"ORIGINAL FORCE";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// progressBar5
			// 
			this->progressBar5->Location = System::Drawing::Point(122, 278);
			this->progressBar5->Name = L"progressBar5";
			this->progressBar5->Size = System::Drawing::Size(158, 26);
			this->progressBar5->TabIndex = 28;
			this->progressBar5->Value = 4;
			// 
			// progressBar6
			// 
			this->progressBar6->Location = System::Drawing::Point(122, 244);
			this->progressBar6->Name = L"progressBar6";
			this->progressBar6->Size = System::Drawing::Size(158, 26);
			this->progressBar6->TabIndex = 27;
			this->progressBar6->Value = 1;
			// 
			// progressBar3
			// 
			this->progressBar3->Location = System::Drawing::Point(122, 212);
			this->progressBar3->Name = L"progressBar3";
			this->progressBar3->Size = System::Drawing::Size(158, 26);
			this->progressBar3->TabIndex = 25;
			this->progressBar3->Value = 3;
			// 
			// progressBar4
			// 
			this->progressBar4->Location = System::Drawing::Point(122, 179);
			this->progressBar4->Name = L"progressBar4";
			this->progressBar4->Size = System::Drawing::Size(158, 26);
			this->progressBar4->TabIndex = 25;
			this->progressBar4->Value = 21;
			// 
			// progressBar2
			// 
			this->progressBar2->Location = System::Drawing::Point(122, 147);
			this->progressBar2->Name = L"progressBar2";
			this->progressBar2->Size = System::Drawing::Size(158, 26);
			this->progressBar2->TabIndex = 25;
			this->progressBar2->Value = 55;
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(122, 115);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(158, 26);
			this->progressBar1->TabIndex = 23;
			this->progressBar1->Value = 10;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->ForeColor = System::Drawing::Color::Black;
			this->label21->Location = System::Drawing::Point(17, 18);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(166, 22);
			this->label21->TabIndex = 22;
			this->label21->Text = L"FORCE SENSOR ";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->ForeColor = System::Drawing::Color::Black;
			this->label15->Location = System::Drawing::Point(444, 278);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(34, 22);
			this->label15->TabIndex = 21;
			this->label15->Text = L"Nm";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->ForeColor = System::Drawing::Color::Black;
			this->label16->Location = System::Drawing::Point(444, 245);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(34, 22);
			this->label16->TabIndex = 20;
			this->label16->Text = L"Nm";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->ForeColor = System::Drawing::Color::Black;
			this->label17->Location = System::Drawing::Point(444, 213);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(34, 22);
			this->label17->TabIndex = 19;
			this->label17->Text = L"Nm";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->ForeColor = System::Drawing::Color::Black;
			this->label18->Location = System::Drawing::Point(444, 180);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(22, 22);
			this->label18->TabIndex = 18;
			this->label18->Text = L"N";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->ForeColor = System::Drawing::Color::Black;
			this->label19->Location = System::Drawing::Point(444, 147);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(22, 22);
			this->label19->TabIndex = 17;
			this->label19->Text = L"N";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->ForeColor = System::Drawing::Color::Black;
			this->label20->Location = System::Drawing::Point(444, 115);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(22, 22);
			this->label20->TabIndex = 16;
			this->label20->Text = L"N";
			// 
			// tbMz
			// 
			this->tbMz->BackColor = System::Drawing::Color::White;
			this->tbMz->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbMz->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbMz->Location = System::Drawing::Point(303, 278);
			this->tbMz->Name = L"tbMz";
			this->tbMz->Size = System::Drawing::Size(125, 23);
			this->tbMz->TabIndex = 15;
			this->tbMz->Text = L"0.0";
			this->tbMz->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::Black;
			this->label13->Location = System::Drawing::Point(63, 278);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(46, 22);
			this->label13->TabIndex = 14;
			this->label13->Text = L"Mz:";
			// 
			// tbMy
			// 
			this->tbMy->BackColor = System::Drawing::Color::White;
			this->tbMy->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbMy->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbMy->Location = System::Drawing::Point(303, 245);
			this->tbMy->Name = L"tbMy";
			this->tbMy->Size = System::Drawing::Size(125, 23);
			this->tbMy->TabIndex = 13;
			this->tbMy->Text = L"0.0";
			this->tbMy->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->ForeColor = System::Drawing::Color::Black;
			this->label14->Location = System::Drawing::Point(63, 245);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(46, 22);
			this->label14->TabIndex = 12;
			this->label14->Text = L"My:";
			// 
			// tbMx
			// 
			this->tbMx->BackColor = System::Drawing::Color::White;
			this->tbMx->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbMx->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbMx->Location = System::Drawing::Point(303, 213);
			this->tbMx->Name = L"tbMx";
			this->tbMx->Size = System::Drawing::Size(125, 23);
			this->tbMx->TabIndex = 11;
			this->tbMx->Text = L"0.0";
			this->tbMx->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::Black;
			this->label11->Location = System::Drawing::Point(63, 213);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(46, 22);
			this->label11->TabIndex = 10;
			this->label11->Text = L"Mx:";
			// 
			// tbFz
			// 
			this->tbFz->BackColor = System::Drawing::Color::White;
			this->tbFz->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbFz->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbFz->Location = System::Drawing::Point(303, 180);
			this->tbFz->Name = L"tbFz";
			this->tbFz->Size = System::Drawing::Size(125, 23);
			this->tbFz->TabIndex = 9;
			this->tbFz->Text = L"0.0";
			this->tbFz->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::Black;
			this->label12->Location = System::Drawing::Point(63, 180);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(46, 22);
			this->label12->TabIndex = 8;
			this->label12->Text = L"Fz:";
			// 
			// tbFy
			// 
			this->tbFy->BackColor = System::Drawing::Color::White;
			this->tbFy->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbFy->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbFy->Location = System::Drawing::Point(303, 147);
			this->tbFy->Name = L"tbFy";
			this->tbFy->Size = System::Drawing::Size(125, 23);
			this->tbFy->TabIndex = 7;
			this->tbFy->Text = L"0.0";
			this->tbFy->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::Black;
			this->label9->Location = System::Drawing::Point(63, 147);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(46, 22);
			this->label9->TabIndex = 6;
			this->label9->Text = L"Fy:";
			// 
			// tbFx
			// 
			this->tbFx->BackColor = System::Drawing::Color::White;
			this->tbFx->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbFx->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbFx->Location = System::Drawing::Point(303, 115);
			this->tbFx->Name = L"tbFx";
			this->tbFx->Size = System::Drawing::Size(125, 23);
			this->tbFx->TabIndex = 5;
			this->tbFx->Text = L"0.0";
			this->tbFx->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::Black;
			this->label10->Location = System::Drawing::Point(63, 115);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(46, 22);
			this->label10->TabIndex = 4;
			this->label10->Text = L"Fx:";
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->tabPage3->Controls->Add(this->label24);
			this->tabPage3->Controls->Add(this->tbHposR);
			this->tabPage3->Controls->Add(this->label25);
			this->tabPage3->Controls->Add(this->tbHposZ);
			this->tabPage3->Controls->Add(this->label26);
			this->tabPage3->Controls->Add(this->tbHposP);
			this->tabPage3->Controls->Add(this->label27);
			this->tabPage3->Controls->Add(this->tbHposY);
			this->tabPage3->Controls->Add(this->label28);
			this->tabPage3->Controls->Add(this->tbHposW);
			this->tabPage3->Controls->Add(this->label29);
			this->tabPage3->Controls->Add(this->tbHposX);
			this->tabPage3->Controls->Add(this->label30);
			this->tabPage3->Location = System::Drawing::Point(4, 4);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(703, 418);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"HAPTIC";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label24->ForeColor = System::Drawing::Color::Black;
			this->label24->Location = System::Drawing::Point(38, 39);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(190, 22);
			this->label24->TabIndex = 26;
			this->label24->Text = L"HAPTIC POSITION";
			// 
			// tbHposR
			// 
			this->tbHposR->BackColor = System::Drawing::Color::White;
			this->tbHposR->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbHposR->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbHposR->Location = System::Drawing::Point(490, 126);
			this->tbHposR->Name = L"tbHposR";
			this->tbHposR->Size = System::Drawing::Size(125, 23);
			this->tbHposR->TabIndex = 25;
			this->tbHposR->Text = L"0.0";
			this->tbHposR->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label25->ForeColor = System::Drawing::Color::Black;
			this->label25->Location = System::Drawing::Point(446, 126);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(34, 22);
			this->label25->TabIndex = 24;
			this->label25->Text = L"R:";
			// 
			// tbHposZ
			// 
			this->tbHposZ->BackColor = System::Drawing::Color::White;
			this->tbHposZ->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbHposZ->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbHposZ->Location = System::Drawing::Point(490, 93);
			this->tbHposZ->Name = L"tbHposZ";
			this->tbHposZ->Size = System::Drawing::Size(125, 23);
			this->tbHposZ->TabIndex = 23;
			this->tbHposZ->Text = L"0.0";
			this->tbHposZ->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label26->ForeColor = System::Drawing::Color::Black;
			this->label26->Location = System::Drawing::Point(446, 93);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(34, 22);
			this->label26->TabIndex = 22;
			this->label26->Text = L"Z:";
			// 
			// tbHposP
			// 
			this->tbHposP->BackColor = System::Drawing::Color::White;
			this->tbHposP->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbHposP->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbHposP->Location = System::Drawing::Point(295, 126);
			this->tbHposP->Name = L"tbHposP";
			this->tbHposP->Size = System::Drawing::Size(126, 23);
			this->tbHposP->TabIndex = 21;
			this->tbHposP->Text = L"0.0";
			this->tbHposP->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label27->ForeColor = System::Drawing::Color::Black;
			this->label27->Location = System::Drawing::Point(250, 126);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(34, 22);
			this->label27->TabIndex = 20;
			this->label27->Text = L"P:";
			// 
			// tbHposY
			// 
			this->tbHposY->BackColor = System::Drawing::Color::White;
			this->tbHposY->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbHposY->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbHposY->Location = System::Drawing::Point(295, 93);
			this->tbHposY->Name = L"tbHposY";
			this->tbHposY->Size = System::Drawing::Size(126, 23);
			this->tbHposY->TabIndex = 19;
			this->tbHposY->Text = L"0.0";
			this->tbHposY->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label28->ForeColor = System::Drawing::Color::Black;
			this->label28->Location = System::Drawing::Point(250, 93);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(34, 22);
			this->label28->TabIndex = 18;
			this->label28->Text = L"Y:";
			// 
			// tbHposW
			// 
			this->tbHposW->BackColor = System::Drawing::Color::White;
			this->tbHposW->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbHposW->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbHposW->Location = System::Drawing::Point(101, 126);
			this->tbHposW->Name = L"tbHposW";
			this->tbHposW->Size = System::Drawing::Size(125, 23);
			this->tbHposW->TabIndex = 17;
			this->tbHposW->Text = L"0.0";
			this->tbHposW->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label29->ForeColor = System::Drawing::Color::Black;
			this->label29->Location = System::Drawing::Point(56, 126);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(34, 22);
			this->label29->TabIndex = 16;
			this->label29->Text = L"W:";
			// 
			// tbHposX
			// 
			this->tbHposX->BackColor = System::Drawing::Color::White;
			this->tbHposX->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbHposX->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbHposX->Location = System::Drawing::Point(101, 93);
			this->tbHposX->Name = L"tbHposX";
			this->tbHposX->Size = System::Drawing::Size(125, 23);
			this->tbHposX->TabIndex = 15;
			this->tbHposX->Text = L"0.0";
			this->tbHposX->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label30->ForeColor = System::Drawing::Color::Black;
			this->label30->Location = System::Drawing::Point(56, 93);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(34, 22);
			this->label30->TabIndex = 14;
			this->label30->Text = L"X:";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &StatusForm::timer1_Tick);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(433, 55);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(101, 76);
			this->button1->TabIndex = 30;
			this->button1->Text = L"Copy";
			this->button1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &StatusForm::button1_Click);
			// 
			// StatusForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(711, 466);
			this->Controls->Add(this->tabControl1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::Transparent;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"StatusForm";
			this->Text = L"ROBOT STATUS";
			this->Load += gcnew System::EventHandler(this, &StatusForm::StatusForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		on_timer();
	}
private: System::Void StatusForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button32_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_setPosition();
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_copyPos();
}
};
}
