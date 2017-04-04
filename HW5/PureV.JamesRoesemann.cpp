//James Roesemann
//HW5
//Abstract class Pure Virtual

#include <iostream>
#include <cstdlib>
using namespace std;


class PureV {

	public:
		PureV(); //default constructor
		float getRawSalary(); //returns rawSalary
		void setRawSalary(float sal); //sets rawSalary
		virtual void salary(void) =0; //virtual function. increases salary depending on which derived class calls it.		
	private:
		float rawSalary;
	
};

class goodEmployee : public PureV
{
	public:
	void salary(void);//increases value of rawSalary by 20%
};

class betterEmployee : public PureV
{
	public:
	void salary(void);//increases value of rawSalary by 30%
};

PureV::PureV() {rawSalary=0.0;}
float PureV::getRawSalary() {return rawSalary;}
void PureV::setRawSalary(float sal) {rawSalary=sal;}
void goodEmployee::salary(void){ this->setRawSalary(this->getRawSalary()+.20*this->getRawSalary());} 
void betterEmployee::salary(void){ this->setRawSalary(this->getRawSalary()+.30*this->getRawSalary());} 

int main()
{
	//testing
	goodEmployee frank;
	betterEmployee george;
	frank.setRawSalary(100);
	george.setRawSalary(100);
	std::cout << "Frank's raw salary: " <<frank.getRawSalary() <<endl;
	std::cout << "George's raw salary: " <<george.getRawSalary() <<endl;
	frank.salary();
	george.salary();
	std::cout << "Frank's raw salary now: " <<frank.getRawSalary() <<endl;
	std::cout << "George's raw salary now: " <<george.getRawSalary() <<endl;
	frank.setRawSalary(89.3);
	george.setRawSalary(126.2);
	std::cout << "Frank's raw salary: " <<frank.getRawSalary() <<endl;
	std::cout << "George's raw salary: " <<george.getRawSalary() <<endl;
	frank.salary();
	george.salary();
	std::cout << "Frank's raw salary now: " <<frank.getRawSalary() <<endl;
	std::cout << "George's raw salary now: " <<george.getRawSalary() <<endl;


	return 0;
}
