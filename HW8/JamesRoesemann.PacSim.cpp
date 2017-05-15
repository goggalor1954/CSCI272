//James Roesemann
//packet simulation assignment

//creates 3 simPacket Objects
//generates random sourceIp, destinationIp and data payload for each.
//creates a queue and adds the objects to it.
//checks sourceIp, destinationIp, and data payload for validity
//if valid, genetates new sourceIp, destinationIp and data payload, pushes the front of the queue to the back and pops the front.
//if sourceIp, destinationIp, or data payload are invalid loop ends and the invalid datamember is printed
#include <iostream>
#include <queue>
#include <string>
#include <cmath>
#include "JamesRoesemann.SimPacket.h"
using namespace std;

int main()
{
	int count=0;
	srand(time(0));
	simPacket pacMan;
	simPacket missPacMan;
	simPacket ghost;

	std::queue<simPacket> cherry;
	cherry.push(missPacMan);
	cherry.push(pacMan);
	cherry.push(ghost);

	while(cherry.front().validSource()==true && cherry.front().validDestination()==true && cherry.front().validData()==false)
	{
		std::cout <<count << " " <<endl;
		cherry.front().dataGen();
		cherry.front().sourceIpGen();
		cherry.front().destinationIpGen();
		cherry.push(cherry.front());
		cherry.pop();
		count++;
		if(count>50) cherry.front().setDat("AppleBerryKPIOKBZcarTruck"); //because it is unlikely that an encrypted "JOHNJAY" will be generated, if count>50, a payload containing one is added to the front of the queue.
	}

	if(cherry.front().validSource()==false){ std::cout << "Source IP is invalid: " << cherry.front().getSource() << endl;}
	if(cherry.front().validDestination()==false){std::cout <<"Destination IP is invalid: " << cherry.front().getDestination() << endl;}
	if(cherry.front().validData()==true){std::cout << "data payload contains encrypted JOHNJAY: " << cherry.front().getPayload() << endl;}

	return 0;
}

