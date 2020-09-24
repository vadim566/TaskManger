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
	if (this->isExpiredA(initDate)) throw "final date expired";
		
}



bool task::isExpiredA(string currentDate) const
{
	string tmpFinal = this->getFinalDate(), tmpCurrent = currentDate;
	string delimiter = " \ ", token0, token1;
	size_t pos0 = 0, pos1 = 0;
	int day[2], month[2], year[2];
	int i = 0;
	while ((pos0 = tmpCurrent.find(delimiter)) != string::npos)//cut the date string and convert into 6 int
	{
		token0 = tmpCurrent.substr(0, pos0);
		token1 = tmpFinal.substr(0, pos1);
		if (i == 0)//first cut off the days
		{
			day[0] = stoi(token0);
			day[1] = stoi(token1);
		}
		if (i == 1)//second cut off the month
		{
			month[0] = stoi(token0);
			month[1] = stoi(token1);

		}
		if (i == 2)//third cut off the year
		{
			year[0] = stoi(token0);
			year[1] = stoi(token1);
		}
		i++;
		tmpCurrent.erase(0, pos0 + delimiter.length());
		tmpFinal.erase(0, pos1 + delimiter.length());
	}

	if (year[0] > year[1])//if current year is higher then final 
		return true;//expired=true
	else
	{
		if (month[0] > month[1])//if current month is higher then final month
			return true;//expired=true
		else
		{
			if (day[0] > day[1])//if current day is higher then final day
				return true;//expired=true
		}



	}

	return false;
	return false;
}//bool is expiredA - reciving a string in format of  "DD / MM / YY" and checking if the object final date is expired, out TRUE if expired FALSE if not expired

void task::removeT()
{
	delete this;
}



task::~task()
{

}


