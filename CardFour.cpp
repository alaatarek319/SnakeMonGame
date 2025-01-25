#include "CardFour.h"

CardFour::CardFour(const CellPosition& pos) : Card(pos)  // set the cell position of the card
{
	cardNumber = 4; // set the inherited cardNumber data member with the card number (1 here)
}

CardFour::~CardFour(void)
{
}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	// Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	//Get the next Snake and move the player there
	Snake* snake = pGrid->GetNextSnake(pPlayer->GetCell()->GetCellPosition());
	if (snake)
	{
		pGrid->UpdatePlayerCell(pPlayer, snake->GetPosition());
		(pPlayer->GetCell()->GetGameObject())->Apply(pGrid, pPlayer);
	}
}

void CardFour::Save(ofstream& OutFile, int Type)
{
	//saving the Data members of Card Four
	if (Type == 3)
	{
		Card::Save(OutFile, Type);
		OutFile << endl;
	}
}