#pragma once

#include "Action.h"

class AddCardAction : public Action
{
	// [Action Parameters]//pManager
	int cardNumber;            // 1- the card number
	CellPosition cardPosition; // 2- cell position of the card
	
public:
	AddCardAction(ApplicationManager *pApp); // A Constructor
		
	virtual void ReadActionParameters(); // Reads AddCardAction action parameters (cardNumber, cardPosition)
	
	virtual void Execute(); // Creates a new Card Object of the specific Card Number
	                        // and Reads the Parameters of This Card Number (if any)
	                        // then Sets this Card Object to GameObject Pointer of its Cell
	
	virtual ~AddCardAction(); // A Virtual Destructor
};

