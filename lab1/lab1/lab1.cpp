// lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "lab1.h"


int main(int argc, char* argv[])
{
	if (argc != total_args){
		usage_message(argv[program_name],"Wrong Number of Argument for ");
		return argument_error;
	}
	

	ifstream fin;

	fin.open(argv[file_name]);

	if (!fin.is_open()){
		cout << "Warning! File " << argv[file_name] << " cannot be opened" << endl;
		cout << "Please input accurate file name." << endl;
		return file_error;
	}

	unsigned int board_x;
	unsigned int board_y;

	bool read_dim_good = false;
		
	while (fin.good())
	{
		if (read_dim(fin, board_x, board_y) == dimensions_valid)
		{
			read_dim_good = true;
			break;
		}
	}

	if (!read_dim_good)
	{
		cout << "Error! Cannot read dimensions from input file!" << endl;
		return no_dim_exist;
	}

	else
	{
		vector<game_piece> PV;
		game_piece tmp_piece;
		tmp_piece.color = no_color;
		tmp_piece.name = "";
		tmp_piece.print_message = " ";

		for (unsigned int i = 0; i < board_x*board_y; i++)
		{
			PV.push_back(tmp_piece);
		}

		int state=read_pieces(fin, PV, board_x, board_y);

		if (state == piece_invalid)
		{
			cout << "Cannot read valid piece" << endl;
			return no_piece_exist;
		}
		else
		{
			return print_pieces(PV, board_x, board_y);
		}

	}
	

	fin.close();

	return success;
}



int usage_message(char* p_name, string message){

	cout << message << p_name << endl;
	cout << "Please only input " << total_args - 1 << " parameter(s) other than program's name!" << endl;

	return argument_error;

}
