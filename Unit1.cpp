//---------------------------------------------------------------------------

#include <vcl.h>
#include <inifiles.hpp>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

TDateTime FileTimeToDateTime(FILETIME *lpftime)
{
	FILETIME localfiletime;
	SYSTEMTIME systime;
	FileTimeToLocalFileTime(lpftime,&localfiletime);
	FileTimeToSystemTime(&localfiletime,&systime);
	return(TDateTime(systime.wYear, systime.wMonth, systime.wDay,systime.wHour, systime.wMinute,systime.wSecond, systime.wMilliseconds));
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
//connect to database
	UnicodeString op,conn,user,t,newVer,Log,Pass,Serv;
	try {   TIniFile *ini;
		ini = new TIniFile( ChangeFileExt( Application->ExeName, ".INI" ) );
		//connect to server
		Log = ini->ReadString("server","login","");
		Pass = ini->ReadString("server","pass","");
		Serv = ini->ReadString("server","serv_path","");
		if(Log != "") {
			AnsiString command = "net use "+Serv+" "+Pass+" /USER:"+Log;
			system(command.c_str());
		}
		//apply settings
		user = ini->ReadString("path","user","");
		t = ini->ReadString("setting","groupColor","");
		Cgroup = t.ToInt();
		t = ini->ReadString("setting","footerColor","");
		Cfooter = t.ToInt();
		op = ini->ReadString("path","mdb","");
        if((op=="") || (!FileExists(op))) throw op;
		newVer = ini->ReadString("path","new_version","");
		if( FileExists(newVer) ) updateProgram(&newVer);//copy new version of program
		//copy autonome DB-file if it`s exists
        UnicodeString autonome = ExtractFilePath(Application->ExeName) + ExtractFileName(op);
		if(FileExists(autonome)) {
			CopyFile(op.c_str(),autonome.c_str(),false);
		}
	} catch(...) {
		if(op.IsEmpty()) {
			ShowMessage("Не указан путь к серверу.");
			Application->Terminate();
		}
		else {
			UnicodeString autonome = ExtractFilePath(Application->ExeName) + ExtractFileName(op);
			if(FileExists(autonome)) {
				ShowMessage("Связь с сервером не установлена\nРабота в автономном режиме");
				op = autonome;
			}
			else {
				ShowMessage("Нет файла "+op);
                Application->Terminate();
			}
		}
	}
	conn = "Provider=Microsoft.Jet.OLEDB.4.0;User ID=Admin;Data Source=";
	conn += op;
	conn += ";Mode=Share Deny None;Jet OLEDB:System database="";Jet OLEDB:Registry Path=\"\"";
	conn += ";Jet OLEDB:Database Password=\"\";Jet OLEDB:Engine Type=5;Jet OLEDB:Database ";
	conn += "Locking Mode=1;Jet OLEDB:Global Partial Bulk Ops=2;Jet OLEDB:Global Bulk ";
	conn += "Transactions=1;Jet OLEDB:New Database Password=\"\";Jet OLEDB:Create System Database=False";
	conn += ";Jet OLEDB:Encrypt Database=False;Jet OLEDB:Don't Copy Locale on Compact=False;Jet OLEDB:";
	conn += "Compact Without Replica Repair=False;Jet OLEDB:SFP=False;";
	this->ADOConnection1->Connected=false;
    this->ADOConnection1->ConnectionString = conn;
	this->ADOConnection1->Connected=true;
    if( !user.IsEmpty() ) {
        Edit1->Text = user;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == 13) Edit2->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit2KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == 13) this->Button1Click(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//test for the correct login and password
    ADOQuery1->Close();
    ADOQuery1->SQL->Clear();
    ADOQuery1->SQL->Add("select * from users where users.login = \'"+Edit1->Text+"\';");
	ADOQuery1->Open();
	if((ADOQuery1->IsEmpty()) || (ADOQuery1->FieldByName("pass")->AsString != Edit2->Text)) {
		ShowMessage("Неправильно введен логин или пароль.");
		Edit2->Text="";
		return;
	}

	//write login for the next enter in the program
	TIniFile *ini;
	ini = new TIniFile( ChangeFileExt( Application->ExeName, ".INI" ) );
	ini->WriteString("path","user",Edit1->Text);
	delete ini;

//set level of user`s rights
	//read only
	if(( ADOQuery1->FieldByName("rules")->AsString == "0" ) ||
	   ( ADOQuery1->FieldByName("rules")->AsString == "2" ))  {
		Form2->DBGridEh1->Width += 350;
		Form2->DBGridEh2->Left += 350;
		Form2->DBGridEh2->Width -= 350;
		Form2->Label1->Left += 350;
		Form2->Label3->Left += 350;
		Form2->DBNavigator2->Left += 350;
		Form2->DBGridEh1->Columns->Items[1]->Visible = true;
		Form2->DBGridEh1->Columns->Items[2]->ReadOnly = true;
		Form2->DBGridEh1->Columns->Items[2]->Title->Caption = "Наименование";
		Form2->DBGridEh1->Columns->Items[3]->Visible = true;
		Form2->DBGridEh2->ReadOnly = true;
		Form2->DBNavigator1->VisibleButtons = TNavButtonSet(0xF);
		Form2->DBNavigator2->VisibleButtons = TNavButtonSet(0x20F);
		Form2->SpeedButton3->Enabled = false;
		Form2->N8->Enabled = false;
		Form2->N15->Enabled = false;
		//users who can read only
		if( ADOQuery1->FieldByName("rules")->AsString == "0" ) {
			Form2->DBGridEh1->ReadOnly = true;
			Form2->userRules = 0;
		} //users of 'Покупники'
		else {
			Form2->userRules = 2;
		}
	} //users of 'БКЭО'
	else {
		Form2->userRules = 1;
	}
//open database with shifrs
	Form2->ADOshifrs->Open();
	Form2->Show();
	this->Hide();
	Form2->ADOshifrs->First();
	Form2->DBGridEh1->SetFocus();
}
//---------------------------------------------------------------------------
void TForm1::updateProgram(UnicodeString *newVer)
{
//copy new version of this program
	TWin32FileAttributeData fold,fnew;
	TFileTime ft1;
	TSystemTime st;
	//get last write time for both files
	GetFileAttributesEx(newVer->c_str(),GetFileExInfoStandard,&fnew);
	GetFileAttributesEx(Application->ExeName.c_str(),GetFileExInfoStandard,&fold);
	//if we have new version of our program
	if(FileTimeToDateTime(&fnew.ftLastWriteTime) > FileTimeToDateTime(&fold.ftLastWriteTime)) {
		//copy new version of program
		DeleteFile((Application->ExeName+".bak").c_str());
		RenameFile(Application->ExeName.c_str(),(Application->ExeName+".bak").c_str());
		CopyFile(newVer->c_str(),Application->ExeName.c_str(),false);
		//run new version
		ShellExecute(Handle, L"open", Application->ExeName.c_str(), NULL, NULL, SW_NORMAL);
		Application->Terminate();
	}
}
