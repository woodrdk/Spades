// Spades.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <string>
#include <cstdlib>
#include <random>
#include <ctime>

using namespace std;

// Defined the decksize
const int DECK_SIZE = 52;

// Array of the decks cards
const array<string, DECK_SIZE> cards{
		 "AH", "AC", "AD", "AS",
		 "2H", "2C", "2D", "2S",
		 "3H", "3C", "3D", "3S",
		 "4H", "4C", "4D", "4S",
		 "5H", "5C", "5D", "5S",
		 "6H", "6C", "6D", "6S",
		 "7H", "7C", "7D", "7S",
		 "8H", "8C", "8D", "8S",
		 "9H", "9C", "9D", "9S",
		 "10H", "10C", "10D", "10S",
		 "JH", "JC", "JD", "JS",
		 "QH", "QC", "QD", "QS",
		 "KH", "KC", "KD", "KS", };

// function prototypes 
void initializeDeck(array<const string*, DECK_SIZE>* deck);
void displayDeck(array<const string*, DECK_SIZE> deck);
void shuffleDeck(array<const string*, DECK_SIZE>* deck);
void printMenu();

// Main function that calls the actions of the program
int main() {
	

	cout << endl << endl << "\t\tWelcome to Rob's C++ Spades Game" << endl;
	cout << endl << "Would you like a short game or a long game? " << endl;
	cout << "1. Short game" << endl;
	cout << "2. Long game" << endl;
	cout << "3. End game" << endl;
	int gameLength;
	cout << "Enter the number you wish to proceed with: " << flush;
	cin >> gameLength;
	int gamePoints;
	if (gameLength > 0 && gameLength < 4) {
		if (gameLength == 1) {
			gamePoints = 200;
		}
		else if (gameLength == 2) {
			gamePoints = 500;
		}
		else {
			// quit game
		}
	}
	else {
		cout << "Not a valid option!" << endl;
	}

	// get players name
	string playerName;
	cout << "What is your name player? " << flush;
	cin >> playerName;
	string names[] = { "Bob", "Draven", "Kellan", "Amie", "Ace", "Charlene", "Leann", "Dan" };
	// get 3 random names
	string players[3] = {};
	

	srand(time(0));  // Initialize random number generator.
	for (int i = 0; i < 3; i++) {
		players[i] = names[(rand() % 8) + 1]; // diag later
	}
	cout << "\t Welcome " << playerName << " you are playing with " << players[0] << ", " << players[1] << " and " << players[2] << "." << endl;
	

	// pauses the program till key is pressed
	system("pause");
	return 0;
}

// This method builds the initial deck of cards before displayed or shuffled
void initializeDeck(array<const string*, DECK_SIZE>* deck) {
	for (size_t i = 0; i < DECK_SIZE; ++i) {
		(*deck)[i] = &cards[i];
	}
}

// This method tells the user what to push to run the program
void printMenu() {
	cout << "0 - Quit" << endl;
	cout << "1 - Shuffle deck" << endl;
	cout << "2 - Display deck" << endl;
}

// This method will display the deck of cards
void displayDeck(array<const string*, DECK_SIZE> deck) {
	cout << "This is the deck of Cards" << endl << endl;
	// Will print out the cards
	for (size_t i = 0; i < DECK_SIZE; ++i)
	{
		// prints out the card in order
		cout << *deck[i] << " ";
		// checks what card it is and if its the 13th, 16th or 39th it inserts an endline
		if (i == 12 || i == 25 || i == 38) {
			cout << endl;
		}
	}
	// prints two blank lines for spacing to make it look better visually
	cout << endl << endl;
}

// This method will shuffle the deck of cards
void shuffleDeck(array<const string*, DECK_SIZE>* deck) {
	static default_random_engine engine(static_cast<unsigned int>(time(0)));
	for (unsigned int i = DECK_SIZE - 1; i > 0; --i)
	{
		uniform_int_distribution<unsigned int> randomInt{ 0, i };
		// sets up what number to swap with 
		unsigned int j = randomInt(engine);
		// swaps card with randomly chosen card
		swap((*deck)[i], (*deck)[j]);
	}
	// Tells the user the deck is shuffled
	cout << "Shuffled the deck!" << endl << endl;
}

// 13 tricks 
// short game or long game

// player 
// score
// bid
// tricks
// bags
// cards

// bids
// blind nill
// nill
// 1-13

