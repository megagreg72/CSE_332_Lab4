#include "stdafx.h"
#include "Player.h"

Player::Player(char * name){
	_name = name;
	_h = Hand();
	won = 0;
	lost = 0;

	read_file(name, won, lost); //reads from file: name, wins, losses
}


void Player::read_file (char * in_file, unsigned int & won, unsigned int & lost){
	vector<string> vs;
	string txt = ".txt";
	string in = in_file + txt;
	ifstream ifs (in);
	if( ifs ){//If input file cannot be opened/doesn't exist
		string word;
		while(ifs >> word){ //put input stream into vector of strings
			vs.push_back(word);
		}

		if(vs[0] == in_file){ //file has structure: Name Wins Losses
			won = stoi(vs[1]);
			lost = stoi(vs[2]);
		}
	}

}


ostream& operator<<(ostream &out, const Player &p){
	out << p._name << ": " << "Wins = " << p.won << ", Losses = " << p.lost;
	return out;
}