#include <iostream>

using namespace std;

class resource
{
public:
	resource(string nameOfResource,string unit,double amountOfResource);
	resource();

	void setNameOfResource(string nameOfResource);
	string getNameOfResource()const {	return nameOfResource;};

	void setAmountOfResource(double amountOfResource);
	double getAmountOfResource()const { return amountOfResource; };

	void setUnit(string unit);
	string getUnit()const {return unit;};

	void removeR();

private:
	double amountOfResource;
	string nameOfResource;
	string unit;

};

