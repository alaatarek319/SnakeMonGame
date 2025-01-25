#include "Edit.h"
#include "Input.h"
#include "Grid.h"
#include "Card.h"

Edit::Edit(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void Edit::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	pGrid->PrintErrorMessage("Click on the cell you want to edit");
	cell = pIn->GetCellClicked();

}

void Edit::Execute()
{
	//Getting cell to be edited from the user
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	//Check if the cell is valid and has a Card
	if (cell.IsValidCell()) {
		Card* C = dynamic_cast <Card*> (pGrid->GetGameObj(cell));
		if (C)
		{
			C->EditCard(pGrid);
		}
		else
			pGrid->PrintErrorMessage("Error This Cell doesnt have a Card");
	}
	else
		pGrid->PrintErrorMessage("Error Invalid Cell");

}

Edit::~Edit()
{

}