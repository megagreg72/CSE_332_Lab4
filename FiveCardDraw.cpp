#include "stdafx.h"
#include "FiveCardDraw.h"

FiveCardDraw::FiveCardDraw(){ 
	dealer = 0;
	//create all 52 cards
	//add_card them to Deck
	_deck = Deck(1);
	_trash = Deck();
}


int FiveCardDraw::before_turn(Player & p){
	cout << "It is your turn: " << p._name << endl;
	cout << "Your hand is: " << endl;
	cout << p._hand << endl;
	
	return 0;
}

int FiveCardDraw::turn(Player & p){
	
	
	
	
	return 0;
}

int FiveCardDraw::after_turn(Player & p){
	
	return 0;
}

int FiveCardDraw::before_round(){
	
	return 0;
}

int FiveCardDraw::round(){
	
	
	return 0;
}

int FiveCardDraw::after_round(){
	Player * winner = _players[0];
	for(int i = 0; i < _players.size(); i++){
		if(_players[i] == winner){
			_players[i]->won++;
		}
		else{
			_players[i]->lost++;
		}
	}



	return 0;
}
