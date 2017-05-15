#include "stdafx.h"
#include "board.h"

bool not_valid_dim(const string s)
{
	int a = -1, b = -1;
	istringstream iss(s);
	iss >> a >> b;
	return (a == -1 || b == -1);
}


int read_dim(ifstream &fin, unsigned int&x, unsigned int &y)
{

	string s;
	getline(fin, s);
	if (not_valid_dim(s))
	{
		return dimensions_invalid;
	}

	istringstream iss(s);
	iss >> x >> y;

	return dimensions_valid;
}

int read_pieces(ifstream &fin, vector<game_piece> &v, unsigned int width, unsigned int height)
{
	string s;
	bool valid_piece_exis = false;
	while (getline(fin, s))
	{

		string colorByString;
		string pieceName;
		string pieceDisplay;
		unsigned int x;
		unsigned int y;

		istringstream iss(s);

		iss >> colorByString;
		iss >> pieceName;
		iss >> pieceDisplay;
		iss >> x;
		iss >> y;

		piece_color tmpColor = getColor(colorByString);
		if (x >= width || y >= height || tmpColor == invalid || tmpColor == no_color || pieceName.size() == 0 || pieceDisplay == " ")//skip invalid line
		{
			continue;
		}

		else
		{
			valid_piece_exis = true;
		}

		int index = width*y + x;

		v[index].color = tmpColor;
		v[index].name = pieceName;
		v[index].print_message = pieceDisplay;
	}

	if (valid_piece_exis)
	{
		return piece_valid;
	}

	else
	{
		return piece_invalid;
	}
}

int print_pieces(const vector<game_piece> &v, unsigned int x, unsigned int y)
{

	for (int j = y - 1; j >= 0; j--)
	{
		for (unsigned int i = 0; i < y; i++)
		{
			cout << v[x*j + i].print_message;
		}
		cout << endl;
	}

	return success;
	
}
