#pragma once
#include "Action.h"

class DeleteGameObject :public Action 
{
	//parameter to hold the cell to be deleted
	CellPosition cpos;

public:

	DeleteGameObject(ApplicationManager* pApp);

	virtual void ReadActionParameters(); 

	virtual void Execute(); 

	virtual ~DeleteGameObject(); 

};

