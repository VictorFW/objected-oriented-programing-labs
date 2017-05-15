#include "stdafx.h"
#include "pieces.h"

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

string toStringColor(piece_color c)
{
	switch (c)
	{
		case red:
			return "red";
		case black:
			return "black";
		case white:
			return "white";
		case invalid:
			return "invalid color";
		default:
			return "no color";
	}
}


piece_color getColor(string s)
{
	toLowercase(s);
	
	if (s == "red")
		return red;
	else if (s == "black")
		return black;
	else if (s == "white")
		return white;
	else if (s == "")
		return no_color;
	else
		return invalid;

}