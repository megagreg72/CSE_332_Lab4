#ifndef Game_h
#define Game_h

#include "stdafx.h"
#include "Deck.h"
#include "Player.h"
#include "FiveCardDraw.h"
#include <string>
#include <vector>

using namespace std;

class Game {

protected:

	static Game * game;
	Deck * deck;
	vector<Player *> players;

public:

	static Game * instance();
	static void start_game(string start);
	static void stop_game();
	void add_player(char * name);
	Player * find_player(string name); // how to make it return 0 if not there?
	virtual ~Game();
	virtual int before_turn(Player & player) = 0;
	virtual int turn(Player & player) = 0;
	virtual int after_turn(Player & player) = 0;
	virtual int before_round() = 0;
	virtual int round() = 0;
	virtual int after_round() = 0;

private:
	
	Game(Game * game);
	void operator=(Game * game);

};

#endif