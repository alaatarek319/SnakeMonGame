
#pragma once
#include "Ladder.h"
#include "Card.h"

class CardThree : public Card
{
	// No parameters for this Card

public:

	CardThree(const CellPosition& pos);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual void Save(ofstream& OutFile, int Type);

	virtual ~CardThree();
};