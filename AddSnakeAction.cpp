#include "AddSnakeAction.h"
#include "Input.h"
#include "Output.h"
#include "Snake.h"

AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	///TODO: Make the needed validations on the read parameters
	if (!(startPos.HCell() == endPos.HCell()) || startPos.VCell() >= endPos.VCell())
	{
		startPos = -1;
		endPos = -1;
	}

	// Clear messages
	pOut->ClearStatusBar();
}

// Execute the action
void AddSnakeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

		Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	if (CellPosition::GetCellNumFromPosition(startPos) != 99) {
		// Create a Snake object with the parameters read from the user
		Snake* pSnake = new Snake(startPos, endPos);

		// Check if the Snake is overlapping another object
		if (pGrid->IsOverLapping(pSnake))
		{
			pGrid->PrintErrorMessage("Error : An OverLapping Snake");
			delete pSnake;
			return;
		}

		//Add the Snake to the Grid
		bool added = pGrid->AddObjectToCell(pSnake);
		// if the GameObject cannot be added
		if (!added)
		{
			// Print an appropriate message
			if (startPos.GetCellNum() == -1 || endPos.GetCellNum() == -1)
				pGrid->PrintErrorMessage("Error: Cell InValid Snake ! Click to continue ...");
			else
				pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
			delete pSnake;
		}
		// Here, the Snake is created and added to the GameObject of its Cell, so we finished executing the AddSnakeAction
	}
	else
		pGrid->PrintErrorMessage("Error: Cell InValid Snake ! Click to continue ...");
}

AddSnakeAction::~AddSnakeAction()
{

}