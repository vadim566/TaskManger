#include "task.h"
#include "participant.h"
#define MAX_PPL 5

class access:public task
{
public:
	access(string location,int numberOfParticipants, string initDate, string finalDate, string name);
	access( int numberOfParticipants, string initDate, string finalDate, string name);
	access(string location, string initDate, string finalDate, string name);
	
	
	void setLocation(string location);
	string getLocation()const { return location; };

	void setNumberOfParticipants(int numberOfParticipants);
	int getNumberOfParticipants()const { return numberOfParticipants; };


	void setParticipantList(participant *participantList);

	bool isExpired( string currentDate)const;

	access &operator+=(const participant &p);
	virtual void PrintT()const;

	void removeA();
	~access();
	

private:
	
	int numberOfParticipants;
	participant *participantList[MAX_PPL];
	string location;
};

