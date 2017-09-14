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
	bool inprogress = true; 

	std::cout << "GoFish!\n\n"; 

	std::cout << "What's your name? "; 
	std::cin >> playerName; 

	Game myGame(playerName, "computer"); 
	myGame.dealHands(); //1. Deal 7 cards to each player
	

	//Check if user has cards
	//2. User asks for card
	while (inprogress) {

		if (turn == 1) {

			std::vector<Card> playerHand = myGame.playerOne.getHand();

			for (int i = 0; i < playerHand.size(); i++) {
				std::cout << playerHand[i].getCardValue() << " ";
			}

			std::cout << "\nAsk for a: ";
			std::cin >> card;

			myGame.checkForCard(myGame.playerOne, myGame.playerTwo, myGame.playerOne.getCard(card));

			if (myGame.checkGoFish()) {
				turn = 0;
				myGame.drawCard(myGame.playerOne); 
				std::cout << "\nGo Fish! \n"; 
			}
			else if (!(myGame.checkGoFish())) {
				if (myGame.playerOne.checkForSet(card)) {
					myGame.playerOne.getSet(card).addCard();
					if (myGame.playerOne.getSet(card).completeSet()) {
						myGame.playerOne.updateScore();
						for (int i = 0; i < 4; i++) {
							Card cardToRemove = myGame.playerOne.getCard(myGame.playerOne.getCard(card).getCardValue());
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

			std::vector<Card> computerHand = myGame.playerTwo.getHand();
			int randCard = rand() % computerHand.size();
			Card computerCard = computerHand[randCard];

			for (int i = 0; i < computerHand.size(); i++) {
				std::cout << computerHand[i].getCardValue() << " ";
			}

			std::cout << "\nPlayer Two asked for a " << computerCard.getCardValue(); 

			myGame.checkForCard(myGame.playerTwo, myGame.playerOne, computerCard);

			if (myGame.checkGoFish()) {
				turn = 1;
				myGame.drawCard(myGame.playerTwo); 
				std::cout << "\nGo Fish!\n"; 
			}
			else if (!(myGame.checkGoFish())) {
				if (myGame.playerTwo.checkForSet(computerCard.getCardValue())) {
					myGame.playerTwo.getSet(computerCard.getCardValue()).addCard();
					if (myGame.playerTwo.getSet(computerCard.getCardValue()).completeSet()) {
						myGame.playerTwo.updateScore();
						for (int i = 0; i < 4; i++) {
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
	}

	//3. Get card or 'Go Fish'
		//3(i) If get card - ask for another card from hand
			//Check for card set
			//if complete set made - score + 1 and remove cards from hand 
			//else create set or add card to set
		//3(ii) Else computer turn

	//Check if computer had 7 cards
	//4. Computer asks for card
		//Repeat step 3



	system("pause"); 

	return 0; 
}