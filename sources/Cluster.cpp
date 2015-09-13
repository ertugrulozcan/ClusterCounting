#include "Cluster.h"

//
// Kurucu Fonksiyon
//
Cluster::Cluster(Color c)
{
	this->cellColor = c;
}


Cluster::~Cluster()
{
}

Color Cluster::getColor()
{
	return this->cellColor;
}