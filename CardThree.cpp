#include "CardThree.h"
CardThree::CardThree(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number (3 here)
}

CardThree::~CardThree(void)
{
}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{

	// Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	//Get the next Ladder and move the player there
	Ladder* Ladder = pGrid->GetNextLadder(pPlayer->GetCell()->GetCellPosition());
	if (Ladder)
	{
		pGrid->UpdatePlayerCell(pPlayer, Ladder->GetPosition());
		
		(pPlayer->GetCell()->GetGameObject())->Apply(pGrid, pPlayer);
	}
}

void CardThree::Save(ofstream& OutFile, int Type)
{
	//saving the Data members of Card Three
	if (Type == 3)
	{
		Card::Save(OutFile, Type);
		OutFile << endl;
	}
}