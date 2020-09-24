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
class install:public task
{
public:

	//Constracturs 
	install(int numberOfResource, bool test, string initDate, string finalDate, string name);
	install(bool test, string initDate, string finalDate, string name);
	install(int numberOfResource, string initDate, string finalDate, string name);
	install();
	
	//Set Methods
	void setNumberOfResource(int numberOfResource)throw(int);
	void setTestInclude(bool testInclude)throw(string);

	//Get Methods
	bool getTestInclude() const{ return testInclude; };
	int getNumberOfResource()const { return numberOfResource; };
	
	//Operators +=
	install &operator+=(const resource &r);

	//Opertator ==
	virtual bool operator==(const task& ing) const
	{
		if (((task*)this)->operator==(ing) == false) {
			return false;
		}
		const install *meet = dynamic_cast<const install*>(&ing);
		if (meet->getTestInclude()==this->getTestInclude() && meet->getNumberOfResource()==this->getNumberOfResource())
		{
			return true;
		}
		else return false;
	}


	//Virtual Methods
	virtual void PrintT(ostream& out)const;

	

	//Distractors 
	void removeI();
	~install();
	
	
private:
	bool testInclude;
	int numberOfResource;
	resource *resourceList[MAX_AMOUNT_RESOURCE];
};

