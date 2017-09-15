#include <vector>
#include "Player.h"
#include "Set.h"
#include "Card.h"

Set::Set(int _value) {
	setValue = _value; 
	cardAmount = 0; 
}

void Set::addCard() {
	cardAmount++; 
}

int Set::getSetValue() {
	return setValue; 
}


void Set::removeSetCard() {
	cardAmount--; 
}

bool Set::completeSet() {
	if (cardAmount == 4) {
		return true;
	}
	else {
		return false; 
	}
}