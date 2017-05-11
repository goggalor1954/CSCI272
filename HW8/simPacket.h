#ifndef SIMPACKET_H
#define SIMPACKET_H
#include <ctime>

class simPacket{

private:
	char sourceIp[16];//12 digits, 2 periods and an mepty character
	char destinationIp[16];
	char dat[26];//made this 26 characthers in orderto add a null character. for now im just goingto allow ascii ranges from A-Z, change this later.

public:
	simPacket(std::string sIP, std::string dIP, std::string datValue)
	{
		setSourceIp(sIP);
		setDestinationIp(dIP);
		setDat(datValue);
	}
	simPacket(){};
	//simPacket(std::string sIP, std::string dIP, std::string datValue){setSourceIp(sIP), setDestinationIp(sIP), setDat(datValue); srand(time(0));} //problem with this default constructor. somethingto do eith string. find out what.
	char* getSourceIp(){return sourceIp;} //returns sourceIp simPacket object
	void setSourceIp(std::string x){charBuilder(x, sourceIp, 0);} // sets sourceIp simpacket object
	char* getDestinationIp(){return destinationIp;} //returns destinationIp simPacket object
	void setDestinationIp(std::string x){charBuilder(x, destinationIp, 0);} // sets destinationIp simpacket object
	char* getDat(){return dat;} //returns the dat 25 character array
	void setDat(std::string x){charBuilder(x, dat, 0);} //sets the dat 25 character array;
	void charBuilder(std::string input){ charBuilder(input, dat, 0);}
	void charBuilder(std::string input, char x[], int pos)//stakes a std::string and convetes it into a 26 character array, with the last character being reserved for the null character;
	{
		//if(input.size()==pos || pos==25){x[pos]=input.at(pos);}
		if(input.size()==pos)
		{
			x[pos]='\0';
			return;
		}
		else
		{
			x[pos]=input.at(pos);
			charBuilder(input, x, pos+1);
		}
	}
	std::string charToString(char x[]){return charToString(x, 0);}
	std::string charToString(char x[], int pos)
	{
		if(x[pos]=='\0'){return std::string();}
		return std::string(1, x[pos])+ charToString(x, pos+1);
	}
	//function to generate a random number for ip address
	/*char ipCharGen(int pos)
	{
		//testinf

		if(pos==0 || pos==4 || pos==8 || pos==12) return static_cast<char>(48+rand()%3);//generate number 0-2 and return
		if(pos==3 || pos==7 || pos==11)return'.';
		return (48+rand()%10);
	}*/
	//function to genetate random characters for data. just capital letter fr now. change htis.
	char datCharGen(){return (65+rand()%26);}
	std::string getSource(){return charToString(getSourceIp());} //returns the string of sourceip
	std::string getDestination(){return charToString(getDestinationIp());}//returns the string of destination ip
	std::string getPayload(){return charToString(getDat());}//returns the string of payload.


	//ip address constructor recursice
	void ipGen(char x[], int pos)
	{
		//if at the end of the array
		if(x[pos]=='\0') return;
		//assign characters and make sure that they are valid (excludeing zero). assign first. then test. if it fails re do it ateh current position
		//0,4,8,12 are thr numbers to test. //test if even or odd maybe?
		//x[pos]=ipCharGen(pos);
		//test
		//std::cout << "test: " << pos <<" " << x[pos]<< std::endl;

		//moving all of ipCharGen here
		if(pos==0 || pos==4 || pos==8 || pos==12) {x[pos]=static_cast<char>(48+rand()%3);}//if pos i at the start of an ip bracket change its value to a random number 3 or less
		if(pos==3 || pos==7 || pos==11) {x[pos]='.';}//if pos is at the position of a period return that.
		if(pos==1 || pos==5 || pos==9 || pos==13)//if pos is a seond digit check to see if the first didit is two and set a value 5 or less. otherwise set random digit.
		{
			if(x[pos-1]==2) {x[pos]=static_cast<char>(48+rand()%6);}
			else {x[pos]=static_cast<char>(48+rand()%10);}
		}
		if(pos==2 || pos==6 || pos==10 || pos==14)//check to see if the first didit is 2 and the second digit is 5. set a value 5 or less. otherwise set random digit
		{
			if( x[pos-2]==2 && x[pos-1]==5){x[pos]=static_cast<char>(48+rand()%6);}
			else {x[pos]=static_cast<char>(48+rand()%10);}
		}
		ipGen(x, pos+1);
	}
	void sourceIpGen(){ipGen(sourceIp, 0);}//generate random sourceIp (with posiblity of invallid 000)
	void destinationIpGen(){ipGen(destinationIp, 0);}//generate random destination ip(with posiblity of invallid 000)
	bool validOctet(char x[], int pos)//checks to see if the octet is 000
	{
		if (x[pos]=='0' && x[pos+1]=='0' && x[pos+2]=='0') return false;
		else return true;
	}
	bool validIp(char x[]) //check to see if the ip is valid(with respect to the 000 octet)
	{
		if(validOctet(x, 0)==true && validOctet(x,4)==true && validOctet(x,8)==true && validOctet(x,12)==true) return true;
		else return false;
	}
	void fillData(char x[], int pos)//fills in fandom character data into the array dat.
	{
		if (x[pos]=='\0') return;
		x[pos]=datCharGen();
		fillData(x, pos+1);
	}
	void dataGen(){fillData(dat, 0);}//generates characters for the dat array.
	/*bool checkData(char x[], int pos) //checs to see if data contains the encrypted data "JOHNJAY" (meaning its the ascii value -1. ) returns ture if found. false if not.
	{
		if (x[pos]==21) return false;
		if(x[pos]-1==)
	}*/
};


#endif