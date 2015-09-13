#pragma once
#include <Colors.h>
#include <Cell.h>
#include <vector>
#include <string>
using namespace std;

class Cluster
{
public:
	Cluster(Color);
	~Cluster();
	Color getColor();
	vector<Cell*> cellList;

private:
	Color cellColor;
};

