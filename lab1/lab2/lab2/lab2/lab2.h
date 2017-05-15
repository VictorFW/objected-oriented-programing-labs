/*
This is the lab2.h file
Author: Wei Fan
Email: weifan@wustl.edu
*/

#ifndef LAB2_H
#define LAB2_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

enum arguments{//enum for input arguments in command line
	program_name,
	game_name,
	total_args
};

enum result
{
	aPlayerWins,//game ends in one player wins
	drawGame,//game ends in draw
	aPlayerQuits,//game ends in one player quit
	argument_error,//error in argument's number
	game_name_error//error input in game's name

};


enum pieces{ E, X, O };//enum in pieces' type, E for empty

class TicTacToeGame
{
private:
	const int board_width = 3;
	const int board_height = 3;
	vector<vector <pieces>> board;
	bool isO;//true if current player is O
	string Omove = "";//store player O's move
	string Xmove = "";//store player X's move
	string tmpMove = "";//store current move
	int turns;//count turns


	void constructBoard(int width, int height);

public:

	
	TicTacToeGame(int width, int height) : board_height(height), board_width(width) //constructor
	{
		constructBoard(width, height);
	}


	bool done();//return true if a player is win
	bool draw();//return true if game end with a draw
	bool prompt(unsigned int&x, unsigned int& y);//return true if continue game; return false if quit
	bool turn();//return true if continue game; return false if quit
	int play();

	friend ostream &operator << (ostream &, const TicTacToeGame&);//declare the &operator << as frend function

};


#endif