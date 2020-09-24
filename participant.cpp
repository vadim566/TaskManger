#include "participant.h"


participant::participant(string nameP, string lastName, string organization, string position)
{
	setName(nameP);
	setLastName(lastName);
	setOrganization(organization);
	setPosition(position);
}

participant::participant()
{
	setName("Mario");
	setLastName("Mario");
	setOrganization("Lala Land");
	setPosition("Hero");
}

void participant::setName(string nameP)throw(string)
{
	if (name == "") throw "Name is Empty String";
	if (name == nullptr) throw "Name is Null";
	if (std::string::npos != name.find_first_of("0123456789"))
		throw "Name Contains Digit";
	this->nameP = nameP;
}

void participant::setLastName(string lastName)throw(string)
{
	if (name == "") throw "last Name is Empty String";
	if (name == nullptr) throw "last Name is Null";
	if (std::string::npos != name.find_first_of("0123456789"))
		throw "last Name Contains Digit";
	this->lastName = lastName;
}

void participant::setOrganization(string organization)throw(string)
{
	if (name == "") throw "name of the organization is Empty String";
	if (name == nullptr) throw "Name of the organization is Null";
	/*if (std::string::npos != name.find_first_of("0123456789"))
		throw "Name Contains Digit";*/
	this->organization = organization;
}

void participant::setPosition(string position)throw(string)
{
	if (name == "") throw "name of the postion is Empty String";
	if (name == nullptr) throw "Name of the postion is Null";
	this->position = position;
}

void participant::printP()const
{
	cout << "\nName of particpant: " << this->getName();
	cout << "\nLast Name: " << this->getLastName();
	cout << "\nName of the Organization: " << this->getOrganization();
	cout << "\nPosition in the organization: " << this->getPosition();
}

void participant::removeP()
{
	delete this;
}

participant::~participant()
{
	this->removeP();
}


