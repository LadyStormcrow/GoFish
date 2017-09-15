#include <string>
#include "Player.h"
#include "Card.h"
#include <vector>

//Player default initaliser
Player::Player() {
	playerName = "Unknown";
	score = 0;
}

//custom constructor
Player::Player(std::string _name) {
	playerName = _name; 
	score = 0; 
}

//add one to the score
void Player::updateScore() {
	score++;
}

//remove a card from the player's hand
void Player::removeCard(Card &_card) {
	for(int i = 0; i < hand.size(); i++) {
		if (hand[i].getCardValue() == _card.getCardValue()) {
			hand.erase(hand.begin() + i); 
		}
	}
}

//add card to the player's hand
void Player::addNewCard(Card _card) {
	bool setFound = false;
	hand.push_back(_card);
	for (int i = 0; i < mySets.size(); i++) {
		if (mySets[i].getSetValue() == _card.getCardValue()) {
			mySets[i].addCard();
			setFound = true;
		}
	}

	if (!(setFound)) {
		Set newSet(_card.getCardValue());
		newSet.addCard();
		mySets.push_back(newSet);
	}
}

//return the player's hand
std::vector<Card> Player::getHand() {
	return hand; 
}


//get a certain card from the hand
Card Player::getCard(int _card) {

	for (int i = 0; i < hand.size(); i++) {
		if (hand[i].getCardValue() == _card) {
			return hand[i]; 
		}
	}
}

//check if the player's hand is empty
bool Player::emptyHand() {
	if (hand.size() == 0) {
		return true; 
	}
	else {
		return false; 
	}
}


//check a card exists
bool Player::checkCard(Card _card) {

	for (int i = 0; i < hand.size(); i++) { 
		if (hand[i].getCardValue() == _card.getCardValue()) {
			return true; 
		}
	}
	return false; 
}

//add a set 
void Player::addSet(int _cardValue) {

	Set newSet(_cardValue);
	newSet.addCard(); 
	mySets.push_back(newSet);

}

//check if a set already exists
bool Player::checkForSet(int _setValue) {

	for (int i = 0; i < mySets.size(); i++) {
		if (mySets[i].getSetValue() == _setValue) {
			return true;
		}
	}
	return false;
}


//get a set of a certain value
Set& Player::getSet(int _setValue) {
	for (int i = 0; i < mySets.size(); i++) {
		if (mySets[i].getSetValue() == _setValue) {
			return mySets[i];
		}
	}
}

//get the player score
int Player::getScore() {
	return score; 
}

//remove set from the set list
void Player::removeSet(int _setValue) {
	for (int i = 0; i < mySets.size(); i++) {
		if (mySets[i].getSetValue() == _setValue) {
			mySets.erase(mySets.begin() + i); 
		}
	}
}

//get the list of sets
std::vector<Set> Player::getSetList() {
	return mySets; 
}

//the size of the player's hand
int Player::handSize() {
	return hand.size(); 
}