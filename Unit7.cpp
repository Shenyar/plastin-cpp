//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit7.h"
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
#pragma resource "*.dfm"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
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
void __fastcall TForm7::DBGridEh2DataGroupFooterAggregateValue(TCustomDBGridEh *Grid,
          TColumnEh *Column, TGridDataGroupFooterEh *GroupFooter, TGridDataGroupFooterColumnItemEh *FooterColumnItem,
          Variant &AValue, TGroupDataTreeNodeEh *Node,
          bool &Processed)
{
	//calc sum only for non-colored(non-grey) fields
	//and which have 'srok' > Date()
	if(AValue.IsEmpty()) AValue = double(0);
	if((Column->Index == 8) || (Column->Index == 10)) {
		if(( MemTableEh1srok->IsNull ) || ( MemTableEh1srok->Value > Date() )) {
			if(MemTableEh1flag->Value != 1) {
				AValue += Column->Field->AsFloat;
			}
		}
	}
	Processed = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm7::DBGridEh2DrawColumnCell(TObject *Sender, const TRect &Rect,
		  int DataCol, TColumnEh *Column, Gridseh::TGridDrawState State)
{
//left and right border of "Норм расхода" - bold line
    if((DataCol == 7) || (DataCol == 11) || (DataCol == 12)) {
		TColor color = Form2->DBGridEh1->Canvas->Pen->Color;
		DBGridEh2->Canvas->Pen->Color = clBlack;
        DBGridEh2->Canvas->MoveTo(Rect.Right,Rect.Top);
		DBGridEh2->Canvas->LineTo(Rect.Right,Rect.Bottom);
		DBGridEh2->Canvas->Pen->Color = color;
        DBGridEh2->Canvas->Pen->Width = 1;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm7::DBGridEh2GetCellParams(TObject *Sender, TColumnEh *Column,
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
