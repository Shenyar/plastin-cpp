//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
#include "Unit2.h"
#include "Unit1.h"
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
#pragma link "DBCtrlsEh"
#pragma resource "*.dfm"
TF_duplicate *F_duplicate;
//---------------------------------------------------------------------------
__fastcall TF_duplicate::TF_duplicate(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TF_duplicate::DBGridEh1DblClick(TObject *Sender)
{
//open field for changing date (info.date_doc)
	if(DBGridEh1->SelectedIndex == 9) {
		this->ADOfield->Close();
		this->ADOfield->SQL->Strings[1] = "WHERE info.id = "+MemTableEh1->FieldByName("id")->AsString+";";
		this->ADOfield->Open();
		this->DBEditEh1->Visible = true;
		this->DBEditEh1->SetFocus();
    }
}
//---------------------------------------------------------------------------
void __fastcall TF_duplicate::DBEditEh1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
//if 'enter' was pressed -> save changes
	if(Key == 13) {
		this->ADOfield->Edit();
		this->ADOfield->Post();
		this->DBEditEh1Exit(Sender);
	}
	else //or discard changes if pressed `esc`
	if(Key == VK_ESCAPE) {
        this->DBEditEh1Exit(Sender);
    }
}
//---------------------------------------------------------------------------
void __fastcall TF_duplicate::DBEditEh1Exit(TObject *Sender)
{
//hide field after date was changed
	this->ADOfield->Close();
	this->DBGridEh1->SetFocus();
	this->DBEditEh1->Visible = false;
	int recno = MemTableEh1->RecNo;
	MemTableEh1->Close();
	MemTableEh1->Open();
	MemTableEh1->RecNo = recno;
}
//---------------------------------------------------------------------------

