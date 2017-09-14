#include <string>
#include "Player.h"
#include "Card.h"
#include <vector>

Player::Player() {
	playerName = "Unknown";
	score = 0;
}

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

	Set removeCard = getSet(_card.getCardValue()); 
	removeCard.removeCard(); 
}

void Player::addCard(Card _card) {
	hand.push_back(_card); 
}

std::vector<Card> Player::getHand() {
	return hand; 
}

Card Player::getCard(int _card) {

	for (int i = 0; i < hand.size(); i++) {
		if (hand[i].getCardValue() == _card) {
			return hand[i]; 
		}
	}
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

void Player::addSet(int _cardValue) {

	Set newSet(_cardValue);
	newSet.addCard();
	mySets.push_back(newSet);

}

bool Player::checkForSet(int _setValue) {

	for (int i = 0; i < mySets.size(); i++) {
		if (mySets[i].getSetValue() == _setValue) {
			return true;
		}
	}
	return false;
}

Set Player::getSet(int _setValue) {
	for (int i = 0; i < mySets.size(); i++) {
		if (mySets[i].getSetValue() == _setValue) {
			return mySets[i];
		}
	}
}