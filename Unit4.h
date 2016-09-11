//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "DBAxisGridsEh.hpp"
#include "DBGridEh.hpp"
#include "DBGridEhGrouping.hpp"
#include "DBGridEhToolCtrls.hpp"
#include "DynVarsEh.hpp"
#include "EhLibVCL.hpp"
#include "GridsEh.hpp"
#include "ToolCtrlsEh.hpp"
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include "DataDriverEh.hpp"
#include "MemTableDataEh.hpp"
#include "MemTableEh.hpp"
//---------------------------------------------------------------------------
class TF_DSE : public TForm
{
__published:	// IDE-managed Components
	TDBGridEh *DBGridEh1;
	TADOQuery *ADOdse;
	TDataSource *DataSource1;
	TButton *Button1;
	TDataSetDriverEh *DataSetDriverEh1;
	TMemTableEh *MemTableEh1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TF_DSE(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TF_DSE *F_DSE;
//---------------------------------------------------------------------------
#endif
