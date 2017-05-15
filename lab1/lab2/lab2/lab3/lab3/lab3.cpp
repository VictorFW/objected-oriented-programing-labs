/*
This is the lab3.cpp file
Author: Wei Fan
Email: weifan@wustl.edu
*/

#include "stdafx.h"
#include "lab3.h"
#include "GameBase.h"
#include "TicTacToeGame.h"
#include "GomokuGame.h"
#include <memory>

//This function will be called when invalid number of arguments input in command line
int usage_message(char* p_name, string message){

	cout << message << p_name << endl;

	return argument_error;
}



int toLowercase(string &s)
{
	char *c = const_cast<char*>(s.c_str());
	int len = strlen(c);
	for (int i = 0; i<len; i++){
		if (c[i]>64 && c[i]<91){
			c[i] += 32;
		}
	}

	return 0;
}

bool is_digit(string s)
{

	if (!isdigit(s[0]))
	{
		return false;
	}

	for (size_t i = 1; i < s.length(); ++i)
	{
		if (!isdigit(s[i]))
		{
			return false;
		}
	}
	return true;
}



int main(int argc, char* argv[])
{

	try
	{
		shared_ptr<GameBase> game(GameBase::argCheck(argc, argv));

		if (game == nullptr)
		{
			return argument_error;
		}

		else
		{
			int return_value;
			try
			{
				return_value = game->play();
			}
			catch (int q)
			{
				cout << "A player force to quit the game" << endl;
				return q;
			}


			return return_value;
		}
	}

	catch (...)
	{
		return bad_main;
	}




}

