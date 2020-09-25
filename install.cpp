#include "install.h"




install::install(string initDate, string finalDate, string name, int numberOfResource, bool test):task(initDate, finalDate, name)
{
	this->setNumberOfResource(numberOfResource);
	this->setTestInclude(test);
}

install::install(string initDate, string finalDate, string name, bool test) :task(initDate, finalDate, name)
{
	this->setNumberOfResource(0);
	this->setTestInclude(test);
	
}

install::install(string initDate, string finalDate, string name, int numberOfResource) :task(initDate, finalDate, name)
{
	this->setNumberOfResource(numberOfResource);
	this->setTestInclude(0);
}

install::install():task()
{
	this->setNumberOfResource(0);
	this->setTestInclude(0);
	
}

/*
set number of the resources 
and check if th number of resources is logic
*/
void install::setNumberOfResource(int numberOfResource=0)throw(int)
{
	if (numberOfResource < 1)
		throw numberOfResource;
	string tmp;
	double tmp1 = 0.0;
	cout << "For task number: " << this->getNumberOfTask() << "\nenter details about the resources.";  /*enter details about the resources*/
		this->numberOfResource = numberOfResource;
		int i = 0;
		for (; i < numberOfResource; i++)
		{
			this->resourceList[i] = new resource;

			cout << "\nEnter details of resource number "<<i+1<<"\nEnter Name of Resource: ";  /*enter name of resources*/
			cin >> tmp;
			this->resourceList[i]->setNameOfResource(tmp);

			cout << "\nEnter unit of mesure: ";  
			cin >> tmp;
			this->resourceList[i]->setUnit(tmp);

			cout << "\nEnter amount of unit of the resource: ";
			cin >> tmp1;
			this->resourceList[i]->setAmountOfResource(tmp1);
		}

}

/*if in the installation included also test */
void install::setTestInclude(bool testInclude)throw(string)
{
	if (testInclude != 0 && testInclude != 1)throw("Bad bool value"); /*check if the value is correct*/
	this->testInclude = testInclude;
}

//operators
install & install::operator+=(const resource & r)
{
	if(this->getNumberOfResource()+1>MAX_AMOUNT_RESOURCE)
		cout << "Too many Resource in the install" << endl;

	else
	{
		this->resourceList[getNumberOfResource() + 1]->setAmountOfResource(r.getAmountOfResource());
		this->resourceList[getNumberOfResource() + 1]->setNameOfResource(r.getNameOfResource());
		this->resourceList[getNumberOfResource() + 1]->setUnit(r.getUnit());
	}
	return *this;
}

install & install::operator=(const install & other)
{
	this->operator=&other;
	this->numberOfResource = (other.getNumberOfResource());
	
	for (int i = 0; i < this->numberOfResource; i++)
	{
		this->resourceList[i] = new resource(other.resourceList[i]->getNameOfResource(), other.resourceList[i]->getUnit(), other.resourceList[i]->getAmountOfResource());
		

	}
	// TODO: insert return statement here
}

/*print the information of the install -
name of the install,initial date,final date,number of resources*/
void install::PrintT(ostream& out)const
{
	cout << "\n\nThe name of the install:" << this->getName();
	cout << "\nThe initial date of install:" << this->getInitDate();
	cout << "\nThe final date of install:" << this->getFinalDate();
	cout << "\nThere are " << this->getNumberOfResource() << " in the installation";
	int i = 0;
	for (; i < getNumberOfResource(); i++)
	{
		this->resourceList[i]->printR();
	}
}


/*free alloction*/
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

