#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <random>

using namespace std;

#pragma region Functions
void board();
void menu();
void boardPrint();
void InputNumber();
void InputNumberComputer();
void numberSort();
void whichPlayer();
void settings();
void winCondition();
void scoreBoard();
void resetGame();
void clearCin();
void intro();
void menuInfo();
void modeCelect();
void rng();

#pragma endregion
#pragma region Variables
const int boardSize = 3; //Length of the board (rows and columns)
const int row = boardSize; //Length of rows
const int column = boardSize; //Length of colums
char MenuCelect{}; //Input variable in different menus
int counterRounds{}; //Keep track of the rounds in a game
int maxRounds = (row * column); //Max number of rounds
int player{1}; //Keeps track of the different players
char XorO{}; //Displays different character based on the player
char player1{'x'}; //The character of player 1
char player2{'o'}; //The character of player 2
int player1Win{};
int player1Lose{};
int player2Win{};
int player2Lose{};
int draw{};
int winner{};
int roundsPlayed{};
int changeLayout{};
int computerPlayer{};
int numberMin{1};
int numberMax{9};
int randomNumber{};
string player1Name{"Player 1"};
string player2Name{"Player 2"};

#pragma endregion
#pragma region Arrays
char placeholder[row][column]; //Shows the numbers in the grid of the game board
#pragma endregion

int main()
{
	intro();

	for (size_t i = 0; i < 1;)
	{
		menu(); //Startup with the menu screen
	}
}

//The Menu	-------------------------------------------------------------------------------------------------------
void intro() {
	//A litte animation, only at the startup, for might and glory
	for (size_t i = 0; i < 3;)
	{
		if (changeLayout == 0)
		{
			cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
			menuInfo();
			cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
			Sleep(300);
			changeLayout = 1;
			system("cls");
		}
		else
		{
			cout << "-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
			menuInfo();
			cout << "-*-*-*-*-*-*-*-*-*-*-*-*-" << endl << endl;
			Sleep(300);
			changeLayout = 0;
			system("cls");
			i++;
		}
	}
}
void menuInfo() {
	//Instead of accidentaly writing this text several times, I can now reffer to it as a function for easier edit
	cout << "Welcome to Tic-Tac-To!" << endl << endl;
	cout << "1. Play" << endl; //Select between Single-/ or Multiplayer
	cout << "2. Settings" << endl; //Game Settings
	cout << "3. Scoreboard" << endl; //Game Settings
	cout << "4. Reset" << endl << endl; //Reset all important game variables
	cout << "5. Exit" << endl; //End the game
}
void menu() {
	//The starting menu with different options
	for (size_t i = 0; i < 1;)
	{
		cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
		menuInfo();
		cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;

		char MenuCelect = _getch();
		system("cls");
		switch (MenuCelect)
		{
		case '1':
			modeCelect();
			i++;
			break;
		case '2':
			settings();
			break;
		case '3':
			scoreBoard();
			break;
		case '4':
			resetGame();
			break;
		case '5':
			exit(0);
			break;
		default:
			break;
		}
		system("cls");
	}
}

//The gameplay segment	-------------------------------------------------------------------------------------------
void modeCelect() {
	//Here you can select single-/ or multiplayer
	for (size_t i = 0; i < 1;)
	{
		cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
		cout << "1. Player vs. Player" << endl;
		cout << "2. Player vs. Computer" << endl;
		cout << "3. Back to Menu" << endl;
		cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;

		char MenuCelect = _getch();
		system("cls");
		switch (MenuCelect)
		{
		case '1':
			computerPlayer = 0;
			board();
			i++;
			break;
		case '2':
			computerPlayer = 1;
			board();
			i++;
			break;
		case '3':
			i++;
			break;
		default:
			break;
		}
	}

}
void board()
{
	//The "main"-function of the Tic-Tac-Toe board
	//In this function everything about the actual game is lined up
	for (size_t rounds = 0; rounds < 1;)
	{
		//Reset the board and it's variables at the beginning and in between runs
		counterRounds = 1;
		winner = 0;
		numberSort();

		for (size_t turns = 0; turns < 1;)
		{
			//Run if max rounds isn't hitted yet
			if (counterRounds < maxRounds)
			{
				whichPlayer();
				boardPrint();
				//Tells what happens during the different game modes
				if (computerPlayer == 0)
				{
					InputNumber();
				}
				else
				{
					//If it is "Player vs. Computer", the player and the computer have to act during different turns
					if (counterRounds % 2)
					{
						InputNumber();
					}
					else
					{
						InputNumberComputer();
					}
				}
				winCondition();
				system("cls");
				//If we have a winner before the game hits its maximum rounds, end the game and send the players right to the "Winner"-segment
				if (winner > 0)
				{
					counterRounds = maxRounds;
				}
			}
			else
			{
				boardPrint();
				//If there is a tie after the game hits its maximum rounds, end the game and play the "draw"-text
				if (winner == 0)
				{
					Sleep(600);
					draw += 1;
					cout << "...it's a draw...";
				}
				//If player 1 is the winner, play the "Player 1"- winner-text
				else if (winner == 1)
				{
					Sleep(600);
					player1Win += 1;
					player2Lose += 1;
					cout << player1Name << " is the vinner!!!";
				}
				//If player 2 is the winner, play the "Player 2"- winner-text
				else if (winner == 2)
				{
					Sleep(600);
					player2Win += 1;
					player1Lose += 1;
					cout << player1Name << " is the vinner!!!";
				}
				else
				{
				}
				//After the resolve of the game, the players have the option to play again or return to the starting menu
				roundsPlayed += 1;
				cout << endl << endl;
				cout << "1. New game" << endl;
				cout << "2. Back to menu" << endl;
				winner = -1;

				char MenuCelect = _getch();
				system("cls");

				switch (MenuCelect)
				{
				case '1':
					turns++;
					break;
				case'2':
					turns++;
					rounds++;
					break;
				default:
					break;
				}
			}
		}
	}
}

void numberSort() {
	//Sorting of the numbers inside the 2D board in the "placeholder" array
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < column; j++)
		{
			placeholder[i][j] = ((i * boardSize) + j + 49); //49 is the number 1 in char
		}
	}
}
void boardPrint() {
	//Printing of the board
	cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;

	for (int i{}; i < row; i++)
	{
		for (int k{}; k < column; k++)
		{
			if (k % boardSize == 0)
			{
				cout << " " << placeholder[i][k] << " ";
			}
			else
			{
				cout << "| " << placeholder[i][k] << " ";
			}
		}
		cout << endl;

		if (i < row - 1)
		{
			for (size_t j = 0; j < column; j++)
			{
				{
					cout << "----";
				}
			}
		}
		cout << endl;
	}
	if (counterRounds >= maxRounds)
	{
		cout << "Round: -" << endl << endl;
	}
	else
	{
		cout << "Round: " << counterRounds << endl;
		if (counterRounds % 2)
		{
			cout << player1Name << "'s turn ( " << XorO << " )" << endl << endl;
		}
		else
		{
			cout << player2Name << "'s turn ( " << XorO << " )" << endl << endl;
		}
	}
	
}
void InputNumber() {
	//Input a valid game number during play ----------------------------------------------------------------------
	int choice{};
	int d = 0;

	while (d < 1)
	{
		cout << "Enter your input: ";
		char choice = _getch();
		cout << choice;
		Sleep(500);

		switch (choice)
		{
		case '1':
			if (placeholder[0][0] == player1 || placeholder[0][0] == player2)
			{}
			else
			{
				placeholder[0][0] = XorO;
				counterRounds += 1;
			}
			d++;
			break;
		case '2':
			if (placeholder[0][1] == player1 || placeholder[0][1] == player2)
			{}
			else
			{
				placeholder[0][1] = XorO;
				counterRounds += 1;
			}
			d++;
			break;
		case '3':
			if (placeholder[0][2] == player1 || placeholder[0][2] == player2)
			{}
			else
			{
				placeholder[0][2] = XorO;
				counterRounds += 1;
			}
			d++;
			break;
		case '4':
			if (placeholder[1][0] == player1 || placeholder[1][0] == player2)
			{}
			else
			{
				placeholder[1][0] = XorO;
				counterRounds += 1;
			}
			d++;
			break;
		case '5':
			if (placeholder[1][1] == player1 || placeholder[1][1] == player2)
			{}
			else
			{
				placeholder[1][1] = XorO;
				counterRounds += 1;
			}
			d++;
			break;
		case '6':
			if (placeholder[1][2] == player1 || placeholder[1][2] == player2)
			{}
			else
			{
				placeholder[1][2] = XorO;
				counterRounds += 1;
			}
			d++;
			break;
		case '7':
			if (placeholder[2][0] == player1 || placeholder[2][0] == player2)
			{}
			else
			{
				placeholder[2][0] = XorO;
				counterRounds += 1;
			}
			d++;
			break;
		case '8':
			if (placeholder[2][1] == player1 || placeholder[2][1] == player2)
			{}
			else
			{
				placeholder[2][1] = XorO;
				counterRounds += 1;
			}
			d++;
			break;
		case '9':
			if (placeholder[2][2] == player1 || placeholder[2][2] == player2)
			{}
			else
			{
				placeholder[2][2] = XorO;
				counterRounds += 1;
			}
			d++;
			break;
		default:
			d++;
			break;
		}
	}
}
void InputNumberComputer() {
	//1.0 - Computer inputs a valid game number during play	-----------------------------------------------------------
	//2.0 - Lots of lines, but the AI has become smart now!
	for (size_t i = 0; i < 1;)
	{
		//If player 2 is about to win, player 2 HAVE TO place it in the winning spot
		//Horizontally
		if (placeholder[0][1] == player2 && placeholder[0][2] == player2 && placeholder[0][0] != player1)
		{
		placeholder[0][0] = XorO;
		counterRounds += 1;
		i++;
		}
		else if (placeholder[0][0] == player2 && placeholder[0][2] == player2 && placeholder[0][1] != player1)
		{
		placeholder[0][1] = XorO;
		counterRounds += 1;
		i++;
		}
		else if (placeholder[0][0] == player2 && placeholder[0][1] == player2 && placeholder[0][2] != player1)
		{
		placeholder[0][2] = XorO;
		counterRounds += 1;
		i++;
		}
		else if (placeholder[1][1] == player2 && placeholder[1][2] == player2 && placeholder[1][0] != player1)
		{
		placeholder[1][0] = XorO;
		counterRounds += 1;
		i++;
		}
		else if (placeholder[1][0] == player2 && placeholder[1][2] == player2 && placeholder[1][1] != player1)
		{
		placeholder[1][1] = XorO;
		counterRounds += 1;
		i++;
		}
		else if (placeholder[1][0] == player2 && placeholder[1][1] == player2 && placeholder[1][2] != player1)
		{
		placeholder[1][2] = XorO;
		counterRounds += 1;
		i++;
		}
		else if (placeholder[2][1] == player2 && placeholder[2][2] == player2 && placeholder[2][0] != player1)
		{
		placeholder[2][0] = XorO;
		counterRounds += 1;
		i++;
		}
		else if (placeholder[2][0] == player2 && placeholder[2][2] == player2 && placeholder[2][1] != player1)
		{
		placeholder[2][1] = XorO;
		counterRounds += 1;
		i++;
		}
		else if (placeholder[2][0] == player2 && placeholder[2][1] == player2 && placeholder[2][2] != player1)
		{
		placeholder[2][2] = XorO;
		counterRounds += 1;
		i++;
		}

		//Vertically
		else if (placeholder[1][0] == player2 && placeholder[2][0] == player2 && placeholder[0][0] != player1)
		{
		placeholder[0][0] = XorO;
		counterRounds += 1;
		i++;
		}
		else if (placeholder[0][0] == player2 && placeholder[2][0] == player2 && placeholder[1][0] != player1)
		{
		placeholder[1][0] = XorO;
		counterRounds += 1;
		i++;
		}
		else if (placeholder[0][0] == player2 && placeholder[1][0] == player2 && placeholder[2][0] != player1)
		{
		placeholder[2][0] = XorO;
		counterRounds += 1;
		i++;
		}
		else if (placeholder[1][1] == player2 && placeholder[2][1] == player2 && placeholder[0][1] != player1)
		{
		placeholder[0][1] = XorO;
		counterRounds += 1;
		i++;
		}
		else if (placeholder[0][1] == player2 && placeholder[2][1] == player2 && placeholder[1][1] != player1)
		{
		placeholder[1][1] = XorO;
		counterRounds += 1;
		i++;
		}
		else if (placeholder[0][1] == player2 && placeholder[1][1] == player2 && placeholder[2][1] != player1)
		{
		placeholder[2][1] = XorO;
		counterRounds += 1;
		i++;
		}
		else if (placeholder[1][2] == player2 && placeholder[2][2] == player2 && placeholder[0][2] != player1)
		{
		placeholder[0][2] = XorO;
		counterRounds += 1;
		i++;
		}
		else if (placeholder[0][2] == player2 && placeholder[2][2] == player2 && placeholder[1][2] != player1)
		{
		placeholder[1][2] = XorO;
		counterRounds += 1;
		i++;
		}
		else if (placeholder[0][2] == player2 && placeholder[1][2] == player2 && placeholder[2][2] != player1)
		{
		placeholder[2][2] = XorO;
		counterRounds += 1;
		i++;
		}

		//Diagonally
		else if (placeholder[1][1] == player2 && placeholder[2][2] == player2 && placeholder[0][0] != player1)
		{
		placeholder[0][0] = XorO;
		counterRounds += 1;
		i++;
		}
		else if (placeholder[0][0] == player2 && placeholder[2][2] == player2 && placeholder[1][1] != player1)
		{
		placeholder[1][1] = XorO;
		counterRounds += 1;
		i++;
		}
		else if (placeholder[0][0] == player2 && placeholder[1][1] == player2 && placeholder[2][2] != player1)
		{
		placeholder[2][2] = XorO;
		counterRounds += 1;
		i++;
		}
		else if (placeholder[1][1] == player2 && placeholder[0][2] == player2 && placeholder[2][0] != player1)
		{
		placeholder[2][0] = XorO;
		counterRounds += 1;
		i++;
		}
		else if (placeholder[2][0] == player2 && placeholder[0][2] == player2 && placeholder[1][1] != player1)
		{
		placeholder[1][1] = XorO;
		counterRounds += 1;
		i++;
		}
		else if (placeholder[0][2] == player2 && placeholder[1][1] == player2 && placeholder[2][0] != player1)
		{
		placeholder[2][0] = XorO;
		counterRounds += 1;
		i++;
		}

		//If the middle spot (no.5) isn't chosen by player 1 at the beginning of the game, ALWAYS choose this spot
		else if (placeholder[1][1] != player1 && placeholder[1][1] != player2)
		{
			placeholder[1][1] = XorO;
			counterRounds += 1;
			i++;
		}

		//If player 1 are gonna win during the next move, the computer need to stop it before it's too late
		//Horisontaly
		else if (placeholder[0][1] == player1 && placeholder[0][2] == player1 && placeholder[0][0] != player2)
		{
			placeholder[0][0] = XorO;
			counterRounds += 1;
			i++;
		}
		else if (placeholder[0][0] == player1 && placeholder[0][2] == player1 && placeholder[0][1] != player2)
		{
			placeholder[0][1] = XorO;
			counterRounds += 1;
			i++;
		}
		else if (placeholder[0][0] == player1 && placeholder[0][1] == player1 && placeholder[0][2] != player2)
		{
			placeholder[0][2] = XorO;
			counterRounds += 1;
			i++;
		}
		else if (placeholder[1][1] == player1 && placeholder[1][2] == player1 && placeholder[1][0] != player2)
		{
			placeholder[1][0] = XorO;
			counterRounds += 1;
			i++;
		}
		else if (placeholder[1][0] == player1 && placeholder[1][2] == player1 && placeholder[1][1] != player2)
		{
			placeholder[1][1] = XorO;
			counterRounds += 1;
			i++;
		}
		else if (placeholder[1][0] == player1 && placeholder[1][1] == player1 && placeholder[1][2] != player2)
		{
			placeholder[1][2] = XorO;
			counterRounds += 1;
			i++;
		}
		else if (placeholder[2][1] == player1 && placeholder[2][2] == player1 && placeholder[2][0] != player2)
		{
			placeholder[2][0] = XorO;
			counterRounds += 1;
			i++;
		}
		else if (placeholder[2][0] == player1 && placeholder[2][2] == player1 && placeholder[2][1] != player2)
		{
			placeholder[2][1] = XorO;
			counterRounds += 1;
			i++;
		}
		else if (placeholder[2][0] == player1 && placeholder[2][1] == player1 && placeholder[2][2] != player2)
		{
			placeholder[2][2] = XorO;
			counterRounds += 1;
			i++;
		}

		//Vertically
		else if (placeholder[1][0] == player1 && placeholder[2][0] == player1 && placeholder[0][0] != player2)
		{
			placeholder[0][0] = XorO;
			counterRounds += 1;
			i++;
		}
		else if (placeholder[0][0] == player1 && placeholder[2][0] == player1 && placeholder[1][0] != player2)
		{
			placeholder[1][0] = XorO;
			counterRounds += 1;
			i++;
		}
		else if (placeholder[0][0] == player1 && placeholder[1][0] == player1 && placeholder[2][0] != player2)
		{
			placeholder[2][0] = XorO;
			counterRounds += 1;
			i++;
		}
		else if (placeholder[1][1] == player1 && placeholder[2][1] == player1 && placeholder[0][1] != player2)
		{
			placeholder[0][1] = XorO;
			counterRounds += 1;
			i++;
		}
		else if (placeholder[0][1] == player1 && placeholder[2][1] == player1 && placeholder[1][1] != player2)
		{
			placeholder[1][1] = XorO;
			counterRounds += 1;
			i++;
		}
		else if (placeholder[0][1] == player1 && placeholder[1][1] == player1 && placeholder[2][1] != player2)
		{
			placeholder[2][1] = XorO;
			counterRounds += 1;
			i++;
		}
		else if (placeholder[1][2] == player1 && placeholder[2][2] == player1 && placeholder[0][2] != player2)
		{
			placeholder[0][2] = XorO;
			counterRounds += 1;
			i++;
		}
		else if (placeholder[0][2] == player1 && placeholder[2][2] == player1 && placeholder[1][2] != player2)
		{
			placeholder[1][2] = XorO;
			counterRounds += 1;
			i++;
		}
		else if (placeholder[0][2] == player1 && placeholder[1][2] == player1 && placeholder[2][2] != player2)
		{
			placeholder[2][2] = XorO;
			counterRounds += 1;
			i++;
		}

		//Diagonally
		else if (placeholder[1][1] == player1 && placeholder[2][2] == player1 && placeholder[0][0] != player2)
		{
		placeholder[0][0] = XorO;
		counterRounds += 1;
		i++;
		}
		else if (placeholder[0][0] == player1 && placeholder[2][2] == player1 && placeholder[1][1] != player2)
		{
		placeholder[1][1] = XorO;
		counterRounds += 1;
		i++;
		}
		else if (placeholder[0][0] == player1 && placeholder[1][1] == player1 && placeholder[2][2] != player2)
		{
		placeholder[2][2] = XorO;
		counterRounds += 1;
		i++;
		}
		else if (placeholder[1][1] == player1 && placeholder[0][2] == player1 && placeholder[2][0] != player2)
		{
		placeholder[2][0] = XorO;
		counterRounds += 1;
		i++;
		}
		else if (placeholder[2][0] == player1 && placeholder[0][2] == player1 && placeholder[1][1] != player2)
		{
		placeholder[1][1] = XorO;
		counterRounds += 1;
		i++;
		}
		else if (placeholder[0][2] == player1 && placeholder[1][1] == player1 && placeholder[2][0] != player2)
		{
		placeholder[2][0] = XorO;
		counterRounds += 1;
		i++;
		}

		//If either player 1 or player 2 are close to winning, the computer will place it in a random available spot
		else
	{
	rng(); //Random number generation between 1 and 9

	if (randomNumber == 1)
	{
		if (placeholder[0][0] == player1 || placeholder[0][0] == player2)
		{
		}
		else
		{
			placeholder[0][0] = XorO;
			counterRounds += 1;
			i++;
		}
	}
	else if (randomNumber == 2)
	{
		if (placeholder[0][1] == player1 || placeholder[0][1] == player2)
		{
		}
		else
		{
			placeholder[0][1] = XorO;
			counterRounds += 1;
			i++;
		}
	}
	else if (randomNumber == 3)
	{
		if (placeholder[0][2] == player1 || placeholder[0][2] == player2)
		{
		}
		else
		{
			placeholder[0][2] = XorO;
			counterRounds += 1;
			i++;
		}
	}
	else if (randomNumber == 5)
	{
		if (placeholder[1][1] == player1 || placeholder[1][1] == player2)
		{
		}
		else
		{
			placeholder[1][1] = XorO;
			counterRounds += 1;
			i++;
		}
	}
	else if (randomNumber == 6)
	{
		if (placeholder[1][2] == player1 || placeholder[1][2] == player2)
		{
		}
		else
		{
			placeholder[1][2] = XorO;
			counterRounds += 1;
			i++;
		}
	}
	else if (randomNumber == 7)
	{
		if (placeholder[2][0] == player1 || placeholder[2][0] == player2)
		{
		}
		else
		{
			placeholder[2][0] = XorO;
			counterRounds += 1;
			i++;
		}
	}
	else if (randomNumber == 8)
	{
		if (placeholder[2][1] == player1 || placeholder[2][1] == player2)
		{
		}
		else
		{
			placeholder[2][1] = XorO;
			counterRounds += 1;
			i++;
		}
	}
	else
	{
		if (randomNumber == 9)
		{
			if (placeholder[2][2] == player1 || placeholder[2][2] == player2)
			{
			}
			else
			{
				placeholder[2][2] = XorO;
				counterRounds += 1;
				i++;
			}
		}
	}
	}
		//"..." for a dramatic, "thinking"-effect from the computer
		cout << ".";
		Sleep(300);
		cout << ".";
		Sleep(300);
		cout << ".";
		Sleep(300);
	}
}

void whichPlayer() {
	//Keeps the player's playing order in order
	if (counterRounds % 2)
	{
		//Gives the variable "XorO" the name of player 1
		XorO = player1;
		player = 1;
	}
	else
	{
		//Gives the variable "XorO" the name of player 2
		XorO = player2;
		player = 2;
	}
}
void winCondition() {
	winner = 0;
	//If any player matches 3 spots i a row, that player wins and the game ends
	//If Player 1 wins, the "winner"-variable goes from 0 to 1, which activate the "Player 1 winner"-text
	//If Player 2 wins, the "winner"-variable goes from 0 to 2, which activate the "Player 2 winner"-text

	//Calculating if the players have 3 matching spots in a row to declare a winner
	//Since this game is turn-based, the order of this calculation isn't important
	//This calculation must be executed after each turn to check if any player has won
	//player 1 - Horisontally
	if (placeholder[0][0] == player1 && placeholder[0][1] == player1 && placeholder[0][2] == player1)
	{
		winner = 1;
	}
	if (placeholder[1][0] == player1 && placeholder[1][1] == player1 && placeholder[1][2] == player1)
	{
		winner = 1;
	}
	if (placeholder[2][0] == player1 && placeholder[2][1] == player1 && placeholder[2][2] == player1)
	{
		winner = 1;
	}
	//Player 1 - Vertically
	if (placeholder[0][0] == player1 && placeholder[1][0] == player1 && placeholder[2][0] == player1)
	{
		winner = 1;
	}
	if (placeholder[0][1] == player1 && placeholder[1][1] == player1 && placeholder[2][1] == player1)
	{
		winner = 1;
	}
	if (placeholder[0][2] == player1 && placeholder[1][2] == player1 && placeholder[2][2] == player1)
	{
		winner = 1;
	}
	//Player 1 - Diagonally
	if (placeholder[0][0] == player1 && placeholder[1][1] == player1 && placeholder[2][2] == player1)
	{
		winner = 1;
	}
	if (placeholder[0][2] == player1 && placeholder[1][1] == player1 && placeholder[2][0] == player1)
	{
		winner = 1;
	}

	//-------------------------------------------------------------------------------------------------------------

	//player 2 - Horisontally
	if (placeholder[0][0] == player2 && placeholder[0][1] == player2 && placeholder[0][2] == player2)
	{
		winner = 2;
	}
	if (placeholder[1][0] == player2 && placeholder[1][1] == player2 && placeholder[1][2] == player2)
	{
		winner = 2;
	}
	if (placeholder[2][0] == player2 && placeholder[2][1] == player2 && placeholder[2][2] == player2)
	{
		winner = 2;
	}
	//Player 2 - Vertically
	if (placeholder[0][0] == player2 && placeholder[1][0] == player2 && placeholder[2][0] == player2)
	{
		winner = 2;
	}
	if (placeholder[0][1] == player2 && placeholder[1][1] == player2 && placeholder[2][1] == player2)
	{
		winner = 2;
	}
	if (placeholder[0][2] == player2 && placeholder[1][2] == player2 && placeholder[2][2] == player2)
	{
		winner = 2;
	}
	//Player 2 - Diagonally
	if (placeholder[0][0] == player2 && placeholder[1][1] == player2 && placeholder[2][2] == player2)
	{
		winner = 2;
	}
	if (placeholder[0][2] == player2 && placeholder[1][1] == player2 && placeholder[2][0] == player2)
	{
		winner = 2;
	}
}

//Other selectables in the starting menu	-----------------------------------------------------------------------
void settings() {
	//The "Settings"-menu
	for (size_t i = 0; i < 1;)
	{
		system("cls");
		cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
		cout << "Settings" << endl << endl;
		cout << "1. Change player names" << endl; //Select new characters names
		cout << "2. Change player characters" << endl; //Select new characters that will be displayed for each player (instead of x and o)
		cout << "3. Back to menu" << endl; //Go back to the starting menu
		cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;

		char MenuCelect = _getch();
		system("cls");
		switch (MenuCelect)
		{
		case '1':
			//Give both players new names
			cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
			cout << "Change the name of player 1: ";
			getline(cin, player1Name);
			cout << "Change the name of player 2: ";
			getline(cin, player2Name);
			break;
		case '2':
			//Give both players new characters (instead of x and o)
			cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
			cout << "Change player 1: ";
			cin >> player1;
			clearCin();
			cout << "Change player 2: ";
			cin >> player2;
			clearCin();
			break;
		case '3':
			i++;
			break;
		default:
			break;
		}
	}
}
void scoreBoard() {
	//The scorebord that brings all the important information about the game to the player(s)
	cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
	cout << "Scoreboard" << endl;
	//Removes grammer error if only 1 game has been played
		if (roundsPlayed == 1)
			{cout << "Played " << roundsPlayed << " time" << endl << endl;}
		else
			{cout << "Games played: " << roundsPlayed << " times" << endl << endl;}
	cout << player1Name << " ( " << player1 << " )" << endl;
	cout << "---------" << endl;
	cout << "Win:\t" << player1Win << endl;
	cout << "Lose:\t" << player1Lose << endl << endl;
	cout << player2Name << " ( " << player2 << " )" << endl;
	cout << "---------" << endl;
	cout << "Win:\t" << player2Win << endl;
	cout << "Lose:\t" << player2Lose << endl << endl;
	cout << "Draw:\t" << draw << endl;
	cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
	system("pause");
}
void resetGame() {
	//Reset all game variables, names ex. to its original state
	for (size_t i = 0; i < 1;)
	{
		cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
		cout << "Do you want to reset all stats?" << endl;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;

		char MenuCelect = _getch();
		system("cls");
		switch (MenuCelect)
		{
		case '1': case 'Y': case 'y':
			cout << "x-x-x-x-x-x-x-x-x-x-x-x-x-x-x" << endl << endl;
			cout << "All stats have been deleted!" << endl << endl;
			cout << "x-x-x-x-x-x-x-x-x-x-x-x-x-x-x" << endl;
			Sleep(1000);
			player1 = 'x';
			player2 = 'o' ; 
			player1Win = 0;
			player1Lose = 0;
			player2Win = 0;
			player2Lose = 0;
			draw = 0;
			winner = 0;
			roundsPlayed = 0;
			player1Name = "Player 1";
			player2Name = "Player 2";
			i++;
			break;
		case '2': case 'N': case 'n':
			i++;
			break;
		default:
			break;
		}
	}
}

//Extra/hidden stuff	-------------------------------------------------------------------------------------------
void clearCin() {
	cin.clear();
	cin.ignore(32767, '\n');
}
void rng() {
	random_device rd;
	mt19937_64 gen(rd());
	uniform_int_distribution<int> RNG(numberMin, numberMax);
	randomNumber = RNG(gen);
}