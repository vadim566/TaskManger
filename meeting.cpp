#include "meeting.h"

using namespace std;







meeting::meeting(string initDate, string finalDate, string name, string location, int numberOfParticipants ) :task(initDate,finalDate,name)
{
	
	if (numberOfParticipants > MAX_PPL)
	{
		numberOfParticipants = MAX_PPL;
		cout << "Max participants in meeting:" << MAX_PPL <<"the value of participant has changed to max value"<< endl;
		
	}
	setNumberOfParticipants(numberOfParticipants);
		this->setLocation(location);
	
	
}

meeting::meeting(string initDate, string finalDate, string name, int numberOfParticipants ):task(initDate, finalDate, name)
{
	this->setLocation("virtual:VC/ZOOM/Tel");
	setNumberOfParticipants(numberOfParticipants);
	int i = 0;

	
}

meeting::meeting(string initDate, string finalDate, string name, string location):task(initDate, finalDate, name)
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

/*set loction for the meeting and checking if the location name is not empty and not contain digits*/
void meeting::setLocation(string location)throw(string)
{
	if (location == "") throw "loction  is Empty String";           /*check is the location is not empty string*/
	if (&location == nullptr) throw "loction is Null";              /*check if th location name is not null*/
	if (std::string::npos != location.find_first_of("0123456789"))  /*check if th location name does not contain digits*/
		throw "loction name Contains Digit";                        /*check if th location name does not contain digits*/ 
	this->location = location;
}
/*set number of oarticipants in the meeting and check if the numbers is logical */
void meeting::setNumberOfParticipants(int numberOfParticipants)throw(int)
{
	if (numberOfParticipants < 0) 
		throw numberOfParticipants;  /*check if the number of participant is logical */
	string tmp;
	this->numberOfParticipants = numberOfParticipants;
	int i = 0;
	cout << "For task number: " << this->getNumberOfTask() << "\nenter details about the participants.";
	for (; i < numberOfParticipants; i++)
	{
		this->participantList[i] = new participant();   /*alloction for participant*/
		cout << "\nEnter info of particpant number "<<i+1 <<"\nnenter the name of the participant: "; /*enter participant first name*/
		cin >> tmp;
		participantList[i]->setName(tmp);
		cout << "enter the name of the last name of participant: ";      /*enter participant last name*/
		cin >> tmp;
		participantList[i]->setLastName(tmp);
		cout << "enter the name of the organization: ";                  /*enter  name of the organization*/
		cin >> tmp;
		participantList[i]->setOrganization(tmp);
		cout << "enter the position in the organization: ";              /*enter  name of the  position in the organization*/
		cin >> tmp;
		participantList[i]->setPosition(tmp);
	}
}



//operators +=
meeting & meeting::operator+=(const participant & p)
{
	if (this->getNumberOfParticipants()  >= MAX_PPL)
		cout << "Too many participants in the meeting" << endl;
	else
	{
		this->participantList[getNumberOfParticipants()] = new participant(p.getName(), p.getLastName(), p.getOrganization(), p.getPosition());
		this->numberOfParticipants++;
	}
			return *this;
}
/*print the information of the meeting - 
id,name,initial date,final date,participants details*/
meeting& meeting::operator=(const meeting & other)
{
	((task*)this)->operator=(other);
	this->numberOfParticipants=(other.getNumberOfParticipants());
	this->setLocation(other.getLocation());
	for (int i = 0; i < this->numberOfParticipants;i++)
	{
		this->participantList[i] = new participant(other.participantList[i]->getName(), other.participantList[i]->getLastName(), other.participantList[i]->getOrganization(), other.participantList[i]->getPosition());
		this->participantList[i]->setName(other.participantList[i]->getName());
		
	}

	return *this;
}
void meeting::PrintT(ostream& out)const
{
	 cout << "\nThe id of the meeting:" << this->getNumberOfTask();  /*id of the meeting*/
	cout << "\nThe name of the meeting:" << this->getName();  /*na,e of the meeting*/
	cout << "\nThe initial date of meeting:" << this->getInitDate();  /*initial date of the meeting*/
	cout << "\nThe final date of meeting:" << this->getFinalDate(); /*final date of the meeting*/
	cout << "\nThere are " << this->getNumberOfParticipants() << " in the meeting\n\nThe details of the particpant:"<<endl;  /*the participants  details*/
	int i = 0;
	for (; i < getNumberOfParticipants(); i++)
	{
		cout << "participant number " << i + 1 <<endl;
		this->participantList[i]->printP();
	}

}

 /*free allocation*/
void meeting::removeA()
{
	int i = 0;
	for (; i < this->getNumberOfParticipants(); i++)
	{
		this->participantList[i]->removeP();
	}
	task::removeT();
}
/*free all alloction*/
meeting::~meeting()
{
	
		this->removeA();
	
}
/*checking if the date is expired -  if current date  == to final date tham the date int expired*/
bool isExpired(string currentDate,string finalDate)
{
	meeting *tmp;
	bool expired ;
	tmp = new meeting();
	tmp->setFinalDate (finalDate);
	expired = tmp->isExpiredA(currentDate);
	return expired;
}
