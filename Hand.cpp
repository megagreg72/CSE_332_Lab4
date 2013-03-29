#include "stdafx.h"
#include "Card.h"
#include "Hand.h"
#include <cctype>

//const int Hand::(int)_cards.size() = 5;

Hand::Hand()
{
}

Hand::Hand(const Card * cards, int size)
{
	for(int i = 0; i < size; i++){
		_cards.push_back(cards[i]);
	}
	sortCards();
}

Hand::Hand(const Hand & hand)
{
	copy(hand);
}

Hand::~Hand()
{
	//vectors are automatically deallocated
}

//higher rank cards to the right,
//higher suit cards to the right
//just use a simple bubble sort
void Hand::sortCards()
{
	bool doneSorting = false;
	while(!doneSorting)
	{
		Card temp;
		doneSorting = true;
		for(int i = 1; i < (int)_cards.size(); i++){
			if(_cards[i - 1] > _cards[i]){
				doneSorting = false;
				temp = _cards[i - 1];
				_cards[i - 1] = _cards[i];
				_cards[i] = temp;
			}
		}
	}
}

bool Hand::operator<(const Hand & hand) const
{
	//compare the right cards first
	//since we sort in increasing order
	for(int i = (int)_cards.size() - 1; i >= 0; i--){
		Card c1 = _cards[i];
		Card c2 = hand._cards[i];
		if(c1.get_erank() < c2.get_erank()){
			return true;
		}
		else if(c1.get_erank() > c2.get_erank()){
			return false;
		}
	}
	//same hand
	return false;
}

bool Hand::operator>(const Hand & hand) const
{
	//compare the right cards first
	//since we sort in increasing order
	for(int i = (int)_cards.size() - 1; i >= 0; i--){
		Card c1 = _cards[i];
		Card c2 = hand._cards[i];
		if(c1.get_erank() > c2.get_erank()){
			return true;
		}
		else if(c1.get_erank() < c2.get_erank()){
			return false;
		}
	}
	//same hand
	return false;
}

Hand & Hand::operator=(const Hand otherHand)
{
	copy(otherHand);
	return *this;
}

bool Hand::operator==(const Hand &otherHand) const
{
	for(int i = 0; i < (int)_cards.size(); i++){
		if(!(_cards[i] == otherHand._cards[i])){
			return false;
		}
	}
	return true;
}

const Card & Hand::operator[] (size_t position){
	if ((position > _cards.size()) || (position < 0)){
		throw "Invalid_Index"; 
	}
	else{
		return _cards[position];
	}
}

void Hand::insert(Card card){
	_cards.push_back(card);
	sortCards();
}

void Hand::remove_card (size_t position){
	if ((position > _cards.size()) || (position < 0)){
		throw "Invalid_Index"; 
	}
	else{
		_cards.erase(_cards.begin()+ position);
	}
}

Card Hand::get_card(int index) const
{
	return _cards[index];
}

vector<Card> Hand::get_cards() const
{
	return _cards;
}

bool Hand::copy(const Hand & hand)
{
	if(this == &hand){
		cout << "same as me!" << endl;
		return false;
	}
	else{
		_cards.clear();
		for(int i = 0; i < (int)hand._cards.size(); i++){
			_cards.push_back(hand._cards[i]);
		}
		return true;
	}
}

int Hand::size() const
{
	return (int)_cards.size();
}

void Hand::print() const
{
	cout << toString() << endl;
}

ostream & operator<<(ostream & out, const Hand & hand)
{
	out << hand.toString();
	return out;
}

string Hand::toString() const
{
	string s = "Hand{\n";
	for(int i = 0; i < (int)_cards.size(); i++){
		s = s + _cards[i].toString() + "\n";
	}
	s = s + "}";
	return s;
}

