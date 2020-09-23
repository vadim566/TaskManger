/*task.h*/

#ifndef STD_LIB
#define STD_LIB
#include<fstream>
#include<istream>

#include <iostream>
#include <string>
using namespace std;

#endif // !STD_LIB



#define _TASK_H

class task
{
public:
	//Constracturs 
	task(string initDate,string finalDate,string name);
	task();
	
	//Set Methods
	void setName(string name);
	void setInitDate(string initDate);
	void setFinalDate(string finalDate);

	//Get Methods
	string getName()const { return name; };
	string getInitDate()const { return initDate; };
	string getFinalDate()const { return finalDate; };
	int getNumberOfTask()const { return numberTask; };
	static int getTaskCt(){ return taskCt; };

	//Virtual Methods
	virtual void PrintT(ostream& out)const  = 0;

	//Distractors
	void removeT();
	~task();

private:
	
	string initDate;
	string finalDate;
	string name;
	const int numberTask;
	static int taskCt;
};


