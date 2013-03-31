#include "stdafx.h"
#include "game.h"

using namespace std;


Game * Game::instance() {
	if (game = 0) {
		throw "instance_not_available";
	} 
	else {
		return game;
	}
}

// method to start a FiveCardDraw game if there is not already a game started
void Game::start_game(string start) {
	if (game != 0) {
		throw "game_already_started";		// if game != 0, then a game has been instanciated
	} else if (start.compare("FiveCardDraw")) {
		throw "unknown_game";				// for this lab, only FiveCardDraw games are known
	} else {
		//game = new FiveCardDraw();
		game = 0;
	}
}

//method to stop a game in progress
void Game::stop_game() {
	if (game == 0) {
		throw "no_game_in_progress";		// throw exception if there is no game in progress
	} else {
		delete game;					// if there is a game, delete it and set the pointer to 0
		game = 0;
	}
}

// method to add a player to the game as long as there is no player by that name
void Game::add_player(char * name) {
	for (unsigned int i = 0; i < players.size(); i++) {			// search through the players vector to compare all existing players' names to the parameter
		if (players[i]->_name == name) {
			throw "already_playing";			// if any are the same, throw an exception
		}
	}
	players.push_back(new Player(name));	// if none are the same, add the new player to the vector
}

// method to return a player from the game as long as there is a player by that name
Player * Game::find_player(string name) {
	for (unsigned int i = 0; i < players.size(); i++) {			// search through the players vector to compare the names
		if (players[i]->_name == name) {
			return players[i];				// if there is a match, return it
		}
	}
	return 0;								// if there are no matches, return 0
}

Game::~Game() {
	while (players.size() != 0) {		// for every player in the game, delete the player - documentation says pop_back deletes the element, is this enough?
		players.pop_back();
	}
}
