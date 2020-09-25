#ifndef STD_LIB
#define STD_LIB
#include<fstream>
#include<istream>

#include <iostream>
#include <string>
using namespace std;

#endif // !STD_LIB
 
#define _RESOURCE_H
/*
class resource
info about the class:resource{this class contain data of all the resources needed to install each project}
abstract class: N
derived class: N
privet parameters in the class:
  double amountOfResource - amount of resource
  string nameOfResource - the name of the resource
  string unit - unit name
*/
class resource
{
public:
	//Constracturs 
	resource(string nameOfResource,string unit,double amountOfResource);
	resource();

	//Set Methods
	void setNameOfResource(string nameOfResource)throw(string);   /*set the name of the resource*/
	void setUnit(string unit)throw(string);                       /*set the name of the unit */
	void setAmountOfResource(double amountOfResource)throw(int);  /* set the amount of resources*/

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
	double amountOfResource; /*amount of resource*/
	string nameOfResource;  /*the name of the resource*/
	string unit;           /*unit name*/

};

