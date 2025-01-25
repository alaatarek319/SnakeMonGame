#pragma once
#include "Action.h"

class CutCard : public Action
{
	//parameter to hold the cell of the card to be cut
	CellPosition cell;

public:

	CutCard(ApplicationManager* pApp); 

	virtual void ReadActionParameters(); 

	virtual void Execute();

	virtual ~CutCard(); 

};

