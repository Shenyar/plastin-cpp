//---------------------------------------------------------------------------

#ifndef Unit3bpiH
#define Unit3bpiH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "DBCtrlsEh.hpp"
#include <Vcl.Mask.hpp>
#include <Vcl.ComCtrls.hpp>
#include "DBGridEh.hpp"
#include "DBLookupEh.hpp"
//---------------------------------------------------------------------------
class TForm3bpi : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *Edit1;
	TButton *Button1;
	TButton *Button2;
	TLabel *Label2;
	TLabel *Label3;
	TDBLookupComboboxEh *DBLookupComboboxEh1;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall DBLookupComboboxEh1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);

private:	// User declarations
public:		// User declarations
	__fastcall TForm3bpi(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3bpi *Form3bpi;
//---------------------------------------------------------------------------
#endif
