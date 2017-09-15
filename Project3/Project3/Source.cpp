//MAIN

#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include "Set.h"
#include "Game.h"
#include "Player.h"
#include "Deck.h"

int main() {
	std::string playerName;
	int card;
	int turn = 1;
	int sets = 6;
	bool inprogress = true;
	std::vector<Set> setLst;
	srand(time(NULL)); 

	std::cout << "Welcome to GoFish!\n\n\tYou (Player One) will begin. Just ask what if Player Two has a card of the same value.\n\tIf they do, go again, or if not, it's Go Fish!\n\n";

	std::cout << "What's your name? ";
	std::cin >> playerName;

	Game myGame(playerName, "computer");

	myGame.getDeck().shuffleDeck(); 
	myGame.dealHand(myGame.playerOne); //Deal 7 cards to each player
	myGame.dealHand(myGame.playerTwo); 

	while (inprogress) {

		if (turn == 1) { //if it is the player's turn

			if (myGame.playerOne.emptyHand()) { //check if player's hand is empty
				if (!(myGame.getDeck().emptyDeck())) { //if the deck isn't empty
					myGame.dealHand(myGame.playerOne); //give the player a new hand
				}
			}

			setLst = myGame.playerOne.getSetList(); //sets of cards
			myGame.checkHandForSet(myGame.playerOne, setLst); //check if the player already has a completed set in hand

			//Print player hand
			std::vector<Card> playerHand = myGame.playerOne.getHand();
			std::cout << "Your hand:\n";
			for (int i = 0; i < playerHand.size(); i++) {
				std::cout << playerHand[i].getCardValue() << " ";
			}

			std::cout << "\nYour score: " << myGame.playerOne.getScore() << std::endl;
			std::cout << "Player Two score: " << myGame.playerTwo.getScore() << std::endl;
			std::cout << "\nAsk Player Two for a: ";
			std::cin >> card;
			Card playerCard = myGame.playerOne.getCard(card); //get the card in the player's hand 

			if (!(myGame.checkForCardInHand(myGame.playerOne, card))) { //check if that card exists in the player's hand
				while (!(myGame.checkForCardInHand(myGame.playerOne, card))) {
					std::cout << "\nThat card isn't in your hand! Pick one from your hand\n";
					std::cout << "\nAsk Player Two for a: ";
					std::cin >> card;
					Card playerCard = myGame.playerOne.getCard(card);
					if (myGame.checkForCardInHand(myGame.playerOne, card)) {
						myGame.checkForCard(myGame.playerOne, myGame.playerTwo, playerCard);
						break;
					}
				}
			}
			else {
				myGame.checkForCard(myGame.playerOne, myGame.playerTwo, playerCard);
			}
	
			if (myGame.checkGoFish()) { //if other player doesn't have the card
				turn = 0; //it will now be the next player's turn
				std::cout << "\nGo Fish! \n"; 
			}
			else if (!(myGame.checkGoFish())) { //if the other player does have the card
				myGame.playerTwo.getSet(card).removeSetCard(); //remove that card from a player two set
				if (myGame.playerOne.checkForSet(card)) { //check if player one has created a set of that card (they already should have)
					if (myGame.playerOne.getSet(card).completeSet()) { //if the set is complete
						std::cout << "You found a set!"; 
						myGame.removeSetFromHand(myGame.playerOne, card); //remove those cards from the hand
					}
				}
				else if (!(myGame.playerOne.checkForSet(card))) { //if the set does not exist for some reason
					myGame.playerOne.addSet(card); //create a set
					myGame.playerOne.getSet(card).addCard(); //add a card to that set
				}
			}

			if (myGame.setsRemaining() <= 0) { //if all the sets have been found
				inprogress = false;
			}
		}

		else if (turn == 0) {//computer player turn

			if (myGame.playerTwo.emptyHand()) { //check for empty hand
				if (!(myGame.getDeck().emptyDeck())) {
					myGame.dealHand(myGame.playerTwo);
				}
			}

			if (!(myGame.playerTwo.emptyHand())) { //if the hand is not empty check for a complete set
				setLst = myGame.playerTwo.getSetList();
				myGame.checkHandForSet(myGame.playerTwo, setLst);
			}

			//Computer randomly selects card
			std::vector<Card> computerHand = myGame.playerTwo.getHand();
			int randCard = rand() % computerHand.size();
			Card computerCard = computerHand[randCard];

			//display computer cards (debug)
			/*
			std::cout << "\n";
			for (int i = 0; i < computerHand.size(); i++) {
				std::cout << computerHand[i].getCardValue() << " ";
			}
			*/

			std::cout << "\nPlayer Two asked for a '" << computerCard.getCardValue() << "'" << std::endl;

			//check if other player has that card
			myGame.checkForCard(myGame.playerTwo, myGame.playerOne, computerCard);

			if (myGame.checkGoFish()) { //if go fish
				turn = 1;
			}
			else if (!(myGame.checkGoFish())) { //if not go fish 
				std::cout << "Player Two got a card\n"; 
				myGame.playerOne.getSet(card).removeSetCard();
				if (myGame.playerTwo.checkForSet(computerCard.getCardValue())) {
					if (myGame.playerTwo.getSet(computerCard.getCardValue()).completeSet()) {
						myGame.removeSetFromHand(myGame.playerTwo, computerCard.getCardValue());
					}
				}
				else if (!(myGame.playerTwo.checkForSet(computerCard.getCardValue()))) {
					myGame.playerTwo.addSet(computerCard.getCardValue());
					myGame.playerTwo.getSet(computerCard.getCardValue()).addCard();
				}
			}

			if (myGame.setsRemaining() <= 0) { //if all sets have been found
				inprogress = false;
			}
		}
	}

	if (!(inprogress)) { //if the game has ended 
		if (myGame.playerOne.getScore() > myGame.playerTwo.getScore()) { //Player One win
			std::cout << "\n\nCONGRATULATIONS!! YOU WIN!!\n\n"; 
		}
		else if (myGame.playerOne.getScore() < myGame.playerTwo.getScore()) { //Computer win
			std::cout << "\n\nSorry, Player Two won this time :(\n\n"; 
		}
	}

	system("pause"); 

	return 0; 
}