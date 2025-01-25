#include "Snake.h"
#include"Ladder.h"
#include"Player.h"

int Snake::SnakeCount = 0;

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	SnakeCount++;
	///TODO: Do the needed validation
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("You have reached a Snake . Click to continue ...");
    // 2- Apply the Snake's effect by moving the player to the endCellPos
    pGrid->UpdatePlayerCell(pPlayer, endCellPos);
    // 3- Check if the player landed on a Card ,if so apply it
    if (pPlayer->GetCell()->HasCard())
		 (pPlayer->GetCell()->GetGameObject())->Apply(pGrid, pPlayer);

}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

int Snake::GetSnakeCount() {

	return SnakeCount;
 }

void Snake::Save(ofstream& OutFile, int Type)
{
	//Checks if we are saving Snakes now ,if yes the save its position
	if (Type == 2)
	{
		OutFile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
	}
}

void Snake::Load(ifstream& InFile, int Type) {

	//Checks if we are loading Snakes now ,it yes load its position
	if (Type == 2)
	{
		int start, end;
		InFile >> start >> end;
		position = position.GetCellPositionFromNum(start);
		endCellPos = endCellPos.GetCellPositionFromNum(end);
	}
}

bool Snake::IsOverLapping(GameObject* newObj) const
{
	//Check if this snake is overlapping with another object
	Snake* newSnake = dynamic_cast<Snake*> (newObj);
	if (newSnake)
		if (newSnake->GetPosition().HCell() == position.HCell())
		{
			if (!(newSnake->endCellPos.VCell() < position.VCell()) && !(newSnake->GetPosition().VCell() > endCellPos.VCell()))
				return true;
		}

	//Checks if this snake is over lapping with a ladder in the same position
	Ladder* newLadder = dynamic_cast<Ladder*> (newObj);
	if (newLadder)
		if (newLadder->GetPosition().HCell() == position.HCell())
		{
			if ((newLadder->GetPosition().VCell() == endCellPos.VCell()) && (newLadder->GetEndPosition().VCell() == position.VCell()))
				return true;
		}

	return false;
}

Snake::~Snake()
{
	SnakeCount--;
}