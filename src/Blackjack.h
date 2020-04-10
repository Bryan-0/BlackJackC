#ifndef BLACKJACK_H
#define BLACKJACK_H

class Blackjack
{
	public:
		Blackjack();
		
		void generateDeck(int deck[13], int userDeck[8]);
		void addCard(int deck[13], int userDeck[8]);
		void displayDeck(int userDeck[8]);
		void haveAce(int userDeck[8]);
		void dealerHaveAce(int userDeck[8]);
		void clearDeck(int userDeck[8]);
		
		int getTotal(int userDeck[8]);
		
		bool playerWin(int userDeck[8], int dealerDeck[8]);
		
};

#endif
