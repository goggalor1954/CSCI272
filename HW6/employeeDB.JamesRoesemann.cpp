//James Roesemann
//Homework 6 Header File
//Note: This program was modified to meet the requirments of the assignment "Header file". No further changes were made to this program.

#include <iostream>
#include <cstdlib>
#include "employee.JamesRoesemann.h"

using namespace std;
int main()
{
	
	employee staff("Mackland", "Bert", 3.50, 8,5,2014);
	staff.printAllRecords();
	std::cout << "populating and printing all records\n";
	staff.setRecord("Roesemann", "James", 17.76, 10, 16, 1988);
	staff.setRecord("Reynolds", "Frank", 78.02, 12, 14, 1978);
	staff.setRecord("Branagan", "Zap", 78.34, 3, 19, 2000);
	staff.setRecord("Segar", "Bob", 12.78, 3, 17, 1963);
	staff.printAllRecords();
	std::cout<<"adding a new record\n";
	staff.setRecord("Gunderson", "Gus", 30.23, 7, 15,1996);
	staff.printAllRecords();
	std::cout << "completely changing an old record\n";
	staff.setRecord("Kent", "Clark", 100.25, 12, 16, 1945, 3);
	staff.printAllRecords();
	std::cout <<"printing out a selected record\n";
	staff.printRecord(2);
	std::cout<<"printing out multiple records\n";
	staff.printRecord(3, 0);
	std::cout << "printing out a range of records \n";
	staff.printRecordRange(1,4);
	std::cout <<"changing the date of a selected record\n";
	staff.setHireDate(3, 21, 2007, 1);
	staff.printRecord(1);
	std::cout << "changing the first and last name of a selected record\n";
	staff.setLastName("Baggens", 3);
	staff.setFirstName("Bilbo", 3);
	staff.printAllRecords();
	std::cout<< "changing the salary of a selected record\n";
	staff.setSalary(99.95, 2);
	staff.printAllRecords();
	std::cout <<"calculating how many years it's been since an employee has been hired.\n";
	staff.printRecord(2);
	std::cout << staff.yearsEmployed(2)<< endl;
	staff.printRecord(1);
	staff.yearsEmployed(1);

	
	return 0;
}
