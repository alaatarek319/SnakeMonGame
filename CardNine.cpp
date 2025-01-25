#include "CardNine.h"

CardNine::CardNine(const CellPosition& pos) :Card(pos)		// set the cell position of the card
{
	cardNumber = 9; // set the inherited cardNumber data member with the card number (9 here)
}

CardNine::~CardNine(void)
{
}

void CardNine::ReadCardParameters(Grid* pGrid)
{
	Input* pIn = pGrid->GetInput();				
	Output* pOut = pGrid->GetOutput();		

	//Get the moved to cell from the user
	(pOut)->PrintMessage("New CardNine: Click on the destination cell ...  ");
	MovedToCell = (pIn)->GetCellClicked();

	pOut->ClearStatusBar();
}

void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
	// Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	//update the player position and draw the player there 
	pGrid->UpdatePlayerCell(pPlayer, MovedToCell);
	pGrid->GetOutput()->PrintMessage("Player moved successfully. ");
	//check if there is a snake or ladder or card after he moves 
	if (pPlayer->GetCell()->HasLadder())
		(pPlayer->GetCell()->GetGameObject())->Apply(pGrid, pPlayer);
	else if (pPlayer->GetCell()->HasSnake())
		(pPlayer->GetCell()->GetGameObject())->Apply(pGrid, pPlayer);
	else if (pPlayer->GetCell()->HasCard())
		(pPlayer->GetCell()->GetGameObject())->Apply(pGrid, pPlayer);
}

void CardNine::Save(ofstream& OutFile, int Type)
{
	if (Type == 3)
	{
		Card::Save(OutFile, Type);
		OutFile << " " <<CellPosition ::GetCellNumFromPosition( MovedToCell) << endl;
	}
}

void CardNine::Load(ifstream& InFile, int Type)
{
	//Check if the type is Cards ,then load the Card number and its position
	if (Type == 3)
	{
		int Destination;
		InFile >> Destination;
		MovedToCell = CellPosition::GetCellPositionFromNum(Destination);
	}
}

void CardNine::Paste(Card* other, CellPosition& cell)
{
	//Pasting Data members if Card Nine
	CardNine* C1 = dynamic_cast <CardNine*> (other);
	if (C1)
	{
		Card::Paste(other, cell);
		this->MovedToCell = C1->MovedToCell;
	}
}

void CardNine::EditCard(Grid* pGrid) {
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pGrid->PrintErrorMessage("Click on the destination cell ...");
	MovedToCell = (pIn)->GetCellClicked();

	pOut->ClearStatusBar();
}