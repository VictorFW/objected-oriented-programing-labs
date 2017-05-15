/*
This is the lab3.h file
Author: Wei Fan
Email: weifan@wustl.edu
*/

#ifndef LAB3_H
#define LAB3_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <iomanip>

using namespace std;

enum arguments{//enum for input arguments in command line
	program_name,
	game_name,
	board_size,//input with board size
	conn_number//input with board size and number of connecting pieces to win
};

enum result
{
	aPlayerWins,//game ends in one player wins
	drawGame,//game ends in draw
	aPlayerQuits,//game ends in one player quit
	argument_error,//error in argument's number
	game_name_error,//error input in game's name
	bad_main//error in main
};


enum pieces{ E, X, O };//enum in pieces' type, E for empty



int usage_message(char* p_name, string message);// to print out error input message
int toLowercase(string &s);
bool is_digit(string str);


#endif