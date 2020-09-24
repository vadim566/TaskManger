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

void resource::setNameOfResource(string nameOfResource)throw(string)
{
	if (name == "") throw "Name is Empty String";
	if (name == nullptr) throw "Name is Null";
		if (std::string::npos != name.find_first_of("0123456789"))
			throw "Name Contains Digit"; 
	this->nameOfResource = nameOfResource;
}

void resource::setAmountOfResource(double amountOfResource)throw(int)
{
	if (amountOfResource < 0)
		throw amountOfResource;
	this->amountOfResource = amountOfResource;
}

void resource::setUnit(string unit)throw(string)
{
	if (name == "") throw "Name is Empty String";
	if (name == nullptr) throw "Name is Null";
		if (std::string::npos != name.find_first_of("0123456789"))    /*i think it can contain dhghts*/
			throw "Name Contains Digit";
	this->unit = unit;
}

void resource::printR() const
{
	cout << "\n\nName of Resource: " << this->getNameOfResource();
	cout << "\n\namount: " << this->getAmountOfResource()<<" " <<this->getUnit()<<endl;

}

void resource::removeR()
{
	delete this;
}

resource::~resource()
{
	
}
