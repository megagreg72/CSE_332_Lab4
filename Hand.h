#include "stdafx.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include "Card.h"
using namespace std;

#ifndef HAND_H
#define HAND_H

struct Hand
{
public:
	// Constructors and destructor
	Hand();
	Hand(const Card * cards, int size);
	Hand(const Hand & hand);
	~Hand();

	// Class methods
	bool operator<(const Hand &otherHand) const;
	bool operator>(const Hand &otherHand) const;
	Hand & operator=(const Hand otherHand);
	bool operator==(const Hand &otherHand) const;
	const Card & operator[] (size_t position);
	void remove_card (size_t position);
	int size() const;
	bool copy(const Hand & hand);
	void print() const;
	string toString() const;

	//getters and setters
	vector<Card> get_cards() const;
	void set_cards(vector<Card> cards);
	Card get_card(int index) const;
	void insert(Card card);

private:
	vector<Card> _cards;
	void sortCards();
};

//non-member stuff
ostream & operator<<(ostream & out, const Hand & hand);

#endif