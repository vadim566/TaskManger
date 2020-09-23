
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

#ifndef _PAYACC_H
#define _PAYACC_H
#include "payAccess.h"
#endif // !_PAYACC_H

#ifndef _PART_H
#define _PART_H
#include "participant.h"
#endif // !_PART_H

#ifndef  _RESOURCE_H
#define _RESOURCE_H
#include "resource.h"
#endif // ! _RESOURCE_H



int main()
{
	task *process[4];

	process[0] = new access("israel", "23 / 09 / 2020", "25 / 09 / 2020", "RFI",2);
	
	
	process[1] = new access("israel", "26 / 09 / 2020", "30 / 09 / 2020", "kickoff", 2);
	process[2] = new payAccess("NIS", "israel", 2, "12 / 10 / 2020", "14 / 10 / 2020", "pdr", 2000);
	process[3] = new install(3, true, "15 / 10 / 2020", "30 / 10 / 2020", "installation of the component");
		process[1]->PrintT(cout);
	process[2]->PrintT(cout);
	process[3]->PrintT(cout);
	

	process[0]->PrintT(cout);

	project *summerCpp;
	summerCpp = new project(4);
	




}