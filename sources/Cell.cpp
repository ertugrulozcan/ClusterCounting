#include "Cell.h"

//
// Kurucu Fonksiyon
//
Cell::Cell()
{
	this->isVisited = false;
}

Cell::~Cell()
{
}

void Cell::setColor(Color c)
{
	this->color = c;
}
