#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Superman.h"

int main()
{

	Superman clark;
	
	clark.charFNameBuilder(0, "Russia");
	std::cout << clark.fNameBuilder(0) << endl;
	clark.setSalary(13.34, 1);
	clark.setSalary(42.9, 3);


	ofstream outfile("batman.dat", ios::out | ios::binary);
	outfile.write(reinterpret_cast<char*>(&clark), sizeof(Superman));


	return 0;
}
