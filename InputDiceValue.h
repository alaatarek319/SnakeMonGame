#pragma once
#include "Action.h"

class InputDiceValue: public Action
{
	// parameter to hold the input dice value
	int DiceValue;      

public:

	InputDiceValue(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~InputDiceValue();

};

