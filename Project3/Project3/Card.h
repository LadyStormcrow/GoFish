#pragma once
#ifndef Card_hpp
#define Card_hpp
class Card {

public: 
	Card(int _cardValue, int _suite);
	int cardStatus(); 
	void changeStatus(int _status);
	bool inPlay(); 
	int getCardValue(); 
	int getCardSuite(); 

private:
	int cardValue; 
	int cardSuite; 
	int status; 
};

#endif