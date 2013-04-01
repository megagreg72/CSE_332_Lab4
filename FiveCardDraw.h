#ifndef FiveCardDraw_h
#define FiveCardDraw_h

#include "stdafx.h"
#include "game.h"
using namespace std;

class FiveCardDraw: public Game {

public:
	FiveCardDraw();
	virtual int before_turn(Player & p);
	virtual int turn(Player & p);
	virtual int after_turn(Player & p);
	virtual int before_round();
	virtual int round();
	virtual int after_round();

protected:
	size_t dealer;
	Deck * _trash;
	
};

#endif