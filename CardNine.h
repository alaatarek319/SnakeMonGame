#pragma once
#include "Card.h"

class CardNine : public Card
{
	//parameter to hold the position of the moved to cell
	CellPosition MovedToCell; 

public:

	CardNine(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	void Paste(Card* other, CellPosition& cell);

	virtual void Save(ofstream& OutFile, int Type);

	virtual void Load(ifstream& InFile, int Type);

	virtual void EditCard(Grid* pGrid);

	virtual ~CardNine(); 

};