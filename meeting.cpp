#include "meeting.h"

using namespace std;




meeting::meeting(string location, string initDate, string finalDate, string name, int numberOfParticipants):task(initDate,finalDate,name)
{
	
	if (numberOfParticipants > MAX_PPL)
	{
		numberOfParticipants = MAX_PPL;
		cout << "Max participants in meeting:" << MAX_PPL <<"the value of participant has changed to max value"<< endl;
		
	}
	setNumberOfParticipants(numberOfParticipants);
		this->setLocation(location);
	
	
}

meeting::meeting(string initDate, string finalDate, string name, int numberOfParticipants):task(initDate, finalDate, name)
{
	this->setLocation("virtual:VC/ZOOM/Tel");
	setNumberOfParticipants(numberOfParticipants);
	int i = 0;

	
}

meeting::meeting(string location, string initDate, string finalDate, string name):task(initDate, finalDate, name)
{
	int numberOfParticipants = 2;
	setNumberOfParticipants(numberOfParticipants);
	this->setLocation(location);
	int i = 0;

}

meeting::meeting():task()
{
	this->setLocation("home");
	this->setNumberOfParticipants(0);
}

void meeting::setLocation(string location)throw(string)
{
	if (location == "") throw "loction  is Empty String";
	if (&location == nullptr) throw "loction is Null";
	if (std::string::npos != location.find_first_of("0123456789"))
		throw "loction name Contains Digit";
	this->location = location;
}

void meeting::setNumberOfParticipants(int numberOfParticipants)throw(int)
{
	if (numberOfParticipants < 1)
		throw numberOfParticipants;
	string tmp;
	this->numberOfParticipants = numberOfParticipants;
	int i = 0;
	cout << "For task number: " << this->getNumberOfTask() << "\nenter details about the participants.";
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



 bool meeting::isExpiredA(string currentDate)const
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


meeting & meeting::operator+=(const participant & p)
{
	if (this->getNumberOfParticipants() + 1 > MAX_PPL)
		cout << "Too many participants in the meeting" << endl;
	else
	{
		this->participantList[getNumberOfParticipants() + 1]->setName(p.getName());
		this->participantList[getNumberOfParticipants() + 1]->setLastName(p.getLastName());
		this->participantList[getNumberOfParticipants() + 1]->setOrganization(p.getOrganization());
		this->participantList[getNumberOfParticipants() + 1]->setPosition(p.getPosition());
	}
			return *this;
}

 void meeting::PrintT(ostream& out)const
{
	 cout << "\nThe id of the meeting:" << this->getNumberOfTask();
	cout << "\nThe name of the meeting:" << this->getName();
	cout << "\nThe initial date of meeting:" << this->getInitDate();
	cout << "\nThe final date of meeting:" << this->getFinalDate();
	cout << "\nThere are " << this->getNumberOfParticipants() << " in the meeting\n\nThe details of the particpant:"<<endl;
	int i = 0;
	for (; i < getNumberOfParticipants(); i++)
	{
		cout << "participant number " << i + 1 <<endl;
		this->participantList[i]->printP();
	}

}

void meeting::removeA()
{
	int i = 0;
	for (; i < this->getNumberOfParticipants(); i++)
	{
		this->participantList[i]->removeP();
	}
	task::removeT();
}

meeting::~meeting()
{
	
		this->removeA();
	
}

bool isExpired(string currentDate,string finalDate)
{
	meeting *tmp;
	bool expired ;
	tmp = new meeting();
	tmp->setFinalDate (finalDate);
	expired = tmp->isExpiredA(currentDate);
	return expired;
}
