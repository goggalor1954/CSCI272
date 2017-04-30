#include <iostream>
#include <fstream>
#include <cstdlib>
#include "BuildingB.h"
using namespace std;

int main()
{
	BuildingB north;
	north.setChar1('g');
	north.setCharArr('q','w','e');
	north.setInt1(42);
	north.setIntArr(23, 45, 67);
	north.setString1("Sun");
	//north.setStringArr("red", "yellow", "green");
	north.setFloat1(12.3);
	//north.setFloatArr(56.3, 99.95, 12.4);
//testing
	//char kip[]={'m','u','d','k','i','p','\0'};
	//north.setCharArr2( kip);


	ofstream outfile("north.dat", ios::out | ios::binary);
	outfile.write(reinterpret_cast<const char*>(&north), sizeof(BuildingB));

	return 0;
}
