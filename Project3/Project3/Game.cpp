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
	sets = 12; 
	cardDeck.shuffleDeck();
}

//return the game deck in use
Deck Game::getDeck() {
	return cardDeck; 
}

//deal a hand to the player
void Game::dealHand(Player &_player) { 

	int range = std::min(cardDeck.deckSize(), 7); 

	for (int i = 0; i < range; i++) {
		Card card = cardDeck.drawCard();
		_player.addNewCard(card); 
	}
}

//check for go fish
bool Game::checkGoFish() {
	return goFish; 
}

//check if a player has a card the other player asked for
void Game::checkForCard(Player &_playerOne, Player &_playerTwo, Card &_card) {

	if (_playerTwo.checkCard(_card)) {
		_playerOne.addNewCard(_playerTwo.getCard(_card.getCardValue()));
		_playerTwo.removeCard(_card);
		goFish = false;
	}
	else {
		if (!(cardDeck.emptyDeck())) {
			Card newCard = cardDeck.drawCard();
			_playerOne.addNewCard(newCard);
		}
		goFish = true; 
	}

}

//check if there is already a set in the hand, might happen when a card is drawn
void Game::checkHandForSet(Player &_player, std::vector<Set> setLst) {
	for (int j = 0; j < setLst.size(); j++) {
		int value;
		if (setLst[j].completeSet()) {
			_player.updateScore();
			for (int i = 0; i < 4; i++) {
				value = setLst[j].getSetValue();
				Card cardToRemove = _player.getCard(value);
				_player.removeCard(cardToRemove);
			}
			_player.removeSet(value);
			sets--;
		}
	}
}

//check the amount of sets remaining
int Game::setsRemaining() {
	return sets; 
}

//remove the cards that are in set
void Game::removeSetFromHand(Player &_player, int _value) {
	_player.updateScore();
	for (int i = 0; i < 4; i++) {
		Card cardToRemove = _player.getCard(_value);
		_player.removeCard(cardToRemove);
	}
	_player.removeSet(_value);
	sets--;
}

//check if a card exists in the player's hand
bool Game::checkForCardInHand(Player _player, int _cardValue) {
	std::vector<Card> playerHand = _player.getHand(); 
	for (int i = 0; i < _player.handSize(); i ++) {
		if (playerHand[i].getCardValue() == _cardValue) {
			return true; 
		}
	}
	return false; 
}