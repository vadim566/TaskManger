#include "access.h"

using namespace std;




access::access(string location, string initDate, string finalDate, string name, int numberOfParticipants):task(initDate,finalDate,name)
{
	
	if (numberOfParticipants > MAX_PPL)
	{
		numberOfParticipants = MAX_PPL;
		cout << "Max participants in access:" << MAX_PPL <<"the value of participant has changed to max value"<< endl;
		
	}
	setNumberOfParticipants(numberOfParticipants);
		this->setLocation(location);
	
	
}

access::access(string initDate, string finalDate, string name, int numberOfParticipants):task(initDate, finalDate, name)
{
	this->setLocation("virtual:VC/ZOOM/Tel");
	setNumberOfParticipants(numberOfParticipants);
	int i = 0;

	
}

access::access(string location, string initDate, string finalDate, string name):task(initDate, finalDate, name)
{
	int numberOfParticipants = 2;
	setNumberOfParticipants(numberOfParticipants);
	this->setLocation(location);
	int i = 0;

}

access::access():task()
{
	this->setLocation("home");
	this->setNumberOfParticipants(0);
}

void access::setLocation(string location)
{
	this->location = location;
}

void access::setNumberOfParticipants(int numberOfParticipants)
{
	string tmp;
	this->numberOfParticipants = numberOfParticipants;
	int i = 0;
	
	for (; i < numberOfParticipants; i++)
	{
		this->participantList[i] = new participant();
		cout << "\nEnter info of particpant number "<<i+1 <<"\nnenter the name of the participant: ";
		cin >> tmp;
		participantList[i]->setName(tmp);
		cout << "enter the name of the last name of participant: ";
		cin >> tmp;
		participantList[i]->setLastName(tmp);
		cout << "enter the name of the organization: ";
		cin >> tmp;
		participantList[i]->setOrganization(tmp);
		cout << "enter the position in the organization: ";
		cin >> tmp;
		participantList[i]->setPosition(tmp);
	}
}



 bool access::isExpiredA(string currentDate)const
{
	string tmpFinal = this->getFinalDate(), tmpCurrent = currentDate;
	string delimiter = " \ ", token0, token1;
	size_t pos0 = 0, pos1 = 0;
	int day[2], month[2], year[2];
	int i = 0;
	while ((pos0 = tmpCurrent.find(delimiter)) != string::npos)//cut the date string and convert into 6 int
	{
		token0 = tmpCurrent.substr(0, pos0);
		token1 = tmpFinal.substr(0, pos1);
		if (i == 0)//first cut off the days
		{
			day[0] = stoi(token0);
			day[1] = stoi(token1);
		}
		if (i == 1)//second cut off the month
		{
			month[0] = stoi(token0);
			month[1] = stoi(token1);

		}
		if (i == 2)//third cut off the year
		{
			year[0] = stoi(token0);
			year[1] = stoi(token1);
		}
		i++;
		tmpCurrent.erase(0, pos0 + delimiter.length());
		tmpFinal.erase(0, pos1 + delimiter.length());
	}

	if (year[0] > year[1])//if current year is higher then final 
		return true;//expired=true
	else
	{
		if (month[0] > month[1])//if current month is higher then final month
			return true;//expired=true
		else
		{
			if (day[0] > day[1])//if current day is higher then final day
				return true;//expired=true
		}



	}

	return false;
}


access & access::operator+=(const participant & p)
{
	if (this->getNumberOfParticipants() + 1 > MAX_PPL)
		cout << "Too many participants in the access" << endl;
	else
	{
		this->participantList[getNumberOfParticipants() + 1]->setName(p.getName());
		this->participantList[getNumberOfParticipants() + 1]->setLastName(p.getLastName());
		this->participantList[getNumberOfParticipants() + 1]->setOrganization(p.getOrganization());
		this->participantList[getNumberOfParticipants() + 1]->setPosition(p.getPosition());
	}
			return *this;
}

 void access::PrintT(ostream& out)const
{
	cout << "\n\nThe name of the access:" << this->getName();
	cout << "\nThe initial date of access:" << this->getInitDate();
	cout << "\nThe final date of access:" << this->getFinalDate();
	cout << "\nThere are " << this->getNumberOfParticipants() << " in the access\n\nThe details of the particpant:";
	int i = 0;
	for (; i < getNumberOfParticipants(); i++)
	{
		cout << "participant number " << i + 1 ;
		this->participantList[i]->printP();
	}

}

void access::removeA()
{
	int i = 0;
	for (; i < this->getNumberOfParticipants(); i++)
	{
		this->participantList[i]->removeP();
	}
	task::removeT();
}

access::~access()
{
	
		this->removeA();
	
}

bool isExpired(string currentDate,string finalDate)
{
	access *tmp;
	bool expired ;
	tmp = new access();
	tmp->setFinalDate (finalDate);
	expired = tmp->isExpiredA(currentDate);
	return expired;
}
