#pragma once
#include <string>
#include "Set.h"
#include "Card.h"
#include <vector>

#ifndef Player_hpp
#define Player_hpp

class Player {

public:
	Player();
	Player(std::string _name);
	void updateScore();
	void updateHand(int _index, Card _card); 
	std::vector<Card> getHand(); 
	bool checkCard(Card _card); 
	void removeCard(Card &_card); 
	void addCard(Card _card); 
	bool emptyHand(); 
	Card getCard(int _card); 
	void addSet(int _cardValue);
	bool checkForSet(int _setValue);
	Set& getSet(int _setValue);
	void addNewCard(Card _card); 
	int getScore(); 
	std::vector<Set> mySets;

private:
	std::string playerName; 
	int score; 
	std::vector<Card> hand; 
	
}; 

#endif