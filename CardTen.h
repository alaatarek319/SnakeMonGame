#pragma once
#include "Card.h"

class CardTen : public Card
{
	static int StationPrice;
	static int Fees;
	static int cardTenNum;
	static bool bought;
	static Player* Owner;
	static int SaveNum;

public:

	CardTen(const CellPosition& pos); 

	virtual void ReadCardParameters(Grid* pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	void Reset();
	
	virtual void Save(ofstream& OutFile, int Type);
	
	virtual void Load(ifstream& InFile, int Type);

	virtual void EditCard(Grid* pGrid);
	
	virtual ~CardTen(); 
};