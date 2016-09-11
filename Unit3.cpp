//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
//save changes
	if(Edit1->Text != "") {
		Form2->ADOtemp->Close();
		Form2->ADOtemp->SQL->Clear();
		Form2->ADOtemp->SQL->Add("UPDATE shifrs SET shifrs.shifr = \'"+Edit1->Text+"\' WHERE shifrs.id = "+Form2->ADOshifrsid->AsString+";");
		Form2->ADOtemp->ExecSQL();
		Form2->Refresh();
	}
	this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
//cancel changes
	this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
//goto save changes
	if(Key == VK_RETURN) this->Button1Click(Sender);
}
//---------------------------------------------------------------------------
