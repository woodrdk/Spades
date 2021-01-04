// Spades.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <string>
#include <cstdlib>
#include <random>
#include <ctime>
#include "Player.h"
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
void printIntro();
string *getNames();
// Main function that calls the actions of the program
int main() {
	printIntro();

	// bids
    // blind nill
    // nill
    // 1-13
	string *participants;
	participants = getNames();
	// following loop was for testing
	Player player1;
	Player player2;
	Player player3;
	Player player4;
	Player pl[4] = { player1, player2, player3, player4 }; // players array
	for (int i = 0; i < sizeof(participants); i++){
		cout << *(participants+i) << endl;
		string name = *(participants + i);
		pl[i].setName(name);
		
		if (i < 2) {
			pl[i].setTeamMate(*(participants + 2));
		}
		else if (i == 2 || i == 4) {
			pl[i].setTeamMate(*(participants - 2));
		}
	}

	


	cout << endl << endl << endl;
	// pauses the program till key is pressed
	system("pause");
	return 0;
}

string* getNames() {
	// get players name
	string playerName;
	cout << "What is your name player? " << flush;
	cin >> playerName;
	string names[] = { "Bob", "Draven", "Kellan", "Amie", "Ace", "Charlene", "Leann", "Dan" };
	// get 3 random names
	static string players[4];
	players[3] = playerName;
	srand(time(0));  // Initialize random number generator.
	for (int i = 0; i < 3; i++) {
		players[i] = names[(rand() % 7) + 1]; //TODO: diag later
	}
	cout << "Welcome " << playerName << " you are playing with " << players[0] << ", " << players[1] << " and " << players[2] << "." << endl;
	cout << "Your teammate is " << players[1] << endl << endl;

	return players;
}

void printInstructions() {
	cout << "These are the rules as per Bicycle Playing cards at https://bicyclecards.com/how-to-play/spades/ " << endl << endl;
	cout << "OBJECT OF THE GAME" << endl;
	cout << "To win at least the number of tricks bid." << endl;
	cout << "THE DEAL" << endl;
	cout << "The first dealer is chosen by a draw for high card, and thereafter the turn to deal proceeds clockwise.The entire deck is dealt one at a time, face down, beginning on the dealer's left. The players then pick up their cards and arrange them by suits." << endl;
	cout << "THE BIDDING" << endl;
	cout << "Each player decides how many tricks they will be able to take.The player to the dealer's left starts the bidding and, in turn, each player states how many tricks they expect to win. There is only one round of bidding, and the minimum bid is One. Every player must make a bid; no player may pass. No suit is named in the bid, for as the name of the game implies, spades are always trump." << endl;
	cout << "THE PLAY" << endl;
	cout << "The game is scored by hands, and the winner must make a certain number of points, which is decided before the game begins.Five hundred points is common, but 200 points is suitable for a short game.The player on the dealer's left makes the opening lead, and players must follow suit, if possible. If a player cannot follow suit, they may play a trump or discard. The trick is won by the player who plays the highest trump or if no trump was played, the player who played the highest card in the suit led. The player who wins the trick leads next. Play continues until none of the players have any cards left. Each hand is worth 13 tricks. Spades cannot be led unless played previously or player to lead has nothing but Spades in his hand." << endl;
	cout << "HOW TO KEEP SCORE" << endl;
	cout << "For making the contract(the number of tricks bid), the player scores 10 points for each trick bid, plus 1 point for each overtrick." << endl;
	cout << "For example, if the player's bid is Seven and they make seven tricks, the score would be 70. If the bid was Five and the player won eight tricks, the score would be 53 points: 50 points for the bid, and 3 points for the three overtricks. In some games, overtricks are called \"bags\" and a deduction of 100 points is made every time a player accumulates 10 bags. Thus, the object is always to fulfill the bid exactly." << endl;
	cout << "If the player \"breaks contract,\" that is, if they take fewer than the number of tricks bid, the score is 0. For example, if a player bids Fourand wins only three tricks, no points are awarded." << endl;
	cout << "One of the players is the scorerand writes the bids down, so that during the playand for the scoring afterward, this information will be available to all the players.When a hand is over, the scores should be recorded next to the bids, and a running score should be kept so that players can readily see each other's total points. If there is a tie, then all players participate in one more round of play." << endl;
}

void printIntro() {
	cout << endl << endl << "\t\tWelcome to Rob's C++ Spades Game" << endl;
	cout << endl << "Do you need instructions how to play? " << endl;
	int instructions;
	cout << "Press 1 for yes or 2 for no " << flush;
	cin >> instructions;
	if (instructions == 1) {
		printInstructions();
	}
	cout << endl << "Would you like a short game or a long game? " << endl;
	cout << "1. Short game" << endl;
	cout << "2. Long game" << endl;
	cout << "3. End game" << endl;
	int gamePoints = -1;
	while (gamePoints == -1) {
		int gameLength;
		cout << "Enter the number you wish to proceed with: " << flush;
		cin >> gameLength;
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
	}
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


