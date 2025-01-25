#include "Ladder.h"
#include"Snake.h"
#include"Player.h"

int Ladder::LadderCount = 0;

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	
	this->endCellPos = endCellPos;
	LadderCount++;
	///TODO: Do the needed validation
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("You have reached a ladder. Click to continue ...");

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	// 3- Check if the player landed on a Card ,if so apply it
	if (pPlayer->GetCell()->HasCard())
		(pPlayer->GetCell()->GetGameObject())->Apply(pGrid, pPlayer);
	
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

 int Ladder::GetLadderCount() {

	 return LadderCount;
 }


 void Ladder::Save(ofstream& OutFile, int Type)
 {
	 //Checks if we are saving Ladders now ,if yes the save its position
	 if (Type == 1)
		 OutFile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
 }

 void Ladder::Load(ifstream& InFile, int Type) {
	 //Checks if we are loading ladders now ,it yes load its position
	 if (Type == 1)
	 {
		 int start, end;
		 InFile >> start >> end;
		 position = CellPosition::GetCellPositionFromNum(start);
		 endCellPos = CellPosition::GetCellPositionFromNum(end);
	 }
 }

bool Ladder::IsOverLapping(GameObject* newObj) const
{
	//Check if this ladder is overlapping with another object
	Ladder* newLadder = dynamic_cast<Ladder*> (newObj);
	 if (newLadder)
		 if (newLadder->GetPosition().HCell() == position.HCell())
		 {
			 if (!(newLadder->endCellPos.VCell() > position.VCell()) && !(newLadder->GetPosition().VCell() < endCellPos.VCell()))
				 return true;
		 }
	 //Checks if this ladder is over lapping with a snake in the same position
	 Snake* newSnake = dynamic_cast<Snake*> (newObj);
	 if (newSnake)
		 if (newSnake->GetPosition().HCell() == position.HCell())
		 {
			 if ((newSnake->GetPosition().VCell() == endCellPos.VCell()) && (newSnake->GetEndPosition().VCell() == position.VCell()))
				 return true;
		 }

	 return false;
}

Ladder::~Ladder()
{
	LadderCount--;
}
