#pragma once

#include <vector>
#include "Card.h"

#ifndef Set_hpp
#define Set_hpp


class Set {
public: 
	Set(); 
	void createSet(Card _cardOne, Card _cardTwo); 
	void addCard(Card _card); 
	bool completeSet(); 

private:
	std::vector<Card> cardSet; 

};

#endif