//James Roesemann
//HW5
//Abstract class Pure Virtual

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;


class PureV {

	public:
		PureV(); //default constructor
		float getRawSalary(); //returns rawSalary
		float getAdjSalary(); //returns adjusted salary 
		void setRawSalary(float sal); //sets rawSalary
		void setAdjSalary(float sal); //sets Adjusted salary
		virtual void salary(void) =0; //virtual function. increases salary depending on which derived class calls it.
		//testing
		
	private:
		float rawSalary;
		float adjSalary;
	
};

class goodEmployee : public PureV
{
	public:
	void salary(void);
};

class betterEmployee : public PureV
{
	public:
	void salary(void);
};

PureV::PureV() {rawSalary=0.0; adjSalary=0.0;}
float PureV::getRawSalary() {return rawSalary;}
float PureV::getAdjSalary() {return adjSalary;}
void PureV::setRawSalary(float sal) {rawSalary=sal;}
void PureV::setAdjSalary(float sal) {adjSalary=sal;}
void goodEmployee::salary(void){ setRawSalary(getRawSalary()+.20*getRawSalary());} //increases value of rawSalary by 20%
void betterEmployee::salary(void){ setRawSalary(getRawSalary()+.30*getRawSalary());} //increases value of rawSalary by 30%



int main()
{
	//testing
	goodEmployee frank;
	betterEmployee george;
	frank.setRawSalary(6.893);
	george.setRawSalary(100);
	std::cout << "Frank's raw salary: " <<frank.getRawSalary() <<endl;
	std::cout << "George's raw salary: " <<george.getRawSalary() <<endl;
	frank.salary();
	george.salary();
	std::cout << "Frank's raw salary: " <<frank.getRawSalary() <<endl;
	std::cout << "George's raw salary: " <<george.getRawSalary() <<endl;
	//testing
	//std::cout << Round(frank.getRawSalary(),2) <<endl;


	return 0;
}