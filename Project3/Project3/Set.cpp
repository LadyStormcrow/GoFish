#include <vector>
#include "Set.h"
#include "Card.h"

Set::Set(int _value) {
	setValue = _value; 
}

void Set::createSet(Card _cardOne, Card _cardTwo) {
	cardSet.push_back(_cardOne); 
	cardSet.push_back(_cardTwo); 
}

void Set::addCard(Card _card) {
	cardSet.push_back(_card); 
}

int Set::getSetValue() {
	return setValue; 
}

void Set::removeCard(Card _card) {
	auto found = std::find(cardSet.begin(), cardSet.end(), _card); 
	cardSet.erase(found); 
}

bool Set::completeSet() {
	if (cardSet.size() == 4) {
		return true;
	}
	else {
		return false; 
	}
}