/*
This is the GameBase.cpp file
Author: Wei Fan
Email: weifan@wustl.edu
*/

#include "stdafx.h"
#include "GameBase.h"
#include "TicTacToeGame.h"
#include "GomokuGame.h"
#include "SudokuGame.h"
#include "UltimateTicTacToeGame.h"

shared_ptr<GameBase> GameBase::game_p = nullptr;//initialize



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
				cout << endl << "Do you want to save the game?" << endl;
				cout << "input Y for YES or N for NO" << endl;
				string respond;
				while (true)
				{
					cin >> respond;
					if (respond == "Y" || respond == "N"){//valid input
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
					fout<< "0";
				}
				else//save
				{

					fout << gamesName << endl;
					fout << turns << endl;//current turns
					fout << save_X_move << endl;//X's move
					if (!isO)
					{
						fout << "-1" << endl;//X's turn
					}
					else
					{
						fout << "-2" << endl;//O's turn
					}

					fout << save_O_move << endl;//O's move


					fout << Xmove << endl;
					fout << Omove << endl;


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
		catch (...)// a player quit the game or open file fail
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




			//reset the gameboard after a player wins
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

}


shared_ptr<GameBase> GameBase::instance()//check nullptr
{

	if (game_p != nullptr)
	{
		return game_p;
	}

	else
	{
		throw is_null_ptr;
	}

}


void GameBase::argCheck(int argc, char * argv[])
{
	
	if (game_p != nullptr)
	{
		throw not_null_ptr;
	}
	else
	{
		string gameName;
		string message;

		if (argc < 2)// no game name
		{
			message = "Please input the game's name after ";
			usage_message(argv[program_name], message);

			throw argument_error;//only one argument
		}

		gameName = argv[game_name];
		toLowercase(gameName);

		if (gameName == "tictactoe")
		{
			if (argc > 2)
			{
				message = "Please do not  input other things other than TicTacToe after ";
				usage_message(argv[program_name], message);
				throw argument_error;
				return;
			}
			game_p = make_shared<TicTacToeGame>();
			return;
		}

		if (gameName == "gomoku")
		{
			
			if (argc > 2)
			{
				message = "Please do not  input other things other than Gomoku after ";
				usage_message(argv[program_name], message);
				throw argument_error;
				return;
			}
			game_p = make_shared<GomokuGame>();
			return;
		}

		if (gameName == "sudoku")
		{

			if (argc > 2)
			{
				message = "Please do not  input other things other than sudoku after ";
				usage_message(argv[program_name], message);
				throw argument_error;
				return;
			}

			game_p = make_shared<SudokuGame>();
			return;

		}

		if (gameName == "ultimatetictactoe")
		{

			if (argc > 2)
			{
				message = "Please do not  input other things other than ultimatetictactoe after ";
				usage_message(argv[program_name], message);
				throw argument_error;
				return;
			}

			game_p = make_shared<UltimateTicTacToeGame>(UltimateTicTacToeGame());
			return;

		}


		else
		{
			message = "Please input a correct game's name after ";
			usage_message(argv[program_name], message);
			throw game_name_error;
			return;

		}
	}	
	
}