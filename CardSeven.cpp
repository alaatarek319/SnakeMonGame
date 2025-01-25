#include "CardSeven.h"
#include <time.h> 

CardSeven::CardSeven(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 7; // set the inherited cardNumber data member with the card number (7 here)
}

CardSeven::~CardSeven() {

}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer) {

	// Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	//Give the player another roll dice
	srand((int)time(NULL)); // time is for different seed each run
	int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed

	pPlayer->setTurnCount(pPlayer->GetTurnCount() - 1);
	pPlayer->Move(pGrid, diceNumber);


}

void CardSeven::Save(ofstream& OutFile, int Type)
{
	if (Type == 3)
	{
		Card::Save(OutFile, Type);
		OutFile << endl;
	}
}