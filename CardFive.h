#pragma once

#include "Card.h"

class CardFive : public Card
{
	// No parameters for this Card

public:
	CardFive(const CellPosition& pos); 

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual void Save(ofstream& OutFile, int Type);

	virtual ~CardFive(); 
};