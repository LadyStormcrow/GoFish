#pragma once
#include "Card.h"

#ifndef Deck_hpp
#define Deck_hpp

class Deck {
public:
	Deck(); 
	void shuffleDeck(); 
	Card drawCard();

private: 
	int deck; 
};

#endif