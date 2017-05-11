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
//johnjay
int main()
{
	srand(time(0));
	simPacket pacMan("192.168.001.001", "432.902.112.145", "AppleBerryTruckHousePhone\0");
	simPacket missPacMan;
	simPacket ghost;
	missPacMan.dataGen();
	missPacMan.sourceIpGen();
	missPacMan.destinationIpGen();
	ghost.dataGen();
	ghost.sourceIpGen();
	ghost.destinationIpGen();

	std::queue<simPacket> cherry;
	cherry.push(missPacMan);
	cherry.push(pacMan);
	cherry.push(ghost);

	//std::cout << cherry.front().getSource() << endl;
	/*while(cherry.front().checkData()!=true || cherry.front().validSource()!=true || cherry.front().validDestination()!=true)
	{
		cherry.front().dataGen();
		cherry.front().sourceIpGen();
		cherry.front().destinationIpGen();
		cherry.push(cherry.front());
		cherry.pop();
		std::cout << cherry.front().checkData() << endl;
	}*/

	//pacMan.setDat("AppleBerryKPIOKBZcarTruck");

	return 0;
}

//al he basic elements work. just need to get the que loop to work.