/*
This is the TicTacToeGame.cpp file
Author: Wei Fan
Email: weifan@wustl.edu
*/


#include "stdafx.h"
#include "TicTacToeGame.h"


string tictactoe_toString(pieces p)//define how to print pieces on board
{
	switch (p)
	{
	case E:return " ";
		break;
	case X:return "X";
		break;
	case O:return "O";
		break;
	default: return" ";
		break;
	}
}



ostream &operator << (ostream & os, const TicTacToeGame& game)//define how the TicTacToeGame class will print
{
	os << '\n';
	for (int i = game.board_height; i >= 1; i--)
	{
		os << setw(game.longest_piece_length) << i;
		for (int j = 1; j <= game.board_width; j++)
		{
			os << setw(game.longest_piece_length) << tictactoe_toString(game.board[i][j]);
		}
		os << '\n';
	}
	os << setw(game.longest_piece_length) << " ";

	for (int i = 1; i <= game.board_width; i++)
	{
		os << setw(game.longest_piece_length) << i;
	}
	return os;
}

void TicTacToeGame::print()
{
	cout << *this << endl;;
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

bool TicTacToeGame::stalemate()
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

	int x;
	int y;


	do
	{
		cout << "Player " << tictactoe_toString(current_piece) << "'s turn: " << endl;
		bool playing;

		try
		{
			playing = prompt(x, y);
			
		}

		catch (...)// a player quit the game or open file fail
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
	if (isO)
	{
		save_O_move += " ";
		save_O_move += tmp_save_move;
	}
	else
	{
		save_X_move += " ";
		save_X_move += tmp_save_move;
	}

	print();//print current board
	cout << endl;

	//print the record of the current player
	cout << "Player " << tictactoe_toString(current_piece) << ": ";
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





void TicTacToeGame::constructBoard(int width, int height)//private function to be called by constructor function
{
	board.resize(board_height + 1);
	for (int i = 0; i <= board_height; i++)
	{
		board[i].resize(board_width + 1);
	}


	string saved_filename;
	ifstream fin;
	string fileName = gamesName;
	string line;
	fin.open(fileName);
	if (!fin.is_open())
	{
		throw fail_open_file;
	}

	getline(fin, saved_filename);

	if (saved_filename != gamesName)
	{
		throw not_valid_file;
	}

	getline(fin, line);
	istringstream inTurns(line);
	inTurns >> turns;

	if (turns == 0)//no saved game
	{
		isO = true;//Player X goes first, before each turn, change it

	}
	else
	{
		getline(fin, save_X_move);
		istringstream inSaveX(save_X_move);
		int tmpx, tmpy;
		while (inSaveX >> tmpx >> tmpy)
		{

			board[tmpy][tmpx] = X;
		}

		getline(fin, line);
		istringstream inFlag(line);
		inFlag >> tmpx;

		if (tmpx == -1)//X's turn
		{
			isO = true;//Player X's turn, before each turn, change it
		}

		if (tmpx == -2)//O's turn
		{
			isO = false;//Player O's turn, before each turn, change it
		}


		getline(fin, save_O_move);
		istringstream inSaveO(save_O_move);

		while (inSaveO >> tmpx >> tmpy)
		{

			board[tmpy][tmpx] = O;
		}

		getline(fin, Xmove);
		getline(fin, Omove);

	}
	fin.close();
	return;

}