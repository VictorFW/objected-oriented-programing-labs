/*
This is the TicTacToeGame.h file
Author: Wei Fan
Email: weifan@wustl.edu
*/


#ifndef TICTACTOEGAME_H
#define TICTACTOEGAME_H

#include "GameBase.h"

class TicTacToeGame :public GameBase
{
private:

	friend ostream &operator << (ostream &, const TicTacToeGame&);//declare the &operator << as frend function
	void constructBoard(int width, int height);


public:


	TicTacToeGame() :GameBase() //constructor
	{
		constructBoard(board_width, board_height);
	}


	virtual bool done();//return true if a player is win
	virtual bool stalemate();//return true if game end with a draw
	virtual bool turn();//return true if continue game;
	virtual void print();//print the board


};


string tictactoe_toString(pieces p);


#endif