//James Roesemann
//Random Access Assignment Part 2

#include <iostream>
#include <fstream>
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
		void setFirstName(string name, int num); //sets firstName for he specified record number.
		void setLastName(string name); //sets lastName
		void setLastName(string name, int num); // sets last name for the specified record number.
		void setHireDate(int month, int day, int year); //sets hireDate
		void setHireDate(int month, int day, int year, int num); //set hireDate for the specified record number.
		void setSalary(float sal); //sets Salary
		void setSalary(float sal, int num); //sets salary for the specified record number;
		void setRecord(string lastN, string firstN, float sal, int month, int day, int year); //sets an entire record.
		void setRecord(string lastN, string firstN, float sal, int month, int day, int year, int num); //changes an entire record when record entry number is specified.
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
		void printRecord(void); //prints the current primary record and the header
		void printRecord(int num); //prints out the record number stated and the header
		void printRecord(int num, int num2); //prints the selected records and the header
		void printRecord(int num, int num2, int num3); //prints the selected records and the header
		void printRecord(int num, int num2, int num3, int num4); //prints the selected records and the header
		void printRecordRange(int begin, int end); //prints records in a range. begin being the newest record and end being the oldest record.
		void printRecordHead(void); //prints the top of the record collums
		void printAllRecords(void); //prints all records and the header
		void printRecordLine(int num); // prints the record line without the header
		int yearsEmployed(int num);//returns how many years its been since the entered record has been hired
		int yearsEmployed(void);//returns how many years it's been since the current record has been entered


		//functions to modify this program for the random access assignment
		void charFNameBuilder(int pos, string input); //converts the entered string into a character array for fName at the enterd poition
		void charLNameBuilder(int pos, string input); //converts the entered string into a character array for lName at the enterd poition
		void charBuilder(int pos, string input, char x[][16], int pos2); //recursive function that convetes the string input into char array x, pos being the position of the char array and pos2 being the position of the character value.
		string fNameBuilder(int pos); //returns the value of the char array at the entered postion of the fName array in the from of a string.
		string lNameBuilder(int pos); //returnes the value of the char array at the entered postion of the lName array in the from of a string.
		string stringBuilder(char x[][16], int pos, int pos2);//returnes the value of char array x in the form of a string, pos being the lication of the array on x, and pos2 puing the location of the character value.
		char getFName(int pos, int pos2); //returns the character value from fName at[pos][pos2]
		char getLName(int pos, int pos2); //returns the character value from lName at[pos][pos2]
		void setFName(int pos, int pos2, char x); //sets the character value at fName at[pos][pos2]
		void setLName(int pos, int pos2, char x); //sets the character value at lName at[pos][pos2]
		void pushFname(int pos, int pos2); //exchanges the character values of fName between pos and pos2
		void pushLName(int col1, int col2); //exchanges the character values of lName between pos and pos2
		
	private:
	
		int hireDay[5], hireMonth[5], hireYear[5];
		float salary[5];
		char fName[5][16], lName[5][16];
		
};

employee::employee(void) {} //default constructor
employee::employee(string lastN, string firstN, float sal, int month, int day, int year)
{
	try
	{
		if(month<1 || month>12 || day<1 || day>31 || year<1900 || year>9999)
		{
			throw 1;
		}
	}
	catch(int err_code) 
	{
		std::cerr <<"You have entered an invalid date value" << endl;
		return;
	}
	charFNameBuilder(0, firstN);
	charLNameBuilder(0, lastN);
	salary[0]=sal;
	hireDay[0]=month;
	hireMonth[0]=day;
	hireYear[0]=year;
}


void employee::setFirstName(string name)
{
	for(int i=4; i>0; i--)
	{
		pushFname(i-1, i);
	}
	charFNameBuilder(0, name);
}
void employee::setFirstName(string name, int num) {charFNameBuilder(num,name);}
void employee::setLastName(string name) 
{
	for(int i=4; i>0; i--)
	{
		pushLName(i-1, i);
	}
	charLNameBuilder(0, name);
}
void employee::setLastName(string name, int num) {charLNameBuilder(num,name);}
void employee::setHireDate(int month, int day, int year)
{
	try
	{
		if(month<1 || month>12 || day<1 || day>31 || year<1900 || year>9999)
		{
			throw 1;
		}
	}
	catch(int err_code) 
	{
		std::cerr <<"You have entered an invalid date value" << endl;
		return;
	}
	for(int i=4; i>0; i--)
	{
		hireDay[i]=hireDay[i-1];
		hireMonth[i]=hireMonth[i-1];
		hireYear[i]=hireYear[i-1];
	}
	hireDay[0]=day;
	hireMonth[0]=month;
	hireYear[0]=year;
}
void employee::setHireDate(int month, int day, int year, int num)
{
	try
	{
		if(month<1 || month>12 || day<1 || day>31 || year<1900 || year>9999)
		{
			throw 1;
		}
	}
	catch(int err_code) 
	{
		std::cerr <<"You have entered an invalid date value" << endl;
		return;
	}
	hireDay[num]=day;
	hireMonth[num]=month;
	hireYear[num]=year;
}
void employee::setSalary(float sal)
{
	for (int i=4; i>0; i--) salary[i]=salary[i-1];
	salary[0]=sal;
}
void employee::setSalary(float sal, int num){ salary[num]=sal;}
void employee::setRecord(string lastN, string firstN, float sal, int month, int day, int year)
{
	try
	{
		if(month<1 || month>12 || day<1 || day>31 || year<1900 || year>9999)
		{
			throw 1;
		}
	}
	catch(int err_code) 
	{
		std::cerr <<"You have entered an invalid date value" << endl;
		return;
	}
	this->setLastName(lastN);
	this->setFirstName(firstN);
	this->setSalary(sal);
	this->setHireDate(month,  day,  year);
}
void employee::setRecord(string lastN, string firstN, float sal, int month, int day, int year, int num)
{
	try
	{
		if(month<1 || month>12 || day<1 || day>31 || year<1900 || year>9999)
		{
			throw 1;
		}
	}
	catch(int err_code) 
	{
		std::cerr <<"You have entered an invalid date value" << endl;
		return;
	}
	this->setLastName(lastN, num );
	this->setFirstName(firstN, num);
	this->setSalary(sal, num);
	this->setHireDate(month,  day,  year, num);
}

string employee::getFirstName(int num)
{
	if(num<0||num>4) exit(0);
	return fNameBuilder(num);
}
string employee::getFirstName(void) {return fNameBuilder(0);}
string employee::getLastName(void) {return lNameBuilder(0);} 
string employee::getLastName(int num)
{
	if(num<0||num>4) exit(0);
	return lNameBuilder(num);
}		
int employee::getHireDay(void) {return hireDay[0];}
int employee::getHireDay(int num)
{
	if(num<0||num>4) exit(0);
	return hireDay[num];
}
int employee::getHireMonth(void) {return hireMonth[0];}
int employee::getHireMonth(int num)
{
	if(num<0||num>4) exit(0);
	return hireMonth[num];
}
int employee::getHireYear(void) {return hireYear[0];}
int employee::getHireYear(int num)
{
	if(num<0||num>4) exit(0);
	return hireYear[num];
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
	std::cout << endl;

}
void employee::printRecord(int num, int num2)
{
	this->printRecordHead();
	this->printRecordLine(num);
	this->printRecordLine(num2);
	std::cout << endl;

}
void employee::printRecord(int num, int num2, int num3)
{
	this->printRecordHead();
	this->printRecordLine(num);
	this->printRecordLine(num2);
	this->printRecordLine(num3);
	std::cout << endl;
}
void employee::printRecord(int num, int num2, int num3, int num4)
{
	this->printRecordHead();
	this->printRecordLine(num);
	this->printRecordLine(num2);
	this->printRecordLine(num3);
	this->printRecordLine(num4);
	std::cout << endl;
}
void employee::printRecordRange(int begin, int end)
{
	//check to make sure the numberse are either equal or smaller. put an error message.
	try
	{
		if(begin<0 ||begin>4 || end<0 || end>4 || end<begin)
		{
			throw 1;
		}
	}
	catch(int err_code)
	{
		std::cerr << "you have entered an invalid range\n";
		return;
	}
	this->printRecordHead();
	for(int i=begin; i<end+1; i++) this->printRecordLine(i);
	std::cout << endl;
}
void employee::printRecordLine(int num) 
{ 
	std::cout<< std::left << std::setw(15) << this->getLastName(num);
	std::cout << std::setw(2) << "";
	std::cout << std::setw(15)<<this->getFirstName(num);
	std::cout << std::setw(2) << "";
	std::cout<<std::setw(7)<<this->getSalary(num);
	std::cout << std::setw(2) << "";
	if(this->getHireMonth(num)<10) std::cout << std::setw(1) <<"0" <<this->getHireMonth(num);
	else std::cout << std::setw(2) <<this->getHireMonth(num);
	std::cout << std::setw(1) << "/"; 
	if(this->getHireDay(num)<10) std::cout << std::setw(1) << "0" <<this->getHireDay(num);
	else std::cout << std::setw(2) << this->getHireDay(num);
	std::cout << std::setw(1) << "/"; 
	std::cout <<std::setw(4)<<this->getHireYear(num)<<endl;
}
void employee::printRecordHead(void) 
{
	std::cout << left <<std::setw(15)<<"Last Name:";
	std::cout << std::setw(2) << "";
	std::cout << std::setw(15)<<"First Name:";
	std::cout << std::setw(2) << "";
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
int employee::yearsEmployed(int num)
{
	time_t now=time(0);
	tm* local=localtime(&now);
	if(this->getHireMonth(num)==(local->tm_mon+1))
	{
		if(this->getHireDay(num)>local->tm_mday)
		{
			return((local->tm_year+1900)-this->getHireYear(num)-1);
		}
	}
	if(this->getHireMonth(num)>local->tm_mon+1)
	{
		return((local->tm_year+1900)-this->getHireYear(num)-1); 
	}
	return((local->tm_year+1900)-this->getHireYear(num));
}
int employee::yearsEmployed(void)
{
	return this->yearsEmployed(0);




}
void employee::charFNameBuilder(int pos, string input){ charBuilder(pos, input, fName, 0);}
void employee::charLNameBuilder(int pos, string input){charBuilder(pos, input, lName, 0);}
void employee::charBuilder(int pos, string input, char x[][16], int pos2)
{
	if(input.size()==pos2 || pos2==15){x[pos][pos2]='\0';}
	else
	{
		x[pos][pos2]=input.at(pos2);
		charBuilder(pos, input, x, pos2+1);
	}
} 
string employee::fNameBuilder(int pos){return stringBuilder(fName, pos, 0);}
string employee::lNameBuilder(int pos){return stringBuilder(lName, pos, 0);}
string employee::stringBuilder(char x[][16], int pos, int pos2)
{
	if(x[pos][pos2]=='\0') return string();
	return string(1, x[pos][pos2])+stringBuilder(x, pos, pos2+1);
}

char employee::getFName(int pos, int pos2){return fName[pos][pos2];}
char employee::getLName(int pos, int pos2){return lName[pos][pos2];}
void employee::setFName(int pos, int pos2, char x){fName[pos][pos2]=x;}
void employee::setLName(int pos, int pos2, char x){lName[pos][pos2]=x;}
void employee::pushFname(int pos, int pos2)
{
	for(int i=0; i<16; i++)
	{
		fName[pos2][i]=fName[pos][i];
	}
}
void employee::pushLName(int col1, int col2)
{
	for(int i=0; i<16; i++)
	{
		lName[col2][i]=lName[col1][i];
	}
}


int main()
{
	employee HRstaff;

	ifstream infile ("employes.dat", ios::in | ios::binary);
	infile.read( reinterpret_cast<char*>(&HRstaff), sizeof(employee));

	HRstaff.printAllRecords();
	HRstaff.setFirstName("Mike", 1);
	HRstaff.setLastName("Piazza", 1);
	HRstaff.printAllRecords();

	std::cout << HRstaff.getFirstName(1) << " " << HRstaff.getLastName(1) << " has worked here for " << HRstaff.yearsEmployed(1) << " years." << endl;

	return 0;
}
