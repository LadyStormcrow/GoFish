#include <vector>
#include "Card.h"

class Set {
	std::vector<Card> cardSet; 

	Set() {

	}

	void createSet(Card _cardOne, Card _cardTwo) {
		cardSet.push_back(_cardOne); 
		cardSet.push_back(_cardTwo); 
	}

	void addCard(Card _card) {
		cardSet.push_back(_card); 
	}

	bool completeSet() {
		if (cardSet.size() == 4) {
			return true;
		}
		else {
			return false; 
		}
	}
};