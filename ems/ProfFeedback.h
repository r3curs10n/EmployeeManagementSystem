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
ref class ProfFeedback
{
public:

	static List<String^>^ fids;

	ProfFeedback(void);

	static bool showFeedback(String^ course){
		if (!Auth::isAdmin){
			return false;
		}

		MySqlCommand^ cmd = gcnew MySqlCommand(String::Format("SELECT COUNT(*) AS numF, AVG(`prof_rating`) AS avgProfRat, AVG(`course_rating`) AS avgCourseRat FROM `prof_feedback` WHERE course='{0}' AND `prof_feedback`.`filled` != 0", course), Auth::con);
		MySqlDataReader^ result = cmd->ExecuteReader();
		if (! result->Read()){
			//
			return false;
		}
		try{
		MessageBox::Show(
			String::Format(
			"Number of Students: {0} \n Average Prof Rating: {1} \n Average Course Rating: {2}",
			result->GetInt32("numF"), result->GetInt32("avgProfRat"), result->GetInt32("avgCourseRat")
			)
			);
		} catch (Exception^ ex){
			MessageBox::Show("No feedback");
		}
		result->Close();
		return true;
	}

	static bool outputFeedbackIds(String^ course) {
		StringBuilder^ sb = gcnew StringBuilder();
		for (int i=0; i < fids->Count; i++){
			sb->AppendLine(fids[i]);
		}

		System::IO::File::WriteAllText(String::Format("{0}\\{1}.txt", Application::StartupPath, course), sb->ToString());
		return true;
	}

	static bool generateFeedbackIds(String^ course, int numOfStudents){
		if(!Auth::isAdmin){
			return false;
		}

		MySqlCommand^ cmd = gcnew MySqlCommand("DELETE FROM `prof_feedback` WHERE `course` = @course", Auth::con);
		cmd->Prepare();

		cmd->Parameters->AddWithValue("@course", course);
		cmd->ExecuteNonQuery();

		cmd = gcnew MySqlCommand("INSERT INTO `prof_feedback` (`course`, `fid`) VALUES (@course, @fid)", Auth::con);
		cmd->Prepare();

		cmd->Parameters->AddWithValue("@course", course);
		cmd->Parameters->AddWithValue("@fid", "xxx");

		Random^ r = gcnew Random(DateTime::Now.Millisecond);
		String^ fid;

		fids = gcnew List<String^>();
		for (int i=0; i<numOfStudents; i++){
			fid =  String::Format("{0}{1}", course, r->Next(100000000));
			cmd->Parameters["@fid"]->Value = fid;
			cmd->ExecuteNonQuery();
			fids->Add(fid);
		}

		return true;
	}

};

