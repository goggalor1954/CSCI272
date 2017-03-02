//exam1 pratice

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//going to create a class. a derived class. access a pointer through a function. play around with pointers generate a random number. create a const pointer a *const pointer and pointers to pointers.
//call by refrence. increment a pointer(array). pass a pointer by refrence to a function. create and sccess a friend function. maybe operator overloading. don't know if i actually have to do this.


//first class
class prisioner
{
	public:
		prisoner(void);
		void setName(string newName);
		void setID(int newID);
		string getName(void);
		int getid(void);

	private:
		string name;
		int idNum;
	//figure out a frined function to put here
}
class prisonWorker : public prisoner
	
	public:
		prisonWorker(void);
		void setPayRate(double newPay);
		double get payRate(void);

	private:
		double payRate;
}
prisoner::prisioner(void) {}
void prisoner::setName(string newName) {name=newName;}
void prisoner::setID(int newID) {idNum=newID;}
string prisoner::getname(void) { return name;}
int prisoner::getID(void) {return idNum;}
prisonWorker::prisonWorker(void) {}
void prisonWorker::setPayRate(double newPay) {payRate=newPay;}
double prisonworker::getPayRate(void) {return payRate;}


