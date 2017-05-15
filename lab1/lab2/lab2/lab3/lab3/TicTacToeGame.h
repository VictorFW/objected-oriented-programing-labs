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


public:


	TicTacToeGame() :GameBase() //constructor
	{}


	virtual bool done();//return true if a player is win
	virtual bool stalemate();//return true if game end with a draw
	virtual bool turn();//return true if continue game;
	virtual void print();//print the board


};


#endif