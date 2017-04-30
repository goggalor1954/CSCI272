#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Superman.h"

int main()
{
	Superman kent;
	ifstream infile("batman.dat", ios::in | ios::binary);
	infile.read(reinterpret_cast<char*>(&kent), sizeof(Superman));
	std::cout << kent.fNameBuilder(0) <<" " << kent.getSalary(3) << " " << kent.getSalary(1) << endl;
	return 0;
}
