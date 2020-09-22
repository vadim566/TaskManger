#include "install.h"





install::install(int numberOfResource, bool test, string initDate, string finalDate, string name):task(initDate, finalDate, name)
{
	this->setNumberOfResource(numberOfResource);
	this->setTestInclude(test);
}

install::install(bool test, string initDate, string finalDate, string name) :task(initDate, finalDate, name)
{
	this->setNumberOfResource(0);
	this->setTestInclude(test);
	
}

install::install(int numberOfResource, string initDate, string finalDate, string name) :task(initDate, finalDate, name)
{
	this->setNumberOfResource(numberOfResource);
	this->setTestInclude(0);
}

install::install():task()
{
	this->setNumberOfResource(0);
	this->setTestInclude(0);
	
}


void install::setNumberOfResource(int numberOfResource=0)
{
		this->numberOfResource = numberOfResource;
		int i = 0;
		for (; i < numberOfResource; i++)
		{
			setResourceList(this->resourceList[i]);
		}

}

void install::setTestInclude(bool testInclude)
{
	this->testInclude = testInclude;
}

void install::setResourceList(resource * resourceList)
{
	string tmp;
	double tmp1=0.0;
	resourceList = NULL;
	resourceList = new resource;

	cout << "\n\nEnter Name of Resource: ";
	cin >> tmp;
	resourceList->setNameOfResource(tmp);

	cout << "Enter unit of mesure: ";
	cin >> tmp;
	resourceList->setUnit(tmp);

	cout << "Enter amount of unit of the resource: ";
	cin >> tmp;
	resourceList->setAmountOfResource(tmp1);

}
install & install::operator+=(const resource & r)
{
	if(this->getNumberOfResource()+1>MAX_AMOUNT_RESOURCE)
		cout << "Too many Resource in the install" << endl;

	else
	{
		this->setResourceList(this->resourceList[getNumberOfResource()]);
	}
	return *this;
}

void install::PrintT(ostream& out)const
{
	cout << "\n\nThe name of the install:" << this->getName();
	cout << "The initial date of access:" << this->getInitDate();
	cout << "The final date of access:" << this->getFinalDate();
	cout << "There are " << this->getNumberOfResource() << "in the installation";
	int i = 0;
	for (; i < getNumberOfResource(); i++)
	{
		this->resourceList[i]->printR();
	}
}



void install::removeI()
{
	int i = 0;
	for (; i < this->getNumberOfResource(); i++)
	{
		this->resourceList[i]->removeR();
	}
	task::removeT();
}




install::~install()
{
	removeI();
}

