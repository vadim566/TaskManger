#ifndef _MEETING_H
#define _MEETING_H
#include "meeting.h"
#endif // !_MEETING_H
#ifndef _INSTALL_H
#define _INSTALL_H
#include "install.h"
#endif // !_INSTALL_H

#ifndef _PAYMENT_H
#define _PAYMENT_H
#include "payment.h"

#endif // !_PAYMENT_H
#ifndef STD_LIB
#define STD_LIB
#include<fstream>
#include<istream>

#include <iostream>
#include <string>
using namespace std;

#endif // !STD_LIB

#define _PROJECT_H
class project
{
public:
	project();
	project(int totalProjectTask,string projectName);

	project(int totalProjectTask);


	void setTotalProjectTask(int totalProjectTask)throw(int);
	int getTotalProjectTask()const { return totalProjectTask; };

	void setProjectTasks(int totalProjectTask);
	
	
	void setIndexTask()throw(int);
	int getIndexTask()const { return indexTask; };

	void setProjectName(string projectName)throw(string);
	string getProjectName()const { return projectName; };

	int searchlist(int taskNumber);
	void printInfo();

	void printInfo(int i);


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
	string projectName;
	int totalProjectTask;
	task **taskList;
	int indexTask;
};

