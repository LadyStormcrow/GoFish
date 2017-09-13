#pragma once

#include <vector>
#include <string>
#include "Player.h"
#include "Card.h"

#ifndef Game_hpp
#define Game_hpp


class Game {
public:
	Game(std::string _playerOne, std::string _playerTwo);
	bool checkGoFish(); 
	void checkForCard(Player _playerOne, Player _playerTwo, Card _card);
	void dealHands(); 
	Player playerOne;
	Player playerTwo;

private:
	Deck cardDeck; 
	bool goFish;

};

#endif