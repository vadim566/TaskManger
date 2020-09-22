/*task.h*/

#ifndef STD_LIB
#define STD_LIB

#include <iostream>
#include <string>
using namespace std;

#endif // !STD_LIB


#define _TASK_H

class task
{
public:
	//constructors
	task(string initDate,string finalDate,string name);
	task();
	
	//get set name
	void setName(string name);
	string getName()const { return name; };

	//get set initDate of a task
	void setInitDate(string initDate);
	string getInitDate()const { return initDate; };

	//get set finalDate of a task
	void setFinalDate(string finalDate);
	string getFinalDate()const { return finalDate; };

	//get unique number of task
	int getNumberOfTask()const { return numberTask; };
	
	//get total count of task in the system
	static int getTaskCt(){ return taskCt; };


	//pure virtual print
	virtual void PrintT(ostream& out)const  = 0;

	//remover
	void removeT();

	~task();

private:
	
	string initDate;
	string finalDate;
	string name;
	const int numberTask;
	static int taskCt;
};


