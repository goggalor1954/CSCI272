//James Roesemann
//Assignment 1 Basic Class
//This program declares an instance of the class "employee" named Tom, prompts the 
//user to enter both Salary and id and assignes those values to SALARY and ID in the 
//object Tom.
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

std::cout << "Enter the ID Number and Salary of employee one." << endl;
std::cin >> staffID >> staffSal;
staffOne.setID(staffID);
staffOne.setSalary(staffSal);
std::cout << "The ID of employee one is: " << staffOne.getID() << " and the salary is: " << staffOne.getSalary() << endl;
std::cout << "Enter the ID Number and Salary of employee two." << endl;
std::cin >> staffID >> staffSal;
//fix this later
EMployee staffTwo(staffID, staffSal);
std::cout << "The ID of employee two is: " << staffTwo.getID() << " and the salary is: " << staffTwo.getSalary() << endl;
	

	return 0;
}



Employee::Employee(void) //constructor, sets both variables to zero.
{
	ID=0;
	SALARY=0;
}
Employee::Employee(int id, float salary)
{
	ID=id;
	SALARY=salary;
}
float Employee::getSalary(void) {return SALARY;} //returns the value of SALARY
int Employee::getID(void) {return ID;} //returns the value of ID 
void Employee::setSalary(float newSalary) { SALARY=newSalary; } // sets the value of SALARY
void Employee::setID(int newID) {ID=newID;} // sets the value of SALARY