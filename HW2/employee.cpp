//James Roesemann
//Assignment 2 Class with constructor and pointers.
/*This program declares an instance of the class "Employee" named staffOne. A pointer to the object staffOne is created named pointOne. All functions in staffOne are accessed through this pointer. The user is prompted to enter the employee Id and Salary. The program returns these values along with a corresponding statment. .*/
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
	Employee *pointOne = &staffOne;

	std::cout << "Enter the ID Number and Salary of the employee." << endl;
	std::cin >> staffID >> staffSal;
	pointOne -> setID(staffID);
	pointOne -> setSalary(staffSal);
	std::cout << "The ID of the employee is: " << pointOne -> getID() << " and the salary is: " << pointOne -> getSalary() << endl;

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
