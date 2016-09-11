//---------------------------------------------------------------------------

#ifndef Unit7H
#define Unit7H
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
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm7 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label3;
	TADOQuery *ADOinfo;
	TDataSetDriverEh *DataSetDriverEh1;
	TMemTableEh *MemTableEh1;
	TAutoIncField *MemTableEh1id;
	TIntegerField *MemTableEh1num_shifr;
	TIntegerField *MemTableEh1chex;
	TWideStringField *MemTableEh1Nlim_kart;
	TWideStringField *MemTableEh1dse;
	TWideStringField *MemTableEh1marka;
	TWideStringField *MemTableEh1num_op;
	TWideStringField *MemTableEh1Tmax;
	TWideStringField *MemTableEh1kol_mest;
	TWideStringField *MemTableEh1kol_plast;
	TFloatField *MemTableEh1norm_l;
	TFloatField *MemTableEh1norm_o;
	TFloatField *MemTableEh1norm;
	TFloatField *MemTableEh1norm_u;
	TWideStringField *MemTableEh1stoikost;
	TFloatField *MemTableEh1Ku;
	TWideStringField *MemTableEh1act;
	TWideStringField *MemTableEh1date_drop;
	TWideStringField *MemTableEh1new_plast;
	TDateTimeField *MemTableEh1srok;
	TDateTimeField *MemTableEh1change_date;
	TWordField *MemTableEh1flag;
	TFloatField *MemTableEh1norm_calc;
	TDataSource *DataSource2;
	TDBGridEh *DBGridEh2;
	TDBNavigator *DBNavigator2;
	void __fastcall DBGridEh2DataGroupFooterAggregateValue(TCustomDBGridEh *Grid, TColumnEh *Column,
          TGridDataGroupFooterEh *GroupFooter, TGridDataGroupFooterColumnItemEh *FooterColumnItem,
          Variant &AValue, TGroupDataTreeNodeEh *Node,
          bool &Processed);
	void __fastcall DBGridEh2DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
		  TColumnEh *Column, Gridseh::TGridDrawState State);
	void __fastcall DBGridEh2GetCellParams(TObject *Sender, TColumnEh *Column, TFont *AFont,
          TColor &Background, Gridseh::TGridDrawState State);
private:	// User declarations
public:		// User declarations
	__fastcall TForm7(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm7 *Form7;
//---------------------------------------------------------------------------
#endif
