#include "Auth.h"

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

ref class SecurityDetails {
public:
	int id; int emp_id;
	String^ day;
	String^ place;
	DateTime^ start_time;
	DateTime^ end_time;

	SecurityDetails(void){

	}
};

ref class StaffDetails {
public:
	int id; int emp_id;
	String^ location;
	String^ dept;
	String^ category;
	String^ respon;

	StaffDetails(void){

	}
};


ref class ProfDetails {
public:
	String^ dept;
	String^ creds;
	String^ course;
	String^ courses;
	String^ webmail;
	String^ projects;
	String^ bach;
	String^ mast;
	String^ phd;

	ProfDetails(void){

	}
};

ref class Employee
{
public:
	int id;
	String^ title;
	String^ name;
	DateTime^ dob;
	String^ mobile;
	String^ role;
	String^ pic;
	int salary;
	DateTime^ start_date;
	int leaves;

	bool found;

public:
	Employee(void);

	void getByName(String^ _name){
		if (!Auth::isLoggedIn){
			return;
		}

		MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("SELECT * FROM `Employee` WHERE `name`=@name AND __active=1"), Auth::con);
		cmd->Prepare();
		cmd->Parameters->AddWithValue("@name", _name);
		MySqlDataReader^ result = cmd->ExecuteReader();

		if (result->Read()){
			this->id = result->GetInt32("id");
			this->title = result->GetString("title");
			this->name = result->GetString("name");
			this->mobile = result->GetString("mobile");
			this->dob = result->GetDateTime("dob");
			this->role = result->GetString("role");
			this->start_date = result->GetDateTime("start_date");
			this->leaves = result->GetInt32("leaves");
			this->salary = result->GetInt32("salary");

			//extractImage(temp file name, result, columnName)
			this->pic = image::image::extractImage(String::Format("{0}{1}.jpg", this->id, DateTime::Now.ToString("HHmmss")), result, "picture");


			this->found=true;
		} else {
			this->found=false;
		}
		result->Close();
	}

	void getById(int _id){

		if (!Auth::isLoggedIn){
			return;
		}

		MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("SELECT * FROM `Employee` WHERE `id`={0} AND __active=1", _id), Auth::con);
		MySqlDataReader^ result = cmd->ExecuteReader();

		if (result->Read()){
			this->id = result->GetInt32("id");
			this->title = result->GetString("title");
			this->name = result->GetString("name");
			this->mobile = result->GetString("mobile");
			this->dob = result->GetDateTime("dob");
			this->role = result->GetString("role");
			this->start_date = result->GetDateTime("start_date");
			this->leaves = result->GetInt32("leaves");
			this->salary = result->GetInt32("salary");

			//extractImage(temp file name, result, columnName)
			this->pic = image::image::extractImage(String::Format("{0}{1}.jpg", this->id, DateTime::Now.ToString("HHmmss")), result, "picture");


			this->found=true;
		} else {
			this->found=false;
		}
		result->Close();
	}

	List<String^>^ getProfResearchInterests(){
		List<String^ > ^ ri = gcnew List<String^ > ();
		MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("SELECT `field` FROM `prof_research_interests` WHERE `prof_id`={0}", id), Auth::con);
		MySqlDataReader^ result = cmd->ExecuteReader();

		while (result->Read()){
			ri->Add(result->GetString("field"));
		}
		result->Close();
		return ri;
	}

	ProfDetails^ getProfDetails() {
		ProfDetails^ pd = gcnew ProfDetails;
		MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("SELECT * FROM `prof_details` WHERE `id`={0}", id), Auth::con);
		MySqlDataReader^ result = cmd->ExecuteReader();

		result->Read();
		pd->dept = result->GetString("dept");
		pd->creds = result->GetString("creds");
		pd->course = result->GetString("course");
		pd->courses = result->GetString("courses");
		pd->projects = result->GetString("projects");
		pd->webmail = result->GetString("webmail");
		pd->bach = result->GetString("bach");
		pd->mast = result->GetString("mast");
		pd->phd = result->GetString("phd");
		result->Close();
		return pd;
	}

	void putNewProf(ProfDetails^ pd, List<String^>^ ri){
		if (!Auth::isLoggedIn){
			return;
		}
		if (!Auth::isAdmin){
			return;
		}

		String^ strcmd;
		strcmd = "INSERT INTO employee (picture) VALUES ('0')";
		MySqlCommand^ cmd = gcnew MySqlCommand(strcmd, Auth::con);
		cmd->ExecuteNonQuery();

		strcmd = "SELECT last_insert_id() AS lid FROM employee";
		cmd = gcnew MySqlCommand(strcmd, Auth::con);
		MySqlDataReader^ result = cmd->ExecuteReader();
		result->Read();
		this->id = result->GetInt32(0);
		result->Close();

		strcmd = String::Format("INSERT INTO login (user, pass, emp_id) VALUES ('df4f45t54', 'dsf435t5', {0})", this->id);
		cmd = gcnew MySqlCommand(strcmd, Auth::con);
		cmd->ExecuteNonQuery();

		strcmd = String::Format("INSERT INTO prof_details (id) VALUES ({0})", this->id);
		cmd = gcnew MySqlCommand(strcmd, Auth::con);
		cmd->ExecuteNonQuery();

		putProf(pd, ri);
	}

	void putProf(ProfDetails^ pd, List<String^>^ ri){
		if (!Auth::isLoggedIn){
			return;
		}

		if (!(Auth::isAdmin || Auth::emp_id==this->id)){
			return;
		}

		String^ strcmd;
		strcmd = "UPDATE employee SET title=@title, role=@role, name=@name, dob=@dob, mobile=@mobile, start_date=@start_date, salary=@salary, leaves=@leaves WHERE employee.id = @id";
		MySqlCommand^ cmd = gcnew MySqlCommand(strcmd, Auth::con);
		cmd->Prepare();
		cmd->Parameters->AddWithValue("@id", this->id);
		cmd->Parameters->AddWithValue("@title", this->title);
		cmd->Parameters->AddWithValue("@name", this->name);
		cmd->Parameters->AddWithValue("@dob", this->dob);
		cmd->Parameters->AddWithValue("@mobile", this->mobile);
		cmd->Parameters->AddWithValue("@start_date", this->start_date);
		cmd->Parameters->AddWithValue("@salary", this->salary);
		cmd->Parameters->AddWithValue("@leaves", this->leaves);
		cmd->Parameters->AddWithValue("@role", this->role);
		cmd->ExecuteNonQuery();

		image::image::updateImage(this->pic, Auth::con, "employee", "picture", this->id);

		strcmd = "UPDATE prof_details SET dept=@dept, creds=@creds, course=@course, courses=@courses, projects=@projects, webmail=@webmail, bach=@bach, mast=@mast, phd=@phd WHERE id=@id";
		cmd = gcnew MySqlCommand(strcmd, Auth::con);
		cmd->Prepare();
		cmd->Parameters->AddWithValue("@id", this->id);
		cmd->Parameters->AddWithValue("@dept", pd->dept);
		cmd->Parameters->AddWithValue("@creds", pd->creds);
		cmd->Parameters->AddWithValue("@course", pd->course);
		cmd->Parameters->AddWithValue("@courses", pd->courses);
		cmd->Parameters->AddWithValue("@projects", pd->projects);
		cmd->Parameters->AddWithValue("@webmail", pd->webmail);
		cmd->Parameters->AddWithValue("@bach", pd->bach);
		cmd->Parameters->AddWithValue("@mast", pd->mast);
		cmd->Parameters->AddWithValue("@phd", pd->phd);
		cmd->ExecuteNonQuery();

		strcmd = "DELETE FROM prof_research_interests WHERE prof_id=@id";
		cmd = gcnew MySqlCommand(strcmd, Auth::con);
		cmd->Prepare();
		cmd->Parameters->AddWithValue("@id", this->id);
		cmd->ExecuteNonQuery();

		strcmd = "INSERT INTO prof_research_interests (field, prof_id) VALUES (@field, @pid)";
		cmd = gcnew MySqlCommand(strcmd, Auth::con);
		cmd->Prepare();
		cmd->Parameters->AddWithValue("@field", "x");
		cmd->Parameters->AddWithValue("@pid", this->id);
		for (int i=0; i< ri->Count; i++){
			cmd->Parameters["@field"]->Value = ri[i];
			cmd->ExecuteNonQuery();
		}
	}


	//staff related
	//staff details
	StaffDetails^ getStaffDetails() {
		StaffDetails^ sfd = gcnew StaffDetails;
		MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("SELECT * FROM `staff_details` WHERE `id`={0}", this->id), Auth::con);
		MySqlDataReader^ result = cmd->ExecuteReader();

		result->Read();
		sfd->category = result->GetString("category");
		sfd->dept = result->GetString("dept");
		sfd->location = result->GetString("location");
		sfd->respon = result->GetString("respon");
		result->Close();
		return sfd;
	}
	
	//new staff
		void putNewStaff(StaffDetails^ sfd){
		if (!Auth::isLoggedIn){
			return;
		}
		if (!Auth::isAdmin){
			return;
		}

		String^ strcmd;
		strcmd = "INSERT INTO employee (picture) VALUES ('0')";
		MySqlCommand^ cmd = gcnew MySqlCommand(strcmd, Auth::con);
		cmd->ExecuteNonQuery();

		strcmd = "SELECT last_insert_id() AS lid FROM employee";
		cmd = gcnew MySqlCommand(strcmd, Auth::con);
		MySqlDataReader^ result = cmd->ExecuteReader();
		result->Read();
		this->id = result->GetInt32(0);
		result->Close();

		strcmd = String::Format("INSERT INTO login (user, pass, emp_id) VALUES ('df4f45t54', 'dsf435t5', {0})", this->id);
		cmd = gcnew MySqlCommand(strcmd, Auth::con);
		cmd->ExecuteNonQuery();

		strcmd = String::Format("INSERT INTO staff_details (id) VALUES ({0})", this->id);
		cmd = gcnew MySqlCommand(strcmd, Auth::con);
		cmd->ExecuteNonQuery();

		putStaff(sfd);
	 }

	//updating the new staff
		void putStaff(StaffDetails^ sfd){
		if (!Auth::isLoggedIn){
			return;
		}

		if (!(Auth::isAdmin || Auth::emp_id==this->id)){
			return;
		}

		String^ strcmd;
		strcmd = "UPDATE employee SET title=@title, name=@name, role=@role, dob=@dob, mobile=@mobile, start_date=@start_date, salary=@salary, leaves=@leaves WHERE employee.id = @id";
		MySqlCommand^ cmd = gcnew MySqlCommand(strcmd, Auth::con);
		cmd->Prepare();
		cmd->Parameters->AddWithValue("@id", this->id);
		cmd->Parameters->AddWithValue("@title", this->title);
		cmd->Parameters->AddWithValue("@name", this->name);
		cmd->Parameters->AddWithValue("@dob", this->dob);
		cmd->Parameters->AddWithValue("@mobile", this->mobile);
		cmd->Parameters->AddWithValue("@start_date", this->start_date);
		cmd->Parameters->AddWithValue("@salary", this->salary);
		cmd->Parameters->AddWithValue("@leaves", this->leaves);
		cmd->Parameters->AddWithValue("@role", this->role);
		cmd->ExecuteNonQuery();
		
		image::image::updateImage(this->pic, Auth::con, "employee", "picture", this->id);

		/*strcmd = "DELETE FROM staff_details WHERE emp_id=@id";
		cmd = gcnew MySqlCommand(strcmd, Auth::con);
		cmd->Prepare();
		cmd->Parameters->AddWithValue("@id", this->id);
		cmd->ExecuteNonQuery();*/

		strcmd = "UPDATE staff_details SET category=@category ,dept=@dept ,location=@location, respon=@respon WHERE id=@id";
		cmd = gcnew MySqlCommand(strcmd, Auth::con);
		cmd->Prepare();
		cmd->Parameters->Add("@category", sfd->category);
		cmd->Parameters->Add("@dept", sfd->dept);
		cmd->Parameters->Add("@location", sfd->location);
		cmd->Parameters->Add("@respon", sfd->respon);
		cmd->Parameters->AddWithValue("@id", this->id);
		cmd->ExecuteNonQuery();


	}

	//security related stuff
	//security details.....
	List<SecurityDetails^>^ getSecurityDetails(){
		List<SecurityDetails^ > ^ sd = gcnew List<SecurityDetails^ > ();
		MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("SELECT * FROM `security_details` WHERE `emp_id`={0}", this->id), Auth::con);			//here the id is emp_id might get confused with id in security_details n employee tables
		MySqlDataReader^ result = cmd->ExecuteReader();

		while (result->Read()){
			SecurityDetails^ sdi = gcnew SecurityDetails();
			sdi->place = result->GetString("place");
			sdi->day = result->GetString("day");
			sdi->start_time = result->GetDateTime("start_time");
			sdi->end_time = result->GetDateTime("end_time");
			sd->Add(sdi);
		}
		result->Close();
		return sd;
	}

	// new security...
		void putNewSecurity(List<SecurityDetails^>^ sd){
		if (!Auth::isLoggedIn){
			return;
		}
		if (!Auth::isAdmin){
			return;
		}

		String^ strcmd;
		strcmd = "INSERT INTO employee (picture) VALUES ('0')";
		MySqlCommand^ cmd = gcnew MySqlCommand(strcmd, Auth::con);
		cmd->ExecuteNonQuery();

		strcmd = "SELECT last_insert_id() AS lid FROM employee";
		cmd = gcnew MySqlCommand(strcmd, Auth::con);
		MySqlDataReader^ result = cmd->ExecuteReader();
		result->Read();
		this->id = result->GetInt32(0);
		result->Close();

		strcmd = String::Format("INSERT INTO login (user, pass, emp_id) VALUES ('df4f45t54', 'dsf435t5', {0})", this->id);
		cmd = gcnew MySqlCommand(strcmd, Auth::con);
		cmd->ExecuteNonQuery();

		putSecurity(sd);
	 }

		//update for new security
		void putSecurity(List<SecurityDetails^>^ sd){
		if (!Auth::isLoggedIn){
			return;
		}

		if (!(Auth::isAdmin || Auth::emp_id==this->id)){
			return;
		}

		String^ strcmd;
		strcmd = "UPDATE employee SET title=@title, name=@name, role=@role, dob=@dob, mobile=@mobile, start_date=@start_date, salary=@salary, leaves=@leaves WHERE employee.id = @id";
		MySqlCommand^ cmd = gcnew MySqlCommand(strcmd, Auth::con);
		cmd->Prepare();
		cmd->Parameters->AddWithValue("@id", this->id);
		cmd->Parameters->AddWithValue("@title", this->title);
		cmd->Parameters->AddWithValue("@name", this->name);
		cmd->Parameters->AddWithValue("@dob", this->dob);
		cmd->Parameters->AddWithValue("@mobile", this->mobile);
		cmd->Parameters->AddWithValue("@start_date", this->start_date);
		cmd->Parameters->AddWithValue("@salary", this->salary);
		cmd->Parameters->AddWithValue("@leaves", this->leaves);
		cmd->Parameters->AddWithValue("@role", this->role);
		cmd->ExecuteNonQuery();
		
		image::image::updateImage(this->pic, Auth::con, "employee", "picture", this->id);

		if(Auth::isAdmin){
			strcmd = "DELETE FROM security_details WHERE emp_id=@id";
			cmd = gcnew MySqlCommand(strcmd, Auth::con);
			cmd->Prepare();
			cmd->Parameters->AddWithValue("@id", this->id);
			cmd->ExecuteNonQuery();

			strcmd = "INSERT INTO security_details (place, day ,start_time ,end_time,emp_id) VALUES (@place, @day ,@start_time ,@end_time,@id)";
			cmd = gcnew MySqlCommand(strcmd, Auth::con);
			cmd->Prepare();
			cmd->Parameters->Add("@place", MySqlDbType::VarChar);
			cmd->Parameters->Add("@day", MySqlDbType::VarChar);
			cmd->Parameters->Add("@start_time", MySqlDbType::DateTime);
			cmd->Parameters->Add("@end_time", MySqlDbType::DateTime);
			cmd->Parameters->AddWithValue("@id", this->id);
			for (int i=0; i< sd->Count; i++){
				cmd->Parameters["@place"]->Value = sd[i]->place;
				cmd->Parameters["@day"]->Value = sd[i]->day;
				cmd->Parameters["@start_time"]->Value = sd[i]->start_time;
				cmd->Parameters["@end_time"]->Value = sd[i]->end_time;
				cmd->ExecuteNonQuery();
			}
		}
	}


};