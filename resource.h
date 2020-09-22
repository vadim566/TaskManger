#ifndef STD_LIB
#define STD_LIB

#include <iostream>
#include <string>
using namespace std;

#endif // !STD_LIB
 
#define _RESOURCE_H
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


	void printR()const;
	void removeR();
	~resource();


private:
	double amountOfResource;
	string nameOfResource;
	string unit;

};

