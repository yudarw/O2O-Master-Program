#pragma once
#include <string>
#include <iostream>
#include "GlobalVariable.h"

namespace OfflineProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
	private: System::Windows::Forms::TabControl^  tabControl1;
	public:
	private: System::Windows::Forms::TabPage^  tabPage1;

	private: System::Windows::Forms::GroupBox^  groupBox1;


	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::GroupBox^  tabel1_name;





	private: System::Windows::Forms::DataGridView^  dataGridView1;


	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  btnRunTrajectory;

	private: System::Windows::Forms::Button^  btnRunProgram;

	private: System::Windows::Forms::Button^  btn_hapticTeleoperation;

	private: System::Windows::Forms::Button^  button8;
	public: static MainForm ^ instance;

	public:




	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
















	private: System::Windows::Forms::Button^  buttonLoad;

















































private: System::Windows::Forms::Timer^  timer1;

private: System::Windows::Forms::Timer^  timer2;
private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
private: System::Windows::Forms::Button^  button32;
private: System::Windows::Forms::Button^  button34;
private: System::Windows::Forms::Button^  button33;
private: System::Windows::Forms::Button^  button14;
private: System::Windows::Forms::Button^  button25;
private: System::Windows::Forms::Button^  button31;
private: System::Windows::Forms::Button^  button30;
private: System::Windows::Forms::Button^  button15;


private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
private: System::Windows::Forms::GroupBox^  groupBox6;
private: System::Windows::Forms::GroupBox^  groupBox10;
private: System::Windows::Forms::Button^  button16;
private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::Button^  button3;
private: System::Windows::Forms::Button^  button2;


private: System::Windows::Forms::Button^  button20;
private: System::Windows::Forms::Button^  button19;
private: System::Windows::Forms::Button^  button18;
private: System::Windows::Forms::Button^  button17;
private: System::Windows::Forms::Button^  button13;

private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
private: System::Windows::Forms::Button^  button21;

private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
private: System::Windows::Forms::GroupBox^  groupBox7;
private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel7;
private: System::Windows::Forms::Button^  button23;
private: System::Windows::Forms::Button^  button24;
private: System::Windows::Forms::Button^  button26;
private: System::Windows::Forms::Button^  button4;
private: System::Windows::Forms::Button^  button5;
















	public:



	public:


	public: static DataGridView ^ tabel;
private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
public:
private: System::Windows::Forms::Button^  button12;
private: System::Windows::Forms::GroupBox^  groupBox8;






private: System::Windows::Forms::Button^  button9;
private: System::Windows::Forms::Button^  button22;
private: System::Windows::Forms::Button^  button28;
private: System::Windows::Forms::Button^  button27;

private: System::Windows::Forms::GroupBox^  groupBox11;


private: System::Windows::Forms::GroupBox^  groupBox9;
private: System::Windows::Forms::Button^  button29;
private: System::Windows::Forms::Button^  button38;
private: System::Windows::Forms::Button^  btnServo;
private: System::Windows::Forms::GroupBox^  groupBox12;


private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  INSTRUCTION;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
private: System::Windows::Forms::Button^  button35;
private: System::Windows::Forms::Button^  button36;







private: System::Windows::Forms::GroupBox^  groupBox15;
private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel9;
private: System::Windows::Forms::GroupBox^  groupBox14;
private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel8;
private: System::Windows::Forms::Button^  button37;
private: System::Windows::Forms::Button^  button39;
private: System::Windows::Forms::Button^  button40;
private: System::Windows::Forms::Panel^  panel1;
private: System::Windows::Forms::Panel^  indicator_robot;

private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::Panel^  indicator_haptic;

private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::Panel^  indicator_ftsensor;

private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::Label^  label_speed_ratio;

private: System::Windows::Forms::Button^  button41;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::Button^  button10;


private: System::Windows::Forms::Panel^  indicator_alarm;
private: System::Windows::Forms::Label^  label_alarm;
private: System::Windows::Forms::Button^  button11;
private: System::Windows::Forms::Button^  button42;
private: System::Windows::Forms::Button^  button43;




	public: static DataGridView ^ tabel2;

		MainForm(void)
		{
			InitializeComponent();
			instance = this;
			tabel = dataGridView1;
			tabel2 = dataGridView2;
			//
			//TODO: Add the constructor code here
			//
		}

		void btn_print();
		void btn_edit_program();
		void btn_add_move_point();
		void btn_add_offline_trajectory();
		void btn_add_wait();
		void btn_add_comment();
		bool isFormOpened(String ^ form_name);
		void on_timer();
		void on_init();
		void update_line_number();
		void btn_initDevice();
		void btn_load_trajectory();
		void show_trajectory_table(vector<pos_t> pos);
		void btn_new_trajectory_file();

		void btn_add_new_point();
		void btn_delete_point();
		void btn_modify_point();
		void btn_replace_current_pos();
		void update_tab2_line_number();

		void btn_move_to_selected_position();
		void btn_move_to_next();
		void btn_move_to_prev();
		void btn_open_calibration_form();

		void show_robot_status_form();
		void show_trajectory_record_form();
		void btn_save_trajectory();

		void btn_haptic_teleoperation();
		void btn_roboguide_connect();
		void btn_apply_trajectory_calibration();

		void btn_tool_calibration();
		void btn_run_trajectory();

		void btn_moveTo_home_pos();
		void btn_moveTo_standby_pos();

		// Sequence Program:
		void btn_save_sequence_program();
		void btn_load_sequence_program();
		void show_program_data();

		void btn_show_graph();
		void btn_servo();
		void btn_resetConnection();
		void btn_add_new_program();

		void save_configuration();

		void update_initialization_data();
		void show_3d_plot();


		// Sequence program:
		void btn_sequence_delete();
		void btn_sequence_insert();
		void btn_sequence_modify();

		//
		void btn_move_to_program_line();
		void btn_test_io();

		void btn_open_robot_settings();
		void btn_haptic_setting_form();

		void btn_increase_speed();
		void btn_decrease_speed();
		void btn_test();

		void show_coppeliasim();
		void btn_haptic_connect();
		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
private: System::ComponentModel::IContainer^  components;
protected:

	protected:









	public:





	public:






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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox15 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel9 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->groupBox14 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel8 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button40 = (gcnew System::Windows::Forms::Button());
			this->button37 = (gcnew System::Windows::Forms::Button());
			this->button39 = (gcnew System::Windows::Forms::Button());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->tabel1_name = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->INSTRUCTION = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button31 = (gcnew System::Windows::Forms::Button());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->groupBox10 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button33 = (gcnew System::Windows::Forms::Button());
			this->button32 = (gcnew System::Windows::Forms::Button());
			this->button34 = (gcnew System::Windows::Forms::Button());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button30 = (gcnew System::Windows::Forms::Button());
			this->buttonLoad = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox12 = (gcnew System::Windows::Forms::GroupBox());
			this->button42 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->groupBox11 = (gcnew System::Windows::Forms::GroupBox());
			this->button43 = (gcnew System::Windows::Forms::Button());
			this->button41 = (gcnew System::Windows::Forms::Button());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->button36 = (gcnew System::Windows::Forms::Button());
			this->button35 = (gcnew System::Windows::Forms::Button());
			this->button29 = (gcnew System::Windows::Forms::Button());
			this->button38 = (gcnew System::Windows::Forms::Button());
			this->btnServo = (gcnew System::Windows::Forms::Button());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->button28 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnRunTrajectory = (gcnew System::Windows::Forms::Button());
			this->btnRunProgram = (gcnew System::Windows::Forms::Button());
			this->btn_hapticTeleoperation = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->indicator_alarm = (gcnew System::Windows::Forms::Panel());
			this->label_alarm = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label_speed_ratio = (gcnew System::Windows::Forms::Label());
			this->indicator_robot = (gcnew System::Windows::Forms::Panel());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->indicator_haptic = (gcnew System::Windows::Forms::Panel());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->indicator_ftsensor = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox15->SuspendLayout();
			this->tableLayoutPanel9->SuspendLayout();
			this->groupBox14->SuspendLayout();
			this->tableLayoutPanel8->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->tableLayoutPanel7->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tabel1_name->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabPage2->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->groupBox10->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->tabPage3->SuspendLayout();
			this->groupBox12->SuspendLayout();
			this->groupBox11->SuspendLayout();
			this->groupBox9->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->indicator_alarm->SuspendLayout();
			this->indicator_robot->SuspendLayout();
			this->indicator_haptic->SuspendLayout();
			this->indicator_ftsensor->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->ItemSize = System::Drawing::Size(100, 35);
			this->tabControl1->Location = System::Drawing::Point(3, 55);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(972, 649);
			this->tabControl1->SizeMode = System::Windows::Forms::TabSizeMode::Fixed;
			this->tabControl1->TabIndex = 4;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->groupBox15);
			this->tabPage1->Controls->Add(this->groupBox14);
			this->tabPage1->Controls->Add(this->groupBox7);
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Controls->Add(this->tabel1_name);
			this->tabPage1->Location = System::Drawing::Point(4, 39);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(964, 606);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Program";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// groupBox15
			// 
			this->groupBox15->Controls->Add(this->tableLayoutPanel9);
			this->groupBox15->Location = System::Drawing::Point(9, 103);
			this->groupBox15->Name = L"groupBox15";
			this->groupBox15->Size = System::Drawing::Size(243, 92);
			this->groupBox15->TabIndex = 27;
			this->groupBox15->TabStop = false;
			this->groupBox15->Text = L"LINE EDIT";
			// 
			// tableLayoutPanel9
			// 
			this->tableLayoutPanel9->ColumnCount = 3;
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel9->Controls->Add(this->button18, 0, 0);
			this->tableLayoutPanel9->Controls->Add(this->button17, 1, 0);
			this->tableLayoutPanel9->Controls->Add(this->button13, 2, 0);
			this->tableLayoutPanel9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel9->Location = System::Drawing::Point(3, 19);
			this->tableLayoutPanel9->Name = L"tableLayoutPanel9";
			this->tableLayoutPanel9->RowCount = 1;
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel9->Size = System::Drawing::Size(237, 70);
			this->tableLayoutPanel9->TabIndex = 0;
			// 
			// button18
			// 
			this->button18->BackColor = System::Drawing::Color::Transparent;
			this->button18->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button18->ForeColor = System::Drawing::Color::Black;
			this->button18->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button18.Image")));
			this->button18->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button18->Location = System::Drawing::Point(3, 3);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(73, 64);
			this->button18->TabIndex = 8;
			this->button18->Text = L"Modify";
			this->button18->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button18->UseVisualStyleBackColor = false;
			this->button18->Click += gcnew System::EventHandler(this, &MainForm::button18_Click);
			// 
			// button17
			// 
			this->button17->BackColor = System::Drawing::Color::Transparent;
			this->button17->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button17->ForeColor = System::Drawing::Color::Black;
			this->button17->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button17.Image")));
			this->button17->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button17->Location = System::Drawing::Point(82, 3);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(73, 64);
			this->button17->TabIndex = 7;
			this->button17->Text = L"Insert";
			this->button17->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button17->UseVisualStyleBackColor = false;
			this->button17->Click += gcnew System::EventHandler(this, &MainForm::button17_Click);
			// 
			// button13
			// 
			this->button13->BackColor = System::Drawing::Color::Transparent;
			this->button13->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button13->ForeColor = System::Drawing::Color::Black;
			this->button13->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button13.Image")));
			this->button13->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button13->Location = System::Drawing::Point(161, 3);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(73, 64);
			this->button13->TabIndex = 6;
			this->button13->Text = L"Delete";
			this->button13->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button13->UseVisualStyleBackColor = false;
			this->button13->Click += gcnew System::EventHandler(this, &MainForm::button13_Click);
			// 
			// groupBox14
			// 
			this->groupBox14->Controls->Add(this->tableLayoutPanel8);
			this->groupBox14->Location = System::Drawing::Point(9, 200);
			this->groupBox14->Name = L"groupBox14";
			this->groupBox14->Size = System::Drawing::Size(243, 92);
			this->groupBox14->TabIndex = 26;
			this->groupBox14->TabStop = false;
			this->groupBox14->Text = L"MOVE ROBOT";
			// 
			// tableLayoutPanel8
			// 
			this->tableLayoutPanel8->ColumnCount = 3;
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel8->Controls->Add(this->button40, 1, 0);
			this->tableLayoutPanel8->Controls->Add(this->button37, 0, 0);
			this->tableLayoutPanel8->Controls->Add(this->button39, 2, 0);
			this->tableLayoutPanel8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel8->Location = System::Drawing::Point(3, 19);
			this->tableLayoutPanel8->Name = L"tableLayoutPanel8";
			this->tableLayoutPanel8->RowCount = 1;
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel8->Size = System::Drawing::Size(237, 70);
			this->tableLayoutPanel8->TabIndex = 0;
			// 
			// button40
			// 
			this->button40->BackColor = System::Drawing::Color::Transparent;
			this->button40->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button40->ForeColor = System::Drawing::Color::Black;
			this->button40->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button40.Image")));
			this->button40->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button40->Location = System::Drawing::Point(82, 3);
			this->button40->Name = L"button40";
			this->button40->Size = System::Drawing::Size(73, 64);
			this->button40->TabIndex = 17;
			this->button40->Text = L"Speed +";
			this->button40->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button40->UseVisualStyleBackColor = false;
			this->button40->Click += gcnew System::EventHandler(this, &MainForm::button40_Click);
			// 
			// button37
			// 
			this->button37->BackColor = System::Drawing::Color::Transparent;
			this->button37->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button37->ForeColor = System::Drawing::Color::Black;
			this->button37->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button37.Image")));
			this->button37->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button37->Location = System::Drawing::Point(3, 3);
			this->button37->Name = L"button37";
			this->button37->Size = System::Drawing::Size(73, 64);
			this->button37->TabIndex = 16;
			this->button37->Text = L"Speed -";
			this->button37->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button37->UseVisualStyleBackColor = false;
			this->button37->Click += gcnew System::EventHandler(this, &MainForm::button37_Click_1);
			// 
			// button39
			// 
			this->button39->BackColor = System::Drawing::Color::Transparent;
			this->button39->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button39->ForeColor = System::Drawing::Color::Black;
			this->button39->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button39.Image")));
			this->button39->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button39->Location = System::Drawing::Point(161, 3);
			this->button39->Name = L"button39";
			this->button39->Size = System::Drawing::Size(73, 64);
			this->button39->TabIndex = 15;
			this->button39->Text = L"Move To";
			this->button39->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button39->UseVisualStyleBackColor = false;
			this->button39->Click += gcnew System::EventHandler(this, &MainForm::button39_Click);
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->tableLayoutPanel7);
			this->groupBox7->Location = System::Drawing::Point(8, 6);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(243, 94);
			this->groupBox7->TabIndex = 25;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"FILE";
			// 
			// tableLayoutPanel7
			// 
			this->tableLayoutPanel7->ColumnCount = 3;
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel7->Controls->Add(this->button23, 2, 0);
			this->tableLayoutPanel7->Controls->Add(this->button24, 0, 0);
			this->tableLayoutPanel7->Controls->Add(this->button26, 1, 0);
			this->tableLayoutPanel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel7->Location = System::Drawing::Point(3, 19);
			this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
			this->tableLayoutPanel7->RowCount = 1;
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel7->Size = System::Drawing::Size(237, 72);
			this->tableLayoutPanel7->TabIndex = 0;
			// 
			// button23
			// 
			this->button23->BackColor = System::Drawing::Color::Transparent;
			this->button23->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button23->ForeColor = System::Drawing::Color::Black;
			this->button23->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button23.Image")));
			this->button23->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button23->Location = System::Drawing::Point(161, 3);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(73, 66);
			this->button23->TabIndex = 11;
			this->button23->Text = L"New";
			this->button23->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button23->UseVisualStyleBackColor = false;
			this->button23->Click += gcnew System::EventHandler(this, &MainForm::button23_Click);
			// 
			// button24
			// 
			this->button24->BackColor = System::Drawing::Color::Transparent;
			this->button24->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button24->ForeColor = System::Drawing::Color::Black;
			this->button24->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button24.Image")));
			this->button24->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button24->Location = System::Drawing::Point(3, 3);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(73, 66);
			this->button24->TabIndex = 9;
			this->button24->Text = L"Open";
			this->button24->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button24->UseVisualStyleBackColor = false;
			this->button24->Click += gcnew System::EventHandler(this, &MainForm::button24_Click);
			// 
			// button26
			// 
			this->button26->BackColor = System::Drawing::Color::Transparent;
			this->button26->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button26->ForeColor = System::Drawing::Color::Black;
			this->button26->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button26.Image")));
			this->button26->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button26->Location = System::Drawing::Point(82, 3);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(73, 66);
			this->button26->TabIndex = 10;
			this->button26->Text = L"Save";
			this->button26->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button26->UseVisualStyleBackColor = false;
			this->button26->Click += gcnew System::EventHandler(this, &MainForm::button26_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Transparent;
			this->groupBox1->Controls->Add(this->tableLayoutPanel3);
			this->groupBox1->Location = System::Drawing::Point(256, 462);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(699, 140);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"INSTRUCTION";
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 5;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel3->Controls->Add(this->button21, 4, 1);
			this->tableLayoutPanel3->Controls->Add(this->button1, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->button6, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->button3, 2, 0);
			this->tableLayoutPanel3->Controls->Add(this->button20, 3, 0);
			this->tableLayoutPanel3->Controls->Add(this->button2, 3, 1);
			this->tableLayoutPanel3->Controls->Add(this->button19, 4, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 19);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 2;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(693, 118);
			this->tableLayoutPanel3->TabIndex = 0;
			// 
			// button21
			// 
			this->button21->BackColor = System::Drawing::Color::Transparent;
			this->button21->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button21->Enabled = false;
			this->button21->ForeColor = System::Drawing::Color::Black;
			this->button21->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button21.Image")));
			this->button21->Location = System::Drawing::Point(555, 62);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(135, 53);
			this->button21->TabIndex = 11;
			this->button21->Text = L"Wait";
			this->button21->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button21->UseVisualStyleBackColor = false;
			this->button21->Click += gcnew System::EventHandler(this, &MainForm::button21_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(3, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(132, 53);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Add Move Point";
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::Transparent;
			this->button6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button6->ForeColor = System::Drawing::Color::Black;
			this->button6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button6.Image")));
			this->button6->Location = System::Drawing::Point(141, 3);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(132, 53);
			this->button6->TabIndex = 3;
			this->button6->Text = L"Add Offline Trajectory";
			this->button6->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MainForm::button6_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Transparent;
			this->button3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button3->ForeColor = System::Drawing::Color::Black;
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.Image")));
			this->button3->Location = System::Drawing::Point(279, 3);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(132, 53);
			this->button3->TabIndex = 5;
			this->button3->Text = L"   I/O";
			this->button3->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click_1);
			// 
			// button20
			// 
			this->button20->BackColor = System::Drawing::Color::Transparent;
			this->button20->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button20->Enabled = false;
			this->button20->ForeColor = System::Drawing::Color::Black;
			this->button20->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button20.Image")));
			this->button20->Location = System::Drawing::Point(417, 3);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(132, 53);
			this->button20->TabIndex = 10;
			this->button20->Text = L"If...else...";
			this->button20->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button20->UseVisualStyleBackColor = false;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Transparent;
			this->button2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button2->ForeColor = System::Drawing::Color::Black;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->Location = System::Drawing::Point(417, 62);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(132, 53);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Comment";
			this->button2->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// button19
			// 
			this->button19->BackColor = System::Drawing::Color::Transparent;
			this->button19->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button19->Enabled = false;
			this->button19->ForeColor = System::Drawing::Color::Black;
			this->button19->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button19.Image")));
			this->button19->Location = System::Drawing::Point(555, 3);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(135, 53);
			this->button19->TabIndex = 9;
			this->button19->Text = L"Loop";
			this->button19->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button19->UseVisualStyleBackColor = false;
			// 
			// tabel1_name
			// 
			this->tabel1_name->BackColor = System::Drawing::Color::Gainsboro;
			this->tabel1_name->Controls->Add(this->dataGridView1);
			this->tabel1_name->Location = System::Drawing::Point(256, 6);
			this->tabel1_name->Name = L"tabel1_name";
			this->tabel1_name->Size = System::Drawing::Size(702, 451);
			this->tabel1_name->TabIndex = 3;
			this->tabel1_name->TabStop = false;
			this->tabel1_name->Text = L"NEW_PROGRAM.TXT [7/20]";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::White;
			this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->INSTRUCTION, this->Column2
			});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Top;
			this->dataGridView1->Location = System::Drawing::Point(3, 19);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(696, 430);
			this->dataGridView1->TabIndex = 2;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView1_CellClick);
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView1_CellContentClick);
			this->dataGridView1->CellContentDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView1_CellContentDoubleClick);
			this->dataGridView1->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView1_CellDoubleClick);
			this->dataGridView1->SelectionChanged += gcnew System::EventHandler(this, &MainForm::dataGridView1_SelectionChanged);
			// 
			// Column1
			// 
			this->Column1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->Column1->HeaderText = L"STEPS";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column1->Width = 82;
			// 
			// INSTRUCTION
			// 
			this->INSTRUCTION->HeaderText = L"INSTRUCTION";
			this->INSTRUCTION->Name = L"INSTRUCTION";
			this->INSTRUCTION->ReadOnly = true;
			this->INSTRUCTION->Width = 500;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"COMMENT";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 274;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->groupBox8);
			this->tabPage2->Controls->Add(this->groupBox6);
			this->tabPage2->Controls->Add(this->groupBox10);
			this->tabPage2->Controls->Add(this->groupBox5);
			this->tabPage2->Controls->Add(this->groupBox4);
			this->tabPage2->Location = System::Drawing::Point(4, 39);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(930, 606);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Trajectory";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// groupBox8
			// 
			this->groupBox8->Location = System::Drawing::Point(6, 444);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(256, 158);
			this->groupBox8->TabIndex = 19;
			this->groupBox8->TabStop = false;
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->tableLayoutPanel5);
			this->groupBox6->Location = System::Drawing::Point(6, 178);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->groupBox6->Size = System::Drawing::Size(256, 166);
			this->groupBox6->TabIndex = 18;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"POINT EDIT";
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 3;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel5->Controls->Add(this->button14, 2, 0);
			this->tableLayoutPanel5->Controls->Add(this->button31, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->button25, 1, 0);
			this->tableLayoutPanel5->Controls->Add(this->button12, 0, 1);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel5->Location = System::Drawing::Point(3, 19);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 2;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(250, 144);
			this->tableLayoutPanel5->TabIndex = 0;
			// 
			// button14
			// 
			this->button14->BackColor = System::Drawing::Color::Transparent;
			this->button14->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button14->ForeColor = System::Drawing::Color::Black;
			this->button14->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button14.Image")));
			this->button14->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button14->Location = System::Drawing::Point(169, 3);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(78, 66);
			this->button14->TabIndex = 14;
			this->button14->Text = L"Modify";
			this->button14->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button14->UseVisualStyleBackColor = false;
			this->button14->Click += gcnew System::EventHandler(this, &MainForm::button14_Click);
			// 
			// button31
			// 
			this->button31->BackColor = System::Drawing::Color::Transparent;
			this->button31->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button31->ForeColor = System::Drawing::Color::Black;
			this->button31->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button31.Image")));
			this->button31->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button31->Location = System::Drawing::Point(3, 3);
			this->button31->Name = L"button31";
			this->button31->Size = System::Drawing::Size(77, 66);
			this->button31->TabIndex = 12;
			this->button31->Text = L"Add";
			this->button31->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button31->UseVisualStyleBackColor = false;
			this->button31->Click += gcnew System::EventHandler(this, &MainForm::button31_Click);
			// 
			// button25
			// 
			this->button25->BackColor = System::Drawing::Color::Transparent;
			this->button25->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button25->ForeColor = System::Drawing::Color::Black;
			this->button25->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button25.Image")));
			this->button25->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button25->Location = System::Drawing::Point(86, 3);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(77, 66);
			this->button25->TabIndex = 13;
			this->button25->Text = L"Delete";
			this->button25->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button25->UseVisualStyleBackColor = false;
			this->button25->Click += gcnew System::EventHandler(this, &MainForm::button25_Click);
			// 
			// button12
			// 
			this->button12->BackColor = System::Drawing::Color::Transparent;
			this->button12->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button12->ForeColor = System::Drawing::Color::Black;
			this->button12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button12.Image")));
			this->button12->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button12->Location = System::Drawing::Point(3, 75);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(77, 66);
			this->button12->TabIndex = 19;
			this->button12->Text = L"Replace";
			this->button12->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button12->UseVisualStyleBackColor = false;
			this->button12->Click += gcnew System::EventHandler(this, &MainForm::button12_Click);
			// 
			// groupBox10
			// 
			this->groupBox10->Controls->Add(this->tableLayoutPanel6);
			this->groupBox10->Location = System::Drawing::Point(6, 349);
			this->groupBox10->Name = L"groupBox10";
			this->groupBox10->Size = System::Drawing::Size(256, 92);
			this->groupBox10->TabIndex = 11;
			this->groupBox10->TabStop = false;
			this->groupBox10->Text = L"MOVE ROBOT";
			// 
			// tableLayoutPanel6
			// 
			this->tableLayoutPanel6->ColumnCount = 3;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel6->Controls->Add(this->button33, 0, 0);
			this->tableLayoutPanel6->Controls->Add(this->button32, 2, 0);
			this->tableLayoutPanel6->Controls->Add(this->button34, 1, 0);
			this->tableLayoutPanel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel6->Location = System::Drawing::Point(3, 19);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 1;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(250, 70);
			this->tableLayoutPanel6->TabIndex = 0;
			// 
			// button33
			// 
			this->button33->BackColor = System::Drawing::Color::Transparent;
			this->button33->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button33->ForeColor = System::Drawing::Color::Black;
			this->button33->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button33.Image")));
			this->button33->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button33->Location = System::Drawing::Point(3, 3);
			this->button33->Name = L"button33";
			this->button33->Size = System::Drawing::Size(77, 64);
			this->button33->TabIndex = 16;
			this->button33->Text = L"Prev";
			this->button33->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button33->UseVisualStyleBackColor = false;
			this->button33->Click += gcnew System::EventHandler(this, &MainForm::button33_Click);
			// 
			// button32
			// 
			this->button32->BackColor = System::Drawing::Color::Transparent;
			this->button32->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button32->ForeColor = System::Drawing::Color::Black;
			this->button32->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button32.Image")));
			this->button32->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button32->Location = System::Drawing::Point(169, 3);
			this->button32->Name = L"button32";
			this->button32->Size = System::Drawing::Size(78, 64);
			this->button32->TabIndex = 15;
			this->button32->Text = L"Move To";
			this->button32->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button32->UseVisualStyleBackColor = false;
			this->button32->Click += gcnew System::EventHandler(this, &MainForm::button32_Click);
			// 
			// button34
			// 
			this->button34->BackColor = System::Drawing::Color::Transparent;
			this->button34->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button34->ForeColor = System::Drawing::Color::Black;
			this->button34->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button34.Image")));
			this->button34->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button34->Location = System::Drawing::Point(86, 3);
			this->button34->Name = L"button34";
			this->button34->Size = System::Drawing::Size(77, 64);
			this->button34->TabIndex = 17;
			this->button34->Text = L"Next";
			this->button34->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button34->UseVisualStyleBackColor = false;
			this->button34->Click += gcnew System::EventHandler(this, &MainForm::button34_Click);
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->tableLayoutPanel4);
			this->groupBox5->Location = System::Drawing::Point(6, 6);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(256, 166);
			this->groupBox5->TabIndex = 5;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"FILE";
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 3;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel4->Controls->Add(this->button5, 2, 1);
			this->tableLayoutPanel4->Controls->Add(this->button4, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->button16, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->button30, 2, 0);
			this->tableLayoutPanel4->Controls->Add(this->buttonLoad, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->button15, 1, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 19);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 2;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(250, 144);
			this->tableLayoutPanel4->TabIndex = 0;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::Transparent;
			this->button5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button5->ForeColor = System::Drawing::Color::Black;
			this->button5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.Image")));
			this->button5->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button5->Location = System::Drawing::Point(169, 75);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(78, 66);
			this->button5->TabIndex = 19;
			this->button5->Text = L"Calibrate";
			this->button5->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MainForm::button5_Click_1);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Transparent;
			this->button4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button4->ForeColor = System::Drawing::Color::Black;
			this->button4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.Image")));
			this->button4->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button4->Location = System::Drawing::Point(3, 75);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(77, 66);
			this->button4->TabIndex = 16;
			this->button4->Text = L"Record";
			this->button4->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
			// 
			// button16
			// 
			this->button16->BackColor = System::Drawing::Color::Transparent;
			this->button16->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button16->ForeColor = System::Drawing::Color::Black;
			this->button16->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button16.Image")));
			this->button16->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button16->Location = System::Drawing::Point(86, 75);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(77, 66);
			this->button16->TabIndex = 15;
			this->button16->Text = L"Set Origin";
			this->button16->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button16->UseVisualStyleBackColor = false;
			this->button16->Click += gcnew System::EventHandler(this, &MainForm::button16_Click);
			// 
			// button30
			// 
			this->button30->BackColor = System::Drawing::Color::Transparent;
			this->button30->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button30->ForeColor = System::Drawing::Color::Black;
			this->button30->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button30.Image")));
			this->button30->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button30->Location = System::Drawing::Point(169, 3);
			this->button30->Name = L"button30";
			this->button30->Size = System::Drawing::Size(78, 66);
			this->button30->TabIndex = 11;
			this->button30->Text = L"New";
			this->button30->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button30->UseVisualStyleBackColor = false;
			this->button30->Click += gcnew System::EventHandler(this, &MainForm::button30_Click);
			// 
			// buttonLoad
			// 
			this->buttonLoad->BackColor = System::Drawing::Color::Transparent;
			this->buttonLoad->Dock = System::Windows::Forms::DockStyle::Fill;
			this->buttonLoad->ForeColor = System::Drawing::Color::Black;
			this->buttonLoad->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonLoad.Image")));
			this->buttonLoad->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->buttonLoad->Location = System::Drawing::Point(3, 3);
			this->buttonLoad->Name = L"buttonLoad";
			this->buttonLoad->Size = System::Drawing::Size(77, 66);
			this->buttonLoad->TabIndex = 9;
			this->buttonLoad->Text = L"Open";
			this->buttonLoad->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->buttonLoad->UseVisualStyleBackColor = false;
			this->buttonLoad->Click += gcnew System::EventHandler(this, &MainForm::buttonLoad_Click);
			// 
			// button15
			// 
			this->button15->BackColor = System::Drawing::Color::Transparent;
			this->button15->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button15->ForeColor = System::Drawing::Color::Black;
			this->button15->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button15.Image")));
			this->button15->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button15->Location = System::Drawing::Point(86, 3);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(77, 66);
			this->button15->TabIndex = 10;
			this->button15->Text = L"Save";
			this->button15->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button15->UseVisualStyleBackColor = false;
			this->button15->Click += gcnew System::EventHandler(this, &MainForm::button15_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->BackColor = System::Drawing::Color::Gainsboro;
			this->groupBox4->Controls->Add(this->dataGridView2);
			this->groupBox4->ForeColor = System::Drawing::Color::Black;
			this->groupBox4->Location = System::Drawing::Point(268, 6);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(660, 599);
			this->groupBox4->TabIndex = 4;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"PROGRAM LINE [1/618]";
			this->groupBox4->Enter += gcnew System::EventHandler(this, &MainForm::groupBox4_Enter);
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->AllowUserToResizeColumns = false;
			this->dataGridView2->AllowUserToResizeRows = false;
			this->dataGridView2->BackgroundColor = System::Drawing::Color::White;
			this->dataGridView2->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
			this->dataGridView2->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->dataGridViewTextBoxColumn1,
					this->Column3, this->Column4, this->Column5, this->Column6, this->Column7, this->Column8
			});
			this->dataGridView2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView2->Location = System::Drawing::Point(3, 19);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView2->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(654, 577);
			this->dataGridView2->TabIndex = 2;
			this->dataGridView2->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView2_CellClick);
			this->dataGridView2->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView2_CellContentClick);
			this->dataGridView2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::dataGridView2_KeyDown);
			this->dataGridView2->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::dataGridView2_KeyUp);
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"STEPS";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewTextBoxColumn1->Width = 60;
			// 
			// Column3
			// 
			this->Column3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column3->HeaderText = L"X";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column4->HeaderText = L"Y";
			this->Column4->Name = L"Column4";
			// 
			// Column5
			// 
			this->Column5->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column5->HeaderText = L"Z";
			this->Column5->Name = L"Column5";
			// 
			// Column6
			// 
			this->Column6->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column6->HeaderText = L"W";
			this->Column6->Name = L"Column6";
			// 
			// Column7
			// 
			this->Column7->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column7->HeaderText = L"P";
			this->Column7->Name = L"Column7";
			// 
			// Column8
			// 
			this->Column8->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column8->HeaderText = L"R";
			this->Column8->Name = L"Column8";
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->groupBox12);
			this->tabPage3->Controls->Add(this->groupBox11);
			this->tabPage3->Controls->Add(this->groupBox9);
			this->tabPage3->Location = System::Drawing::Point(4, 39);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(930, 606);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Settings";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// groupBox12
			// 
			this->groupBox12->Controls->Add(this->button42);
			this->groupBox12->Controls->Add(this->button11);
			this->groupBox12->Controls->Add(this->button10);
			this->groupBox12->Location = System::Drawing::Point(171, 3);
			this->groupBox12->Name = L"groupBox12";
			this->groupBox12->Size = System::Drawing::Size(574, 593);
			this->groupBox12->TabIndex = 20;
			this->groupBox12->TabStop = false;
			// 
			// button42
			// 
			this->button42->Location = System::Drawing::Point(11, 133);
			this->button42->Name = L"button42";
			this->button42->Size = System::Drawing::Size(120, 20);
			this->button42->TabIndex = 4;
			this->button42->Text = L"Coopelia Sim";
			this->button42->UseVisualStyleBackColor = true;
			this->button42->Click += gcnew System::EventHandler(this, &MainForm::button42_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(11, 88);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(120, 40);
			this->button11->TabIndex = 3;
			this->button11->Text = L"Reset Alarm";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MainForm::button11_Click_1);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(11, 29);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(120, 40);
			this->button10->TabIndex = 0;
			this->button10->Text = L"Test Yaskawa Record";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MainForm::button10_Click_1);
			// 
			// groupBox11
			// 
			this->groupBox11->Controls->Add(this->button43);
			this->groupBox11->Controls->Add(this->button41);
			this->groupBox11->Controls->Add(this->button22);
			this->groupBox11->Location = System::Drawing::Point(750, 3);
			this->groupBox11->Name = L"groupBox11";
			this->groupBox11->Size = System::Drawing::Size(171, 593);
			this->groupBox11->TabIndex = 19;
			this->groupBox11->TabStop = false;
			this->groupBox11->Text = L"SETIING";
			// 
			// button43
			// 
			this->button43->BackColor = System::Drawing::Color::Transparent;
			this->button43->ForeColor = System::Drawing::Color::Black;
			this->button43->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button43.Image")));
			this->button43->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button43->Location = System::Drawing::Point(26, 172);
			this->button43->Name = L"button43";
			this->button43->Size = System::Drawing::Size(125, 62);
			this->button43->TabIndex = 16;
			this->button43->Text = L"Haptic Connect";
			this->button43->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button43->UseVisualStyleBackColor = false;
			this->button43->Click += gcnew System::EventHandler(this, &MainForm::button43_Click);
			// 
			// button41
			// 
			this->button41->BackColor = System::Drawing::Color::Transparent;
			this->button41->ForeColor = System::Drawing::Color::Black;
			this->button41->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button41.Image")));
			this->button41->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button41->Location = System::Drawing::Point(26, 105);
			this->button41->Name = L"button41";
			this->button41->Size = System::Drawing::Size(125, 62);
			this->button41->TabIndex = 15;
			this->button41->Text = L"Haptic Settings";
			this->button41->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button41->UseVisualStyleBackColor = false;
			this->button41->Click += gcnew System::EventHandler(this, &MainForm::button41_Click);
			// 
			// button22
			// 
			this->button22->BackColor = System::Drawing::Color::Transparent;
			this->button22->ForeColor = System::Drawing::Color::Black;
			this->button22->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button22.Image")));
			this->button22->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button22->Location = System::Drawing::Point(26, 29);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(125, 62);
			this->button22->TabIndex = 14;
			this->button22->Text = L"Robot Settings";
			this->button22->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button22->UseVisualStyleBackColor = false;
			this->button22->Click += gcnew System::EventHandler(this, &MainForm::button22_Click);
			// 
			// groupBox9
			// 
			this->groupBox9->Controls->Add(this->button36);
			this->groupBox9->Controls->Add(this->button35);
			this->groupBox9->Controls->Add(this->button29);
			this->groupBox9->Controls->Add(this->button38);
			this->groupBox9->Controls->Add(this->btnServo);
			this->groupBox9->Controls->Add(this->button27);
			this->groupBox9->Controls->Add(this->button28);
			this->groupBox9->Controls->Add(this->button9);
			this->groupBox9->Location = System::Drawing::Point(10, 3);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(155, 593);
			this->groupBox9->TabIndex = 18;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"DEFAULT POSITION";
			// 
			// button36
			// 
			this->button36->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button36->ForeColor = System::Drawing::Color::Black;
			this->button36->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button36.Image")));
			this->button36->Location = System::Drawing::Point(14, 426);
			this->button36->Name = L"button36";
			this->button36->Size = System::Drawing::Size(125, 62);
			this->button36->TabIndex = 22;
			this->button36->Text = L"Test Graph";
			this->button36->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->button36->UseVisualStyleBackColor = false;
			this->button36->Click += gcnew System::EventHandler(this, &MainForm::button36_Click);
			// 
			// button35
			// 
			this->button35->BackColor = System::Drawing::Color::Transparent;
			this->button35->ForeColor = System::Drawing::Color::Black;
			this->button35->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button35.Image")));
			this->button35->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button35->Location = System::Drawing::Point(14, 493);
			this->button35->Name = L"button35";
			this->button35->Size = System::Drawing::Size(125, 62);
			this->button35->TabIndex = 21;
			this->button35->Text = L"Save Configuration";
			this->button35->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button35->UseVisualStyleBackColor = false;
			this->button35->Click += gcnew System::EventHandler(this, &MainForm::button35_Click);
			// 
			// button29
			// 
			this->button29->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button29->ForeColor = System::Drawing::Color::Black;
			this->button29->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button29.Image")));
			this->button29->Location = System::Drawing::Point(14, 358);
			this->button29->Name = L"button29";
			this->button29->Size = System::Drawing::Size(125, 62);
			this->button29->TabIndex = 20;
			this->button29->Text = L"Show Graph";
			this->button29->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->button29->UseVisualStyleBackColor = false;
			this->button29->Click += gcnew System::EventHandler(this, &MainForm::button29_Click_1);
			// 
			// button38
			// 
			this->button38->BackColor = System::Drawing::Color::Transparent;
			this->button38->ForeColor = System::Drawing::Color::Black;
			this->button38->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button38.Image")));
			this->button38->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button38->Location = System::Drawing::Point(14, 223);
			this->button38->Name = L"button38";
			this->button38->Size = System::Drawing::Size(125, 62);
			this->button38->TabIndex = 18;
			this->button38->Text = L"Reset Yaskawa";
			this->button38->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button38->UseVisualStyleBackColor = false;
			this->button38->Click += gcnew System::EventHandler(this, &MainForm::button38_Click);
			// 
			// btnServo
			// 
			this->btnServo->BackColor = System::Drawing::Color::Transparent;
			this->btnServo->ForeColor = System::Drawing::Color::Black;
			this->btnServo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnServo.Image")));
			this->btnServo->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnServo->Location = System::Drawing::Point(14, 155);
			this->btnServo->Name = L"btnServo";
			this->btnServo->Size = System::Drawing::Size(125, 62);
			this->btnServo->TabIndex = 17;
			this->btnServo->Text = L"Servo ON";
			this->btnServo->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->btnServo->UseVisualStyleBackColor = false;
			this->btnServo->Click += gcnew System::EventHandler(this, &MainForm::button37_Click);
			// 
			// button27
			// 
			this->button27->BackColor = System::Drawing::Color::Transparent;
			this->button27->ForeColor = System::Drawing::Color::Black;
			this->button27->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button27.Image")));
			this->button27->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button27->Location = System::Drawing::Point(14, 20);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(125, 62);
			this->button27->TabIndex = 15;
			this->button27->Text = L"Home Position";
			this->button27->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button27->UseVisualStyleBackColor = false;
			this->button27->Click += gcnew System::EventHandler(this, &MainForm::button27_Click);
			// 
			// button28
			// 
			this->button28->BackColor = System::Drawing::Color::Transparent;
			this->button28->ForeColor = System::Drawing::Color::Black;
			this->button28->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button28.Image")));
			this->button28->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button28->Location = System::Drawing::Point(14, 88);
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(125, 62);
			this->button28->TabIndex = 16;
			this->button28->Text = L"Standby Position";
			this->button28->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button28->UseVisualStyleBackColor = false;
			this->button28->Click += gcnew System::EventHandler(this, &MainForm::button28_Click);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::Transparent;
			this->button9->ForeColor = System::Drawing::Color::Black;
			this->button9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button9.Image")));
			this->button9->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button9->Location = System::Drawing::Point(14, 290);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(125, 62);
			this->button9->TabIndex = 13;
			this->button9->Text = L"Roboguide Connect";
			this->button9->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &MainForm::button9_Click_1);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->tabControl1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->panel1, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 655)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 82)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 19)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(978, 789);
			this->tableLayoutPanel1->TabIndex = 5;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 5;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel2->Controls->Add(this->btnRunTrajectory, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->btnRunProgram, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->btn_hapticTeleoperation, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->button8, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->button7, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 710);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(972, 76);
			this->tableLayoutPanel2->TabIndex = 5;
			// 
			// btnRunTrajectory
			// 
			this->btnRunTrajectory->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnRunTrajectory->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnRunTrajectory->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRunTrajectory->ForeColor = System::Drawing::Color::Black;
			this->btnRunTrajectory->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnRunTrajectory.Image")));
			this->btnRunTrajectory->Location = System::Drawing::Point(585, 3);
			this->btnRunTrajectory->Name = L"btnRunTrajectory";
			this->btnRunTrajectory->Size = System::Drawing::Size(188, 70);
			this->btnRunTrajectory->TabIndex = 10;
			this->btnRunTrajectory->Text = L"  RUN TRAJECTORY";
			this->btnRunTrajectory->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnRunTrajectory->UseVisualStyleBackColor = false;
			this->btnRunTrajectory->Click += gcnew System::EventHandler(this, &MainForm::button11_Click);
			// 
			// btnRunProgram
			// 
			this->btnRunProgram->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnRunProgram->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnRunProgram->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRunProgram->ForeColor = System::Drawing::Color::Black;
			this->btnRunProgram->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnRunProgram.Image")));
			this->btnRunProgram->Location = System::Drawing::Point(779, 3);
			this->btnRunProgram->Name = L"btnRunProgram";
			this->btnRunProgram->Size = System::Drawing::Size(190, 70);
			this->btnRunProgram->TabIndex = 9;
			this->btnRunProgram->Text = L"  RUN PROGRAM";
			this->btnRunProgram->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnRunProgram->UseVisualStyleBackColor = false;
			this->btnRunProgram->Click += gcnew System::EventHandler(this, &MainForm::button10_Click);
			// 
			// btn_hapticTeleoperation
			// 
			this->btn_hapticTeleoperation->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btn_hapticTeleoperation->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btn_hapticTeleoperation->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_hapticTeleoperation->ForeColor = System::Drawing::Color::Black;
			this->btn_hapticTeleoperation->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_hapticTeleoperation.Image")));
			this->btn_hapticTeleoperation->Location = System::Drawing::Point(391, 3);
			this->btn_hapticTeleoperation->Name = L"btn_hapticTeleoperation";
			this->btn_hapticTeleoperation->Size = System::Drawing::Size(188, 70);
			this->btn_hapticTeleoperation->TabIndex = 8;
			this->btn_hapticTeleoperation->Text = L"HAPTIC TELEOPERATION";
			this->btn_hapticTeleoperation->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_hapticTeleoperation->UseVisualStyleBackColor = false;
			this->btn_hapticTeleoperation->Click += gcnew System::EventHandler(this, &MainForm::button9_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->ForeColor = System::Drawing::Color::Black;
			this->button8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button8.Image")));
			this->button8->Location = System::Drawing::Point(3, 3);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(188, 70);
			this->button8->TabIndex = 7;
			this->button8->Text = L"   INITIALIZATION";
			this->button8->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &MainForm::button8_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->ForeColor = System::Drawing::Color::Black;
			this->button7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button7.Image")));
			this->button7->Location = System::Drawing::Point(197, 3);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(188, 70);
			this->button7->TabIndex = 6;
			this->button7->Text = L"   ROBOT STATUS";
			this->button7->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MainForm::button7_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Black;
			this->panel1->Controls->Add(this->indicator_alarm);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label_speed_ratio);
			this->panel1->Controls->Add(this->indicator_robot);
			this->panel1->Controls->Add(this->indicator_haptic);
			this->panel1->Controls->Add(this->indicator_ftsensor);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(972, 46);
			this->panel1->TabIndex = 6;
			// 
			// indicator_alarm
			// 
			this->indicator_alarm->BackColor = System::Drawing::Color::Red;
			this->indicator_alarm->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->indicator_alarm->Controls->Add(this->label_alarm);
			this->indicator_alarm->Location = System::Drawing::Point(603, 3);
			this->indicator_alarm->Name = L"indicator_alarm";
			this->indicator_alarm->Size = System::Drawing::Size(71, 31);
			this->indicator_alarm->TabIndex = 3;
			// 
			// label_alarm
			// 
			this->label_alarm->AutoSize = true;
			this->label_alarm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_alarm->ForeColor = System::Drawing::Color::White;
			this->label_alarm->Location = System::Drawing::Point(12, 7);
			this->label_alarm->Name = L"label_alarm";
			this->label_alarm->Size = System::Drawing::Size(63, 18);
			this->label_alarm->TabIndex = 0;
			this->label_alarm->Text = L"ALARM";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Aqua;
			this->label3->Location = System::Drawing::Point(8, 5);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(370, 29);
			this->label3->TabIndex = 5;
			this->label3->Text = L"O2O SOFTWARE INTERFACE";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(466, 10);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(69, 18);
			this->label2->TabIndex = 4;
			this->label2->Text = L"SPEED:";
			// 
			// label_speed_ratio
			// 
			this->label_speed_ratio->AutoSize = true;
			this->label_speed_ratio->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_speed_ratio->ForeColor = System::Drawing::Color::Lime;
			this->label_speed_ratio->Location = System::Drawing::Point(531, 5);
			this->label_speed_ratio->Name = L"label_speed_ratio";
			this->label_speed_ratio->Size = System::Drawing::Size(78, 29);
			this->label_speed_ratio->TabIndex = 1;
			this->label_speed_ratio->Text = L"100%";
			// 
			// indicator_robot
			// 
			this->indicator_robot->BackColor = System::Drawing::Color::Maroon;
			this->indicator_robot->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->indicator_robot->Controls->Add(this->label13);
			this->indicator_robot->Location = System::Drawing::Point(680, 3);
			this->indicator_robot->Name = L"indicator_robot";
			this->indicator_robot->Size = System::Drawing::Size(71, 31);
			this->indicator_robot->TabIndex = 2;
			this->indicator_robot->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::panel4_Paint);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::White;
			this->label13->Location = System::Drawing::Point(8, 7);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(67, 18);
			this->label13->TabIndex = 0;
			this->label13->Text = L"ROBOT";
			// 
			// indicator_haptic
			// 
			this->indicator_haptic->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->indicator_haptic->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->indicator_haptic->Controls->Add(this->label12);
			this->indicator_haptic->Location = System::Drawing::Point(756, 3);
			this->indicator_haptic->Name = L"indicator_haptic";
			this->indicator_haptic->Size = System::Drawing::Size(71, 31);
			this->indicator_haptic->TabIndex = 1;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::White;
			this->label12->Location = System::Drawing::Point(8, 7);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(67, 18);
			this->label12->TabIndex = 0;
			this->label12->Text = L"HAPTIC";
			// 
			// indicator_ftsensor
			// 
			this->indicator_ftsensor->BackColor = System::Drawing::Color::Maroon;
			this->indicator_ftsensor->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->indicator_ftsensor->Controls->Add(this->label11);
			this->indicator_ftsensor->Location = System::Drawing::Point(832, 3);
			this->indicator_ftsensor->Name = L"indicator_ftsensor";
			this->indicator_ftsensor->Size = System::Drawing::Size(107, 31);
			this->indicator_ftsensor->TabIndex = 0;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::White;
			this->label11->Location = System::Drawing::Point(8, 7);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(108, 18);
			this->label11->TabIndex = 0;
			this->label11->Text = L"F/T SENSOR";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(978, 789);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1000, 840);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(1000, 840);
			this->Name = L"MainForm";
			this->Text = L"O2O SOFTWARE TEACHING INTERFACE";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->groupBox15->ResumeLayout(false);
			this->tableLayoutPanel9->ResumeLayout(false);
			this->groupBox14->ResumeLayout(false);
			this->tableLayoutPanel8->ResumeLayout(false);
			this->groupBox7->ResumeLayout(false);
			this->tableLayoutPanel7->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tabel1_name->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->groupBox6->ResumeLayout(false);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->groupBox10->ResumeLayout(false);
			this->tableLayoutPanel6->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->groupBox12->ResumeLayout(false);
			this->groupBox11->ResumeLayout(false);
			this->groupBox9->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->indicator_alarm->ResumeLayout(false);
			this->indicator_alarm->PerformLayout();
			this->indicator_robot->ResumeLayout(false);
			this->indicator_robot->PerformLayout();
			this->indicator_haptic->ResumeLayout(false);
			this->indicator_haptic->PerformLayout();
			this->indicator_ftsensor->ResumeLayout(false);
			this->indicator_ftsensor->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
		on_init();
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_add_move_point();
}
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
//	update_line_number();
}
private: System::Void dataGridView1_CellContentDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	
}
private: System::Void dataGridView1_CellDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	btn_edit_program();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_print();
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	show_robot_status_form();
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_add_offline_trajectory();
}
private: System::Void groupBox6_Enter(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_add_wait();
}
private: System::Void groupBox15_Enter(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	on_timer();
}
private: System::Void dataGridView1_SelectionChanged(System::Object^  sender, System::EventArgs^  e) {
	update_line_number();
}
private: System::Void btnInitDevice_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_initDevice();
}
private: System::Void buttonLoad_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_load_trajectory();
}
private: System::Void button33_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_move_to_prev();
}
private: System::Void button30_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_new_trajectory_file();
}
private: System::Void button31_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_add_new_point();
}
private: System::Void button25_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_delete_point();
}
private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_modify_point();
}
private: System::Void dataGridView2_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	
}
private: System::Void dataGridView2_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	update_tab2_line_number();
}
private: System::Void dataGridView2_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	update_tab2_line_number();
}
private: System::Void dataGridView2_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	update_tab2_line_number();
}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_initDevice();
}
private: System::Void button32_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_move_to_selected_position();
}
private: System::Void button34_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_move_to_next();
}
private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_open_calibration_form();
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	show_trajectory_record_form();
}
private: System::Void button15_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_save_trajectory();
}
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_replace_current_pos();
}
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_haptic_teleoperation();
}
private: System::Void button9_Click_1(System::Object^  sender, System::EventArgs^  e) {
	btn_roboguide_connect();
}
private: System::Void button5_Click_1(System::Object^  sender, System::EventArgs^  e) {
	btn_apply_trajectory_calibration();
}
private: System::Void button22_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_open_robot_settings();
}
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_print();
}
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_run_trajectory();
}
private: System::Void button27_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_moveTo_home_pos();
}
private: System::Void button28_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_moveTo_standby_pos();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_add_comment();
}
private: System::Void button18_Click(System::Object^  sender, System::EventArgs^  e) {
	//btn_sequence_modify();
	btn_edit_program();
}
private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_sequence_insert();
}
private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_sequence_delete();
}
private: System::Void button3_Click_1(System::Object^  sender, System::EventArgs^  e) {
	btn_test_io();
}
private: System::Void button26_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_save_sequence_program();
}
private: System::Void button29_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button29_Click_1(System::Object^  sender, System::EventArgs^  e) {
	btn_show_graph();
}
private: System::Void button37_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_servo();
}
private: System::Void button38_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_resetConnection();
}
private: System::Void button24_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_load_sequence_program();
}
private: System::Void button23_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_add_new_program();
}
private: System::Void button35_Click(System::Object^  sender, System::EventArgs^  e) {
	save_configuration();
}
private: System::Void button36_Click(System::Object^  sender, System::EventArgs^  e) {
	show_3d_plot();
}
private: System::Void dataGridView1_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	update_line_number();
}
private: System::Void groupBox4_Enter(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button21_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_add_wait();
}
private: System::Void button39_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_move_to_program_line();
}
private: System::Void button41_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_haptic_setting_form();
}
private: System::Void panel4_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
private: System::Void button40_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_increase_speed();
}
private: System::Void button37_Click_1(System::Object^  sender, System::EventArgs^  e) {
	btn_decrease_speed();
}
private: System::Void button10_Click_1(System::Object^  sender, System::EventArgs^  e) {
	btn_test();
}
private: System::Void button11_Click_1(System::Object^  sender, System::EventArgs^  e) {
	yrc.reset_alarm();
}
private: System::Void button42_Click(System::Object^  sender, System::EventArgs^  e) {
	show_coppeliasim();
}
private: System::Void button43_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_haptic_connect();
}
};
}
