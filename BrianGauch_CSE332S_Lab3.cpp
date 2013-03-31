// BrianGauch_CSE332S_Lab2.cpp : Entry point for the console application.

#include "stdafx.h"
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <ostream>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <vector>

#include "Card.h"
#include "Hand.h"
#include "Deck.h"

const static int HAND_SIZE = 5;

bool poker_rank(const Hand & hand1, const Hand & hand2);

int explainUsage(){
	cout << "USAGE: BrianGauch_CSE332_Lab2.exe inputFile.txt";
	return -1;
}

int main(int argc, char* argv[])
{
	//process args
	bool shuffle = false;
	string filename = "";
	if (argc < 2 || argc > 3){
		return explainUsage();
	}
	else if (argc == 2){
		filename = argv[1];
	}
	else{  //argc == 3
		if(string(argv[1]) == "-shuffle"){
			shuffle = true;
			filename = argv[2];
		}
		else if(string(argv[2]) == "-shuffle"){
			shuffle = true;
			filename = argv[1];
		}
		else{
			return explainUsage();
		}
	}

	//open the file
	ifstream din;
	din.open(filename.c_str());
	if(din.fail()){
		return -1;
	}
	string str;
	Deck deck;
	//read the file
	while(din>>str){
		try{
			Card card(str);
			deck.add_card(card);
		}
		catch(...){
		}
	}
	din.close();
	//shuffle the cards
	if(shuffle){
		deck.shuffle();
	}
	//deal the hands
	const int NUM_HANDS = 9;
	vector<Hand> hands;
	for(int i = 0; i < NUM_HANDS; i++){
		Hand hand;
		for(int j = 0; j < HAND_SIZE; j++){
			hand << deck;
		}
		cout << "i = " << i << endl;
		hand.print();
		hands.push_back(hand);
		cout << "hands.size = " << hands.size() << endl;
	}
	//sort by hand strength
	std::sort(hands.begin(), hands.end());
	cout << endl << "----------AFTER SORTING---------" << endl << endl;
	for(int i = 0; i < (int)hands.size(); i++){
		cout << hands[i] << endl;
	}

	std::sort(hands.begin(), hands.end(), poker_rank);
	cout << endl << "---------AFTER POKER SORTING----------" << endl << endl;
	for(int i = 0; i < (int)hands.size(); i++){
		cout << hands[i] << endl;
	}

	string junk;
	cout << "Type anything and hit enter to quit" << endl;
	cin >> junk;
	return 0;
}