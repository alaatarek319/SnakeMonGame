#include "OpenGrid.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
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


#include <fstream>

OpenGrid::OpenGrid(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

 void OpenGrid:: ReadActionParameters() {

	 Grid* pGrid = pManager->GetGrid();
	 Output* pOut = pGrid->GetOutput();
	 Input* pIn = pGrid->GetInput();
	 //Getting the file name from the user 
	 pGrid->PrintErrorMessage("Now Opening a grid....Enter the file name  ");
	 filename = pIn->GetSrting(pOut);
 }

 void OpenGrid::Execute() {


	 Grid* pGrid = pManager->GetGrid();
	 //Reading file name from user
	 ReadActionParameters();
	 //Creating Ifstrean file
	 ifstream InFile;
	 //Open the file and Check if it opened correctly
	 InFile.open(filename);
	 if (InFile.is_open())
	 {
		 //delete the objects existing first 
		 pGrid->RemoveGrid();
		 int count;
		 //loading Ladders from file
		 InFile >> count;
		 for (int i = 0; i < count; i++)
		 {
			 Ladder* lad = new Ladder(CellPosition(0), CellPosition(0));
			 lad->Load(InFile, 1);
			 pGrid->AddObjectToCell(lad);
		 }
		 //loading Snakes from file
		 InFile >> count;
		 for (int i = 0; i < count; i++)
		 {
			 Snake* sna = new Snake(CellPosition(0), CellPosition(0));
			 sna->Load(InFile, 2);
			 pGrid->AddObjectToCell(sna);
		 }
		 //loading Cards from file
		 InFile >> count;
		 for (int i = 0; i < count; i++)
		 {
			 CellPosition cardPosition;
			 Card* pCard;
			 int cardnum, cardPos;
			 InFile >> cardnum >> cardPos;
			 cardPosition = CellPosition::GetCellPositionFromNum(cardPos);
			 switch (cardnum)
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
			 pCard->Load(InFile, 3);
			 pGrid->AddObjectToCell(pCard);
		 }
		 pGrid->PrintErrorMessage("Grid loaded successfully ");
	 }
	 else
	 {
		 pGrid->PrintErrorMessage("Failed to open the file : "+filename);
	 }
 }

 OpenGrid::~OpenGrid()
 {

 }