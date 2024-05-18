//---------------------------------------------------------------------------

#ifndef TransicionH
#define TransicionH
//---------------------------------------------------------------------------
#include <list>
#include <iostream>


const int MAX = 100;

struct Trans
{
	char Estado;    
	char Simbolo;
	char Nextestado;
	char Nextsimbolo;
	char Instruccion;
	Trans() 
	{
		Estado = Simbolo = Nextestado = ' ';
		Instruccion = 'H';
    }
	
	Trans(char estado, char simbolo, char nextestado, char nextsimbolo, char instruccion)
	{
		Estado = estado;
		Nextestado = nextestado;
		Simbolo = simbolo;
		Nextsimbolo = nextsimbolo;
		Instruccion = instruccion;
	}
};

class Transiciones
{
public:
	Transiciones();
	void SetEstado(char estado);
	void SetSimbolo(char simbolo);
	void SetEndInstr(char end) { EndInstruction = end; }
	char GetEndInstr() { return EndInstruction; }
	void SetTransicion(char estado, char simbolo, char nextestado, char nextsimbolo, char instruccion);
	int SearchPosE(char estado);
	int SearchPosS(char simbolo);
	Trans GetTransicion(char estado, char simbolo);
	void Turing(std::string& cinta, std::string& entrada, int& pos, int& pose);
private:
	char Estado[MAX];
	char epos;
	char Simbolo[MAX];
	char Instruction[MAX];
	char spos;
	char EndInstruction = '$';
	Trans trans[MAX][MAX];
};   

class Estad
{
public:
private:
};

#endif
