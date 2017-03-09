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

class employee
{
	public:
		void setFirstName(string name);
		string getFirstName(void);
		srring getFirstName(int pos);
		void setLastName(string name);
		srting getLastName(void);
		string getFirstName(int pos);
		void setHireMonth(int month);
		int getHireMonth(void);
		int getHireMonth(int pos);
		void setHireDay(int day);
		int getHireDay(void);
		int getHireDay(int pos);
		void setHireYear(int year);
		int getHireYear(void);
		int getHireYear(int pos);
		void setDateChanged( string date);
		string getDateChanged(void);
		
		
	private:
		string firstLastName[5][5];
		int hireMonth[5];
		int hireDay[5];
		int hireYear[5];
		string dateChanged[5];
		float salary[5];
		

};

int main()
{


	return 0;
}
