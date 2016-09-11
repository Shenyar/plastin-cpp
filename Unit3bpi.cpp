//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3bpi.h"
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBCtrlsEh"
#pragma link "DBGridEh"
#pragma link "DBLookupEh"
#pragma resource "*.dfm"
TForm3bpi *Form3bpi;
//---------------------------------------------------------------------------
__fastcall TForm3bpi::TForm3bpi(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3bpi::Button2Click(TObject *Sender)
{
//cancel changes
	this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm3bpi::Button1Click(TObject *Sender)
{
//save changes
	AnsiString kod = Edit1->Text.SubString(1,25),
				postav = DBLookupComboboxEh1->KeyValue;
	Form2->ADOtemp->Close();
	Form2->ADOtemp->SQL->Clear();
	Form2->ADOtemp->SQL->Add("UPDATE shifrs SET shifrs.kod = \'"+kod+"\', shifrs.postav = "+postav+" WHERE shifrs.id = "+Form2->ADOshifrsid->AsString+";");
	Form2->ADOtemp->ExecSQL();
	Form2->Refresh();
	this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm3bpi::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == 13) {
        this->DBLookupComboboxEh1->SetFocus();
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm3bpi::DBLookupComboboxEh1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift)
{
	if(Key == 13) {
        this->Button1Click(Sender);
    }
}
//---------------------------------------------------------------------------
