//exam2 practice
//first i am going to create a .h file to be used with this file xxx
//i need to makes derived classes. xxx
//i need to make virtual classes. XXX
//multiple inheritance xxx
//diamond multiple inheritance xx
//dynamic memory allocation xxx
//linked list xxx
//protected member and public inherit
//protected xxx
//static members xx
//pointer basics xxx
//whatever the fuck ios::app is
//file reading/direction
//sequential access vs random access
//know how many bits each basic types are
//know how to dynamically create and destroy arrays
//friend classes

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "transport.h"
#include <fstream>
using namespace std;

int main()
{
//inheritance
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

	//diamond inheritance and virtual class/functions
	pinkDimond pDimond;
	blueDimond bDimond;
	whiteDimond wDimond;
	yellowDimond yDimond;
	pDimond.setStatus("shattered");
	bDimond.setStatus("crying");
	wDimond.setStatus("hiding");
	std::cout << "pDimond: " <<pDimond.getStatus() <<"\nbDimond: " << bDimond.getStatus() << "\nwDimind: " <<wDimond.getStatus() <<endl;
	yDimond.setStatus("CLOD");//this will not work. mutiple inheritance
	std::cout << "yDimond: " <<yDimond.getStatus() << endl;
	 
	 //linked list
	 NodeA a1, a2;
	 a1.setHead(23);
	 a2.setHead(45);
	 a1.setNext(&a2);
	 std::cout << "a1 head: " << a1.getHead() <<"\na2 Head: " << (a1.getNext()).getHead() <<endl;
	 
	 //dynamic allocation
	 int *dynamic;
	 dynamic = new int[6];
	 srand(time(0));
	 for(int i=0; i<6; i++) {dynamic[i]=rand()%20+1;}
	 for(int i=0; i<6; i++){ std::cout << dynamic[i] << " ";}
	 std::cout <<endl;
	 delete [] dynamic; // [] needs to happen before the pointer name. i don't think it deletes the pointer.
	
	 //protected data members can be accessed by friend and derived classe the same way you would access private data members. 
	 //act as private to classes not a friend or derived.
	 //additionally, it can only be accessed in function. not directly.
	 
	 /*to defing a static member ou use the scope resolution operator
	 	example
	 class someClass
	 {
	 	private:
	 		int data1;
	 		int data2
		public:
		stuff......
	};
	someClass::data2 = 0;
	this will innitilize data2 to 0.
	anytime datas i changed from now on. thhat change will be persistant. 
	the program wil remember it no matter how many times that class is inviked.
	this must be done outside of main.*/	
	
	//operator overloading
 	bag backpack(11), duffel;
 	duffel.setCash(20);
 	bag *suitcase=duffel+backpack; 
 	std:cout << suitcase->getCash() <<" " << duffel-backpack << endl;
 	backpack^duffel;
 	std::cout << backpack.getCash() << endl;
 	
	 putout out1;
	 out1.assign();
	 ofstream outFile("output.txt", ios::out);
	 for (int i=0; i<30; i++){outFile <<out1.getDynamic(i) <<endl;}
	 outFile.close();
	 ifstream infile("output.text", ios::in);
	// while infile!.eof()(std::cout << infile.read();}
	 std::cout <<endl;
	 out1.assign();
	 ofstream outFile2("output2.txt" ,ios::binary);
	 outFile2.write((char*) &out1, sizeof(putout));
	 
	 ifstream infile2("output.text", ios::binary);
   infile2.read((char*)&out1, sizeof(out1));


	return 0;
}
