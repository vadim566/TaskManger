#ifndef _TASK_H
#define _TASK_H
#include "task.h"
#endif // !_TASK_H

#ifndef  _RESOURCE_H
#define _RESOURCE_H
#include "resource.h"
#endif // ! _RESOURCE_H

#ifndef _ACCESS_H
#define _ACCESS_H
#include "access.h"
#endif // !_ACCESS_H


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
	install(int numberOfResource, bool test, string initDate, string finalDate, string name);
	install(bool test, string initDate, string finalDate, string name);
	install(int numberOfResource, string initDate, string finalDate, string name);
	install();
	


	void setNumberOfResource(int numberOfResource);
	int getNumberOfResource()const { return numberOfResource; };
	
	void setTestInclude(bool testInclude);
	bool getTestInclude() const{ return testInclude; };

	
	install &operator+=(const resource &r);
	virtual void PrintT(ostream& out)const;
	friend bool isExpired(string currentDate, string fDate);


	void removeI();
	~install();
	
	
private:
	bool testInclude;
	int numberOfResource;
	resource *resourceList[MAX_AMOUNT_RESOURCE];
};

