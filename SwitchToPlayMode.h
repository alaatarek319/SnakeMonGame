#pragma once

#include "Action.h"

class SwitchToPlayMode : public Action
{

	// No parameters for this action

public:
	SwitchToPlayMode(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~SwitchToPlayMode();
};


