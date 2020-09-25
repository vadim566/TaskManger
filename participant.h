
#ifndef STD_LIB
#define STD_LIB

#include <iostream>
#include <string>
using namespace std;

#endif // !STD_LIB


#define _PART_H

/*
class participant
info about the class:participant{this class contain information about the participant in the meetings}
abstract class: N
derived class: Y
privet parameters in the class:
   string nameP - name of the participant
   string lastName - last name of the participant
   string organization - name of the organization
   string position - the participant position int the organization
*/
class participant
{
public:
	//Constracturs 
	participant(string nameP,string lastName ,string organization,string position);
	participant();

	//Set Methods  
	void setName(string nameP)throw(string); /*set the name of the participant */
	void setLastName(string lastName)throw(string);/* set the last name of the participant*/
	void setOrganization(string organization)throw(string); /* set the name of the organization*/
	void setPosition(string poistion)throw(string); /* set the participant position int the organization*/

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
	string nameP; /*name of the participant*/
	string lastName; /*last name of the participant*/
	string organization;/*name of the organization*/
	string position;/*the participant position int the organization*/

};

