#include "Deck.h"

Deck::Deck(void)
{
}

Deck::Deck(int decks){
	for(int i=0; i < decks; i++){
		for( int j = Card::two; j < Card::ace; j++){
			for ( int k = Card::club; k < Card::spade; k++){
				Card::_RANK jj = (Card::_RANK)j;
				Card::_SUIT kk = (Card::_SUIT)k;
				Card c = Card(jj,kk);
				cout << i << j << k << endl;
				add_card(c);
			}
		}
	}
	shuffle(decks*100);
}

Deck::~Deck(void)
{
	//vector automatically cleans up after itself
}

void Deck::add_card(const Card & card)
{
	_cards.push_back(card);
}

void Deck::shuffle(int num_swaps)
{
	//const int NUM_SHUFFLES = 10;
	int size = (int)_cards.size();
	srand((unsigned int)time(0));
	for(int i = 0; i < num_swaps; i++){
		int r1 = rand() % size;
		int r2 = rand() % size;
		Card temp = _cards[r1];
		_cards[r1] = _cards[r2];
		_cards[r2] = temp;
	}
}

Card Deck::deal()
{
	Card card;
	if(_cards.size() > 0){
		card = _cards.back();
		_cards.pop_back();
	}
	return card;
}

//non-member stuff
Hand & operator<<(Hand & hand, Deck & deck)
{
	Card card = deck.deal();
	hand.insert(card);
	return hand;
}