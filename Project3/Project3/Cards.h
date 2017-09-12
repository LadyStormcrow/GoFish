#pragma once

class Card {

public: 
	Card(); 
	int cardStatus(); 
	void changeStatus(int _status);
	bool inPlay(); 
	bool inDeck(); 
	bool inSet(); 

private:
	int cardValue; 
	int cardSuite; 
	int status; 
};