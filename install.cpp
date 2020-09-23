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
	string tmp;
	double tmp1 = 0.0;
		this->numberOfResource = numberOfResource;
		int i = 0;
		for (; i < numberOfResource; i++)
		{
			this->resourceList[i] = new resource;

			cout << "\nEnter details of resource number "<<i+1<<"nEnter Name of Resource: ";
			cin >> tmp;
			this->resourceList[i]->setNameOfResource(tmp);

			cout << "Enter unit of mesure: ";
			cin >> tmp;
			this->resourceList[i]->setUnit(tmp);

			cout << "Enter amount of unit of the resource: ";
			cin >> tmp;
			this->resourceList[i]->setAmountOfResource(tmp1);
		}

}

void install::setTestInclude(bool testInclude)
{
	this->testInclude = testInclude;
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

