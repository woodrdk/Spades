#include "Player.h"


#include<sstream>

// tostring methos using a stringstream
string Player::toString() {
	stringstream ss;
	ss << "Name: ";
	ss << name;
	ss << "Score: ";
	ss << score;
	ss << "Bid: ";
	ss << bid;
	ss << "Tricks: ";
	ss << tricks;
	ss << "Bags: ";
	ss << bags;
	ss << "Cards: ";
	ss << cards;
	ss << "Team mate: ";
	ss << teamMate;
	return ss.str();
}

// setter to set Name
void Player::setName(string newName) {
	name = newName;
}

// getter to get Name
string Player::getName() {
	return name;
}

// to set teammates name
void Player::setTeamMate(string teamMate) {
	name = teamMate;
}

// to set the players cards
void Player::setCards(string cards[]) {
	for (int i = 0; i < 13; i++) {
		cards = &cards[i];
	}
}
// to set player bid
void Player::setBid(int tricks) {
	bid = tricks;
}
// to see players bid
int Player::seeBid() {
	return bid;
}
