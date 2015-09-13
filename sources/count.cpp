/*
	Onur Muhendislik YM-01 Teknik Mulakat Sorusu

	AHMET ERTUGRUL OZCAN
	ertugrul.ozcan@bil.omu.edu.tr
	2015
*/

#include <iostream>
#include <ClusterPanel.h>
#include <conio.h>
using namespace std;

int main(int ac, char** av)
{
	ClusterPanel* clusterPanel = new ClusterPanel();
	clusterPanel->clusterCounting();
	clusterPanel->drawTable();
	cout << endl << endl;
	cout << clusterPanel->getResults();

	getchar();
}