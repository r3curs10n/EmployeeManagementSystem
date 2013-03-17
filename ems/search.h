#include "Auth.h"
//by harsha
using namespace System;
using namespace System::Collections::Generic;
using namespace System::ComponentModel;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Linq;
using namespace System::Text;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

#pragma once
ref class search
{
public:
	System::Windows::Forms::ComboBox^  Employee_comboBox;
	System::Windows::Forms::ComboBox^  Searchby_comboBox;

	search(){
		// initailise 
		// TODO
		//			Employee_comboBox = System::Windows::Forms::ComboBox^ Employee_comboBox;
	}


	search(System::Windows::Forms::ComboBox^ Employee_combo)
	{
		Employee_comboBox=Employee_combo;
		//		Employee_comboBox->Text='ravi';
	}

public:	void call(void)
		{
			Employee_comboBox->Items->Clear();
			/*Employee_comboBox->Items->Add("hii");
			MessageBox::Show("Test");*/
		}

public: void FillEmployeeCombo(System::Windows::Forms::ComboBox^ Employee_comboBox)
		{
			//		MessageBox::Show("In search class, fill employeecombo","test");
			if (Auth::isLoggedIn){
				MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("SELECT * FROM `employee` GROUP BY `role`"), Auth::con);
				MySqlDataReader^ result = cmd->ExecuteReader();

				Employee_comboBox->Items->Clear();

				while (result->Read()){
					String^ Employee;
					Employee=result->GetString("role");
					Employee_comboBox->Items->Add(Employee);
				}
				result->Close();
			}

			else
			{
				MessageBox::Show("Error occured... Please Login");
				return;
			}

		}

		//Various kinds of Search for professors
public: void FillSearchComboforProf(System::Windows::Forms::ComboBox^ Searchby_comboBox,System::Windows::Forms::ComboBox^ comboBox1)
		{
			//		MessageBox::Show("In search class, in fillsearchcomboforprof","test");
			Searchby_comboBox->Items->Clear();
			FillCombo_Prof(comboBox1);
			Searchby_comboBox->Items->Add("Dept");
			Searchby_comboBox->Items->Add("Research");
			Searchby_comboBox->Items->Add("Webmail");
			Searchby_comboBox->Items->Add("Projects");
		}

public: void FillCombo_Prof(System::Windows::Forms::ComboBox^ comboBox1){
			String^ role="prof";
			if (Auth::isLoggedIn){
				MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("SELECT * FROM `employee` WHERE __active=1 AND `role`='{0}'",role), Auth::con);
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

public: void FillCombo_Security(System::Windows::Forms::ComboBox^ comboBox1){
			String^ role="security";
			if(Auth::isLoggedIn){
				MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("SELECT * FROM `employee` WHERE __active=1 AND `role`='{0}'",role), Auth::con);
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

public: void FillCombo_Staff(System::Windows::Forms::ComboBox^ comboBox1){
			String^ role="staff";
			if(Auth::isLoggedIn){
				MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("SELECT * FROM `employee` WHERE __active=1 AND `role`='{0}'",role), Auth::con);
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

public: void FillCombo_Dept(System::Windows::Forms::ComboBox^ comboBox2){

			if(Auth::isLoggedIn)
			{
				MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("SELECT * FROM `prof_details` GROUP BY `dept`"), Auth::con);
				MySqlDataReader^ result = cmd->ExecuteReader();
				comboBox2->Items->Clear();

				while (result->Read()){
					String^ Dept;
					Dept=result->GetString("dept");
					comboBox2->Items->Add(Dept);
				}
				result->Close();
			}
			else
			{
				MessageBox::Show("Error occured... Please Login");
				return;
			}
		}

public: void FillNameComboByDept(System::Windows::Forms::ComboBox^ comboBox1 , String^ Dept){

			if(Auth::isLoggedIn){
				MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("SELECT employee.name, prof_details.dept FROM employee INNER JOIN prof_details ON employee.id=prof_details.id WHERE __active=1 AND prof_details.dept='{0}'",Dept), Auth::con);
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

public: void FillCombo_Field(System::Windows::Forms::ComboBox^ Research_comboBox){

			if(Auth::isLoggedIn){
				MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("SELECT * FROM `prof_research_interests` GROUP BY `field`"), Auth::con);
				MySqlDataReader^ result = cmd->ExecuteReader();

				Research_comboBox->Items->Clear();

				while (result->Read()){
					String^ field;
					field=result->GetString("field");
					Research_comboBox->Items->Add(field);
				}
				result->Close();
			}
			else
			{
				MessageBox::Show("Error occured... Please Login");
				return;
			}		
		}

public: void FillNameComboByResearch(System::Windows::Forms::ComboBox^ comboBox1, String^ fields){

			
		int wordcount=0;
		array<String^>^ words;		
	//	MessageBox::Show(query, "words");

		 String^ delimStr = ";";
		array<Char>^ delimiter = delimStr->ToCharArray( );

		fields->ToLower();

		words = fields->Split(delimiter);
		wordcount = words->Length ;
  //		MessageBox::Show(fields);
		String^ query = "";
		query = "SELECT employee.name, prof_research_interests.field FROM employee INNER JOIN prof_research_interests ON employee.id=prof_research_interests.prof_id WHERE __active=1 AND " ;
		String^ sub = " prof_research_interests.field=";
	//	MessageBox::Show(query);
		for (int word=0; word < words->Length-1; word++){
	//		MessageBox::Show(words[word], "words");
			query = query + sub + "'" + words[word] + "'" ;
			if (word != words->Length -2)
				query += " OR ";
			else
				query += " GROUP BY `prof_id`";
		}

			if(Auth::isLoggedIn)
			{
				MySqlCommand^ cmd = gcnew MySqlCommand(query, Auth::con);
				MySqlDataReader^ result = cmd->ExecuteReader();

				comboBox1->Items->Clear();

				while (result->Read())
				{
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

public: void FillCombo_webmail(System::Windows::Forms::ComboBox^ webmail){

			if(Auth::isLoggedIn){
				MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("SELECT * FROM `prof_details` GROUP BY `webmail`"), Auth::con);
				MySqlDataReader^ result = cmd->ExecuteReader();

				webmail->Items->Clear();

				while (result->Read()){
					String^ webmail_id;
					webmail_id=result->GetString("webmail");
					webmail->Items->Add(webmail_id);
				}
				result->Close();
			}
			else
			{
				MessageBox::Show("Error occured... Please Login");
				return;
			}		
		}

public: void FillNameComboBywebmail_id(System::Windows::Forms::ComboBox^ comboBox1, String^ webmail_id)
		{
				if(Auth::isLoggedIn)
				{
					MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("SELECT employee.name, prof_details.webmail FROM employee INNER JOIN prof_details ON employee.id=prof_details.id WHERE __active=1 AND prof_details.webmail='{0}'",webmail_id), Auth::con);
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

public: void FillCombo_projects(System::Windows::Forms::ComboBox^ projects){

			if(Auth::isLoggedIn)
			{
				MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("SELECT * FROM `prof_details` GROUP BY `projects`"), Auth::con);
				MySqlDataReader^ result = cmd->ExecuteReader();

				projects->Items->Clear();

				while (result->Read()){
					String^ project_name;
					project_name=result->GetString("projects");
					projects->Items->Add(project_name);
				}
				result->Close();
			}
			else
			{
				MessageBox::Show("Error occured... Please Login");
				return;
			}		
		}

public: void FillNameComboByprojects(System::Windows::Forms::ComboBox^ comboBox1, String^ project_name)
		{
				if(Auth::isLoggedIn)
				{
					MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("SELECT employee.name, prof_details.projects FROM employee INNER JOIN prof_details ON employee.id=prof_details.id WHERE __active=1 AND prof_details.projects LIKE '%{0}%'",project_name), Auth::con);
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
		//End of Search for Professors

		//Search for Security 
public: void FillSearchComboforSecurity(System::Windows::Forms::ComboBox^ SearchforSecurity_comboBox,System::Windows::Forms::ComboBox^ comboBox1)
		{
			//		MessageBox::Show("In search class, in fillsearchcomboforprof","test");
			SearchforSecurity_comboBox->Items->Clear();
			FillCombo_Security(comboBox1);
			SearchforSecurity_comboBox->Items->Add("Place");
			SearchforSecurity_comboBox->Items->Add("Time and Day");
		}

public: void FillCombo_place(System::Windows::Forms::ComboBox^ Place_comboBox){

			if(Auth::isLoggedIn)
			{
				MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("SELECT * FROM `security_details` GROUP BY `place`"), Auth::con);
				MySqlDataReader^ result = cmd->ExecuteReader();
				Place_comboBox->Items->Clear();

				while (result->Read()){
					String^ Place;
					Place=result->GetString("place");
					Place_comboBox->Items->Add(Place);
				}
				result->Close();
			}
			else
			{
				MessageBox::Show("Error occured... Please Login");
				return;
			}
		}

public: void FillNameComboByPlace(System::Windows::Forms::ComboBox^ comboBox1, String^ place)
		{
				if(Auth::isLoggedIn)
				{
					MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("SELECT employee.name, security_details.place FROM employee INNER JOIN security_details ON employee.id=security_details.emp_id WHERE __active=1 AND security_details.place='{0}'",place), Auth::con);
					MySqlDataReader^ result = cmd->ExecuteReader();
					comboBox1->Items->Clear();
					while (result->Read()){
						String^ SecurityName;
						SecurityName=result->GetString("name");
						comboBox1->Items->Add(SecurityName);

					}
					result->Close();
				}
			else
			{
				MessageBox::Show("Error occured... Please Login");
				return;
			}		
		}


//public: void FillCombo_StartTime(System::Windows::Forms::ComboBox^ StartTime_comboBox){
//
//			if(Auth::isLoggedIn)
//			{
//				MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("SELECT security_details.start_time FROM `security_details` GROUP BY `start_time` ORDER BY `start_time`"), Auth::con);
//				MySqlDataReader^ result = cmd->ExecuteReader();
//				StartTime_comboBox->Items->Clear();
//
//				while (result->Read()){
//					String^ st_time;
//					st_time=result->GetString("start_time");
//					StartTime_comboBox->Items->Add(st_time);
//				}
//				result->Close();
//			}
//			else
//			{
//				MessageBox::Show("Error occured... Please Login");
//				return;
//			}
//		}
//
//public: void FillCombo_EndTime(System::Windows::Forms::ComboBox^ EndTime_comboBox){
//
//			if(Auth::isLoggedIn)
//			{
//				MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("SELECT security_details.end_time FROM `security_details` GROUP BY `end_time` ORDER BY `end_time`"), Auth::con);
//				MySqlDataReader^ result = cmd->ExecuteReader();
//				EndTime_comboBox->Items->Clear();
//
//				while (result->Read()){
//					String^ end_time;
//					end_time=result->GetString("end_time");
//					EndTime_comboBox->Items->Add(end_time);
//				}
//				result->Close();
//			}
//			else
//			{
//				MessageBox::Show("Error occured... Please Login");
//				return;
//			}
//		}

public: void FillCombo_Day(System::Windows::Forms::ComboBox^ Day_comboBox){

			if(Auth::isLoggedIn)
			{
				//MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("SELECT security_details.day FROM `security_details` GROUP BY `day`"), Auth::con);
				//MySqlDataReader^ result = cmd->ExecuteReader();
				Day_comboBox->Items->Clear();

				//while (result->Read()){
					//String^ day;
					//day=result->GetString("day");
					Day_comboBox->Items->Add("Monday");
					Day_comboBox->Items->Add("Tuesday");
					Day_comboBox->Items->Add("Wednesday");
					Day_comboBox->Items->Add("Thursday");
					Day_comboBox->Items->Add("Friday");
					Day_comboBox->Items->Add("Saturday");
					Day_comboBox->Items->Add("Sunday");
				//}
				//result->Close();
			}
			else
			{
				MessageBox::Show("Error occured... Please Login");
				return;
			}
		}

public: void FillNameComboByTimeandDay(System::Windows::Forms::ComboBox^ comboBox1,String^ st_time,String^ end_time,String^ day){
			if(Auth::isLoggedIn)
			{
				st_time = "2000-07-30 " + st_time;
				end_time = "2000-07-30 " + end_time;
				String^ a = String::Format("SELECT employee.name , security_details.day , security_details.start_time , security_details.end_time FROM employee INNER JOIN security_details ON employee.id=security_details.emp_id WHERE __active=1 AND `day` LIKE '{0}' AND ((`start_time` >= '{1}' AND `start_time` <= '{2}') OR (`end_time` <= '{2}'  AND `end_time` >= '{1}')) ",day,st_time,end_time);
				MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("SELECT employee.name , security_details.day , security_details.start_time , security_details.end_time FROM employee INNER JOIN security_details ON employee.id=security_details.emp_id WHERE __active=1 AND `day` LIKE '{0}' AND ((`start_time` >= '{1}' AND `start_time` <= '{2}') OR (`end_time` <= '{2}'  AND `end_time` >= '{1}')) ",day,st_time,end_time), Auth::con);
				MySqlDataReader^ result = cmd->ExecuteReader();
				comboBox1->Items->Clear();

				while (result->Read()){
					String^ SecurityName;
					SecurityName=result->GetString("name");
					comboBox1->Items->Add(SecurityName);

				}
				result->Close();
			}
			else
			{
				MessageBox::Show("Error occured... Please Login");
				return;
			}
		}


};