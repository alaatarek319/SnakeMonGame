#include "CopyCard.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Card.h"

CopyCard::CopyCard(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void CopyCard::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pGrid->PrintErrorMessage("click on the source cell");
	cell = pIn->GetCellClicked();
}

void CopyCard::Execute()
{
	//Getting the Card to be copied from the user
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	//check if the cell is valid and has a card
	if (cell.IsValidCell())
	{
		Card* C = dynamic_cast <Card*> (pGrid->GetGameObj(cell));
		if (C)
		{
			pGrid->SetClipboard(C);
			pGrid->PrintErrorMessage("Card copied successfully");
		}
		else
			pGrid->PrintErrorMessage("This Cell Does not Have a Card");
	}
	else
	{
		pGrid->PrintErrorMessage("Error InValid Cell");
	}
}

CopyCard::~CopyCard()
{

}
