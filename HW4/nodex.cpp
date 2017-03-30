//james Roesemann
//Homework #4
//Linked List

#include <iostream>
using namespace std;

class NodeX
{
	public:
	NodeX(); //default constructor
	void setNext(NodeX *nextPtr); //sets the next value
	NodeX* getNext(void);  // returns the next NodeX object
	float getSalary(); //returns Salary
	void setSalary(float sal); //sets Salary

	private:
	NodeX *next;
	float Salary;
};

NodeX::NodeX(void) {next=NULL;}
void NodeX::setNext(NodeX *nextPtr) {next=nextPtr;}
NodeX* NodeX::getNext(void) {return next;}
float NodeX::getSalary() {return Salary;}
void NodeX::setSalary(float sal) {Salary=sal;}

int main()
{
	NodeX thing1;
	NodeX thing2;
	thing1.setSalary(15.0);
	thing2.setSalary(3.50);
	thing1.setNext(&thing2);

	return 0;
	
}

