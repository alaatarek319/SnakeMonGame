#pragma once

#include "GameObject.h"
#include "Player.h"

// Base Class of All Types of Cards (CardOne, CardTwo, CardThree, ...etc.)
// Note: We will make each type of Card in a separate class because:
// it may have additional data members and functions like: Apply(), ...etc. which have different implementation depending on Card Number
class Card : public GameObject
{
	static int CardCount;           //Card counter needed in the save and load 

protected:

	int cardNumber;                 // an integer representing the card number

public:
	Card(const CellPosition & pos); // A Constructor for card that takes the cell position of it

	static int GetCardCount();      // Getter for the Cards Count 
	void SetCardNumber(int cnum);   // The setter of card number
	int GetCardNumber();            // The getter of card number
	void DecCardCount();            // Decrements Card Count when a Card is deleted 
	void Draw(Output* pOut) const;  // Draws the card number in the cell position of the card
	                                // It has the same implementation for all Card Types (Non-Virtual)

	virtual void ReadCardParameters(Grid * pGrid);           // It reads the parameters specific for each Card Type
	                                                         // It is a virtual function (implementation depends on Card Type)

	virtual void Apply(Grid* pGrid, Player* pPlayer);        // It applies the effect of the Card Type on the passed player
	                                                         // It is a virtual function (implementation depends on Card Type)

	virtual void Save(ofstream& OutFile, int Type);          //This function is virtual because some cards have other parameters 
	virtual void Load(ifstream& InFile, int Type);           //This function is virtual because some cards have other parameters  
	virtual bool IsOverLapping(GameObject* newObj) const;

	virtual void Reset();                                    //Resets the Card parameters that are related to players ownership
	virtual void Paste(Card* C, CellPosition& cell);         //Sets the cellposition of the paste card 
	virtual void EditCard(Grid* pGrid);                      //Edits the Card parameters (if any ,thats why its virtual )
	virtual ~Card();                                         // A Virtual Destructor
};

