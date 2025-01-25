#include "CardEight.h"

CardEight::CardEight(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 8; // set the inherited cardNumber data member with the card number (8 here)
}

CardEight::~CardEight(void)
{
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
    //Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	//set the stop to true to prevent him from playing the next turn
	pPlayer->SetStop(true);
}

void CardEight::Save(ofstream& OutFile, int Type)
{
	if (Type == 3)
	{
		Card::Save(OutFile, Type);
		OutFile << endl;
	}
}