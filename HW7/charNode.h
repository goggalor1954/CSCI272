#ifndef CHARNODE_H
#define CHARNODE_H
#include <string>

class charNode
{
private:
	char head;
	*charNode next;
public:
	void setHead(char x){head=x;}
	char getHead(){return x;}
	void setNext(*charNode x){next=x;}
	charNode getNext(){return this->next;}
}

#endif