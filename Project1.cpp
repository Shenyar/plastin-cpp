//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Unit3bpi.cpp", Form3bpi);
USEFORM("Unit3.cpp", Form3);
USEFORM("Unit4.cpp", F_DSE);
USEFORM("Unit6.cpp", F_duplicate);
USEFORM("Unit5.cpp", Form_dse_report);
USEFORM("Unit2.cpp", Form2);
USEFORM("Unit1.cpp", Form1);
USEFORM("Unit7.cpp", Form7);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		//Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TForm2), &Form2);
		Application->CreateForm(__classid(TForm3), &Form3);
		Application->CreateForm(__classid(TF_DSE), &F_DSE);
		Application->CreateForm(__classid(TForm_dse_report), &Form_dse_report);
		Application->CreateForm(__classid(TF_duplicate), &F_duplicate);
		Application->CreateForm(__classid(TForm3bpi), &Form3bpi);
		Application->CreateForm(__classid(TForm7), &Form7);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
