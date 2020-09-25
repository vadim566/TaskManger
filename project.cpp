#include "project.h"

project::project()
{
	this->setProjectName("default");
	this->setIndexTask();
	this->setTotalProjectTask(0);
	this->setProjectTasks(0);
}

project::project(int totalProjectTask,string projectName)
{
	this->setProjectName(projectName);
	this->setIndexTask();
	this->setTotalProjectTask(totalProjectTask);
	this->setProjectTasks(totalProjectTask);
}
 
project::project(int totalProjectTask)
{
	this->setProjectName("default");
	this->setProjectName(projectName);
	this->setIndexTask();
	this->setTotalProjectTask(totalProjectTask);
	this->setProjectTasks(totalProjectTask);
}
/*set the project total tasks,check if the total check is logic*/
void project::setTotalProjectTask(int totalProjectTask)throw(int)
{
	if (totalProjectTask < 0)
		throw totalProjectTask;/*check if the total check is logic*/
	if (totalProjectTask)
		this->totalProjectTask = totalProjectTask;
}

/*set the project tasks*/
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


/*set the index of each task*/
void project::setIndexTask()throw(int)
{
	int i = 0;
	for (i = 0; i < this->totalProjectTask; i++)
	{
		if (this->taskList[i] == NULL)
		{

			this->indexTask = i;
			return;
		}
		if((indexTask<0)||(indexTask>totalProjectTask))throw(indexTask);
	}
}

/*set the project name, check if the name of the project is logic*/
void project::setProjectName(string projectName)throw(string)
{
	if (projectName == "") throw "Name of the project is Empty String"; /*check if the name is empty*/
	if (&projectName == nullptr) throw "Name of the project is Null"; /*check if the name is null*/
	
	this->projectName = projectName;
}


/*search if the task is at the task list*/
int project::searchlist(int taskNumber)
{
	for (int i = 0; i < this->getIndexTask()+1; i++)
	{
		if (this->taskList[i] && taskNumber == this->taskList[i]->getNumberOfTask()) return i;
	}
	cout << "\nThere is no such a task!" << endl;  /*if there is no task like the user insert */
	return -1;
	
}

/*this function print the information of the project*/
void project::printInfo()throw(string)
{
	cout << "\n************************************************************************\n\nProject " << this->getProjectName() << ", info of the tasks";
	
	for (int i = 0; i < this->getIndexTask(); i++)
	{
		
		if (this->taskList[i])
		{
			cout << "\n-----------------------------------------------------------------------------\n";
			cout << "\nTask number: " << i + 1 << ",the id of the task is: " << this->taskList[i]->getNumberOfTask() << endl;
		
			this->taskList[i]->PrintT(cout);
			cout << "\n-----------------------------------------------------------------------------\n";
		}
		else
		{
			cout << "\nThere is no such a task!" << endl;
		}
		

	}
	cout << "\n************************************************************************\n";
}

/*print the index of each task*/
void project::printInfo(int i)
{


		if (this->taskList[i]  && i>=0)
		{
			cout << "\n-----------------------------------------------------------------------------\n";
			cout << "\nTask number: " << i + 1 << ",the id of the task is: " << this->taskList[i]->getNumberOfTask() << endl;
			this->taskList[i]->PrintT(cout);
			cout << "\n-----------------------------------------------------------------------------\n";
		}


}

/*Distractor and free alloction*/
project::~project()
{
	for (int i = 0; i < this->getTotalProjectTask(); i++)
	{
		if(this->taskList[i])
			this->taskList[i]->removeT();
	}
	delete[] this->taskList;
}
