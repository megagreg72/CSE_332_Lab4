#include "Deck.h"

Deck::Deck(void)
{
}

Deck::~Deck(void)
{
	//vector automatically cleans up after itself
}

void Deck::add_card(const Card & card)
{
	_cards.push_back(card);
}

void Deck::shuffle()
{
	const int NUM_SHUFFLES = 10;
	int size = (int)_cards.size();
	srand(time(0));
	for(int i = 0; i < size*NUM_SHUFFLES; i++){
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