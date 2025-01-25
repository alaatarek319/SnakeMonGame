#pragma once
#include "Action.h"

class CopyCard : public Action
{
	//parameter to hold the cell of card to be copied
	CellPosition cell;

public:

	CopyCard(ApplicationManager* pApp); 

	virtual void ReadActionParameters(); 

	virtual void Execute(); 

	virtual ~CopyCard(); 
};

