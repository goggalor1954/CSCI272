//james Roesemann
//Homework #4
//Linked List

#include <iostream>
using namespace std;

class NodeX
{
	public:
	NodeX(void);
	void setNext(NodeX nextPtr);
	NodeX* getNext(void);
	float getSalary();
	void setSalary(float sal);
	//testing

	private:
	NodeX *next;
	float Salary;
};

NodeX::NodeX(void) {next=NULL;}
void NodeX::setNext(NodeX nextPtr) {next=&nextPtr;}
NodeX* NodeX::getNext(void) {return next;}
float NodeX::getSalary() {return Salary;}
void NodeX::setSalary(float sal) {Salary=sal;}

int main()
{
	NodeX *thing1=new NodeX, *thing2=new NodeX;
	/* TESTING
	std::cout <<"address of thing 1 " << &thing1 << "\nand thing2 " <<  &thing2 << endl;
	std::cout <<"next value for thing1 next " <<thing1.getNext() <<"\nand thing2 next " <<thing2.getNext() << endl;
	thing1.setNodeX(&thing2);
	std::cout <<"Now, Value of thing1 next " << thing1.getNext() <<"\nand thing2 next " <<thing2.getNext() <<endl;
	std::cout <<"Does thing2.next()== NULL " << (thing2.getNext()==NULL) << true<< endl;
	*/
	thing1->setSalary(15.00);
	thing2->setSalary(3.50);
	std::cout << thing1->getSalary() <<"\n"<<thing2->getSalary() <<endl;
	
	thing1->setNext(*thing2);
	std::cout << thing1->getSalary() <<"\n" << thing1->getNext()->getSalary() << endl;


	return 0;
	
}

