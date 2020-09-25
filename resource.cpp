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

/*set the name of the resource,check if the name is logic */
void resource::setNameOfResource(string nameOfResource)throw(string)
{
	if (nameOfResource == "") throw "Name is Empty String";/*check if the name is empty*/
	if (&nameOfResource == nullptr) throw "Name is Null";/*check if the name is null*/
		if (std::string::npos != nameOfResource.find_first_of("0123456789"))/*check if the name contain digits*/
			throw "Name Contains Digit"; 
	this->nameOfResource = nameOfResource;
}
/* set the amount of resources,check if the name is logic */
void resource::setAmountOfResource(double amountOfResource)throw(int)
{
	if (amountOfResource < 0)
		throw amountOfResource; /*checking if the amount of resource is logic or real */
	this->amountOfResource = amountOfResource;
}
/*set the name of the unit, check if the name of the unit is real and logic */
void resource::setUnit(string unit)throw(string)
{
	if (unit == "") throw "Unit name is Empty String";/*check if the name is empty*/
	if (&unit == nullptr) throw "Unit name is Null";/*check if the name is null*/
	
	this->unit = unit;
}
/*print the information of the resource -
name of the resource,amount of resources*/
void resource::printR() const
{
	cout << "\n\nName of Resource: " << this->getNameOfResource();
	cout << "\n\namount: " << this->getAmountOfResource()<<" " <<this->getUnit()<<endl;

}
/*free resource allocation*/
void resource::removeR()
{
	delete this;
}

resource::~resource()
{
	
}
