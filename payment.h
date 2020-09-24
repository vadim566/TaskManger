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

class payment :public meeting
{
public:
@ - 21, 22 + 34, 22 @@ public:
	payment();

	//Set Methods
	void setAmountOfCurrency(int amountOfCurrency)throw(int);
	void setCurrency(string currency);
	void setAmountOfCurrency(int amountOfCurrency)throw(int); /*set how much money needed*/
	void setCurrency(string currency);                        /*set the type of the currency*/

	//Get Methods
	int getAmountOfCurrency()const { return amountOfCurrency; };
	string getCurrency()const { return currency; };

	//Virtual Method
	virtual void PrintT(ostream& out)const;
	virtual void PrintT(ostream& out)const; /*it is a virtual printing function, not working for this class*/

	//Distractors 
	void removePA();
	~payment();

private:
	int amountOfCurrency;
	string currency;
	int amountOfCurrency; /*how much money needed*/
	string currency; /*the type of the currency*/

};