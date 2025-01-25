#pragma once
#include"Card.h"
class CardSeven: public Card
{
	// No parameters for this Card

public :

	CardSeven(const CellPosition& pos);
	
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	
	virtual void Save(ofstream& OutFile, int Type);
	
	virtual ~CardSeven();
};

