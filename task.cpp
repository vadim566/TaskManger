#include "task.h"

int task::taskCt = 10000;

task::task(string initDate, string finalDate, string name):numberTask(taskCt++)
{
	setInitDate(initDate);
	setFinalDate(finalDate);
	setName(name);
}

task::task() :numberTask(taskCt++) 
{
	setInitDate("1/1/1900");
	setFinalDate("30/1/1900");
	setName("Pray for Peace");
}

void task::setName(string name)
{
	this->name = name;
}

void task::setInitDate(string initDate)//set initate date of a task
{
	this->initDate = initDate;
}

void task::setFinalDate(string finalDate)//set final date of a task
{
	this->finalDate = finalDate;
}

void task::removeT()
{
	delete this;
}

task::~task()
{
	this->removeT();
}


