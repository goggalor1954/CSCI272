//James Roesemann
// hw 7 test PartA

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "building.h"
using namespace std;
	//recursivly creating a strinf

	string stringBuilder(char x[], int y)
	{
		if (x[y]=='\0') return string();
		return string(1, x[y])+stringBuilder(x, y+1);
	}

	char* stringDestructor(string input, char output[])
	//remeber that ou need to pass it a new array of size input +1 
	{
		//char output[input.size()+1];
		for(int i=0; i<input.size(); i++)
		{
			output[i]=input.at(i);
		}
		output[input.size()]='\0';
		return output;
	}

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


	string north="potato :";
	char south[north.size()+1];
	for(int i=0; i< north.size(); i++)
	{
		south[i]=north.at(i);
		//std::cout << north.at(i) << " " << i << endl;
	}
	std::cout << north.size() << endl;
	south[north.size()]='\0';

	/*for(int i=0; i < north.size()+1; i++)
	{
		//did this to make sure \0 was notthe same as a a space character.
		std::cout << int(south[i]) << endl;
	}*/
	std::cout << stringBuilder(south, 0)<< stringBuilder(south, 0).size() << endl;

	string muf="muffins";
	char* test=stringDestructor(muf, new char[muf.size()]);
	std::cout << stringBuilder( test, 0)<< endl;


	return 0;
}