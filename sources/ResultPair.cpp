#include "ResultPair.h"


ResultPair::ResultPair(Color c)
{
	this->count = 1;
	this->color = c;
	this->colorStr = colorToString(this->color);
}


ResultPair::~ResultPair()
{
}

//
// Renklerin string karsiligini doner
//
string ResultPair::colorToString(Color c)
{
	switch (c)
	{
		case RED:	return "Red";
		case GREEN:	return "Green";
		case BLUE:	return "Blue";
		case ORANGE:	return "Orange";
		case PINK:	return "Pink";
		case YELLOW:	return "Yellow";
		case WHITE:	return "White";
		case BLACK:	return "Black";
		case BROWN:	return "Brown";
		case CYAN:	return "Cyan";
		case MAGENTA:	return "Magenta";
		case PURPLE:	return "Purple";
		case GRAY:	return "Gray";
	}

	return "UNKNOWN COLOR";
}