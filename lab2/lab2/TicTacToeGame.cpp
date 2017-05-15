/*
This is the definition for functions in TicTacToeGame class
Author: Wei Fan
Email: weifan@wustl.edu
*/

#include "stdafx.h"
#include "lab2.h"


ostream& operator<<(ostream& os, pieces p)//define how pieces will print
{
	switch (p)
	{
	case E: os << " ";    break;
	case X: os << "X"; break;
	case O: os << "O";  break;

	}
	return os;
}

void TicTacToeGame::constructBoard(int width, int height)//private function to be called by constructor function
{
	board.resize(board_height+1);
	for (int i = 0; i <= board_height; i++)
	{
		board[i].resize(board_width+1);
	}

	isO = true;//Player X goes first, before each turn, change it
	turns = 0;

}


ostream &operator << (ostream & os, const TicTacToeGame& game)//define how the TicTacToeGame class will print
{
	os << '\n';
	for (int i = game.board_height ; i > 0; i--)
	{
		os << i;
		for (int j = 1; j <= game.board_width; j++)
		{
			os << game.board[i][j];
		}
		os << '\n';
	}
	os << "X";

	for (int i = 1; i <= game.board_width; i++)
	{
		os << i;
	}
	return os;
}

bool TicTacToeGame::done()
{

	for (int i = 1; i <= 3; i++)//3-Xs or Os in a horizontal line
	{
		if (board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][3] != E)
		{
			return true;
		}
	}

	for (int i = 1; i <= 3; i++)//3-Xs or Os in a vertical line
	{
		if (board[1][i] == board[2][i] && board[2][i] == board[3][i] && board[3][i] != E)
		{
			return true;
		}
	}

	if ((board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] != E) || (board[1][3] == board[2][2] && board[2][2] == board[3][1] && board[3][1] != E))//3-Xs or Os in a diagnoal line
	{
		return true;
	}

	return false;
}

bool TicTacToeGame::draw()
{
	if (done())//a player wins
	{
		return false;
	}

	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			if (board[i][j] == E)//a square is empty
			{
				return false;
			}

		}
	}

	return true;//game end with a draw
}


bool	isInteger(string str)
{
	//first character is '+' or '-' or digit
	if (str[0] != '+' && str[0] != '-' && !isdigit(str[0]))
	{
		return false;
	}
	//following characters are digits
	for (size_t i = 1; i < str.length(); ++i)
	{
		if (!isdigit(str[i]))
		{
			return false;
		}
	}
	return true;
}

bool TicTacToeGame::prompt(unsigned int&x, unsigned int& y)
{
	string s1, s2;
	while (true)
	{
		cout << "Please input valid coordinate of a square on the board as a comma-separated pair of unsigned decimal integers. Or input \"quit\" to quit the game." << endl;
		string s = "";
		getline(cin, s);
		if (s == "quit")//player choose quit
		{
			return false;
		}

		string tmpS = s;


		int comma = s.find(",");

		if (comma == -1)
		{
			cout << "invalid input!" << endl;
			continue;
		}
		s.replace(comma, 1, " ");
		istringstream iss(s);

		if (!(iss >> s1) || !(iss >> s2) || !isInteger(s1) || !isInteger(s2))
		{
			cout << "invalid input!" << endl;
			continue;
		}

		else
		{
			istringstream iss1(s1);
			istringstream iss2(s2);
			iss1 >> x;
			iss2 >> y;
		}

		if (x<1 || x>board_width || y<1 || y>board_height)
		{
			cout << "out of range!" << endl;
			continue;
		}

		tmpMove = tmpS;//store this move to s
		return true;


	}
}


/*
bool TicTacToeGame::prompt(unsigned int&x, unsigned int& y)
{
	
	while (true)
	{
		cout << "Please input valid coordinate of a square on the board as a comma-separated pair of unsigned decimal integers. Or input \"quit\" to quit the game." << endl;
		string s="";
		getline(cin, s);
		if (s == "quit")//player choose quit
		{
			return false;
		}

		char *c = const_cast<char*>(s.c_str());
		int len = strlen(c);
		if (len != 3)//input not like "1,1", which has a length 3
		{
			cout << "invalid input!" << endl;
			continue;
		}
		if (c[0]<49 || c[0]>51)//in put out of range
		{
			cout << "input value should between 1 to 3" << endl;
			continue;
		}

		if (c[1] != 44)//not a comma
		{
			cout << "please separate with comma" << endl;
			continue;
		}

		if (c[2]<49 || c[2]>51)//in put out of range
		{
			cout << "input value should between 1 to 3" << endl;
			continue;
		}

		//get the coordinate
		x = c[0] - 48;
		y = c[2] - 48;

		tmpMove = s;//store this move to s

		return true;
	}
}
*/

bool TicTacToeGame::turn()
{
	isO = (!isO);//switch players
	pieces current_piece = E;
	if (isO)
	{
		current_piece = O;
	}
	else
	{
		current_piece = X;
	}

	unsigned int x;
	unsigned int y;


	do
	{
		cout << "Player " << current_piece << "'s turn: " << endl;
		bool playing = prompt(x, y);
		if (!playing)//player choose quit game
		{
			return false;
		}


		if (board[y][x] != E)//coordinates occupied, should call prompt function again
		{
			cout << "The coordinates you entered is occupied!" << endl;
		}

		else//valid input, stop calling prompt function
		{
			break;
		}

	} while (true);

	board[y][x] = current_piece;//move piece to the square

	cout << *this << endl;//print current board
	cout << endl;

	//print the record of the current player
	cout << "Player " << current_piece << ": ";
	if (isO)//player O
	{
		if (Omove.length() != 0)//not first move
		{
			Omove += "; ";
		}
		Omove += tmpMove;
		cout << Omove << endl;
	}
	else//player X
	{
		if (Xmove.length() != 0)//not first move
		{
			Xmove += "; ";
		}
		Xmove += tmpMove;
		cout << Xmove << endl;
	}

	turns++;//count turns
	return true;
}

int TicTacToeGame::play()
{
	cout << *this << endl;//print the initial board
	while (turn())//users continue take moves
	{
		if (draw())//game end in draw
		{
			cout << "Draw! No valid move available!" << endl;
			cout << turns << "turns were played" << endl;
			return drawGame;
		}

		if (done())//game end in one player wins
		{
			if (isO)
			{
				cout << "Player O wins!" << endl;
			}
			else
			{
				cout << "Player X wins!" << endl;
			}
			
			cout << turns << " turn(s) was(were) played" << endl;
			return aPlayerWins;
		}
	}

	//user quit game
	if (isO)
	{
		cout << "Player O quit the game" << endl;
	}
	else
	{
		cout << "Player X quit the game" << endl;
	}
	cout << turns << " turn(s) was(were) played" << endl;
	return aPlayerQuits;
}