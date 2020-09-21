#include "task.h"
#include "resource.h"
#include "access.h"
#include <iostream>
#include <string>
#define MAX_AMOUNT_RESOURCE 10
class install:public task
{
public:
	install();
	~install();


	void setNumberOfResource(int numberOfResource=0);
	int getNumberOfResource()const { return numberOfResource; };
	
	void setTestInclude(bool testInclude);
	bool getTestInclude() const{ return testInclude; };

	void setResourceList(resource *resourceList);
	install &operator+=(const resource &r);
	virtual void PrintT()const;
	
	void removeI();
	~install();
	
	
private:
	bool testInclude;
	int numberOfResource;
	resource *resourceList[MAX_AMOUNT_RESOURCE];
};

