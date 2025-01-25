#pragma once

#include "Action.h"

class SwitchToDesignMode : public Action
{

	// No parameters for this action

public:
	SwitchToDesignMode(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~SwitchToDesignMode();
};

