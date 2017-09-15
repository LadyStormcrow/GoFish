#include "Card.h"
#include "Deck.h"
#include <algorithm>
#include <vector>

Deck::Deck() {
	
	for (int i = 1; i <= 13; i++) {
		for (int j = 1; j <= 4; j++) {
			Card tmpCard = Card(i, j);
			deck.push_back(tmpCard);
		}
	}
}

//shuffle the deck
void Deck::shuffleDeck() {
	std::random_shuffle(deck.begin(), deck.end());
}

//get the deck list
std::vector<Card> Deck::getDeck() {
	return deck; 
}

//draw a card from the deck
Card Deck::drawCard() {
	if (!(deck.empty())) {
		Card topCard = deck[0];
		topCard.changeStatus(1);
		deck.erase(deck.begin());
		return topCard;
	} 
}

//get the length of the deck list
int Deck::deckSize() {
	return deck.size(); 
}

//check if the deck is empty
bool Deck::emptyDeck() {
	if (deck.size() == 0) {
		return true;
	}
	else {
		return false; 
	}
}
