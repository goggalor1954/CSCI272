//James Roesemann
//packet simulation assignment

#include <iostream>
#include <queue>
#include <string>
#include <cmath>
#include "simPacket.h"
using namespace std;
/*ok first i will test the simPacket class.
 I will construct a que. 
 random number will be generated for the ip addresses. 
 random characters will be generated
 i will start with some base condition for each object in the que (3 of them)
 then they will be changed randomly.
 the ip addresses will be checked for suspisious 000 or encrypted characters (see how to check that numericaly.)
 if suspisious characters found. program will output a warning nad end.
 if not. values will be changed and pushed back into the queue.
 if this loops endlessly i will put in some condition where the correct suspicios characters are enterd.
 //he wants something visible to show that data has been read.
 */

int main()
{
	simPacket pacMan("192.168.001.001", "432.902.112.145", "012345678901234567890123");
	simPacket missPacMan;

	srand(time(0));

/*
	std::cout << "Testing ip generator: ";
	for(int i=0; i<25; i++)
	{
		std::cout <<  missPacMan.datGen();
	}
	std::cout <<'0' <<std::endl;*/


	return 0;
}