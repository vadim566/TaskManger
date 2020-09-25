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
/* set name of the participant and check if the name is logic*/
void participant::setName(string nameP)throw(string)
{
	if (nameP == "") throw "Name is Empty String"; /*check if the name is empty*/
	if (&nameP == nullptr) throw "Name is Null";  /*check if the name is null*/
	if (std::string::npos != nameP.find_first_of("0123456789")) /*check if the name contain digits*/
		throw "Name Contains Digit";
	this->nameP = nameP;
}
/*set last name of the participant and check if the name is logic*/
void participant::setLastName(string lastName)throw(string)
{
	if (lastName == "") throw "last Name is Empty String";/*check if the last name is empty*/
	if (&lastName == nullptr) throw "last Name is Null";/*check if the last name is null*/
	if (std::string::npos != lastName.find_first_of("0123456789"))/*check if the last name contain digits*/
		throw "last Name Contains Digit";
	this->lastName = lastName;
}
/* set name of the Organization and check if the name is logic*/
void participant::setOrganization(string organization)throw(string)
{
	if (organization == "") throw "name of the organization is Empty String";/*check if the Organization name is empty*/
	if (&organization == nullptr) throw "Name of the organization is Null";/*check if the Organization name is null*/
	/*the Organization name can contain digits*/
	
	this->organization = organization;
}
/* set participant position int the Organization and check if the name is logic*/
void participant::setPosition(string position)throw(string)
{
	if (position == "") throw "name of the postion is Empty String";/*check if the postion is empty*/
	if (&position == nullptr) throw "Name of the postion is Null"; /*check if the postion is null*/
	this->position = position;
}
/*print the information of the participant -
name of the participant,last name,organiztion name,Position in the organization*/
void participant::printP()const
{
	cout << "\nName of particpant: " << this->getName();
	cout << "\nLast Name: " << this->getLastName();
	cout << "\nName of the Organization: " << this->getOrganization();
	cout << "\nPosition in the organization: " << this->getPosition();
}
/*free alloction*/
void participant::removeP()
{
	delete this;
}

participant::~participant()
{
	this->removeP();
}


