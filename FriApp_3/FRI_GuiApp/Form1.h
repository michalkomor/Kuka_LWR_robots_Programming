#pragma once
namespace FRI_GuiApp {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1()
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			addRowsToDataView();

			resetGui(false);
		}

	protected:
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  msrDataView;
	protected: 

	private: System::ComponentModel::BackgroundWorker^  FRIThread;
	private: System::Windows::Forms::Button^  startStop;

	private: System::Windows::Forms::Label^  Quality;
	private: System::Windows::Forms::Label^  Motor;
	private: System::Windows::Forms::Label^  FRIState;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  cmdMsrPos;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  msrMsrPos;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  estExtJntTrq;
	private: System::Windows::Forms::DataGridView^  dataViewKRLUser;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  FRMReal;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  TOReal;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  FRMInt;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  TOInt;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  FRMBool;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  TOBool;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  testBoxStatistics;
	private: System::Windows::Forms::CheckBox^  checkBoxDoSpeed;
	private: System::Windows::Forms::TrackBar^  trackBarA1;
	private: System::Windows::Forms::TrackBar^  trackBarA2;
	private: System::Windows::Forms::TrackBar^  trackBarA3;
	private: System::Windows::Forms::TrackBar^  trackBarA4;
	private: System::Windows::Forms::TrackBar^  trackBarA5;
	private: System::Windows::Forms::TrackBar^  trackBarA6;
	private: System::Windows::Forms::TrackBar^  trackBarA7;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  FRICtrlModeLabel;
	private: System::Windows::Forms::ProgressBar^  FRI_Life;























	private: System::Windows::Forms::DataGridViewTextBoxColumn^  msrTorque;




	protected: 

		void addRowsToDataView()
		{

			// Guenter weiss noch nicht, wohin damit
			// Es gibt bereits einen Eintrag, mit Add fügt man weitere hinzu
			for (int i = 0; i < LBR_MNJ; i++)
				this->msrDataView->Rows->Add();	
			for ( int i = 0; i < FRI_USER_SIZE; i++)
			{
				this ->dataViewKRLUser->Rows->Add();
				// Vorbelegen
			}
			for ( int i = 0; i < FRI_USER_SIZE; i++)
			{
				this->dataViewKRLUser->Rows[i]->Cells[/*"FRMReal" */0]->Value=0.0;
				this->dataViewKRLUser->Rows[i]->Cells[/*"FRMInt" */2]->Value= i;
				this->dataViewKRLUser->Rows[i]->Cells[/*"FRMBool" */4]->Value= false;

				this->dataViewKRLUser->Rows[i]->Cells[/*"TOReal" */1]->Value=0.0;
				this->dataViewKRLUser->Rows[i]->Cells[/*"TOInt" */3]->Value=i;
				this->dataViewKRLUser->Rows[i]->Cells[/*"TOBool" */5]->Value=false;
			}



		}

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->msrDataView = (gcnew System::Windows::Forms::DataGridView());
			this->cmdMsrPos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->msrMsrPos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->msrTorque = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->estExtJntTrq = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->FRIThread = (gcnew System::ComponentModel::BackgroundWorker());
			this->startStop = (gcnew System::Windows::Forms::Button());
			this->Quality = (gcnew System::Windows::Forms::Label());
			this->Motor = (gcnew System::Windows::Forms::Label());
			this->FRIState = (gcnew System::Windows::Forms::Label());
			this->dataViewKRLUser = (gcnew System::Windows::Forms::DataGridView());
			this->FRMReal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TOReal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->FRMInt = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TOInt = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->FRMBool = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->TOBool = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->FRICtrlModeLabel = (gcnew System::Windows::Forms::Label());
			this->testBoxStatistics = (gcnew System::Windows::Forms::TextBox());
			this->checkBoxDoSpeed = (gcnew System::Windows::Forms::CheckBox());
			this->trackBarA1 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarA2 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarA3 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarA4 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarA5 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarA6 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarA7 = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->FRI_Life = (gcnew System::Windows::Forms::ProgressBar());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->msrDataView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataViewKRLUser))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarA1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarA2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarA3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarA4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarA5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarA6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarA7))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// msrDataView
			// 
			this->msrDataView->AllowUserToAddRows = false;
			this->msrDataView->AllowUserToDeleteRows = false;
			this->msrDataView->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->msrDataView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->msrDataView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->cmdMsrPos, 
				this->msrMsrPos, this->msrTorque, this->estExtJntTrq});
			this->msrDataView->Location = System::Drawing::Point(-4, 2);
			this->msrDataView->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->msrDataView->Name = L"msrDataView";
			this->msrDataView->RowTemplate->Height = 28;
			this->msrDataView->Size = System::Drawing::Size(418, 202);
			this->msrDataView->TabIndex = 0;
			// 
			// cmdMsrPos
			// 
			this->cmdMsrPos->HeaderText = L"msrCmdPos";
			this->cmdMsrPos->Name = L"cmdMsrPos";
			this->cmdMsrPos->ReadOnly = true;
			// 
			// msrMsrPos
			// 
			this->msrMsrPos->HeaderText = L"msrMsrPos";
			this->msrMsrPos->Name = L"msrMsrPos";
			this->msrMsrPos->ReadOnly = true;
			// 
			// msrTorque
			// 
			this->msrTorque->HeaderText = L"msrTorque";
			this->msrTorque->Name = L"msrTorque";
			this->msrTorque->ReadOnly = true;
			// 
			// estExtJntTrq
			// 
			this->estExtJntTrq->HeaderText = L"estExtJntTrq";
			this->estExtJntTrq->Name = L"estExtJntTrq";
			this->estExtJntTrq->ReadOnly = true;
			// 
			// FRIThread
			// 
			this->FRIThread->WorkerReportsProgress = true;
			this->FRIThread->WorkerSupportsCancellation = true;
			this->FRIThread->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::FRIThread_DoWork);
			this->FRIThread->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &Form1::FRIThread_ProgressChanged);
			// 
			// startStop
			// 
			this->startStop->Location = System::Drawing::Point(17, 8);
			this->startStop->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->startStop->Name = L"startStop";
			this->startStop->Size = System::Drawing::Size(76, 26);
			this->startStop->TabIndex = 1;
			this->startStop->Text = L"startStop";
			this->startStop->UseVisualStyleBackColor = true;
			this->startStop->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Quality
			// 
			this->Quality->AutoSize = true;
			this->Quality->Location = System::Drawing::Point(11, 13);
			this->Quality->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Quality->Name = L"Quality";
			this->Quality->Size = System::Drawing::Size(39, 13);
			this->Quality->TabIndex = 3;
			this->Quality->Text = L"Quality";
			// 
			// Motor
			// 
			this->Motor->AutoSize = true;
			this->Motor->Location = System::Drawing::Point(69, 13);
			this->Motor->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Motor->Name = L"Motor";
			this->Motor->Size = System::Drawing::Size(34, 13);
			this->Motor->TabIndex = 4;
			this->Motor->Text = L"Motor";
			// 
			// FRIState
			// 
			this->FRIState->AutoSize = true;
			this->FRIState->Location = System::Drawing::Point(122, 13);
			this->FRIState->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->FRIState->Name = L"FRIState";
			this->FRIState->Size = System::Drawing::Size(49, 13);
			this->FRIState->TabIndex = 5;
			this->FRIState->Text = L"FRIState";
			// 
			// dataViewKRLUser
			// 
			this->dataViewKRLUser->AllowUserToAddRows = false;
			this->dataViewKRLUser->AllowUserToDeleteRows = false;
			this->dataViewKRLUser->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataViewKRLUser->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataViewKRLUser->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {this->FRMReal, 
				this->TOReal, this->FRMInt, this->TOInt, this->FRMBool, this->TOBool});
			this->dataViewKRLUser->Location = System::Drawing::Point(443, 58);
			this->dataViewKRLUser->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dataViewKRLUser->Name = L"dataViewKRLUser";
			this->dataViewKRLUser->RowTemplate->Height = 28;
			this->dataViewKRLUser->Size = System::Drawing::Size(364, 354);
			this->dataViewKRLUser->TabIndex = 6;
			this->dataViewKRLUser->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dataViewKRLUser_CellContentClick);
			// 
			// FRMReal
			// 
			this->FRMReal->HeaderText = L"FRMReal";
			this->FRMReal->Name = L"FRMReal";
			// 
			// TOReal
			// 
			this->TOReal->HeaderText = L"TOReal";
			this->TOReal->Name = L"TOReal";
			// 
			// FRMInt
			// 
			this->FRMInt->HeaderText = L"FRMInt";
			this->FRMInt->Name = L"FRMInt";
			this->FRMInt->ReadOnly = true;
			this->FRMInt->Width = 70;
			// 
			// TOInt
			// 
			this->TOInt->HeaderText = L"TOInt";
			this->TOInt->Name = L"TOInt";
			this->TOInt->Width = 70;
			// 
			// FRMBool
			// 
			this->FRMBool->HeaderText = L"FRMBool";
			this->FRMBool->Name = L"FRMBool";
			this->FRMBool->ReadOnly = true;
			this->FRMBool->Width = 50;
			// 
			// TOBool
			// 
			this->TOBool->HeaderText = L"TOBool";
			this->TOBool->Name = L"TOBool";
			this->TOBool->Width = 50;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->FRICtrlModeLabel);
			this->groupBox1->Controls->Add(this->Quality);
			this->groupBox1->Controls->Add(this->Motor);
			this->groupBox1->Controls->Add(this->FRIState);
			this->groupBox1->Location = System::Drawing::Point(103, 3);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->groupBox1->Size = System::Drawing::Size(260, 31);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			// 
			// FRICtrlModeLabel
			// 
			this->FRICtrlModeLabel->AutoSize = true;
			this->FRICtrlModeLabel->Location = System::Drawing::Point(176, 13);
			this->FRICtrlModeLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->FRICtrlModeLabel->Name = L"FRICtrlModeLabel";
			this->FRICtrlModeLabel->Size = System::Drawing::Size(79, 13);
			this->FRICtrlModeLabel->TabIndex = 6;
			this->FRICtrlModeLabel->Text = L"FRICTRLMode";
			// 
			// testBoxStatistics
			// 
			this->testBoxStatistics->Location = System::Drawing::Point(367, 3);
			this->testBoxStatistics->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->testBoxStatistics->Multiline = true;
			this->testBoxStatistics->Name = L"testBoxStatistics";
			this->testBoxStatistics->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->testBoxStatistics->Size = System::Drawing::Size(365, 38);
			this->testBoxStatistics->TabIndex = 8;
			// 
			// checkBoxDoSpeed
			// 
			this->checkBoxDoSpeed->AutoSize = true;
			this->checkBoxDoSpeed->Location = System::Drawing::Point(367, 279);
			this->checkBoxDoSpeed->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->checkBoxDoSpeed->Name = L"checkBoxDoSpeed";
			this->checkBoxDoSpeed->Size = System::Drawing::Size(74, 17);
			this->checkBoxDoSpeed->TabIndex = 9;
			this->checkBoxDoSpeed->Text = L"Do Speed";
			this->checkBoxDoSpeed->UseVisualStyleBackColor = true;
			this->checkBoxDoSpeed->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxDoSpeed_CheckedChanged);
			// 
			// trackBarA1
			// 
			this->trackBarA1->AutoSize = false;
			this->trackBarA1->Location = System::Drawing::Point(4, 16);
			this->trackBarA1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->trackBarA1->Maximum = 5;
			this->trackBarA1->Minimum = -5;
			this->trackBarA1->Name = L"trackBarA1";
			this->trackBarA1->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBarA1->Size = System::Drawing::Size(39, 161);
			this->trackBarA1->TabIndex = 10;
			// 
			// trackBarA2
			// 
			this->trackBarA2->AutoSize = false;
			this->trackBarA2->Location = System::Drawing::Point(39, 16);
			this->trackBarA2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->trackBarA2->Maximum = 5;
			this->trackBarA2->Minimum = -5;
			this->trackBarA2->Name = L"trackBarA2";
			this->trackBarA2->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBarA2->Size = System::Drawing::Size(39, 161);
			this->trackBarA2->TabIndex = 11;
			// 
			// trackBarA3
			// 
			this->trackBarA3->AutoSize = false;
			this->trackBarA3->Location = System::Drawing::Point(83, 16);
			this->trackBarA3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->trackBarA3->Maximum = 5;
			this->trackBarA3->Minimum = -5;
			this->trackBarA3->Name = L"trackBarA3";
			this->trackBarA3->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBarA3->Size = System::Drawing::Size(41, 161);
			this->trackBarA3->TabIndex = 12;
			// 
			// trackBarA4
			// 
			this->trackBarA4->AutoSize = false;
			this->trackBarA4->Location = System::Drawing::Point(128, 16);
			this->trackBarA4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->trackBarA4->Maximum = 5;
			this->trackBarA4->Minimum = -5;
			this->trackBarA4->Name = L"trackBarA4";
			this->trackBarA4->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBarA4->Size = System::Drawing::Size(40, 161);
			this->trackBarA4->TabIndex = 13;
			// 
			// trackBarA5
			// 
			this->trackBarA5->AutoSize = false;
			this->trackBarA5->Location = System::Drawing::Point(180, 16);
			this->trackBarA5->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->trackBarA5->Maximum = 5;
			this->trackBarA5->Minimum = -5;
			this->trackBarA5->Name = L"trackBarA5";
			this->trackBarA5->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBarA5->Size = System::Drawing::Size(38, 161);
			this->trackBarA5->TabIndex = 14;
			// 
			// trackBarA6
			// 
			this->trackBarA6->AutoSize = false;
			this->trackBarA6->Location = System::Drawing::Point(229, 16);
			this->trackBarA6->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->trackBarA6->Maximum = 5;
			this->trackBarA6->Minimum = -5;
			this->trackBarA6->Name = L"trackBarA6";
			this->trackBarA6->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBarA6->Size = System::Drawing::Size(39, 161);
			this->trackBarA6->TabIndex = 15;
			// 
			// trackBarA7
			// 
			this->trackBarA7->AutoSize = false;
			this->trackBarA7->Location = System::Drawing::Point(291, 16);
			this->trackBarA7->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->trackBarA7->Maximum = 5;
			this->trackBarA7->Minimum = -5;
			this->trackBarA7->Name = L"trackBarA7";
			this->trackBarA7->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBarA7->Size = System::Drawing::Size(39, 161);
			this->trackBarA7->TabIndex = 16;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->trackBarA7);
			this->groupBox2->Controls->Add(this->trackBarA1);
			this->groupBox2->Controls->Add(this->trackBarA2);
			this->groupBox2->Controls->Add(this->trackBarA3);
			this->groupBox2->Controls->Add(this->trackBarA4);
			this->groupBox2->Controls->Add(this->trackBarA5);
			this->groupBox2->Controls->Add(this->trackBarA6);
			this->groupBox2->Location = System::Drawing::Point(11, 279);
			this->groupBox2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->groupBox2->Size = System::Drawing::Size(347, 190);
			this->groupBox2->TabIndex = 17;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"groupBox2";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(17, 49);
			this->tabControl1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(422, 196);
			this->tabControl1->TabIndex = 18;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->msrDataView);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tabPage1->Size = System::Drawing::Size(414, 170);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"msrData";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->comboBox1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tabPage2->Size = System::Drawing::Size(293, 135);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Demo";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(8) {L"Nothing", L"PTP P1", L"PTP P2", L"CartImp", L"Lissajou", 
				L"Position", L"FRIStart ", L"FRIStop"});
			this->comboBox1->Location = System::Drawing::Point(17, 25);
			this->comboBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(82, 21);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// FRI_Life
			// 
			this->FRI_Life->Location = System::Drawing::Point(17, 30);
			this->FRI_Life->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->FRI_Life->Name = L"FRI_Life";
			this->FRI_Life->Size = System::Drawing::Size(76, 15);
			this->FRI_Life->TabIndex = 19;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(899, 480);
			this->Controls->Add(this->FRI_Life);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->checkBoxDoSpeed);
			this->Controls->Add(this->testBoxStatistics);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataViewKRLUser);
			this->Controls->Add(this->startStop);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"Form1";
			this->Text = L"FRI_RemoteTest";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->msrDataView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataViewKRLUser))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarA1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarA2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarA3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarA4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarA5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarA6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarA7))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 resetSpeeds();
				 if ( this->FRIThread->IsBusy)
				 {
					 // stop it
					 this->FRIThread->CancelAsync();
					 this->startStop->BackColor = System::Drawing::Color::Red;
					 resetGui(false);
				 }
				 else
				 {
					 this->FRIThread->RunWorkerAsync();
					 this->startStop->BackColor = System::Drawing::Color::Green;
				 }

			 }
			 void resetGui(bool connectPending)
			 {
				 resetSpeeds();
				 /* Fixme -- reset colors etc... */
				 if ( connectPending )
					 this->startStop->BackColor=System::Drawing::Color::Beige;

				 else
					 this->startStop->BackColor=System::Drawing::Color::Gray;
				 this->Motor->BackColor=System::Drawing::Color::Gray;
				 this->Quality->BackColor=System::Drawing::Color::Gray;
				 this->FRIState->BackColor=System::Drawing::Color::Gray;
				 this->checkBoxDoSpeed->Checked=false;
				 this->groupBox2->Hide();

				 this->comboBox1->SelectedIndex = 0;
				 this->FRICtrlModeLabel->Text="CTRL N/A";
				 for ( int i = 0; i < FRI_USER_SIZE; i++)								//MO¯E TU COŒ TRZEBA ZMIENIæ TO NIE BÊDZIE TEGO B£ÊDU!!!!!
				 {
					 this->dataViewKRLUser->Rows[i]->Cells[/*"FRMReal" */0]->Value=0.0;
					 this->dataViewKRLUser->Rows[i]->Cells[/*"FRMInt" */2]->Value= i;
					 this->dataViewKRLUser->Rows[i]->Cells[/*"FRMBool" */4]->Value= false;

					 this->dataViewKRLUser->Rows[i]->Cells[/*"TOReal" */1]->Value=0.0;
					 this->dataViewKRLUser->Rows[i]->Cells[/*"TOInt" */3]->Value=i;
					 this->dataViewKRLUser->Rows[i]->Cells[/*"TOBool" */5]->Value=false;
				 }
				 this->dataViewKRLUser->Rows[0]->Cells[/*"TOReal" */1]->Value=200;
				 this->dataViewKRLUser->Rows[1]->Cells[/*"TOReal" */1]->Value=2000;
				 this->dataViewKRLUser->Rows[2]->Cells[/*"TOReal" */1]->Value=2000;
				 this->dataViewKRLUser->Rows[3]->Cells[/*"TOReal" */1]->Value=250;
				 this->dataViewKRLUser->Rows[4]->Cells[/*"TOReal" */1]->Value=250;
				 this->dataViewKRLUser->Rows[5]->Cells[/*"TOReal" */1]->Value=250;

			 }
			 void resetSpeeds()
			 {
				 int aNullValue = 0;
				 this->trackBarA1->Value=aNullValue;
				 this->trackBarA2->Value=aNullValue;
				 this->trackBarA3->Value=aNullValue;
				 this->trackBarA4->Value=aNullValue;
				 this->trackBarA5->Value=aNullValue;
				 this->trackBarA6->Value=aNullValue;
				 this->trackBarA7->Value=aNullValue;

			 }
			 void updateGui( tFriMsrData &msr,
				 tFriCmdData &cmd)
			 {
				 bool updateRequired = false;
				 {
					 static int lastState = -1;
					 // just detect change // update neccessary for high speeds 
					 if ( lastState != msr.intf.state)
					 {
						 updateRequired = true;
					 }
					 lastState = msr.intf.state;
				 }
				 {
					 static int lastQuality = -1;
					 if ( lastQuality != msr.intf.quality )
					 {
						 updateRequired = true;
					 }
					 lastQuality = msr.intf.quality;
					}
				 {
					 static int lastMotor = -1;
					 if ( lastMotor != msr.robot.power)
					 {
						 updateRequired = true;
					 }
					 lastMotor = msr.robot.power;
				 }
				 int divisor = (int) Math::Ceiling( 0.1/msr.intf.desiredCmdSampleTime );
				 if ( msr.head.sendSeqCount % divisor == 0)
				 {
					 updateRequired = true;
				 }
				 // return, if no update required
				 if ( ! updateRequired ) {return ;}

				 {
					 System::String ^aString;
					 aString = gcnew  System::String("");
					 aString->Format("timestamp = {0}; state = {1}; quality = {2}; desiredMsrSampleTime = {3}; desiredCmdSampleTime = {4}; safetyLimits = {5};",
						 msr.intf.timestamp, msr.intf.state, msr.intf.quality, msr.intf.desiredMsrSampleTime, msr.intf.desiredCmdSampleTime, msr.intf.safetyLimits);

					 this->testBoxStatistics->Text=aString;
				 }
				 /* Quality */
				 switch (msr.intf.quality)
				 {
				 case FRI_QUALITY_BAD:
					 this->Quality->BackColor=Color::Red;
					 break;
				 case FRI_QUALITY_UNACCEPTABLE:
					 this->Quality->BackColor=Color::OrangeRed;
					 break;
				 case FRI_QUALITY_OK:
					 this->Quality->BackColor=Color::Yellow;
					 break;
				 case FRI_QUALITY_PERFECT:
					 this->Quality->BackColor=Color::Green;
					 break;
				 default:
					 this->Quality->BackColor=Color::Transparent;
					 break;
				 }


				 /* Motor */
				 if  (msr.robot.power)
				 {
					 this->Motor->BackColor=Color::Green;
				 }
				 else
				 {
					 this->Motor->BackColor=Color::Red;
				 }


				 /* FRI State */
				 switch (msr.intf.state)
				 {
				 case FRI_STATE_OFF:  // No State at all
					 this->FRIState->BackColor=Color::Red;
					 resetSpeeds();
					 break;
				 case FRI_STATE_MON:
					 this->FRIState->BackColor=Color::Yellow;
					 resetSpeeds();
					 break;
				 case FRI_STATE_CMD:
					 this->FRIState->BackColor=Color::Green;
					 break;
				 default:
					 this->FRIState->BackColor=Color::Transparent;
					 break;
				 }


				 switch (msr.robot.control)
				 {
				 case FRI_CTRL_POSITION: // 1
					 this->FRICtrlModeLabel->Text = "Position";
					 break;
				 case FRI_CTRL_CART_IMP: // 2
					 this->FRICtrlModeLabel->Text = "CartImp";
					 break;
				 case FRI_CTRL_JNT_IMP: //3 
					 this->FRICtrlModeLabel->Text = "JntImp";
					 break;

				 case FRI_CTRL_OTHER: // 0
					 this->FRICtrlModeLabel->Text = "Other";
					 break;				
				 default:
					 this->FRICtrlModeLabel->Text = "Unknown";

				 }
				 for (int i = 0; i < LBR_MNJ; i++)
				 {
					 //this->msrDataView->Rows[i]->Cells["msrCmdPos"]->Value=msr.data.cmdJntPos[i];
					 this->msrDataView->Rows[i]->Cells[0]->Value=msr.data.cmdJntPos[i];

					 //this->msrDataView->Rows[i]->Cells["msrMsrPos"]->Value=msr.data.msrJntPos[i];

					 this->msrDataView->Rows[i]->Cells[1]->Value=msr.data.msrJntPos[i];
					 //this->msrDataView->Rows[i]->Cells["msrTorque"]->Value=msr.data.msrJntTrq[i];
					 this->msrDataView->Rows[i]->Cells[2]->Value=msr.data.msrJntTrq[i];
					 //this->msrDataView->Rows[i]->Cells["estExtJntTrq"]->Value=msr.data.estExtJntTrq[i];
					 this->msrDataView->Rows[i]->Cells[3]->Value=msr.data.estExtJntTrq[i];
				 }
				 int boolData=0;
				 for ( int i = 0 ; i < FRI_USER_SIZE; i++)
				 {
					 // Austausch der KRL User Variablen...
					 // lesen
					 this->dataViewKRLUser->Rows[i]->Cells[/*"FRMReal" */0]->Value=msr.krl.realData[i];
					 this->dataViewKRLUser->Rows[i]->Cells[/*"FRMInt" */2]->Value=msr.krl.intData[i];
					 this->dataViewKRLUser->Rows[i]->Cells[/*"FRMBool" */4]->Value=(msr.krl.boolData & (1<<i));

					 // schreiben
					 System::Single aVal = 
						 System::Convert::ToSingle(this->dataViewKRLUser->Rows[i]->Cells[/*"TOReal" */1]->Value);

					 cmd.krl.realData[i]=aVal;

					 System::Int64 anotherVal = 
						 System::Convert::ToInt64(this->dataViewKRLUser->Rows[i]->Cells[/*"TOInt" */3]->Value);

					 cmd.krl.intData[i] = (long)anotherVal;
					 boolData|= ((System::Convert::ToBoolean(this->dataViewKRLUser->Rows[i]->Cells[/*"TOBool" */5]->Value))?1:0 )<<i;

				 }
				 cmd.krl.boolData=boolData;

				 // optional "Kommando Modi" setzen
				 //
				 // diese sollten aber in der Echtzeitschleife (Background task) ausgewertet werden
				 //
				 //
				 if ( this->checkBoxDoSpeed->Checked)
				 {
					 int val;
#define READ_CONVERT_TRACKBAR(TRACKBAR,INDEX) \
	val = System::Convert::ToInt32( this->TRACKBAR->Value); \
	jntSpeed[INDEX]=(float)val / 10.f;

					 READ_CONVERT_TRACKBAR(trackBarA1,0);
					 READ_CONVERT_TRACKBAR(trackBarA2,1);
					 READ_CONVERT_TRACKBAR(trackBarA3,2);
					 READ_CONVERT_TRACKBAR(trackBarA4,3);
					 READ_CONVERT_TRACKBAR(trackBarA5,4);
					 READ_CONVERT_TRACKBAR(trackBarA6,5);
					 READ_CONVERT_TRACKBAR(trackBarA7,6);

					 flagDoJntSpeed = true;

				 }
				 else
				 {
					 flagDoJntSpeed=false;
					 for ( int i = 0; i < LBR_MNJ; i++)
					 {
						 jntSpeed[i]=0.;
						 jntLastIncrement[i]=0.;
					 }
				 }
			 }

			 void doCommandMode( friRemote&friInst)
			 {				 
				 float cmdJntPos[LBR_MNJ];
				 // initialize properly								
				 for ( int i= 0; i < LBR_MNJ; i++)
				 {
					 cmdJntPos[i]= friInst.getMsrMsrJntPosition()[i]; //teraz mo¿na w³¹czyæ ZAWSZE
					//cmdJntPos[i]= friInst.getMsrMsrJntPosition()[i];	//skacze o milimetry tylko i wraca - z³e dzia³anie
					 //friInst.getMsrCmdJntPosition()[i] + friInst.getMsrCmdJntPositionOffset()[i];  //w³¹cza siê tylko przy dobrej poz. pocz¹tkowej!!
				 }
				 if (friInst.isPowerOn())
				 {
					 if ( flagDoJntSpeed )
					 {
						 for ( int i= 0; i < LBR_MNJ; i++)
						 {
							 cmdJntPos[i]+=jntSpeed[i] * msr.intf.desiredCmdSampleTime;		//ZMIANA
						 }
					 }
				 }
				 // Just set the desired position - but don't do data exchange
				 // This is job of the background worker itself
				 friInst.doPositionControl(cmdJntPos,false);
			 }
	private: System::Void FRIThread_ProgressChanged(System::Object^  sender,System::ComponentModel::ProgressChangedEventArgs ^  e) 
			 {
				 // update the internal gui with measurements
				 if ( e->ProgressPercentage >= 9 ) // worker is successful
					 updateGui(msr,cmd);
				 else
					 resetGui(true);
				 this->FRI_Life->Value=e->ProgressPercentage;
			 }
	private: System::Void FRIThread_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) 
			 {
				 System::ComponentModel::BackgroundWorker^ worker = dynamic_cast<System::ComponentModel::BackgroundWorker^>(sender); // as BackgroundWorker;

				 System::Threading::Thread::CurrentThread->Priority=System::Threading::ThreadPriority::AboveNormal;
				 //System::CurrentThread->Priority=System::ThreadPriority::Realtime;


				 // open the connection
				 /// Open the Fast Research Interface
				 friRemote friInst;
				 while ( !(worker->CancellationPending) )
				 {
					 if (friInst.doReceiveData()>=0)
					 {
						 msr=friInst.getMsrBuf();
						 friInst.getCmdBuf()=cmd;
						 doCommandMode(friInst);
						 friInst.doSendData();
						 worker->ReportProgress( friInst.getSequenceCount()%90+10  );
					 }
					 else
					 {
						 worker->ReportProgress( 0  );
					 }
				 } /* end while */

			 }

	private: System::Void dataViewKRLUser_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		 }
	private: System::Void tabPage1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void tabPage1_Click_1(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void checkBoxDoSpeed_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 this->groupBox2->Visible  = this->checkBoxDoSpeed->Checked;
				 resetSpeeds();
			 }
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

				 this->dataViewKRLUser->Rows[0]->Cells[/*"TOInt" */3]->Value=
					 this->comboBox1->SelectedIndex;
				 int val = this->comboBox1->SelectedIndex;
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 this->Size.Width=800;
				 this->Size.Height=690;
			 }
	};
}

