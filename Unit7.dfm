object Form7: TForm7
  Left = 0
  Top = 0
  ActiveControl = DBGridEh2
  Caption = #1048#1089#1090#1086#1088#1080#1103' '#1080#1079#1084#1077#1085#1077#1085#1080#1081
  ClientHeight = 617
  ClientWidth = 1023
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  DesignSize = (
    1023
    617)
  PixelsPerInch = 96
  TextHeight = 13
  object Label3: TLabel
    Left = 19
    Top = 3
    Width = 376
    Height = 23
    Caption = #1048#1089#1090#1086#1088#1080#1103' '#1080#1079#1084#1077#1085#1077#1085#1080#1081' '#1074#1099#1073#1088#1072#1085#1085#1086#1075#1086' '#1096#1080#1092#1088#1072' '#1059':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object DBGridEh2: TDBGridEh
    Left = 8
    Top = 32
    Width = 1007
    Height = 546
    AllowedSelections = [gstAll]
    Anchors = [akLeft, akTop, akRight, akBottom]
    AutoFitColWidths = True
    DataGrouping.Active = True
    DataGrouping.Color = clFuchsia
    DataGrouping.GroupLevels = <
      item
        ColumnName = 'Column_0_chex'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end>
    DataGrouping.Footers = <
      item
        Color = clMoneyGreen
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        Visible = True
        ColumnItems = <
          item
          end
          item
          end
          item
          end
          item
          end
          item
          end
          item
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
          item
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
          item
          end
          item
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            ValueType = gfvSumEh
          end
          item
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
          item
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            ValueType = gfvSumEh
          end
          item
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
          item
          end
          item
          end
          item
          end
          item
          end
          item
          end
          item
          end
          item
          end>
        ParentColor = False
        ParentFont = False
        ShowFunctionName = False
        RunTimeCustomizable = False
      end>
    DataGrouping.ParentColor = False
    DataGrouping.DefaultStateExpanded = True
    DataGrouping.ShiftFolldataGroupRow = False
    DataSource = DataSource2
    DynProps = <>
    EditActions = [geaCutEh, geaCopyEh, geaPasteEh, geaDeleteEh, geaSelectAllEh]
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    FooterParams.Font.Charset = DEFAULT_CHARSET
    FooterParams.Font.Color = clWindowText
    FooterParams.Font.Height = -13
    FooterParams.Font.Name = 'Tahoma'
    FooterParams.Font.Style = []
    FooterParams.ParentFont = False
    IndicatorOptions = [gioShowRowIndicatorEh]
    Options = [dgEditing, dgTitles, dgIndicator, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit, dgMultiSelect]
    OptionsEh = [dghFixed3D, dghHighlightFocus, dghClearSelection, dghEnterAsTab, dghDialogFind, dghColumnResize, dghExtendVertLines]
    ParentFont = False
    ParentShowHint = False
    ReadOnly = True
    ShowHint = True
    STFilter.Font.Charset = DEFAULT_CHARSET
    STFilter.Font.Color = clBlue
    STFilter.Font.Height = -11
    STFilter.Font.Name = 'Tahoma'
    STFilter.Font.Style = []
    STFilter.ParentFont = False
    TabOrder = 0
    TitleParams.Font.Charset = DEFAULT_CHARSET
    TitleParams.Font.Color = clWindowText
    TitleParams.Font.Height = -11
    TitleParams.Font.Name = 'Tahoma'
    TitleParams.Font.Style = [fsBold]
    TitleParams.MultiTitle = True
    TitleParams.ParentFont = False
    VertScrollBar.VisibleMode = sbAlwaysShowEh
    OnDataGroupFooterAggregateValue = DBGridEh2DataGroupFooterAggregateValue
    OnDrawColumnCell = DBGridEh2DrawColumnCell
    OnGetCellParams = DBGridEh2GetCellParams
    Columns = <
      item
        DropDownSpecRow.Font.Charset = DEFAULT_CHARSET
        DropDownSpecRow.Font.Color = clWindowText
        DropDownSpecRow.Font.Height = -11
        DropDownSpecRow.Font.Name = 'Tahoma'
        DropDownSpecRow.Font.Style = []
        DynProps = <>
        EditButtons = <>
        EndEllipsis = True
        FieldName = 'chex'
        Footers = <>
        Title.Caption = #1062#1077#1093' '#1087#1086#1090#1088#1077#1073#1080#1090#1077#1083#1100
        Width = 55
      end
      item
        DynProps = <>
        EditButtons = <>
        EndEllipsis = True
        FieldName = 'Nlim_kart'
        Footers = <>
        Title.Caption = #8470' '#1083#1080#1084#1080#1090#1085#1086#1081' '#1082#1072#1088#1090#1099
        Width = 58
      end
      item
        DynProps = <>
        EditButtons = <>
        EndEllipsis = True
        FieldName = 'dse'
        Footers = <>
        Title.Caption = #1044#1057#1045
        Width = 90
      end
      item
        Alignment = taRightJustify
        DynProps = <>
        EditButtons = <>
        EndEllipsis = True
        FieldName = 'num_op'
        Footers = <>
        Title.Caption = #8470' '#1086#1087#1077#1088#1072'- '#1094#1080#1080
        Width = 42
      end
      item
        Alignment = taRightJustify
        DynProps = <>
        EditButtons = <>
        EndEllipsis = True
        FieldName = 'Tmax'
        Footers = <>
        Title.Caption = #1058#1084#1072#1096'.'
        Width = 40
      end
      item
        Alignment = taRightJustify
        DynProps = <>
        EditButtons = <>
        EndEllipsis = True
        FieldName = 'kol_mest'
        Footers = <>
        Title.Caption = #1050#1086#1083'-'#1074#1086' '#1088#1072#1073#1086#1095#1080#1093' '#1084#1077#1089#1090
        Width = 55
      end
      item
        Alignment = taRightJustify
        DynProps = <>
        EditButtons = <>
        EndEllipsis = True
        FieldName = 'kol_plast'
        Footer.Alignment = taRightJustify
        Footers = <>
        Title.Caption = #1050#1086#1083'-'#1074#1086' '#1086#1076#1085#1086#1074#1088'. '#1080#1089#1087#1086#1083#1100#1079'. '#1087#1083#1072#1089#1090#1080#1085
        Width = 55
      end
      item
        DynProps = <>
        EditButtons = <>
        EndEllipsis = True
        FieldName = 'marka'
        Footers = <>
        Title.Caption = #1052#1072#1088#1082#1072' '#1086#1073#1088'. '#1084#1072#1090#1077#1088#1080#1072#1083#1072
        Width = 70
      end
      item
        Color = clInfoBk
        DisplayFormat = '0.##'
        DynProps = <>
        EditButtons = <>
        EndEllipsis = True
        FieldName = 'norm_l'
        Footers = <>
        Title.Caption = #1053#1086#1088#1084#1099' '#1088#1072#1089#1093#1086#1076#1072'|'#1051
        Width = 35
        WordWrap = True
      end
      item
        Color = clInfoBk
        DisplayFormat = '0.##'
        DynProps = <>
        EditButtons = <>
        EndEllipsis = True
        FieldName = 'norm_o'
        Footers = <>
        Title.Caption = #1053#1086#1088#1084#1099' '#1088#1072#1089#1093#1086#1076#1072'|'#1054
        Width = 35
        WordWrap = True
      end
      item
        Color = clInfoBk
        DisplayFormat = '0.##'
        DynProps = <>
        EditButtons = <>
        EndEllipsis = True
        FieldName = 'norm'
        Footers = <>
        Title.Caption = #1053#1086#1088#1084#1099' '#1088#1072#1089#1093#1086#1076#1072'|'#1053'./'#1056'.'
        Width = 45
        WordWrap = True
      end
      item
        Color = clInfoBk
        DisplayFormat = '0.####'
        DropDownSpecRow.Font.Charset = DEFAULT_CHARSET
        DropDownSpecRow.Font.Color = clWindowText
        DropDownSpecRow.Font.Height = -11
        DropDownSpecRow.Font.Name = 'Tahoma'
        DropDownSpecRow.Font.Style = []
        DynProps = <>
        EditButtons = <>
        EndEllipsis = True
        FieldName = 'norm_calc'
        Footers = <>
        Title.Caption = #1053#1086#1088#1084#1099' '#1088#1072#1089#1093#1086#1076#1072'|'#1059#1076#1077#1083#1100'- '#1085#1099#1081
        Width = 45
        WordWrap = True
      end
      item
        Color = clFuchsia
        DropDownSpecRow.Font.Charset = DEFAULT_CHARSET
        DropDownSpecRow.Font.Color = clWindowText
        DropDownSpecRow.Font.Height = -11
        DropDownSpecRow.Font.Name = 'Tahoma'
        DropDownSpecRow.Font.Style = []
        DynProps = <>
        EditButtons = <>
        EndEllipsis = True
        FieldName = 'srok'
        Footers = <>
        Title.Caption = #1053#1086#1088#1084#1099' '#1088#1072#1089#1093#1086#1076#1072'|'#1057#1088#1086#1082' '#1076#1077#1081#1089#1090#1074#1080#1103
        Width = 68
      end
      item
        Alignment = taRightJustify
        DynProps = <>
        EditButtons = <>
        EndEllipsis = True
        FieldName = 'stoikost'
        Footers = <>
        Title.Caption = #1057#1090#1086#1081#1082#1086#1089'. '#1058#1089#1090'. ('#1095'.)'
        Width = 55
      end
      item
        DisplayFormat = '0.####'
        DynProps = <>
        EditButtons = <>
        EndEllipsis = True
        FieldName = 'Ku'
        Footers = <>
        Title.Caption = #1050#1091
        Width = 40
      end
      item
        DynProps = <>
        EditButtons = <>
        EndEllipsis = True
        FieldName = 'act'
        Footers = <>
        Title.Caption = #1053#1072#1083#1080#1095#1080#1077' '#1072#1082#1090#1072
        Width = 90
      end
      item
        DynProps = <>
        EditButtons = <>
        EndEllipsis = True
        FieldName = 'date_drop'
        Footers = <>
        Title.Caption = #1054#1089#1085#1086#1074#1072#1085#1080#1077' '#1080' '#1076#1072#1090#1072' '#1080#1079#1084#1077#1085#1077#1085#1080#1103' '#1085#1086#1088#1084' '#1088#1072#1089#1093#1086#1076#1072
        Width = 120
      end
      item
        DynProps = <>
        EditButtons = <>
        EndEllipsis = True
        FieldName = 'new_plast'
        Footers = <>
        Title.Caption = #1042#1085#1086#1074#1100' '#1074#1074#1086#1076#1080#1084#1099#1081' '#1096#1080#1092#1088
        Width = 105
      end
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'change_date'
        Footers = <>
        Title.Caption = #1044#1072#1090#1072' '#1080#1079#1084#1077#1085#1077#1085#1080#1103
        Width = 80
      end>
    object RowDetailData: TRowDetailPanelControlEh
    end
  end
  object DBNavigator2: TDBNavigator
    Left = 19
    Top = 584
    Width = 140
    Height = 25
    DataSource = DataSource2
    VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
    Anchors = [akLeft, akBottom]
    TabOrder = 1
  end
  object ADOinfo: TADOQuery
    Connection = Form1.ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select * from info;')
    Left = 175
    Top = 144
  end
  object DataSetDriverEh1: TDataSetDriverEh
    KeyFields = 'id'
    ProviderDataSet = ADOinfo
    Left = 239
    Top = 144
  end
  object MemTableEh1: TMemTableEh
    FetchAllOnOpen = True
    Params = <>
    DataDriver = DataSetDriverEh1
    Left = 295
    Top = 144
    object MemTableEh1id: TAutoIncField
      FieldName = 'id'
    end
    object MemTableEh1num_shifr: TIntegerField
      FieldName = 'num_shifr'
    end
    object MemTableEh1chex: TIntegerField
      FieldName = 'chex'
    end
    object MemTableEh1Nlim_kart: TWideStringField
      FieldName = 'Nlim_kart'
      Size = 15
    end
    object MemTableEh1dse: TWideStringField
      FieldName = 'dse'
      Size = 25
    end
    object MemTableEh1marka: TWideStringField
      FieldName = 'marka'
      Size = 25
    end
    object MemTableEh1num_op: TWideStringField
      FieldName = 'num_op'
      Size = 10
    end
    object MemTableEh1Tmax: TWideStringField
      FieldName = 'Tmax'
      Size = 10
    end
    object MemTableEh1kol_mest: TWideStringField
      FieldName = 'kol_mest'
      Size = 10
    end
    object MemTableEh1kol_plast: TWideStringField
      FieldName = 'kol_plast'
      Size = 10
    end
    object MemTableEh1norm_l: TFloatField
      FieldName = 'norm_l'
    end
    object MemTableEh1norm_o: TFloatField
      FieldName = 'norm_o'
    end
    object MemTableEh1norm: TFloatField
      FieldName = 'norm'
    end
    object MemTableEh1norm_u: TFloatField
      FieldName = 'norm_u'
    end
    object MemTableEh1stoikost: TWideStringField
      FieldName = 'stoikost'
      Size = 10
    end
    object MemTableEh1Ku: TFloatField
      FieldName = 'Ku'
    end
    object MemTableEh1act: TWideStringField
      FieldName = 'act'
    end
    object MemTableEh1date_drop: TWideStringField
      FieldName = 'date_drop'
      Size = 40
    end
    object MemTableEh1new_plast: TWideStringField
      FieldName = 'new_plast'
      Size = 40
    end
    object MemTableEh1srok: TDateTimeField
      FieldName = 'srok'
    end
    object MemTableEh1change_date: TDateTimeField
      FieldName = 'change_date'
    end
    object MemTableEh1flag: TWordField
      DefaultExpression = '0'
      FieldName = 'flag'
    end
    object MemTableEh1norm_calc: TFloatField
      FieldKind = fkCalculated
      FieldName = 'norm_calc'
      Calculated = True
    end
  end
  object DataSource2: TDataSource
    DataSet = MemTableEh1
    Left = 351
    Top = 144
  end
end
