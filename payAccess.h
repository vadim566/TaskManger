#ifndef _ACCESS_H
#define _ACCESS_H
#include "access.h"
#endif // !_ACCESS_H

#define _PAYACC_H
class payAccess:public access
{
public:
	payAccess( string currency, string location, int numberOfParticipants, string initDate, string finalDate, string name, int amountOfCurrency = 1);
	payAccess();
	


	void setAmountOfCurrency(int amountOfCurrency );
	int getAmountOfCurrency()const { return amountOfCurrency; };

	void setCurrency(string currency);
	string getCurrency()const { return currency; };

	virtual void PrintT(ostream& out)const;

	void removePA();
	~payAccess();

private:
	int amountOfCurrency;
	string currency;

};
