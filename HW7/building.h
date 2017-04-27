//James Roeemann
//hw 7 test buiding.h

#ifndef BUILDING_H
#define BUILDING_H
#include <string>
#include <cmath>

using namespace std;

class building
{
	private:
		int house;
		int office[5];
		int church[2][2];
		string store;
		string tower[3][3];
		float rent;//represents the first and second half of a float value.
	public:
		//i think for this to work i need to write acessor funtions ratherer than the regular get function
		void setHouse(int x){house=x;}
		int getHouse(){return house;}
		void setOffice(int a, int b, int c, int d, int e)
		{
			office[0]=a;
			office[1]=b;
			office[2]=c;
			office[3]=d;
			office[4]=e;
		}
		int* getOffice()  {return office;}
		void setChurch(int a, int b, int c, int d)
		{
			church[0][0]=a;
			church[0][1]=b;
			church[1][0]=c;
			church[1][1]=d;
		}
		//int* getChurch() {return church;}
		int getChurchAt(int x, int y){ return church[x][y];}
		void setStore(string x){store = x;}
		string getStore() {return store;}
		void setTower(string a, string b, string c, string d, string e, string f, string x, string y, string z)
		{
			tower[0][0]=a;
			tower[0][1]=b;
			tower[0][2]=c;
			tower[1][0]=d;
			tower[1][1]=e;
			tower[1][2]=f;
			tower[2][0]=x;
			tower[2][1]=y;
			tower[2][2]=z;
		}
		string getTowerAt(int x, int y){return tower[x][y];}
		void setRent(float x){rent=x;}
		float getRent() {return rent;}
		//testing
		/*void save(ofstream& of)
		{
			of.write(&house, sizeof(house));
			of.write(office, sizeof(office));
			of.write(church, sizeof(church));
			of.write()*/

		//}
		//void load(ifstream& inf);

};
#endif
