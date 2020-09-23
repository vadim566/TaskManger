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
#define _PAYACC_H
class payment:public meeting
{
public:
	payment( string currency, string location, int numberOfParticipants, string initDate, string finalDate, string name, int amountOfCurrency = 1);
	payment();
	


	void setAmountOfCurrency(int amountOfCurrency );
	int getAmountOfCurrency()const { return amountOfCurrency; };

	void setCurrency(string currency);
	string getCurrency()const { return currency; };

	virtual void PrintT(ostream& out)const;

	void removePA();
	~payment();

private:
	int amountOfCurrency;
	string currency;

};
