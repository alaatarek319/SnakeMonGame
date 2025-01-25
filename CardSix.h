#pragma once

#include "Card.h"

class CardSix : public Card
{
	// No parameters for this Card

public:

	CardSix(const CellPosition& pos);

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	virtual void Save(ofstream& OutFile, int Type);
	
	virtual ~CardSix(); 
};