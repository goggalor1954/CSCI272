//james Roesemann
//Homework #4
//Linked List

#include <iostream>
using namespace std;

class NodeX
{
	public:
	void setNodeX(NodeX *next);
	NodeX getNext(void);

	private:
	NodeX *next;
};

//NodeX::NodeX(void) {next=NULL;}
void NodeX::setNodeX(NodeX *next) {next=next;}
NodeX NodeX::getNext(void) {return *next;}

int main()
{
	NodeX thing1, thing2;
	std::cout <<"value of thing 1 " << &thing1 << "\nand thing2 " <<  &thing2 << endl;
	std::cout <<"next value for thing1 " << &thing1.getNext(); <<"\nand thing 2 " <<&thing2.getNext() << endl;



	return 0;
	
}

