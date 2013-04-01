#include "stdafx.h"
#include "Player.h"

Player::Player(string name){
	_name = name;
	_hand = Hand();
	won = 0;
	lost = 0;
	//const char * foo = name.c_str();
	//char * mutable_foo = foo;

	read_file(name, won, lost); //reads from file: name, wins, losses
}


void Player::read_file (string name, unsigned int & won, unsigned int & lost){
	vector<string> vs;
	string txt = ".txt";
	string file_name = name + txt;
	ifstream ifs (file_name);
	if( ifs ){//If input file cannot be opened/doesn't exist
		string word;
		while(ifs >> word){ //put input stream into vector of strings
			vs.push_back(word);
		}

		if(vs[0] == name){ //file has structure: Name Wins Losses (Ex: Daniel 1 2)
			won = stoi(vs[1]);
			lost = stoi(vs[2]);
		}
	}

}



ostream& operator<<(ostream &out, const Player &p){
	out << p._name << ": " << "Wins = " << p.won << ", Losses = " << p.lost;
	return out;
}