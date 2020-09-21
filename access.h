#include "task.h"
#include "participant.h"


class access:public task
{
public:
	access();
	~access();
	
	void setLocation(string location);
	string getLocation()const { return location; };

	void setNumberOfParticipants(int numberOfParticipants);
	int getNumberOfParticipants()const { return numberOfParticipants; };


	void setParticipantList(participant *participantList);

	bool isExpired(string currentDate);

	access &operator+=(const participant &p);
	virtual void PrintT(int taskNunmber)const;

private:
	
	int numberOfParticipants;
	participant *participantList;
	string location;
};

