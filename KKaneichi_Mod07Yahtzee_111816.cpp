//Kerry Kaneichi
//November 18, 2016
//Module 07 Coding Project #1 - Finished Yahtzee Game
//Programming 1 - Fall Quarter
//Instructor:  Christine Palazzolo
//--------------------------------------------------------
#include "stdafx.h"
#include <iostream>
#include <string>   
#include <time.h>
#include <sstream>       
#include <vector>       
#include <algorithm>

using namespace std;

//global constants
const int MAX_DIE = 5;
const int MAX_TURNS = 13;
const int MAX_ROUNDS = 8;
const int SCORE_CATEGORIES = 14;

//functions
int getPlayers();
string getName();
void rollDie();
void placeScore();
void calcScore();
bool sortScore();
void scoreRanking();


//get number of players
int getPlayers()
{
	int input = 0;
	bool valid = false;
	do
	{
		cout << "Enter the number of players: ";
		cin >> input;
		if (cin.good() && input > 0)
		{
			valid = true;
		}
		else
		{
			// Clean up (if there is invalid input)
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "---------------------" << endl;
			cout << "Please input a number" << endl;
			cout << "---------------------" << endl;
		}
	} while (!valid);
	return input;
}

//get players names
string getName(int index)
{
	string input;
	cout << "Please enter Player " << index + 1 << "'s name: ";
	cin >> input;
	return input;
}

//roll dice
void rollDie(int die[])
{
	const int MAX_TURNS = 3;
	cout << "Roll 1: ";
	for (int index = 0; index < MAX_DIE; index++)
	{
		die[index] = rand() % 6 + 1;
		cout << die[index] << " ";
	}
	for (int turn = 1; turn < MAX_TURNS; ++turn)
	{
		cout << endl << "Do you want to reroll any dice? (y/n)" << endl;
		char reroll;
		cin >> reroll;

		// Determine which dice to reroll
		if (toupper(reroll) == 'Y')
		{
			for (int index = 0; index < MAX_DIE; index++)
			{
				cout << "Reroll " << die[index] << "? (y/n)";
				char rerollDie; cin >> rerollDie;
				// Reroll die
				if (toupper(rerollDie) == 'Y') die[index] = rand() % 6 + 1;
			}
			//new roll
			cout << "Next roll: ";
			for (int index = 0; index < MAX_DIE; index++)
			{
				cout << die[index] << " ";
			}
		}
		//keep roll
		else turn = MAX_TURNS;
	}
}

//score card
void placeScore(int die[], vector<vector<int>> &scoreCard, int player)
{
	string category[13] = { "One's", "Two's", "Three's", "Four's", "Five's", "Six's", "3 of a Kind", "4 of a  Kind", "Full House", "Small Straight", "Large Straight", "Yahtzee", "Chance" };
	bool goAgain;
	do
	{
		goAgain = false;
		// Display final roll
		cout << endl << "Final Roll: ";
		for (int index = 0; index< MAX_DIE; index++)
		{
			cout << die[index] << " ";
		}

		// Remove used categories from list
		for (int index = 0; index< 13; index++)
		{
			if (scoreCard[player][index] != 0)
				category[index] = "----";
		}
		// Display score menu
		cout << endl << "Score Category:" << endl;
		cout << "1. " << category[0] << endl;
		cout << "2. " << category[1] << endl;
		cout << "3. " << category[2] << endl;
		cout << "4. " << category[3] << endl;
		cout << "5. " << category[4] << endl;
		cout << "6. " << category[5] << endl;
		cout << "7. " << category[6] << endl;
		cout << "8. " << category[7] << endl;
		cout << "9. " << category[8] << endl;
		cout << "10. " << category[9] << endl;
		cout << "11. " << category[10] << endl;
		cout << "12. " << category[11] << endl;
		cout << "13. " << category[12] << endl;
		cout << "Enter your Selection: ";
		int option;
		cin >> option;
		cin.ignore();
		// Selection options
		switch (option)
		{
		case 1:
			if (scoreCard[player][0] == 0)
			{
				int tempScore = 0;
				for (int index = 0; index< MAX_DIE; index++) {
					if (die[index] == 1)
					{
						tempScore += die[index];
					}
				}
				if (tempScore == 0)
				{
					tempScore = -1;
				}
				scoreCard[player][0] = tempScore;
				break;
			}
			//if player chooses an option already used
			else if (scoreCard[player][0] != 0)
			{
				cout << "------------------------------" << endl;
				cout << "Please select another category" << endl;
				cout << "------------------------------" << endl;
				goAgain = true;
				break;
			}

		case 2:
			if (scoreCard[player][1] == 0)
			{
				int tempScore = 0;
				for (int index = 0; index< MAX_DIE; index++)
				{
					if (die[index] == 2)
					{
						tempScore += die[index];
					}
				}
				if (tempScore == 0)
				{
					tempScore = -1;
				}
				scoreCard[player][1] = tempScore;
				break;
			}
			else if (scoreCard[player][1] != 0)
			{
				cout << "------------------------------" << endl;
				cout << "Please select another category" << endl;
				cout << "------------------------------" << endl;
				goAgain = true;
				break;
			}

		case 3:
			if (scoreCard[player][2] == 0)
			{
				int tempScore = 0;
				for (int index = 0; index< MAX_DIE; index++)
				{
					if (die[index] == 3)
					{
						tempScore += die[index];
					}
				}
				if (tempScore == 0)
				{
					tempScore = -1;
				}
				scoreCard[player][2] = tempScore;
				break;
			}
			else if (scoreCard[player][2] != 0)
			{
				cout << "------------------------------" << endl;
				cout << "Please select another category" << endl;
				cout << "------------------------------" << endl;
				goAgain = true;
				break;
			}

		case 4:
			if (scoreCard[player][3] == 0)
			{
				int tempScore = 0;
				for (int index = 0; index< MAX_DIE; index++)
				{
					if (die[index] == 4)
					{
						tempScore += die[index];
					}
				}
				if (tempScore == 0)
				{
					tempScore = -1;
				}
				scoreCard[player][3] = tempScore;
				break;
			}
			else if (scoreCard[player][3] != 0)
			{
				cout << "------------------------------" << endl;
				cout << "Please select another category" << endl;
				cout << "------------------------------" << endl;
				goAgain = true;
				break;
			}

		case 5:
			if (scoreCard[player][4] == 0)
			{
				int tempScore = 0;
				for (int index = 0; index< MAX_DIE; index++)
				{
					if (die[index] == 5)
					{
						tempScore += die[index];
					}
				}
				if (tempScore == 0)
				{
					tempScore = -1;
				}
				scoreCard[player][4] = tempScore;
				break;
			}
			else if (scoreCard[player][4] != 0)
			{
				cout << "------------------------------" << endl;
				cout << "Please select another category" << endl;
				cout << "------------------------------" << endl;
				goAgain = true;
				break;
			}

		case 6:
			if (scoreCard[player][5] == 0)
			{
				int tempScore = 0;
				for (int index = 0; index< MAX_DIE; index++)
				{
					if (die[index] == 6)
					{
						tempScore += die[index];
					}
				}
				if (tempScore == 0)
				{
					tempScore = -1;
				}
				scoreCard[player][5] = tempScore;
				break;
			}
			else if (scoreCard[player][5] != 0)
			{
				cout << "------------------------------" << endl;
				cout << "Please select another category" << endl;
				cout << "------------------------------" << endl;
				goAgain = true;
				break;
			}

		case 7:
			if (scoreCard[player][6] == 0)
			{
				int temp[6];
				int tempScore = 0;
				for (int index = 0; index< 6; index++)
				{
					temp[index] = count(die, die + MAX_DIE, index + 1);
					if (temp[index] == 3)
					{
						for (int index2 = 0; index2 < MAX_DIE; index2++)
							tempScore += die[index2];
					}
				}
				if (tempScore == 0)
				{
					tempScore = -1;
				}
				scoreCard[player][6] = tempScore;
				break;
			}
			else if (scoreCard[player][6] != 0)
			{
				cout << "------------------------------" << endl;
				cout << "Please select another category" << endl;
				cout << "------------------------------" << endl;
				goAgain = true;
				break;
			}

		case 8:
			if (scoreCard[player][7] == 0)
			{
				int temp[6];
				int tempScore = 0;
				for (int index = 0; index< 6; index++)
				{
					temp[index] = count(die, die + MAX_DIE, index + 1);
					if (temp[index] == 4)
					{
						for (int index2 = 0; index2 < MAX_DIE; index2++)
							tempScore += die[index2];
					}
				}
				if (tempScore == 0)
				{
					tempScore = -1;
				}
				scoreCard[player][7] = tempScore;
				break;
			}
			else if (scoreCard[player][7] != 0)
			{
				cout << "------------------------------" << endl;
				cout << "Please select another category" << endl;
				cout << "------------------------------" << endl;
				goAgain = true;
				break;
			}

		case 9:
			if (scoreCard[player][8] == 0)
			{
				int temp[6];
				int fullHouse = 0;
				for (int index = 0; index< 6; index++)
				{
					temp[index] = count(die, die + MAX_DIE, index + 1);
					if (temp[index] == 3)
					{
						++fullHouse;
					}
					else if (temp[index] == 2)
					{
						++fullHouse;
					}
				}
				if (fullHouse == 2)
				{
					scoreCard[player][8] = 25;
					break;
				}
				else
				{
					scoreCard[player][8] = -1;
					break;
				}
			}
			else if (scoreCard[player][8] != 0)
			{
				cout << "------------------------------" << endl;
				cout << "Please select another category" << endl;
				cout << "------------------------------" << endl;
				goAgain = true;
				break;
			}

		case 10:
			if (scoreCard[player][9] == 0)
			{
				int count = 0;
				sort(die, die + MAX_DIE);
				for (int index = 1; index< MAX_DIE; index++)
				{
					if (die[index] == die[index - 1] + 1)
					{
						++count;
					}
				}
				if (count > 3)
				{
					scoreCard[player][9] = 30;
					break;
				}
				else
				{
					scoreCard[player][9] = -1;
					break;
				}
			}
			else if (scoreCard[player][9] != 0)
			{
				cout << "------------------------------" << endl;
				cout << "Please select another category" << endl;
				cout << "------------------------------" << endl;
				goAgain = true;
				break;
			}

		case 11:
			if (scoreCard[player][10] == 0)
			{
				int count = 0;
				sort(die, die + MAX_DIE);
				for (int index = 1; index< MAX_DIE; index++)
				{
					if (die[index] == die[index - 1] + 1)
					{
						++count;
					}
				}
				if (count > 4)
				{
					scoreCard[player][10] = 30;
					break;
				}
				else
				{
					scoreCard[player][10] = -1;
					break;
				}
			}
			else if (scoreCard[player][10] != 0)
			{
				cout << "------------------------------" << endl;
				cout << "Please select another category" << endl;
				cout << "------------------------------" << endl;
				goAgain = true;
				break;
			}

		case 12:
			if (scoreCard[player][11] == 0)
			{
				int temp[6];
				int tempScore = 0;
				for (int index = 0; index< 6; index++)
				{
					temp[index] = count(die, die + MAX_DIE, index + 1);
					if (temp[index] == 5)
					{
						tempScore = 50;
					}
				}
				if (tempScore == 0)
				{
					tempScore = -1;
				}
				scoreCard[player][11] = tempScore;
				break;
			}
			else if (scoreCard[player][11] != 0)
			{
				cout << "------------------------------" << endl;
				cout << "Please select another category" << endl;
				cout << "------------------------------" << endl;
				goAgain = true;
				break;
			}

		case 13:
			if (scoreCard[player][12] == 0)
			{
				int tempScore = 0;
				for (int index = 0; index< MAX_DIE; index++)
					tempScore += die[index];
				if (tempScore == 0)
				{
					tempScore = -1;
				}
				scoreCard[player][12] = tempScore;
				break;
			}
			else if (scoreCard[player][12] != 0)
			{
				cout << "------------------------------" << endl;
				cout << "Please select another category" << endl;
				cout << "------------------------------" << endl;
				goAgain = true;
				break;
			}

		default:
			cout << "-----------------------------------" << endl;
			cout << "Invalid entry - Please select again" << endl;
			cout << "-----------------------------------" << endl;
			goAgain = true;
		}

	} while (goAgain);
}

//calculates score and bonus
void calcScore(vector<vector<int>> &scoreCard, int player)
{
	int upperScore = 0;
	int lowerScore = 0;

	for (int index = 0; index< SCORE_CATEGORIES; index++)
	{
		if (scoreCard[player][index] == -1)
			scoreCard[player][index] = 0;
	}
	// Upper score
	for (int index = 0; index< 5; index++)
	{
		upperScore += scoreCard[player][index];
	}
	//bonus
	if (upperScore > 62)
	{
		upperScore += 35;
		cout << "Upper Score Bonus!" << endl;
		cout << "-----------------------------" << endl;
	}
	// Lower score
	for (int index = 6; index< 12; index++)
	{
		lowerScore += scoreCard[player][index];
	}
	// Assign players score
	scoreCard[player][13] = upperScore + lowerScore;
}

// Sorting the score
bool sortScore(const vector<string>& index, const vector<string>& index2)
{
	return index[1] > index2[1];
}

void scoreRanking(vector <vector<int>> &scoreCard, vector<string> &playerName, int MAX_PLAYERS)
{

	// To combine name and score
	vector<vector<string>> playerRank;
	for (int index = 0; index < MAX_PLAYERS; index++)
	{

		// This creates temp vectors to hold data from game rows
		vector<string> temp;
		for (int index2 = 0; index2 < 2; index2++)
		{
			// To load names into first column
			if (index2 == 0)
				temp.push_back(playerName[index]);
			// To load scores into second column
			if (index2 == 1)
				temp.push_back(static_cast<ostringstream*>(&(ostringstream() << scoreCard[index]
					[13]))->str());
		}
		// Push temp vector
		playerRank.push_back(temp);
	}

	// Sort player's rank by score in descending order
	sort(playerRank.begin(), playerRank.end());

}

int main()
{
	int maxPlayers = getPlayers();

	vector<string> playerName(maxPlayers);
	for (int index = 0; index < maxPlayers; index++)
	{
		playerName[index] = getName(index);
	}

	vector<vector<int>> roundScore(MAX_ROUNDS, vector<int>(maxPlayers, 0));

	int round = 0;
	bool goAgain = false;

	// loop that controls the game interaction
	do
	{
		vector<vector<int>> scoreCard(maxPlayers, vector<int>(SCORE_CATEGORIES, 0));
		srand(time(NULL)); // random via time
		int die[MAX_DIE];

		for (int turn = 0; turn < MAX_TURNS; turn++)
		{
			for (int player = 0; player < maxPlayers; player++)
			{
				cout << "\n####################################" << endl;
				cout << "Turn " << turn + 1 << ": " << playerName[player] << endl;

				rollDie(die);
				placeScore(die, scoreCard, player);
			}
		}
		cout << "\n####################################" << endl;
		cout << "\n The Round is Over!" << endl;
		cout << "\n####################################" << endl;

		// Calculating the Scores
		for (int index = 0; index < maxPlayers; index++)
		{
			calcScore(scoreCard, index);
			scoreRanking(scoreCard, playerName, maxPlayers);
		}
		for (int index = 0; index < maxPlayers; index++)
		{
			roundScore[round][index] = scoreCard[index][13];
		}

		// Display played round numbers
		for (int index = 0; index < round + 1; index++)
		{
			cout << "\tRound " << round + 1;
		}
		cout << endl;

		// Display player names and their final scores for each round played
		for (int index = 0; index < maxPlayers; index++)
		{
			cout << playerName[index] << "\t";
			for (int index2 = 0; index2 < round + 1; index2++)
				cout << roundScore[index2][index] << "\t";
			cout << endl;
		}
		cout << endl;

		// Ask to play another round if max rounds have not been played
		if (round < MAX_ROUNDS)
		{
			cout << "Play another round? (y/n)";
			char replay;
			cin >> replay;
			if (toupper(replay) == 'Y')
			{
				goAgain = true;
				++round;
			}
		}
		else
		{     // Max rounds played, end of the game
			goAgain = false;
		}
	} while (goAgain);

	cout << "Thanks for playing!" << endl;

	system("pause");
	return 0;
}