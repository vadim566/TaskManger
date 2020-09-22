#include "project.h"

project::project()
{
	this->setIndexTask();
	this->setTotalProjectTask(0);
	this->setProjectTasks(0);
}

project::project(int totalProjectTask)
{
	this->setIndexTask();
	this->setTotalProjectTask(totalProjectTask);
	this->setProjectTasks(totalProjectTask);
}

void project::setTotalProjectTask(int totalProjectTask)
{
	if (totalProjectTask)
		this->totalProjectTask = totalProjectTask;
}

void project::setProjectTasks(int totalProjectTask)
{
	if (totalProjectTask)
	{
		this->taskList = new task *[totalProjectTask];

		int i = 0;
		for (; i < totalProjectTask; i++)
		{
			this->taskList[i] = NULL;
		}
	}
	else this->taskList = NULL;

}



void project::setIndexTask()
{
	int i = 0;
	for (i = 0; i < this->totalProjectTask; i++)
	{
		if (this->taskList[i] == NULL)
		{

			this->indexTask = i;
			return;
		}
	}
}

int project::searchlist(int taskNumber)
{
	for (int i = 0; i < this->totalProjectTask; i++)
	{
		if (this->taskList[i] && taskNumber == this->taskList[i]->getNumberOfTask()) return i;
	}
	return -1;
	
}

void project::printInfo()
{
	for (int i = 0; i < this->getTotalProjectTask(); i++)
	{
		if (this->taskList[i])
			this->taskList[i]->PrintT(cout);

	}
}

project::~project()
{
	for (int i = 0; i < this->getTotalProjectTask(); i++)
	{
		if(this->taskList[i])
			this->taskList[i]->removeT();
	}
	delete[] this->taskList;
}
