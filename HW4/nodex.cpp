//james Roesemann
//Homework #4
//Linked List

#include <iostream>
using namespace std;

class NodeX
{
	public:
	NodeX() {};
	void setNext(NodeX *nextPtr) {next=nextPtr;}
	NodeX* getNext(void) {return next;}
	float getSalary() {return Salary;}
	void setSalary(float sal) {Salary=sal;}
	//testing
	//NodeX& getNextA();

	private:
	NodeX *next;
	float Salary;
};
/*
NodeX::NodeX(void) {next=NULL;}
//void NodeX::setNext(NodeX*& nextPtr) {next=&nextPtr;}
void NodeX::setNext(NodeX *nextPtr) {next =nextPtr;}
NodeX* NodeX::getNext(void) {return next;}
//NodeX& NodeX::getNextA(void) {return *next;}
float NodeX::getSalary() {return Salary;}
void NodeX::setSalary(float sal) {Salary=sal;}
*/
int main()
{
	NodeX thing1;
	NodeX thing2;
	thing1.setSalary(15.0);
	thing2.setSalary(3.50);
	std::cout <<thing1.getSalary() <<"\n"<<thing1.getNext() <<endl;
	thing1.setNext(&thing2);
	std::cout <<thing1.getNext() <<endl;
	std::cout <<thing1.getNext()->getSalary() <<endl;
	


	//testing
//	std::cout <<&thing1 << " thin1g address"<< endl;;
//	std::cout <<&thing2 <<" thing2 address" << endl;
//	std::cout <<"Thing1 next " <<(*thing1).getNext() <<" thing2 next " <<thing2->getNext() << endl;
//	thing1->setNext(*thing2);
//	std::cout <<"thing1 next "<<thing1->getNext() <<" thing2 next " <<thing2->getNext() << endl;
//	std::cout <<&thing2 <<endl;




	return 0;
	
}

