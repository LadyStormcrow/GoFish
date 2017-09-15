//MAIN

#include <string>
#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Deck.h"

int main() {
	std::string playerName; 
	int card; 
	int turn = 1; 
	int sets = 13; 
	bool inprogress = true; 
	bool win = false; 

	std::cout << "Welcome to GoFish!\n\n\tYou (Player One) will begin. Just ask what if Player Two has a card of the same value.\n\tIf they do, go again, or if not, it's Go Fish!\n\n"; 

	std::cout << "What's your name? "; 
	std::cin >> playerName; 

	Game myGame(playerName, "computer"); 
	myGame.dealHands(); //1. Deal 7 cards to each player
	

	//Check if user has cards
	//2. User asks for card
	while (inprogress) {

		if (turn == 1) {

			if (myGame.playerOne.emptyHand()) {
				if (!(myGame.getDeck().emptyDeck())) {
					myGame.dealPlayerNewHand(myGame.playerOne);
				}
			}

			std::vector<Card> playerHand = myGame.playerOne.getHand();
			std::cout << "\n"; 
			for (int i = 0; i < playerHand.size(); i++) {
				std::cout << playerHand[i].getCardValue() << " ";
			}

			std::cout << "\nAsk Player Two for a: ";
			std::cin >> card;

			myGame.checkForCard(myGame.playerOne, myGame.playerTwo, myGame.playerOne.getCard(card));
			
			if (myGame.checkGoFish()) {
				turn = 0;
				std::cout << "\nGo Fish! \n"; 
			}
			else if (!(myGame.checkGoFish())) {
				myGame.playerTwo.getSet(card).removeSetCard();
				if (myGame.playerOne.checkForSet(card)) {
					if (myGame.playerOne.getSet(card).completeSet()) {
						myGame.playerOne.updateScore();
						for (int i = 0; i < 4; i++) {
							sets--; 
							Card cardToRemove = myGame.playerOne.getCard(card);
							myGame.playerOne.removeCard(cardToRemove);
						}
					}
				}
				else if (!(myGame.playerOne.checkForSet(card))) {
					myGame.playerOne.addSet(card);
					myGame.playerOne.getSet(card).addCard();
				}
			}
		}
		else if (turn == 0) {

			if (myGame.playerTwo.emptyHand()) {
				if (!(myGame.getDeck().emptyDeck())) {
					myGame.dealPlayerNewHand(myGame.playerTwo);
				}
			}

			//Computer randomly selects card
			std::vector<Card> computerHand = myGame.playerTwo.getHand();
			int randCard = rand() % computerHand.size();
			Card computerCard = computerHand[randCard];

			//display computer cards (debug)
			std::cout << "\n";
			for (int i = 0; i < computerHand.size(); i++) {
				std::cout << computerHand[i].getCardValue() << " ";
			}

			std::cout << "\nPlayer Two asked for a " << computerCard.getCardValue() << std::endl;

			myGame.checkForCard(myGame.playerTwo, myGame.playerOne, computerCard);

			if (myGame.checkGoFish()) {
				turn = 1;
				std::cout << "\nGo Fish!\n"; 
			}
			else if (!(myGame.checkGoFish())) {
				if (myGame.playerTwo.checkForSet(computerCard.getCardValue())) {
					if (myGame.playerTwo.getSet(computerCard.getCardValue()).completeSet()) {
						myGame.playerTwo.updateScore();
						for (int i = 0; i < 4; i++) {
							sets--; 
							Card cardToRemove = myGame.playerTwo.getCard(computerCard.getCardValue());
							myGame.playerTwo.removeCard(cardToRemove);
						}
					}
				}
				else if (!(myGame.playerOne.checkForSet(card))) {
					myGame.playerOne.addSet(card);
					myGame.playerOne.getSet(card).addCard();
				}
			}
		}

		if (sets == 0) {
			inprogress = false; 
		}
	}

	if (!(inprogress)) {
		if (myGame.playerOne.getScore() > myGame.playerTwo.getScore()) {
			std::cout << "\n\nCONGRATULATIONS!! YOU WIN!!"; 
		}
		else if (myGame.playerOne.getScore() < myGame.playerTwo.getScore()) {
			std::cout << "\n\nSorry, Player Two won this time :("; 
		}
	}

	system("pause"); 

	return 0; 
}