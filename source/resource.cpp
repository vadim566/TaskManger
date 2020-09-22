#include "resource.h"



resource::resource(string nameOfResource, string unit, double amountOfResource)
{
	setNameOfResource(nameOfResource);
	setUnit(unit);
	setAmountOfResource(amountOfResource);
}

resource::resource()
{
	setNameOfResource("Tech");
	setUnit("hour");
	setAmountOfResource(1.0);

}

void resource::setNameOfResource(string nameOfResource)
{
	this->nameOfResource = nameOfResource;
}

void resource::setAmountOfResource(double amountOfResource)
{
	this->amountOfResource = amountOfResource;
}

void resource::setUnit(string unit)
{
	this->unit = unit;
}

void resource::printR() const
{
	cout << "Name of Resource: " << this->getNameOfResource();
	cout << "amount: " << this->getAmountOfResource()<<" " <<this->getUnit()<<endl;

}

void resource::removeR()
{
	delete this;
}

resource::~resource()
{
	this->removeR();
}
