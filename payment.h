#ifndef _MEETING_H
#define _MEETING_H
#include "meeting.h"
#endif // !_MEETING_H
#ifndef STD_LIB
#define STD_LIB
#include<fstream>
#include<istream>

#include <iostream>
#include <string>
using namespace std;

#endif // !STD_LIB
#define _PAYMENT_H

/*
class payment
info about the class:payment{this class contain information about a ameeting that in that neeting it needed to get pay}
abstract class: N
derived class: Y
child class of: meetinng and task
privet parameters in the class:
   int amountOfCurrency - how much money needed
   string currency - the type of the currency

*/
class payment:public meeting
{
public:
	//Constracturs 
	payment( string currency, string location, int numberOfParticipants, string initDate, string finalDate, string name, int amountOfCurrency = 1);
	payment();
	
	//Set Methods
	void setAmountOfCurrency(int amountOfCurrency )throw(int);
	void setCurrency(string currency);

	//Get Methods
	int getAmountOfCurrency()const { return amountOfCurrency; };
	string getCurrency()const { return currency; };

	//Virtual Method
	virtual void PrintT(ostream& out)const;

	//Distractors 
	void removePA();
	~payment();

private:
	int amountOfCurrency;
	string currency;

};
