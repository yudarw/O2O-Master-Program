#pragma once



namespace OfflineProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TrajectoryCalibrationForm
	/// </summary>
	public ref class TrajectoryCalibrationForm : public System::Windows::Forms::Form
	{
	public:
		TrajectoryCalibrationForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void on_timer();
		void on_init();
		void update_data();
		void update_origin();
		void update_method();
		void btn_apply();
		void set_center_pos();
		void set_x_pos();
		void set_y_pos();
		void btn_read_current_pos();
		void btn_move_to_origin();
		void btn_apply_offset();

	private: System::Windows::Forms::Button^  button6;
	public:
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label_ypos;

	private: System::Windows::Forms::Label^  label_xpos;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Button^  btnApplyOffset;

	private: System::Windows::Forms::TextBox^  tbOffsetZ;

	private: System::Windows::Forms::TextBox^  tbOffsetY;

	private: System::Windows::Forms::TextBox^  tbOffsetX;


			 int  set_steps;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TrajectoryCalibrationForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  tbPosX;


	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  tbPosW;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  tbPosP;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  tbPosY;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  tbPosR;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  tbPosZ;
	private: System::Windows::Forms::Label^  labelComment;
	private: System::Windows::Forms::Label^  label_center;









	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::ComboBox^  comboSelect;

	private: System::Windows::Forms::ComboBox^  comboMethod;


	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;

	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TextBox^  tbComment1;

	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::TextBox^  tbSetR;

	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::TextBox^  tbSetW;

	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::TextBox^  tbSetP;

	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::TextBox^  tbSetZ;

	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::TextBox^  tbSetX;

	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  tbSetY;

	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Timer^  timer1;
private: System::Windows::Forms::TextBox^  tbComment2;

	private: System::Windows::Forms::Label^  label24;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(TrajectoryCalibrationForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tbPosX = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbPosW = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tbPosP = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tbPosY = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->tbPosR = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->tbPosZ = (gcnew System::Windows::Forms::TextBox());
			this->labelComment = (gcnew System::Windows::Forms::Label());
			this->label_center = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->comboSelect = (gcnew System::Windows::Forms::ComboBox());
			this->comboMethod = (gcnew System::Windows::Forms::ComboBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label_ypos = (gcnew System::Windows::Forms::Label());
			this->label_xpos = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->tbComment2 = (gcnew System::Windows::Forms::TextBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->tbComment1 = (gcnew System::Windows::Forms::TextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->tbSetR = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->tbSetW = (gcnew System::Windows::Forms::TextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->tbSetP = (gcnew System::Windows::Forms::TextBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->tbSetZ = (gcnew System::Windows::Forms::TextBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->tbSetX = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->tbSetY = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->tbOffsetX = (gcnew System::Windows::Forms::TextBox());
			this->tbOffsetY = (gcnew System::Windows::Forms::TextBox());
			this->tbOffsetZ = (gcnew System::Windows::Forms::TextBox());
			this->btnApplyOffset = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(18, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(168, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Orient Origin Point:";
			this->label1->Click += gcnew System::EventHandler(this, &TrajectoryCalibrationForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(34, 53);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(152, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"X Direction Point:";
			this->label2->Click += gcnew System::EventHandler(this, &TrajectoryCalibrationForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(34, 83);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(152, 17);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Y Direction Point:";
			this->label3->Click += gcnew System::EventHandler(this, &TrajectoryCalibrationForm::label3_Click);
			// 
			// tbPosX
			// 
			this->tbPosX->BackColor = System::Drawing::Color::White;
			this->tbPosX->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPosX->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPosX->Location = System::Drawing::Point(79, 76);
			this->tbPosX->Name = L"tbPosX";
			this->tbPosX->Size = System::Drawing::Size(112, 16);
			this->tbPosX->TabIndex = 4;
			this->tbPosX->Text = L"0.0";
			this->tbPosX->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(34, 75);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(24, 17);
			this->label4->TabIndex = 5;
			this->label4->Text = L"X:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(34, 105);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(24, 17);
			this->label5->TabIndex = 7;
			this->label5->Text = L"W:";
			// 
			// tbPosW
			// 
			this->tbPosW->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPosW->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPosW->Location = System::Drawing::Point(79, 106);
			this->tbPosW->Name = L"tbPosW";
			this->tbPosW->Size = System::Drawing::Size(112, 16);
			this->tbPosW->TabIndex = 6;
			this->tbPosW->Text = L"0.0";
			this->tbPosW->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(204, 106);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(24, 17);
			this->label6->TabIndex = 11;
			this->label6->Text = L"P:";
			// 
			// tbPosP
			// 
			this->tbPosP->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPosP->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPosP->Location = System::Drawing::Point(249, 107);
			this->tbPosP->Name = L"tbPosP";
			this->tbPosP->Size = System::Drawing::Size(112, 16);
			this->tbPosP->TabIndex = 10;
			this->tbPosP->Text = L"0.0";
			this->tbPosP->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(204, 76);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(24, 17);
			this->label7->TabIndex = 9;
			this->label7->Text = L"Y:";
			// 
			// tbPosY
			// 
			this->tbPosY->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPosY->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPosY->Location = System::Drawing::Point(249, 78);
			this->tbPosY->Name = L"tbPosY";
			this->tbPosY->Size = System::Drawing::Size(112, 16);
			this->tbPosY->TabIndex = 8;
			this->tbPosY->Text = L"0.0";
			this->tbPosY->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(377, 107);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(24, 17);
			this->label8->TabIndex = 15;
			this->label8->Text = L"R:";
			// 
			// tbPosR
			// 
			this->tbPosR->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPosR->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPosR->Location = System::Drawing::Point(422, 108);
			this->tbPosR->Name = L"tbPosR";
			this->tbPosR->Size = System::Drawing::Size(112, 16);
			this->tbPosR->TabIndex = 14;
			this->tbPosR->Text = L"0.0";
			this->tbPosR->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(377, 78);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(24, 17);
			this->label9->TabIndex = 13;
			this->label9->Text = L"Z:";
			// 
			// tbPosZ
			// 
			this->tbPosZ->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPosZ->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPosZ->Location = System::Drawing::Point(422, 79);
			this->tbPosZ->Name = L"tbPosZ";
			this->tbPosZ->Size = System::Drawing::Size(112, 16);
			this->tbPosZ->TabIndex = 12;
			this->tbPosZ->Text = L"0.0";
			this->tbPosZ->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// labelComment
			// 
			this->labelComment->AutoSize = true;
			this->labelComment->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelComment->Location = System::Drawing::Point(34, 20);
			this->labelComment->Name = L"labelComment";
			this->labelComment->Size = System::Drawing::Size(136, 17);
			this->labelComment->TabIndex = 17;
			this->labelComment->Text = L"SSD_FRAME_ORIGIN";
			// 
			// label_center
			// 
			this->label_center->AutoSize = true;
			this->label_center->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_center->Location = System::Drawing::Point(260, 20);
			this->label_center->Name = L"label_center";
			this->label_center->Size = System::Drawing::Size(104, 17);
			this->label_center->TabIndex = 19;
			this->label_center->Text = L"300,-300,111";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(436, 483);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(130, 53);
			this->button1->TabIndex = 28;
			this->button1->Text = L"Move To";
			this->button1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &TrajectoryCalibrationForm::button1_Click);
			// 
			// button14
			// 
			this->button14->BackColor = System::Drawing::Color::Transparent;
			this->button14->ForeColor = System::Drawing::Color::Black;
			this->button14->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button14.Image")));
			this->button14->Location = System::Drawing::Point(26, 483);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(130, 53);
			this->button14->TabIndex = 27;
			this->button14->Text = L"  Apply";
			this->button14->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button14->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button14->UseVisualStyleBackColor = false;
			this->button14->Click += gcnew System::EventHandler(this, &TrajectoryCalibrationForm::button14_Click);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(7, 164);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(120, 17);
			this->label16->TabIndex = 23;
			this->label16->Text = L"SELECT ORIGIN:";
			// 
			// comboSelect
			// 
			this->comboSelect->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->comboSelect->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboSelect->FormattingEnabled = true;
			this->comboSelect->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"ORIGIN1", L"ORIGIN2", L"ORIGIN3", L"ORIGIN4",
					L"ORIGIN5", L"ORIGIN6", L"ORIGIN7", L"ORIGIN8", L"ORIGIN9", L"ORIGIN10"
			});
			this->comboSelect->Location = System::Drawing::Point(181, 161);
			this->comboSelect->Name = L"comboSelect";
			this->comboSelect->Size = System::Drawing::Size(209, 25);
			this->comboSelect->TabIndex = 24;
			this->comboSelect->SelectedIndexChanged += gcnew System::EventHandler(this, &TrajectoryCalibrationForm::comboSelect_SelectedIndexChanged);
			// 
			// comboMethod
			// 
			this->comboMethod->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->comboMethod->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboMethod->FormattingEnabled = true;
			this->comboMethod->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"DIRECT_ENTRY", L"THREE_POINT" });
			this->comboMethod->Location = System::Drawing::Point(181, 199);
			this->comboMethod->Name = L"comboMethod";
			this->comboMethod->Size = System::Drawing::Size(209, 25);
			this->comboMethod->TabIndex = 26;
			this->comboMethod->SelectedIndexChanged += gcnew System::EventHandler(this, &TrajectoryCalibrationForm::comboMethod_SelectedIndexChanged);
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(7, 202);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(64, 17);
			this->label17->TabIndex = 25;
			this->label17->Text = L"METHOD:";
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->btnApplyOffset);
			this->groupBox1->Controls->Add(this->tbOffsetZ);
			this->groupBox1->Controls->Add(this->tbOffsetY);
			this->groupBox1->Controls->Add(this->tbOffsetX);
			this->groupBox1->Controls->Add(this->label_ypos);
			this->groupBox1->Controls->Add(this->label_xpos);
			this->groupBox1->Controls->Add(this->button6);
			this->groupBox1->Controls->Add(this->button5);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->tbComment2);
			this->groupBox1->Controls->Add(this->label24);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label_center);
			this->groupBox1->Location = System::Drawing::Point(14, 271);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(567, 206);
			this->groupBox1->TabIndex = 29;
			this->groupBox1->TabStop = false;
			this->groupBox1->Visible = false;
			// 
			// label_ypos
			// 
			this->label_ypos->AutoSize = true;
			this->label_ypos->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_ypos->Location = System::Drawing::Point(260, 81);
			this->label_ypos->Name = L"label_ypos";
			this->label_ypos->Size = System::Drawing::Size(104, 17);
			this->label_ypos->TabIndex = 47;
			this->label_ypos->Text = L"300,-300,111";
			// 
			// label_xpos
			// 
			this->label_xpos->AutoSize = true;
			this->label_xpos->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_xpos->Location = System::Drawing::Point(260, 51);
			this->label_xpos->Name = L"label_xpos";
			this->label_xpos->Size = System::Drawing::Size(104, 17);
			this->label_xpos->TabIndex = 46;
			this->label_xpos->Text = L"300,-300,111";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(442, 82);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(110, 28);
			this->button6->TabIndex = 45;
			this->button6->Text = L"Record";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &TrajectoryCalibrationForm::button6_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(442, 51);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(110, 28);
			this->button5->TabIndex = 44;
			this->button5->Text = L"Record";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &TrajectoryCalibrationForm::button5_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(442, 18);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(110, 28);
			this->button4->TabIndex = 43;
			this->button4->Text = L"Record";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &TrajectoryCalibrationForm::button4_Click);
			// 
			// tbComment2
			// 
			this->tbComment2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbComment2->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbComment2->Location = System::Drawing::Point(124, 170);
			this->tbComment2->Name = L"tbComment2";
			this->tbComment2->Size = System::Drawing::Size(291, 16);
			this->tbComment2->TabIndex = 42;
			this->tbComment2->Text = L"MY_ORIGIN1";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label24->Location = System::Drawing::Point(17, 170);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(72, 17);
			this->label24->TabIndex = 41;
			this->label24->Text = L"COMMENT:";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->labelComment);
			this->groupBox2->Controls->Add(this->tbPosP);
			this->groupBox2->Controls->Add(this->tbPosY);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->comboMethod);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->tbPosX);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->label17);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->label16);
			this->groupBox2->Controls->Add(this->tbPosZ);
			this->groupBox2->Controls->Add(this->tbPosR);
			this->groupBox2->Controls->Add(this->tbPosW);
			this->groupBox2->Controls->Add(this->comboSelect);
			this->groupBox2->Location = System::Drawing::Point(14, 14);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(567, 251);
			this->groupBox2->TabIndex = 30;
			this->groupBox2->TabStop = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Transparent;
			this->button3->ForeColor = System::Drawing::Color::Black;
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.Image")));
			this->button3->Location = System::Drawing::Point(162, 483);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(130, 53);
			this->button3->TabIndex = 32;
			this->button3->Text = L"Cancel";
			this->button3->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button3->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &TrajectoryCalibrationForm::button3_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->groupBox3->Controls->Add(this->tbComment1);
			this->groupBox3->Controls->Add(this->label23);
			this->groupBox3->Controls->Add(this->tbSetR);
			this->groupBox3->Controls->Add(this->label20);
			this->groupBox3->Controls->Add(this->tbSetW);
			this->groupBox3->Controls->Add(this->label21);
			this->groupBox3->Controls->Add(this->tbSetP);
			this->groupBox3->Controls->Add(this->label22);
			this->groupBox3->Controls->Add(this->tbSetZ);
			this->groupBox3->Controls->Add(this->label19);
			this->groupBox3->Controls->Add(this->tbSetX);
			this->groupBox3->Controls->Add(this->label11);
			this->groupBox3->Controls->Add(this->tbSetY);
			this->groupBox3->Controls->Add(this->label18);
			this->groupBox3->Location = System::Drawing::Point(14, 271);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(567, 164);
			this->groupBox3->TabIndex = 30;
			this->groupBox3->TabStop = false;
			this->groupBox3->Visible = false;
			// 
			// tbComment1
			// 
			this->tbComment1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbComment1->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbComment1->Location = System::Drawing::Point(124, 119);
			this->tbComment1->Name = L"tbComment1";
			this->tbComment1->Size = System::Drawing::Size(238, 16);
			this->tbComment1->TabIndex = 40;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->Location = System::Drawing::Point(17, 119);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(72, 17);
			this->label23->TabIndex = 39;
			this->label23->Text = L"COMMENT:";
			// 
			// tbSetR
			// 
			this->tbSetR->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbSetR->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbSetR->Location = System::Drawing::Point(250, 84);
			this->tbSetR->Name = L"tbSetR";
			this->tbSetR->Size = System::Drawing::Size(112, 16);
			this->tbSetR->TabIndex = 37;
			this->tbSetR->Text = L"0.0";
			this->tbSetR->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->Location = System::Drawing::Point(205, 83);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(24, 17);
			this->label20->TabIndex = 38;
			this->label20->Text = L"R:";
			// 
			// tbSetW
			// 
			this->tbSetW->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbSetW->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbSetW->Location = System::Drawing::Point(250, 26);
			this->tbSetW->Name = L"tbSetW";
			this->tbSetW->Size = System::Drawing::Size(112, 16);
			this->tbSetW->TabIndex = 33;
			this->tbSetW->Text = L"0.0";
			this->tbSetW->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->Location = System::Drawing::Point(205, 25);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(24, 17);
			this->label21->TabIndex = 34;
			this->label21->Text = L"W:";
			// 
			// tbSetP
			// 
			this->tbSetP->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbSetP->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbSetP->Location = System::Drawing::Point(250, 55);
			this->tbSetP->Name = L"tbSetP";
			this->tbSetP->Size = System::Drawing::Size(112, 16);
			this->tbSetP->TabIndex = 35;
			this->tbSetP->Text = L"0.0";
			this->tbSetP->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label22->Location = System::Drawing::Point(205, 54);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(24, 17);
			this->label22->TabIndex = 36;
			this->label22->Text = L"P:";
			// 
			// tbSetZ
			// 
			this->tbSetZ->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbSetZ->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbSetZ->Location = System::Drawing::Point(62, 82);
			this->tbSetZ->Name = L"tbSetZ";
			this->tbSetZ->Size = System::Drawing::Size(112, 16);
			this->tbSetZ->TabIndex = 31;
			this->tbSetZ->Text = L"0.0";
			this->tbSetZ->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->Location = System::Drawing::Point(17, 81);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(24, 17);
			this->label19->TabIndex = 32;
			this->label19->Text = L"Z:";
			// 
			// tbSetX
			// 
			this->tbSetX->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbSetX->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbSetX->Location = System::Drawing::Point(62, 24);
			this->tbSetX->Name = L"tbSetX";
			this->tbSetX->Size = System::Drawing::Size(112, 16);
			this->tbSetX->TabIndex = 27;
			this->tbSetX->Text = L"0.0";
			this->tbSetX->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(17, 22);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(24, 17);
			this->label11->TabIndex = 28;
			this->label11->Text = L"X:";
			// 
			// tbSetY
			// 
			this->tbSetY->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbSetY->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbSetY->Location = System::Drawing::Point(62, 53);
			this->tbSetY->Name = L"tbSetY";
			this->tbSetY->Size = System::Drawing::Size(112, 16);
			this->tbSetY->TabIndex = 29;
			this->tbSetY->Text = L"0.0";
			this->tbSetY->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(17, 52);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(24, 17);
			this->label18->TabIndex = 30;
			this->label18->Text = L"Y:";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &TrajectoryCalibrationForm::timer1_Tick);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Transparent;
			this->button2->ForeColor = System::Drawing::Color::Black;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->Location = System::Drawing::Point(299, 483);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(130, 53);
			this->button2->TabIndex = 33;
			this->button2->Text = L"Record";
			this->button2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button2->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &TrajectoryCalibrationForm::button2_Click);
			// 
			// tbOffsetX
			// 
			this->tbOffsetX->BackColor = System::Drawing::Color::White;
			this->tbOffsetX->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbOffsetX->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbOffsetX->Location = System::Drawing::Point(194, 123);
			this->tbOffsetX->Name = L"tbOffsetX";
			this->tbOffsetX->Size = System::Drawing::Size(70, 23);
			this->tbOffsetX->TabIndex = 27;
			this->tbOffsetX->Text = L"0.0";
			this->tbOffsetX->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbOffsetY
			// 
			this->tbOffsetY->BackColor = System::Drawing::Color::White;
			this->tbOffsetY->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbOffsetY->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbOffsetY->Location = System::Drawing::Point(270, 123);
			this->tbOffsetY->Name = L"tbOffsetY";
			this->tbOffsetY->Size = System::Drawing::Size(70, 23);
			this->tbOffsetY->TabIndex = 48;
			this->tbOffsetY->Text = L"0.0";
			this->tbOffsetY->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbOffsetZ
			// 
			this->tbOffsetZ->BackColor = System::Drawing::Color::White;
			this->tbOffsetZ->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbOffsetZ->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbOffsetZ->Location = System::Drawing::Point(346, 123);
			this->tbOffsetZ->Name = L"tbOffsetZ";
			this->tbOffsetZ->Size = System::Drawing::Size(70, 23);
			this->tbOffsetZ->TabIndex = 49;
			this->tbOffsetZ->Text = L"0.0";
			this->tbOffsetZ->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// btnApplyOffset
			// 
			this->btnApplyOffset->Location = System::Drawing::Point(442, 120);
			this->btnApplyOffset->Name = L"btnApplyOffset";
			this->btnApplyOffset->Size = System::Drawing::Size(110, 28);
			this->btnApplyOffset->TabIndex = 50;
			this->btnApplyOffset->Text = L"Apply Offset";
			this->btnApplyOffset->UseVisualStyleBackColor = true;
			this->btnApplyOffset->Click += gcnew System::EventHandler(this, &TrajectoryCalibrationForm::btnApplyOffset_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(58, 125);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(128, 17);
			this->label10->TabIndex = 51;
			this->label10->Text = L"Offset (X-Y-Z):";
			this->label10->Click += gcnew System::EventHandler(this, &TrajectoryCalibrationForm::label10_Click);
			// 
			// TrajectoryCalibrationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(596, 548);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox3);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"TrajectoryCalibrationForm";
			this->Text = L"User Frame Calibration";
			this->Load += gcnew System::EventHandler(this, &TrajectoryCalibrationForm::TrajectoryCalibrationForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		set_steps = 0;
	}
	private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void comboMethod_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	update_method();
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	on_timer();
}
private: System::Void comboSelect_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	update_origin();
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	set_steps = 1;
}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
	set_steps = 2;
}
private: System::Void TrajectoryCalibrationForm_Load(System::Object^  sender, System::EventArgs^  e) {
	on_init();
}
private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_apply();
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	set_center_pos();
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	set_x_pos();
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	set_y_pos();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_read_current_pos();
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_move_to_origin();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
private: System::Void label10_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void btnApplyOffset_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_apply_offset();
}
};
}
