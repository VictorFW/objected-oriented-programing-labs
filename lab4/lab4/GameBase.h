/*
This is the GameBase.h file
Author: Wei Fan
Email: weifan@wustl.edu
*/

#ifndef GAMEBASE_H
#define GAMEBASE_H
#include"lab4.h"

class GameBase
{
protected:
	int longest_piece_length;	//longest display string length
	int board_width;
	int board_height;
	bool isO;//true if current player is O
	string Omove = "";//store player O's move to print
	string Xmove = "";//store player X's move to print
	string tmpMove = "";//store current move
	vector<vector <pieces>> board;//store game board
	int turns;//count turns

	static shared_ptr<GameBase> game_p;

	string gamesName;//store game's name
	string save_X_move="";//to save the game state in file
	string save_O_move="";//to save the game state in file
	string tmp_save_move = "";



public:
	GameBase()//constructor
	{
		gamesName = "tictactoe";
		board_width = 3;
		board_height = 3;
		longest_piece_length = 1;

	}

	static	void argCheck(int, char **);

	static shared_ptr<GameBase> instance();//check nullptr

	virtual void	print() = 0;		//print the game board
	virtual bool	done() = 0;			//Determine if game is over
	virtual bool	stalemate() = 0;	//Determine if game ends with a tie
	virtual bool	turn() = 0;			//play round

	virtual bool prompt(int&x, int& y);//return true if continue game; 
	virtual int play();

};


#endif