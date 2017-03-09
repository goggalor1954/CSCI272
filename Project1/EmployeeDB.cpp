#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
//linked list method of employee database
//need to iterate through the list to update/retrive records. recursively.
//also need to calculate the date passed from hire date.
//also need to limit it to 5 records.
class EmployeeDB
{
	public:
	EmployeeDB(void); //default constructor
	EmployeeDB(EmployeeDB &head);//creates the new linked EmployeeDB object.
	string getLastName(void); //returns lastName
	string getFirstName(void); //returns firstName
	float getSalary(void); //returns salary
	int getMonth(void); //returns hireMonth
	int getDay(void); //returns hireDay
	int getYear(void); //returns hireYear
	EmployeeDB getNext(void); //returns the pointer to the next EmployeeDB object
	void setLastName(string name); //sets lastName
	void setFirstName(string name); //sets firstName
	void setSalary(float sal); //returns salary
	void setMonth(int month); //returns hireMonth
	void setDay(int day); //returns hireDay
	void setYear(int year); //returns hireYear
	void setNext(EmployeeDB *nextDB); //sets next to point next EmployeeDB
	void printRecordHead(void); //prints the record output head
	void setHireDate(int month, int day, int year); //sets the hire date at once
	
	private:
	string lastName;
	string firstName;
	float salary;
	int hireMonth;
	int hireDay;
	int hireYear;
	EmployeeDB *next;
};

EmployeeDB::EmployeeDB(void) {next = NULL;}
EmployeeDB::EmployeeDB(EmployeeDB &head) {next = &head;}
string EmployeeDB::getLastName(void) {return lastName;}
string EmployeeDB::getFirstName(void) {return firstName;}
float EmployeeDB::getSalary(void) {return salary;}
int EmployeeDB::getMonth(void) {return hireMonth;}
int EmployeeDB::getDay(void) {return hireDay;}
int EmployeeDB::getYear(void) {return hireYear;}
EmployeeDB EmployeeDB::getNext(void) {return *next;}
void EmployeeDB::setLastName(string name) {lastName=name;}
void EmployeeDB::setFirstName(string name) {firstName=name;}
void EmployeeDB::setSalary(float sal) {salary=sal;}
void EmployeeDB::setMonth(int month) {hireMonth=month;}
void EmployeeDB::setDay(int day) {hireDay=day;}
void EmployeeDB::setYear(int year) {hireYear=year;}
void EmployeeDB::setNext(EmployeeDB *nextDB) {*next=*nextDB;} // i might need to fix this one.
void EmployeeDB::setHireDate(int month, int day, int year)
{
	hireMonth=month;
	hireDay=day;
	hireYear=year;
}
void EmployeeDB::printRecordHead(void) 
{
	std::cout << left <<std::setw(15)<<"Last Name:";
	std::cout << std::setw(2) << "";
	std::cout << std::setw(15)<<"First Name:";
	std::cout << std::setw(7) <<"Salary:";
	std::cout << std::setw(2) << "";
	std::cout <<std::setw(10) <<"Hire Date:" <<endl;
}

int main()
{
	//testing
	EmployeeDB deptA;
	deptA.setLastName("Roesemann");
	deptA.setFirstName("James");
	deptA.setSalary(23.95);
	deptA.setHireDate( 10, 18, 2010);
	
	

	

	return 0;
}

//rember to out in destructors. no cleanup in cpp