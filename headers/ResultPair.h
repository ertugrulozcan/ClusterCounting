#pragma once

#include <Colors.h>
#include <string>
using namespace std;

//
// Tabloda kume sayimi yapilirken kullanilan yardimci sinif
//
class ResultPair
{
public:
	ResultPair(Color);
	~ResultPair();
	
	Color color;
	string colorStr;
	int count;

private:
	string colorToString(Color);
};

