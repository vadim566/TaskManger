
#ifndef STD_LIB
#define STD_LIB

#include <iostream>
#include <string>
using namespace std;

#endif // !STD_LIB


#define _PART_H

class participant
{
public:
	participant(string nameP,string lastName ,string organization,string position);
	participant();
	void setName(string nameP);
	string getName()const { return nameP; };

	void setLastName(string lastName);
	string getLastName()const{ return lastName; };

	void setOrganization(string organization);
	string getOrganization()const { return organization; };

	void setPosition(string poistion);
	string getPosition()const { return position; };

	void printP()const;
	void removeP();
	~participant();
	
	

private:
	string nameP;
	string lastName;
	string organization;
	string position;

};

