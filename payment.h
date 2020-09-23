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
class payment:public meeting
{
public:
	//Constracturs 
	payment( string currency, string location, int numberOfParticipants, string initDate, string finalDate, string name, int amountOfCurrency = 1);
	payment();
	
	//Set Methods
	void setAmountOfCurrency(int amountOfCurrency );
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
