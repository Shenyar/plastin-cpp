//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
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
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Dialogs.hpp>
#include "PrnDbgeh.hpp"
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.StdActns.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include "DBCtrlsEh.hpp"
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TADOQuery *ADOshifrs;
	TDBGridEh *DBGridEh1;
	TDBGridEh *DBGridEh2;
	TDataSource *DataSource1;
	TDBNavigator *DBNavigator1;
	TDBNavigator *DBNavigator2;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TToolBar *ToolBar1;
	TLabel *Label4;
	TEdit *Edit1;
	TShape *Shape1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton4;
	TShape *Shape2;
	TButton *Button1;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N7;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *N11;
	TADOQuery *ADOtemp;
	TColorDialog *ColorDialog1;
	TMenuItem *N12;
	TMenuItem *N13;
	TPrintDBGridEh *PrintDBGridEh1;
	TPrintDialog *PrintDialog1;
	TActionList *ActionList1;
	TMenuItem *N14;
	TMenuItem *N15;
	TLabel *Label5;
	TShape *Shape3;
	TEdit *Edit2;
	TSpeedButton *SpeedButton5;
	TDataSource *DataSource2;
	TADOQuery *ADOinfo;
	TDataSetDriverEh *DataSetDriverEh1;
	TMemTableEh *MemTableEh1;
	TADOQuery *ADOname_delivery;
	TButton *Button2;
	TSpeedButton *bPrintShifrs;
	TShape *Shape4;
	TLabel *Label6;
	TEdit *Edit_dse;
	TSpeedButton *SpeedButton6;
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
	TButton *Button_report;
	TMenuItem *N6;
	TMenuItem *N_report_dse;
	TMenuItem *N_report_duplicate;
	TDataSource *DataSourceDelivery;
	TButton *Button3;
	TAutoIncField *ADOshifrsid;
	TWideStringField *ADOshifrsshifr;
	TWordField *ADOshifrsflag;
	TFloatField *ADOshifrss_norm;
	TDateTimeField *ADOshifrsdate_in;
	TWideStringField *ADOshifrsnaim;
	TWideStringField *ADOshifrskod;
	TIntegerField *ADOshifrsnpp;
	TIntegerField *ADOshifrspostav;
	TWideStringField *ADOshifrsmaterial;
	TDBEditEh *DBEditMaterial;
	TLabel *Label7;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ADOshifrsCalcFields(TDataSet *DataSet);
	void __fastcall ADOshifrsAfterScroll(TDataSet *DataSet);
	void __fastcall DBGridEh1DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
		  TColumnEh *Column, Gridseh::TGridDrawState State);
	void __fastcall Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall DBGridEh2DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
		  TColumnEh *Column, Gridseh::TGridDrawState State);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall N11Click(TObject *Sender);
	void __fastcall MemTableEh1AfterInsert(TDataSet *DataSet);
	void __fastcall MemTableEh1BeforeInsert(TDataSet *DataSet);
	void __fastcall DBGridEh1Exit(TObject *Sender);
	void __fastcall N12Click(TObject *Sender);
	void __fastcall N13Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall N7Click(TObject *Sender);
	void __fastcall N8Click(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall DBNavigator2Click(TObject *Sender, TNavigateBtn Button);
	void __fastcall N15Click(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall DBGridEh2KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall DBGridEh2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall DBGridEh2MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall ADOshifrsPostError(TDataSet *DataSet, EDatabaseError *E, TDataAction &Action);
	void __fastcall MemTableEh1AfterPost(TDataSet *DataSet);
	void __fastcall Edit2KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall SpeedButton5Click(TObject *Sender);
	void __fastcall DBGridEh2HintShowPause(TCustomDBGridEh *Sender, TPoint &CursorPos,
          Gridseh::TGridCoord &Cell, TPoint &InCellCursorPos, TColumnEh *Column, int &HintPause,
		  bool &Processed);
	void __fastcall MemTableEh1BeforePost(TDataSet *DataSet);
	void __fastcall MemTableEh1CalcFields(TDataSet *DataSet);
	void __fastcall Edit1Enter(TObject *Sender);
	void __fastcall DBGridEh2ColEnter(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall bPrintShifrsClick(TObject *Sender);
	void __fastcall Edit_dseKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall SpeedButton6Click(TObject *Sender);
	void __fastcall ADOinfoBeforePost(TDataSet *DataSet);
	void __fastcall ADOinfoPostError(TDataSet *DataSet, EDatabaseError *E, TDataAction &Action);
	void __fastcall DBGridEh2DataGroupFooterAggregateValue(TCustomDBGridEh *Grid, TColumnEh *Column,
          TGridDataGroupFooterEh *GroupFooter, TGridDataGroupFooterColumnItemEh *FooterColumnItem,
          Variant &AValue, TGroupDataTreeNodeEh *Node,
          bool &Processed);
	void __fastcall Button_reportClick(TObject *Sender);
	void __fastcall DBGridEh2GetCellParams(TObject *Sender, TColumnEh *Column, TFont *AFont,
		  TColor &Background, Gridseh::TGridDrawState State);
	void __fastcall DBGridEh1GetCellParams(TObject *Sender, TColumnEh *Column, TFont *AFont,
          TColor &Background, Gridseh::TGridDrawState State);
	void __fastcall N_report_dseClick(TObject *Sender);
	void __fastcall N_report_duplicateClick(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall DBGridEh1DblClick(TObject *Sender);
	void __fastcall DBGridEh2DblClick(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall DBEditMaterialExit(TObject *Sender);



private:	// User declarations
public:		// User declarations
	void Refresh();
	friend void ToPrint(TDBGridEh *table, int OrientationLandscape);
	__fastcall TForm2(TComponent* Owner);
	int recno,go_dse,CanGo,mov_can,userRules,ado_post,dsInsertFlag;
	AnsiString Vold,Vnew,infoChex,infoDse,infoNlim;
	double numprev,numnext;
	UnicodeString mov;
	TDateTime now_date;
	UnicodeString old_info_record[20];
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
