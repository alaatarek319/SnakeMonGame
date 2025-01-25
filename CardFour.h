#pragma once

#include "Card.h"
#include "Snake.h"

class CardFour : public Card
{
	// No parameters for this Card

public:

	CardFour(const CellPosition& pos); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	virtual void Save(ofstream& OutFile, int Type);

	virtual ~CardFour(); 
};