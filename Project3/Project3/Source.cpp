//MAIN

#include <string>
#include <iostream>
#include "Player.h"
#include "Deck.h"

int main() {
	std::string playerName; 

	std::cout << "What's your name? "; 
	std::cin >> playerName; 

	 //create card deck
	Player person(playerName); //create user player
	Player computer("computer"); //create computer player 

	//1. Deal 7 cards to each player

	//Check if user has 7 cards
	//2. User asks for card

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

void play(Player _playerOne, Player _playerTwo, Card _card) {

	if (_playerTwo.checkCard(_card)) {
		_playerOne.addCard(_card); 
		_playerTwo.removeCard(_card); 
		goFish(false); 
	}
	else {
		std::cout << "Go Fish!" << std::endl; 
	}

}
