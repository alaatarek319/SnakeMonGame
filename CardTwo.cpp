#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number (2 here)
}

CardTwo::~CardTwo(void)
{

}

void CardTwo::ReadCardParameters(Grid* pGrid)
{

	Input* INP = pGrid->GetInput();
	Output* OUTP = pGrid->GetOutput();

	OUTP->PrintMessage("New CardTwo: Enter its wallet amount to add ...");
	int w = INP->GetInteger(OUTP);
	if (w < 0)
		walletAmount = 0;
	else
		walletAmount = w;

	OUTP->ClearStatusBar();
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
   //Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	//increment the wallet of the player with the input value  
	pPlayer->SetWallet(pPlayer->GetWallet() + walletAmount);
	

}

void CardTwo::Save(ofstream& OutFile, int Type)
{
	//saving the Data members of Card two
	if (Type == 3)
	{
	    Card::Save(OutFile, Type);
		OutFile << " " << walletAmount << endl;
	}
}

void CardTwo::Load(ifstream& InFile, int Type)
{
	//Check if the type is Cards ,then load the Card number and its position
	if (Type == 3)
	{
		int NewWallet;
		InFile >> NewWallet;
		walletAmount = NewWallet;
	}
}

void CardTwo::Paste(Card* other, CellPosition& cell)
{
	//Pasting Data members if Card Two
	CardTwo* C1 = dynamic_cast <CardTwo*> (other);
	if (C1)
	{
		Card::Paste(other, cell);
		this->walletAmount = C1->walletAmount;
	}
}

void CardTwo::EditCard(Grid* pGrid) {

	//Editing the data members of Card two
	Input* INP = pGrid->GetInput();
	Output* OUTP = pGrid->GetOutput();
	OUTP->PrintMessage("Edit CardOne : Enter its wallet amount to decrease ...");
	int w = INP->GetInteger(OUTP);
	if (w < 0)
		walletAmount = 0;
	else
		walletAmount = w;
	OUTP->ClearStatusBar();
	pGrid->PrintErrorMessage("Card Edited Successfully ");
}