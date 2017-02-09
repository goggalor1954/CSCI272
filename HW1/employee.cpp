//James Roesemann
//Assignment 1 Basic Class
/*This program declares an instance of the class "employee" named staffOne, prompts the user to enter both Salary and id and assignes those values to SALARY and ID in the object staffOne.*/
#include <iostream>
using namespace std;

class Employee
{
	public:
		Employee(void); //default constructor, sets both variables to zero.
		Employee(int id, float Salary); //constructor. allows the user to create a employee objecte with both ID and SALARY
		void setSalary(float newSalary); // sets the value of SALARY
		void setID(int newID); // sets the value of ID
		float getSalary(void); //returns the value of SALARY
		int getID(void); //returns the value of ID 
		
	private:
		float SALARY;
		int ID;
};


int main()
{
	Employee staffOne;
	int staffID;
	float staffSal;

	std::cout << "Enter the ID Number and Salary of the employee." << endl;
	std::cin >> staffID >> staffSal;
	staffOne.setID(staffID);
	staffOne.setSalary(staffSal);

	//That satisfies the Assignment. I wasen't sure how strictly you wanted to us to follow the instructions given. So I wrote the statments commented out below showing that the program works as intended and that the other constructor I wrote works as well.
	/*
	std::cout << "The ID of the employee is: " << staffOne.getID() << " and the salary is: " << staffOne.getSalary() << endl;
	std::cout << "Enter the ID Number and Salary of the employee." << endl;
	std::cin >> staffID >> staffSal;
	Employee staffTwo(staffID, staffSal);
	std::cout << "The ID of the employee is: " << staffTwo.getID() << " and the salary is: " << staffTwo.getSalary() << endl;
	*/	

	return 0;
}



Employee::Employee(void) //default constructor, sets both variables to zero.
{
	ID=0;
	SALARY=0;
}
Employee::Employee(int id, float salary) //constructor. allows the user to create a employee objecte with both ID and SALARY
{
	ID=id;
	SALARY=salary;
}
float Employee::getSalary(void) {return SALARY;} //returns the value of SALARY
int Employee::getID(void) {return ID;} //returns the value of ID 
void Employee::setSalary(float newSalary) { SALARY=newSalary; } // sets the value of SALARY
void Employee::setID(int newID) {ID=newID;} // sets the value of SALARY
