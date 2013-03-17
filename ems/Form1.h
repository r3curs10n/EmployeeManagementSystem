#pragma once
#include "Auth.h"
#include "Employee.h"
#include "ProfFeedback.h"
#include "search.h"
#define isNew chkIsNew->Checked
namespace ems {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	using namespace System::IO;
	using namespace FormSerialisation;
	using namespace System::Diagnostics;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			fields = "";
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

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
	private: System::Windows::Forms::TextBox^  txtUser;
	protected: 
	private: System::Windows::Forms::TextBox^  txtPass;
	private: System::Windows::Forms::Button^  btnLogin;

	private: System::Windows::Forms::TextBox^  txtName;


	private: System::Windows::Forms::TextBox^  txtId;
	private: System::Windows::Forms::Button^  btnView;
	private: System::Windows::Forms::TextBox^  txtMobile;
	private: System::Windows::Forms::DateTimePicker^  txtDob;
	private: System::Windows::Forms::Panel^  pnlProf;


	private: System::Windows::Forms::ListBox^  lstProfRi;
	private: System::Windows::Forms::TextBox^  txtRi;
	private: System::Windows::Forms::Button^  btnAddRi;
	private: System::Windows::Forms::Button^  btnRemoveRi;
	private: System::Windows::Forms::Panel^  pnlData;
	private: System::Windows::Forms::TextBox^  txtProfCourse;
	private: System::Windows::Forms::Button^  btnShowProfFeedback;
	private: System::Windows::Forms::Button^  btnGenProfFeedback;
	private: System::Windows::Forms::TextBox^  txtNumStudents;
	private: System::Windows::Forms::PictureBox^  pbxPicture;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  QUALIFICATION;
	private: System::Windows::Forms::ComboBox^  txtProfDept;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  txtProfCoursesTaught;

	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  txtProfProjects;

	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TextBox^  txtProfWebmail;
	private: System::Windows::Forms::Panel^  pnlSecurity;
	private: System::Windows::Forms::TextBox^  txtPlace;

	public: static String^ fields;

	private: System::Windows::Forms::Label^  PLACE;
	private: System::Windows::Forms::TextBox^  txtNumOfLeaves;

	private: System::Windows::Forms::DateTimePicker^  txtStartDate;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::TextBox^  txtSalary;
	private: System::Windows::Forms::ComboBox^  txtTitle;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Button^  btnADD;

	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::DateTimePicker^  txtEndTime;

	private: System::Windows::Forms::DateTimePicker^  txtStartTime;

	private: System::Windows::Forms::ComboBox^  txtDay;
	private: System::Windows::Forms::ListBox^  lstSecurityTimings;
	private: System::Windows::Forms::Button^  btnUpload;
	private: System::Windows::Forms::OpenFileDialog^  FileDialog;
	private: System::Windows::Forms::Panel^  pnlStaff;
	private: System::Windows::Forms::ComboBox^  txtStaffResponsibility;

	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::TextBox^  txtStaffLocation;

	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::ComboBox^  txtStaffCategory;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::ComboBox^  txtRole;

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  addToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  profToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  staffToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  securityToolStripMenuItem;
private: System::Windows::Forms::Label^  label26;
private: System::Windows::Forms::Label^  label25;
private: System::Windows::Forms::Label^  label24;
private: System::Windows::Forms::TextBox^  txtmast;

private: System::Windows::Forms::TextBox^  txtphd;
private: System::Windows::Forms::TextBox^  txtbach;
private: System::Windows::Forms::TextBox^  txtStaffDepartment;
private: System::Windows::Forms::Label^  label27;
private: System::Windows::Forms::Button^  btnSecSubtract;
private: System::Windows::Forms::Label^  lblId;
private: System::Windows::Forms::Button^  btnSave;
private: System::Windows::Forms::Panel^  pnlSearch;

private: System::Windows::Forms::GroupBox^  groupBox2;
private: System::Windows::Forms::GroupBox^  groupBox3;
private: System::Windows::Forms::Label^  label28;
private: System::Windows::Forms::ComboBox^  Day_comboBox;
private: System::Windows::Forms::Label^  label29;
private: System::Windows::Forms::Label^  label30;
private: System::Windows::Forms::DateTimePicker^  dateTimePicker2;
private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
private: System::Windows::Forms::Button^  Searchbtn_TimeandDay;
private: System::Windows::Forms::ComboBox^  Place_comboBox;
private: System::Windows::Forms::Label^  label31;
private: System::Windows::Forms::Label^  label32;
private: System::Windows::Forms::ComboBox^  SearchforSecurity_comboBox;
private: System::Windows::Forms::GroupBox^  groupBox1;
private: System::Windows::Forms::ComboBox^  projects;
private: System::Windows::Forms::ComboBox^  webmail;
private: System::Windows::Forms::Label^  label33;
private: System::Windows::Forms::Label^  label34;
private: System::Windows::Forms::Label^  label35;
private: System::Windows::Forms::ComboBox^  Searchby_comboBox;
private: System::Windows::Forms::Label^  label36;
private: System::Windows::Forms::ComboBox^  Research_comboBox;
private: System::Windows::Forms::Label^  label37;
private: System::Windows::Forms::ComboBox^  comboBox2;
private: System::Windows::Forms::Label^  label38;
private: System::Windows::Forms::ComboBox^  Employee_comboBox;
private: System::Windows::Forms::Label^  label39;
private: System::Windows::Forms::ComboBox^  comboBox1;
private: System::Windows::Forms::TextBox^  txtProfCreds;
private: System::Windows::Forms::ToolStripMenuItem^  searchToolStripMenuItem;
private: System::Windows::Forms::StatusStrip^  statusStrip1;
private: System::Windows::Forms::ToolStripStatusLabel^  lblStatus;
private: System::Windows::Forms::Panel^  pnlLogin;
private: System::Windows::Forms::Label^  lblUser;

private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::Label^  label41;
private: System::Windows::Forms::TextBox^  txtQuickFind;
private: System::Windows::Forms::ToolStripMenuItem^  undeleteToolStripMenuItem;
private: System::Windows::Forms::Label^  label40;
private: System::Windows::Forms::Panel^  deletedPanel;
private: System::Windows::Forms::Button^  btnUndelete;
private: System::Windows::Forms::ListBox^  lstDeleted;
private: System::Windows::Forms::ListBox^  lstDeletedId;
private: System::Windows::Forms::Button^  btnDelete;
private: System::Windows::Forms::ToolStripMenuItem^  restoreSessionToolStripMenuItem;
private: System::Windows::Forms::Timer^  tmr;
private: System::Windows::Forms::CheckBox^  chkIsNew;
private: System::Windows::Forms::ToolStripMenuItem^  backupToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  backupToolStripMenuItem1;
private: System::Windows::Forms::ToolStripMenuItem^  restoreToolStripMenuItem;
private: System::Windows::Forms::Panel^  pnlELogin;
private: System::Windows::Forms::Button^  btnSaveUP;
private: System::Windows::Forms::TextBox^  txtNewPassword;
private: System::Windows::Forms::Label^  label43;
private: System::Windows::Forms::TextBox^  txtNewUsername;
private: System::Windows::Forms::Label^  label42;
private: System::Windows::Forms::Label^  label44;
private: System::Windows::Forms::PictureBox^  pictureBox1;
private: System::Windows::Forms::ToolStripMenuItem^  matchProjectsToolStripMenuItem;



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
			this->txtUser = (gcnew System::Windows::Forms::TextBox());
			this->txtPass = (gcnew System::Windows::Forms::TextBox());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->txtId = (gcnew System::Windows::Forms::TextBox());
			this->btnView = (gcnew System::Windows::Forms::Button());
			this->txtMobile = (gcnew System::Windows::Forms::TextBox());
			this->txtDob = (gcnew System::Windows::Forms::DateTimePicker());
			this->pnlProf = (gcnew System::Windows::Forms::Panel());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->txtProfCreds = (gcnew System::Windows::Forms::TextBox());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->txtmast = (gcnew System::Windows::Forms::TextBox());
			this->txtphd = (gcnew System::Windows::Forms::TextBox());
			this->txtbach = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->txtProfWebmail = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->txtProfCoursesTaught = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->txtProfProjects = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->QUALIFICATION = (gcnew System::Windows::Forms::Label());
			this->txtProfDept = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->btnShowProfFeedback = (gcnew System::Windows::Forms::Button());
			this->btnGenProfFeedback = (gcnew System::Windows::Forms::Button());
			this->txtNumStudents = (gcnew System::Windows::Forms::TextBox());
			this->txtProfCourse = (gcnew System::Windows::Forms::TextBox());
			this->txtRi = (gcnew System::Windows::Forms::TextBox());
			this->btnAddRi = (gcnew System::Windows::Forms::Button());
			this->btnRemoveRi = (gcnew System::Windows::Forms::Button());
			this->lstProfRi = (gcnew System::Windows::Forms::ListBox());
			this->pnlData = (gcnew System::Windows::Forms::Panel());
			this->pnlELogin = (gcnew System::Windows::Forms::Panel());
			this->btnSaveUP = (gcnew System::Windows::Forms::Button());
			this->txtNewPassword = (gcnew System::Windows::Forms::TextBox());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->txtNewUsername = (gcnew System::Windows::Forms::TextBox());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->lblId = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->txtRole = (gcnew System::Windows::Forms::ComboBox());
			this->pnlStaff = (gcnew System::Windows::Forms::Panel());
			this->txtStaffDepartment = (gcnew System::Windows::Forms::TextBox());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->txtStaffResponsibility = (gcnew System::Windows::Forms::ComboBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->txtStaffLocation = (gcnew System::Windows::Forms::TextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->txtStaffCategory = (gcnew System::Windows::Forms::ComboBox());
			this->btnUpload = (gcnew System::Windows::Forms::Button());
			this->txtTitle = (gcnew System::Windows::Forms::ComboBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->txtNumOfLeaves = (gcnew System::Windows::Forms::TextBox());
			this->txtStartDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->txtSalary = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pbxPicture = (gcnew System::Windows::Forms::PictureBox());
			this->pnlSecurity = (gcnew System::Windows::Forms::Panel());
			this->btnSecSubtract = (gcnew System::Windows::Forms::Button());
			this->btnADD = (gcnew System::Windows::Forms::Button());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->txtEndTime = (gcnew System::Windows::Forms::DateTimePicker());
			this->txtStartTime = (gcnew System::Windows::Forms::DateTimePicker());
			this->txtDay = (gcnew System::Windows::Forms::ComboBox());
			this->lstSecurityTimings = (gcnew System::Windows::Forms::ListBox());
			this->txtPlace = (gcnew System::Windows::Forms::TextBox());
			this->PLACE = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->FileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->addToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->profToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->staffToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->securityToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->searchToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->undeleteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->restoreSessionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->backupToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->backupToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->restoreToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pnlSearch = (gcnew System::Windows::Forms::Panel());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->Day_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->Searchbtn_TimeandDay = (gcnew System::Windows::Forms::Button());
			this->Place_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->SearchforSecurity_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->projects = (gcnew System::Windows::Forms::ComboBox());
			this->webmail = (gcnew System::Windows::Forms::ComboBox());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->Searchby_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->Research_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->Employee_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->pnlLogin = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->lblStatus = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->lblUser = (gcnew System::Windows::Forms::Label());
			this->txtQuickFind = (gcnew System::Windows::Forms::TextBox());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->deletedPanel = (gcnew System::Windows::Forms::Panel());
			this->lstDeletedId = (gcnew System::Windows::Forms::ListBox());
			this->btnUndelete = (gcnew System::Windows::Forms::Button());
			this->lstDeleted = (gcnew System::Windows::Forms::ListBox());
			this->tmr = (gcnew System::Windows::Forms::Timer(this->components));
			this->chkIsNew = (gcnew System::Windows::Forms::CheckBox());
			this->matchProjectsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pnlProf->SuspendLayout();
			this->pnlData->SuspendLayout();
			this->pnlELogin->SuspendLayout();
			this->pnlStaff->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbxPicture))->BeginInit();
			this->pnlSecurity->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->pnlSearch->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->pnlLogin->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->statusStrip1->SuspendLayout();
			this->deletedPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// txtUser
			// 
			this->txtUser->Location = System::Drawing::Point(135, 4);
			this->txtUser->Name = L"txtUser";
			this->txtUser->Size = System::Drawing::Size(100, 20);
			this->txtUser->TabIndex = 0;
			// 
			// txtPass
			// 
			this->txtPass->Location = System::Drawing::Point(135, 30);
			this->txtPass->Name = L"txtPass";
			this->txtPass->PasswordChar = '*';
			this->txtPass->Size = System::Drawing::Size(100, 20);
			this->txtPass->TabIndex = 1;
			// 
			// btnLogin
			// 
			this->btnLogin->Location = System::Drawing::Point(160, 56);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(75, 23);
			this->btnLogin->TabIndex = 2;
			this->btnLogin->Text = L"Login";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &Form1::btnLogin_Click);
			// 
			// txtName
			// 
			this->txtName->Location = System::Drawing::Point(93, 42);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(100, 20);
			this->txtName->TabIndex = 4;
			// 
			// txtId
			// 
			this->txtId->Location = System::Drawing::Point(12, 271);
			this->txtId->Name = L"txtId";
			this->txtId->Size = System::Drawing::Size(100, 20);
			this->txtId->TabIndex = 7;
			this->txtId->Visible = false;
			// 
			// btnView
			// 
			this->btnView->Location = System::Drawing::Point(118, 269);
			this->btnView->Name = L"btnView";
			this->btnView->Size = System::Drawing::Size(75, 23);
			this->btnView->TabIndex = 8;
			this->btnView->Text = L"btnView";
			this->btnView->UseVisualStyleBackColor = true;
			this->btnView->Visible = false;
			this->btnView->Click += gcnew System::EventHandler(this, &Form1::btnView_Click);
			// 
			// txtMobile
			// 
			this->txtMobile->Location = System::Drawing::Point(93, 95);
			this->txtMobile->Name = L"txtMobile";
			this->txtMobile->Size = System::Drawing::Size(100, 20);
			this->txtMobile->TabIndex = 6;
			// 
			// txtDob
			// 
			this->txtDob->Location = System::Drawing::Point(93, 68);
			this->txtDob->Name = L"txtDob";
			this->txtDob->Size = System::Drawing::Size(148, 20);
			this->txtDob->TabIndex = 9;
			// 
			// pnlProf
			// 
			this->pnlProf->Controls->Add(this->label44);
			this->pnlProf->Controls->Add(this->txtProfCreds);
			this->pnlProf->Controls->Add(this->label26);
			this->pnlProf->Controls->Add(this->label25);
			this->pnlProf->Controls->Add(this->label24);
			this->pnlProf->Controls->Add(this->txtmast);
			this->pnlProf->Controls->Add(this->txtphd);
			this->pnlProf->Controls->Add(this->txtbach);
			this->pnlProf->Controls->Add(this->label13);
			this->pnlProf->Controls->Add(this->txtProfWebmail);
			this->pnlProf->Controls->Add(this->label12);
			this->pnlProf->Controls->Add(this->txtProfCoursesTaught);
			this->pnlProf->Controls->Add(this->label11);
			this->pnlProf->Controls->Add(this->txtProfProjects);
			this->pnlProf->Controls->Add(this->label10);
			this->pnlProf->Controls->Add(this->QUALIFICATION);
			this->pnlProf->Controls->Add(this->txtProfDept);
			this->pnlProf->Controls->Add(this->label9);
			this->pnlProf->Controls->Add(this->label8);
			this->pnlProf->Controls->Add(this->btnShowProfFeedback);
			this->pnlProf->Controls->Add(this->btnGenProfFeedback);
			this->pnlProf->Controls->Add(this->txtNumStudents);
			this->pnlProf->Controls->Add(this->txtProfCourse);
			this->pnlProf->Controls->Add(this->txtRi);
			this->pnlProf->Controls->Add(this->btnAddRi);
			this->pnlProf->Controls->Add(this->btnRemoveRi);
			this->pnlProf->Controls->Add(this->lstProfRi);
			this->pnlProf->Location = System::Drawing::Point(276, 16);
			this->pnlProf->Name = L"pnlProf";
			this->pnlProf->Size = System::Drawing::Size(336, 533);
			this->pnlProf->TabIndex = 10;
			this->pnlProf->Visible = false;
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(47, 447);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(104, 13);
			this->label44->TabIndex = 27;
			this->label44->Text = L"Number of Students:";
			// 
			// txtProfCreds
			// 
			this->txtProfCreds->Location = System::Drawing::Point(24, 311);
			this->txtProfCreds->Name = L"txtProfCreds";
			this->txtProfCreds->Size = System::Drawing::Size(100, 20);
			this->txtProfCreds->TabIndex = 17;
			this->txtProfCreds->Visible = false;
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(101, 126);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(43, 13);
			this->label26->TabIndex = 26;
			this->label26->Text = L"BTECH";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(101, 153);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(59, 13);
			this->label25->TabIndex = 25;
			this->label25->Text = L"MASTERS";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(101, 179);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(30, 13);
			this->label24->TabIndex = 24;
			this->label24->Text = L"PHD";
			// 
			// txtmast
			// 
			this->txtmast->Location = System::Drawing::Point(164, 146);
			this->txtmast->Name = L"txtmast";
			this->txtmast->Size = System::Drawing::Size(100, 20);
			this->txtmast->TabIndex = 23;
			// 
			// txtphd
			// 
			this->txtphd->Location = System::Drawing::Point(164, 172);
			this->txtphd->Name = L"txtphd";
			this->txtphd->Size = System::Drawing::Size(100, 20);
			this->txtphd->TabIndex = 22;
			// 
			// txtbach
			// 
			this->txtbach->Location = System::Drawing::Point(164, 119);
			this->txtbach->Name = L"txtbach";
			this->txtbach->Size = System::Drawing::Size(100, 20);
			this->txtbach->TabIndex = 21;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(101, 396);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(57, 13);
			this->label13->TabIndex = 20;
			this->label13->Text = L"WEBMAIL";
			// 
			// txtProfWebmail
			// 
			this->txtProfWebmail->Location = System::Drawing::Point(164, 396);
			this->txtProfWebmail->Name = L"txtProfWebmail";
			this->txtProfWebmail->Size = System::Drawing::Size(167, 20);
			this->txtProfWebmail->TabIndex = 19;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(47, 74);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(107, 13);
			this->label12->TabIndex = 18;
			this->label12->Text = L"COURSES TAUGHT";
			// 
			// txtProfCoursesTaught
			// 
			this->txtProfCoursesTaught->Location = System::Drawing::Point(160, 74);
			this->txtProfCoursesTaught->Name = L"txtProfCoursesTaught";
			this->txtProfCoursesTaught->Size = System::Drawing::Size(171, 20);
			this->txtProfCoursesTaught->TabIndex = 17;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(91, 350);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(63, 13);
			this->label11->TabIndex = 16;
			this->label11->Text = L"PROJECTS";
			// 
			// txtProfProjects
			// 
			this->txtProfProjects->Location = System::Drawing::Point(164, 348);
			this->txtProfProjects->Multiline = true;
			this->txtProfProjects->Name = L"txtProfProjects";
			this->txtProfProjects->Size = System::Drawing::Size(167, 42);
			this->txtProfProjects->TabIndex = 15;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(28, 210);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(130, 13);
			this->label10->TabIndex = 14;
			this->label10->Text = L"RESEARCH INTERESTS";
			// 
			// QUALIFICATION
			// 
			this->QUALIFICATION->AutoSize = true;
			this->QUALIFICATION->Location = System::Drawing::Point(66, 100);
			this->QUALIFICATION->Name = L"QUALIFICATION";
			this->QUALIFICATION->Size = System::Drawing::Size(88, 13);
			this->QUALIFICATION->TabIndex = 13;
			this->QUALIFICATION->Text = L"QUALIFICATION";
			// 
			// txtProfDept
			// 
			this->txtProfDept->FormattingEnabled = true;
			this->txtProfDept->Items->AddRange(gcnew cli::array< System::Object^  >(11) {L"CSE", L"ECE", L"MECHANICAL", L"CIVIL", L"BIOTECH", 
				L"DESIGN", L"CHEMICAL", L"EEE", L"CST", L"EP", L"MNC"});
			this->txtProfDept->Location = System::Drawing::Point(160, 17);
			this->txtProfDept->Name = L"txtProfDept";
			this->txtProfDept->Size = System::Drawing::Size(171, 21);
			this->txtProfDept->TabIndex = 12;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(41, 51);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(113, 13);
			this->label9->TabIndex = 11;
			this->label9->Text = L"COURSE_TEACHING";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(72, 25);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(82, 13);
			this->label8->TabIndex = 10;
			this->label8->Text = L"DEPARTMENT";
			// 
			// btnShowProfFeedback
			// 
			this->btnShowProfFeedback->Location = System::Drawing::Point(231, 471);
			this->btnShowProfFeedback->Name = L"btnShowProfFeedback";
			this->btnShowProfFeedback->Size = System::Drawing::Size(100, 23);
			this->btnShowProfFeedback->TabIndex = 9;
			this->btnShowProfFeedback->Text = L"Show Feedback";
			this->btnShowProfFeedback->UseVisualStyleBackColor = true;
			this->btnShowProfFeedback->Click += gcnew System::EventHandler(this, &Form1::btnShowProfFeedback_Click);
			// 
			// btnGenProfFeedback
			// 
			this->btnGenProfFeedback->Location = System::Drawing::Point(231, 442);
			this->btnGenProfFeedback->Name = L"btnGenProfFeedback";
			this->btnGenProfFeedback->Size = System::Drawing::Size(100, 23);
			this->btnGenProfFeedback->TabIndex = 8;
			this->btnGenProfFeedback->Text = L"Generate Feedback";
			this->btnGenProfFeedback->UseVisualStyleBackColor = true;
			this->btnGenProfFeedback->Click += gcnew System::EventHandler(this, &Form1::btnGenProfFeedback_Click);
			// 
			// txtNumStudents
			// 
			this->txtNumStudents->Location = System::Drawing::Point(164, 444);
			this->txtNumStudents->Name = L"txtNumStudents";
			this->txtNumStudents->Size = System::Drawing::Size(61, 20);
			this->txtNumStudents->TabIndex = 7;
			// 
			// txtProfCourse
			// 
			this->txtProfCourse->Location = System::Drawing::Point(160, 44);
			this->txtProfCourse->Name = L"txtProfCourse";
			this->txtProfCourse->Size = System::Drawing::Size(171, 20);
			this->txtProfCourse->TabIndex = 6;
			// 
			// txtRi
			// 
			this->txtRi->Location = System::Drawing::Point(191, 311);
			this->txtRi->Name = L"txtRi";
			this->txtRi->Size = System::Drawing::Size(113, 20);
			this->txtRi->TabIndex = 5;
			// 
			// btnAddRi
			// 
			this->btnAddRi->Location = System::Drawing::Point(308, 309);
			this->btnAddRi->Name = L"btnAddRi";
			this->btnAddRi->Size = System::Drawing::Size(23, 23);
			this->btnAddRi->TabIndex = 4;
			this->btnAddRi->Text = L"+";
			this->btnAddRi->UseVisualStyleBackColor = true;
			this->btnAddRi->Click += gcnew System::EventHandler(this, &Form1::btnAddRi_Click);
			// 
			// btnRemoveRi
			// 
			this->btnRemoveRi->Location = System::Drawing::Point(162, 309);
			this->btnRemoveRi->Name = L"btnRemoveRi";
			this->btnRemoveRi->Size = System::Drawing::Size(23, 23);
			this->btnRemoveRi->TabIndex = 3;
			this->btnRemoveRi->Text = L"-";
			this->btnRemoveRi->UseVisualStyleBackColor = true;
			this->btnRemoveRi->Click += gcnew System::EventHandler(this, &Form1::btnRemoveRi_Click);
			// 
			// lstProfRi
			// 
			this->lstProfRi->FormattingEnabled = true;
			this->lstProfRi->Location = System::Drawing::Point(162, 210);
			this->lstProfRi->Name = L"lstProfRi";
			this->lstProfRi->Size = System::Drawing::Size(171, 95);
			this->lstProfRi->TabIndex = 2;
			// 
			// pnlData
			// 
			this->pnlData->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlData->Controls->Add(this->pnlELogin);
			this->pnlData->Controls->Add(this->btnDelete);
			this->pnlData->Controls->Add(this->btnSave);
			this->pnlData->Controls->Add(this->lblId);
			this->pnlData->Controls->Add(this->label23);
			this->pnlData->Controls->Add(this->txtRole);
			this->pnlData->Controls->Add(this->pnlStaff);
			this->pnlData->Controls->Add(this->btnUpload);
			this->pnlData->Controls->Add(this->txtTitle);
			this->pnlData->Controls->Add(this->label16);
			this->pnlData->Controls->Add(this->label15);
			this->pnlData->Controls->Add(this->txtNumOfLeaves);
			this->pnlData->Controls->Add(this->txtStartDate);
			this->pnlData->Controls->Add(this->label14);
			this->pnlData->Controls->Add(this->txtSalary);
			this->pnlData->Controls->Add(this->label5);
			this->pnlData->Controls->Add(this->label4);
			this->pnlData->Controls->Add(this->label3);
			this->pnlData->Controls->Add(this->label2);
			this->pnlData->Controls->Add(this->label1);
			this->pnlData->Controls->Add(this->pbxPicture);
			this->pnlData->Controls->Add(this->pnlProf);
			this->pnlData->Controls->Add(this->txtName);
			this->pnlData->Controls->Add(this->txtDob);
			this->pnlData->Controls->Add(this->txtMobile);
			this->pnlData->Controls->Add(this->pnlSecurity);
			this->pnlData->Location = System::Drawing::Point(199, 33);
			this->pnlData->Name = L"pnlData";
			this->pnlData->Size = System::Drawing::Size(627, 562);
			this->pnlData->TabIndex = 11;
			// 
			// pnlELogin
			// 
			this->pnlELogin->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlELogin->Controls->Add(this->btnSaveUP);
			this->pnlELogin->Controls->Add(this->txtNewPassword);
			this->pnlELogin->Controls->Add(this->label43);
			this->pnlELogin->Controls->Add(this->txtNewUsername);
			this->pnlELogin->Controls->Add(this->label42);
			this->pnlELogin->Location = System::Drawing::Point(9, 437);
			this->pnlELogin->Name = L"pnlELogin";
			this->pnlELogin->Size = System::Drawing::Size(116, 114);
			this->pnlELogin->TabIndex = 32;
			this->pnlELogin->Visible = false;
			// 
			// btnSaveUP
			// 
			this->btnSaveUP->Location = System::Drawing::Point(7, 87);
			this->btnSaveUP->Name = L"btnSaveUP";
			this->btnSaveUP->Size = System::Drawing::Size(102, 23);
			this->btnSaveUP->TabIndex = 4;
			this->btnSaveUP->Text = L"Save";
			this->btnSaveUP->UseVisualStyleBackColor = true;
			this->btnSaveUP->Click += gcnew System::EventHandler(this, &Form1::btnSaveUP_Click);
			// 
			// txtNewPassword
			// 
			this->txtNewPassword->Location = System::Drawing::Point(9, 61);
			this->txtNewPassword->Name = L"txtNewPassword";
			this->txtNewPassword->Size = System::Drawing::Size(100, 20);
			this->txtNewPassword->TabIndex = 3;
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Location = System::Drawing::Point(6, 45);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(80, 13);
			this->label43->TabIndex = 2;
			this->label43->Text = L"New password:";
			// 
			// txtNewUsername
			// 
			this->txtNewUsername->Location = System::Drawing::Point(7, 22);
			this->txtNewUsername->Name = L"txtNewUsername";
			this->txtNewUsername->Size = System::Drawing::Size(100, 20);
			this->txtNewUsername->TabIndex = 1;
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Location = System::Drawing::Point(4, 6);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(81, 13);
			this->label42->TabIndex = 0;
			this->label42->Text = L"New username:";
			// 
			// btnDelete
			// 
			this->btnDelete->Location = System::Drawing::Point(99, 356);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(75, 23);
			this->btnDelete->TabIndex = 31;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &Form1::btnDelete_Click);
			// 
			// btnSave
			// 
			this->btnSave->Location = System::Drawing::Point(18, 356);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(75, 23);
			this->btnSave->TabIndex = 30;
			this->btnSave->Text = L"Save";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &Form1::btnSave_Click);
			// 
			// lblId
			// 
			this->lblId->AutoSize = true;
			this->lblId->Location = System::Drawing::Point(42, 392);
			this->lblId->Name = L"lblId";
			this->lblId->Size = System::Drawing::Size(16, 13);
			this->lblId->TabIndex = 29;
			this->lblId->Text = L"-1";
			this->lblId->Visible = false;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(15, 319);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(36, 13);
			this->label23->TabIndex = 28;
			this->label23->Text = L"ROLE";
			// 
			// txtRole
			// 
			this->txtRole->Enabled = false;
			this->txtRole->FormattingEnabled = true;
			this->txtRole->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"prof", L"security", L"staff"});
			this->txtRole->Location = System::Drawing::Point(78, 314);
			this->txtRole->Name = L"txtRole";
			this->txtRole->Size = System::Drawing::Size(99, 21);
			this->txtRole->TabIndex = 27;
			// 
			// pnlStaff
			// 
			this->pnlStaff->Controls->Add(this->txtStaffDepartment);
			this->pnlStaff->Controls->Add(this->label27);
			this->pnlStaff->Controls->Add(this->txtStaffResponsibility);
			this->pnlStaff->Controls->Add(this->label22);
			this->pnlStaff->Controls->Add(this->txtStaffLocation);
			this->pnlStaff->Controls->Add(this->label21);
			this->pnlStaff->Controls->Add(this->label20);
			this->pnlStaff->Controls->Add(this->txtStaffCategory);
			this->pnlStaff->Location = System::Drawing::Point(277, 16);
			this->pnlStaff->Name = L"pnlStaff";
			this->pnlStaff->Size = System::Drawing::Size(229, 146);
			this->pnlStaff->TabIndex = 26;
			this->pnlStaff->Visible = false;
			// 
			// txtStaffDepartment
			// 
			this->txtStaffDepartment->Location = System::Drawing::Point(105, 106);
			this->txtStaffDepartment->Name = L"txtStaffDepartment";
			this->txtStaffDepartment->Size = System::Drawing::Size(100, 20);
			this->txtStaffDepartment->TabIndex = 7;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(3, 113);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(82, 13);
			this->label27->TabIndex = 6;
			this->label27->Text = L"DEPARTMENT";
			// 
			// txtStaffResponsibility
			// 
			this->txtStaffResponsibility->FormattingEnabled = true;
			this->txtStaffResponsibility->Items->AddRange(gcnew cli::array< System::Object^  >(10) {L"SCIENTIFIC OFFICER", L"JUNIOR TECHNICIAN", 
				L"TECHNICAL SUPRITENDANT", L"JUNIOR ATTENDENT", L"ATTENDENT", L"ACCOUNTS SECTION", L"MEDIA SECTION", L"FINANCE SECTION", L"MAINTANENCE SECTION", 
				L"STUDENT AFFAIRS SECTION"});
			this->txtStaffResponsibility->Location = System::Drawing::Point(105, 79);
			this->txtStaffResponsibility->Name = L"txtStaffResponsibility";
			this->txtStaffResponsibility->Size = System::Drawing::Size(121, 21);
			this->txtStaffResponsibility->TabIndex = 5;
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(3, 79);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(95, 13);
			this->label22->TabIndex = 4;
			this->label22->Text = L"RESPONSIBILITY";
			// 
			// txtStaffLocation
			// 
			this->txtStaffLocation->Location = System::Drawing::Point(105, 42);
			this->txtStaffLocation->Name = L"txtStaffLocation";
			this->txtStaffLocation->Size = System::Drawing::Size(100, 20);
			this->txtStaffLocation->TabIndex = 3;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(3, 49);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(61, 13);
			this->label21->TabIndex = 2;
			this->label21->Text = L"LOCATION";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(3, 20);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(66, 13);
			this->label20->TabIndex = 1;
			this->label20->Text = L"CATEGORY";
			// 
			// txtStaffCategory
			// 
			this->txtStaffCategory->FormattingEnabled = true;
			this->txtStaffCategory->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"OFFICE STAFF", L"TECHNICAL STAFF"});
			this->txtStaffCategory->Location = System::Drawing::Point(105, 12);
			this->txtStaffCategory->Name = L"txtStaffCategory";
			this->txtStaffCategory->Size = System::Drawing::Size(121, 21);
			this->txtStaffCategory->TabIndex = 0;
			// 
			// btnUpload
			// 
			this->btnUpload->Location = System::Drawing::Point(209, 208);
			this->btnUpload->Name = L"btnUpload";
			this->btnUpload->Size = System::Drawing::Size(61, 31);
			this->btnUpload->TabIndex = 25;
			this->btnUpload->Text = L"UPLOAD";
			this->btnUpload->UseVisualStyleBackColor = true;
			this->btnUpload->Click += gcnew System::EventHandler(this, &Form1::btnUpload_Click);
			// 
			// txtTitle
			// 
			this->txtTitle->FormattingEnabled = true;
			this->txtTitle->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Mr.", L"Mrs.", L"Miss."});
			this->txtTitle->Location = System::Drawing::Point(94, 16);
			this->txtTitle->Name = L"txtTitle";
			this->txtTitle->Size = System::Drawing::Size(99, 21);
			this->txtTitle->TabIndex = 24;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(28, 172);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(48, 13);
			this->label16->TabIndex = 23;
			this->label16->Text = L"LEAVES";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(3, 149);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(75, 13);
			this->label15->TabIndex = 22;
			this->label15->Text = L"START DATE";
			// 
			// txtNumOfLeaves
			// 
			this->txtNumOfLeaves->Location = System::Drawing::Point(93, 172);
			this->txtNumOfLeaves->Name = L"txtNumOfLeaves";
			this->txtNumOfLeaves->Size = System::Drawing::Size(100, 20);
			this->txtNumOfLeaves->TabIndex = 21;
			// 
			// txtStartDate
			// 
			this->txtStartDate->Location = System::Drawing::Point(94, 149);
			this->txtStartDate->Name = L"txtStartDate";
			this->txtStartDate->Size = System::Drawing::Size(147, 20);
			this->txtStartDate->TabIndex = 20;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(20, 122);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(49, 13);
			this->label14->TabIndex = 19;
			this->label14->Text = L"SALARY";
			// 
			// txtSalary
			// 
			this->txtSalary->Location = System::Drawing::Point(93, 119);
			this->txtSalary->Name = L"txtSalary";
			this->txtSalary->Size = System::Drawing::Size(100, 20);
			this->txtSalary->TabIndex = 18;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(15, 208);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(54, 13);
			this->label5->TabIndex = 16;
			this->label5->Text = L"PICTURE";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(28, 49);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(38, 13);
			this->label4->TabIndex = 15;
			this->label4->Text = L"NAME";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(39, 74);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(30, 13);
			this->label3->TabIndex = 14;
			this->label3->Text = L"DOB";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(22, 98);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 13);
			this->label2->TabIndex = 13;
			this->label2->Text = L"MOBILE";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(32, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 13);
			this->label1->TabIndex = 12;
			this->label1->Text = L"TITLE";
			// 
			// pbxPicture
			// 
			this->pbxPicture->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pbxPicture->Location = System::Drawing::Point(73, 211);
			this->pbxPicture->Name = L"pbxPicture";
			this->pbxPicture->Size = System::Drawing::Size(120, 95);
			this->pbxPicture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbxPicture->TabIndex = 11;
			this->pbxPicture->TabStop = false;
			this->pbxPicture->Click += gcnew System::EventHandler(this, &Form1::pbxPicture_Click);
			// 
			// pnlSecurity
			// 
			this->pnlSecurity->Controls->Add(this->btnSecSubtract);
			this->pnlSecurity->Controls->Add(this->btnADD);
			this->pnlSecurity->Controls->Add(this->label19);
			this->pnlSecurity->Controls->Add(this->label18);
			this->pnlSecurity->Controls->Add(this->label17);
			this->pnlSecurity->Controls->Add(this->txtEndTime);
			this->pnlSecurity->Controls->Add(this->txtStartTime);
			this->pnlSecurity->Controls->Add(this->txtDay);
			this->pnlSecurity->Controls->Add(this->lstSecurityTimings);
			this->pnlSecurity->Controls->Add(this->txtPlace);
			this->pnlSecurity->Controls->Add(this->PLACE);
			this->pnlSecurity->Location = System::Drawing::Point(276, 16);
			this->pnlSecurity->Name = L"pnlSecurity";
			this->pnlSecurity->Size = System::Drawing::Size(336, 279);
			this->pnlSecurity->TabIndex = 17;
			this->pnlSecurity->Visible = false;
			// 
			// btnSecSubtract
			// 
			this->btnSecSubtract->Location = System::Drawing::Point(213, 107);
			this->btnSecSubtract->Name = L"btnSecSubtract";
			this->btnSecSubtract->Size = System::Drawing::Size(38, 24);
			this->btnSecSubtract->TabIndex = 10;
			this->btnSecSubtract->Text = L"-";
			this->btnSecSubtract->UseVisualStyleBackColor = true;
			this->btnSecSubtract->Click += gcnew System::EventHandler(this, &Form1::btnSecSubtract_Click);
			// 
			// btnADD
			// 
			this->btnADD->Location = System::Drawing::Point(213, 241);
			this->btnADD->Name = L"btnADD";
			this->btnADD->Size = System::Drawing::Size(38, 23);
			this->btnADD->TabIndex = 9;
			this->btnADD->Text = L"+";
			this->btnADD->UseVisualStyleBackColor = true;
			this->btnADD->Click += gcnew System::EventHandler(this, &Form1::btnADD_Click);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(11, 223);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(59, 13);
			this->label19->TabIndex = 8;
			this->label19->Text = L"END TIME";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(11, 198);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(72, 13);
			this->label18->TabIndex = 7;
			this->label18->Text = L"START TIME";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(11, 173);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(29, 13);
			this->label17->TabIndex = 6;
			this->label17->Text = L"DAY";
			// 
			// txtEndTime
			// 
			this->txtEndTime->Format = System::Windows::Forms::DateTimePickerFormat::Time;
			this->txtEndTime->Location = System::Drawing::Point(119, 217);
			this->txtEndTime->Name = L"txtEndTime";
			this->txtEndTime->Size = System::Drawing::Size(132, 20);
			this->txtEndTime->TabIndex = 5;
			// 
			// txtStartTime
			// 
			this->txtStartTime->Format = System::Windows::Forms::DateTimePickerFormat::Time;
			this->txtStartTime->Location = System::Drawing::Point(119, 192);
			this->txtStartTime->Name = L"txtStartTime";
			this->txtStartTime->Size = System::Drawing::Size(132, 20);
			this->txtStartTime->TabIndex = 4;
			// 
			// txtDay
			// 
			this->txtDay->FormattingEnabled = true;
			this->txtDay->Items->AddRange(gcnew cli::array< System::Object^  >(7) {L"Sunday", L"Monday", L"Tuesday", L"Wednesday", L"Thursday", 
				L"Friday", L"Saturday"});
			this->txtDay->Location = System::Drawing::Point(119, 167);
			this->txtDay->Name = L"txtDay";
			this->txtDay->Size = System::Drawing::Size(132, 21);
			this->txtDay->TabIndex = 3;
			// 
			// lstSecurityTimings
			// 
			this->lstSecurityTimings->FormattingEnabled = true;
			this->lstSecurityTimings->Location = System::Drawing::Point(12, 8);
			this->lstSecurityTimings->Name = L"lstSecurityTimings";
			this->lstSecurityTimings->Size = System::Drawing::Size(239, 95);
			this->lstSecurityTimings->TabIndex = 2;
			// 
			// txtPlace
			// 
			this->txtPlace->Location = System::Drawing::Point(119, 141);
			this->txtPlace->Name = L"txtPlace";
			this->txtPlace->Size = System::Drawing::Size(132, 20);
			this->txtPlace->TabIndex = 1;
			// 
			// PLACE
			// 
			this->PLACE->AutoSize = true;
			this->PLACE->Location = System::Drawing::Point(11, 148);
			this->PLACE->Name = L"PLACE";
			this->PLACE->Size = System::Drawing::Size(41, 13);
			this->PLACE->TabIndex = 0;
			this->PLACE->Text = L"PLACE";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(61, 7);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(68, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"USERNAME";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(61, 33);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(70, 13);
			this->label7->TabIndex = 13;
			this->label7->Text = L"PASSWORD";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->addToolStripMenuItem, 
				this->searchToolStripMenuItem, this->undeleteToolStripMenuItem, this->restoreSessionToolStripMenuItem, this->backupToolStripMenuItem, 
				this->matchProjectsToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->menuStrip1->Size = System::Drawing::Size(841, 24);
			this->menuStrip1->TabIndex = 15;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// addToolStripMenuItem
			// 
			this->addToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->profToolStripMenuItem, 
				this->staffToolStripMenuItem, this->securityToolStripMenuItem});
			this->addToolStripMenuItem->Name = L"addToolStripMenuItem";
			this->addToolStripMenuItem->Size = System::Drawing::Size(41, 20);
			this->addToolStripMenuItem->Text = L"Add";
			this->addToolStripMenuItem->Visible = false;
			// 
			// profToolStripMenuItem
			// 
			this->profToolStripMenuItem->Name = L"profToolStripMenuItem";
			this->profToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->profToolStripMenuItem->Text = L"Prof";
			this->profToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::profToolStripMenuItem_Click);
			// 
			// staffToolStripMenuItem
			// 
			this->staffToolStripMenuItem->Name = L"staffToolStripMenuItem";
			this->staffToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->staffToolStripMenuItem->Text = L"Staff";
			this->staffToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::staffToolStripMenuItem_Click);
			// 
			// securityToolStripMenuItem
			// 
			this->securityToolStripMenuItem->Name = L"securityToolStripMenuItem";
			this->securityToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->securityToolStripMenuItem->Text = L"Security";
			this->securityToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::securityToolStripMenuItem_Click);
			// 
			// searchToolStripMenuItem
			// 
			this->searchToolStripMenuItem->Name = L"searchToolStripMenuItem";
			this->searchToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->searchToolStripMenuItem->Text = L"Search";
			this->searchToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::searchToolStripMenuItem_Click);
			// 
			// undeleteToolStripMenuItem
			// 
			this->undeleteToolStripMenuItem->Name = L"undeleteToolStripMenuItem";
			this->undeleteToolStripMenuItem->Size = System::Drawing::Size(66, 20);
			this->undeleteToolStripMenuItem->Text = L"Undelete";
			this->undeleteToolStripMenuItem->Visible = false;
			this->undeleteToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::undeleteToolStripMenuItem_Click);
			// 
			// restoreSessionToolStripMenuItem
			// 
			this->restoreSessionToolStripMenuItem->Name = L"restoreSessionToolStripMenuItem";
			this->restoreSessionToolStripMenuItem->Size = System::Drawing::Size(100, 20);
			this->restoreSessionToolStripMenuItem->Text = L"Restore Session";
			this->restoreSessionToolStripMenuItem->Visible = false;
			this->restoreSessionToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::restoreSessionToolStripMenuItem_Click);
			// 
			// backupToolStripMenuItem
			// 
			this->backupToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->backupToolStripMenuItem1, 
				this->restoreToolStripMenuItem});
			this->backupToolStripMenuItem->Name = L"backupToolStripMenuItem";
			this->backupToolStripMenuItem->Size = System::Drawing::Size(58, 20);
			this->backupToolStripMenuItem->Text = L"Backup";
			this->backupToolStripMenuItem->Visible = false;
			// 
			// backupToolStripMenuItem1
			// 
			this->backupToolStripMenuItem1->Name = L"backupToolStripMenuItem1";
			this->backupToolStripMenuItem1->Size = System::Drawing::Size(113, 22);
			this->backupToolStripMenuItem1->Text = L"Backup";
			this->backupToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::backupToolStripMenuItem1_Click);
			// 
			// restoreToolStripMenuItem
			// 
			this->restoreToolStripMenuItem->Name = L"restoreToolStripMenuItem";
			this->restoreToolStripMenuItem->Size = System::Drawing::Size(113, 22);
			this->restoreToolStripMenuItem->Text = L"Restore";
			this->restoreToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::restoreToolStripMenuItem_Click);
			// 
			// pnlSearch
			// 
			this->pnlSearch->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlSearch->Controls->Add(this->groupBox2);
			this->pnlSearch->Controls->Add(this->groupBox1);
			this->pnlSearch->Controls->Add(this->label38);
			this->pnlSearch->Controls->Add(this->Employee_comboBox);
			this->pnlSearch->Controls->Add(this->label39);
			this->pnlSearch->Controls->Add(this->comboBox1);
			this->pnlSearch->Location = System::Drawing::Point(56, 27);
			this->pnlSearch->Name = L"pnlSearch";
			this->pnlSearch->Size = System::Drawing::Size(503, 312);
			this->pnlSearch->TabIndex = 16;
			this->pnlSearch->Visible = false;
			this->pnlSearch->MouseLeave += gcnew System::EventHandler(this, &Form1::pnlSearch_MouseLeave);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->groupBox3);
			this->groupBox2->Controls->Add(this->Place_comboBox);
			this->groupBox2->Controls->Add(this->label31);
			this->groupBox2->Controls->Add(this->label32);
			this->groupBox2->Controls->Add(this->SearchforSecurity_comboBox);
			this->groupBox2->Location = System::Drawing::Point(248, 50);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(236, 214);
			this->groupBox2->TabIndex = 35;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Security";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label28);
			this->groupBox3->Controls->Add(this->Day_comboBox);
			this->groupBox3->Controls->Add(this->label29);
			this->groupBox3->Controls->Add(this->label30);
			this->groupBox3->Controls->Add(this->dateTimePicker2);
			this->groupBox3->Controls->Add(this->dateTimePicker1);
			this->groupBox3->Controls->Add(this->Searchbtn_TimeandDay);
			this->groupBox3->Location = System::Drawing::Point(1, 84);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(229, 100);
			this->groupBox3->TabIndex = 36;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Time and Day";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(5, 76);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(26, 13);
			this->label28->TabIndex = 42;
			this->label28->Text = L"Day";
			// 
			// Day_comboBox
			// 
			this->Day_comboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->Day_comboBox->FormattingEnabled = true;
			this->Day_comboBox->Location = System::Drawing::Point(37, 73);
			this->Day_comboBox->Name = L"Day_comboBox";
			this->Day_comboBox->Size = System::Drawing::Size(111, 21);
			this->Day_comboBox->TabIndex = 41;
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(123, 16);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(73, 13);
			this->label29->TabIndex = 40;
			this->label29->Text = L"End Time Slot";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(6, 16);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(76, 13);
			this->label30->TabIndex = 39;
			this->label30->Text = L"Start Time Slot";
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Format = System::Windows::Forms::DateTimePickerFormat::Time;
			this->dateTimePicker2->Location = System::Drawing::Point(126, 36);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(97, 20);
			this->dateTimePicker2->TabIndex = 38;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Time;
			this->dateTimePicker1->Location = System::Drawing::Point(8, 36);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(100, 20);
			this->dateTimePicker1->TabIndex = 37;
			// 
			// Searchbtn_TimeandDay
			// 
			this->Searchbtn_TimeandDay->Location = System::Drawing::Point(164, 68);
			this->Searchbtn_TimeandDay->Name = L"Searchbtn_TimeandDay";
			this->Searchbtn_TimeandDay->Size = System::Drawing::Size(59, 23);
			this->Searchbtn_TimeandDay->TabIndex = 36;
			this->Searchbtn_TimeandDay->Text = L"Search";
			this->Searchbtn_TimeandDay->UseVisualStyleBackColor = true;
			this->Searchbtn_TimeandDay->Click += gcnew System::EventHandler(this, &Form1::Searchbtn_TimeandDay_Click);
			// 
			// Place_comboBox
			// 
			this->Place_comboBox->FormattingEnabled = true;
			this->Place_comboBox->Location = System::Drawing::Point(68, 55);
			this->Place_comboBox->Name = L"Place_comboBox";
			this->Place_comboBox->Size = System::Drawing::Size(121, 21);
			this->Place_comboBox->TabIndex = 30;
			this->Place_comboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::Place_comboBox_SelectedIndexChanged);
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(6, 29);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(56, 13);
			this->label31->TabIndex = 29;
			this->label31->Text = L"Search By";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(7, 57);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(34, 13);
			this->label32->TabIndex = 28;
			this->label32->Text = L"Place";
			// 
			// SearchforSecurity_comboBox
			// 
			this->SearchforSecurity_comboBox->FormattingEnabled = true;
			this->SearchforSecurity_comboBox->Location = System::Drawing::Point(68, 26);
			this->SearchforSecurity_comboBox->Name = L"SearchforSecurity_comboBox";
			this->SearchforSecurity_comboBox->Size = System::Drawing::Size(121, 21);
			this->SearchforSecurity_comboBox->TabIndex = 26;
			this->SearchforSecurity_comboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::SearchforSecurity_comboBox_SelectedIndexChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->label41);
			this->groupBox1->Controls->Add(this->projects);
			this->groupBox1->Controls->Add(this->webmail);
			this->groupBox1->Controls->Add(this->label33);
			this->groupBox1->Controls->Add(this->label34);
			this->groupBox1->Controls->Add(this->label35);
			this->groupBox1->Controls->Add(this->Searchby_comboBox);
			this->groupBox1->Controls->Add(this->label36);
			this->groupBox1->Controls->Add(this->Research_comboBox);
			this->groupBox1->Controls->Add(this->label37);
			this->groupBox1->Controls->Add(this->comboBox2);
			this->groupBox1->Location = System::Drawing::Point(21, 50);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(215, 214);
			this->groupBox1->TabIndex = 33;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Professor";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(164, 89);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(27, 23);
			this->button1->TabIndex = 36;
			this->button1->Text = L"go";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Location = System::Drawing::Point(13, 118);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(0, 13);
			this->label41->TabIndex = 38;
			// 
			// projects
			// 
			this->projects->FormattingEnabled = true;
			this->projects->Location = System::Drawing::Point(66, 179);
			this->projects->Name = L"projects";
			this->projects->Size = System::Drawing::Size(121, 21);
			this->projects->TabIndex = 27;
			this->projects->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::projects_SelectedIndexChanged);
			// 
			// webmail
			// 
			this->webmail->FormattingEnabled = true;
			this->webmail->Location = System::Drawing::Point(66, 144);
			this->webmail->Name = L"webmail";
			this->webmail->Size = System::Drawing::Size(122, 21);
			this->webmail->TabIndex = 26;
			this->webmail->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::webmail_SelectedIndexChanged);
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(6, 184);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(45, 13);
			this->label33->TabIndex = 25;
			this->label33->Text = L"Projects";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(6, 148);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(48, 13);
			this->label34->TabIndex = 24;
			this->label34->Text = L"Webmail";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(6, 23);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(55, 13);
			this->label35->TabIndex = 23;
			this->label35->Text = L"Search by";
			// 
			// Searchby_comboBox
			// 
			this->Searchby_comboBox->FormattingEnabled = true;
			this->Searchby_comboBox->Location = System::Drawing::Point(66, 18);
			this->Searchby_comboBox->Name = L"Searchby_comboBox";
			this->Searchby_comboBox->Size = System::Drawing::Size(121, 21);
			this->Searchby_comboBox->TabIndex = 22;
			this->Searchby_comboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::Searchby_comboBox_SelectedIndexChanged);
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(6, 92);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(53, 13);
			this->label36->TabIndex = 21;
			this->label36->Text = L"Research";
			// 
			// Research_comboBox
			// 
			this->Research_comboBox->FormattingEnabled = true;
			this->Research_comboBox->Location = System::Drawing::Point(66, 89);
			this->Research_comboBox->Name = L"Research_comboBox";
			this->Research_comboBox->Size = System::Drawing::Size(92, 21);
			this->Research_comboBox->TabIndex = 20;
			this->Research_comboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::Research_comboBox_SelectedIndexChanged);
			this->Research_comboBox->SelectedValueChanged += gcnew System::EventHandler(this, &Form1::Research_comboBox_SelectedValueChanged);
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(6, 55);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(30, 13);
			this->label37->TabIndex = 17;
			this->label37->Text = L"Dept";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(66, 54);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 15;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox2_SelectedIndexChanged);
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(18, 23);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(53, 13);
			this->label38->TabIndex = 34;
			this->label38->Text = L"Employee";
			// 
			// Employee_comboBox
			// 
			this->Employee_comboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->Employee_comboBox->FormattingEnabled = true;
			this->Employee_comboBox->Location = System::Drawing::Point(87, 23);
			this->Employee_comboBox->Name = L"Employee_comboBox";
			this->Employee_comboBox->Size = System::Drawing::Size(121, 21);
			this->Employee_comboBox->TabIndex = 32;
			this->Employee_comboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::Employee_comboBox_SelectedIndexChanged);
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(156, 280);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(42, 13);
			this->label39->TabIndex = 31;
			this->label39->Text = L"Results";
			// 
			// comboBox1
			// 
			this->comboBox1->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->comboBox1->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(213, 277);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 30;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// pnlLogin
			// 
			this->pnlLogin->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlLogin->Controls->Add(this->pictureBox1);
			this->pnlLogin->Controls->Add(this->label6);
			this->pnlLogin->Controls->Add(this->txtUser);
			this->pnlLogin->Controls->Add(this->txtPass);
			this->pnlLogin->Controls->Add(this->label7);
			this->pnlLogin->Controls->Add(this->btnLogin);
			this->pnlLogin->Location = System::Drawing::Point(280, 262);
			this->pnlLogin->Name = L"pnlLogin";
			this->pnlLogin->Size = System::Drawing::Size(246, 87);
			this->pnlLogin->TabIndex = 18;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 7);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(44, 43);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 14;
			this->pictureBox1->TabStop = false;
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->lblStatus});
			this->statusStrip1->Location = System::Drawing::Point(0, 607);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->statusStrip1->Size = System::Drawing::Size(841, 22);
			this->statusStrip1->TabIndex = 17;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// lblStatus
			// 
			this->lblStatus->Name = L"lblStatus";
			this->lblStatus->Size = System::Drawing::Size(16, 17);
			this->lblStatus->Text = L"...";
			// 
			// lblUser
			// 
			this->lblUser->AutoSize = true;
			this->lblUser->Location = System::Drawing::Point(15, 33);
			this->lblUser->Name = L"lblUser";
			this->lblUser->Size = System::Drawing::Size(81, 13);
			this->lblUser->TabIndex = 19;
			this->lblUser->Text = L"Welcome guest";
			this->lblUser->Visible = false;
			// 
			// txtQuickFind
			// 
			this->txtQuickFind->Location = System::Drawing::Point(12, 558);
			this->txtQuickFind->Name = L"txtQuickFind";
			this->txtQuickFind->Size = System::Drawing::Size(147, 20);
			this->txtQuickFind->TabIndex = 20;
			this->txtQuickFind->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::txtQuickFind_KeyPress);
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(9, 542);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(61, 13);
			this->label40->TabIndex = 21;
			this->label40->Text = L"Quick Find:";
			// 
			// deletedPanel
			// 
			this->deletedPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->deletedPanel->Controls->Add(this->lstDeletedId);
			this->deletedPanel->Controls->Add(this->btnUndelete);
			this->deletedPanel->Controls->Add(this->lstDeleted);
			this->deletedPanel->Location = System::Drawing::Point(110, 28);
			this->deletedPanel->Name = L"deletedPanel";
			this->deletedPanel->Size = System::Drawing::Size(156, 172);
			this->deletedPanel->TabIndex = 22;
			this->deletedPanel->Visible = false;
			this->deletedPanel->MouseLeave += gcnew System::EventHandler(this, &Form1::deletedPanel_MouseLeave);
			// 
			// lstDeletedId
			// 
			this->lstDeletedId->FormattingEnabled = true;
			this->lstDeletedId->Location = System::Drawing::Point(7, 124);
			this->lstDeletedId->Name = L"lstDeletedId";
			this->lstDeletedId->Size = System::Drawing::Size(24, 30);
			this->lstDeletedId->TabIndex = 2;
			this->lstDeletedId->Visible = false;
			// 
			// btnUndelete
			// 
			this->btnUndelete->Location = System::Drawing::Point(62, 137);
			this->btnUndelete->Name = L"btnUndelete";
			this->btnUndelete->Size = System::Drawing::Size(75, 23);
			this->btnUndelete->TabIndex = 1;
			this->btnUndelete->Text = L"Undelete";
			this->btnUndelete->UseVisualStyleBackColor = true;
			this->btnUndelete->Click += gcnew System::EventHandler(this, &Form1::btnUndelete_Click);
			// 
			// lstDeleted
			// 
			this->lstDeleted->FormattingEnabled = true;
			this->lstDeleted->Location = System::Drawing::Point(17, 21);
			this->lstDeleted->Name = L"lstDeleted";
			this->lstDeleted->Size = System::Drawing::Size(120, 108);
			this->lstDeleted->TabIndex = 0;
			// 
			// tmr
			// 
			this->tmr->Enabled = true;
			this->tmr->Interval = 10000;
			this->tmr->Tick += gcnew System::EventHandler(this, &Form1::tmr_Tick);
			// 
			// chkIsNew
			// 
			this->chkIsNew->AutoSize = true;
			this->chkIsNew->Location = System::Drawing::Point(12, 83);
			this->chkIsNew->Name = L"chkIsNew";
			this->chkIsNew->Size = System::Drawing::Size(80, 17);
			this->chkIsNew->TabIndex = 23;
			this->chkIsNew->Text = L"checkBox1";
			this->chkIsNew->UseVisualStyleBackColor = true;
			this->chkIsNew->Visible = false;
			// 
			// matchProjectsToolStripMenuItem
			// 
			this->matchProjectsToolStripMenuItem->Name = L"matchProjectsToolStripMenuItem";
			this->matchProjectsToolStripMenuItem->Size = System::Drawing::Size(98, 20);
			this->matchProjectsToolStripMenuItem->Text = L"Match Projects";
			this->matchProjectsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::matchProjectsToolStripMenuItem_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(841, 629);
			this->Controls->Add(this->chkIsNew);
			this->Controls->Add(this->deletedPanel);
			this->Controls->Add(this->label40);
			this->Controls->Add(this->txtQuickFind);
			this->Controls->Add(this->pnlLogin);
			this->Controls->Add(this->pnlSearch);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->pnlData);
			this->Controls->Add(this->btnView);
			this->Controls->Add(this->txtId);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->lblUser);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Employee Management System";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->pnlProf->ResumeLayout(false);
			this->pnlProf->PerformLayout();
			this->pnlData->ResumeLayout(false);
			this->pnlData->PerformLayout();
			this->pnlELogin->ResumeLayout(false);
			this->pnlELogin->PerformLayout();
			this->pnlStaff->ResumeLayout(false);
			this->pnlStaff->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbxPicture))->EndInit();
			this->pnlSecurity->ResumeLayout(false);
			this->pnlSecurity->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->pnlSearch->ResumeLayout(false);
			this->pnlSearch->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->pnlLogin->ResumeLayout(false);
			this->pnlLogin->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->deletedPanel->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: void showMsg(String^ message){
					 lblStatus->Text = message;

				 }

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

				 pnlData->Visible = false;
				 Auth::user = "hello";
				 Auth::openDB();

				 pictureBox1->Load(Application::StartupPath + "\\lock.png");
				 //FormSerialisor::Deserialise(this, "e:\\serialise.xml");

			 }
	private: System::Void btnLogin_Click(System::Object^  sender, System::EventArgs^  e) {

				 search sc;

				 //first run setup
				 if (IO::File::Exists(Application::StartupPath + "\\firstrun")){
					 String^ cstri = IO::File::ReadAllText(Application::StartupPath + "\\firstrun");
					 MySqlCommand^ cm = gcnew MySqlCommand(cstri, Auth::con);
					 cm->ExecuteNonQuery();
					 IO::File::Move(Application::StartupPath + "\\firstrun", Application::StartupPath + "\\nofirstrun");
				 }

				 //login user and set visibilities
				 Auth::login(this->txtUser->Text, this->txtPass->Text);
				 if (Auth::isLoggedIn){
					//MessageBox::Show(String::Format("Welcome {0}!", Auth::user));
					 showMsg(String::Format("Welcome {0}!", Auth::user));
					 pnlData->Visible = true;
					sc.FillEmployeeCombo(Employee_comboBox);
					pnlLogin->Visible = false;
					lblUser->Text = String::Format("Logged in as {0}", Auth::user);
					lblUser->Visible = true;

					//crash restore
					if (IO::File::Exists("crash.bin") && IO::File::ReadAllText("crash.bin")->Equals("crash")){
						if (Auth::isLoggedIn)
							FormSerialisor::Deserialise(this, Application::StartupPath + "\\sess.xml");
					}
					IO::File::WriteAllText("crash.bin", "crash");

					//set admin sensitive visibilities
					if (Auth::isAdmin){
						pnlELogin->Visible = true;
						addToolStripMenuItem->Visible = true;
						undeleteToolStripMenuItem->Visible = true;
						backupToolStripMenuItem->Visible = true;
					} else {
						txtSalary->Enabled = false;
						txtNumOfLeaves->Enabled = false;
						btnDelete->Enabled = false;
					}
				 } else {
					 //MessageBox::Show("Sorry, wrong username or password...");
					 showMsg("Wrong username or password.");
				 }
				 

			 }

			 //loads properties from employee object to form
	private: void load_employee_given_e(Employee^ e){
				 pnlProf->Visible = false;

				 if (e->found)
				 {
					 this->lblId->Text = Convert::ToString(e->id);
					 this->txtTitle->Text = e->title;
					 this->txtName->Text = e->name;
					 this->txtMobile->Text = e->mobile;
					 this->txtDob->Value = e->dob->Date;
					 this->pbxPicture->Load(e->pic);
					 this->txtSalary->Text = Convert::ToString(e->salary);
					 this->txtStartDate->Value = e->start_date->Date;
					 this->txtNumOfLeaves->Text = Convert::ToString(e->leaves);
					 this->txtRole->Text = e->role;
					 if (e->role->Equals("prof"))
					 {
						 pnlProf->Visible = true;
						 pnlSecurity->Visible = false;
						 pnlStaff->Visible = false;

						 ProfDetails^ pd = e->getProfDetails();
						 this->txtProfDept->Text = pd->dept;
						 //this->txtProfCreds->Text = pd->creds;
						 this->txtProfCourse->Text = pd->course;
						 this->txtProfCoursesTaught->Text = pd->courses;
						 this->txtProfProjects->Text = pd->projects;
						 this->txtProfWebmail->Text = pd->webmail;
						 this->txtbach->Text = pd->bach;
						 this->txtmast->Text = pd->mast;
						 this->txtphd->Text = pd->phd;


						 

						 lstProfRi->Items->Clear();
						 List<String^>^ ri = e->getProfResearchInterests();
						 for (int i=0; i < ri->Count; i++){
							 lstProfRi->Items->Add(ri[i]);
						 }
					 }
					 if(e->role->Equals("security"))
					 {
						pnlSecurity->Visible = true;
						pnlProf->Visible = false;
						pnlStaff->Visible = false;
						lstSecurityTimings->Items->Clear();
						List<SecurityDetails^>^ r2 = e->getSecurityDetails();
						for( int i=0;i < r2->Count;i++)
						{
							lstSecurityTimings->Items->Add(String::Format("{1}\t{2}\t{3}\t{0}",r2[i]->place,r2[i]->day,r2[i]->start_time->ToString("HH:mm:ss"),r2[i]->end_time->ToString("HH:mm:ss")));
						}
					 }
					 
					 
					 if(e->role->Equals("staff"))
					 {
						pnlStaff->Visible = true;
						pnlProf->Visible = false;
						pnlSecurity->Visible = false;

						StaffDetails^ sd =  e->getStaffDetails();
						this->txtStaffCategory->Text = sd->category;
						this->txtStaffLocation->Text = sd->location;
						this->txtStaffResponsibility->Text = sd->respon;
						this->txtStaffDepartment->Text = sd->dept;

					 }




				 }  else {
					 MessageBox::Show("Error occured...");
				 }
				 

			 }

	private: void load_employee(int id){

				 Employee^ e = gcnew Employee();
				 e->getById(id);
				 load_employee_given_e(e);
				 
			 }

			 //save employee given id (from form to db)
			 void save_employee(int id){
				 Employee e;
				 e.id = id;
				 e.title = txtTitle->Text;
				 e.name = this->txtName->Text;
				 e.dob =  this->txtDob->Value;
				 e.mobile = this->txtMobile->Text;
				 e.salary = Convert::ToInt32(this->txtSalary->Text);
				 e.leaves = Convert::ToInt32(this->txtNumOfLeaves->Text);
				 e.start_date = this->txtStartDate->Value;
				 e.pic = pbxPicture->ImageLocation;
				 e.role = txtRole->Text;

				 if (txtRole->Text->Equals("prof")){
						 ProfDetails^ pd = gcnew ProfDetails();
						 pd->dept = this->txtProfDept->Text;
						 //this->txtProfCreds->Text = pd->creds;
						 pd->creds = "";
						 pd->course = this->txtProfCourse->Text;
						 pd->courses = this->txtProfCoursesTaught->Text;
						 pd->projects = this->txtProfProjects->Text;
						 pd->webmail = this->txtProfWebmail->Text;
						 pd->bach = this->txtbach->Text;
						 pd->mast = this->txtmast->Text;
						 pd->phd = this->txtphd->Text;

						 List<String^>^ ri = gcnew List<String^>();
						 for (int i=0; i< lstProfRi->Items->Count; i++){
							 ri->Add(lstProfRi->Items[i]->ToString());
						 }
						 if (!isNew) e.putProf(pd, ri); else e.putNewProf(pd, ri);
				 }
				 else if (txtRole->Text->Equals("staff")){
					StaffDetails^ sd = gcnew StaffDetails();
					sd->category = this->txtStaffCategory->Text;
					sd->respon = this->txtStaffResponsibility->Text;
					sd->location = this->txtStaffLocation->Text;
					sd->dept = this->txtStaffDepartment->Text;
					if (!isNew) e.putStaff(sd); else e.putNewStaff(sd);
				 }
				 else if(txtRole->Text->Equals("security")){
					 
					 List<SecurityDetails^>^ st = gcnew List<SecurityDetails^>();
					 for (int i=0;i<lstSecurityTimings->Items->Count;i++)
					 {
						 SecurityDetails^ s = gcnew SecurityDetails();
						 array<String^>^ l = lstSecurityTimings->Items[i]->ToString()->Split('\t');
							 s->day = l[0];
							 s->place = l[3];
							 //s->start_time = l[2];
							 //s->end_time l[3];
							 DateTime dt1 = Convert::ToDateTime("2000-07-30 " + l[1]);
							 DateTime dt2 = Convert::ToDateTime("2000-07-30 " + l[2]);
							 s->start_time = dt1;
							 s->end_time = dt2;
							 
						st->Add(s);
					}
					 if (!isNew) e.putSecurity(st); else e.putNewSecurity(st);
				}


				 isNew = false;

			 }

	private: System::Void btnView_Click(System::Object^  sender, System::EventArgs^  _e) {

				 int id = Convert::ToInt32(this->txtId->Text);
				 load_employee(id);

			 }
private: System::Void btnRemoveRi_Click(System::Object^  sender, System::EventArgs^  e) {

			 if (lstProfRi->SelectedIndex < 0) return;
			 lstProfRi->Items->RemoveAt(lstProfRi->SelectedIndex);

		 }
private: System::Void btnAddRi_Click(System::Object^  sender, System::EventArgs^  e) {

			 lstProfRi->Items->Add(txtRi->Text);

		 }
private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {

			 //chkCrash->Checked=false;
			 //graceful exit
			 IO::File::WriteAllText("crash.bin", "nocrash");
			 FormSerialisor::Serialise(this, Application::StartupPath + "\\sess.xml");

		 }
private: System::Void btnShowProfFeedback_Click(System::Object^  sender, System::EventArgs^  e) {

			 ProfFeedback::showFeedback(this->txtProfCourse->Text);

		 }
private: System::Void btnGenProfFeedback_Click(System::Object^  sender, System::EventArgs^  e) {
			 int x;
			 if (!Int32::TryParse(this->txtNumStudents->Text, x)){
				 showMsg("Enter valid integer");
				 return;
			 }
			 if (txtProfCourse->Text->Equals("")) {
				 showMsg("Course is null.");
				 return;
			 }
			 ProfFeedback::generateFeedbackIds(this->txtProfCourse->Text, x);
			 ProfFeedback::outputFeedbackIds(this->txtProfCourse->Text);
			 showMsg("Feedback generated");
		 }
private: System::Void pbxPicture_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void btnADD_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ concat;
			 concat = String::Format("{1}\t{2}\t{3}\t{0}", txtPlace->Text, txtDay->Text, txtStartTime->Text, txtEndTime->Text);
			 lstSecurityTimings->Items->Add(concat);
		 }
private: System::Void btnUpload_Click(System::Object^  sender, System::EventArgs^  e) {
			// OpenFileDialog ^ FileDialog = gcnew OpenFileDialog();
			// FileDialog->Filter = "Image Files|*.jpg";
			 FileDialog->Filter = "Image files (*.bmp;*.jpg;*.gif;*.png;*.tiff)|*.bmp;*.jpg;*.gif;*.png;*.tiff|All files (*.*)|*.*";
			 FileDialog->Title = "Select a Image File";

			 if (FileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				// this->Cursor = gcnew System::Windows::Forms::Cursor(FileDialog->OpenFile());
				//String^ filename = FileDialog->FileName;
				int var = (gcnew FileInfo(FileDialog->FileName))->Length;
				//MessageBox::Show(var);
				 //this->pbxPicture->Load(FileDialog->FileName);
				if( var > 65000)
				{
					//MessageBox::Show(var.ToString());
					MessageBox::Show("file size limit exceeded");
				}
				else
				{
					this->pbxPicture->Load(FileDialog->FileName);
				}
			 }

		 }

		 //static bool isNew = false;

private: System::Void profToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 pnlProf->Visible = true;
			 pnlSecurity->Visible = false;
			 pnlStaff->Visible = false;

			 isNew = true;

			 //reset form
			 txtTitle->Text = "";
			 txtName->Text = "";
			 txtMobile->Text = "";
			 txtSalary->Text = "0";
			 txtNumOfLeaves->Text = "0";
			 // DISPLAY DEFAULT IMAGE
			 pbxPicture->Load(Application::StartupPath + "\\bat.png");
			 txtRole->Text = "prof";

			 txtProfDept->Text = "";
			 txtProfCourse->Text = "";
			 txtProfCoursesTaught->Text = "";
			 txtbach->Text = "";
			 txtmast->Text = "";
			 txtphd->Text = "";
			 txtProfProjects->Text = "";
			 txtProfWebmail->Text = "";
			 lstProfRi->Items->Clear();

		 }
private: System::Void btnSecSubtract_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (lstSecurityTimings->SelectedIndex !=-1){
				 lstSecurityTimings->Items->RemoveAt(lstSecurityTimings->SelectedIndex);
			 }
		 }

private: System::Void btnSave_Click(System::Object^  sender, System::EventArgs^  e) {

			 //validation
			
			 String^ errortext, ^errorblank;
			 int num; bool err=false;
			 if(this->txtName->Text->Equals(""))
			 {
				 errorblank += " Name must be entered";
				 errorblank += " \n";
				 err= true;
			 }
			 if(this->txtDob->Text->Equals(""))
			 {
				 errorblank += " Date of Birth must be entered";
				 errorblank += " \n";
				 err= true;
			 }
			 if(this->txtStartDate->Text->Equals(""))
			 {
				 errorblank += " Starting Date must be entered";
				 errorblank += " \n";
				 err= true;
			 }
			 if(this->txtRole->Text->Equals(""))
			 {
				 errorblank += " Role must be entered";
				 errorblank += " \n";
				 err= true;
			 }
			 if(1)
			 { 
				 bool errortextresultsalary = Int32::TryParse(this->txtSalary->Text,num);
				 if(errortextresultsalary)
				 {}
				 else
				 {
					 errortext += " Salary is given an absurd value (Input for salary has to in numbers)";
					 errortext += " \n";
					 err= true;
				 }
			 }
			 //if(txtMobile->Text!="")
			 //{
				//bool errortextresultmobile = Int32::TryParse(this->txtMobile->Text,num);
				//if(errortextresultmobile)
				//{}
				//else
				//{
					//errortext += " Mobile is given an absurd value(Input for mobile has to in numbers)";
					//errortext += " \n";
					//err= true;
				//}
			 //}
			 //save if no error
			 if(err== false)
			 {
				 errortext = "";
				 errorblank = "";
				 if (!Auth::isAdmin && Auth::emp_id != Convert::ToInt32(this->lblId->Text)){
					showMsg("Insufficient previledges.");
					}
				save_employee(Convert::ToInt32(this->lblId->Text));
				isNew = false;
				showMsg("Record saved.");
				load_employee(txtName->Text);
			 }
			 lblStatus->Text= errortext + errorblank;
		 

			 //


			 
		 }

#pragma region search
		 //Search code
//Changes made by harsha

private: System::Void Searchby_comboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 search sc;
			 String^ SearchSelect=Searchby_comboBox->Text;
			 comboBox1->Text="";
			 comboBox2->Text="";
			 Research_comboBox->Text="";
			 webmail->Text="";
			 projects->Text="";
			 comboBox1->Items->Clear();
			 comboBox2->Items->Clear();
			 Research_comboBox->Items->Clear();
			 webmail->Items->Clear();
			 projects->Items->Clear();

			 if(SearchSelect=="Dept")
				 sc.FillCombo_Dept(comboBox2);
			 else if(SearchSelect=="Research")
				 sc.FillCombo_Field(Research_comboBox);
			 else if(SearchSelect=="Webmail")
				 sc.FillCombo_webmail(webmail);
			  else if(SearchSelect=="Projects")
				 sc.FillCombo_projects(projects);
		 }


private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 String^ EmpName=comboBox1->Text;
			 load_employee(EmpName);
			 pnlSearch->Visible = false;
		 }

		 private: void load_employee(String^ name){//function to load employee by name

				 Employee^ e = gcnew Employee();
				 e->getByName(name);
				
				 load_employee_given_e(e);

			 }

private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 search sc;
			 String^ Dept=comboBox2->Text;
			 comboBox1->Items->Clear();
			 sc.FillNameComboByDept(comboBox1,Dept);
		 }

		 private: void FillNameComboByDept(String^ Dept){
			 
			 if(Auth::isLoggedIn){
				 MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("SELECT employee.name, prof_details.dept FROM employee INNER JOIN prof_details ON employee.id=prof_details.id WHERE prof_details.dept='{0}'",Dept), Auth::con);
		MySqlDataReader^ result = cmd->ExecuteReader();

		 comboBox1->Items->Clear();

		while (result->Read()){
			String^ ProfName;
			ProfName=result->GetString("name");
			comboBox1->Items->Add(ProfName);

		}
		result->Close();
			 }
		 else
			 {
				  MessageBox::Show("Error occured... Please Login");
				  return;
			 }
		
		
		 }

	
private: System::Void Research_comboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 //search sc;
			 //String^ Research=Research_comboBox->Text;
			 //sc.FillNameComboByResearch(comboBox1,Research);
		 }


private: System::Void Employee_comboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 search sc;
			 String^ Employee=Employee_comboBox->Text;
			 comboBox1->Items->Clear();
			 Searchby_comboBox->Items->Clear();
			 Research_comboBox->Items->Clear();
			 comboBox2->Items->Clear();
			 SearchforSecurity_comboBox->Items->Clear();
			 Place_comboBox->Items->Clear();
			 comboBox1->Text="";
			  comboBox2->Text="";
			  Research_comboBox->Text="";
			  Searchby_comboBox->Text="";
			  SearchforSecurity_comboBox->Text="";
			  Place_comboBox->Text="";
			 if(Employee=="prof"){
					//label2->Visible="True";
					//comboBox1->Visible="True";
					label1->Visible="True";					
					label3->Visible="True";					
					comboBox2->Visible="True";
					Research_comboBox->Visible="True";
				  //FillCombo_Prof();//change
				  sc.FillSearchComboforProf(Searchby_comboBox,comboBox1);
				 // FillCombo_Dept();
				  // FillCombo_Field();
			 }
			 else if(Employee=="security"){
				 // MessageBox::Show("In Security");
					 label1->Visible="False";					
				  label3->Visible="False";					
			      comboBox2->Visible="False";
				  Research_comboBox->Visible="False";
				  sc.FillSearchComboforSecurity(SearchforSecurity_comboBox,comboBox1);
				  //sc.FillCombo_Security(comboBox1);//change
			 
			 }
				
		 }
private: System::Void Prof_radiobutton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }



private: System::Void webmail_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 search sc;
			 String^ webmail_id=webmail->Text;
			 comboBox1->Items->Clear();
			 sc.FillNameComboBywebmail_id(comboBox1,webmail_id);
		 }
private: System::Void projects_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 search sc;
			 String^ project_name=projects->Text;
			 comboBox1->Items->Clear();
			 sc.FillNameComboByprojects(comboBox1,project_name);
		 }

private: System::Void SearchforSecurity_comboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 search sc;
			 String^ SearchSelect=SearchforSecurity_comboBox->Text;
			 comboBox1->Text="";
			 Place_comboBox->Text="";
			 comboBox1->Items->Clear();
			 Place_comboBox->Items->Clear();
			 

			 if(SearchSelect=="Place")
				 sc.FillCombo_place(Place_comboBox);
			 else if(SearchSelect=="Time and Day")
			 {
				sc.FillCombo_Day(Day_comboBox);
			 }
			
		 }
private: System::Void Place_comboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 search sc;
			 String^ place=Place_comboBox->Text;
			 comboBox1->Items->Clear();
			 sc.FillNameComboByPlace(comboBox1,place);
		 }

private: System::Void Searchbtn_TimeandDay_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ st_time=dateTimePicker1->Text;
			 String^ end_time=dateTimePicker2->Text;
			 String^ day=Day_comboBox->Text;
			 search sc;
			 if (day=="")
			 {
				 MessageBox::Show("Please select a day!!!");
			 }
			 else
				sc.FillNameComboByTimeandDay(comboBox1,st_time,end_time,day);
			 
		 }
		 //
#pragma endregion

private: System::Void searchToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 pnlSearch->Visible = !(pnlSearch->Visible);
		 }
private: System::Void pnlSearch_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			 int x,y;
			 x = pnlSearch->PointToClient(Cursor->Position).X;
			 y= pnlSearch->PointToClient(Cursor->Position).Y;
			 if (x>0 && x < pnlSearch->Width-10 && y>0 && y<pnlSearch->Height-10) return;
			 pnlSearch->Visible = false;
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			  search sc;
		//	 String^ Research=Research_comboBox->Text;#
			  if (label41->Text->Equals("")) return;
			 comboBox1->Items->Clear();
			 sc.FillNameComboByResearch(comboBox1,fields);
			 
	//		 MessageBox::Show(fields);
			 fields = "";
			 label41->Text = fields;
	//		


		 }

private: System::Void Research_comboBox_SelectedValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 fields +=  (Research_comboBox->SelectedItem->ToString() + ";"); 

		int wordcount=0;
		array<String^>^ words;		
	//	MessageBox::Show(query, "words");

		 String^ delimStr = ";";
		array<Char>^ delimiter = delimStr->ToCharArray( );

	//	fields->ToLower();

		words = label41->Text->Split(delimiter);
		wordcount = words->Length ;
		for (int word=0; word < words->Length-1; word++)
		//	 label6->Text = fields;
			if ( Research_comboBox->SelectedItem->ToString() == words[word] )
				return;
		label41->Text += Research_comboBox->SelectedItem->ToString() + ";";
		 }
		 

		 
private: System::Void staffToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 pnlProf->Visible = false;
			 pnlSecurity->Visible = false;
			 pnlStaff->Visible = true;
			 isNew = true;

			 //reset
			 txtTitle->Text = "";
			 txtName->Text = "";
			 txtMobile->Text = "";
			 txtSalary->Text = "0";
			 txtNumOfLeaves->Text = "0";
			 // DISPLAY DEFAULT IMAGE
			 pbxPicture->Load(Application::StartupPath + "\\bat.png");
			 txtRole->Text = "staff";

			 txtStaffCategory->Text = "";
			 txtStaffLocation->Text = "";
			 txtStaffResponsibility->Text = "";
			 txtStaffDepartment->Text = "";
		 }
private: System::Void txtQuickFind_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 //search if enter pressed
			 if (e->KeyChar == (char)13){
				 if (Auth::isLoggedIn){
					 MySqlCommand^ cmd = gcnew MySqlCommand("SELECT id FROM employee WHERE __active=1 AND `name` LIKE @name", Auth::con);
					 cmd->Prepare();
					 cmd->Parameters->AddWithValue("@name", String::Format("%{0}%", txtQuickFind->Text));
					 MySqlDataReader^ result = cmd->ExecuteReader();
					 if (result->Read()){
						 int x = result->GetInt32("id");
						 result->Close();
						 load_employee(x);
					 } else {
						 showMsg("No employee found.");
					 }
					 result->Close();
				 } else {
					 lblStatus->Text = "Please login to Search";
				 }
			 }
		 }
private: System::Void securityToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 pnlProf->Visible = false;
			pnlSecurity->Visible = true;
			pnlStaff->Visible = false;
			isNew = true;

			//reset form
			txtTitle->Text = "";
			 txtName->Text = "";
			 txtMobile->Text = "";
			 txtSalary->Text = "0";
			 txtNumOfLeaves->Text = "0";
			 // DISPLAY DEFAULT IMAGE
			 pbxPicture->Load(Application::StartupPath + "\\bat.png");
			 txtRole->Text = "security";

			lstSecurityTimings->Items->Clear();
			txtPlace->Text = "";
			txtStaffLocation->Text = "";
		 }
private: System::Void deletedPanel_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			 //hide on mouse exit
			 int x,y;
			 x = deletedPanel->PointToClient(Cursor->Position).X;
			 y= deletedPanel->PointToClient(Cursor->Position).Y;
			 if (x>0 && x < deletedPanel->Width-10 && y>0 && y<deletedPanel->Height-10) return;
			 deletedPanel->Visible = false;
		 }
private: System::Void undeleteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 deletedPanel->Visible = !deletedPanel->Visible;

			 if (!Auth::isLoggedIn){
				 return;
			 }

			 //load deleted objects
			 MySqlCommand^ cmd = gcnew MySqlCommand("SELECT name, id FROM employee WHERE __active=0", Auth::con);
			 MySqlDataReader^ r = cmd->ExecuteReader();
			 lstDeleted->Items->Clear();
			 lstDeletedId->Items->Clear();
			 while (r->Read()){
				 lstDeleted->Items->Add(r->GetString("name"));
				 lstDeletedId->Items->Add(r->GetInt32("id"));
			 }
			 r->Close();

		 }
private: System::Void btnUndelete_Click(System::Object^  sender, System::EventArgs^  e) {

			 //undelete
			 if (lstDeleted->SelectedIndex != -1){
				 int x = Convert::ToInt32(lstDeletedId->Items[lstDeleted->SelectedIndex]);
				 MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("UPDATE employee SET __active=1 WHERE id={0}", x), Auth::con);
				 cmd->ExecuteNonQuery();
				 showMsg("Record restored");
			 }

		 }
private: System::Void btnDelete_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 //delete record
			 int x;
			 if (Int32::TryParse(lblId->Text, x) && !isNew){
				 MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("UPDATE employee SET __active=0 WHERE id={0}", x), Auth::con);
				 cmd->ExecuteNonQuery();
				 showMsg("Record deleted.");

			 //reset form
			 txtTitle->Text = "";
			 txtName->Text = "";
			 txtMobile->Text = "";
			 txtSalary->Text = "0";
			 txtNumOfLeaves->Text = "0";
			 // DISPLAY DEFAULT IMAGE
			 txtRole->Text = "";
			 pnlProf->Visible = false;
			 pnlStaff->Visible = false;
			 pnlSecurity->Visible = false;
			 }
		 }
private: System::Void tmr_Tick(System::Object^  sender, System::EventArgs^  e) {
			 //save state periodically
			 if (Auth::isLoggedIn && !pnlSearch->Visible && !deletedPanel->Visible)
				FormSerialisor::Serialise(this, Application::StartupPath + "\\sess.xml");
		 }
private: System::Void restoreSessionToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //restore session
			 if (Auth::isLoggedIn)
			 FormSerialisor::Deserialise(this, Application::StartupPath + "\\sess.xml");
		 }
private: System::Void backupToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {

			 if (!Auth::isAdmin) return;

			 SaveFileDialog^ ofd = gcnew SaveFileDialog();
			 ofd->Filter = "EMS Backup files (*.emsbkp)|*.emsbkp";
			 if(ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 ProcessStartInfo^ startInfo = gcnew ProcessStartInfo();
				 startInfo->FileName = "cmd.exe";
				 startInfo->Arguments = "/c mysqldump.exe -u emsadmin -pptls ems > \"" + ofd->FileName + "\"";

				 Process::Start(startInfo);
				 showMsg("Database backed up.");
				 //MySqlDump^ md = gcnew MySqlDump
			 }
		 }
private: System::Void btnSaveUP_Click(System::Object^  sender, System::EventArgs^  e) {
			 int x;
			 if (!Int32::TryParse(lblId->Text, x)) return;
			 MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("UPDATE login set user=@user, pass=@pass WHERE emp_id={0}", x), Auth::con);
			 cmd->Prepare();
			 cmd->Parameters->AddWithValue("@user", txtNewUsername->Text);
			 cmd->Parameters->AddWithValue("@pass", txtNewPassword->Text);
			 cmd->ExecuteNonQuery();
			 showMsg("New credentials set.");
		 }
private: System::Void restoreToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 if (!Auth::isAdmin) return;

			 OpenFileDialog^ ofd = gcnew OpenFileDialog();
			 ofd->Filter = "EMS Backup files (*.emsbkp)|*.emsbkp";
			 if(ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 ProcessStartInfo^ startInfo = gcnew ProcessStartInfo();
				 startInfo->FileName = "cmd.exe";
				 startInfo->Arguments = "/c mysql.exe -u emsadmin -pptls ems < \"" + ofd->FileName + "\"";

				 Process::Start(startInfo);
				 showMsg("Database restored.");
			 }

		 }
private: System::Void matchProjectsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 if(mod::mod::match(Auth::con, Application::StartupPath+"\\input.txt", Application::StartupPath+"\\output.txt")){
				 showMsg("Matching saved in output.txt");
			 } else {
				 showMsg("Error occured");
			 }

		 }
};
}

