#include "CardFive.h"


CardFive::CardFive(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (5 here)
}

CardFive::~CardFive(void)
{
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	// Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	pPlayer->setTurnCount(pPlayer->GetTurnCount() - 1);
	pPlayer->Move(pGrid, pPlayer->GetRollDice());

}

void CardFive::Save(ofstream& OutFile, int Type)
{
	if (Type == 3)
	{
		Card::Save(OutFile, Type);
		OutFile << endl;
	}
}