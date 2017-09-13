#include "Game.h"
#include "Player.h"
#include "Deck.h"
#include "Card.h"
#include <string>

Game::Game(std::string _playerOne, std::string _playerTwo) {
	Player playerOne(_playerOne);
	Player playerTwo(_playerTwo);
	Deck cardDeck();
	goFish = false; 
}

void dealHands() {
	//cardDeck.shuffleDeck();
}

bool Game::checkGoFish() {
	return goFish; 
}

void Game::checkForCard(Player _playerOne, Player _playerTwo, Card _card) {

	if (_playerTwo.checkCard(_card)) {
		_playerOne.addCard(_card);
		_playerTwo.removeCard(_card);
		goFish = false;
	}
	else {
		Card newCard = cardDeck.drawCard(); 
		_playerOne.addCard(newCard); 
		goFish = true; 
	}

}