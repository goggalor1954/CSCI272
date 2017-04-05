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

class dimond
{
	public:
		dimond(){status="";}
		string getStatus(){return status;}
		void setStatus(string currentStatus){status=currentStatus;}
	private:
	string status;
	
};
class whiteDimond : public dimond
{
};
class blueDimond : public dimond
{
};
class yellowDimond : public dimond
{
};//finish this up

#endif