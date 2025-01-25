#include "RollDiceAction.h"
#include "Grid.h"
#include "Player.h"
#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager *pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
{
	Grid * pGrid= pManager->GetGrid();

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	bool Ended = pGrid->GetEndGame();
	// -- If not ended, do the following --:
	if (!Ended) {

		// 2- Generate a random number from 1 to 6 
		srand((int)time(NULL)); 
		int diceNumber = 1 + rand() % 6; 
		// 3- Get the "current" player from pGrid
		Player* pCurrent = pGrid->GetCurrentPlayer();
		// 4- Move the currentPlayer using function Move of class player
		pCurrent->Move(pGrid, diceNumber);
		// 5- Advance the current player number of pGrid
		pGrid->AdvanceCurrentPlayer();

	}
	else
		//The game ended and set to ended in move ,then we print a message
		pGrid->PrintErrorMessage("*********The game ended horraayy*********** ");

}

RollDiceAction::~RollDiceAction()
{

}
