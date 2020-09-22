#include "access.h"

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
