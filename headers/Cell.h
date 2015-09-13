#pragma once

#include <Colors.h>

class Cell
{
public:
	Cell();
	~Cell();
	Color color;
	void setColor(Color);
	bool isVisited;
};

