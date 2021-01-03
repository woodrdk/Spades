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
};