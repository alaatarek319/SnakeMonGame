#include "Player.h"

#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum((playerNum<0|| playerNum>= MaxPlayerCount) ? -1: playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	justRolledDiceNum = 0;
	stop = false;
	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	if(wallet>=0)
	this->wallet = wallet;
	// Make any needed validations
}
void Player::SetJustRolledDiceNum(int DiceNum)
{
   if (DiceNum > 0 && DiceNum < 7)
		this->justRolledDiceNum = DiceNum;
}

void Player::SetStop(bool S) {

	//Stop Flag to stop the player from moving in this turn
	stop = S;
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

int Player::GetRollDice()const
{

	return justRolledDiceNum;
}

int Player::GetStepCount()const
{
	return stepCount;
}

int Player::GetPlayerNumber() const
{
	return playerNum;
}

void Player::SetStepCount(int s) 
{
	stepCount = s;
}

void Player::setTurnCount(int t) {

	turnCount = t;
}


// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];
	///TODO: use the appropriate output function to draw the player with "playerColor"
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);
}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);
}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, int diceNumber)
{
	if (!stop) {
		///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


		// == Here are some guideline steps (numbered below) to implement this function ==


		// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
		turnCount++;

		// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
		//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
		// 3- Set the justRolledDiceNum with the passed diceNumber
		SetJustRolledDiceNum(diceNumber);

		if (turnCount == 3) {
			turnCount = 0;
			wallet += 10 * justRolledDiceNum;
			return;
		}
		else if (wallet == 0)
			return;

		
		// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
		//    Using the appropriate function of CellPosition class to update "pos"
		CellPosition cNew = pCell->GetCellPosition();

		if (cNew.GetCellNum() + diceNumber > 99)
		{
			cNew = CellPosition::GetCellPositionFromNum(99);
			pGrid->UpdatePlayerCell(this, cNew);
			pGrid->SetEndGame(true);
			string winingpPlayer = to_string(playerNum);
			pGrid->PrintErrorMessage("***** Player " + winingpPlayer + " won the game *******");

			return;
		}

		cNew.AddCellNum(justRolledDiceNum);


		// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
		//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
		pGrid->UpdatePlayerCell(this, cNew);


		// 6- Apply() the game object of the reached cell (if any)
		if (pCell->HasLadder())
			(pCell->GetGameObject())->Apply(pGrid, this);
		else if (pCell->HasSnake())
			(pCell->GetGameObject())->Apply(pGrid, this);
		else if (pCell->HasCard())
			(pCell->GetGameObject())->Apply(pGrid, this);

		// increamenting the step count 
		stepCount = pCell->GetCellPosition().GetCellNum() ;

	}
	else
	{
		stop = false;
		turnCount++;
		if (turnCount == 3) {
			turnCount = 0;
			wallet += 10 * justRolledDiceNum;
			return;
		}

	}

}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}

void Player::ResetPlayer(Grid* pGrid) {

	CellPosition resetcell(8,0);
	pGrid->UpdatePlayerCell(this, resetcell);
	stepCount=0;		   
	wallet=100;		      
	justRolledDiceNum=0; 
	turnCount=0;       
	stop = false;

}