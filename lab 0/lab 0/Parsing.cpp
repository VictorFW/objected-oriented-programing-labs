/*
This is the definition for Parsing function
Author: Wei Fan
Email: weifan@wustl.edu
*/

#include "stdafx.h"
#include "lab 0.h"


int Parsing(vector<string> &S, char* f_name){

	ifstream fin;

	fin.open(f_name);
	if (!fin.is_open()){
		cout << "Warning! File " << f_name << " cannot be opened" << endl;
		cout << "Please input accurate file name." << endl;
		return file_error;
	}

	else{
		string temp_string;
		while (fin.good()){
			fin >> temp_string;
			S.push_back(temp_string);
		}

		fin.close();

		cout << "Parsing is completed." << endl;
		return success;
	}
}