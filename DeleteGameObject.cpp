#include "DeleteGameObject.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"

DeleteGameObject::DeleteGameObject(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}


void DeleteGameObject::ReadActionParameters() 
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pGrid->PrintErrorMessage("Select the object to delete ");
	cpos = pIn->GetCellClicked();

 }
void DeleteGameObject::Execute() {
	
	//Getting the cell to be deleted from the user
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	//Removing the object from the grid
	pGrid->RemoveObjectFromCell(cpos);

}

DeleteGameObject::~DeleteGameObject()
{

}