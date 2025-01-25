#include "CutCard.h"
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


CutCard::CutCard(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void CutCard::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	pGrid->PrintErrorMessage("click on the source cell");
	cell = pIn->GetCellClicked();
}

void CutCard::Execute()
{
	//Getting the card to cut from the user
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	//Check if the cell is valid and has a card
	if (cell.IsValidCell()) {
		Card* C = dynamic_cast <Card*> (pGrid->GetGameObj(cell));
		if (C)
		{
			//Get the card number and accordingly cut the card
			int Number = (dynamic_cast <Card*> (pGrid->GetGameObj(cell)))->GetCardNumber();
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
			pCard->Paste(C, cell);
			pGrid->SetClipboard(pCard);
			pCard->DecCardCount();
			pGrid->RemoveObjectFromCell(cell);
		}
		else
			pGrid->PrintErrorMessage("This object is not a card ");
	}
	else
		pGrid->PrintErrorMessage("Error Invalid Cell ");
}

CutCard::~CutCard()
{

}
