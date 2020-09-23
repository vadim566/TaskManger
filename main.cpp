
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
	summerCpp->printInfo();
	
}