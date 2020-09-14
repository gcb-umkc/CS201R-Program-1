#include <iostream>
#include <ctime>
#include <random>
using namespace std;


//Returns a random integer between 1 and 6
int RollDie(){
	int roll = (rand() % 6) + 1;
	return roll;
}


//Rolls the dice and returns the value of the roll
int AddDice(int firstRoll, int secondRoll) {
	int roll = -1;
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

	cout << "Try again? y/n ";

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
	srand(time(NULL));
	int userWins = 0;
	int computerWins = 0;
	int topNumber = 0;

	//Main Game Loop
	while (!exit) {

		//User Rolls
		int userNumber;
		int userRoll1 = RollDie();
		int userRoll2 = RollDie();

		cout << "Rolling 2 dice for human: " << endl;
		userNumber = AddDice(userRoll1, userRoll2);
		cout << "Rolled " << userRoll1 << " and " << userRoll2 << ", making " << userNumber << "." << endl;

		//Setting top number
		cout << endl;
		if (topNumber < userNumber) {
			topNumber = userNumber;
			cout << topNumber << " is the number to beat!" << endl;
		}
		else {
			//If its on the second loop if the userNumber is smaller, then it exits the loop
			computerWins++;
			topNumber = 0;
			cout << "Too bad, the Computer Wins!" << endl;
			cout << "The current score is - Human: " << userWins << ", Computer: " << computerWins << endl;
			exit = !promptUser();
			if (exit) {
				break;
			}
			else {
				continue;
			}
		}
		
		//Computer Rolls
		int computerNumber;
		int computerRoll1 = RollDie();
		int computerRoll2 = RollDie();
		
		cout << "Rolling 2 dice for computer: " << endl;
		computerNumber = AddDice(computerRoll1, computerRoll2);
		cout << "Rolled " << computerRoll1 << " and " << computerRoll2 << ", making " << computerNumber << "." << endl;

		//Checks if either computer or user wins
		if (topNumber > userNumber) {
			computerWins++;
			topNumber = 0;

			cout << "Too bad, the Computer Wins!" << endl;
			cout << "The current score is - Human: " << userWins << ", Computer: " << computerWins << endl;
			exit = !promptUser();
			
		}
		else if (topNumber > computerNumber){
			userWins++;
			topNumber = 0;
			
			cout << "User Wins!";
			cout << "The current score is - Human: " << userWins << ", Computer: " << computerWins << endl;
			exit = !promptUser();
		}
		else {
			cout << endl;
			if (topNumber < computerNumber) {
				topNumber = computerNumber;
			}
			cout << topNumber << " is the number to beat!";
		}
		cout << endl;
	}
}