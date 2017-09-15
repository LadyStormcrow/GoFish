#include <vector>
#include "Player.h"
#include "Set.h"
#include "Card.h"

//set initalizer
Set::Set(int _value) {
	setValue = _value; 
	cardAmount = 0; 
}

//add a card to a set
void Set::addCard() {
	cardAmount++; 
}

//remove the card from a set
void Set::removeSetCard() {
	cardAmount--;
}

//get the value of the set (i.e. the value of the cards in the set)
int Set::getSetValue() {
	return setValue; 
}

//check if the set is complete
bool Set::completeSet() {
	if (cardAmount == 4) {
		return true;
	}
	else {
		return false; 
	}
}