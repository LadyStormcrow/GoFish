/*GAME: describes functions that used in the game*/
#pragma once

#include <vector>
#include <string>
#include "Player.h"
#include "Card.h"
#include "Deck.h"

#ifndef Game_hpp
#define Game_hpp

class Game {
public:
	Game(std::string _playerOne, std::string _playerTwo); //game initaliser
	Deck getDeck(); //get the game deck
	bool checkGoFish(); //check for go fish
	void checkForCard(Player &_playerOne, Player &_playerTwo, Card &_card); //check if a player has a card another player requested
	void dealHand(Player &_player); //deal a hand
	void checkHandForSet(Player &_player, std::vector<Set> setLst); 
	int setsRemaining(); 
	void removeSetFromHand(Player &_player, int _value); 
	bool checkForCardInHand(Player _player, int _cardValue); 
	Player playerOne;
	Player playerTwo;

private:
	Deck cardDeck; 
	bool goFish;
	int sets; 
};

#endif