/*
This is the head file for lab 0
Author: Wei Fan
Email: weifan@wustl.edu
*/

#ifndef LAB0_H
#define LAB0_H

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

enum  result{
	success,
	argument_error,//error in argument's number
	file_error,//error in file name
	string_error//invalid string input
};


int usage_message(char* p_name);
int Parsing(vector<string> &S, char* f_name);
int digit_print(vector<string> &S);


#endif