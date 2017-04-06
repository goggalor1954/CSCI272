//exam2 pratice
#ifndef Transport_H
#define Transport_H

#include <iostream>
#include <cstdlib>

using namespace std;
using std::string;

class vehicle
{
	public:
		vehicle(){driver="", model="";}
		string getDriver(){return driver;}
		string getModel(){return model;}
		void setDriver(string x){driver=x;}
		void setModel(string x){model=x;}
		virtual double costToCommute(double distance)=0;
	private:
	string driver;
	string model;
};
class bike: public vehicle
{
	public:
		bike(){calories=0;}
		int getCalories(){return calories;}
		void setCalories(int cal){calories=cal;}
		double costToCommute(double distance){return calories/distance;}
	private:
	int calories; //how many calories have been burned	
};
class car: public vehicle
{
	public:
		car(){gasTank=0, price=0, mpg=0;}
		double getGasTank(){return gasTank;}
		void setGasTank(double gas){gasTank=gas;}
		void setPrice(double x){price=x;}
		double getPrice(){return price;}
		double getMpg(void);
		void setMpg(int x){mpg=x;}
		double costToCommute(double distance){return (mpg*price)/distance;}


	private:
	double gasTank; //how much fule is in the tank	
	double price;
	int mpg;
};

//need to put this on hold. inheritance not working.
class dimond
{
	public:
		virtual void repeatStatus()=0;
		void setStatus(string currentStatus){status=currentStatus;}
		string getStatus(){return this->status;}
		/*{
			if(ptr==NULL) return "";
			return *ptr;
		}*/
		dimond(void)
		{
			status="";
			ptr=&status;
		}

	private:
		string status;
		string *ptr;
	
};
class whiteDimond : public virtual dimond
{
	public:
		//void setStatus(string currentStatus){status=currentStatus;}
		//string getStatus(){return this->status;}
		void repeatStatus()
		{
			for(int i=0; i<3; i++)
			{
				std::cout << this->getStatus() << " ";
			}
		}
	//whiteDimond() : dimond(){}
	
	
};
class blueDimond : public virtual dimond
{
	public:
		//void setStatus(string currentStatus){status=currentStatus;}
		//string getStatus(){return this->status;}
		void repeatStatus()
			{
				for(int i=0; i<4; i++)
				{
					std::cout << this->getStatus() << " ";
				}
			}
	//	blueDimond() : dimond(){}

	
};
class yellowDimond : public  whiteDimond, public  blueDimond//this will not work. mutiple inheritance
{
	public:
		void repeatStatus(){blueDimond::repeatStatus();}
		//string getStatus(){blueDimond::getStatus();}
		//string blueDimond::getStatus();
		//void setStatus(string currentStatus){blueDimond::setStatus(currentStatus);}
		//yellowDimond() : blueDimond(){}

		
};
class pinkDimond : public  whiteDimond, public blueDimond
{
	public:
		void repeatStatus(){whiteDimond::repeatStatus();}
		//string getStatus(){whiteDimond::getStatus();}
		//void setStatus(string currentStatus){whiteDimond::setStatus(currentStatus);}
	//	pinkDimond()  : whiteDimond(){}

		
};

class NodeA
{
	private:
		int head;
		NodeA *next;
	public:
		int getHead(){return head;}
		void setHead(int headx){head=headx;}
		void setNext(NodeA *ptr){next=ptr;}
		NodeA getNext(){return *next;}
};

//operator overloading;
class bag
{
	private:
		int cash;
	public:
		bag(int x){cash=x;}
		bag(){cash=0;}
		int getCash(){return cash;}
		void setCash(int x){cash=x;}
		bag* operator+(bag x){return new bag(this->getCash()+x.getCash());}
		int operator-(bag x){return this->getCash()-x.getCash();}
		void operator^(bag y){this->setCash(this->getCash()*y.getCash());}
};

class putout
{
	private:
	int *dynamic;
	public:
	int getDynamic(int x){return dynamic[x];}
	void setDynamic(int x, int y){dynamic[x]=y;}
	putout(){dynamic=new int[30];} //default. will not delete yet
	void assign()
	{
		srand(time(0));
		for(int i=0; i<30; i++){
			this->setDynamic(i, rand()%30+1);
		}
	}
};
			

	
#endif
