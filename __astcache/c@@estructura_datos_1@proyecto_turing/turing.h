//---------------------------------------------------------------------------

#ifndef TuringH
#define TuringH
//---------------------------------------------------------------------------

#include <vector>

const int MAX = 100;

class Transition
{
public:
	char currentState;
    char readSymbol;
    char nextState;
    char writeSymbol;
	char moveDirection; // 'L' for Left, 'R' for Right, 'S' for Stay

    Transition(char current, char read, char next, char write, char move) :
		currentState(current), readSymbol(read), nextState(next),
        writeSymbol(write), moveDirection(move) {}
};

class TuringMachine
{
public:
	TuringMachine();
	void SetTransition(char current, char read, char next, char write, char move);
	void Execute();
private:
	Transition FindTransition(char current, char read);
	void PrintTape();
public:
    std::vector<char> tape;
private:
	std::vector<Transition> transitions;
	int currentPosition;
	char currentState;
};

#endif
