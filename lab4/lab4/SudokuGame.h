/*
This is the SudokuGame.h file
Author: Wei Fan
Email: weifan@wustl.edu
*/


#ifndef SUDUKUGAME_h
#define SUDUKUGAME_h

#include "GameBase.h"

class SudokuGame : public GameBase
{
private:
	void constructBoard_sudoku(int width, int height);
	vector<vector <int>> board;
	vector<vector<bool>> original_board;
	friend ostream &operator << (ostream &, const SudokuGame&);//declare the &operator << as frend function




public:
	SudokuGame()//constructor
	{
		board_width = 9;
		board_height = 9;
		longest_piece_length = 1;
		gamesName = "sudoku";
		constructBoard_sudoku(board_width, board_height);


	}



	virtual void print();
	virtual bool done();//return true if a player is win
	virtual bool stalemate();
	virtual bool turn();
	virtual int play();
	void prompt(int& x, int& y, int& v);

};



#endif