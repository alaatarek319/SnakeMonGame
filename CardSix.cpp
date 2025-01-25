#include "CardSix.h"

CardSix::CardSix(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 6; // set the inherited cardNumber data member with the card number (6 here)
}

CardSix::~CardSix(void)
{
}
void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
   // Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	//move the player back to where he was
	CellPosition NewCell = pPlayer->GetCell()->GetCellPosition();
	int PreviousCellNum = NewCell.GetCellNum() - pPlayer->GetRollDice();
	pGrid->UpdatePlayerCell(pPlayer, PreviousCellNum);
	if (pPlayer->GetCell()->HasLadder())
		(pPlayer->GetCell()->GetGameObject())->Apply(pGrid, pPlayer);
	else if (pPlayer->GetCell()->HasSnake())
		(pPlayer->GetCell()->GetGameObject())->Apply(pGrid, pPlayer);
	else if (pPlayer->GetCell()->HasCard())
		(pPlayer->GetCell()->GetGameObject())->Apply(pGrid, pPlayer);


}

void CardSix::Save(ofstream& OutFile, int Type)
{
	if (Type == 3)
	{
		Card::Save(OutFile, Type);
		OutFile << endl;
	}
}