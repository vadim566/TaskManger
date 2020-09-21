#include "access.h"
#include <iomanip>
using namespace std;




void access::setLocation(string location)
{
	this->location = location;
}

void access::setNumberOfParticipants(int numberOfParticipants)
{
	this->numberOfParticipants = numberOfParticipants;
}

void access::setParticipantList(participant *participantList)
{
	if (participantList!=nullptr)
	{
		this->participantList = participantList;
	}
}

bool access::isExpired(string currentDate)
{
	string tmpFinal = this->getFinalDate(),tmpCurrent=currentDate;
	string delimiter = " \ ",token0,token1;
	size_t pos0 = 0,pos1=0;
	int day[2], month[2], year[2];
	int i = 0;
	while ((pos0 = tmpCurrent.find(delimiter)) != string::npos)//cut the date string and convert into 6 int
	{
		token0 = tmpCurrent.substr(0, pos0);
		token1 = tmpFinal.substr(0, pos1);
		if(i==0)//first cut off the days
		{
		day[0]=stoi(token0);
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
		if(month[0] > month[1])//if current month is higher then final month
			return true;//expired=true
		else
		{
			if (day[0] > day[1])//if current day is higher then final day
				return true;//expired=true
		}
	

	
	}

	return false;
}


