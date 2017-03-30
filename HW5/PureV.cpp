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
		float getToZero(float val);
		float getCents(float val);
		
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

//testing
float PureV::getToZero(float val)
{
	if(val<=1) return 0;
	return 1+(getToZero(val-1));
}
float PureV::getCents(float val)
{
	if(val<=.01) return 0;
	return .01+(getCents(val-.01));
}




int main()
{
	//testing
	goodEmployee frank;
	betterEmployee george;
	frank.setRawSalary(44.7653);
	george.setRawSalary(100);
	std::cout << "Frank's raw salary: " <<frank.getRawSalary() <<endl;
	std::cout << "George's raw salary: " <<george.getRawSalary() <<endl;
	frank.salary();
	george.salary();
	std::cout << "Frank's raw salary: " <<frank.getRawSalary() <<endl;
	std::cout << "George's raw salary: " <<george.getRawSalary() <<endl;
	//testing
	std::cout <<"should have the same whole numbers as franks raw: " << frank.getToZero(frank.getRawSalary()) << endl;
	std::cout <<"decimal values. " << frank.getRawSalary()-frank.getToZero(frank.getRawSalary()) << endl;
	std::cout <<"should be the first 2 decimal places " << frank.getCents(frank.getRawSalary()-frank.getToZero(frank.getRawSalary())) <<endl;
	if(frank.getRawSalary()-frank.getToZero(frank.getRawSalary())-frank.getCents(frank.getRawSalary()-frank.getToZero(frank.getRawSalary())) >=0.005) 
	{//increase by 1 sent. if it iit increases the dollar value increase that and disregard cents.
		if(frank.getCents(frank.getRawSalary()-frank.getToZero(frank.getRawSalary()))==.99) {frank
	}
	else {frank.setAdjSalary(frank.getToZero(frank.getRawSalary())+frank.getCents(frank.getRawSalary()-frank.getToZero(frank.getRawSalary())));}
	
	std::cout << "franks adjusted salary " << frank.getAdjSalary() <<endl;
	


	return 0;
}