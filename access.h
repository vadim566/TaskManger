#include "task.h"



class access:public task
{
public:
	access();
	~access();

private:
	
	int numberOfParticipants;
	string location;
};

access::access()
{
}

access::~access()
{
}