/*
This is the definition for digit_print function
Author: Wei Fan
Email: weifan@wustl.edu
*/

#include "stdafx.h"
#include "lab 0.h"


int digit_print(vector<string> &_S){
	vector<int> digit;
	int size = _S.size();
	if (size == 0){
		cout << "invalid string input" << endl;
		return string_error;
	}

	for (int i = 0; i < size; i++){
		char *c = const_cast<char*>(_S[i].c_str());
		int len = strlen(c);
		bool flag = true;
		for (int j = 0; j < len; j++){
			if (!isdigit(c[j]))
				flag = false;
		}

		if (flag == false){
			cout << c << endl;
		}
		else{//contains only digits
			istringstream input;
			input.str(c);
			int tmp;
			input >> tmp;
			digit.push_back(tmp);

		}
	}

	for (int k = 0; k < digit.size(); k++){
		cout << digit[k] << endl;
	}

	return success;

}