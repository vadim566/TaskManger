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
