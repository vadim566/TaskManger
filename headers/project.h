

#ifndef _ACCESS_H
#define _ACCESS_H
#include "access.h"
#endif // !_ACCESS_H
#ifndef _INSTALL_H
#define _INSTALL_H
#include "install.h"
#endif // !_INSTALL_H

#ifndef _PAYACC_H
#define _PAYACC_H
#include "payAccess.h"

#endif // !_PAYACC_H
#ifndef STD_LIB
#define STD_LIB
#include<fstream>
#include<istream>

#include <iostream>
#include <string>
using namespace std;

#endif // !STD_LIB


class project
{
public:
	project();
	project(int totalProjectTask);


	void setTotalProjectTask(int totalProjectTask);
	int getTotalProjectTask()const { return totalProjectTask; };

	void setProjectTasks(int totalProjectTask);
	
	
	void setIndexTask();
	int getIndexTask()const { return indexTask; };



	int searchlist(int taskNumber);
	void printInfo();


	void operator+=(task& other)
	{
		this->setIndexTask();
		if (this->totalProjectTask > this->getIndexTask())
		{
			this->taskList[this->getIndexTask()] = &other;
		}

	}
	
	void operator-=(int other)
	{
		if (this->taskList[other])
		{
			delete this->taskList[other];
			this->taskList[other] = NULL;
			setIndexTask();
		}

	}

~project();

private:
	int totalProjectTask;
	task **taskList;
	int indexTask;
};

