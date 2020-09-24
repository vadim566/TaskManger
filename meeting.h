
#ifndef _TASK_H
#define _TASK_H
#include "task.h"
#endif // !_TASK_H

#ifndef STD_LIB
#define STD_LIB
#include<fstream>
#include<istream>

#include <iostream>
#include <string>
using namespace std;

#endif // !STD_LIB

#ifndef _PART_H
#define _PART_H
#include "participant.h"
#endif // !_PART_H

#define MAX_PPL 5

#define _MEETING_H

/*
class meeting
info about the class:meeting{this class contain information about the participants of the meeting and have the meeting loction }
abstract class: N
derived class: Y
child class of:task
privet parameters in the class:
   int numberOfParticipants - number of participants
   participant* participantList[MAX_PPL] - the list of all the participants in the meeting
   string location - the loction of the meeting

*/

class meeting:public task
{
public:
	

	//Constracturs 
	meeting(string location, string initDate, string finalDate, string name, int numberOfParticipants=0);
	meeting(  string initDate, string finalDate, string name, int numberOfParticipants=0);
	meeting(string location, string initDate, string finalDate, string name);
	meeting();

	//Set Methods
	void setLocation(string location)throw(string);                   /*set loction for the meeting*/
	void setNumberOfParticipants(int numberOfParticipants)throw(int); /*set number of participants that will be in the meeting*/

	//Get Methods
	string getLocation()const { return location; };
	int getNumberOfParticipants()const { return numberOfParticipants; };

	//Bool function return 1 if expired and if not it return 0
	 friend bool isExpired(string currentDate,string fDate);

	 /*Operator +=*/
	 meeting &operator+=(const participant &p);

	 /*opertaor ==*/
	 virtual bool operator==(const task& ing) const
	 {
		 if (((task*)this)->operator==(ing) == false) {
			 return false;
		 }
		 const meeting *meet = dynamic_cast<const meeting*>(&ing);
		 if (meet->getLocation() == this->getLocation() && meet->getNumberOfParticipants() == this->getNumberOfParticipants())
		 {
			 return true;
		 }
		 else return false;
	 }


	 //Print function
	 void PrintT(ostream& out)const;

	 //Distractors 
	void removeA();
	~meeting();
	

private:
	
	int numberOfParticipants;                /*number of participants*/
	participant *participantList[MAX_PPL];   /*the list of all the participants in the meeting*/
	string location;                         /*the loction of the meeting*/
};

