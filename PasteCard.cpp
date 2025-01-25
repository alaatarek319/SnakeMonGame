#include "PasteCard.h"
#include "Input.h"
#include "Grid.h"
#include "Card.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"

PasteCard::PasteCard(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void PasteCard::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	pGrid->PrintErrorMessage("Click on the destination cell");
	//Getting the Cell that we'll paste to
	cell = pIn->GetCellClicked();

}

void PasteCard::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	//Read input from user
	ReadActionParameters();
	GameObject * HasObj = pGrid->GetGameObj(cell);
	//Check if the cell is valid and dosent have an object and there is a Card in the clipboard to paste
	//else print error messages 
	if (cell.IsValidCell() && !HasObj) {
		if (pGrid->GetClipboard())
		{
			//Get the Card number and accordingly paste the Card
			int Number = pGrid->GetClipboard()->GetCardNumber();
			Card* pCard = NULL;
			switch (Number)
			{
			case 1:
				pCard = new CardOne(cell);
				break;
			case 2:
				pCard = new CardTwo(cell);
				break;
			case 3:
				pCard = new CardThree(cell);
				break;
			case 4:
				pCard = new CardFour(cell);
				break;
			case 5:
				pCard = new CardFive(cell);
				break;
			case 6:
				pCard = new CardSix(cell);
				break;
			case 7:
				pCard = new CardSeven(cell);
				break;
			case 8:
				pCard = new CardEight(cell);
				break;
			case 9:
				pCard = new CardNine(cell);
				break;
			case 10:
				pCard = new CardTen(cell);
				break;
			case 11:
				pCard = new CardEleven(cell);
				break;
			case 12:
				pCard = new CardTwelve(cell);
				break;
			case 13:
				pCard = new CardThirteen(cell);
				break;
			default:
				break;
			}
			pCard->Paste(pGrid->GetClipboard(), cell);
			pGrid->AddObjectToCell(pCard);
			// delete pGrid
		}
	}
	else if (HasObj) 
	{
		pGrid->PrintErrorMessage("Error this cell contains an object ");
	}
	else
	{
		pGrid->PrintErrorMessage(" Error Invalid Cell ");
	}
}

PasteCard::~PasteCard()
{

}
