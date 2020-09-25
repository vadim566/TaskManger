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

void participant::setName(string nameP)
{
	this->nameP = nameP;
}

void participant::setLastName(string lastName)
{
	this->lastName = lastName;
}

void participant::setOrganization(string organization)
{
	this->organization = organization;
}

void participant::setPosition(string poistion)
{
	this->position = position;
}

void participant::printP()const
{
	cout << "Name of particpant: " << this->getName();
	cout << "Last Name: " << this->getLastName();
	cout << "Name of the Organization: " << this->getOrganization();
	cout << "Position in the organization: " << this->getPosition();
}

void participant::removeP()
{
	delete this;
}

participant::~participant()
{
	this->removeP();
}


