

class Card {
	int cardValue; 
	int cardSuite; 
	int status;

	Card(int _cardValue, int _suite) {
		cardValue = _cardValue; 
		cardSuite = _suite; 
		status = 0; 
	}

	int getCardValue() {
		return cardValue; 
	}

	int getCardSuite() {
		return cardSuite; 
	}

	int cardStatus() {
		return status;
	}

	void changeStatus(int _status) {
		status = _status; 
	}

	bool inDeck() {
		if (status == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	bool inPlay() {
		if (status == 1) {
			return true;
		}
		else {
			return false;
		}
	}

	bool inSet() {
		if (status == 2) {
			return true;
		}
		else {
			return false;
		}
	}

};