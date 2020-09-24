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

/*calass dectionary
1.name of the class:
2.description of the class:
3.function in the class:
 3.1 input meaning of the input, output , meaning output
 3.2 virtual void printT - is  a virtual 
*/
class task
{
public:
	//Constracturs 
	task(string initDate,string finalDate,string name);
	task();
	
	//Set Methods
	void setName(string name)throw(string);
	void setInitDate(string initDate)throw(string);
	void setFinalDate(string finalDate)throw(string);

	//Get Methods
	string getName()const { return name; };
	string getInitDate()const { return initDate; };
	string getFinalDate()const { return finalDate; };
	int getNumberOfTask()const { return numberTask; };
	static int getTaskCt(){ return taskCt; };


	bool isExpiredA(string currentDate) const;

	//Virtual Methods
	virtual void PrintT(ostream& out)const  = 0;

	//operators
	//print operator
	friend ostream& operator<<(ostream& out, const task& ain)
	{
		out << "\nName of Task: "<<ain.getName();
		return out;
	}
	/*==*/
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
	string name;                /*the name of the task*/
	const int numberTask;       /*the number of the tasks*/
	static int taskCt;          /*how many tasks*/
};


