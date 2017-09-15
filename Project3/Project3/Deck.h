#pragma once
#include <vector>
#include "Card.h"

#ifndef Deck_hpp
#define Deck_hpp

class Deck {
public:
	Deck(); 
	void shuffleDeck(); 
	Card drawCard();
	int deckSize(); 
	bool emptyDeck(); 
	std::vector<Card> getDeck(); 

private: 
	std::vector<Card> deck;
};

#endif