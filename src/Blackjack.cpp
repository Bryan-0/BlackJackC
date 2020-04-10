#include "Blackjack.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

Blackjack::Blackjack()
{
	// Random Settings
	srand(time(0)); // generate random seeds for nums.
	
	cout << " " << endl;
	cout << "	Welcome to BlackJack Game! (Simple version)" << endl;
	cout << "	Rules are simple: " << endl;
	cout << "	You will be given 2 random cards, you can pick more if you want to." << endl;
	cout << "	If your cards make a total of 21 or is greater than the dealer's total, you win!" << endl;
	cout << " " << endl;
	cout << "	Start Game? (1 for Yes) - (0 for No)" << endl;
}

void Blackjack::generateDeck(int deck[13], int userDeck[8]) {
	for (int i = 0; i < 2; i++) {
		userDeck[i] = deck[rand() % 12];
	}
	
}

void Blackjack::addCard(int deck[13], int userDeck[8]) {
	for (int i = 0; i < 8; i++) {
		if (userDeck[i] > 0) {
			continue;
		} 
		else if (userDeck[i] == 0) {
			userDeck[i] = deck[rand() % 12];
			break;
		}
	}
}

void Blackjack::displayDeck(int userDeck[8]) {
	for (int i = 0; i < 8; i++) {
		if (userDeck[i] > 0) {
			cout << userDeck[i] << endl;
		}
	}
}

void Blackjack::haveAce(int userDeck[8]) {
	int newValue;
	
	for (int i = 0; i < 8; i++) {
		if (userDeck[i] == 1) {
			cout << "You have an Ace!" << endl;
			cout << "To choose a value: " << endl;
			
			while (true) {
				cout << "Please type which (1 or 11)" << endl;
				cin >> newValue;
				if (newValue == 1 || newValue == 11) {
					break;
				} else {
					continue;
				}
			}
			
			userDeck[i] = newValue;
		}
	}
}

void Blackjack::dealerHaveAce(int userDeck[8]) {
	int randomOption = rand() % 2;
	
	for (int i = 0; i < 8; i++) {
		if (userDeck[i] == 1) {
			if (randomOption = 1) {
				userDeck[i] = 1;
			} else if (randomOption == 0){
				userDeck[i] = 11;
			}
		}
	}
}

void Blackjack::clearDeck(int userDeck[8]) {
	for (int i = 0; i < 8; i++) {
		userDeck[i] = 0;
	}
}

int Blackjack::getTotal(int userDeck[8]) {
	int total = 0;
	
	for (int i = 0; i < 8; i++) {
		total += userDeck[i];
	}
	
	return total;
}

bool Blackjack::playerWin(int userDeck[8], int dealerDeck[8]) {
	int playerTotal = 0;
	int dealerTotal = 0;
	
	for (int i = 0; i < 8; i++) {
		playerTotal += userDeck[i];
	}
	
	for (int i = 0; i < 8; i++) {
		dealerTotal += dealerDeck[i];
	}
	
	if (playerTotal > 21) {
		cout << "PLAYER BOOSTED!" << endl;
		return false;
	} else if (dealerTotal > 21) {
		cout << "DEALER BOOSTED!" << endl;
		return true;
	}
	
	if (playerTotal == 21) {
		cout << "PLAYER GOT A BLACKJACK!" << endl;
		return true;
	} else if (dealerTotal == 21) {
		cout << "DEALER GOT A BLACKJACK!" << endl;
		return false;
	} else if (playerTotal > dealerTotal) {
		return true;
	} else if (dealerTotal > playerTotal) {
		return false;
	} else {
		cout << "It's a TIE!" << endl;
		return true;
	}
}
