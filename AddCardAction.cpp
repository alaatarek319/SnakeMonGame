#include "AddCardAction.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include"CardTwo.h"
#include"CardThree.h"
#include"CardFour.h"
#include"CardFive.h"
#include"CardSix.h"
#include"CardSeven.h"
#include"CardEight.h"
#include"CardNine.h"
#include"CardTen.h"
#include"CardEleven.h"
#include"CardTwelve.h"
#include"CardThirteen.h"

AddCardAction::AddCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void AddCardAction::ReadActionParameters() 
{	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Input* pIn= pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	// 2- Read the "cardNumber" parameter and set its data member
	pOut->PrintMessage("New Card : Enter The Card Number ...");
	cardNumber = pIn->GetInteger(pOut);


	// 3- Read the "cardPosition" parameter (its cell position) and set its data member
	pOut->PrintMessage("New Card : Click on its  Cell ...");
	cardPosition = pIn->GetCellClicked();

	// 4- Make the needed validations on the read parameters
	if (cardNumber < 1 || cardNumber > 13) {
		cardNumber = 0;
		pGrid->PrintErrorMessage("Error : Invalid Card number ");
	}
	if (!cardPosition.IsValidCell() ||( CellPosition::GetCellNumFromPosition(cardPosition) == 1) || (CellPosition::GetCellNumFromPosition(cardPosition) == 99))
		pGrid->PrintErrorMessage("Error : Invalid Cell");

	// 5- Clear status bar
	pOut->ClearStatusBar();
	
}

void AddCardAction::Execute()
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	//  The first line of any Action Execution is to read its parameter first
	ReadActionParameters();

	//  Switch case on cardNumber data member and create the appropriate card object type
	if (cardPosition.IsValidCell() && cardNumber && (CellPosition::GetCellNumFromPosition(cardPosition) != 1) && (CellPosition::GetCellNumFromPosition(cardPosition) != 99)) {
		Card* pCard = NULL; // will point to the card object type
		switch (cardNumber)
		{
		case 1:
			pCard = new CardOne(cardPosition);
			break;
		case 2:
			pCard = new CardTwo(cardPosition);
			break;
		case 3:
			pCard = new CardThree(cardPosition);
			break;
		case 4:
			pCard = new CardFour(cardPosition);
			break;
		case 5:
			pCard = new CardFive(cardPosition);
			break;
		case 6:
			pCard = new CardSix(cardPosition);
			break;
		case 7:
			pCard = new CardSeven(cardPosition);
			break;
		case 8:
			pCard = new CardEight(cardPosition);
			break;
		case 9:
			pCard = new CardNine(cardPosition);
			break;
		case 10:
			pCard = new CardTen(cardPosition);
			break;
		case 11:
			pCard = new CardEleven(cardPosition);
			break;
		case 12:
			pCard = new CardTwelve(cardPosition);
			break;
		case 13:
			pCard = new CardThirteen(cardPosition);
			break;
		default:
			break;

		}

		//  if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
		if (pCard)
		{
			//  We get a pointer to the Grid from the ApplicationManager
			Grid* pGrid = pManager->GetGrid();
			Input* pIn = pGrid->GetInput();
			Output* pOut = pGrid->GetOutput();

			// Make the pCard reads its card parameters
			pCard->ReadCardParameters(pGrid);
			
			// Add the card object to the GameObject of its Cell
			bool valid = pManager->GetGrid()->AddObjectToCell(pCard);

			if (valid)
			{
				pGrid->PrintErrorMessage("The Card was added successfully!  Click anywhere to continue ...");
			}
			else
			{
				pGrid->PrintErrorMessage("Couldn't add the card, another game object exists already!  Click anywhere to continue ...");
				delete pCard;
			}
			// if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar

		}

		// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction
	}

}

AddCardAction::~AddCardAction()
{

}
