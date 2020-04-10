#include <iostream>
#include "Blackjack.h"

using namespace std;

int main() {
	
	Blackjack gameManager;
	
	int startOption;
	cin >> startOption;
	
	if (startOption == 1) {
	
		int deck[13] = {
			2, 3, 4, 5, 6, 7, 8, 9, // Normal cards
			10, 10, 10, 1, // J, Q, K, or 10. // Ace 1 or 11
			10
		};
	
		int playerDeck[8] = {0, 0, 0, 0, 0, 0, 0, 0}; // Limits 8 cards per deck
		int dealerDeck[8] = {0, 0, 0, 0, 0, 0, 0, 0}; // Limits 8 cards per deck
	
	
		// Game Loop
		while (true) {
		
			gameManager.generateDeck(deck, playerDeck);
			gameManager.generateDeck(deck, dealerDeck);
			gameManager.dealerHaveAce(dealerDeck);
			
			cout << "YOUR DECK: " << endl;
			gameManager.displayDeck(playerDeck);
			gameManager.haveAce(playerDeck);
			cout << "TOTAL SUM: " << gameManager.getTotal(playerDeck) << endl;
			
			if (gameManager.getTotal(playerDeck) == 21) {
				cout << "PLAYER GOT A BLACKJACK!" << endl;
				
				int playAgain;
				
				cout << "" << endl;
				cout << "Do you want to play again? (1 for Yes) -- (0 for No)" << endl;
				cin >> playAgain;
				
				if (playAgain == 1) {
					gameManager.clearDeck(playerDeck);
					gameManager.clearDeck(dealerDeck);
					continue;
				} else {
					break;
				}
				
			} else if (gameManager.getTotal(dealerDeck) == 21) {
				cout << "DEALER GOT A BLACKJACK!" << endl;
				
				int playAgain;
				
				cout << "" << endl;
				cout << "Do you want to play again? (1 for Yes) -- (0 for No)" << endl;
				cin >> playAgain;
				
				if (playAgain == 1) {
					gameManager.clearDeck(playerDeck);
					gameManager.clearDeck(dealerDeck);
					continue;
				} else {
					break;
				}
				
			} else if (gameManager.getTotal(playerDeck) > 21) {
				cout << "PLAYER BOOSTED!" << endl;
				
				int playAgain;
				
				cout << "" << endl;
				cout << "Do you want to play again? (1 for Yes) -- (0 for No)" << endl;
				cin >> playAgain;
				
				if (playAgain == 1) {
					gameManager.clearDeck(playerDeck);
					gameManager.clearDeck(dealerDeck);
					continue;
				} else {
					break;
				}
				
			} else if (gameManager.getTotal(dealerDeck) > 21) {
				cout << "DEALER BOOSTED!" << endl;
				
				int playAgain;
				
				cout << "" << endl;
				cout << "Do you want to play again? (1 for Yes) -- (0 for No)" << endl;
				cin >> playAgain;
				
				if (playAgain == 1) {
					gameManager.clearDeck(playerDeck);
					gameManager.clearDeck(dealerDeck);
					continue;
				} else {
					break;
				}
				
			}
			
			cout << "" << endl;
			
			cout << "DEALER DECK: " << endl;
			gameManager.displayDeck(dealerDeck);
			cout << "TOTAL SUM: " << gameManager.getTotal(dealerDeck) << endl;
			
			cout << "" << endl;
			
			int option;
			
			while (true) {
				cout << "Do you want to add more cards? (1 for Yes) - (0 for No)" << endl;
				cin >> option;
			
				if (option == 1) {
					cout << "YOUR DECK: " << endl;
					gameManager.addCard(deck, playerDeck);
					gameManager.displayDeck(playerDeck);
					gameManager.haveAce(playerDeck);
					cout << "TOTAL SUM: " << gameManager.getTotal(playerDeck) << endl;
					
					if (gameManager.getTotal(playerDeck) == 21) {
						cout << "PLAYER GOT A BLACKJACK!" << endl;
				
						int playAgain;
				
						cout << "" << endl;
						cout << "Do you want to play again? (1 for Yes) -- (0 for No)" << endl;
						cin >> playAgain;
				
						if (playAgain == 1) {
							gameManager.clearDeck(playerDeck);
							gameManager.clearDeck(dealerDeck);
							continue;
						} else {
							break;
						}
					} else if (gameManager.getTotal(playerDeck) > 21) {
						cout << "PLAYER BOOSTED!" << endl;
				
						int playAgain;
				
						cout << "" << endl;
						cout << "Do you want to play again? (1 for Yes) -- (0 for No)" << endl;
						cin >> playAgain;
				
						if (playAgain == 1) {
							gameManager.clearDeck(playerDeck);
							gameManager.clearDeck(dealerDeck);
							continue;
						} else {
							break;
						}
				
					}
					
				continue;
				}
				else {
					break;
				}
			}
			
			if (gameManager.playerWin(playerDeck, dealerDeck)) {
				cout << "PLAYER WIN!" << endl;
				
				int playAgain;
				
				cout << "" << endl;
				cout << "Do you want to play again? (1 for Yes) -- (0 for No)" << endl;
				cin >> playAgain;
				
				if (playAgain == 1) {
					gameManager.clearDeck(playerDeck);
					gameManager.clearDeck(dealerDeck);
					continue;
				} else {
					break;
				}
				
			} else {
				cout << "DEALER WIN!" << endl;
				
				int playAgain;
				
				cout << "" << endl;
				cout << "Do you want to play again? (1 for Yes) -- (0 for No)" << endl;
				cin >> playAgain;
				
				if (playAgain == 1) {
					gameManager.clearDeck(playerDeck);
					gameManager.clearDeck(dealerDeck);
					continue;
				} else {
					break;
				}
			}
		
		}
		
	} 
	else {
		cout << "See you later!" << endl;
	}
	
	
	cout << "Thanks for playing Blackjack simple version!" << endl;
	cout << "Developed by Brayan Ayala in C++" << endl;
}
