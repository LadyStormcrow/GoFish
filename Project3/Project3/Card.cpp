#include "Card.h"

//card initaliser
Card::Card(int _cardValue, int _suite) {
	cardValue = _cardValue; 
	cardSuite = _suite; 
	status = 0; 
}

//get the value of the card
int Card::getCardValue() {
	return cardValue; 
}

//get the card suite
int Card::getCardSuite() {
	return cardSuite; 
}

//get the card status
int Card::cardStatus() {
	return status;
}

//change the card status
void Card::changeStatus(int _status) {
	status = _status; 
}

//check if the card is in play
bool Card::inPlay() {
	if (status == 1) {
		return true;
	}
	else {
		return false;
	}
}