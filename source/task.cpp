#include "task.h"

int task::taskCt = 1000;

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

void task::setName(string name)throw(string)
{
	if (name == "") throw "Name is Empty String";
	if (&name == nullptr) throw "Name is Null";
	if (std::string::npos != name.find_first_of("0123456789"))
		throw "Name Contains Digit";
	this->name = name;
}

void task::setInitDate(string initDate)//set initate date of a task
{ 
	if (initDate == "") throw "Date is Empty ";
	if (&initDate == nullptr) throw "Date is Null";
	if (std::string::npos != name.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz`!@#$%^&*()_\+="))
		throw "Date Contains restedricted symbols";
	this->initDate = initDate;
}

void task::setFinalDate(string finalDate)//set final date of a task
{
	
		if (finalDate == "") throw "Date is Empty ";
		if (&finalDate == nullptr) throw "Date is Null";
		if (std::string::npos != name.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz`!@#$%^&*()_\+="))
			throw "Date Contains restedricted symbols";
		
	this->finalDate = finalDate;
}

void task::removeT()
{
	delete this;
}



task::~task()
{

}


