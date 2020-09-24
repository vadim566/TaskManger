
#ifndef  _PROJECT_H
#define _PROJECT_H
#include "project.h"
#endif // ! _PROJECT_H

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

#ifndef _INSTALL_H
#define _INSTALL_H
#include "install.h"
#endif // !_INSTALL_H

#ifndef _MEETING_H
#define _MEETING_H
#include "meeting.h"
#endif // !_PAYACC_H

#ifndef _PART_H
#define _PART_H
#include "participant.h"
#endif // !_PART_H

#ifndef  _RESOURCE_H
#define _RESOURCE_H
#include "resource.h"
#endif // ! _RESOURCE_H

#ifndef _PAYMENT_H
#define _PAYMENT_H
#include "payment.h"
#endif
string intDateToStringDate(int day, int month, int year);
int main()
{
	task *process[4];

	process[0] = new meeting("israel", "23 / 09 / 2020", "25 / 09 / 2020", "RFI",2);
	process[1] = new meeting("israel", "26 / 09 / 2020", "30 / 09 / 2020", "kickoff", 2);
	process[2] = new payment("NIS", "israel", 2, "12 / 10 / 2020", "14 / 10 / 2020", "pdr", 2000);
	process[3] = new install(3, true, "15 / 10 / 2020", "30 / 10 / 2020", "installation of the component");




	project *summerCpp;
	summerCpp = new project(4);
	*summerCpp += *process[0];
	*summerCpp += *process[1];
	*summerCpp += *process[2];
	*summerCpp += *process[3];
	//summerCpp->printInfo();
	int index = summerCpp->searchlist(1003);
	summerCpp->printInfo(index);
	*summerCpp -= 2;
	 index = summerCpp->searchlist(1003);
	summerCpp->printInfo(index);


	project *oathCpp, *winterCpp;
	oathCpp = new project(4);
	winterCpp = new project(5);

	*oathCpp += *process[2];
	*oathCpp += *process[4];
	*oathCpp += *process[1];
	*oathCpp += *process[3];


	
	*winterCpp += *process[1];
	*winterCpp += *process[2];
	*winterCpp += *process[4];
	*winterCpp += *process[3];

	
}

string intDateToStringDate(int day, int month, int year)
{
	if (day > 31 || day<1)day = 31;
	if (month > 12 || month <1)month = 12;
	if (year < 1900 || year>2100)year = 2020;


	string dayS = to_string(day);
	string monthS = to_string(month);
	string yearS = to_string(year);
	string brk = " / ";
	string dateS = dayS + brk + monthS + brk + yearS;

	return dateS;
	



}