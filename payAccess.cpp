#include "payAccess.h"

payAccess::payAccess(string currency, string location, int numberOfParticipants, string initDate, string finalDate, string name, int amountOfCurrency):access( location,   initDate,  finalDate,  name, numberOfParticipants)
{
	this->setCurrency(currency);
	this->setAmountOfCurrency(amountOfCurrency);
}

payAccess::payAccess():access()
{
	this->setCurrency("NIS");
	this->setAmountOfCurrency(1);
}

void payAccess::setAmountOfCurrency(int amountOfCurrency)
{
	this->amountOfCurrency = amountOfCurrency;
}

void payAccess::setCurrency(string currency)
{
	this->currency = currency;
}

void payAccess::PrintT(ostream & out) const
{
	access::PrintT(cout);
	cout << getAmountOfCurrency() << " " << getCurrency();
	
}

void payAccess::removePA()
{
	access::removeA();
}

payAccess::~payAccess()
{
	this->removePA();
}
