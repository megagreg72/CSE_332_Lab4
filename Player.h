#ifndef Player_h
#define Player_h

#include "Card.h"
#include "Hand.h"
#include "Deck.h"
using namespace std;


struct Player{
	string _name;
	Hand _hand;
	unsigned int won;
	unsigned int lost;
	Player(string name);

	void read_file (string in_file, unsigned int & won, unsigned int & lost);

};

ostream& operator<<(ostream &out, const Player &p);




#endif