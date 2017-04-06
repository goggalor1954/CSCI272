#ifndef
#define

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

class employee
{
	public:
		employee(void) {} //default constructor
		employee(string lastN, string firstN, float sal, int month, int day, int year)//sets an entire record at once when values are entered apropriatly.
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
			firstLastName[0][0]=firstN;
			firstLastName[0][1]=lastN;
			salary[0]=sal;
			hireDate[0][0]=month;
			hireDate[0][1]=day;
			hireDate[0][2]=year;
		}


		void setFirstName(string name)// sets firstName
		{
			for(int i=4; i>0; i--) firstLastName[i][0]=firstLastName[i-1][0];
			firstLastName[0][0]=name;
		}
		void setFirstName(string name, int num) //sets firstName for he specified record number.
		{
			firstLastName[num][0]=name;
		}
		void setLastName(string name) //sets lastName
		{
			for(int i=4; i>0; i--) firstLastName[i][1]=firstLastName[i-1][1];
			firstLastName[0][1]=name;
		}
		void setLastName(string name, int num) // sets last name for the specified record number.
		{
			firstLastName[num][1]=name;
		}
		void setHireDate(int month, int day, int year)//sets hireDate
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
				hireDate[i][2]=hireDate[i-1][2];
				hireDate[i][1]=hireDate[i-1][1];
				hireDate[i][0]=hireDate[i-1][0];
			}
			hireDate[0][2]=year;
			hireDate[0][1]=day;
			hireDate[0][0]=month;
		}
		void setHireDate(int month, int day, int year, int num)//set hireDate for the specified record number.
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
			hireDate[num][2]=year;
			hireDate[num][1]=day;
			hireDate[num][0]=month;
		}
		void setSalary(float sal)//sets Salary
		{
			for (int i=4; i>0; i--) salary[i]=salary[i-1];
			salary[0]=sal;
		}
		void setSalary(float sal, int num)//sets salary for the specified record number;
		{ 
			salary[num]=sal;
		}
		void setRecord(string lastN, string firstN, float sal, int month, int day, int year)//sets an entire record.
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
		void setRecord(string lastN, string firstN, float sal, int month, int day, int year, int num)//changes an entire record when record entry number is specified.
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

		string getFirstName(int num)// returns firstName from the record number given
		{
			if(num<0||num>4) exit(0);
			return firstLastName[num][0];
		}
		string getFirstName(void)//returns firstName 
		{
			return firstLastName[0][0];
		}
		string getLastName(void)//returns lastName
		{
			return firstLastName[0][1];
		} 
		string getLastName(int num)//returns lastName from the record number given
		{
			if(num<0||num>4) exit(0);
			return firstLastName[num][1];
		}		
		int getHireDay(void) {return hireDate[0][1];}
		int getHireDay(int num)
		{
			if(num<0||num>4) exit(0);
			return hireDate[num][1];
		}
		int getHireMonth(void) {return hireDate[0][0];}
		int getHireMonth(int num) //returns hireMonth from therecord number given
		{
			if(num<0||num>4) exit(0);
			return hireDate[num][0];
		}
		int getHireYear(void) {return hireDate[0][2];}
		int getHireYear(int num)
		{
			if(num<0||num>4) exit(0);
			return hireDate[num][2];
		}
		float getSalary(void) //returns Salary
		{
			return salary[0];
		}
		float getSalary(int num)//returns salary from the record number given
		{
			if (num<0||num>4) exit(0);
			return salary[num];
		}
		void printRecord(void) 
		{
			this->printRecordHead();
			this->printRecordLine(0);
		} 
		void printRecord(int num)
		{
			this->printRecordHead();
			this->printRecordLine(num);
			std::cout << endl;

		}
		void printRecord(int num, int num2)
		{
			this->printRecordHead();
			this->printRecordLine(num);
			this->printRecordLine(num2);
			std::cout << endl;

		}
		void printRecord(int num, int num2, int num3)
		{
			this->printRecordHead();
			this->printRecordLine(num);
			this->printRecordLine(num2);
			this->printRecordLine(num3);
			std::cout << endl;
		}
		void printRecord(int num, int num2, int num3, int num4)
		{
			this->printRecordHead();
			this->printRecordLine(num);
			this->printRecordLine(num2);
			this->printRecordLine(num3);
			this->printRecordLine(num4);
			std::cout << endl;
		}
		void printRecordRange(int begin, int end)
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
		void printRecordLine(int num) 
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
		void printRecordHead(void) 
		{
			std::cout << left <<std::setw(15)<<"Last Name:";
			std::cout << std::setw(2) << "";
			std::cout << std::setw(15)<<"First Name:";
			std::cout << std::setw(2) << "";
			std::cout << std::setw(7) <<"Salary:";
			std::cout << std::setw(2) << "";
			std::cout <<std::setw(10) <<"Hire Date:" <<endl;
		}
		void printAllRecords(void)
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
		int yearsEmployed(int num)
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
		int yearsEmployed(void)
		{
			return this->yearsEmployed(0);
		}

		
		
	private:
		string firstLastName[5][2]; //5 arrays of 2 collums. collum 0 is first name. collum 1 is last name
		int hireDate[5][3]; //5 rows, 3 collums. collum 0 has month. 1 had day, 2 has year
		float salary[5];
};