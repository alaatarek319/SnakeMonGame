#include "Card.h"

int Card::CardCount = 0;

Card::Card(const CellPosition & pos) : GameObject(pos) // sets the cell position of the GameObject
{
	CardCount++;
}

void Card::SetCardNumber(int cnum)
{
	if (cnum > 0 && cnum < 14)
		cardNumber = cnum; // needs validation
	else
		cardNumber = 0;
}

int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::Draw(Output* pOut) const
{
	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(position, cardNumber);
}

void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}

int Card::GetCardCount()
{
	return CardCount;
 }


void Card::Save(ofstream& OutFile, int Type)
{
	//Check if the type is Cards ,then Save the Card number and its position
	if (Type == 3)
	{	
		OutFile << cardNumber << " " << position.GetCellNum() << " ";
	}
	//This function is virtual because some cards have other parameters 
}

void Card::Load(ifstream& InFile, int Type)
{
	//Check if the type is Cards ,then load the Card number and its position
	/*if (Type == 3)
	{
		int cell;
		InFile >> cardNumber >> cell;
		position = position.GetCellPositionFromNum(cell);
	}*/
	//This function is virtual because some cards have other parameters 

}

bool Card::IsOverLapping(GameObject* newObj) const
{
	return false;
}

void Card::DecCardCount()
{
	CardCount--;
}

void Card::Reset()
{

}

void Card::Paste(Card* C, CellPosition& cell)
{
	position = cell;
}

 void Card::EditCard(Grid* pGrid)
 {

	 pGrid->PrintErrorMessage("This Card has no parameters to edit");

 }

Card::~Card()
{
	CardCount--;
}
