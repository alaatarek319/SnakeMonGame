#include "InputDiceValue.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Player.h"

InputDiceValue::InputDiceValue(ApplicationManager* pApp) : Action(pApp)
{

}

void InputDiceValue::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	//Getting the dice number from the user
	pOut->PrintMessage("Please enter a dice value between 1-6");
	int DV  = pIn->GetInteger(pOut);
	//Validation of the user input
	DiceValue = (DV > 0 && DV < 7) ? DV : 0;
	
}
void InputDiceValue::Execute() {

	//Getting Dicevalue from the user
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	bool Ended = pGrid->GetEndGame();

	//check if the game ended,if no move the player with the input dice value
	if (!Ended) {
		if (DiceValue) {

			Player* pCurrent = pGrid->GetCurrentPlayer();

			pCurrent->Move(pGrid, DiceValue);

			pGrid->AdvanceCurrentPlayer();

		}
		else
			pGrid->PrintErrorMessage("You entered an invalid Dice Number ");
	}
	else 
		pGrid->PrintErrorMessage("*********The game ended horraayy*********** ");

}

InputDiceValue::~InputDiceValue() 
{

}
