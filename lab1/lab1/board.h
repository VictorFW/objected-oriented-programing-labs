#ifndef BOARD_H
#define BOARD_H

#include "pieces.h"

enum dim_valid
{
	dimensions_valid,
	dimensions_invalid
};

enum p_valid
{
	piece_valid,
	piece_invalid
};

bool not_valid_dim(const string s);
int read_dim(ifstream &name, unsigned int &x, unsigned int &y);
int read_pieces(ifstream &name, vector<game_piece> &v, unsigned int x, unsigned int y);
int print_pieces(const vector<game_piece> &v, unsigned int x, unsigned int y);


#endif