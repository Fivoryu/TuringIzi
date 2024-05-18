//---------------------------------------------------------------------------

#pragma hdrstop

#include "Turing.h"
//---------------------------------------------------------------------------

TuringMachine::TuringMachine()
{
	currentPosition = 0;
	currentState = 'A';
	tape.resize(MAX, ' ');
}

void TuringMachine::SetTransition(char current, char read, char next, char write, char move)
{
	transitions.emplace_back(current, read, next, write, move);
}

void TuringMachine::Execute()
{
	while (currentState != 'H')
	{
		char currentSymbol = tape[currentPosition];
		char nextState = FindTransition(currentState, currentSymbol).nextState;
		char writeSymbol = FindTransition(currentState, currentSymbol).writeSymbol;
		char moveDirection = FindTransition(currentState, currentSymbol).moveDirection;

		tape[currentPosition] = writeSymbol;
		currentState = nextState;
		if (moveDirection == 'R')
		{
			currentPosition++;
		}
		else if (moveDirection == 'L')
		{
			currentPosition--;
		}
		PrintTape();
	}

}

Transition TuringMachine::FindTransition(char current, char read)
{
	for (const auto& transition : transitions)
	{
		if (transition.currentState	== current && transition.readSymbol	== read)
			return transition;
	}

	return Transition(current, read, 'H', read, 'S');
}
void TuringMachine::PrintTape()
{

}


#pragma package(smart_init)
