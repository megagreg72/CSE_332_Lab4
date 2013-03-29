#include "stdafx.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

#ifndef CARD_H
#define CARD_H

struct Card
{
public:
	// Constructors and destructor
	Card();
	Card(string rank, string suit);
	Card(string token);
	~Card();
	const static int NUM_RANKS = 15;
	const static int NUM_SUITS = 5;
	static enum _RANK {nullRank = 0, two=2, three=3, four=4, five=5, six=6, seven=7, eight=8, nine=9, ten=10, jack=11, queen=12, king=13, ace=14};
	static enum _SUIT {nullSuit = 0, club=1, diamond=2, heart=3, spade=4};

	// Class methods
	bool operator==(const Card &rightCard) const;
	bool operator<(const Card &rightCard) const;
	bool operator>(const Card &rightCard) const;
	bool set_rank(string rank);
	bool set_suit(string suit);
	static _RANK convertRank(string rank);
	static _SUIT convertSuit(string suit);
	static string convertErank(_RANK erank);
	static string convertEsuit(_SUIT suit);
	string get_rank() const;
	string get_suit() const;
	_RANK get_erank() const;
	_SUIT get_esuit() const;
	void print() const;
	string toString() const;

private:
	string _rank;
	string _suit;
	_RANK _erank;
	_SUIT _esuit;
};
#endif