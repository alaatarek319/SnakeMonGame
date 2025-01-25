#pragma once

#include "Card.h"

// [ CardOne ] Summary:
// Its Apply() Function: Decrements the value of the passing player’s wallet by a value
// Its Parameters: The Wallet Value to decrease --> put it as a "data member" and read it in ReadCardParameters()

class CardEight : public Card
{
	// No parameters for this Card

public:
	CardEight(const CellPosition& pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
	// by decrementing the player's wallet by the walletAmount data member
	virtual void Save(ofstream& OutFile, int Type);
	virtual ~CardEight(); // A Virtual Destructor
};