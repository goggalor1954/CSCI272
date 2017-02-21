//James Roesemann
//Assignment 3 Derived class
/* This program contains two classes. PERSONNEL contains the public data NAME and the private data ID. STUDENT is a class derived from PERSONAL that contains the private data MAJOR. This program declares an instance of each, and assigns values to each data member. */
#include <cstdlib>
#include <iostream>
using namespace std;


class PERSONNEL
{
	public:
		PERSONNEL(void); //default constructor
		PERSONNEL(string NAME, int ID); //constructor
		void setName(string Name);//sets value of NAME
		void setID(int ID); //sets value of ID
		string getName(void); //returns value of NAME
		int getID(void); //returns value of ID
		string NAME; //Value of NAME


	private:
		int ID; //value of ID
};
class STUDENT : public PERSONNEL // STUDENT is a derived class of PERSONNEL
{
	public:
	STUDENT(void); //default constructor
	string getMajor(void); //returns the value of major
	void setMajor(string major); //sets the value of major
	
	private:
	string MAJOR; //Value of MAJOR
};

int main()
{	
	STUDENT guy1;
	guy1.setName("Roesemann, James");
	guy1.setID(5555552);
	guy1.setMajor("Computer Science");

	return 0;
};
PERSONNEL::PERSONNEL(void){};//default constructor
STUDENT::STUDENT(void) {}; //default constructor
void PERSONNEL::setName(string Name) {NAME=Name;} //sets value of NAME
void PERSONNEL::setID(int id) {ID=id;} //sets value of ID
string PERSONNEL::getName(void) {return NAME;} //returns value of NAME
int PERSONNEL::getID(void) {return ID;} //returns value of ID
void STUDENT::setMajor(string major) {MAJOR=major;} // sets the value of major
string STUDENT::getMajor(void) {return MAJOR;} //returns the value of major
