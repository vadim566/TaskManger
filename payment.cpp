#include "payment.h"

payment::payment(string initDate, string finalDate, string name, string currency, string location, int numberOfParticipants, int amountOfCurrency ):meeting(    initDate,  finalDate,  name, location, numberOfParticipants)
{
	this->setCurrency(currency);
	this->setAmountOfCurrency(amountOfCurrency);
}

payment::payment():meeting()
{
	this->setCurrency("NIS");
	this->setAmountOfCurrency(1);
}
/*set how much money needed and check if the payment is ok*/
void payment::setAmountOfCurrency(int amountOfCurrency)
{
	if (amountOfCurrency < 0)
		throw amountOfCurrency;/*checking if the amount of currency is logic or real*/
	this->amountOfCurrency = amountOfCurrency;
}
/*set the type of the currency*/
void payment::setCurrency(string currency)
{
	this->currency = currency;
}
/*print the information of the meeting - amount of money needed to pay*/
void payment::PrintT(ostream & out) const
{
	meeting::PrintT(cout);
	cout <<"\nThe amount of money that need to pay:"<<getAmountOfCurrency() <<" "<< getCurrency()<<endl;
	
}
payment& payment::operator=(const payment & other)
{
	((meeting*)this)->operator=(other);
	this->setAmountOfCurrency(other.getAmountOfCurrency());
	this->setCurrency(other.getCurrency());

	return *this;
}
/*free meeting allocation*/
void payment::removePA()
{
	meeting::removeA();
}
/*free payment alloction*/
payment::~payment()
{
	this->removePA();
}
