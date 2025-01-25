#include "SwitchToPlayMode.h"
#include"Output.h"
#include"Grid.h"

SwitchToPlayMode::SwitchToPlayMode(ApplicationManager* pApp) : Action(pApp)
{
}

void SwitchToPlayMode::ReadActionParameters()
{
	// no parameters to read from user
}

void SwitchToPlayMode::Execute() {

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	//setting the endgame to not ended  
	pGrid->SetEndGame(false);
	//creating the play mode tool bar 
	pOut->CreatePlayModeToolBar();

}

SwitchToPlayMode::~SwitchToPlayMode()
{

}
