/*
This is the head file for lab 1
Author: Wei Fan
Email: weifan@wustl.edu
*/


#ifndef LAB1_H
#define LAB1_H

#include "board.h"

using namespace std;

enum  arguments{
	program_name,
	file_name,
	total_args
};

int usage_message(char* p_name, string message);

#endif