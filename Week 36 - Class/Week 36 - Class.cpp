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
	cout << "Welcome to Tic-Tac-To!" << endl << endl;
	cout << "1. Play" << endl; //Select between Single-/ or Multiplayer
	cout << "2. Settings" << endl; //Game Settings
	cout << "3. Scoreboard" << endl; //Game Settings
	cout << "4. Reset" << endl << endl; //Reset all important game variables
	cout << "5. Exit" << endl; //End the game
}
void menu() {
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

//The game play itself out	---------------------------------------------------------------------------------------
void modeCelect() {

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
	for (size_t rounds = 0; rounds < 1;)
	{
		counterRounds = 1;
		winner = 0;
		numberSort();

		for (size_t turns = 0; turns < 1;)
		{

			if (counterRounds < maxRounds)
			{
				whichPlayer();
				boardPrint();
				if (computerPlayer == 0)
				{
					InputNumber();
				}
				else
				{
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
				if (winner > 0)
				{
					counterRounds = maxRounds;
				}
			}
			else
			{
				boardPrint();

				if (winner == 0)
				{
					draw += 1;
					cout << "...it's a draw...";
				}
				else if (winner == 1)
				{
					player1Win += 1;
					player2Lose += 1;
					cout << player1Name << " is the vinner!!!";
				}
				else if (winner == 2)
				{
					player2Win += 1;
					player1Lose += 1;
					cout << player1Name << " is the vinner!!!";
				}
				else
				{
				}

				roundsPlayed += 1;
				cout << endl << endl;
				cout << "1. New game" << endl;
				cout << "2. Back to menu" << endl;

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
	// Input number	-------------------------------------------------------------------------------------------
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
	// Input number	-------------------------------------------------------------------------------------------
	for (size_t i = 0; i < 1;)
	{
		rng();

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
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
	}
}

void whichPlayer() {
	if (counterRounds % 2)
	{
		XorO = player1;
		player = 1;
	}
	else
	{
		XorO = player2;
		player = 2;
	}
}
void winCondition() {
	winner = 0;

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

//Menu	-----------------------------------------------------------------------------------------------------------
void settings() {
	for (size_t i = 0; i < 1;)
	{
		cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
		cout << "Settings" << endl << endl;
		cout << "1. Change player names" << endl; //Select new characters names
		cout << "2. Change player characters" << endl; //Select new characters that will be displayed for each player
		cout << "3. Back to menu" << endl; //End the game
		cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;

		char MenuCelect = _getch();
		system("cls");
		switch (MenuCelect)
		{
		case '1':
			cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
			cout << "Change the name of player 1: ";
			getline(cin, player1Name);
			cout << "Change the name of player 2: ";
			getline(cin, player2Name);
			i++;
			break;
		case '2':
			cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
			cout << "Change player 1: ";
			cin >> player1;
			clearCin();
			cout << "Change player 2: ";
			cin >> player2;
			clearCin();
			i++;
		case '3':
			i++;
			break;
		default:
			break;
		}
	}
}
void scoreBoard() {
	cout << "*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
	cout << "Scoreboard" << endl;
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

//Extra	-----------------------------------------------------------------------------------------------------------
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