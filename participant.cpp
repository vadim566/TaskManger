#include "participant.h"
#pragma once

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

void participant::removeP()
{
	delete this;
}

