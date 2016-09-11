object F_DSE: TF_DSE
  Left = 0
  Top = 0
  Caption = #1044#1057#1045' 101102103 '#1091#1078#1077' '#1089#1091#1097#1077#1089#1090#1074#1091#1077#1090' '#1074' '#1076#1088#1091#1075#1080#1093' '#1096#1080#1092#1088#1072#1093
  ClientHeight = 450
  ClientWidth = 650
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnShow = FormShow
  DesignSize = (
    650
    450)
  PixelsPerInch = 96
  TextHeight = 13
  object DBGridEh1: TDBGridEh
    Left = 8
    Top = 8
    Width = 634
    Height = 395
    Anchors = [akLeft, akTop, akRight, akBottom]
    AutoFitColWidths = True
    DataGrouping.Active = True
    DataGrouping.Font.Charset = DEFAULT_CHARSET
    DataGrouping.Font.Color = clWindowText
    DataGrouping.Font.Height = -13
    DataGrouping.Font.Name = 'Tahoma'
    DataGrouping.Font.Style = []
    DataGrouping.GroupLevels = <
      item
        Color = clInfoBk
        ColumnName = 'Column_0_shifr'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentColor = False
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
          end
          item
          end
          item
          end
          item
          end
          item
            DisplayFormat = '0.##'
            ValueType = gfvSumEh
          end
          item
          end
          item
          end>
        ParentColor = False
        ParentFont = False
      end>
    DataGrouping.ParentFont = False
    DataGrouping.DefaultStateExpanded = True
    DataSource = DataSource1
    DynProps = <>
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    IndicatorOptions = [gioShowRowIndicatorEh]
    ParentFont = False
    TabOrder = 0
    TitleParams.Font.Charset = DEFAULT_CHARSET
    TitleParams.Font.Color = clWindowText
    TitleParams.Font.Height = -11
    TitleParams.Font.Name = 'Tahoma'
    TitleParams.Font.Style = [fsBold]
    TitleParams.MultiTitle = True
    TitleParams.ParentFont = False
    VertScrollBar.VisibleMode = sbAlwaysShowEh
    Columns = <
      item
        DynProps = <>
        EditButtons = <>
        EndEllipsis = True
        FieldName = 'shifr'
        Footers = <>
        Title.Caption = #1064#1080#1092#1088
        Visible = False
        Width = 122
        WordWrap = False
      end
      item
        DynProps = <>
        EditButtons = <>
        EndEllipsis = True
        FieldName = 'chex'
        Footers = <>
        Title.Caption = #1062#1077#1093' '#1087#1086#1090#1088#1077#1073'.'
        Width = 55
        WordWrap = False
      end
      item
        DynProps = <>
        EditButtons = <>
        EndEllipsis = True
        FieldName = 'Nlim_kart'
        Footers = <>
        Title.Caption = #8470' '#1083#1080#1084#1080#1090#1085#1086#1081' '#1082#1072#1088#1090#1099
        Width = 58
        WordWrap = False
      end
      item
        DynProps = <>
        EditButtons = <>
        EndEllipsis = True
        FieldName = 'dse'
        Footers = <>
        Title.Caption = #1044#1057#1045
        Width = 80
        WordWrap = False
      end
      item
        DynProps = <>
        EditButtons = <>
        EndEllipsis = True
        FieldName = 'num_op'
        Footers = <>
        Title.Caption = #8470' '#1086#1087#1077#1088#1072'- '#1094#1080#1080
        Width = 42
        WordWrap = False
      end
      item
        DynProps = <>
        EditButtons = <>
        EndEllipsis = True
        FieldName = 'Tmax'
        Footers = <>
        Title.Caption = #1058#1084#1072#1096'.'
        Width = 40
        WordWrap = False
      end
      item
        DynProps = <>
        EditButtons = <>
        EndEllipsis = True
        FieldName = 'kol_mest'
        Footers = <>
        Title.Caption = #1050#1086#1083'-'#1074#1086' '#1088#1072#1073#1086#1095#1080#1093' '#1084#1077#1089#1090
        Width = 55
        WordWrap = False
      end
      item
        DynProps = <>
        EditButtons = <>
        EndEllipsis = True
        FieldName = 'kol_plast'
        Footers = <>
        Title.Caption = #1050#1086#1083'-'#1074#1086' '#1086#1076#1085#1086#1074#1088'. '#1080#1089#1087#1086#1083#1100#1079'. '#1087#1083#1072#1089#1090#1080#1085
        Width = 55
        WordWrap = False
      end
      item
        DynProps = <>
        EditButtons = <>
        EndEllipsis = True
        FieldName = 'marka'
        Footers = <>
        Title.Caption = #1052#1072#1088#1082#1072' '#1086#1073#1088'. '#1084#1072#1090#1077#1088#1080#1072#1083#1072
        Width = 70
        WordWrap = False
      end
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'norm_l'
        Footers = <>
        Title.Caption = #1053#1086#1088#1084#1099' '#1088#1072#1089#1093#1086#1076#1072'|'#1051
        Width = 30
      end
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'norm_o'
        Footers = <>
        Title.Caption = #1053#1086#1088#1084#1099' '#1088#1072#1089#1093#1086#1076#1072'|'#1054
        Width = 30
      end
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'srok'
        Footers = <>
        Title.Caption = #1053#1086#1088#1084#1099' '#1088#1072#1089#1093#1086#1076#1072'|'#1057#1088#1086#1082' '#1076#1077#1081#1089#1090#1074#1080#1103
        Width = 65
      end>
    object RowDetailData: TRowDetailPanelControlEh
    end
  end
  object Button1: TButton
    Left = 16
    Top = 409
    Width = 113
    Height = 34
    Anchors = [akLeft, akBottom]
    Caption = 'OK'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 1
    OnClick = Button1Click
  end
  object ADOdse: TADOQuery
    Connection = Form1.ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      
        'SELECT shifrs.shifr, info.dse, info.chex, info.num_op, info.Nlim' +
        '_kart, info.Tmax, info.kol_plast, info.kol_mest, info.marka, inf' +
        'o.id, shifrs.id, info.norm_l, info.norm_o, info.srok'
      'FROM shifrs INNER JOIN info ON (shifrs.id = info.num_shifr)'
      'WHERE'
      '(info.dse = '#39'101102103'#39')'
      'AND (info.num_op = '#39'1'#39')'
      'AND (info.chex = 45)'
      'AND (shifrs.shifr <> '#39'e1231'#39');')
    Left = 120
    Top = 208
  end
  object DataSource1: TDataSource
    DataSet = MemTableEh1
    Left = 288
    Top = 208
  end
  object DataSetDriverEh1: TDataSetDriverEh
    ProviderDataSet = ADOdse
    Left = 176
    Top = 208
  end
  object MemTableEh1: TMemTableEh
    FetchAllOnOpen = True
    Params = <>
    DataDriver = DataSetDriverEh1
    Left = 232
    Top = 208
  end
end
