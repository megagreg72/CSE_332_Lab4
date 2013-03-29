#include <vector>
#include <ctime>
#include "Card.h"
#include "Hand.h"

#pragma once
class Deck
{
public:
	Deck(void);
	~Deck(void);
	void add_card(const Card & card);
	void shuffle();
	Card deal();

private:
	vector<Card> _cards;
};

Hand & operator<<(Hand & hand, Deck & deck);

