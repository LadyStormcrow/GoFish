#pragma once
#include <string>

class Player {
public:
	Player(std::string _name);
	void updateSet();
	void updateHand(int _index, Card _card); 
	int* getHand(); 

private:
	std::string playerName; 
	int score; 
	int hand[7]; 
}