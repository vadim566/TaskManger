#ifndef STD_LIB
#define STD_LIB
#include<fstream>
#include<istream>

#include <iostream>
#include <string>
using namespace std;

#endif // !STD_LIB
 
#define _RESOURCE_H
class resource
{
public:
	//Constracturs 
	resource(string nameOfResource,string unit,double amountOfResource);
	resource();

	//Set Methods
	void setNameOfResource(string nameOfResource);
	void setUnit(string unit);
	void setAmountOfResource(double amountOfResource);

	//Get Methods
	string getNameOfResource()const {	return nameOfResource;};
	double getAmountOfResource()const { return amountOfResource; };
	string getUnit()const {return unit;};

	//Print function
	void printR()const;

	//Distractors
	void removeR();
	~resource();


private:
	double amountOfResource;
	string nameOfResource;
	string unit;

};

