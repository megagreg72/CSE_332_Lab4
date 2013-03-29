#include "stdafx.h"
#include "Card.h"

const static string validRanks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
const static string validSuits[] = {"C", "D", "H", "S"};

Card::Card()
{
	_rank = "";
	_suit = "";
	_erank = nullRank;
	_esuit = nullSuit;
}

Card::Card(string rank, string suit)
{
	_rank = rank;
	_suit = suit;
	_erank = convertRank(rank);
	_esuit = convertSuit(suit);
}

Card::Card(string token)
{
	int throwable = 0;
	string rank = "";
	string suit = "";
	if(token.length() == 2){
		rank  = token.substr(0,1);
		suit  = token.substr(1,1);
	}
	else if(token.length() == 3){
		rank  = token.substr(0,2);
		suit  = token.substr(2,1);
	}
	else{
		std::cout << "Error: Token in file with wrong size\n";
		throwable += -1;
	}
	if(!set_rank(rank) || !set_suit(suit)){
		std::cout << "Error: Card in file is invalid\n";
		throwable += -2;
	}
	if(throwable != 0)
	{
		throw throwable;
	}
}

Card::~Card()
{
	//vectors automatically cleans up after themselves
}

bool Card::operator==(const Card & rightCard) const
{
	return ((_erank == rightCard._erank) && 
		    (_esuit == rightCard._esuit));
}

bool Card::operator<(const Card & rightCard) const
{
	return ((_erank < rightCard._erank) ||
		    (_erank == rightCard._erank && _esuit < rightCard._esuit));
}

bool Card::operator>(const Card & rightCard) const
{
	return ((_erank > rightCard._erank) ||
		    (_erank == rightCard._erank && _esuit > rightCard._esuit));
}

string Card::convertErank(Card::_RANK erank)
{
	string rank = "";
	switch(erank)
	{
    case two:
		rank = "2";
		break;
	case three:
		rank = "3";
		break;
	case four:
		rank = "4";
		break;
	case five:
		rank = "5";
		break;
	case six:
		rank = "6";
		break;
	case seven:
		rank = "7";
		break;
	case eight:
		rank = "8";
		break;
	case nine:
		rank = "9";
		break;
	case ten:
		rank = "10";
		break;
	case jack:
		rank = "J";
		break;
	case queen:
		rank = "Q";
		break;
	case king:
		rank = "K";
		break;
	case ace:
		rank = "A";
		break;
	default:
		cout << "Error: Invalid card rank" << endl;
		rank = ""; 
	}
	return rank;
}

string Card::convertEsuit(Card::_SUIT esuit)
{
	string suit = "";
	switch(esuit)
	{
    case club:
		suit = "C";
		break;
	case diamond:
		suit = "D";
		break;
	case spade:
		suit = "S";
		break;
	case heart:
		suit = "H";
		break;
	default:
		cout << "Error: Invalid card suit" << endl;
		suit = ""; 
	}
	return suit;
}

Card::_RANK Card::convertRank(string rank)
{
	//make all caps
	for(unsigned int i = 0; i < rank.length(); i++){
		rank[i] = toupper(rank[i]);
	}

	Card::_RANK rankEnum = two;
	if(rank == "A"){
		rankEnum = ace;
	}
	else if(rank == "2"){
		rankEnum = two;
	}
	else if(rank == "3"){
		rankEnum = three;
	}
	else if(rank == "4"){
		rankEnum = four;
	}
	else if(rank == "5"){
		rankEnum = five;
	}
	else if(rank == "6"){
		rankEnum = six;
	}
	else if(rank == "7"){
		rankEnum = seven;
	}
	else if(rank == "8"){
		rankEnum = eight;
	}
	else if(rank == "9"){
		rankEnum = nine;
	}
	else if(rank == "10"){
		rankEnum = ten;
	}
	else if(rank == "J"){
		rankEnum = jack;
	}
	else if(rank == "Q"){
		rankEnum = queen;
	}
	else if(rank == "K"){
		rankEnum = king;
	}
	else{
		cout << "Error: Invalid card rank" << endl;
		rankEnum = nullRank; 
	}
	return rankEnum;
}

Card::_SUIT Card::convertSuit(string suit)
{
	//make all caps
	for(unsigned int i = 0; i < suit.length(); i++){
		suit[i] = toupper(suit[i]);
	}
	_SUIT suitEnum;
	if(suit == "C"){
		suitEnum = club;
	}
	else if(suit == "H"){
		suitEnum = heart;
	}
	else if(suit == "D"){
		suitEnum = diamond;
	}
	else if(suit == "S"){
		suitEnum = spade;
	}
	else{
		cout << "Error: Invalid card suit" << endl;
		suitEnum = nullSuit; 
	}
	return suitEnum;
}

bool Card::set_rank(string rank)
{
	bool valid = false;
	_erank = convertRank(rank);

	for(unsigned int i = 0; i < rank.length(); i++){
		rank[i] = toupper(rank[i]);
	}
	for(int i = 0; i < NUM_RANKS; i++){
		if(validRanks[i] == rank){
			valid = true;
		}
	}
	if(valid){
		_rank = rank;
	}
	return valid;
}

bool Card::set_suit(string suit)
{
	bool valid = false;
	_esuit = convertSuit(suit);

	for(unsigned int i = 0; i < suit.length(); i++){
		suit[i] = toupper(suit[i]);
	}
	for(int i = 0; i < NUM_SUITS; i++){
		if(validSuits[i] == suit){
			valid = true;
		}
	}
	if(valid){
		_suit = suit;
	}
	return valid;
}

string Card::get_suit() const
{
	return _suit;
}

string Card::get_rank() const
{
	return _rank;
}

Card::_RANK Card::get_erank() const
{
	return _erank;
}

Card::_SUIT Card::get_esuit() const
{
	return _esuit;
}

void Card::print() const
{
	cout << toString() << endl;
}

string Card::toString() const
{
	return "rank = " + _rank + ", suit = " + _suit;
}