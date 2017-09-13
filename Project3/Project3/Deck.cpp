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

void Deck::shuffleDeck() {
	std::random_shuffle(deck.begin(), deck.end());
}

Card Deck::drawCard() {
	Card topCard = deck[0]; 
	deck.erase(deck.begin()); 
	return topCard
}
