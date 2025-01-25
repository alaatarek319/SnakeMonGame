#pragma once
#include "Action.h"

class Edit : public Action
{
	//parameter to hold edited card cell
	CellPosition cell;

public:

	Edit(ApplicationManager* pApp); 

	virtual void ReadActionParameters(); 

	virtual void Execute();

	virtual ~Edit(); 
};

