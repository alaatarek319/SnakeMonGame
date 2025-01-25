#pragma once
#include "SaveGrid.h"
#include"Action.h"

class OpenGrid :public Action
{
	//parameter that holds the name of the file we read from
	string filename;

public:

	OpenGrid(ApplicationManager* pApp); 

	virtual void ReadActionParameters();

	virtual void Execute(); 

	virtual ~OpenGrid(); 

};
