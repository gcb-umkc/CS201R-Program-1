#include <iostream>
#include <ctime>
#include <random>
using namespace std;


//Rolls the dice and returns the value of the roll
int RollDice() {
	int roll = -1;
	int firstRoll = rand() % 6;
	int secondRoll = rand() % 6;
	if (secondRoll > firstRoll) {
		roll = (secondRoll * 10) + firstRoll;
	}
	else {
		roll = (firstRoll * 10) + secondRoll;
	}
	return roll;
}


//Takes an y or n from the user, and outputs either true or false
bool promptUser() {
	char userInput;
	bool waitingForUser = true;
	bool result;

	//Loop runs while input is invalid
	while (waitingForUser) {
		cin >> userInput;
		switch (userInput) {
		case 'N':
		case 'n':
			result = false;
			waitingForUser = false;
			break;
		case 'Y':
		case 'y':
			result = true;
			waitingForUser = false;
			break;
		default:
			cout << "Invalid Input, please try again" << endl;
			break;
		}
	}
	return result;
}

int main() {
	bool exit = false;
	//srand(time(NULL));
	srand(0);
	int userWins = 0;
	int computerWins = 0;


	//Main Game Loop
	while (!exit) {
		int userRoll;
		userRoll = RollDice();
		cout << "User rolls: " << userRoll << endl;

		int computerRoll;
		computerRoll = RollDice();
		cout << "Computer rolls: " << computerRoll << endl;

		//Checks if 
		if (computerRoll > userRoll) {
			computerWins++;
			cout << "Computer Wins!";
		}
		else {
			userWins++;
			cout << "User Wins!";
		}

		//Outputs Score
		cout << "The current score is - Human: " << userWins;
		cout << ", Computer: " << computerWins;
		cout << "Try again? y/n ";
		exit = promptUser();
	}
}