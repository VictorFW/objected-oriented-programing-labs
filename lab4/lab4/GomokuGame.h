/*
This is the GomokuGame.h file
Author: Wei Fan
Email: weifan@wustl.edu
*/


#ifndef GOMOKUGAME_H
#define GOMOKUGAME_H

#include "GameBase.h"


class GomokuGame : public GameBase
{
private:
	int connecting;//the number of connecting pieces to win
	friend ostream &operator << (ostream &, const GomokuGame&);//declare the &operator << as frend function
	void constructBoard(int width, int height);

public:
	GomokuGame()//constructor
	{
		gamesName = "gomoku";
		board_width = 19;
		board_height = 19;
		connecting = 5;
		longest_piece_length = 3;
		constructBoard(board_height, board_width);
		
	}




	virtual void print();
	virtual bool done();//return true if a player is win
	virtual bool stalemate();
	virtual bool turn();
	virtual int play();

};


#endif