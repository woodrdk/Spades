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
public:
	string toString();
	void setName(string newName);
	string getName();
	void setTeamMate(string teamMate);
	void setCards(string cards[]);
	Player(): score(0),bid(0), tricks(0), bags(0), cards(), teamMate() {};
};