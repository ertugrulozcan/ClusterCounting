#include "ClusterPanel.h"
#include <Cluster.h>
#include <Colors.h>

#include <iostream>
using namespace std;

//
// Kurucu Fonksiyon
//
ClusterPanel::ClusterPanel()
{
	this->createTable();
}


ClusterPanel::~ClusterPanel()
{
}

//
// Ornek bir tablo olusturur
// NOT : Tabloya soruda verilen ornek islenmistir.
//
void ClusterPanel::createTable()
{
	for (int i = 0; i < arraysize(this->cells); i++)
		for (int j = 0; j < arraysize(this->cells[0]); j++)
			this->cells[i][j].color = EMPTY;

	this->cells[2][2].color = RED;
	this->cells[3][2].color = RED;
	this->cells[3][1].color = RED;

	this->cells[12][2].color = RED;
	this->cells[13][3].color = RED;
	this->cells[13][4].color = RED;

	this->cells[14][11].color = RED;

	this->cells[2][9].color = GREEN;
	this->cells[3][8].color = GREEN;
	this->cells[4][8].color = GREEN;
	this->cells[3][7].color = GREEN;
	this->cells[3][9].color = GREEN;

	this->cells[7][16].color = GREEN;
	this->cells[6][15].color = GREEN;
	this->cells[7][15].color = GREEN;

	this->cells[1][12].color = BLUE;
	this->cells[1][13].color = BLUE;
	this->cells[2][12].color = BLUE;
	this->cells[2][13].color = BLUE;

	this->cells[9][7].color = BLUE;
	this->cells[9][8].color = BLUE;
	this->cells[9][9].color = BLUE;
	this->cells[10][7].color = BLUE;
	this->cells[10][8].color = BLUE;

	this->cells[5][15].color = ORANGE;
	this->cells[5][14].color = ORANGE;
	this->cells[5][13].color = ORANGE;
	this->cells[6][14].color = ORANGE;
	this->cells[6][13].color = ORANGE;
	this->cells[7][14].color = ORANGE;
}

//
// Kume sayim islemini yapar
// Tespit ettigi kumeleri clusterList'e ekler.
//
void ClusterPanel::clusterCounting()
{
	for (int i = 0; i < arraysize(this->cells); i++)
	{
		for (int j = 0; j < arraysize(this->cells[0]); j++)
		{
			if (this->cells[i][j].isVisited || this->cells[i][j].color == EMPTY)
				continue;

			this->cells[i][j].isVisited = true;
			Cluster* cluster = new Cluster(this->cells[i][j].color);
			cluster->cellList.push_back(&this->cells[i][j]);
			this->clusterList.push_back(cluster);
			this->scanAround(i, j, cluster);
		}
	}
}

//
// clusterCounting fonksiyonu icerisinde kullanilir.
// Her bir hucrenin etrafindaki hucreleri kontrol ederek aynni kumeye ait hucreleri gruplandirir.
// Rekursif olarak dallanir.
//
void ClusterPanel::scanAround(int i, int j, Cluster* cluster)
{
	// Üst
	if (i - 1 >= 0 && !this->cells[i - 1][j].isVisited)
	{
		// Eðer ayný renkte ise;
		if (this->cells[i][j].color == this->cells[i - 1][j].color)
		{
			this->cells[i - 1][j].isVisited = true;
			cluster->cellList.push_back(&this->cells[i - 1][j]);
			this->scanAround(i - 1, j, cluster);
		}
	}

	// Alt
	if (i + 1 < arraysize(this->cells) && !this->cells[i + 1][j].isVisited)
	{
		// Eðer ayný renkte ise;
		if (this->cells[i][j].color == this->cells[i + 1][j].color)
		{
			this->cells[i + 1][j].isVisited = true;
			cluster->cellList.push_back(&this->cells[i + 1][j]);
			this->scanAround(i + 1, j, cluster);
		}
	}

	// Sol
	if (j - 1 >= 0 && !this->cells[i][j - 1].isVisited)
	{
		// Eðer ayný renkte ise;
		if (this->cells[i][j].color == this->cells[i][j - 1].color)
		{
			this->cells[i][j - 1].isVisited = true;
			cluster->cellList.push_back(&this->cells[i][j - 1]);
			this->scanAround(i, j - 1, cluster);
		}
	}

	// Alt
	if (j + 1 < arraysize(this->cells[0]) && !this->cells[i][j + 1].isVisited)
	{
		// Eðer ayný renkte ise;
		if (this->cells[i][j].color == this->cells[i][j + 1].color)
		{
			this->cells[i][j + 1].isVisited = true;
			cluster->cellList.push_back(&this->cells[i][j + 1]);
			this->scanAround(i, j + 1, cluster);
		}
	}
}

//
// Sonuc string'ini uretir.
//
string ClusterPanel::getResults()
{
	int count = this->clusterList.size();
	for (int i = 0; i < count; i++)
	{
		Cluster* c = this->clusterList[i];
		bool isCounted = false;

		int resultListLength = this->resultList.size();
		for (int j = 0; j < resultListLength; j++)
		{
			ResultPair* rp = this->resultList[j];

			if (rp->color == c->getColor())
			{
				rp->count++;
				isCounted = true;
			}
		}

		if (!isCounted)
			this->resultList.push_back(new ResultPair(c->getColor()));
	}

	string result("");
	result += to_string(this->resultList.size()) + " color group(s) detected:\r\n";
	int resultListLength = this->resultList.size();
	for (int k = 0; k < resultListLength; k++)
	{
		ResultPair* rp = this->resultList[k];
		result += rp->colorStr;
		result += " -> ";
		result += to_string(rp->count);
		result += "\r\n";
	}
	
	return result;
}

string colorToString(Color c)
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
	case EMPTY:	return "EMPTY";
	}

	return "UNKNOWN COLOR";
}

//
// Tabloyu ekrana cizer.
//
void ClusterPanel::drawTable()
{
	for (int i = 0; i < arraysize(this->cells); i++)
	{
		for (int j = 0; j < arraysize(this->cells[0]); j++)
		{
			if (this->cells[i][j].color != NULL)
				cout << colorToString(this->cells[i][j].color)[0];
			else
				cout << "#";
		}

		cout << endl;
	}
}