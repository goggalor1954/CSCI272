//James Roesemann
//Project1



#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

class employee
{
	public:
		employee(void); //default constructor
		employee(string lastN, string firstN, float sal, int month, int day, int year); //sets an entire record at once when values are entered apropriatly.
		void setFirstName(string name); // sets firstName
		void setLastName(string name); //sets lastName
		void setHireDate(int month, int day, int year); //sets hireDate
		void setSalary(float sal); //sets Salary
		void setRecord(string lastN, string firstN, float sal, int month, int day, int year); //sets an entire record when values are enterd apropriatly.
		float getSalary(void); //returns Salary
		string getFirstName(void); //returns firstName
		string getLastName(void);  //returns lastName
		string getFirstName(int num); // returns firstName from the record number given
		string getLastName(int num);//returns lastName from the record number given
		int getHireMonth(int num); //returns hireMonth from therecord number given
		int getHireDay(int num); //returns hireDay from the record number given
		int getHireYear(int num); //returns hireYear from the number given
		float getSalary(int num); //returns salary from the record number given
		int getHireMonth(void); //returns hireMonth
		int getHireDay(void); //returns hireDay
		int getHireYear(void); //returns hireYear
		void printRecord(void); //prints the current primary record
		void printRecord(int num); //prints out the record number stated
		void printRecordHead(void); //prints the top of the record collums
		void printAllRecords(void); //prints all records and the header
		void printRecordLine(int num); // prints the record line without the header


		
		//void setDateChanged( string date);
		//string getDateChanged(void);
		
		
	private:
		string firstLastName[5][2]; //5 arrays of 2 collums. collum 0 is first name. collum 1 is last name
		int hireDate[5][3]; //5 rows, 3 collums. collum 0 has month. 1 had day, 2 has year
		float salary[5];
		//string dateChanged[5];
};

employee::employee(void) {} //default constructor
employee::employee(string lastN, string firstN, float sal, int month, int day, int year)
{
	firstLastName[0][0]=firstN;
	firstLastName[0][1]=lastN;
	salary[0]=sal;
	hireDate[0][0]=month;
	hireDate[0][1]=day;
	hireDate[0][2]=year;
}


void employee::setFirstName(string name) //adds first name to the begining of the array while incrementing the other values.
{
	for(int i=4; i>0; i--) firstLastName[i][0]=firstLastName[i-1][0];
	firstLastName[0][0]=name;
}
void employee::setLastName(string name) //adds last name to the begining of the array while incrementing the other values.
{
	for(int i=4; i>0; i--) firstLastName[i][1]=firstLastName[i-1][1];
	firstLastName[0][1]=name;
}
void employee::setHireDate(int month, int day, int year)
{
	for(int i=4; i>0; i--)
	{
		hireDate[i][2]=hireDate[i-1][2];
		hireDate[i][1]=hireDate[i-1][1];
		hireDate[i][0]=hireDate[i-1][0];
	}
	hireDate[0][2]=year;
	hireDate[0][1]=day;
	hireDate[0][0]=month;
}
void employee::setSalary(float sal)
{
	for (int i=4; i>0; i--) salary[i]=salary[i-1];
	salary[0]=sal;
}
void employee::setRecord(string lastN, string firstN, float sal, int month, int day, int year)
{
	this->setLastName(lastN);
	this->setFirstName(firstN);
	this->setSalary(sal);
	this->setHireDate(month,  day,  year);
}

string employee::getFirstName(int num)
{
	if(num<0||num>4) exit(0);
	return firstLastName[num][0];
}
string employee::getFirstName(void) {return firstLastName[0][0];}//returns fist name in the first array
string employee::getLastName(void) {return firstLastName[0][1];} //returns the last name in the first array.
string employee::getLastName(int num)
{
	if(num<0||num>4) exit(0);
	return firstLastName[num][1];
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
float employee::getSalary(void) {return salary[0];}
float employee::getSalary(int num)
{
	if (num<0||num>4) exit(0);
	return salary[num];
}
void employee::printRecord(void) 
{
	this->printRecordHead();
	this->printRecordLine(0);
} 
void employee::printRecord(int num)
{
	this->printRecordHead();
	this->printRecordLine(num);
}
void employee::printRecordLine(int num) 

{ 
	std::cout<< std::left << std::setw(15) << this->getLastName(num);
	std::cout << std::setw(2) << "";
	std::cout << std::setw(15)<<this->getFirstName(num);
	std::cout << std::setw(2) << "";

	std::cout<<std::setw(7)<<this->getSalary(num);
	std::cout << std::setw(2) <<this->getHireMonth(num);
	std::cout << std::setw(1) << "/"; 
	std::cout << std::setw(2) <<this->getHireDay(num);
	std::cout << std::setw(1) << "/"; 
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
void employee::printAllRecords(void)
{
	if (this->getHireYear()==0) {return;}
	this->printRecordHead();
	for(int i=0; i<5; i++)
	{

		this->printRecordLine(i);
		if (i+1==5) break; //had to do this because i get an error if i+1 dosn't exist.
		if (this->getSalary(i+1)==0) i=5; //fix this. salary could realy be zero. use hire date i guess
	}
	std::cout << endl;
}




int main()
{
	//employee guy1;
	employee staff("Mackland", "Bert", 3.50, 8,5,2014);
	string fName="james", lName="roesemann";
	float sal=17.76;
	staff.setFirstName(fName);
	staff.setLastName(lName);
	staff.setHireDate(10, 16, 1988);
	staff.setSalary(sal);	
	staff.setFirstName("Frank");
	staff.setLastName("Dee");
	staff.setHireDate(12, 14, 1978);
	staff.setSalary(78.02);
	staff.setFirstName("Zap");
	staff.setLastName("Branagan");
	staff.setHireDate(4, 17, 3000);
	staff.setSalary(78.34);
	staff.setRecord("Segar", "Bob", 12.78, 9, 18, 1963);
	//testing
	staff.printAllRecords();
	staff.printRecord(4);
	
	return 0;
}
// next you need to figure out how to constrain entered variables to a centin size. porbably warn the user. and create a function that can tell how long it's been since the employee was hired. also just so stuff looks goo write a function to print out numbers that are amaller than 10 with a 0 in front of them.
