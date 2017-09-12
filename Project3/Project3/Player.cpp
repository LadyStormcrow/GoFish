#include <string>
#include "Card.h"
#include <vector>

class Player {
	std::string playerName; 
	int score; 
	std::vector<Card> hand; 

	Player(std::string _name) {
		playerName = _name; 
		score = 0; 
	}

	void updateScore() {
		score++;
	}

	void updateHand(int _index, Card _card) {
		hand[_index] = _card; 
	}

	void removeCard(int _index) {
		hand.erase(hand.begin() + _index); 
	}

	void addCard(Card _card) {
		hand.push_back(_card); 
	}

	std::vector<Card> getHand() {
		return hand; 
	}

	bool emptyHand() {
		if (hand.empty()) {
			return true; 
		}
		else {
			return false; 
		}
	}

	bool checkCard(Card _card) {

		for (int i = 0; i < hand.size(); i++) { //change 7 to hand length
			if (hand[i].getCardValue() == _card.getCardValue()) {
				return true; 
			}
		}
		return false; 
	}
}