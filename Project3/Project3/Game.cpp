#include "Game.h"
#include "Player.h"
#include "Deck.h"
#include "Card.h"
#include <string>
#include <algorithm>

Game::Game(std::string _playerOne, std::string _playerTwo) {
	playerOne = Player(_playerOne);
	playerTwo = Player(_playerTwo);
	cardDeck = Deck(); 
	goFish = false;
}

Deck Game::getDeck() {
	return cardDeck; 
}

void Game::dealHands() {
	cardDeck.shuffleDeck();

	for (int i = 0; i < 7; i++) {
		Card card = cardDeck.drawCard();
		if (playerOne.checkForSet(card.getCardValue())) {
			playerOne.getSet(card.getCardValue()).addCard();
		}
		else {
			playerOne.addSet(card.getCardValue()); 
		}
		playerOne.addCard(card); 
	}

	for (int j = 0; j < 7; j++) {
		Card card = cardDeck.drawCard();
		if (playerTwo.checkForSet(card.getCardValue())) {
			playerTwo.getSet(card.getCardValue()).addCard();
		}
		else {
			playerTwo.addSet(card.getCardValue());
		}
		playerTwo.addCard(card);
	}
}

void Game::dealPlayerNewHand(Player _player) {

	int range = std::min(cardDeck.deckSize(), 7); 

	for (int i = 0; i < 7; i++) {
		Card card = cardDeck.drawCard();
		if (_player.checkForSet(card.getCardValue())) {
			_player.getSet(card.getCardValue()).addCard();
		}
		else {
			_player.addSet(card.getCardValue());
		}
		_player.addCard(card);
	}
}

void Game::drawCard(Player &_player) {
	Card newCard = cardDeck.drawCard(); 
	_player.addCard(newCard); 
}


bool Game::checkGoFish() {
	return goFish; 
}

void Game::checkForCard(Player &_playerOne, Player &_playerTwo, Card &_card) {

	if (_playerTwo.checkCard(_card)) {
		_playerOne.addNewCard(_playerTwo.getCard(_card.getCardValue()));
		_playerTwo.removeCard(_card);
		goFish = false;
	}
	else {
		Card newCard = cardDeck.drawCard(); 
		_playerOne.addNewCard(newCard); 
		goFish = true; 
	}

}