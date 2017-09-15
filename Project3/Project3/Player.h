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
	std::vector<Card> getHand(); 
	bool checkCard(Card _card); 
	void removeCard(Card &_card);  
	bool emptyHand(); 
	Card getCard(int _card); 
	void addSet(int _cardValue);
	bool checkForSet(int _setValue);
	Set& getSet(int _setValue);
	std::vector<Set> getSetList(); 
	void addNewCard(Card _card); 
	int getScore(); 
	void removeSet(int _setValue);
	int handSize(); 
	std::vector<Set> mySets;

private:
	std::string playerName; 
	int score; 
	std::vector<Card> hand; 
	
}; 

#endif