/*
This is the GameBase.cpp file
Author: Wei Fan
Email: weifan@wustl.edu
*/

#include "stdafx.h"
#include "GameBase.h"
#include "TicTacToeGame.h"
#include "GomokuGame.h"


void GameBase::constructBoard(int width, int height)//private function to be called by constructor function
{
	board.resize(board_height + 1);
	for (int i = 0; i <= board_height; i++)
	{
		board[i].resize(board_width + 1);
	}

	turns = 0;
	isO = true;//Player X goes first, before each turn, change it


}


bool GameBase::prompt(int&x, int& y)
{
	string s1, s2;
	while (true)
	{
		cout << "Please input valid coordinate of a square on the board as a comma-separated pair of unsigned decimal integers. Or input \"quit\" to quit the game." << endl;
		string s = "";
		getline(cin, s);
		try
		{
			if (s == "quit")//player choose quit
			{
				int q = aPlayerQuits;
				throw q;
			}
		}
		catch (int)
		{
			throw;
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

		if (!(iss >> s1) || !(iss >> s2) || !is_digit(s1) || !is_digit(s2))
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


int GameBase::play()
{
	print();//print the initial board
	while (true)//users continue take moves
	{
		try
		{
			turn();
		}
		catch (int)// a player quit the game
		{
			throw;
		}

		if (stalemate())//game end in draw
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

			cout << turns << " turns were played" << endl;
			return aPlayerWins;
		}
	}

}


GameBase * GameBase::argCheck(int argc, char * argv[])
{
	string gameName;
	string message;

	if (argc < 2)// no game name
	{
		message = "Please input the game's name after ";
		usage_message(argv[program_name], message);
		return nullptr;
	}

	gameName = argv[game_name];
	toLowercase(gameName);

	if (gameName == "tictactoe")
	{
		if (argc > 2)
		{
			message = "Please do not  input other things other than TicTacToe after ";
			usage_message(argv[program_name], message);
			return nullptr;
		}

		return new TicTacToeGame();
	}

	if (gameName == "gomoku")
	{
		if (argc == 2)
		{
			return new GomokuGame();
		}

		if (argc == 3)//extra credit: input with board size
		{
			if (!is_digit(argv[board_size]))
			{
				cout << "Please input a valid integer as the board size." << endl;
				return nullptr;
			}

			int b_size;
			istringstream iss(argv[board_size]);
			iss >> b_size;

			if (b_size < 1)
			{
				cout << "Please input a positive integer as the size of board." << endl;
				return nullptr;
			}

			return new GomokuGame(b_size);
		}

		if (argc == 4)//extra credit: input with board size and the number of connecting pieces to win
		{
			if (!is_digit(argv[board_size]) || !is_digit(argv[conn_number]))
			{
				cout << "Please input a valid integer as the board size, and a valid integer (greater or equal to 3) as the number of connecting pieces to win after the game's name." << endl;
				return nullptr;
			}

			int b_size;
			int c_num;
			istringstream iss1(argv[board_size]);
			istringstream iss2(argv[conn_number]);

			iss1 >> b_size;
			iss2 >> c_num;
			if (b_size < 1)
			{
				cout << "Please input a positive integer as the size of board." << endl;
				return nullptr;
			}

			if (b_size < c_num)//not possible
			{
				cout << "The size of board should not smaller than the connecting number" << endl;
				return nullptr;
			}

			if (c_num < 3)
			{
				cout << "Please input a connecting number greater than or equal to 3" << endl;
				return nullptr;
			}


			return new GomokuGame(b_size, c_num);

		}

		else
		{
			cout << "Please input board size(optional) and the number of connecting pieces to win(optional) orderly after the game name." << endl;
			return nullptr;
		}

	}

	else
	{
		message = "Please input a correct game's name after ";
		usage_message(argv[program_name], message);
		return nullptr;
	}
}