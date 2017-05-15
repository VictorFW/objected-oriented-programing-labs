/*
This is the UltimateTicTacToeGame.h file
Author: Wei Fan
Email: weifan@wustl.edu
*/


#ifndef SUDULTIMATETICTACTOEGAME_h
#define SUDULTIMATETICTACTOEGAME_h

#include "GameBase.h"
#include"TicTacToeGame.h"


enum big_squre//for a 3*3 square big board
{
	not_end,
	X_wins,
	O_wins,
	tie
};

class UltimateTicTacToeGame:public GameBase
{
private:
	void constructBoard_ultimateTictactoe(int width, int height);
	friend ostream &operator << (ostream &, const UltimateTicTacToeGame&);
	vector<vector<big_squre>> big_board;
	int big_board_done(int x,int y);//1 if X wins, 2 if O wins, 0 if otherwise
	int prev_x;
	int prev_y;



public:
	UltimateTicTacToeGame()
	{
		gamesName = "ultimatetictactoe";
		board_height = 9;
		board_width = 9;
		prev_x = -1;
		prev_y = -1;
		constructBoard_ultimateTictactoe(board_width, board_height);
	}

	void prompt(int&x, int&y, string message);

	virtual void print();//print the board
	virtual bool done();//true if a player wins
	virtual bool stalemate();
	virtual bool turn();
	virtual int play();





};




#endif