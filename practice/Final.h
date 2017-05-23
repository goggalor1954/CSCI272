//final .h file

#ifndef Final_H
#define	Final_H

#include <cstdli>
#include <string>

class sustenance
{
private:
	int calories;
	string name;
	stack<string> ingredients //make sure you can access this. later.



public:
	sustenance(); //default constructor
	sustenance(string n, int cal); // constructor tha acepts a string as the value of name and an int as the value of calories.
	void setCalories(int cal); //acepts an int and sets the value of calories
	int getCalories(); //returns the int value of calories
	void setName(string n); //accepts a string and sets the value of name
	string getName(); //returns the string value of name

};

	sustenance::sustenance(){};
	sustenance::sustenance(string n, int cal){name=n, calories=cal;}
	void sustenance::setCalories(int x){calories=x;}
	int sustenance::getCalories(){return cslories;}
	void sustenance::setName(string n){name=n;}
	string sustenance::getName(){return name;}

class drink : public sustenance
{
private:
	bool mixed;
public:
	drink(); //default
	drink(string n, int cal, bool mx); //default with bool value of cooked
	bool getMixed(); //returns the bool value of mixed;
	void setMixed(bool x); //assignes the entered bool value of mixed

};

drink::drink(){}; 
drink::drink(string n, int cal, bool mx){name=n, calories=cal, mixed=mx;}
void drink::setMixed(bool x){mixed=x;} 
bool drink::getMixed(){return mixed;}

class food : public sustenance
{
private:
	bool cooked;
public:
	food(); //default constructor
	food(string n, int cal, bool co);//constructor assign a string value to name, a int value to calories, and a bool value to cooked
	void setCooked(bool x);//sets the bool value of cooked.
	bool getCooked(); //returns bool value of cooked.
}

food::food(){}
food::food(string n, int cal, bool co){name=n, calories=cal, cooked=co;}
void food::setCooked(bool co){cooked=co;}
bool food::getCooked(){return cooked;}


class smoothie : public 



#endif