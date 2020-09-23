#include "payment.h"

payment::payment(string currency, string location, int numberOfParticipants, string initDate, string finalDate, string name, int amountOfCurrency):meeting( location,   initDate,  finalDate,  name, numberOfParticipants)
{
	this->setCurrency(currency);
	this->setAmountOfCurrency(amountOfCurrency);
}

payment::payment():meeting()
{
	this->setCurrency("NIS");
	this->setAmountOfCurrency(1);
}

void payment::setAmountOfCurrency(int amountOfCurrency)
{
	this->amountOfCurrency = amountOfCurrency;
}

void payment::setCurrency(string currency)
{
	this->currency = currency;
}

void payment::PrintT(ostream & out) const
{
	meeting::PrintT(cout);
	cout <<"\nThe amount of money that need to pay:"<<getAmountOfCurrency() <<" "<< getCurrency()<<endl;
	
}

void payment::removePA()
{
	meeting::removeA();
}

payment::~payment()
{
	this->removePA();
}
