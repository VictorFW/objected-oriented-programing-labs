/*
This is the GomokuGame.cpp file
Author: Wei Fan
Email: weifan@wustl.edu
*/


#include "stdafx.h"
#include "GameBase.h"
#include "GomokuGame.h"



string gomoku_toString(pieces p)//define how to print pieces on board
{
	switch (p)
	{
	case E:return " ";
		break;
	case X:return "B";
		break;
	case O:return "W";
		break;
	default: return" ";
		break;
	}
}




ostream &operator << (ostream & os, const GomokuGame& game)//define how the TicTacToeGame class will print
{
	os << '\n';
	for (int i = game.board_height; i > 0; i--)
	{
		os << setw(game.longest_piece_length) << i;
		for (int j = 1; j <= game.board_width; j++)
		{
			os << setw(game.longest_piece_length) << gomoku_toString(game.board[i][j]);
		}
		os << '\n';
		os << '\n';
	}
	os << setw(game.longest_piece_length) << "X";

	for (int i = 1; i <= game.board_width; i++)
	{
		os << setw(game.longest_piece_length) << i;
	}
	return os;
}

void GomokuGame::print()
{
	cout << *this << endl;
}





bool GomokuGame::done()//one player wins
{
	bool flag = false;
	for (int i = 1; i <= board_width; i++)//win with vertical connecting
	{
		for (int j = 1; j <= board_height - connecting + 1; j++)
		{
			if (board[i][j] != E)
			{
				flag = true;
				for (int k = 0; k < connecting - 1; k++)
				{
					if (board[i][j + k] != board[i][j + k + 1])
					{
						flag = false;
						break;
					}
				}
				if (flag == true)
				{
					return true;
				}
			}
		}
	}

	for (int i = 1; i <= board_width - connecting + 1; i++)//win with horizontal connecting
	{
		for (int j = 1; j < board_height; j++)
		{
			if (board[i][j] != E)
			{
				flag = true;
				for (int k = 0; k < connecting - 1; k++)
				{
					if (board[i + k][j] != board[i + k + 1][j])
					{
						flag = false;
						break;
					}
				}
				if (flag == true)
				{
					return true;
				}
			}
		}
	}

	for (int i = 1; i <= board_width - connecting + 1; i++)//win with diagonal like '/'
	{
		for (int j = 1; j <= board_height - connecting + 1; j++)
		{
			if (board[i][j] != E)
			{
				flag = true;
				for (int k = 0; k < connecting - 1; k++)
				{
					if (board[i + k][j + k] != board[i + k + 1][j + k + 1])
					{
						flag = false;
						break;
					}
				}
				if (flag == true)
				{
					return true;
				}
			}
		}
	}

	for (int i = connecting; i <= board_width; i++)//win with diagonal like '\'
	{
		for (int j = 1; j <= board_height - connecting + 1; j++)
		{
			if (board[i][j] != E)
			{
				flag = true;
				for (int k = 0; k < connecting - 1; k++)
				{
					if (board[i - k][j + k] != board[i - k - 1][j + k + 1])
					{
						flag = false;
						break;
					}
				}
				if (flag == true)
				{
					return true;
				}
			}
		}
	}

	return false;//else,return false, game not done
}



bool GomokuGame::stalemate()//game ends in draw
{


	for (int i = 1; i <= board_width; i++)
	{
		for (int j = 1; j <= board_height; j++)
		{
			if (board[i][j] == E)
			{
				return false;
			}
		}
	}

	if (done())
	{
		return false;
	}

	return true;

}


bool GomokuGame::turn()
{
	isO = (!isO);//switch players
	//X is B, O is W
	pieces current_piece = E;
	if (isO)
	{
		current_piece = O;
	}
	else
	{
		current_piece = X;
	}

	int x;
	int y;


	do
	{
		cout << "Player " << gomoku_toString(current_piece) << "'s turn: " << endl;

		bool playing;
		try
		{
			playing = prompt(x, y);
		}
		catch (int)// a player quit the game
		{
			throw;
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

	print();//print current board
	cout << endl;

	//print the record of the current player
	cout << "Player " << gomoku_toString(current_piece) << ": ";
	if (isO)//player W
	{
		if (Omove.length() != 0)//not first move
		{
			Omove += "; ";
		}
		Omove += tmpMove;
		cout << Omove << endl;
	}
	else//player B
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

int GomokuGame::play()
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
				cout << "The White Stone wins!" << endl;
			}
			else
			{
				cout << "The Black Stone wins!" << endl;
			}

			cout << turns << " turns were played" << endl;
			return aPlayerWins;
		}
	}


}