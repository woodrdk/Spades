#pragma once

#include <iostream>
using namespace std;

class Player
{
private:
	string name;
	int score;
	int bid;
	int tricks;
	int bags;
	int cards[13];
	string teamMate;
	int teamScore;
public:
	string toString();
	void setName(string newName);
	string getName();
	void setTeamMate(string teamMate);
	void setCards(string cards[]);
	void setBid(int tricks);
	int seeBid();
	void setTeamScore(int score);

	int seeTeamScore();
	Player(): score(0),bid(0), tricks(0), bags(0), cards(), teamMate(), teamScore(0) {};
};