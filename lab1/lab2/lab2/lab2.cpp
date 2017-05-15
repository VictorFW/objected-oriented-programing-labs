// lab2.cpp : Defines the entry point for the console application.
//

/*
This is the lab2.cpp file
Author: Wei Fan
Email: weifan@wustl.edu
*/

#include "stdafx.h"
#include "lab2.h"

//This function will be called when invalid number of arguments input in command line
int usage_message(char* p_name, string message){

	cout << message << p_name << endl;
	cout << "Please input and only input " << total_args - 1 << " parameter(s) other than program's name, which should be the game's name." << endl;

	return argument_error;
}


int main(int argc, char* argv[])
{
	
	if (argc != total_args)//when the number of arguments input in command line is not right
	{
		return (usage_message(argv[program_name], "Wrong Number of Argument for "));
	}

	string gameName = argv[game_name];//use gameName to store the input gamename

	if (gameName != "TicTacToe")//the input game name is wrong
	{
		cout << "You entered a wrong game name!" << endl; 
		return game_name_error;
	}

	TicTacToeGame game = TicTacToeGame(3, 3);//create an object of the TicTacToe game calss

	return(game.play());//execute the play function and return the value
}

