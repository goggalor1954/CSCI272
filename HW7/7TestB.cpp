//James Roesemann
//Homework#7 testB


#include <iostream>
#include <fstream>
#include <cstdlib>
#include "building.h"
using namespace std;

int main()
{
	ifstream infile ("west.dat", ios::in | ios::binary);
	building east;
	infile.read( reinterpret_cast<char*>(&east), sizeof(building));

	std::cout << "TEST: " << east.getOffice()[3] << endl;
	std::cout << "TEST 2d: " << east.getChurchAt(0,1) << endl;
	std::cout << "TEST STRING: " << east.getStore() << endl;
	std::cout << "Test string array: " << east.getTowerAt(0,2) <<endl;

	return 0;
}

//ok. figured out how to approach this. 
//step one. convetre all string objects to arrays of characters.
// output to random access
//create a second program to use this output.
//or it would be faster if i could just figure out how to iterate through the characters of a string and read those
//not sure if that wiil work,
//fuck. asignment says i need to use an array of characters. well theres time wsted.

//ok so that i can change a little as possible. 
//wite a function that creates an array of characters from a string. 
//create on that returns a string from an array of characters.
// change the string values in the class to an array of characters 