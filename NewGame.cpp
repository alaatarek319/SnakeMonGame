#include "NewGame.h"
#include"Player.h"
#include"Grid.h"

NewGame::NewGame(ApplicationManager* pApp) : Action(pApp)
{

}

void NewGame::ReadActionParameters()
{
	// no parameters to read from user
}

void NewGame::Execute() {

	Grid* pGrid= pManager->GetGrid();
	//setting the endgame to false in case it ended
	pGrid->SetEndGame(false);
	//looping around the players and reseting their parameters
	for (int i = 0; i < 4; i++) {

		Player * Pcurrent = pGrid->GetCurrentPlayer();
		Pcurrent->ResetPlayer(pGrid);
		pGrid->AdvanceCurrentPlayer();

	}
	//reseting the cards that are owned by the players 
	pGrid->ResetCards();

}

NewGame::~NewGame()
{

}
