#ifndef SUPERMAN_H
#define SUPERMAN_H
#include <string>
#include <cmath>
using namespace std;

class Superman
{
	private:
		char fName[5][16];
		char lName[5][16];
		int month[5], day[5], year[5];
		float salary[5];
	public:
		/*string stringBuilder(char x[], int y)//recursivly builds a string from a char array.
		{
			if (x[y]=='\0') return string();
			return string(1, x[y])+stringBuilder(x, y+1);
		}
		string stringBuilder(char x[]){return stringBuilder(x, 0);} //takes as char array and returns a string.
		
		char charArrayBuild(string input, char output[])//takes a string and creates a char array.
		{
			return charArrayBuild(input, output, 0);
			
		}
		char charArrayBuild(string input, char output[], int x)//recursive version of the charArrayBuild function
		{
			//return condition
			if(input.size()==x || x==15)
			{
				output[x]='\0';
				return output;
			}
			output[x]=input.at(x);
			return charArrayBuild(input, output, x+1);
		}*/
		void charFNameBuilder(int pos, string input){ charBuilder(pos, input, fName, 0);}
		void charLNameBuilder(int pos, string input){charBuilder(pos, input, lName, 0);}
		void charBuilder(int pos, string input, char x[][16], int pos2)
		{
			if(input.size()==pos2 || pos2==15){x[pos][pos2]='\0';}
			else
			{
				x[pos][pos2]=input.at(pos2);
				charBuilder(pos, input, x, pos2+1);
			}
		} 
		string fNameBuilder(int pos){return stringBuilder(fName, pos, 0);}
		string lNameBuilder(int pos){return stringBuilder(lName, pos, 0);}
		string stringBuilder(char x[][16], int pos, int pos2)
		{
			if(x[pos][pos2]=='\0') return string();
			return string(1, x[pos][pos2])+stringBuilder(x, pos, pos2+1);
		}
			

		void setMonth(int x,  int pos){month[pos]=x;}
		int getMonth(int pos){return month[pos];}
		void setDay(int x, int pos){day[pos]=x;}
		int getDay(int pos){return day[pos];}
		void setYear(int x, int pos){year[pos]=x;}
		int getYear(int pos){return year[pos];}
		void setSalary(float x, int pos){salary[pos]=x;}
		float getSalary(int pos){return salary[pos];}
		char getFName(int pos, int pos2){return fName[pos][pos2];}
		char getLName(int pos, int pos2){return lName[pos][pos2];}
		void setFName(int pos, int pos2, char x){fName[pos][pos2]=x;}
		void setLName(int pos, int pos2, char x){lName[pos][pos2]=x;}
		void pushFname(int pos, int pos2){moveName(pos, pos2)
		{
			for(int i=0; i<16; i++)
			{
				fName[col2][i]=fName[col1][i];
			}
		}
		void pushLName(int col1, int col2){
		{
			for(int i=0; i<16; i++)
			{
				lName[col2][i]=lName[col1][i];
			}
		}


		//void setRecord(string first, string last,  int m, int d, int y, float sal){setRecord(first, last, m, d, y, sal, 0);
};
		

#endif
