
#include "task.h"



class access:public task
{
public:
	access();
	~access();

private:
	string *participants;
	int numberOfParticipants;
	string location;
};

access::access()
{
}

access::~access()
{
}