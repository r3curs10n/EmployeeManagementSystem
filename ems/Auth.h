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
ref class Auth
{
public:
	static String^ user;
	static bool isAdmin = false;
	static bool isLoggedIn = false;
	static MySqlConnection^ con;
	static int emp_id;
	static String^ constr;
public:
	Auth(void);

	static void openDB(){
		if (IO::File::Exists(Application::StartupPath + "\\server")){
			constr = String::Format("Server={0};Database=ems;Uid=emsadmin;pwd=ptls", IO::File::ReadAllText(Application::StartupPath + "\\server"));
		} else
			constr = "Server=localhost;Database=ems;Uid=emsadmin;pwd=ptls";
		
		con = gcnew MySqlConnection(constr);
		try {
			con->Open();
		} catch (Exception^ ex){

		}
	}

	static String^ encrypt(String^ str){
		return str;
	}

	static bool login(String^ user, String^ pass){
		pass = encrypt(pass);
		String^ query = "SELECT * FROM `login` WHERE user=@user AND pass=@pass";
		MySqlCommand^ cmd = gcnew MySqlCommand(query, con);
		cmd->Prepare();
		cmd->Parameters->AddWithValue("@user", user);
		cmd->Parameters->AddWithValue("@pass", pass);
		MySqlDataReader^ result = cmd->ExecuteReader();

		if (result->Read()){
			
			Auth::user = result->GetString("user");
			Auth::emp_id = result->GetInt32("emp_id");
			//MessageBox::Show(user);
			isLoggedIn = true;
			String^ type = result->GetString("type");
			if (type->Equals("admin")){
				isAdmin = true;
			} else {
				isAdmin = false;
			}
			result->Close();
			return true;
		} else {
			result->Close();
			return isAdmin = isLoggedIn = false;
		}
	}



};

