//pointer practice

//stuff to do
//declare a pointer and have it point to something/another variable
//have it point to something else/check the results
//declare a constant pointer and try to have it point to something else
//read the value of a pointer 
//read the (derefrenced pointer) location
//pass a ponter to a function
//use a pointer in a class

#include <iostream>
using namespace std;

int pointAdd(int *uno, int *dos);

int main()
{
	int firstVal=42, secondVal=53;
	int *pointOne;
	const int *pointTwo = &secondVal;
	pointOne=&firstVal;
	
	std::cout << "this is the value in firstVal " << firstVal <<endl;
	std::cout << "this is the value pointOne points to " << pointOne << endl;
	std::cout << "this is the address of firstVal " << &firstVal << endl;
	std::cout << "this is the address of pointOne " << &pointOne << endl;
	std::cout << "this should be the value that pointOne points to " << *pointOne << endl;
	std::cout << "this should be the value of secondVal " << secondVal<< endl;
	std::cout << "this should be the address of secondVal " << &secondVal << endl;
	std::cout << "this should be the address pointTwo points to "<< pointTwo << endl;
	std::cout << "this should be the value pointTwo points to " << *pointTwo <<endl;
	std::cout << "this should be the address of point two " << &pointTwo << endl;
	std::cout << "lets change where point one points to" <<endl;
	std::cout << "tets try changing where pointTwo points to " << endl;
	pointTwo=&firstVal;
	std::cout << "pointTwo now points to " << pointTwo << endl;
	std::cout << "whose value is " << *pointTwo << endl;
	std::cout << "lets put everything back and test a function. this: " << firstVal+secondVal << endl;
	pointTwo=&secondVal;
	std::cout <<"should be the same as this " << pointAdd( &firstVal, &secondVal) << endl;

	return 0;
}

int pointAdd (int *uno, int *dos) 
{
	return *uno + *dos;
}