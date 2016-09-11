object F_duplicate: TF_duplicate
  Left = 0
  Top = 0
  ActiveControl = DBGridEh1
  Caption = #1054#1090#1095#1077#1090' '#1087#1086' '#1076#1091#1073#1083#1080#1082#1072#1090#1072#1084
  ClientHeight = 600
  ClientWidth = 1000
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  DesignSize = (
    1000
    600)
  PixelsPerInch = 96
  TextHeight = 19
  object DBGridEh1: TDBGridEh
    Left = 8
    Top = 44
    Width = 984
    Height = 548
    Anchors = [akLeft, akTop, akRight, akBottom]
    AutoFitColWidths = True
    DataGrouping.Active = True
    DataGrouping.GroupLevels = <
      item
        Color = clSkyBlue
        ColumnName = 'Column_0_chex'
        ParentColor = False
      end
      item
        Color = clActiveCaption
        ColumnName = 'Column_1_dse'
        ParentColor = False
      end>
    DataGrouping.DefaultStateExpanded = True
    DataSource = DataSource1
    DynProps = <>
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    IndicatorOptions = [gioShowRowIndicatorEh]
    ParentFont = False
    ReadOnly = True
    TabOrder = 0
    TitleParams.Font.Charset = DEFAULT_CHARSET
    TitleParams.Font.Color = clWindowText
    TitleParams.Font.Height = -16
    TitleParams.Font.Name = 'Tahoma'
    TitleParams.Font.Style = []
    TitleParams.MultiTitle = True
    TitleParams.ParentFont = False
    OnDblClick = DBGridEh1DblClick
    Columns = <
      item
        Alignment = taCenter
        DynProps = <>
        EditButtons = <>
        FieldName = 'chex'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        Footers = <>
        Title.Caption = #8470' '#1094#1077#1093#1072
        Width = 50
      end
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'dse'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        Footers = <>
        Title.Caption = #1044#1057#1045
        Width = 140
      end
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'num_op'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        Footers = <>
        Title.Caption = #8470' '#1086#1087#1077#1088#1072#1094#1080#1080
        Width = 75
      end
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'shifr'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        Footers = <>
        Title.Caption = #1064#1080#1092#1088' '#1080#1085#1089#1090#1088#1091#1084#1077#1085#1090#1072
        Width = 240
      end
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'Nlim_kart'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        Footers = <>
        Title.Caption = #8470' '#1083#1080#1084#1080#1090#1085#1086#1081' '#1082#1072#1088#1090#1099
        Width = 80
      end
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'Tmax'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        Footers = <>
        Title.Caption = #1058#1084#1072#1096'.'
        Width = 60
      end
      item
        Color = clInfoBk
        DisplayFormat = '0.##'
        DynProps = <>
        EditButtons = <>
        FieldName = 'norm_l'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        Footers = <>
        Title.Caption = #1053#1086#1088#1084#1099' '#1088#1072#1089#1093#1086#1076#1072'|'#1051
        Width = 60
      end
      item
        Color = clInfoBk
        DisplayFormat = '0.##'
        DynProps = <>
        EditButtons = <>
        FieldName = 'norm_o'
        Footers = <>
        Title.Caption = #1053#1086#1088#1084#1099' '#1088#1072#1089#1093#1086#1076#1072'|'#1054
        Width = 60
      end
      item
        Color = clInfoBk
        DisplayFormat = '0.##'
        DynProps = <>
        EditButtons = <>
        FieldName = 'norm'
        Footers = <>
        Title.Caption = #1053#1086#1088#1084#1099' '#1088#1072#1089#1093#1086#1076#1072'|'#1053'./'#1056'.'
        Width = 60
      end
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'date_doc'
        Footers = <>
        Title.Caption = #1044#1072#1090#1072' '#1087#1088#1077#1076#1086#1089#1090#1072#1074#1083#1077#1085#1080#1103' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074
        Width = 120
      end>
    object RowDetailData: TRowDetailPanelControlEh
    end
  end
  object Button1: TButton
    Left = 8
    Top = 8
    Width = 95
    Height = 30
    Caption = #1055#1077#1095#1072#1090#1100
    TabOrder = 1
  end
  object DBEditEh1: TDBEditEh
    Left = 832
    Top = 8
    Width = 144
    Height = 27
    DataField = 'date_doc'
    DataSource = DataSourceField
    DynProps = <>
    EditButtons = <>
    TabOrder = 2
    Visible = False
    OnExit = DBEditEh1Exit
    OnKeyDown = DBEditEh1KeyDown
  end
  object ADOQuery1: TADOQuery
    Active = True
    Connection = Form1.ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM ['#1054#1090#1095#1077#1090'_'#1086'_'#1076#1091#1073#1083#1080#1082#1072#1090#1072#1093'];')
    Left = 72
    Top = 136
  end
  object DataSource1: TDataSource
    DataSet = MemTableEh1
    Left = 208
    Top = 136
  end
  object DataSetDriverEh1: TDataSetDriverEh
    KeyFields = 'id'
    ProviderDataSet = ADOQuery1
    Left = 120
    Top = 136
  end
  object MemTableEh1: TMemTableEh
    Active = True
    FetchAllOnOpen = True
    Params = <>
    DataDriver = DataSetDriverEh1
    Left = 168
    Top = 136
  end
  object ADOfield: TADOQuery
    Connection = Form1.ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT info.id, info.date_doc FROM info'
      'WHERE info.id = 104;')
    Left = 440
    Top = 3
  end
  object DataSourceField: TDataSource
    DataSet = ADOfield
    Left = 480
    Top = 3
  end
end
