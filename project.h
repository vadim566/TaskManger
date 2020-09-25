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
/*
class project
info about the class:project
{this class can Bind into it a set of tasks according to the participant's input
and actually allow the user access to functions that give an overall view of the project.}
abstract class: N
derived class: N
privet parameters in the class:
  string projectName - the name of the project
int totalProjectTask - total tasks in the project
task** taskList - task list
int indexTask - index of each task
*/
class project
{
public:
	project();
	project(int totalProjectTask,string projectName);

	project(int totalProjectTask);


	void setTotalProjectTask(int totalProjectTask)throw(int); /*set the project total tasks*/
	int getTotalProjectTask()const { return totalProjectTask; }; 

	void setProjectTasks(int totalProjectTask); /*set the project tasks*/
	
	
	void setIndexTask()throw(int); /*set the index of each task*/
	int getIndexTask()const { return indexTask; };

	void setProjectName(string projectName)throw(string); /*set the project name*/
	string getProjectName()const { return projectName; };

	int searchlist(int taskNumber); /*search if the task is at the task list*/
	void printInfo()throw(string); /*this function print the information of the project*/

	void printInfo(int i); /*print the index of each task*/

	/*operator +=*/
	void operator+=(task& other)
	{
		this->setIndexTask();  
		if (this->totalProjectTask > this->getIndexTask())
		{
			this->taskList[this->getIndexTask()] = &other;
		}

	}
	/*operator -=*/
	void operator-=(int other)
	{
		if (this->taskList[other])
		{
			delete this->taskList[other];
			this->taskList[other] = NULL;
			setIndexTask();
		}

	}
	//Distractor
    ~project();

private:
	string projectName;/*the name of the project*/
	int totalProjectTask; /*total tasks in the project*/
	task **taskList; /*task list*/
	int indexTask; /*index of each task*/
};

