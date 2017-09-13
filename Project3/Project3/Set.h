#pragma once

#include <vector>
#include "Card.h"

#ifndef Set_hpp
#define Set_hpp


class Set {
public: 
	Set(int _value); 
	void createSet(Card _cardOne, Card _cardTwo); 
	void addCard(Card _card); 
	bool completeSet(); 
	int getSetValue(); 
	void removeCard(Card _card); 

private:
	std::vector<Card> cardSet; 
	int setValue; 

};

#endif