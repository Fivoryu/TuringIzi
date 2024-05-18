//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Formulario.h"
#include <iostream>
//#include "Turing.h"
#include "Transicion.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Transiciones trans;
std::string Cinta;
std::string Entrada;
int ini = 5;
int poseini = 0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
    trans.SetEndInstr('B');	
	for (int i = 0; i < 5; i++)
		trans.SetEstado(0x30 + i);
	std::string Simbolos = "01XYB";
	for (int i = 0; i <= Simbolos.length(); i++)
		trans.SetSimbolo(Simbolos[i]);
	trans.SetTransicion('0','0','1','X','R');
	trans.SetTransicion('0','Y','3','Y','R');	
	trans.SetTransicion('1','0','1','0','R');	
	trans.SetTransicion('1','1','2','Y','L');	
	trans.SetTransicion('1','Y','1','Y','R');	
	trans.SetTransicion('2','0','2','0','L');	
	trans.SetTransicion('2','X','0','X','R');	
	trans.SetTransicion('2','Y','2','Y','L');	
	trans.SetTransicion('3','Y','3','Y','R');	
	trans.SetTransicion('3','B','4','B','R');
}

//TuringMachine tm;


//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{     
	/*	
	tm.SetTransition('A', '0', 'A', '1', 'R');

	int h = Edit1->Text.Length();
	AnsiString cad = Edit1->Text;
	std::string cad1 = cad.c_str();
	
	for (int i = 0; i < h; i++)
	{
		tm.tape[i] = cad1[i];
	}

	tm.Execute();
	cad1 = "";

	for (int i = 0; i < tm.tape.size(); i++)
	{
		cad1[i] = tm.tape[i];
	}

	Edit2->Text = cad1.c_str();
	*/
	Cinta = "";
	poseini = 0;
	ini = 5;
	for (int i = 1; i <= 10; i++)
		Cinta += trans.GetEndInstr();  // Cinta = "BBBBBBBBB"
	std::string ahs = Cinta;
	AnsiString entrada = Edit1->Text;   // Entrada = "1100"
	Entrada = entrada.c_str();
	Cinta.insert(5, entrada.c_str());   // Cinta = "BBBBB1100BBBBB"
	ahs = Cinta;
	Edit2->Text = Cinta.c_str();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	AnsiString end = Edit3->Text;
	Edit3->Text = "";
	trans.SetEndInstr(end[1]);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	
	char s = Cinta[ini];
	trans.Turing(Cinta, Entrada, ini, poseini);
	Edit2->Text = Cinta.c_str();	
}
//---------------------------------------------------------------------------
