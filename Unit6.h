//---------------------------------------------------------------------------

#ifndef Unit6H
#define Unit6H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "DataDriverEh.hpp"
#include "DBAxisGridsEh.hpp"
#include "DBGridEh.hpp"
#include "DBGridEhGrouping.hpp"
#include "DBGridEhToolCtrls.hpp"
#include "DynVarsEh.hpp"
#include "EhLibVCL.hpp"
#include "GridsEh.hpp"
#include "MemTableDataEh.hpp"
#include "MemTableEh.hpp"
#include "ToolCtrlsEh.hpp"
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include "DBCtrlsEh.hpp"
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------
class TF_duplicate : public TForm
{
__published:	// IDE-managed Components
	TADOQuery *ADOQuery1;
	TDataSource *DataSource1;
	TDataSetDriverEh *DataSetDriverEh1;
	TMemTableEh *MemTableEh1;
	TDBGridEh *DBGridEh1;
	TButton *Button1;
	TDBEditEh *DBEditEh1;
	TADOQuery *ADOfield;
	TDataSource *DataSourceField;
	void __fastcall DBGridEh1DblClick(TObject *Sender);
	void __fastcall DBEditEh1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall DBEditEh1Exit(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TF_duplicate(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TF_duplicate *F_duplicate;
//---------------------------------------------------------------------------
#endif
