#ifndef SIMPACKET_H
#define SIMPACKET_H
#include <ctime>
#include <cstdlib>

class simPacket{

private:
	char sourceIp[16];//15 characters and a '\0'
	char destinationIp[16];//15 characters and a '\0'
	char dat[26];//25 characters and a '\0'
public:
	simPacket(std::string sIP, std::string dIP, std::string datValue)
	{
		setSourceIp(sIP);
		setDestinationIp(dIP);
		setDat(datValue);
	}
	simPacket()
	{
		this->dataGen();
		this->destinationIpGen();
		this->sourceIpGen();
	};
	char* getSourceIp(){return sourceIp;} //returns sourceIp character Array.
	void setSourceIp(std::string x){charBuilder(x, sourceIp, 0);} // sets sourceIp character Array from entered string
	char* getDestinationIp(){return destinationIp;} //returns destinationIp character array.
	void setDestinationIp(std::string x){charBuilder(x, destinationIp, 0);} // sets destinationIp character array from entered string.
	char* getDat(){return dat;} //returns the dat 26 character array
	void setDat(std::string x){charBuilder(x, dat, 0);} //sets the dat character array;
	void charBuilder(std::string input){ charBuilder(input, dat, 0);}//takes a string and convetes it into a 26 character array, with the last character being reserved for the null character;
	void charBuilder(std::string input, char x[], int pos)//takes a string and convetes it into a 26 character array, with the last character being reserved for the null character;
	{
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
	std::string charToString(char x[]){return charToString(x, 0);}//takes a character array and returns a string
	std::string charToString(char x[], int pos)//takes a character array and returns a string
	{
		if(x[pos]=='\0'){return std::string();}
		return std::string(1, x[pos])+ charToString(x, pos+1);
	}
	char datCharGen(){return (65+rand()%26);}//genetares a random capital letter char
	std::string getSource(){return charToString(getSourceIp());} //returns the string of sourceip
	std::string getDestination(){return charToString(getDestinationIp());}//returns the string of destination ip
	std::string getPayload(){return charToString(getDat());}//returns the string of payload.


	//ip address constructor recursice
	void ipGen(char x[], int pos)
	{
		if(pos==15) return;
		if(pos==0 || pos==4 || pos==8 || pos==12) {x[pos]=static_cast<char>(48+rand()%3);}//if pos is at the start of an ip octet change its value to a random number 3 or less
		if(pos==3 || pos==7 || pos==11) {x[pos]='.';}//if pos is at the position of a period return '.'.
		if(pos==1 || pos==5 || pos==9 || pos==13)//if pos is a second digit of an octet, check to see if the first digit is two and set it's to value 5 or less. otherwise set random digit.
		{
			if(x[pos-1]==2) {x[pos]=static_cast<char>(48+rand()%6);}
			else {x[pos]=static_cast<char>(48+rand()%10);}
		}
		if(pos==2 || pos==6 || pos==10 || pos==14)//check to see if the first digit of the octet is 2 and the second digit is 5. if so set the value 5 or less. otherwise set a random digit
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
	bool validSource(){return validIp(sourceIp);}//checks if the sourceIp is valid
	bool validDestination(){return validIp(destinationIp);}// chackes if the DestinationIp is valid
	void fillData(char x[], int pos)//fills in random character data into the array dat.
	{
		if (pos==25) return;
		x[pos]=datCharGen();
		fillData(x, pos+1);
	}
	void dataGen(){fillData(dat, 0);}//generates characters for the dat array.
	bool validData(char x[], int pos) //checks to see if data contains the encrypted data "JOHNJAY" (meaning its the ascii value -1. ) returns ture if found. false if not.
	{
		if (pos==18) return false;
		if (x[pos]-1=='J' && x[pos+1]-1=='O' && x[pos+2]-1=='H' && x[pos+3]-1=='N' && x[pos+4]-1=='J' && x[pos+5]-1=='A' && x[pos+6]-1=='Y') return true;
		return validData(x, pos+1);
	}
	bool validData(){return validData(dat, 0);}
};


#endif
