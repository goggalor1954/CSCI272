#include <iostream>
#include <fstream>
#include <cstdlib>
#include "BuildingB.h"
using namespace std;

int main()
{
	BuildingB south;
	ifstream infile ("north.dat", ios::in | ios::binary);
	infile.read( reinterpret_cast<char*>(&south), sizeof(BuildingB));


	std::cout <<"int: " << south.getInt1() << endl << "intArr ";
	for(int i=0; i < 3; i++)
	{
		std::cout << south.getIntArr()[i] << " : ";
	}
	std::cout << endl << "char1: " << south.getChar1() << endl << "charArr " ;
	for (int i=0; i< 3; i++)
	{
		std::cout << south.getCharArr()[i] << " : ";
	}
	std::cout <<endl << " string1: " << south.getString1() << endl;/* << "stringArr ";
	for(int i=0; i<3; i++)
	{
		std::cout << south.getStringArr()[i] << " : ";
	}*/
	std::cout << endl << "float1: " << south.getFloat1() << endl;/* << "floatArr ";
	for (int i=0; i<3; i++)
	{
		std::cout << south.getFloatArr()[i] << " : ";
	}*/
	//std::cout << "charArr2: " << south.stringBuilder(south.getCharArr2()) << endl;
	return 0;
}
//not sure wahts causing the segment fault. could be the stream not being closes. culd be something to do with the arrays. run this through a debugger at home.

//i think the problem is that you i can't pass a float as it is.
