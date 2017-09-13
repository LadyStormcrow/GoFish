#include "Card.h"


Card::Card(int _cardValue, int _suite) {
	cardValue = _cardValue; 
	cardSuite = _suite; 
	status = 0; 
}

int Card::getCardValue() {
	return cardValue; 
}

int Card::getCardSuite() {
	return cardSuite; 
}

int Card::cardStatus() {
	return status;
}

void Card::changeStatus(int _status) {
	status = _status; 
}

bool Card::inDeck() {
	if (status == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Card::inPlay() {
	if (status == 1) {
		return true;
	}
	else {
		return false;
	}
}

bool Card::inSet() {
	if (status == 2) {
		return true;
	}
	else {
			return false;
	}
}