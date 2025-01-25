#include "CardThirteen.h"

int CardThirteen::cardThirteenNum = 0;
bool CardThirteen::bought = false;
Player* CardThirteen::Owner = NULL;
int CardThirteen::StationPrice = 0;
int CardThirteen::Fees = 0;
int CardThirteen::SaveNum = 0;


CardThirteen::CardThirteen(const CellPosition& pos) :Card(pos)        // A Constructor takes card position
{
	cardNumber = 13;                                          // set the inherited cardNumber data member with the card number (13 here)
	cardThirteenNum++;
}

CardThirteen::~CardThirteen(void)
{
	cardThirteenNum--;
	if (SaveNum > 0)
		SaveNum--;
}

void CardThirteen::ReadCardParameters(Grid* pGrid)
{
	//only done once at the first time of constructing such an object
	if (cardThirteenNum == 1)
	{
		
		Input* pIn = pGrid->GetInput();
		Output* pOut = pGrid->GetOutput();

		pGrid->PrintErrorMessage("New CardThirteen: Click anywhere to start entering parameters...");


		pOut->PrintMessage("Enter the Card Price ...");
		int x = pIn->GetInteger(pOut);
		if (x <= 0)
			StationPrice = 0;
		else
			StationPrice = x;
		pOut->PrintMessage("Enter the Fees ...");
		x = pIn->GetInteger(pOut);
		if (x <= 0)
			Fees = 0;
		else
			Fees = x;

		pOut->ClearStatusBar();
	}
	else
		return;

}

void CardThirteen::Apply(Grid* pGrid, Player* pPlayer)
{
   //Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne

    //Check if the Card is bought or not ,if no ask the player if he wants to buy it
	if (!bought && ((pPlayer->GetWallet()) >= StationPrice))
	{
		pOut->PrintMessage("you have reached a station. Do you want to buy it? y/n");
		string x = pIn->GetSrting(pOut);
		if (x[0] == 'y')
		{
			Owner = pPlayer;
			bought = true;
			int Wallet = pPlayer->GetWallet() - StationPrice;
			Owner->SetWallet(Wallet);
		}
		else if (x[0] == 'n')
		{
			return; //dont buy anything just return 
		}
		else
		{
			pOut->PrintMessage("Invalid input!");
			return;
		}																
	}
	//If it is bought decide whether to deduct the fees or no (this player is the owner in this case)
	else if (bought)
	{
		pOut->PrintMessage("you have reached a bought station.Click anywhere to continue ...");
		pIn->GetCellClicked();
		if (pPlayer != Owner)
		{
			if (pPlayer->GetWallet() >= Fees)
			{
				pPlayer->SetWallet(pPlayer->GetWallet() - Fees);
				Owner->SetWallet(Owner->GetWallet() + Fees);
			}
			else
			{
				Owner->SetWallet(pPlayer->GetWallet() + Owner->GetWallet());
				pPlayer->SetWallet(0);
			}
		}
	}
	else
		return;
}

void CardThirteen::Reset() {
	Owner = nullptr;
	bought = false;
}

void CardThirteen::Save(ofstream& OutFile, int Type)
{
	if (Type == 3)
	{
		SaveNum++;
		Card::Save(OutFile, Type);
		if (SaveNum == 1)
			OutFile << StationPrice << " " << Fees;
		OutFile << endl;
	}
}

void CardThirteen::Load(ifstream& InFile, int Type)
{
	//Check if the type is Cards ,then load the Card number and its position
	if (Type == 3)
	{
		if (cardThirteenNum == 1)
		{
			int newStationPrice, newFees;
			InFile >> newStationPrice >> newFees;
			StationPrice = newStationPrice;
			Fees = newFees;
		}
	}
}


void CardThirteen::EditCard(Grid* pGrid) {
	//editing the Card parameters
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pGrid->PrintErrorMessage("Edit CardThirteen: Click anywhere to start entering parameters...");


	pOut->PrintMessage("Enter the Card Price ...");
	int x = pIn->GetInteger(pOut);
	if (x <= 0)
		StationPrice = 0;
	else
		StationPrice = x;
	pOut->PrintMessage("Enter the Fees ...");
	x = pIn->GetInteger(pOut);
	if (x <= 0)
		Fees = 0;
	else
		Fees = x;

	pOut->ClearStatusBar();
	pGrid->PrintErrorMessage("Card Edited Successfully ");
}