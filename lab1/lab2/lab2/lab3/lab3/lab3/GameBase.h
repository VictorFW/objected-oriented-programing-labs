/*
This is the GameBase.h file
Author: Wei Fan
Email: weifan@wustl.edu
*/

#ifndef GAMEBASE_H
#define GAMEBASE_H

#include"lab3.h"

class GameBase
{
protected:
	int longest_piece_length;	//longest display string length
	int board_width;
	int board_height;
	bool isO;//true if current player is O
	string Omove = "";//store player O's move
	string Xmove = "";//store player X's move
	string tmpMove = "";//store current move
	vector<vector <pieces>> board;
	int turns;//count turns

	void constructBoard(int width, int height);



public:
	GameBase()//constructor
	{
		board_width = 3;
		board_height = 3;
		longest_piece_length = 1;
		constructBoard(board_height, board_width);
	}

	static	GameBase * argCheck(int, char **);

	virtual void	print() = 0;		//print the game board
	virtual bool	done() = 0;			//Determine if game is over
	virtual bool	stalemate() = 0;	//Determine if game ends with a tie
	virtual bool	turn() = 0;			//play round

	virtual bool prompt(int&x, int& y);//return true if continue game; 
	virtual int play();

};


#endif