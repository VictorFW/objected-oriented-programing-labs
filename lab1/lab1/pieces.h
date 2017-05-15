#ifndef PIECES_H
#define PIECES_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

enum  result
{
	success,
	argument_error,//error in argument's number
	file_error,//error in file name
	no_dim_exist,//cannot read valid dimensions
	no_piece_exist//cannot read valid pieces
};

enum  piece_color 
{
	red,
	black,
	white,
	invalid,
	no_color
};

struct game_piece
{
	piece_color color;
	string name;
	string print_message;
};

string toStringColor (piece_color c);
piece_color getColor(string s);
int toLowercase(string &s);

#endif