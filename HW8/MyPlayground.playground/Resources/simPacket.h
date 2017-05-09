#ifndef SIMPACKET_H
#define SIMPACKET_H

class simPacket{

private:
	char sourceIp[16];//12 digits, 2 periods and an mepty character
	char destinationIp[16];
	char dat[26];//made this 26 characthers in orderto add a null character. for now im just goingto allow ascii ranges from A-Z, change this later.

public:
	//simPacket(){sourceIP=new char[25], destinationIp = new char(), dat=new char();}
	simPacket(){srand(time(0));};
	simPacket(std::string sIP, std::string dIP, std::string datValue){setSourceIp(sIP), setDestinationIp(sIP), setDat(datValue); srand(time(0));}
	char* getSourceIp(){return sourceIp;} //returns sourceIp simPacket object
	void setSourceIp(std::string x){charBuilder(x, sourceIp, 0);} // sets sourceIp simpacket object
	char* getDestinationIp(){return destinationIp;} //returns destinationIp simPacket object
	void setDestinationIp(std::string x){charBuilder(x, destinationIp, 0);} // sets destinationIp simpacket object
	char* getDat(){return dat;} //returns the dat 25 character array
	void setDat(std::string x){charBuilder(x, dat, 0);} //sets the dat 25 character array;
	void charBuilder(std::string input){ charBuilder(input, dat, 0);}
	void charBuilder(std::string input, char x[], int pos)//stakes a std::string and convetes it into a 26 character array, with the last character being reserved for the null character;
	{
		if(input.size()==pos || pos==25){x[pos]=input.at(pos);}
		else
		{
			x[pos]=input.at(pos);
			charBuilder(input, x, pos+1);
		}
	}
	std::string charTostdString(char x[]){return charTostdString(x, 0);}
	std::string charTostdString(char x[], int pos)
	{
		if(x[pos]=='\0'){return std::string();}
		return std::string(1, x[pos])+ charTostdString(x, pos+1);
	}
	//function to generate a random number for ip address
	char ipGen(int pos)
	{
		if(pos==0 || pos==4 || pos==8 || pos==12) return static_cast<char>(rand()%3);//generate number 0-2 and return
		if(pos==3 || pos==7 || pos==11)return'.';
		return char(rand()%10);
	}
	//function to genetate random characters for data. just capital letter fr now. change htis.
	char datGen(){return static_cast<char>(65+rand()%26);}
/*	void charCopy(char input, char stored, int pos)
	{
		if(stored[pos]=='\0' || input[pos]=='\0') return;

	}*/

	//add this for when char arrays are nt permited size;
	/*void charArrayCopy(*char source, *char destination)
	{

	}*/

};


#endif