/*
This is the SudokuGame.cpp file
Author: Wei Fan
Email: weifan@wustl.edu
*/


#include "stdafx.h"
#include "SudokuGame.h"



ostream &operator << (ostream & os, const SudokuGame& game)//define how the TicTacToeGame class will print
{
	os << '\n';
	for (int i = game.board_height-1; i >= 0; i--)
	{
		os <<i<<"||";
		for (int j = 0; j < game.board_width; j++)
		{
			if (game.board[i][j] == 0)//empty
			{
				os << " " << "|";
			}
			else
			{
				os << game.board[i][j] << "|";
			}

			if (j % 3 == 2)
			{
				os << "|";
			}

		}
		os << '\n';
		if (i % 3 != 0)
		{
			os << "-||-|-|-||-|-|-||-|-|-||";
		}
		else
		{
			os << "=||=|=|=||=|=|=||=|=|=||";
		}
		os << '\n';
	}
	os << "#"<<"||";

	for (int i = 0; i < game.board_width; i++)
	{
		os << i<<"|";
		if (i % 3 == 2)
		{
			os << "|";
		}

	}
	return os;
}


void SudokuGame::constructBoard_sudoku(int width, int height)
{
	board.resize(board_height);
	original_board.resize(board_height);
	for (int i = 0; i < board_height; i++)
	{
		board[i].resize(board_width);
		original_board[i].resize(board_width);
	}
	ifstream fin;



	fin.open("sudoku0");

	int org_turns = 0;//orignial board numbers

	int tmpO;
	for (int i = 0; i < board_height; i++)
	{
		for (int j = 0; j < board_width; j++)
		{
			fin >> tmpO;
			if (tmpO != 0)
			{
				original_board[i][j] = true;
				org_turns++;
			}
		}
	}

	fin.close();


	string save_filename;

	string fileName = gamesName;
	fin.open(fileName);
	if (!fin.is_open())
	{
		throw fail_open_file;
	}

	fin >> save_filename;

	if (save_filename != gamesName)
	{
		throw not_valid_file;
	}
	
	fin >> turns;
	if (turns == 0)//no saved game
	{
		fin.close();

		fileName = "sudoku0";
		fin.open(fileName);
		
		if (!fin.is_open())
		{
			throw fail_open_file;
		}



		for (int i = 0; i < board_height; i++)
		{
			for (int j = 0; j < board_width; j++)
			{
				fin >> board[i][j];
			}
		}

		turns = org_turns;

	}

	else//has saved file
	{
		
		int tmpx, tmpy, tmpValue;
		for (int i = 0; i < turns; i++)
		{
			fin >> tmpx >> tmpy >> tmpValue;

			board[tmpy][tmpx] = tmpValue;
		}
	}

	fin.close();
}


void SudokuGame::print()
{
	cout << *this << endl;
}
bool SudokuGame::done()//return true if a player is win
{


	for (int i = 0; i < board_height; i++)
	{
		int sum1 = 0;
		int sum2 = 0;
		for (int j = 0; j < board_width; j++)
		{
			sum1 +=twoExp(board[i][j]);
			sum2 += twoExp(board[j][i]);
		}
		if ((sum1 != 1022) || (sum2!=1022))
		{
			return false;
		}
	}

	for (int i = 0; i < board_height; i += 3)
	{
		for (int j = 0; j < board_width; j += 3)
		{
			int sum = 0;
			for (int k = i; k < i + 3; k++)
			{
				for (int l = j; l < j + 3; l++)
				{
					sum += twoExp(board[l][k]);
				}
			}
			if (sum != 1022)
			{
				return false;
			}
		}
	}

	return true;


}

void SudokuGame::prompt(int& x, int& y, int& v)
{
	string s1, s2;
	while (true)
	{
		cout << "Please input valid coordinate you want to put digit in as a comma-separated pair of unsigned decimal integers. Or input \"quit\" to quit the game." << endl;
		string s = "";
		getline(cin, s);
		try
		{
			if (s == "quit")//player choose quit
			{
				cout << endl << "Do you want to save the game?" << endl;
				cout << "input Y for YES or N for NO" << endl;
				string respond;
				while (true){
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
				fout.open(fileName);//not deal with fail open

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
					fout << turns << endl;
					for (int i = 0; i < board_height; i++)
					{
						for (int j = 0; j < board_width; j++)
						{
							if (board[i][j] != 0)//has a value
							{
								fout << j << " " << i << " " << board[i][j] << endl;
							}
						}
					}

				}

				fout.close();


				int q = aPlayerQuits;
				throw q;
			}
		}
		catch (...)
		{
			throw;
		}





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

		if (x<0 || x>=board_width || y<0 || y>=board_height)
		{
			cout << "out of range!" << endl;
			continue;
		}

		if (original_board[y][x] == true)//initial game board
		{
			cout << "You can not change the digit on initial game board!" << endl;
			continue;//valid input, stop calling prompt function
		}


		string sv;//for saving value
		
		while (true)
		{
			cout << "Please input the digit you want put in the coordinate of (" << x << "," << y << ")" << endl;
			getline(cin, sv);	
			if ((sv.length() != 1) || (!isdigit(sv[0])))
			{
				cout << "Please input a number between 1 and 9" << endl;
				continue;
			}

			break;

		}

		char *c = const_cast<char*>(sv.c_str());
		v = c[0] - 48;//get the digit to input
		return;

	}



}

bool SudokuGame::stalemate()
{
	return false;
}

bool SudokuGame::turn()
{
	int x, y;
	int v;
	while (true)
	{
		try
		{
			prompt(x, y, v);
		}
		catch (...)//quit of fail open file
		{
			throw;
		}
	
		
		break;
		
	}


	if (board[y][x] == 0)
	{
		turns++;
	}
	board[y][x] = v;
	
	print();
	cout << endl;

	return true;
}
int SudokuGame::play()
{
	print();//print the initial board
	
	while (true)//players continue take moves
	{
		try
		{
			turn();
		}
		catch (...)// a player quit the game
		{
			throw;
		}

		if (done())//game ends;
		{
			cout << "You have done! awesome!" << endl;
			ofstream fout;
			fout.open("sudoku");
			if (!fout.is_open())
			{
				throw fail_open_file;
			}

			fout << gamesName << endl;
			fout << "0";
			fout.close();

			return aPlayerWins;
		}

		if (turns == 81 && !done())//some digits wrong
		{
			cout << "you might input somethings wrong, try to change some digits!" << endl;
			continue;
		}

	}
	
	
	return 0;
}