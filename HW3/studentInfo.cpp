//James Roesemann
//Assignment 3 Derived class
/* This program contains two classes. PERSONNEL contains the public data NAME and the private data ID. STUDENT is a class derived from PERSONAL that contains the private data MAJOR. This program declares an instance of each, and assigns values to each data member. */

class PERSONNEL
{
	public:
		PERSONNEL(void); //default constructor
		PERSONNEL(string NAME, int ID); //constructor
		string NAME;
		void setName(string Name);//sets value of NAME
		void setID(int ID); //sets value of ID
		string getName(void); //returns value of NAME
		int getID(void); //returns value of ID

	private:
		int ID;
}


int main()
{

	return 0;
}

void PERSONNEL::setName(string Name) {NAME=name;} //sets value of NAME
void PERSONNEL::setID(int id) {ID=id;} //sets value of ID
string PERSONNEL::getName(void) {return NAME;} //returns value of NAME
int PERSONNEL::getID(void) {return ID;} //returns value of ID

