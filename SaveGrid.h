#pragma once
#include"Action.h"

class SaveGrid:public Action 
{
	//parameter to hold file name
	string filename;
	
public:
	SaveGrid(ApplicationManager* pApp); 

	virtual void ReadActionParameters(); 

	virtual void Execute(); 

	virtual ~SaveGrid(); 

};

