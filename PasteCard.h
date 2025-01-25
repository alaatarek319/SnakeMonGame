#pragma once
#include "Action.h"

class PasteCard : public Action
{
	//parameter to hold the paste destination cell
	CellPosition cell;

public:

	PasteCard(ApplicationManager* pApp); 

	virtual void ReadActionParameters(); 

	virtual void Execute(); 

	virtual ~PasteCard(); 
};

