//exam1 pratice

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//going to create a classx. a derived classx. access a function through a pointerx. play around with pointersx. generate a random numberx. xcreate a const pointer a *const pointer and pointers to pointersx.
//call by refrence. xincrement a pointer(array). xpass a pointer by refrence to a function. xcreate and sccess a friend function. xmaybe operator overloading. don't know if i actually have to do this.


//first class
class prisoner
{
	public:
		prisoner(void);
		void setName(string newName);
		void setID(int newID);
		string getName(void);
		int getID(void);
		prisoner operator+ ( prisoner& B)
		{
			prisoner C;
			C.setName(this->getName()+" "+B.getName());
			C.setID(this->getID()+B.getID());
			return C;
		}

	private:
		string name;
		int idNum;
	//figure out a frined function to put here
	friend string bff(string, int);
	
};
class prisonWorker : public prisoner
{	
	public:
		prisonWorker(void);
		void setPayRate(double newPay);
		double getPayRate(void);

	private:
		double payRate;
};
prisoner::prisoner(void) {}
void prisoner::setName(string newName) {name=newName;}
void prisoner::setID(int newID) {idNum=newID;}
string prisoner::getName(void) { return name;}
int prisoner::getID(void) {return idNum;}
prisonWorker::prisonWorker(void) {}
void prisonWorker::setPayRate(double newPay) {payRate=newPay;}
double prisonWorker::getPayRate(void) {return payRate;}
string bff(string x, int y) {return x+to_string(y);}
string OrangeSoda(void) { return "Kel loves orange soda";}
void tired(string &x)
{
	x = "God Dam Plane";
}

int main()
{
	prisoner snitch1, snitch2;
	prisonWorker cook1;
	
	snitch1.setName("Jerry Gergich");
	snitch1.setID(22234);
	cook1.setName("Hector Rameriez");
	cook1.setID(89242);
	cook1.setPayRate(18.00);
	std::cout << snitch1.getName() << endl << snitch1.getID() << endl;
	std::cout <<"friend function\n" << bff(snitch1.getName(), snitch1.getID()) << endl;
	std::cout << cook1.getName() << endl << cook1.getID() << endl << cook1.getPayRate() << endl;
	std::cout << "friend function test\n";
	std::cout << bff(cook1.getName(), cook1.getID())<<endl;
	string (*whoLoves)(void)= &OrangeSoda;
	std::cout << whoLoves() << endl << "playing with pointers now\n";
	string fleetWood="mac", downton="abby", bruce="Springsteen";
	string *stevie=&fleetWood; //asignes stevie to point to fleetwood
	string const *british =&downton; //assignes british to pointer and forbid it form changeing its value through a derefrenced pointer.
	//*british = "out"; //illegal
	british = &fleetWood; //can still change what it is being pointed to though
	string *const boss=&bruce; //asignes boss to point o bruce. can not change what it points to.
	*boss = "bitch";//cou can however derefrence it and change its value.
	int theCount[] ={1, 2,5,6};
	int *ahAh = &theCount[0];
	std::cout << *ahAh << endl;
	++ahAh;
	++ahAh;
	std::cout << *ahAh<<endl;
	--ahAh;
	std::cout << *ahAh<<endl;
	string **music;
	music=&stevie;
	std::cout << **music << endl;
	srand(time(0));
	int foo=rand()%25+1; 
	int bar=rand();
	std::cout << foo << " " << bar<< endl;
	string jackson="God dam snakes";
	std::cout << jackson << endl;
	tired(jackson);
	std::cout << jackson << endl;
	snitch2.setName("jack Jhonson");
	snitch2.setID(1);
	string s=" ";
	std::cout << snitch1.getName() << s <<snitch1.getID()<<endl<<snitch2.getName()<<s<<snitch2.getID() <<endl;
	prisoner snitch3 = snitch1+snitch2;
	std::cout << snitch3.getName() << s << snitch3.getID()<<endl;
	

	
	return 0;
}


