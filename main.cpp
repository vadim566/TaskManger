

/*
MANGEMENT PROJECT 
authors:
David Musaev
Yakir Maymon
Shaked Spector
to compile this project you MUST HAVE the following sdk installed on Visual Studio:
Windows 10 SDK (10.0.17763.0)
Windows 10 SDK (10.0.18362.0)
*/
#ifndef  _PROJECT_H
#define _PROJECT_H
#include "project.h"
#endif // ! _PROJECT_H

#ifndef _TASK_H
#define _TASK_H
#include "task.h"
#endif // !_TASK_H

#ifndef STD_LIB
#define STD_LIB
#include<fstream>
#include<istream>

#include <iostream>
#include <string>
using namespace std;

#endif // !STD_LIB

#ifndef _INSTALL_H
#define _INSTALL_H
#include "install.h"
#endif // !_INSTALL_H

#ifndef _MEETING_H
#define _MEETING_H
#include "meeting.h"
#endif // !_PAYACC_H

#ifndef _PART_H
#define _PART_H
#include "participant.h"
#endif // !_PART_H

#ifndef  _RESOURCE_H
#define _RESOURCE_H
#include "resource.h"
#endif // ! _RESOURCE_H

#ifndef _PAYMENT_H
#define _PAYMENT_H
#include "payment.h"
#endif
#define MAX_PROJ 10//max number of projects the program can hold the same time
#define MAX_TOTAL_TASK 100//max tasks that the project can hold the same time
task* globalTaskList[MAX_TOTAL_TASK]{NULL};//global task list for use
int globalInt{ 0 };//global index for the global tasks



project *projectMenu(project &proj);//second menu for project mangemnt
string intDateToStringDate(int day, int month, int year);//convert date of int to string date
void setVarsOftasks(int globalIndex);//set variables for tasks
int main()
{
	
	try {
		bool demo;
		cout << "Welcome to Project Mangment software" << endl;
		cout << "as a start the the Project can demo 3 projects if you want a demo.\nfor demo enter 1, for skip enter 0" << endl;
		cin >> demo;
		
		if (demo)
		{

			task* process[4], * tasks[4], * quest[4];
			//participants constructors
			participant* id1 = new participant("David", "Musaev", "Ruppin", "student");
			participant* id2 = new participant("Yakir", "Maymon", "Ruppin", "student");
			participant* id3 = new participant("Shaked", "Spector", "Ruppin", "student");
			participant* id4 = new participant();
			//resources constructor
			resource* res1 = new resource("notebook", "piece", 3);
			resource* res2 = new resource("wood", "kg", 3);
			resource* res3 = new resource();

			//meeting and payment constructor
			process[0] = new meeting( "23 / 09 / 2020", "25 / 09 / 2020",  "RFI", "israel", 0);
			process[1] = new meeting("24 / 09 / 2020", "25 / 09 / 2020", "RPI", "usa", 0);
			process[2] = new payment("12 / 10 / 2020", "14 / 10 / 2020", "pdr",  "NIS", "israel", 0, 2000 );

			//meeting downcast for adding += operator
			meeting* meetingProceess = dynamic_cast<meeting*>(process[0]);
			*meetingProceess += *id1;
			*meetingProceess += *id2;
			meeting* meetingProceess1 = dynamic_cast<meeting*>(process[1]);
			*meetingProceess1 += *id1;
			*meetingProceess1 += *id2;
			meeting* meetingProceess2 = dynamic_cast<meeting*>(process[2]);
			*meetingProceess2 += *id3;
			*meetingProceess2 += *id4;
			//install constructor
			process[3] = new install( "15 / 10 / 2020", "30 / 10 / 2020", "installation of the component", 0, true);
			//install downcast for += operator
			install* installProceess1 = dynamic_cast<install*>(process[3]);
			*installProceess1 += *res1;
			*installProceess1 += *res2;
			
			
			//project number 1
			project* summerCpp;
			summerCpp = new project(4);
			summerCpp->setProjectName("Summer quest");
			for (int j = 0; j < 4; j++)*summerCpp += *process[j];//add 4 tasks into the project
			
			
			summerCpp->printInfo();//print information about the summer project
					
		

			//project number 2
			project* oath = new project(4,"Oath project");
			for(int j=0;j<4;j++)*oath += *process[j];//add 4 tasks into the project
			 
			//project number 3
			project* winter = new project(4, "Winter project");
			for (int j = 0; j < 4; j++)*winter += *process[j];

			winter->printInfo();
			oath->printInfo();

			


			summerCpp->printInfo(summerCpp->searchlist(process[3]->getNumberOfTask()));//find and print by unique id
			int indexToPrint = summerCpp->searchlist(process[3]->getNumberOfTask());//get index to print
			*summerCpp -= indexToPrint;//remove index to print
			summerCpp->printInfo(summerCpp->searchlist(process[3]->getNumberOfTask()));//try to print the index that had removed
			summerCpp->printInfo();//print the whole project.
		}//end of demo
		
		int choice, choice1;//choices of the switch case
		project *proj[MAX_PROJ];//list of projects that the program can contain
		bool flag = 0;//flag of keep runing the while loop of the main menu
		int index = 0; // genric index project that saving the last position of the task of t
		int i = 0;//index counter
		proj[index] = NULL;//set the first project as NULL
		int numberOfTasks = 0, taskNumber = 9000;//numer of task index for cases 1,2,3 and tasknumber unique number for case 5
		string projectName;
		cout << "Do you want to start a new project ? (if yes press 1, if no press 0)" << endl;
		cin >> choice;
		while (!flag) {//while flag 1 the main menu will keep runing
			while ((choice != 0) & (choice != 1)) // choice  - if you want to open a project or not
			{
				cin.clear();//to prevent a loop and flash the input
				getc(stdin);
				cout << "Please try again\n";
				cin >> choice;
			}
			if (choice == 1) // choice1 - what do you want to do in this project
			{
				cout << "Please choose which project type do you want :\n1.Empty project\n2.Project with tasks\n3.Project with name and tasks\n4.manage a project by its name\n5.manage a project by its unique number\n6.print info of all projects\n0.EXIT" << endl;
				cin >> choice1;//get choice for main menu

				switch (choice1)
				{
				case 1:	//create an empty project
					while (index < MAX_PROJ)//if not in the limitation of max project number
					{
						if(proj[index]==NULL)//if its initlized for use as NULL and its ready to use
						{ 
							proj[index] = new project();
							if (index == MAX_PROJ - 1)break;//if its the last one stop here 
							proj[index + 1] = NULL;//continue and put the next index at null value
							index++;//move the index foward
							break;
						}
						index++;
					}
					if(index==MAX_PROJ-1)//if the project list is full show massage to user
					cout << "\nThe project list is FULL!" << endl;
					break;
					
				
				case 2:	//constructor with number of task	
					while (index < MAX_PROJ)//if less then max number project allowed
					{
						if (proj[index] == NULL)//if its initlized for use as NULL and its ready to use
						{
							cout << "Please enter number of tasks:" << endl;//set number of tasks
							cin >> numberOfTasks;
							cin.clear();//to prevent a loop and flash the input
							proj[index] = new project(numberOfTasks);//the rest of here the same as case 1
							if (index == MAX_PROJ - 1)break;
							proj[index + 1] = NULL;
							index++;
							break;
						}
						index++;
					}
					if (index == MAX_PROJ-1)
						cout << "\nThe project list is FULL!" << endl;
					break;
					
					
				
				case 3:
					while (index < MAX_PROJ)//if less then max number project allowed
					{
						if (proj[index] == NULL)//if its initlized for use as NULL
						{
							//constructor with name and number of task
							cout << "Please enter project's name:" << endl;
							cin >> projectName;
							cin.clear();//to prevent a loop and flash the input
							cout << "Please enter number of tasks:" << endl;
							cin >> numberOfTasks;
							cin.clear();//to prevent a loop and flash the input
							proj[index] = new project(numberOfTasks, projectName);//the same as case 1 and 2
							if (index == MAX_PROJ - 1)break;
							proj[index + 1] = NULL;
							index++;
							break;
						}
						index++;
						break;//prevent the while
					}
					if (index == MAX_PROJ-1)
						cout << "\nThe project list is FULL!" << endl;
					break;
				case 4://find a project by its name and mange it
					projectName = "default";
					
					cout << "enter the name of the project" << endl;
						cin >> projectName;
						if(!index==0)//if project list is empty index is a pivot of the last used index of project array
							for (i = 0; i < index; i++)//find project by its name, go threw all availble projects
							{
								if (proj[i]->getProjectName() == projectName)
									proj[i] = projectMenu(*proj[i]);
								if (proj[i] == NULL)index--;
							}
						else//if not found
						{
							cout << "There is no such Project!" << endl;
						}
					break;
				case 5://find a project by its unique project number

					cout << "enter the unique number of the project" << endl;//same as case 4 but here its using the unique id of the project
					cin >> taskNumber;
					if (!index == 0)//if project list is empty
						for (i = 0; i < index; i++)//find project by its name
						{	
							if (proj[i]->getProjectNumber() == taskNumber)
								proj[i] = projectMenu(*proj[i]);
							if (proj[i] == NULL)index--;
						}
					else
					{
						cout << "There is no such Project!" << endl;
					}

					break;

				case 6:
						if (!index == 0)//if project list is empty
						for (i = 0; i < index; i++)//find project by its name
						{
							cout << "*******************************" << endl;
							cout << "project number:" << i + 1 << endl;
							cout << "-------------------------------" << endl;
							cout << "its unique Id is:" << proj[i]->getProjectNumber() << endl;
							cout << "project Name: "<<proj[i]->getProjectName() << endl;
							cout << "*******************************" << endl;
						}
						break;
				case 0:
					//exit
					flag = true;
					break;
				 default:
					cin.clear();
					break;
				}
				cin.clear();//prevent a loop in the menu
				getc(stdin);
				
			};
		}
	}
	catch (string error)
	{
		cout << error<<endl;//show the error massage
	}
	catch (int error)
	{
		cout << "the value has set to BAD value, the value that havebeen set:" << error<<endl;//show the bad value
	}
	catch (...)
	{
		cout << "***fatal error***";
	}
}

string intDateToStringDate(int day, int month, int year)//int date to string date format DD / MM / YY
{
	//some modification to prevent bad values
	if (day > 31 || day < 1)day = 31;
	if (month > 12 || month < 1)month = 12;
	if (year < 1900 || year>2100)year = 2020;

	//int to string
	string dayS = to_string(day);
	string monthS = to_string(month);
	string yearS = to_string(year);
	string brk = " / ";//space  / space its the format of the brake between the values
	string dateS = dayS + brk + monthS + brk + yearS;//create the string for use

	return dateS;//return the date


}

project* projectMenu(project &proj)//second menu for project mangemnt
{
	bool flag = 1;
	bool choice = 0;
	int choice2 , day=0, month=0, year=0,taskN;
	string pTmpSt = "default";//project tempory string for tempory use
	
	int numberOfparticipants = 0;
	
	cout << "Please enter your choice :\n1.Set\Change project name\n2.Add meeting\n3.Remove the last task from the project\n4.Find a task in project and show its information\n5.Show all the project data\n6.delete the project\n0.save and Exit" << endl;
	cin >> choice2;
	while (choice2 != 0)// choice2  - which option do you want to chose
	{
		switch (choice2)
		{
		case 1://set project name

			cout << "\nenter the name of the project:" << endl;
			cin >> pTmpSt;
			proj.setProjectName(pTmpSt);
			
			break;

		case 2://add meeting
			while (globalInt < MAX_TOTAL_TASK)
			{
				if (globalTaskList[globalInt] == NULL)
				{

					//create a meeting
					setVarsOftasks(globalInt);
					//add the task into the task list of proj Project list by using operator +=
					proj.operator+=(*globalTaskList[globalInt]);
					//end of list limitation
					if (globalInt == MAX_TOTAL_TASK - 1)break;
					globalTaskList[globalInt + 1] = NULL;//if not in the end of list put the next one in the list as NULL
					globalInt++;
					break;//end here if all done well, and this task had been added to this project
				}
			}
			break;//jump here if smth went wrong end of list or smth else

		case 3://remove the last task from the project
			cout << "\nremoving the last task in the project" << endl;
			if (proj.getIndexTask() >= 0)
				proj -= proj.getIndexTask();//remove the last one
			break;
		case 4://print one task of index by its unique taskNumber
			cout << "\nenter the number of the task:" << endl;
			cin >> taskN;

			proj.printInfo(proj.searchlist(taskN));//print info of one task
			break;
		case 5:
			cout << "\nthe info of all task:" << endl;
			proj.printInfo();//print info of one task
			break;
		case 6://delete the project
			cout << "Are you sure you want to delete this project? press 1 to delete" << endl;
				cin >> choice;
				if (choice==1)
				{
			cout << "\nremoving project" << endl;
			 proj.~project();
			 cout << "\project removed" << endl;
			 choice2 = 0;//exit
			 return NULL;
				}
				break;
		default: cout << "Please try again\n"<<endl;
			break;
		};
		cin.clear();//prevent loop
		cout << "Please enter your choice :\n1.Set\Change project name\n2.Add meeting\n3.Remove the last task from the project\n4.Find a task in project and show its information\n5.Show all the project data\n6.delete the project\n0.save and Exit" << endl;
		cin >> choice2;
	}
	return &proj;//return this project after stoped working on it
}

void setVarsOftasks(int globalIndex)//initilize task into a project
{

	///variables that will be in use in the function
	string location, iniDate, finalDate, taskName,currency;
	int choice = 0, numberOfparticipants=0,amountOfMoney=0,resources=0;
	bool tests = 0;
	string pTmpSt = "default";
	int day, month, year;
	cout << "\nenter the name of the meeting" << endl;
	cin >> taskName;
	
	//get from the user and set initial date
	cout << "\nenter the inital date of the meeting" << endl;
	cout << "\nenter the day "; cin >> day;
	cout << "\nenter the month "; cin >> month;
	cout << "\nenter the year "; cin >> year;
	iniDate = intDateToStringDate(day, month, year);
	
	//get from the user and set final date
	cout << "\nenter the final date of the task" << endl;
	cout << "\nenter the day "; cin >> day;
	cout << "\nenter the month "; cin >> month;
	cout << "\nenter the year "; cin >> year;
	finalDate = intDateToStringDate(day, month, year);

	//choose if this task is a meeting /install/payment 
	cout << "\nIf its a meeting task enter 1\nIf its a install task enter 2\nIf its a payment task meeting enter 3" << endl;
	cin >> choice;
		switch (choice)
		{
			case 1://meeting choice
				cout << "\nenter the location place" << endl;
				cin >> location;
				cout << "\nenter the number of participants" << endl;
				cin >> numberOfparticipants;
				//construct a task and keep it in the global task list
				globalTaskList[globalIndex] = new meeting(iniDate, finalDate, location, numberOfparticipants);
				break;
			case 2://install choice
				cout << "\nenter 1 if tests included" << endl;
				cin >> tests;
				cout << "\nenter the number of resources" << endl;
				cin >> resources;
				//construct a task and keep it in the global task list
				globalTaskList[globalIndex] = new install(iniDate, finalDate, taskName, resources);
			
				break;
			case 3://payment meeting choice
				cout << "\nenter the location place" << endl;
				cin >> location;
				cout << "\nenter the number of participants" << endl;
				cin >> numberOfparticipants;
				cout << "\nenter the amount of money that needed to pay" << endl;
				cin >> amountOfMoney;
				cout << "\nenter the currency of the money that needed to pay" << endl;
				cin >> currency;
				//construct a task and keep it in the global task list
				globalTaskList[globalIndex] = new payment(iniDate, finalDate, taskName, currency, location, numberOfparticipants, amountOfMoney);
				break;
				
			default:
				break;
		}
}