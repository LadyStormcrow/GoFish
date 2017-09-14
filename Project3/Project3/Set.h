#pragma once

#include <vector>
#include "Card.h"

#ifndef Set_hpp
#define Set_hpp


class Set {
public: 
	Set(int _value); 
	void addCard(); 
	bool completeSet(); 
	int getSetValue(); 
	void removeCard(); 

private:
	std::vector<Card> cardSet; 
	int setValue; 
	int cardAmount;

};

#endif