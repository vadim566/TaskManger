
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
	//Constracturs 
	participant(string nameP,string lastName ,string organization,string position);
	participant();

	//Set Methods  
	void setName(string nameP)throw(string);
	void setLastName(string lastName)throw(string);
	void setOrganization(string organization)throw(string);
	void setPosition(string poistion)throw(string);

	//Get Methods  
	string getName()const { return nameP; };
	string getLastName()const{ return lastName; };
	string getOrganization()const { return organization; };
	string getPosition()const { return position; };

	//Print function
	void printP()const;

	//Distractors 
	void removeP();
	~participant();
	
	

private:
	string nameP;
	string lastName;
	string organization;
	string position;

};

