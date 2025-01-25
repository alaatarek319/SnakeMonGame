#pragma once
#include "Card.h"

class CardTwelve : public Card
{
	static int StationPrice;
	static int Fees;
	static int cardTwelveNum;
	static bool bought;
	static Player* Owner;
	static int SaveNum;


public:

	CardTwelve(const CellPosition& pos); 

	virtual void ReadCardParameters(Grid* pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	void Reset();

	void Save(ofstream& OutFile, int Type);

	void Load(ifstream& InFile, int Type);

	virtual void EditCard(Grid* pGrid);

	virtual ~CardTwelve(); 



};