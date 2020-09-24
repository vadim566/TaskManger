
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
class meeting:public task
{
public:
	//Friend function
	friend class install;

	//Constracturs 
	meeting(string location, string initDate, string finalDate, string name, int numberOfParticipants=0);
	meeting(  string initDate, string finalDate, string name, int numberOfParticipants=0);
	meeting(string location, string initDate, string finalDate, string name);
	meeting();

	//Set Methods
	void setLocation(string location)throw(string);
	void setNumberOfParticipants(int numberOfParticipants)throw(int);

	//Get Methods
	string getLocation()const { return location; };
	int getNumberOfParticipants()const { return numberOfParticipants; };

	//Bool function return 1 if expired and if not it return 0
	 bool isExpiredA(string currentDate) const;
	 friend bool isExpired(string currentDate,string fDate);

	 //Operator +=
	 meeting &operator+=(const participant &p);

	 //Print function
	 void PrintT(ostream& out)const;

	 //Distractors 
	void removeA();
	~meeting();
	

private:
	
	int numberOfParticipants;
	participant *participantList[MAX_PPL];
	string location;
};

