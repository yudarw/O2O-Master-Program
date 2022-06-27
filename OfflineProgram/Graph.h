#pragma once

namespace OfflineProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ChartDirector;

	/// <summary>
	/// Summary for Graph
	/// </summary>
	public ref class Graph : public System::Windows::Forms::Form
	{
	public:
		Graph(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	public:	void on_timer();
	public:	void show_chart();
	public:	XYChart ^ c;
	public: void update_force_ui();

	private: System::Windows::Forms::TrackBar^  trackBarX;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  tbFz;
	private: System::Windows::Forms::ProgressBar^  progressBarZ;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TrackBar^  trackBarZ;
	private: System::Windows::Forms::TextBox^  tbFy;
	private: System::Windows::Forms::ProgressBar^  progressBarY;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TrackBar^  trackBarY;
	private: System::Windows::Forms::TextBox^  tbFx;
	private: System::Windows::Forms::ProgressBar^  progressBarX;
	private: System::Windows::Forms::Label^  label1;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Graph()
		{
			if (components)
			{
				delete components;
			}
		}
	private: ChartDirector::WinChartViewer^  winChartViewer1;
	protected:
	private: System::Windows::Forms::Timer^  timer1;
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
			this->winChartViewer1 = (gcnew ChartDirector::WinChartViewer());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->trackBarX = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tbFz = (gcnew System::Windows::Forms::TextBox());
			this->progressBarZ = (gcnew System::Windows::Forms::ProgressBar());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->trackBarZ = (gcnew System::Windows::Forms::TrackBar());
			this->tbFy = (gcnew System::Windows::Forms::TextBox());
			this->progressBarY = (gcnew System::Windows::Forms::ProgressBar());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->trackBarY = (gcnew System::Windows::Forms::TrackBar());
			this->tbFx = (gcnew System::Windows::Forms::TextBox());
			this->progressBarX = (gcnew System::Windows::Forms::ProgressBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->winChartViewer1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarX))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarZ))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarY))->BeginInit();
			this->SuspendLayout();
			// 
			// winChartViewer1
			// 
			this->winChartViewer1->Location = System::Drawing::Point(0, 0);
			this->winChartViewer1->Name = L"winChartViewer1";
			this->winChartViewer1->Size = System::Drawing::Size(633, 409);
			this->winChartViewer1->TabIndex = 0;
			this->winChartViewer1->TabStop = false;
			this->winChartViewer1->Click += gcnew System::EventHandler(this, &Graph::winChartViewer1_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &Graph::timer1_Tick);
			// 
			// trackBarX
			// 
			this->trackBarX->Location = System::Drawing::Point(182, 42);
			this->trackBarX->Maximum = 100;
			this->trackBarX->Name = L"trackBarX";
			this->trackBarX->Size = System::Drawing::Size(259, 56);
			this->trackBarX->TabIndex = 1;
			this->trackBarX->TickFrequency = 100;
			this->trackBarX->Value = 50;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tbFz);
			this->groupBox1->Controls->Add(this->progressBarZ);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->trackBarZ);
			this->groupBox1->Controls->Add(this->tbFy);
			this->groupBox1->Controls->Add(this->progressBarY);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->trackBarY);
			this->groupBox1->Controls->Add(this->tbFx);
			this->groupBox1->Controls->Add(this->progressBarX);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->trackBarX);
			this->groupBox1->Location = System::Drawing::Point(12, 415);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(609, 172);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"HAPTIC FEEDBACK FORCE";
			// 
			// tbFz
			// 
			this->tbFz->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbFz->Location = System::Drawing::Point(66, 108);
			this->tbFz->Name = L"tbFz";
			this->tbFz->Size = System::Drawing::Size(100, 17);
			this->tbFz->TabIndex = 12;
			this->tbFz->Text = L"0.000";
			this->tbFz->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// progressBarZ
			// 
			this->progressBarZ->Location = System::Drawing::Point(447, 108);
			this->progressBarZ->Name = L"progressBarZ";
			this->progressBarZ->Size = System::Drawing::Size(139, 23);
			this->progressBarZ->TabIndex = 11;
			this->progressBarZ->Value = 40;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(36, 107);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(25, 18);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Fz";
			// 
			// trackBarZ
			// 
			this->trackBarZ->Location = System::Drawing::Point(182, 108);
			this->trackBarZ->Maximum = 100;
			this->trackBarZ->Name = L"trackBarZ";
			this->trackBarZ->Size = System::Drawing::Size(259, 56);
			this->trackBarZ->TabIndex = 9;
			this->trackBarZ->TickFrequency = 100;
			this->trackBarZ->Value = 50;
			// 
			// tbFy
			// 
			this->tbFy->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbFy->Location = System::Drawing::Point(66, 75);
			this->tbFy->Name = L"tbFy";
			this->tbFy->Size = System::Drawing::Size(100, 17);
			this->tbFy->TabIndex = 8;
			this->tbFy->Text = L"0.000";
			this->tbFy->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// progressBarY
			// 
			this->progressBarY->Location = System::Drawing::Point(447, 75);
			this->progressBarY->Name = L"progressBarY";
			this->progressBarY->Size = System::Drawing::Size(139, 23);
			this->progressBarY->TabIndex = 7;
			this->progressBarY->Value = 40;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(36, 74);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(24, 18);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Fy";
			// 
			// trackBarY
			// 
			this->trackBarY->Location = System::Drawing::Point(182, 75);
			this->trackBarY->Maximum = 100;
			this->trackBarY->Name = L"trackBarY";
			this->trackBarY->Size = System::Drawing::Size(259, 56);
			this->trackBarY->TabIndex = 5;
			this->trackBarY->TickFrequency = 100;
			this->trackBarY->Value = 50;
			// 
			// tbFx
			// 
			this->tbFx->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbFx->Location = System::Drawing::Point(66, 42);
			this->tbFx->Name = L"tbFx";
			this->tbFx->Size = System::Drawing::Size(100, 17);
			this->tbFx->TabIndex = 4;
			this->tbFx->Text = L"0.000";
			this->tbFx->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// progressBarX
			// 
			this->progressBarX->Location = System::Drawing::Point(447, 42);
			this->progressBarX->Name = L"progressBarX";
			this->progressBarX->Size = System::Drawing::Size(139, 23);
			this->progressBarX->TabIndex = 3;
			this->progressBarX->Value = 40;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(36, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(24, 18);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Fx";
			// 
			// Graph
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(633, 599);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->winChartViewer1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"Graph";
			this->Text = L"Graph";
			this->Load += gcnew System::EventHandler(this, &Graph::Graph_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->winChartViewer1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarX))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarZ))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarY))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Graph_Load(System::Object^  sender, System::EventArgs^  e) {
		//on_timer();
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		on_timer();
	}
	private: System::Void winChartViewer1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
