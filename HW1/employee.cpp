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
		Employee(void); //constructor, sets both variables to zero.
		void setSalary(float newSalary); // sets the value of SALARY
		void setID(int newID); // sets the value of SALARY
		float getSalary(void); //returns the value of SALARY
		int getID(void); //returns the value of ID 

		
	private:
	double SALARY;
	int ID;
};

Employee::Employee(void) //constructor, sets both variables to zero.
{
	ID=0;
	SALARY=0;
}
float Employee::getSalary(void) {return SALARY;} //returns the value of SALARY
int Employee::getID(void) {return ID;} //returns the value of ID 
void Employee::setSalary(float newSalary) { SALARY=newSalary; } // sets the value of SALARY
void Employee::setID(int newID) {ID=newID;} // sets the value of SALARY

int main()
{

	
	
	

	return 0;
}