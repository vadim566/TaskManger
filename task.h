/*task.h*/

#ifndef STD_LIB
#define STD_LIB
#include<fstream>
#include<istream>

#include <iostream>
#include <string>
#include<ctime>
using namespace std;

#endif // !STD_LIB



#define _TASK_H
/*
class task
info about the class:task{this class contain information about the start of the task ,the end of the task and the name of the task}
abstract class: Y
derived class: N
child class of:
privet parameters in the class:
   string initDate - start of the task
   string finalDate - end of the task
   string name - name of the task
   const int numberTask - the number of the task
   static int taskCt - how many tasks

*/


class task
{
public:
	//Constracturs 
	task(string initDate,string finalDate,string name); 
	task();
	
	//Set Methods
	void setName(string name)throw(string);/*set the name of the task*/
	void setInitDate(string initDate)throw(string);//set initate date of a task
	void setFinalDate(string finalDate)throw(string);//set final date of a task

	//Get Methods
	string getName()const { return name; };
	string getInitDate()const { return initDate; };
	string getFinalDate()const { return finalDate; };
	int getNumberOfTask()const { return numberTask; };
	static int getTaskCt(){ return taskCt; };


	bool isExpiredA(string currentDate) const; /*chek if the task final date is expired*/

	//Virtual Methods
	virtual void PrintT(ostream& out)const  = 0;/*it is a virtual printing function,not working for this class*/

	//operators
	/*print operator*/
	friend ostream& operator<<(ostream& out, const task& ain)
	{
		out << "\nName of Task: "<<ain.getName();
		return out;
	}

	/*operator ==*/
	virtual bool operator==(const task& ain)
	{
		if (getInitDate() == ain.getInitDate() && getFinalDate() == ain.getFinalDate() && getName() == ain.getName())
			return true;
		else
			false;

	

	}
	//Distractors
	void removeT();
	~task();
	

private:
	
	string initDate;            /*start of the task*/
	string finalDate;           /*end of the task*/
	string name;                /*name of the task*/
	const int numberTask;       /* the number of the task*/
	static int taskCt;          /*how many tasks*/
};


