// Kerry Kaneichi
// Module 11 Project - Refactor your Tetris Code Incorporating Feedback
// June 12, 2017
// Programming 2 - 2017 Spring Quarter
// Instructor: Carl Arrington
// Note:  Did not received discussion feedback
// ------------------------------------------------------

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <time.h>
#include <conio.h>

using namespace std;

//class to create the tetris shape
class TetrisShape
{
public:
	int shapeTopLeftX; //x axis
	int shapeTopLeftY; // y axis

	TetrisShape() //default constructor
	{
		shapeTopLeftX = 4; //start at (4, 0)
		shapeTopLeftY = 0;
	}

	char shapeArray[4][4]; //largest size of tetris shape

						   //define shapes
	void getShape(int shapeType)
	{
		int a = 0, b = 1, c = 2, d = 3;
		switch (shapeType)
		{
		case 1: //L shape
			shapeArray[a][0] = ' '; shapeArray[b][0] = 'X'; shapeArray[c][0] = ' '; shapeArray[d][0] = ' '; //-X--
			shapeArray[a][1] = ' '; shapeArray[b][1] = 'X'; shapeArray[c][1] = ' '; shapeArray[d][1] = ' '; //-X--
			shapeArray[a][2] = ' '; shapeArray[b][2] = 'X'; shapeArray[c][2] = 'X'; shapeArray[d][2] = ' '; //-XX-
			shapeArray[a][3] = ' '; shapeArray[b][3] = ' '; shapeArray[c][3] = ' '; shapeArray[d][3] = ' '; //----
			break;
		case 2: //I shape
			shapeArray[a][0] = ' '; shapeArray[b][0] = 'X'; shapeArray[c][0] = ' '; shapeArray[d][0] = ' '; //-X--
			shapeArray[a][1] = ' '; shapeArray[b][1] = 'X'; shapeArray[c][1] = ' '; shapeArray[d][1] = ' '; //-X--
			shapeArray[a][2] = ' '; shapeArray[b][2] = 'X'; shapeArray[c][2] = ' '; shapeArray[d][2] = ' '; //-X--
			shapeArray[a][3] = ' '; shapeArray[b][3] = 'X'; shapeArray[c][3] = ' '; shapeArray[d][3] = ' '; //-X--
			break;
		case 3: //O shape
			shapeArray[a][0] = ' '; shapeArray[b][0] = ' '; shapeArray[c][0] = ' '; shapeArray[d][0] = ' '; //----
			shapeArray[a][1] = ' '; shapeArray[b][1] = 'X'; shapeArray[c][1] = 'X'; shapeArray[d][1] = ' '; //-XX-
			shapeArray[a][2] = ' '; shapeArray[b][2] = 'X'; shapeArray[c][2] = 'X'; shapeArray[d][2] = ' '; //-XX-
			shapeArray[a][3] = ' '; shapeArray[b][3] = ' '; shapeArray[c][3] = ' '; shapeArray[d][3] = ' '; //----
			break;
		case 4: //T shape
			shapeArray[a][0] = 'X'; shapeArray[b][0] = 'X'; shapeArray[c][0] = 'X'; shapeArray[d][0] = ' '; //XXX-
			shapeArray[a][1] = ' '; shapeArray[b][1] = 'X'; shapeArray[c][1] = ' '; shapeArray[d][1] = ' '; //-X--
			shapeArray[a][2] = ' '; shapeArray[b][2] = ' '; shapeArray[c][2] = ' '; shapeArray[d][2] = ' '; //----
			shapeArray[a][3] = ' '; shapeArray[b][3] = ' '; shapeArray[c][3] = ' '; shapeArray[d][3] = ' '; //----
			break;
		case 5: //S shape
			shapeArray[a][0] = ' '; shapeArray[b][0] = 'X'; shapeArray[c][0] = 'X'; shapeArray[d][0] = ' '; //-XX-
			shapeArray[a][1] = 'X'; shapeArray[b][1] = 'X'; shapeArray[c][1] = ' '; shapeArray[d][1] = ' '; //XX--
			shapeArray[a][2] = ' '; shapeArray[b][2] = ' '; shapeArray[c][2] = ' '; shapeArray[d][2] = ' '; //----
			shapeArray[a][3] = ' '; shapeArray[b][3] = ' '; shapeArray[c][3] = ' '; shapeArray[d][3] = ' '; //----
			break;
		case 6: //J shape
			shapeArray[a][0] = ' '; shapeArray[b][0] = 'X'; shapeArray[c][0] = ' '; shapeArray[d][0] = ' '; //-X--
			shapeArray[a][1] = ' '; shapeArray[b][1] = 'X'; shapeArray[c][1] = ' '; shapeArray[d][1] = ' '; //-X--
			shapeArray[a][2] = 'X'; shapeArray[b][2] = 'X'; shapeArray[c][2] = ' '; shapeArray[d][2] = ' '; //XX--
			shapeArray[a][3] = ' '; shapeArray[b][3] = ' '; shapeArray[c][3] = ' '; shapeArray[d][3] = ' '; //----
			break;
		case 7: //Z shape
			shapeArray[a][0] = 'X'; shapeArray[b][0] = 'X'; shapeArray[c][0] = ' '; shapeArray[d][0] = ' '; //XX--
			shapeArray[a][1] = ' '; shapeArray[b][1] = 'X'; shapeArray[c][1] = 'X'; shapeArray[d][1] = ' '; //-XX-
			shapeArray[a][2] = ' '; shapeArray[b][2] = ' '; shapeArray[c][2] = ' '; shapeArray[d][2] = ' '; //----
			shapeArray[a][3] = ' '; shapeArray[b][3] = ' '; shapeArray[c][3] = ' '; shapeArray[d][3] = ' '; //----
			break;
		}
	}
};

const int WIDTH = 12;
const int HEIGHT = 25;

int checkRows();
int clearRow(int row);

//design bucket
char bucket[HEIGHT][WIDTH] =
{
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' }

};

//set initial position for piece to drop
void setCursorTo(int x, int y)
{
	HANDLE handle;
	COORD position;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(handle, position);
}

//displays bucket
void drawBucket(int score)
{
	setCursorTo(0, 0);
	for (int x = 0; x < HEIGHT; x++)
	{

		for (int y = 0; y < WIDTH; y++)
		{
			cout << bucket[x][y];
		}
		cout << endl;
	}
	cout << "Score: " << score;
}

//updates bucket with tetris shape
void updateBucket(TetrisShape localTetrisShape)
{
	///object move
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (localTetrisShape.shapeArray[i][j] == 'X')
				bucket[localTetrisShape.shapeTopLeftY + i][localTetrisShape.shapeTopLeftX + j] = localTetrisShape.shapeArray[i][j];
		}
	}
}

//accepts user input of arrow keys
int getUserInput()
{
	int input = 0;
	while (_kbhit())
		input = _getch();
	return input;
}

int stuckCheck(int newShapeTopLeftX, int newShapeTopLeftY, char array[][4])
{
	int isStuck = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			if ((array[i][j] == 'X') && (bucket[newShapeTopLeftY + i][newShapeTopLeftX + j] == '#' || bucket[newShapeTopLeftY + i][newShapeTopLeftX + j] == 'X')) isStuck = 1;
	}
	return isStuck;
}

//cleans up residue from falling shape
void removeTrail(TetrisShape localTetrisShape)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (localTetrisShape.shapeArray[i][j] == 'X')
				bucket[localTetrisShape.shapeTopLeftY + i][localTetrisShape.shapeTopLeftX + j] = ' ';
		}
	}

}

//instructions for each arrow key
int moveShape(int input, int& newShapeTopLeftX, int& newShapeTopLeftY, char array[][4], TetrisShape localTetrisShape)
{
	enum key { UP_ARROW = 72, DOWN_ARROW = 80, LEFT_ARROW = 75, RIGHT_ARROW = 77 };
	int flag = 0;

	switch (input)
	{
	case UP_ARROW: //rotates shape
		char arrayTemp[4][4]; //needed as a temp array as the shape rotates
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				arrayTemp[i][j] = array[3 - j][i];
		}
		// checks to see if it will bump into another shape
		flag = stuckCheck(localTetrisShape.shapeTopLeftX, localTetrisShape.shapeTopLeftY, arrayTemp);

		if (flag == 0)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
					array[i][j] = arrayTemp[i][j];
			}
		}
		break;
	case DOWN_ARROW: //move the shape down
		flag = stuckCheck(localTetrisShape.shapeTopLeftX, localTetrisShape.shapeTopLeftY + 1, array);
		if (flag == 1) flag = 2;
		if (flag == 0) newShapeTopLeftY++;
		break;
	case LEFT_ARROW: //move the shape left
		flag = stuckCheck(localTetrisShape.shapeTopLeftX - 1, localTetrisShape.shapeTopLeftY, array);
		if (flag == 0)
			newShapeTopLeftX--;
		break;
	case RIGHT_ARROW: //move the shape right
		flag = stuckCheck(localTetrisShape.shapeTopLeftX + 1, localTetrisShape.shapeTopLeftY, array);
		if (flag == 0)
			newShapeTopLeftX++;
		break;
	default:
		break;
	}
	return flag;
}

//shape moves down one space (automatically during gameplay)
int moveDown(TetrisShape localTetrisShape, int& newShapeTopLeftY)
{
	int flag = 0;
	flag = stuckCheck(localTetrisShape.shapeTopLeftX, localTetrisShape.shapeTopLeftY + 1, localTetrisShape.shapeArray);
	if (flag == 1) flag = 2;
	if (flag == 0) newShapeTopLeftY++;
	return flag;
}

int checkRows()
{
	int score = 0;
	for (int i = HEIGHT - 2; i >= 0; i--)
	{
		int flag = 0;
		for (int j = 1; j <= WIDTH - 2; j++)
			if (bucket[i][j] == ' ') flag = 1;
		if (flag == 0)
		{
			clearRow(i);
			i++;
			score = score + 100;
		}
	}
	return score;
}

int clearRow(int row)
{
	for (int i = row; i > 0; i--)
	{
		for (int j = 1; j <= WIDTH - 2; j++)
		{
			bucket[i][j] = bucket[i - 1][j];
		}

	}
	for (int j = 1; j <= WIDTH - 2; j++)
	{
		bucket[0][j] = ' ';
	}
	return 0;
}

//main
int main()
{
	int gameOver = 0; //initial set to 0 (false)
	int score = 0; //initial set to 0
	int timer = 400; //initial set game speed to 400

	while (gameOver == 0)
	{
		int userInput = 0;
		int bottom = 0;

		srand(time(NULL));
		int number = rand() % 7 + 1;
		TetrisShape shape;
		shape.getShape(number);
		while (bottom != 2)
		{
			userInput = getUserInput(); //input arrow keys
			removeTrail(shape);	// removeTrail erase the previus shape into the bucket
			bottom = moveShape(userInput, shape.shapeTopLeftX, shape.shapeTopLeftY, shape.shapeArray, shape); //moves shape per user input or drop the shape by default
			updateBucket(shape); //bucket with shape
			drawBucket(score); //shows bucket to screen
			removeTrail(shape); //erases old 'X' as it moves
			if (bottom != 2) bottom = moveDown(shape, shape.shapeTopLeftY); //checks for the bottom of the bucket
			updateBucket(shape); //bucket with shape in new position
			drawBucket(score); //shows bucket to screen
			Sleep(timer); // controls the speed of the game
		}

		if (timer < 101)
			timer = 100;
		else
			timer = timer - 5;// makes piece move faster after each loop
		score = score + checkRows(); //updates score
		if (shape.shapeTopLeftY <= 0) gameOver = 1; //sets gameOver (true) if shape is stuck at the top
	}
	cout << "\nGame Over" << endl; //print to screen
	getchar();
	return 0;
}