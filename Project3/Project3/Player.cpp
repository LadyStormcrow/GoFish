#include <string>
#include "Player.h"
#include "Card.h"
#include <vector>


Player::Player(std::string _name) {
	playerName = _name; 
	score = 0; 
}

void Player::updateScore() {
	score++;
}

void Player::updateHand(int _index, Card _card) {
	hand[_index] = _card; 
}

void Player::removeCard(Card _card) {
	for(int i = 0; i < hand.size(); i++) {
		if (hand[i].getCardSuite() == _card.getCardSuite() && hand[i].getCardValue() == _card.getCardValue()) {
			hand.erase(hand.begin() + i); 
		}
	}
}

void Player::addCard(Card _card) {
	hand.push_back(_card); 
}

std::vector<Card> Player::getHand() {
	return hand; 
}

bool Player::emptyHand() {
	if (hand.empty()) {
		return true; 
	}
	else {
		return false; 
	}
}

bool Player::checkCard(Card _card) {

	for (int i = 0; i < hand.size(); i++) { 
		if (hand[i].getCardValue() == _card.getCardValue()) {
			return true; 
		}
	}
	return false; 
}