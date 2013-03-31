#include <vector>
#include <ctime>
#include "Card.h"
#include "Hand.h"

#pragma once
class Deck
{
public:
	Deck(void);
	Deck(int decks);
	~Deck(void);
	void add_card(const Card & card);
	void shuffle(int num_swaps);
	Card deal();

private:
	vector<Card> _cards;
};

Hand & operator<<(Hand & hand, Deck & deck);

