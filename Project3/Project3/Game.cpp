#include "Game.h"
#include "Player.h"
#include "Deck.h"
#include "Card.h"
#include <string>

Game::Game(std::string _playerOne, std::string _playerTwo) {
	playerOne = Player(_playerOne);
	playerTwo = Player(_playerTwo);
	cardDeck = Deck(); 
	goFish = false;
}

void Game::dealHands() {
	cardDeck.shuffleDeck();

	for (int i = 0; i < 7; i++) {
		Card card = cardDeck.drawCard();  
		playerOne.addCard(card); 
	}

	for (int j = 0; j < 7; j++) {
		Card cardTwo = cardDeck.drawCard();
		playerTwo.addCard(cardTwo);
	}
}

void Game::dealPlayerNewHand(Player _player) {

	for (int i = 0; i < 7; i++) {
		Card card = cardDeck.drawCard();
		_player.addCard(card);
	}
}

void Game::drawCard(Player _player) {
	Card newCard = cardDeck.drawCard(); 
	_player.addCard(newCard); 
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