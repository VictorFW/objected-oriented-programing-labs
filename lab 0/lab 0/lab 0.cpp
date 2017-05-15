// lab 0.cpp : Defines the entry point for the console application.
//

/*
This is the lab 0.cpp file
Author: Wei Fan
Email: weifan@wustl.edu
*/


#include "stdafx.h"
#include "lab 0.h"

int main(int argc, char* argv[])
{
	vector<string> S;// a string vector to store content of file

	if (argc != 2){
		usage_message(argv[0]);
		return argument_error;
	}

	else{
		Parsing(S, argv[1]);
	}

	return(digit_print(S));
}



