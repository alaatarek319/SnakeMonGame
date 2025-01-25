#include "CardOne.h"

CardOne::CardOne(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 1; // set the inherited cardNumber data member with the card number (1 here)
}

CardOne::~CardOne(void)
{
}

void CardOne::ReadCardParameters(Grid * pGrid)
{
	
	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* INP = pGrid->GetInput();
	Output* OUTP = pGrid->GetOutput();


	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	OUTP->PrintMessage("New CardOne: Enter its wallet amount to decrease ...");
	int w = INP->GetInteger(OUTP);
	if (w < 0)
		walletAmount = 0;
	else
		walletAmount = w;

	// [ Note ]:
	// In CardOne, the only parameter of CardOne is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	OUTP->ClearStatusBar();
}

void CardOne::Apply(Grid* pGrid, Player* pPlayer)
{
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid,pPlayer);

	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne
	pPlayer->SetWallet(pPlayer->GetWallet() - walletAmount);

}

void CardOne::Load(ifstream& InFile, int Type)
{
	//Check if the type is Cards ,then load the Card number and its position
	if (Type == 3)
	{
		int NewWallet;
		InFile >> NewWallet;
		walletAmount = NewWallet;
	}
}


void CardOne::Save(ofstream& OutFile, int Type)
{
	//saving the Data members of Card One
	if (Type == 3)
	{
	    Card::Save(OutFile, Type);
		OutFile << " " << walletAmount << endl;
	}
}

void CardOne ::Paste(Card* other, CellPosition& cell)
{
	//Pasting the Data members of Card One
	CardOne* C1 = dynamic_cast <CardOne*> (other);
	if (C1)
	{
		Card::Paste(other, cell);
		this->walletAmount = C1->walletAmount;
	}
}
void CardOne::EditCard(Grid* pGrid) {

	//Editing the Data members of Card One
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