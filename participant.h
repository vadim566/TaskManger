#pragma once
#include <iostream>
using namespace std;


class participant
{
public:
	participant(string nameP,string lastName ,string organization,string position);
	participant();
	void setName(string nameP);
	string getName()const { return nameP; };

	void setLastName(string lastName);
	string getLastName()const{ return lastName; };

	void setOrganization(string organization);
	string getOrganization()const { return organization; };

	void setPosition(string poistion);
	string getPosition()const { return position; };

	void removeP();

	

private:
	string nameP;
	string lastName;
	string organization;
	string position;

};

