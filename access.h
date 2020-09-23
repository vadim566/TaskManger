
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

#define _ACCESS_H
class access:public task
{
public:
	friend class install;
	access(string location, string initDate, string finalDate, string name, int numberOfParticipants=0);
	access(  string initDate, string finalDate, string name, int numberOfParticipants=0);
	access(string location, string initDate, string finalDate, string name);
	access();
	
	void setLocation(string location);
	string getLocation()const { return location; };

	void setNumberOfParticipants(int numberOfParticipants);

	

	
	
	int getNumberOfParticipants()const { return numberOfParticipants; };


	

	 bool isExpiredA(string currentDate) const;
	
	 friend bool isExpired(string currentDate,string fDate);

	access &operator+=(const participant &p);
	 void PrintT(ostream& out)const;

	

	void removeA();
	~access();
	

private:
	
	int numberOfParticipants;
	participant *participantList[MAX_PPL];
	string location;
};

