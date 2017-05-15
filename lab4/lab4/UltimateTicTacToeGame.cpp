/*
This is the UltimateTicTacToeGame.cpp file
Author: Wei Fan
Email: weifan@wustl.edu
*/

#include "stdafx.h"
#include "UltimateTicTacToeGame.h"


void UltimateTicTacToeGame::constructBoard_ultimateTictactoe(int width, int height)
{
	turns = 0;
	board.resize(board_height);
	for (int i = 0; i < board_height; i++)
	{
		board[i].resize(board_width);
	}



	big_board.resize(board_height / 3);
	for (int i = 0; i < board_height / 3; i++)
	{
		big_board[i].resize(board_width / 3);
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

	fin >> saved_filename;
	if (saved_filename != gamesName)
	{
		throw not_valid_file;
	}
	fin >> turns;
	if (turns == 0)//no saved game
	{
		isO = true;//Player X goes first, before each turn, change it
	}
	else
	{
		int tmp;
		fin >> tmp;
		if (tmp == -1)//X's turn
		{
			isO = true;// before each turn, change it
		}
		else if (tmp == -2)//O's turn
		{
			isO = false;//before each turn, change it
		}
		else
		{
			throw not_valid_file;
		}

		fin >> prev_x >> prev_y;

		for (int i = 0; i < board_height; i++)
		{
			for (int j = 0; j < board_width; j++)
			{
				fin >> tmp;
				switch (tmp)
				{
				case 0:
					board[i][j] = E;
					break;
				case 1:
					board[i][j] = X;
					break;
				case 2:
					board[i][j] = O;
					break;
				}
			}
		}


		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				fin >> tmp;
				switch (tmp)
				{
				case 0:
					big_board[i][j] = not_end;
					break;
				case 1:
					big_board[i][j] = X_wins;
					break;
				case 2:
					big_board[i][j] = O_wins;
					break;
				case 3:
					big_board[i][j] = tie;
					break;
				}			
			}
		}
	}
	fin.close();
	return;
}

ostream &operator << (ostream & os, const UltimateTicTacToeGame& game)
{
	int big_board_index;//indicate big board index
	os << '\n';
	for (int i = game.board_height - 1; i >= 0; i--)
	{
		
		big_board_index = i / 3;
		os << big_board_index;
		os << "|";
		os << i%3 << "||";
		for (int j = 0; j < game.board_width; j++)
		{
			os << tictactoe_toString(game.board[i][j]) << "|";
			

			if (j % 3 == 2)
			{
				os << "|";
			}

		}
		os << '\n';
		if (i % 3 != 0)
		{
			os << "-|-||-|-|-||-|-|-||-|-|-||";
		}
		else
		{
			os << "=|=||=|=|=||=|=|=||=|=|=||";
		}
		os << '\n';
	}
	os << "  #" << "||";

	for (int i = 0; i < game.board_width; i++)
	{
		os << i % 3 << "|";
		if (i % 3 == 2)
		{
			os << "|";
		}
	}
	os << '\n';
	os << "   ||-|-|-||-|-|-||-|-|-||";
	os << '\n';
	os << "   ||";
	for (int i = 0; i < game.board_width; i++)
	{
		big_board_index = i / 3;
		os << big_board_index << "|";
		if (i % 3 == 2)
		{
			os << "|";
		}
	}


	return os;
}

void UltimateTicTacToeGame::print()
{
	cout << *this << endl;
}

int UltimateTicTacToeGame::big_board_done(int x, int y)
{
	int square_x = x * 3;
	int square_y = y * 3;
	for (int i = square_y; i < square_y+3; i++)//3-Xs in a horizontal line
	{
		if (board[i][square_x] == board[i][square_x + 1] && board[i][square_x + 1] == board[i][square_x + 2] && board[i][square_x + 2] == X)
		{
			big_board[y][x] = X_wins;
			cout << "X wins in board ("<<x<<", "<<y<<")"<<endl;
			return 1;
		}
	}

	for (int i = square_y; i < square_y + 3; i++)//3-Os in a horizontal line
	{
		if (board[i][square_x] == board[i][square_x + 1] && board[i][square_x + 1] == board[i][square_x + 2] && board[i][square_x + 2] == O)
		{
			big_board[y][x] = O_wins;
			cout << "O wins in board (" << x << ", " << y << ")" << endl;
			return 2;
		}
	}

	for (int i = square_x; i < square_x + 3; i++)//3-X in a vertical line
	{
		if (board[square_y][i] == board[square_y + 1][i] && board[square_y + 1][i] == board[square_y + 2][i] && board[square_y + 2][i] == X)
		{
			big_board[y][x] = X_wins;
			cout << "X wins in board (" << x << ", " << y << ")" << endl;
			return 1;
		}
	}

	for (int i = square_x; i < square_x + 3; i++)//3-O in a vertical line
	{
		if (board[square_y][i] == board[square_y + 1][i] && board[square_y + 1][i] == board[square_y + 2][i] && board[square_y + 2][i] == O)
		{
			big_board[y][x] = O_wins;
			cout << "O wins in board (" << x << ", " << y << ")" << endl;
			return 2;
		}
	}

	if ((board[square_y][square_x] == board[square_y + 1][square_x + 1] && board[square_y + 1][square_x + 1] == board[square_y + 2][square_x + 2] && board[square_y + 2][square_x + 2] == X) || (board[square_y][square_x + 2] == board[square_y + 1][square_x + 1] && board[square_y + 1][square_x + 1] == board[square_y + 2][square_x] && board[square_y + 2][square_x] == X))//3-Xs in a diagnoal line
	{
		big_board[y][x] = X_wins;
		cout << "X wins in board (" << x << ", " << y << ")" << endl;
		return 1;
	}

	if ((board[square_y][square_x] == board[square_y + 1][square_x + 1] && board[square_y + 1][square_x + 1] == board[square_y + 2][square_x + 2] && board[square_y + 2][square_x + 2] == O) || (board[square_y][square_x + 2] == board[square_y + 1][square_x + 1] && board[square_y + 1][square_x + 1] == board[square_y + 2][square_x] && board[square_y + 2][square_x] == O))//3-Xs in a diagnoal line
	{
		big_board[y][x] = O_wins;
		cout << "O wins in board (" << x << ", " << y << ")" << endl;
		return 2;
	}
	return 0;

}


bool UltimateTicTacToeGame::done()
{
	for (int i = 0; i < 3; i++)//3 big board in a horizontal line
	{
		if (big_board[i][0] == big_board[i][1] && big_board[i][1] == big_board[i][2] && (big_board[i][2] == X_wins || big_board[i][2] == O_wins))
		{
			return true;
		}
	}


	for (int i = 0; i < 3; i++)//3-Xs or Os in a vertical line
	{
		if (big_board[0][i] == big_board[1][i] && big_board[1][i] == big_board[2][i] && (big_board[2][i] == X_wins || big_board[2][i] == O_wins))
		{
			return true;
		}
	}

	if ((big_board[0][0] == big_board[1][1] && big_board[1][1] == big_board[2][2] && (big_board[2][2] == X_wins || big_board[2][2] == O_wins)) || (big_board[0][2] == big_board[1][1] && big_board[1][1] == big_board[2][0] && (big_board[2][0] == X_wins || big_board[2][0] == O_wins)))//3-Xs or Os in a diagnoal line
	{
		return true;
	}

	return false;

}

bool UltimateTicTacToeGame::stalemate()
{
	if (done())
	{
		return false;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (big_board[i][j] == not_end)
			{
				return false;
			}
		}
	}

	return true;//game end with a draw

}

void UltimateTicTacToeGame::prompt(int& x, int& y, string message)
{
	string s1, s2;
	while (true)
	{
		cout << message << endl;
		string s = "";
		getline(cin, s);
		
		
		try
		{
			if (s == "quit")
			{
				cout << endl << "Do you want to save the game?" << endl;
				cout << "input Y for YES or N for NO" << endl;
				string respond;
				while (true)
				{
					cin >> respond;
					if (respond == "Y" || respond == "N"){
						break;
					}
					else{
						cout << "Wrong response, please input again [Y/N]" << endl;
					}
				}


				ofstream fout;
				string fileName = gamesName;

				fout.open(fileName);
				
				if (!fout.is_open())
				{
					throw fail_open_file;
				}
				
				if (respond == "N")//not save
				{
					fout << gamesName << endl;
					fout << "0";
				}
				else//save
				{
					fout << gamesName << endl;
					fout << turns << endl;//current turns
					if (!isO)
					{
						fout << "-1" << endl;//X's turn
					}
					else
					{
						fout << "-2" << endl;//O's turn
					}
					fout << prev_x << " " << prev_y << endl;

					for (int i = 0; i < board_height; i++)
					{
						for (int j = 0; j < board_width; j++)
						{
							fout << " " << board[i][j];
						}
						fout << endl;
					}


					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							fout << " " << big_board[i][j];
						}
						fout << endl;
					}

					fout.close();
				}
			
				
				int q = aPlayerQuits;
				throw q;
			}
		}

		catch (...)
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
		tmp_save_move = s;
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

		if (x<0 || x>2 || y<0 || y>2)
		{
			cout << "out of range!" << endl;
			continue;
		}
		else
		{
			break;
		}
	}
}


bool UltimateTicTacToeGame::turn()
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

	while (true)
	{
		cout << "Player " << tictactoe_toString(current_piece) << "'s turn: " << endl;
		if (prev_x == -1 || big_board[prev_y][prev_x] != not_end)//choose big board first
		{
			string message1 = "Please choose which board you want to put your piece. Input valid coordinate of board as a comma-separated pair of unsigned decimal integers. Or input \"quit\" to quit the game.";
			try
			{
				prompt(x, y, message1);
			}
			catch (...)// a player quit the game or open file fail
			{
				throw;
			}

			if (big_board[y][x] != not_end)
			{
				cout << "You can not put your piece on a board that is already done!" << endl;
				continue;
			}

			int _x, _y;//for small board
			
			string message2 = "Please input the coordinates of the piece you want to put in the board you chose as a comma-separated pair of unsigned decimal integers. Or input \"quit\" to quit the game.";

			try
			{
				prompt(_x, _y, message2);
			}
			catch (...)// a player quit the game or open file fail
			{
				throw;
			}

			if (board[y * 3 + _y][x * 3 + _x] != E)//coordinates occupied, should call prompt function again
			{
				cout << "The coordinates you entered is occupied!" << endl;
				continue;
			}

			else
			{
				board[y * 3 + _y][x * 3 + _x] = current_piece;
				big_board_done(x, y);
				prev_x = _x;
				prev_y = _y;
				break;
			}

		}

		else
		{
			cout << "Now, you have to put your piece in the (" << prev_x << "," << prev_y << ") board." << endl;
			string message3 = "Please input the coordinates of the piece you want to put in the board as a comma-separated pair of unsigned decimal integers. Or input \"quit\" to quit the game.";
			try
			{
				prompt(x, y, message3);
			}
			catch (...)// a player quit the game or open file fail
			{
				throw;
			}

			if (board[prev_y * 3 + y][prev_x * 3 + x] != E)//coordinates occupied, should call prompt function again
			{
				cout << "The coordinates you entered is occupied!" << endl;
				continue;
			}

			else
			{
				board[prev_y * 3 + y][prev_x * 3 + x] = current_piece;
				big_board_done(prev_x, prev_y);
				prev_x = x;
				prev_y = y;
				break;
			}
		}
	}

	print();
	cout << endl;
	turns++;

	return true;

}

int UltimateTicTacToeGame::play()
{
	print();//print the initial board
	while (true)
	{
		try
		{
			turn();
		}
		catch (...)// a player quit the game
		{
			throw;
		}

		if (stalemate())//game end in draw
		{
			cout << "Draw! No valid move available!" << endl;
			cout << turns << "turns were played" << endl;
			//reset the gameboard after game ends
			ofstream fout;
			string fileName = gamesName;

			fout.open(fileName);

			if (!fout.is_open())
			{
				throw fail_open_file;
			}


			fout << gamesName << endl;
			fout << "0";
			fout.close();
			return drawGame;
		}

		if (done())
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

			//reset the gameboard after game ends
			ofstream fout;
			string fileName = gamesName;

			fout.open(fileName);

			if (!fout.is_open())
			{
				throw fail_open_file;
			}


			fout << gamesName << endl;
			fout << "0";
			fout.close();

			return aPlayerWins;
		}
	}

	return 0;
}