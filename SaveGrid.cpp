#include "SaveGrid.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include<fstream>

SaveGrid::SaveGrid(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}


void SaveGrid::ReadActionParameters() {

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	//Getting the file name from the user 
	pGrid->PrintErrorMessage("Now saving the grid ....Enter the file name  ");
	filename = pIn->GetSrting(pOut);
}

void SaveGrid::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	//Reading file name from user
	ReadActionParameters();
	//Creating Ofstrean file
	ofstream OutFile;
	//Open the file and Check if it opened correctly
	OutFile.open(filename);
	if (OutFile.is_open())
	{
		//Saving Ladders then snakes then Cards to the file where 
		//Type 1 -> Ladders 
		//Type 2-> Snakes 
		//Type 3-> Cards
		pGrid->SaveAll(OutFile, 1);
		pGrid->SaveAll(OutFile, 2);
		pGrid->SaveAll(OutFile, 3);
		pGrid->PrintErrorMessage("Grid Saved successfully to the file : " + filename);
	}
	else 
		pGrid->PrintErrorMessage("Failed to Open the file : " + filename);
	//Close the file after saving 
	OutFile.close();

}

SaveGrid::~SaveGrid()
{

}