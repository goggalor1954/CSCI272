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
 */

int main()
{
	simPacket pacMan("192.168.001.001\0", "432.902.112.145\0", "0123456789012345678901234\0");
	simPacket missPacMan;

	//testing
	std::cout << "Testing ip generator: ";
	for(int i=0; i<25; i++)
	{
		//std::cout << std::string(1, pacMan.ipGen(i));
	}
	std::cout << std::endl;

	return 0;
}