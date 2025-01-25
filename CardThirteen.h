#pragma once
#include "Card.h"

class CardThirteen : public Card
{
	static int StationPrice;
	static int Fees;
	static int cardThirteenNum;
	static bool bought;
	static Player* Owner;
	static int SaveNum;


public:

	CardThirteen(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	void Reset();

	void Save(ofstream& OutFile, int Type);

	void Load(ifstream& InFile, int Type);

	virtual void EditCard(Grid* pGrid);

	virtual ~CardThirteen();
};