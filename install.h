#ifndef _TASK_H
#define _TASK_H
#include "task.h"
#endif // !_TASK_H

#ifndef  _RESOURCE_H
#define _RESOURCE_H
#include "resource.h"
#endif // ! _RESOURCE_H

#ifndef _MEETING_H
#define _MEETING_H
#include "MEETING.h"
#endif // !_MEETING_H


#ifndef STD_LIB
#define STD_LIB

#include <iostream>
#include <string>
using namespace std;

#endif // !STD_LIB

#define MAX_AMOUNT_RESOURCE 10

#define _INSTALL_H

/*
class install
info about the class:install{this class contain information about what needed for instal the object  -  how many and which type of resource needed  }
abstract class: N
derived class: Y
child class of:task
privet parameters in the class:
  bool testInclude - test
  int numberOfResource - number of resource
  resource* resourceList[MAX_AMOUNT_RESOURCE] - Resource reference

*/
class install :public task
{
public:

	//Constracturs 
	install( string initDate, string finalDate, string name, int numberOfResource, bool test);
	install( string initDate, string finalDate, string name, bool test);
	install( string initDate, string finalDate, string name, int numberOfResource);
	install();

	//Set Methods
	void setNumberOfResource(int numberOfResource)throw(int); /*set number of the resources*/
	void setTestInclude(bool testInclude)throw(string);       /*if in the installation included also test */

	//Get Methods
	bool getTestInclude() const { return testInclude; };
	int getNumberOfResource()const { return numberOfResource; };

	//Operators +=
	install& operator+=(const resource& r);

	//Opertator ==
	virtual bool operator==(const task& ing) const
	{
		if (((task*)this)->operator==(ing) == false) {
			return false;
		}
		const install* meet = dynamic_cast<const install*>(&ing);
		if (meet->getTestInclude() == this->getTestInclude() && meet->getNumberOfResource() == this->getNumberOfResource())
		{
			return true;
		}
		else return false;
	}


	//Virtual Methods
	virtual void PrintT(ostream& out)const; /*it is a virtual printing function, not working for this class*/



	//Distractors 
	void removeI();
	~install();


private:
	bool testInclude;                            /*test*/
	int numberOfResource;                        /*number of resource*/
	resource* resourceList[MAX_AMOUNT_RESOURCE]; /*Resource reference*/
};

