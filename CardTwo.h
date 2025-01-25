#pragma once

#include "Card.h"

class CardTwo : public Card
{
	int walletAmount; // the wallet value to increase from the player

public:
	CardTwo(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	virtual void Save(ofstream& OutFile, int Type);
	virtual void Load(ifstream& InFile, int Type);
	virtual void EditCard(Grid* pGrid);
	void Paste(Card* other, CellPosition& cell);
	
	virtual ~CardTwo(); // A Virtual Destructor
};

