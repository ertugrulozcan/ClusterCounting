#pragma once

#include <Cell.h>
#include <Cluster.h>
#include <ResultPair.h>
#include <string>
using namespace std;

// Dizi boyutunu ogrenmek icin
template <typename T, unsigned S>
inline unsigned arraysize(const T(&v)[S]) { return S; }

class ClusterPanel
{
public:
	ClusterPanel();
	~ClusterPanel();

	Cell cells[17][17];
	void createTable();
	void clusterCounting();
	string getResults();
	void drawTable();

private:
	vector<Cluster*> clusterList;
	vector<ResultPair*> resultList;
	void scanAround(int, int, Cluster*);
};

