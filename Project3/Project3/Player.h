#pragma once
#include <string>
#include "Card.h"
#include <vector>

#ifndef Player_hpp
#define Player_hpp

class Player {
public:
	Player(std::string _name);
	void updateScore();
	void updateHand(int _index, Card _card); 
	Card* getHand(); 
	bool checkCard(Card _card); 
	void removeCard(int _index); 
	void addCard(Card _card); 
	bool emptyHand(); 

private:
	std::string playerName; 
	int score; 
	std::vector<Card> hand; 
}

#endif