#ifndef BUILDINGB_H
#define BUILDINGB_H
#include <string>
#include <cmath>
//i realy shouldnt use this but i am anyway.
using namespace std;

class BuildingB
{
private:
	char char1;
	char charArr[3];
	//going to set the arrays as size 3 for now. later i want so see what happens if i just try and pass whole arrays to them.

	char* charArr2;
	int int1;
	int intArr[3];
	string string1;
	string stringArr[3];
	float float1;
	float floatArr[3];

public:
	void setChar1(char x){char1=x;}
	char getChar1(){return char1;}
	void setCharArr(char a, char b, char c)
	{
		charArr[0]=a;
		charArr[1]=b;
		charArr[2]=c;
	}
	char* getCharArr(){return charArr;}

	//testing
	void setCharArr2(char x[]){charArr2=x;}
	char* getCharArr2(){return charArr2;}

	void setInt1(int x){int1=x;}
	int getInt1(){return int1;}
	void setIntArr(int a, int b, int c)
	{
		intArr[0]=a;
		intArr[1]=b;
		intArr[2]=c;
	}
	int* getIntArr(){return intArr;}
	void setString1(string x){string1=x;}
	string getString1(){return string1;}
	void setStringArr(string a,  string b,  string c)
	{
		stringArr[0]=a;
		stringArr[1]=b;
		stringArr[2]=c;
	}
	string* getStringArr(){return stringArr;}
	void setFloat1(float x){float1=x;}
	float getFloat1(){return float1;}
	void setFloatArr(float a, float b, float c)
	{
		floatArr[0]=a;
		floatArr[1]=b;
		floatArr[2]=c;
	}
	float* getFloatArr(){return floatArr;}

	string stringBuilder(char x[], int y)
	{
		if (x[y]=='\0') return string();
		return string(1, x[y])+stringBuilder(x, y+1);
	}
	string stringBuilder(char x[]){return stringBuilder(x, 0);}
};

#endif
