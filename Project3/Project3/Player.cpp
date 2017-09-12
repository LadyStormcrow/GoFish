#include <string>

class Player {
	std::string playerName; 
	int score; 
	int hand[7]; 

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

	int* getHand() {
		return hand; 
	}
}