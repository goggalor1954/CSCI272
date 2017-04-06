//exam2 practice
//first i am going to create a .h file to be used with this file xxx
//i need to makes derived classes. xxx
//i need to make virtual classes. XXX
//multiple inheritance
//diamond multiple inheritance
//dynamic memory allocation
//linked list
//protected member and public inherit
//protected
//static members
//pointer basics
//whatever the fuck ios::app is
//file reading/direction
//sequential access vs random access
//know how many bits each basic types are
//know how to dynamically create and destroy arrays

#include <iostream>
#include <cstdlib>
#include "transport.h"
using namespace std;

int main()
{
//testing
	bike mtnBike;
	car sedan;
	mtnBike.setModel("Schwinn");
	mtnBike.setDriver("James");
	mtnBike.setCalories(76+44);
	sedan.setModel("Impalla");
	sedan.setDriver("Paul");
	sedan.setGasTank(12.45);
	sedan.setPrice(2.50);
	sedan.setMpg(25);
	std::cout << mtnBike.getDriver() << " rides a " << mtnBike.getModel() << " and burned " << mtnBike.getCalories() << " calories this morning." << endl;
	std::cout << "He burned " << mtnBike.costToCommute(3.5) << " calories per mile." << endl;
	std::cout << sedan.getDriver() << " drives a " << sedan.getModel() << " and has " << sedan.getGasTank() << " gallons of fule in his tank." <<endl;
	std::cout << "it cost him $" << sedan.costToCommute(3.5) << " to travel the same distance."  << endl;

	dimond pDimond;
	blueDimond bDimond;
	whiteDimond wDimond;
	yellowDimond yDimond;
	pDimond.setStatus("shattered");
	bDimond.setStatus("crying");
	wDimond.setStatus("hiding");
	std::cout << "pDimond: " <<pDimond.getStatus() <<"\nbDimond: " << bDimond.getStatus() << "\nwDimind: " <<wDimond.getStatus() <<endl;
	yDimond.setStatus("CLOD");//this will not work. mutiple inheritance
	std::cout << "yDimond: " <<yDimond.getStatus() << endl;
	 
	return 0;
}
