//James Roesemann
//Project1

//program that holds an employee record. using an array and pointers. (if it can be anonymous even better)
//2 or 3 classes. one for displaying a record. one for the employee redords. one for supervisor record derived from employee
//record has room for 5 saleries. 5 names. and five hire dates(possible with adational information for when this information was changed)
//the ablity to print out one, some, or all records
//best way to do this woul be to create 1 sub function , and then several functions to access that function maybe
//make it unoform. 2 characters. 3 rows. spaced by 4
//must be able to mive/delete records as the are entered
//supervisor inhereded class (find something to fill in that)
//maybe use a 2d array for name
//array should update recursivly. create an object data structure for just the array
//figure out a way to put restrains on number sizw maby for dates

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

class employee
{
	public:
		employee(void);
		void setFirstName(string name);
		string getFirstName(void);
		void setLastName(string name);
		string getLastName(void);
		void setHireDate(int month, int day, int year);
		int getHireMonth(void);
		int getHireDay(void);
		int getHireYear(void);
		void setSalary(float sal);
		float getSalary(void);
		void printRecord(void); //prints the current primary record
		void printRecord(int num);
		void printRecordHead(void); //prints the top of the record collums
		//void printAllRecords(void); //set this up once i can print specific values
		string getFirstName(int num);
		string getLastName(int num);
		int getHireMonth(int num);
		int getHireDay(int num);
		int getHireYear(int num);
		float getSalary(int num);
		//void setDateChanged( string date);
		//string getDateChanged(void);
		
		
	private:
		string firstLastName[5][2]; //5 arrays of 2 strings/ first collum is first name. 2nd collum is last name
		int hireDate[5][3]; //5 rows, 3 collums. collum 0 has month. 1 had day, 2 has year
		float salary[5];
		//int hireMonth[5];
		//int hireDay[5];
		//int hireYear[5];
		//string dateChanged[5];
};

employee::employee(void) {} //default constructor
void employee::setFirstName(string name) //adds first name to the begining of the array while incrementing the other values.
{
	for(int i=4; i==0; i--) firstLastName[i][0]=firstLastName[i-1][0];
	firstLastName[0][0]=name;
}
string employee::getFirstName(int num)
{
	if(num<0||num>4) exit(0);
	return firstLastName[num][0];
}
string employee::getFirstName(void) {return firstLastName[0][0];}//returns fist name in the first array
void employee::setLastName(string name) //adds last name to the begining of the array while incrementing the other values.
{
	for(int i=4; i==0; i--) firstLastName[i][1]=firstLastName[i-1][1];
	firstLastName[0][1]=name;
}
string employee::getLastName(void) {return firstLastName[0][1];} //returns the last name in the first array.
string employee::getLastName(int num)
{
	if(num<0||num>4) exit(0);
	return firstLastName[num][1];
}		
void employee::setHireDate(int month, int day, int year)
{
	for(int i=4; i==0; i--)
	{
		hireDate[i][2]=hireDate[i-1][2];
		hireDate[i][1]=hireDate[i-1][1];
		hireDate[i][0]=hireDate[i-1][0];
	}
	hireDate[0][2]=year;
	hireDate[0][1]=day;
	hireDate[0][0]=month;
}
int employee::getHireDay(void) {return hireDate[0][1];}
int employee::getHireDay(int num)
{
	if(num<0||num>4) exit(0);
	return hireDate[num][1];
}
int employee::getHireMonth(void) {return hireDate[0][0];}
int employee::getHireMonth(int num)
{
	if(num<0||num>4) exit(0);
	return hireDate[num][0];
}
int employee::getHireYear(void) {return hireDate[0][2];}
int employee::getHireYear(int num)
{
	if(num<0||num>4) exit(0);
	return hireDate[num][2];
}
void employee::setSalary(float sal)
{
	for (int i=4; i==0; i--) salary[i]=salary[i-1];
	salary[0]=sal;
}
float employee::getSalary(void) {return salary[0];}
float employee::getSalary(int num)
{
	if (num<0||num>4) exit(0);
	return salary[num];
}
void employee::printRecord(void) {this->printRecord(0);} 
void employee::printRecord(int num) 
{ 
	std::cout<< std::left << std::setw(15) << this->getLastName(num);
	std::cout << std::setw(2) << "";
	std::cout << std::setw(15)<<this->getFirstName(num);
	std::cout << std::setw(2) << "";

	std::cout<<std::setw(7)<<this->getSalary(num);
	std::cout << std::setw(2) <<this->getHireMonth(num);
	std::cout << std::setw(1) << ""; 
	std::cout << std::setw(2) <<this->getHireDay(num);
	std::cout << std::setw(1) << ""; 
	std::cout <<std::setw(4)<<this->getHireYear(num)<<endl;
}

void employee::printRecordHead(void) 
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
	employee guy1;
	string fName="james", lName="roesemann";
	float sal=17.76;
	

	guy1.setFirstName(fName);
	guy1.setLastName(lName);
	guy1.setHireDate(10, 16, 1988);
	guy1.setSalary(sal);	
	guy1.printRecordHead();
	guy1.printRecord();
	
	return 0;
}


//next work out print all records