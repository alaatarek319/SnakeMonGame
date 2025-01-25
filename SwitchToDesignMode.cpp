#include "SwitchToDesignMode.h"
#include"Output.h"
#include"Grid.h"
#include"Player.h"


SwitchToDesignMode::SwitchToDesignMode(ApplicationManager* pApp) : Action(pApp)
{
}

void SwitchToDesignMode::ReadActionParameters()
{
	// no parameters to read from user
}


void SwitchToDesignMode::Execute() {

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	//setting the endgame to not ended 
	pGrid->SetEndGame(false);
	//creating Design mode tool bar
	pOut->CreateDesignModeToolBar();
	//looping around the four players and reseting them back 
	for (int i = 0; i < 4; i++) {
		Player* Pcurrent = pGrid->GetCurrentPlayer();
		Pcurrent->ResetPlayer(pGrid);
		pGrid->AdvanceCurrentPlayer();
	}
	//reseting special cards
	pGrid->ResetCards();

 }
SwitchToDesignMode::~SwitchToDesignMode()
{
	
}
