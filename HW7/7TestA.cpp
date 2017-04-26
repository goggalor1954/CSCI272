//James Roesemann
// hw 7 test PartA

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "building.h"
using namespace std;

int main()
{
	building West;

	West.setHouse(5);
	West.setOffice(2,4,6,67,88);
	West.setChurch(32,42,62,2);
	West.setStore("Deli");
	West.setTower("She", "Sells", "sea", "shells", "by", "the", "sea", "shore", "!");

	ofstream outfile("west.dat", ios::out | ios::binary);
	outfile.write(reinterpret_cast<const char*>(&West), sizeof(building));


	return 0;
}