//---------------------------------------------------------------------------

#include <vcl.h>
#include <inifiles.hpp>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit3bpi.h"
#include "Unit7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DataDriverEh"
#pragma link "DBAxisGridsEh"
#pragma link "DBGridEh"
#pragma link "DBGridEhGrouping"
#pragma link "DBGridEhToolCtrls"
#pragma link "DynVarsEh"
#pragma link "EhLibVCL"
#pragma link "GridsEh"
#pragma link "MemTableDataEh"
#pragma link "MemTableEh"
#pragma link "ToolCtrlsEh"
#pragma link "PrnDbgeh"
#pragma link "DBCtrlsEh"
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	DBGridEh2->ShowHint = true;
	ADOname_delivery->Open();
	now_date = Date();
	Vold="";
	Vnew="";
	go_dse=0;
	CanGo=1;
	ado_post=0;
	old_info_record[0] = 0;
	//resize to full window
	this->Resizing(wsMaximized);
	//applying settings
	if(Form1->Cgroup)	DBGridEh2->DataGrouping->Color = Form1->Cgroup;
	else DBGridEh2->DataGrouping->Color = clWindow;
	if(Form1->Cfooter) DBGridEh2->DataGrouping->Footers->Items[0]->Color = Form1->Cfooter;
	else DBGridEh2->DataGrouping->Footers->Items[0]->Color = clWindow;

	DBGridEh2->Columns->Items[12]->Color = 0xffe4ff;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
//save settings before close application
	TIniFile *ini;
	ini = new TIniFile( ChangeFileExt( Application->ExeName, ".INI" ) );
	ini->WriteInteger("setting","groupColor",Form1->Cgroup);
	ini->WriteInteger("setting","footerColor",Form1->Cfooter);
	MemTableEh1->Close();
	ADOshifrs->Close();
	Form1->ADOConnection1->Close();
	Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ADOshifrsCalcFields(TDataSet *DataSet)
{
//calculate record`s number and full limit of instrument
	ADOshifrsnpp->Value = DataSet->RecNo;
	if(ADOshifrsnpp->Value == -1) {
			ADOshifrsnpp->Value = 1;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ADOshifrsAfterScroll(TDataSet *DataSet)
{
//looking for details of the selected shifr
	if(CanGo==0) return;
	MemTableEh1->Close();
	ADOinfo->SQL->Clear();
	AnsiString sql = "select * from info where info.flag <> 1 AND info.num_shifr = ";   /**/
	sql += ADOshifrs->FieldByName("id")->AsInteger;
	//if we have filter by field 'chex' -> select only it information about 'shifr'
	if(Edit2->Text != "") {
		sql += " AND info.chex = " + Edit2->Text;
	}
	//if we have filter by field 'dse' -> select only it information about 'shifr'
	if(Edit_dse->Text != "") {
		sql += " AND info.dse = \'" + Edit_dse->Text + "\'";
	}
	//if grouping inactive -> order by only 'id'
	if(DBGridEh2->DataGrouping->Active == true) {
		sql += " order by info.chex, info.dse, info.num_op, info.flag desc, info.id;";
	}
	else {
		sql += " order by info.id;";
	}
	ADOinfo->SQL->Add(sql);
	MemTableEh1->Open();
	Label3->Caption = "Информация о шифре "+ADOshifrsshifr->AsString+" ( Марка обрабатываемого материала ";
	DBEditMaterial->Left = Label3->Left + Label3->Width;
	Label7->Left = DBEditMaterial->Left + DBEditMaterial->Width + 5;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::DBGridEh1DrawColumnCell(TObject *Sender, const TRect &Rect,
		  int DataCol, TColumnEh *Column, Gridseh::TGridDrawState State)
{
//move arrow
	if(State.Contains(Gridseh::gdSelected)) Label1->Top = DBGridEh1->Top + Rect.top - 16;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == 13) {
		//filter
		ADOshifrs->Close();
		if(Edit1->Text == "") {
		  ADOshifrs->SQL->Strings[21] = " ";
		}
		else {
		  //it is sad, but current driver version can not use function 'Replace' :(
		  //ADOshifrs->SQL->Strings[3] = " Replace(shifrs.shifr, ' ', '') = Replace(\'"+Edit1->Text+"%\', ' ', '') ";
		  //and I don`t have much rights for update this driver
		  UnicodeString noSpaces = "";
		  UnicodeString tmp = Edit1->Text;
		  for(int i=1; i<=tmp.Length(); i++) {
			noSpaces += UnicodeString(tmp[i])+" ";
		  }
		  noSpaces = StringReplace(noSpaces," ","%",TReplaceFlags()<<rfReplaceAll);
		  ADOshifrs->SQL->Strings[21] = " (shifrs.shifr Like \'"+noSpaces+"\') AND ";
		}
		ADOshifrs->Open();
		//add 'shifr' if we not finded it
		if( ADOshifrs->IsEmpty() && (userRules == 1) && (Edit1->Text != "") ) {
			if(IDYES == Application->MessageBox(L"Данный шифр не найден. Добавить его?", L"Добавление", MB_YESNO)) {
				//add 'shifr' into main table
				ADOtemp->Close();
				ADOtemp->SQL->Clear();
				ADOtemp->SQL->Add("INSERT INTO shifrs ( shifr, flag, date_in ) VALUES ( \'"+Edit1->Text+"\', 0, Date() );");
				ADOtemp->ExecSQL();

				//select 'id' of the added 'shifr'
                ADOtemp->Close();
				ADOtemp->SQL->Clear();
				ADOtemp->SQL->Add("SELECT id FROM shifrs ORDER BY id desc;");
				ADOtemp->Open();
				ADOtemp->First();
				AnsiString shifr_id = ADOtemp->FieldByName("id")->AsString;

				//add 'info' for added 'shifr'
				ADOtemp->Close();
				ADOtemp->SQL->Clear();
				ADOtemp->SQL->Add("INSERT INTO info ( num_shifr, chex ) VALUES ( "+shifr_id+", 0 );");
				ADOtemp->ExecSQL();

				//show added 'shifr'
				Refresh();
			}
		}
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
//on/off grouping in the table
	if(DBGridEh2->DataGrouping->Active == true) {
		DBGridEh2->DataGrouping->Active = false;
		N11->Checked = false;
		Button1->Caption = "Группировка :Вкл";
		DBGridEh2->Columns->Items[0]->HideDuplicates = false;
		DBGridEh2->Columns->Items[1]->HideDuplicates = false;
		DBGridEh2->Columns->Items[2]->HideDuplicates = false;
		this->ADOshifrsAfterScroll(DataSource1->DataSet);
	}
	else {
		DBGridEh2->DataGrouping->Active = true;
		N11->Checked = true;
		Button1->Caption = "Группировка :Выкл";
		DBGridEh2->Columns->Items[0]->HideDuplicates = true;
		DBGridEh2->Columns->Items[1]->HideDuplicates = true;
		DBGridEh2->Columns->Items[2]->HideDuplicates = true;
		this->ADOshifrsAfterScroll(DataSource1->DataSet);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::DBGridEh2DrawColumnCell(TObject *Sender, const TRect &Rect,
		  int DataCol, TColumnEh *Column, Gridseh::TGridDrawState State)
{
//left and right border of "Норм расхода" - bold line
    if((DataCol == 7) || (DataCol == 11) || (DataCol == 12)) {
		TColor color = DBGridEh1->Canvas->Pen->Color;
		DBGridEh2->Canvas->Pen->Color = clBlack;
        DBGridEh2->Canvas->MoveTo(Rect.Right,Rect.Top);
		DBGridEh2->Canvas->LineTo(Rect.Right,Rect.Bottom);
		DBGridEh2->Canvas->Pen->Color = color;
        DBGridEh2->Canvas->Pen->Width = 1;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::SpeedButton4Click(TObject *Sender)
{
//delete filter
	Edit1->Text = "";
	unsigned short key=13;
	this->Edit1KeyDown(Sender,key,TShiftState());
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N11Click(TObject *Sender)
{
//grouping from the menu
	this->Button1Click(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::MemTableEh1AfterInsert(TDataSet *DataSet)
{
//insert 'id' of the 'shifr' into the new 'detail'
	MemTableEh1->FieldByName("num_shifr")->AsInteger = ADOshifrs->FieldByName("id")->AsInteger;
	if(infoChex != "") MemTableEh1->FieldByName("chex")->AsString = infoChex;
	if(infoDse != "") MemTableEh1->FieldByName("dse")->AsString = infoDse;
	if(infoNlim != "") MemTableEh1->FieldByName("Nlim_kart")->AsString = infoNlim;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::MemTableEh1BeforeInsert(TDataSet *DataSet)
{
//save old 'chex' and 'dse'
	infoChex = MemTableEh1->FieldByName("chex")->AsString;
	infoDse = MemTableEh1->FieldByName("dse")->AsString;
	infoNlim = MemTableEh1->FieldByName("Nlim_kart")->AsString;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::DBGridEh1Exit(TObject *Sender)
{
//if we go out from the table with 'shifrs' - post all changes
	if((ADOshifrs->State == dsInsert) || (ADOshifrs->State == dsEdit))
		ADOshifrs->Post();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N12Click(TObject *Sender)
{
//color for 'groups'
	if(ColorDialog1->Execute()) {
		Form1->Cgroup = ColorDialog1->Color;
		DBGridEh2->DataGrouping->Color = ColorDialog1->Color;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N13Click(TObject *Sender)
{
//color for 'sum'
	if(ColorDialog1->Execute()) {
		Form1->Cfooter = ColorDialog1->Color;
		DBGridEh2->DataGrouping->Footers->Items[0]->Color = ColorDialog1->Color;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N2Click(TObject *Sender)
{
//Print info about shifr
	this->Button2Click(Sender);
}
//---------------------------------------------------------------------------
//COPY
void __fastcall TForm2::SpeedButton2Click(TObject *Sender)
{
	if(DBGridEh2->DataGrouping->Active == true)
		{this->Button1Click(Sender);}
	DBGridEh2->SetFocus();
	DBGridEh2->Selection->SelectAll();
	keybd_event(VK_CONTROL,0,0,0);
	keybd_event(0x43,0,0,0);
	keybd_event(0x43,0,KEYEVENTF_KEYUP,0);
	keybd_event(VK_CONTROL,0,KEYEVENTF_KEYUP,0);
	//DBGridEh2->Selection->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N7Click(TObject *Sender)
{
//COPY
	this->SpeedButton2Click(Sender);
}
//---------------------------------------------------------------------------
//PASTE
void __fastcall TForm2::N8Click(TObject *Sender)
{
	this->SpeedButton3Click(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::SpeedButton3Click(TObject *Sender)
{
//PASTE
	if(DBGridEh2->DataGrouping->Active == true)
		{this->Button1Click(Sender);}
	DBGridEh2->SetFocus();
	DBGridEh2->SelectedIndex = 0;
	MemTableEh1->Last();
	MemTableEh1->Insert();
	MemTableEh1->Post();
	keybd_event(VK_CONTROL,0,0,0);
	keybd_event(0x56,0,0,0);
	keybd_event(0x56,0,KEYEVENTF_KEYUP,0);
	keybd_event(VK_CONTROL,0,KEYEVENTF_KEYUP,0);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::DBNavigator2Click(TObject *Sender, TNavigateBtn Button)
{
//recalc 'limits' for whole plant
	if(Button == nbRefresh) {
		Refresh();
	}
	if(Button == nbInsert) {
		DBGridEh2->SetFocus();
		DBGridEh2->SelectedIndex = 0;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N15Click(TObject *Sender)
{
//correcting mistake in the 'shifr' name
	Form3->Edit1->Text = ADOshifrsshifr->Value;
	Form3->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormResize(TObject *Sender)
{
//fit columns width only on fullscreen
	if((this->WindowState == wsMaximized) && (DBGridEh2->Width > 1100)) {
		DBGridEh2->AutoFitColWidths = true;
	}
	else DBGridEh2->AutoFitColWidths = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::DBGridEh2KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
//go to selected 'shifr' or insert this 'shifr' into the database
	if((Key == 13) && (DBGridEh2->SelectedIndex == 17)) {
		UnicodeString shifr = MemTableEh1->FieldByName("new_plast")->AsString;

		if(shifr == "") return;
		if(IDYES == Application->MessageBox(L"Перейти к выбранному шифру?", L"Переход", MB_YESNO)) {
			if((MemTableEh1->State == dsInsert) || (MemTableEh1->State == dsEdit))
				MemTableEh1->Post();
			//find 'shifr'
			Edit1->Text = shifr;
			ADOshifrs->Close();
			ADOshifrs->SQL->Strings[3] = "shifrs.shifr like \'"+Edit1->Text+"%\'";
			ADOshifrs->Open();
			if(ADOshifrs->IsEmpty()) {
				//if 'shifr' not finded -> then insert it
				Edit1->Text = "";
				ADOshifrs->Close();
				ADOshifrs->SQL->Strings[3] = "shifrs.shifr like \'"+Edit1->Text+"%\'";
				ADOshifrs->Open();
				ADOshifrs->Insert();
				ADOshifrs->FieldByName("shifr")->AsString = shifr;
				ADOshifrs->Post();
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::DBGridEh2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
//copy selected cell when we do 'drag & drop'
	mov = DBGridEh2->SelectedField->AsString;
	mov_can = DBGridEh2->Row;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::DBGridEh2MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
//if we done 'drag & drop' to another record -> then paste into selected cell
	if(DBGridEh2->Row != mov_can) {
		DBGridEh2->DataSource->DataSet->Edit();
		DBGridEh2->SelectedField->AsString = mov;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ADOshifrsPostError(TDataSet *DataSet, EDatabaseError *E, TDataAction &Action)
{
//on error - cancel record`s changes
	Action = daAbort;
	DataSet->Cancel();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::MemTableEh1AfterPost(TDataSet *DataSet)
{
//add old version of the record (if limits were changed)
	if(this->old_info_record[0] == 1) {
		if(old_info_record[2] == "") old_info_record[2] = "Null";
		if(old_info_record[10] == "") old_info_record[10] = "Null";
		if(old_info_record[11] == "") old_info_record[11] = "Null";
		if(old_info_record[12] == "") old_info_record[12] = "Null";
		if(old_info_record[15] == "") old_info_record[15] = "Null";
		old_info_record[10] = StringReplace(old_info_record[10], ",", ".", TReplaceFlags()<<rfReplaceAll);
		old_info_record[11] = StringReplace(old_info_record[11], ",", ".", TReplaceFlags()<<rfReplaceAll);
		old_info_record[12] = StringReplace(old_info_record[12], ",", ".", TReplaceFlags()<<rfReplaceAll);
		old_info_record[15] = StringReplace(old_info_record[15], ",", ".", TReplaceFlags()<<rfReplaceAll);
		ADOtemp->Close();
		ADOtemp->SQL->Clear();
		ADOtemp->SQL->Add("INSERT INTO info (num_shifr, chex, Nlim_kart, dse, marka, num_op, Tmax, kol_mest, kol_plast, norm_l, norm_o, norm, stoikost, Ku, act, date_drop, new_plast, srok, change_date, flag) ");
		ADOtemp->SQL->Add(" VALUES ( "+old_info_record[1]+", "+old_info_record[2]+", \'"+old_info_record[3]+"\',");
		ADOtemp->SQL->Add(" \'"+old_info_record[4]+"\', \'"+old_info_record[5]+"\', \'"+old_info_record[6]+"\',");
		ADOtemp->SQL->Add(" \'"+old_info_record[7]+"\', \'"+old_info_record[8]+"\', \'"+old_info_record[9]+"\',");
		ADOtemp->SQL->Add(" "+old_info_record[10]+", "+old_info_record[11]+", "+old_info_record[12]+",");
		ADOtemp->SQL->Add(" \'"+old_info_record[14]+"\', "+old_info_record[15]+", \'"+old_info_record[16]+"\',");
		ADOtemp->SQL->Add(" \'"+old_info_record[17]+"\', \'"+old_info_record[18]+"\',");
		if(old_info_record[19] == "") ADOtemp->SQL->Add(" Null,");
		else ADOtemp->SQL->Add(" \'"+old_info_record[19]+"\',");
		if(old_info_record[20] == "") ADOtemp->SQL->Add(" Null, 1);");
		else ADOtemp->SQL->Add(" \'"+old_info_record[20]+"\', 1);");
		ADOtemp->ExecSQL();
		this->old_info_record[0] = 0;
		//reopen info
		/*int recno = MemTableEh1->RecNo;
		MemTableEh1->Close();
		MemTableEh1->Open();
		MemTableEh1->RecNo = recno;*/
	}

//yellowed 'shifr' if we add record with zero limits
	int paste = 1;
	if((dsInsertFlag == 1) && (MemTableEh1norm_l->AsString == "") && (MemTableEh1norm_o->AsString == "") &&
		(MemTableEh1norm->AsString == "") && (ADOshifrs->FieldByName("flag")->AsInteger == 0)) {
			paste = 2;
	}
	//if we have limits - 'shifr' don`t colored
	else
	if( ((MemTableEh1norm_l->AsString != "") || (MemTableEh1norm_o->AsString != "") ||
		(MemTableEh1norm->AsString != "")) && (ADOshifrs->FieldByName("flag")->AsInteger == 2)) {
			paste = 0;
	}

	//reopen 'shifr'
	if(paste != 1) {
		int recno = MemTableEh1->RecNo;
		MemTableEh1->Close();
		ADOshifrs->Edit();
		ADOshifrs->FieldByName("flag")->AsInteger = paste;
		ADOshifrs->Post();
		MemTableEh1->Open();
		MemTableEh1->RecNo = recno;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit2KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == 13) {
		//filter by 'chex'
		ADOshifrs->Close();
		if(Edit2->Text != "")
			ADOshifrs->SQL->Strings[20] = " (info.chex = "+Edit2->Text+") AND ";
		else
			ADOshifrs->SQL->Strings[20] = " ";
		ADOshifrs->Open();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::SpeedButton5Click(TObject *Sender)
{
	//delete filter by 'chex'
	Edit2->Text = "";
	unsigned short key=13;
	this->Edit2KeyDown(Sender,key,TShiftState());
}
//---------------------------------------------------------------------------
void __fastcall TForm2::DBGridEh2HintShowPause(TCustomDBGridEh *Sender, TPoint &CursorPos,
          Gridseh::TGridCoord &Cell, TPoint &InCellCursorPos, TColumnEh *Column, int &HintPause,
          bool &Processed)
{
	//hint when the record was edited
	DBGridEh2->Hint = MemTableEh1->FieldByName("change_date")->AsString;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::MemTableEh1BeforePost(TDataSet *DataSet)
{
	dsInsertFlag = 0;
	if((MemTableEh1->State == dsInsert)) dsInsertFlag = 1;
	//write date when new record was added
	if( MemTableEh1->FieldByName("change_date")->AsString == "" ) {
		MemTableEh1->FieldByName("change_date")->AsDateTime = Date();
	}
	else
	 //write date when record`s "нормы расхода" was edited
	 try{
	  int save = 0;
	  if(!MemTableEh1norm_l->OldValue.IsNull())
	  if( (MemTableEh1norm_l->OldValue.operator double() != MemTableEh1norm_l->Value) )
		  {
			save = 1;
		  }
	  else if(!MemTableEh1norm_o->OldValue.IsNull())
	  if( (MemTableEh1norm_o->OldValue.operator double() != MemTableEh1norm_o->Value) )
		  {
			save = 1;
		  }
	  else if(!MemTableEh1norm->OldValue.IsNull())
	  if( (MemTableEh1norm->OldValue.operator double() != MemTableEh1norm->Value) )
		  {
			save = 1;
		  }

	  if(save == 1) {
		  MemTableEh1->FieldByName("change_date")->AsDateTime = Date();
		  //save old version of the record
		  this->old_info_record[0] = 1;
		  for(int i=1; i<21; i++) {
			  if(MemTableEh1->Fields->Fields[i]->OldValue.IsNull()) {
				  old_info_record[i] = "";
			  }
			  else {
				  old_info_record[i] = MemTableEh1->Fields->Fields[i]->OldValue.operator UnicodeString();
			  }
		  } 
		  return;
	  }
	 }
	 catch(...){}

	 //cancel post if we have the same record before
	 ADOtemp->Close();
	 ADOtemp->SQL->Clear();
	 ADOtemp->SQL->Add("SELECT * FROM shifrs INNER JOIN info ON shifrs.id = info.num_shifr ");
	 ADOtemp->SQL->Add(" WHERE (shifrs.id = "+ADOshifrsid->AsString+")");
	 ADOtemp->SQL->Add(" AND (info.chex = "+MemTableEh1chex->AsString+")");
	 ADOtemp->SQL->Add(" AND (info.dse = \'"+MemTableEh1dse->AsString+"\')");
	 ADOtemp->SQL->Add(" AND (info.num_op = \'"+MemTableEh1num_op->AsString+"\')");
	 if(MemTableEh1id->AsString != "")
	 	ADOtemp->SQL->Add(" AND (info.id <> "+MemTableEh1id->AsString+")");
	 ADOtemp->SQL->Add(" AND (info.flag <> 1);");
	 ADOtemp->Open();
	 if( !ADOtemp->IsEmpty() ) {
		ShowMessage("Запись с таким цехом, ДСЕ и номером операции уже есть в шифре!");
		//MemTableEh1->Cancel();
		ado_post = 0;
		return;
	 }

	 if(go_dse == 1) return;
	 //if 'dse' was edited and we have the same 'dse' in other 'shifrs' -> tell to user about this
	 try{
	  if((MemTableEh1->FieldByName("dse")->OldValue != MemTableEh1->FieldByName("dse")->NewValue) ||
		 (MemTableEh1->FieldByName("chex")->OldValue != MemTableEh1->FieldByName("chex")->NewValue) ||
		 (MemTableEh1->FieldByName("num_op")->OldValue != MemTableEh1->FieldByName("num_op")->NewValue) ||
		 (MemTableEh1->FieldByName("dse")->OldValue.IsNull()) ) {
		  F_DSE->MemTableEh1->Close();
		  F_DSE->ADOdse->SQL->Strings[3] = " (info.dse = \'"+MemTableEh1->FieldByName("dse")->AsString+"\')";
		  F_DSE->ADOdse->SQL->Strings[4] = " AND (info.chex = "+MemTableEh1->FieldByName("chex")->AsString+")";
		  F_DSE->ADOdse->SQL->Strings[5] = " AND (info.num_op = \'"+MemTableEh1->FieldByName("num_op")->AsString+"\')";
		  F_DSE->ADOdse->SQL->Strings[6] = " AND (shifrs.shifr <> \'"+ADOshifrs->FieldByName("shifr")->AsString+"\');";
		  F_DSE->MemTableEh1->Open();

		  if(F_DSE->ADOdse->RecordCount > 0) {
			F_DSE->Caption = "ДСЕ "+MemTableEh1->FieldByName("dse")->AsString+" уже существует в других шифрах";
			F_DSE->ShowModal();
		  }
	  }
	 }
	 catch(...){}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::MemTableEh1CalcFields(TDataSet *DataSet)
{
	//autocalculate 'limits if detail'
	if( (MemTableEh1->FieldByName("Tmax")->AsString != "") &&
		(MemTableEh1->FieldByName("stoikost")->AsString != "") &&
		(MemTableEh1->FieldByName("Ku")->AsString != "") ) {
			float Tmax, stoikost, Ku;
			Ku = MemTableEh1->FieldByName("Ku")->AsFloat;
			try{
				Tmax = StringReplace(MemTableEh1->FieldByName("Tmax")->AsString,".",",",TReplaceFlags()<<rfReplaceAll).ToDouble();
				stoikost = StringReplace(MemTableEh1->FieldByName("stoikost")->AsString,".",",",TReplaceFlags()<<rfReplaceAll).ToDouble();
			}
			catch(EConvertError &e) {
				try{
					//if we have '.' -> replace this on ','
					Tmax = StringReplace(MemTableEh1->FieldByName("Tmax")->AsString,",",".",TReplaceFlags()<<rfReplaceAll).ToDouble();
					stoikost = StringReplace(MemTableEh1->FieldByName("stoikost")->AsString,",",".",TReplaceFlags()<<rfReplaceAll).ToDouble();
				}
				catch(...) {
					ShowMessage("Проверьте поля Тмаш, Стойкость, Ку\nТам должны быть только цифры");
					return;
				}
			}
			float calc = Tmax;
			calc /= (60 * stoikost);
			calc *= Ku;
			MemTableEh1->FieldByName("norm_calc")->AsFloat = calc;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit1Enter(TObject *Sender)
{
	//goto english charset in field " find 'shifr' "
	LoadKeyboardLayout(L"00000409", KLF_ACTIVATE);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::DBGridEh2ColEnter(TObject *Sender)
{
	if(DBGridEh2->SelectedIndex == 7) {
		//goto russian charset in field 'material'
		LoadKeyboardLayout(L"00000419", KLF_ACTIVATE);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
//print 'shifr'
	ToPrint(DBGridEh2,1);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::bPrintShifrsClick(TObject *Sender)
{
//print all 'shifrs'
	ToPrint(DBGridEh1,0);
}
//---------------------------------------------------------------------------
void ToPrint(TDBGridEh *table, int OrientationLandscape)
{
	if(Form2->PrintDialog1->Execute()) {
		Printer()->Canvas->Font->Name = "Courier new";
		Printer()->Canvas->Font->Size = 10;
		Form2->PrintDBGridEh1->PageHeader->CenterText->Clear();
		if( OrientationLandscape ) {
			Printer()->Orientation = poLandscape;
			Form2->PrintDBGridEh1->Options = TPrintDBGridEhOptions(0x7);
			Form2->PrintDBGridEh1->PageHeader->CenterText->Add("Информация о шифре: "+Form2->ADOshifrs->FieldByName("shifr")->AsString);
		}
		else {
			Printer()->Orientation = poPortrait;
			Form2->PrintDBGridEh1->Options = TPrintDBGridEhOptions(0x1D);
			Form2->CanGo = 0;
		}
		Form2->PrintDBGridEh1->DBGridEh = table;
		Form2->PrintDBGridEh1->Print();
		Form2->CanGo = 1;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit_dseKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == 13) {
		//filter by 'ДСЕ'
		ADOshifrs->Close();
		if(Edit_dse->Text != "")
			ADOshifrs->SQL->Strings[22] = " (info.dse Like \'"+Edit_dse->Text+"\') AND ";
		else
			ADOshifrs->SQL->Strings[22] = " ";
		ADOshifrs->Open();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::SpeedButton6Click(TObject *Sender)
{
	//delete filter by 'chex'
	Edit_dse->Text = "";
	unsigned short key = 13;
	this->Edit_dseKeyDown(Sender,key,TShiftState());
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ADOinfoBeforePost(TDataSet *DataSet)
{
	if(ado_post == 1) {
		ADOinfo->Cancel();
		ado_post = 0;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ADOinfoPostError(TDataSet *DataSet, EDatabaseError *E, TDataAction &Action)
{
	Action = daAbort;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::DBGridEh2DataGroupFooterAggregateValue(TCustomDBGridEh *Grid,
          TColumnEh *Column, TGridDataGroupFooterEh *GroupFooter, TGridDataGroupFooterColumnItemEh *FooterColumnItem,
          Variant &AValue, TGroupDataTreeNodeEh *Node,
          bool &Processed)
{
	//calc sum only for non-colored(non-grey) fields
	//and which have 'srok' > Date()
	if(AValue.IsEmpty()) AValue = double(0);
	if((Column->Index >= 8) || (Column->Index <= 10)) {
		if(( MemTableEh1srok->IsNull ) || ( MemTableEh1srok->Value > Date() )) {
			if(MemTableEh1flag->Value != 1) {
				AValue += Column->Field->AsFloat;
			}
		}
	}
	Processed = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button_reportClick(TObject *Sender)
{
	Form_dse_report->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::DBGridEh2GetCellParams(TObject *Sender, TColumnEh *Column,
		  TFont *AFont, TColor &Background, Gridseh::TGridDrawState State)
{
//if instrument has lifetime - it will be colored
	if( !MemTableEh1->FieldByName("srok")->AsString.IsEmpty() ) {
		if( MemTableEh1->FieldByName("srok")->AsDateTime > Date() )
			Background = 0xFFE4FF;
		else
			Background = 0x8F95FE;
	}
//Darker 'shifrs' which are removed from operations
//OR info`s record is the old version
	if( !MemTableEh1->FieldByName("date_drop")->AsString.IsEmpty() ||
		(MemTableEh1->FieldByName("flag")->AsInteger == 1)) {
		Background = 0xD8D8D8;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::DBGridEh1GetCellParams(TObject *Sender, TColumnEh *Column,
		  TFont *AFont, TColor &Background, Gridseh::TGridDrawState State)
{
//old 'shifrs' must be filled by gray color
	if((ADOshifrs->FieldByName("flag")->AsInteger == 1)  && (userRules == 1)) {
		Background = cl3DLight;
	}
//new 'shifrs' have yellow color
	if(userRules == 1)
	 if((ADOshifrs->FieldByName("flag")->AsInteger == 2)) {
		Background = 0x71FEF6;
	 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N_report_dseClick(TObject *Sender)
{
	Button_report->Click();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N_report_duplicateClick(TObject *Sender)
{
//show report about duplicate of operations
	F_duplicate->MemTableEh1->Close();
	F_duplicate->MemTableEh1->Open();
	F_duplicate->ShowModal();
}
//---------------------------------------------------------------------------
void TForm2::Refresh()
{
    int pos = ADOshifrs->RecNo;
	ADOshifrs->Close();
	ADOshifrs->Open();
	if(pos > 0)
		ADOshifrs->RecNo = pos;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N4Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::DBGridEh1DblClick(TObject *Sender)
{
	if(userRules != 2) return;
//fill 'deliver' in the selected 'shifr'
	Form3bpi->Label1->Caption = "Выбран " + ADOshifrsshifr->Value + ":";
	Form3bpi->Edit1->Text = ADOshifrskod->Value;
	Form3bpi->DBLookupComboboxEh1->KeyValue = ADOshifrspostav->Value;
	Form3bpi->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::DBGridEh2DblClick(TObject *Sender)
{
//open history of the 'shifr' changes
	Form7->Label3->Caption = "История изменений выбранного шифра "+ADOshifrsshifr->Value+":";
	Form7->MemTableEh1->Close();
	Form7->ADOinfo->SQL->Clear();
	Form7->ADOinfo->SQL->Add("SELECT * FROM info WHERE num_shifr = "+AnsiString(ADOshifrsid->Value)+" ORDER BY chex, Nlim_kart, dse, num_op, id desc;");
	Form7->MemTableEh1->Open();
	Form7->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
	MemTableEh1->Edit();
	MemTableEh1flag->Value = 0;
	MemTableEh1->Post();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::DBEditMaterialExit(TObject *Sender)
{
//apply changes in 'material' of 'shifr' when exit from element
	if( ADOshifrs->State == dsEdit ) {
		ADOshifrs->Post();
	}
}
//---------------------------------------------------------------------------

