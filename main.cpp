
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
#define MAX_PROJ 10
#define MAX_TOTAL_TASK 100
task* globalTaskList[MAX_TOTAL_TASK]{NULL};//global task list for use
int globalInt{ 0 };
project *projectMenu(project &proj);
string intDateToStringDate(int day, int month, int year);//convert date of int to string date
void setVarsOftasks(int globalIndex);//set variables for tasks
int main()
{
	
	try {
		bool demo;
		cout << "Welcome to Project Mangment software" << endl;
		cout << "as a start the the Project can demo 3 projects if you want a demo.\nfor demo enter 1, for skip enter 0" << endl;
		cin >> demo;
		/*
		if (demo)
		{

			task* process[4], * tasks[4], * quest[4];

			process[0] = new meeting("israel", "23 / 09 / 2020", "25 / 09 / 2020", "RFI", 2);
			process[1] = new meeting("israel", "26 / 09 / 2020", "30 / 09 / 2020", "kickoff", 2);
			process[2] = new payment("NIS", "israel", 2, "12 / 10 / 2020", "14 / 10 / 2020", "pdr", 2000);
			process[3] = new install(3, true, "15 / 10 / 2020", "30 / 10 / 2020", "installation of the component");

			tasks[0] = new meeting("usa", "13 / 09 / 2020", "16 / 09 / 2020", "searching land", 2);
			tasks[1] = new meeting("italy", "26 / 09 / 2020", "30 / 09 / 2020", "choosing land", 2);
			tasks[2] = new payment("dolar", "israel", 2, "12 / 10 / 2020", "30/ 10 / 2020", "buying land", 2000);
			tasks[3] = new install(3, true, "15 / 11 / 2021", "30 / 10 / 2020", "building a house");

			quest[0] = new meeting("israel", "23 / 09 / 2020", "25 / 09 / 2020", "brain strom of an idea", 2);
			quest[1] = new meeting("israel", "26 / 09 / 2020", "30 / 09 / 2020", "choosing an idea", 2);
			quest[2] = new payment("NIS", "israel", 2, "12 / 10 / 2020", "14 / 10 / 2020", "buying all the materials", 2000);
			quest[3] = new install(3, true, "15 / 10 / 2020", "30 / 10 / 2020", "building and creating the idea");

			project* summerCpp;
			summerCpp = new project(4);
			summerCpp->setProjectName("Summer quest");
			*summerCpp += *process[0];
			*summerCpp += *process[1];
			*summerCpp += *process[2];
			*summerCpp += *process[3];
			summerCpp->printInfo();
			int index = summerCpp->searchlist(1003);
			summerCpp->printInfo(index);
			*summerCpp -= 2;
			index = summerCpp->searchlist(1003);
			summerCpp->printInfo(index);


			project* oathCpp, * winterCpp;
			oathCpp = new project(4);
			winterCpp = new project(5);
			oathCpp->setProjectName("Oath Tasks");
			*oathCpp += *tasks[1];
			*oathCpp += *tasks[2];
			*oathCpp += *tasks[3];
			


			winterCpp->setProjectName("Winter quest");
			*winterCpp += *quest[1];
			*winterCpp += *quest[2];
			*winterCpp += *quest[3];
			


			summerCpp->printInfo();
			oathCpp->printInfo();
			winterCpp->printInfo();
		}//end of demo
		*/
		int choice, choice1;
		project *proj[MAX_PROJ];//list of projects that the program can contain
		bool flag = 0;//flag
		int index = 0; // index
		int i = 0;//index counter
		proj[index] = NULL;//set the first project as NULL
		int numberOfTasks=0;
		string projectName;
		cout << "Do you want to start a new project ? (if yes press 1, if no press 0)" << endl;
		cin >> choice;
		while (!flag) {
			while ((choice != 0) & (choice != 1)) // choice  - if you want to open a project or not
			{
				cout << "Please try again\n";
				cin >> choice;
			}
			if (choice == 1) // choice1 - what do you want to do in this project
			{
				cout << "Please choose which project type do you want :\n1.Empty project\n2.Project with tasks\n3.Project with name and tasks\n4.manage the project by its name\n5.exit" << endl;
				cin >> choice1;

				switch (choice1)
				{
				case 1:	
					while (index < MAX_PROJ)
					{
						if(proj[index]==NULL)
						{ 
							proj[index] = new project();
							if (index == MAX_PROJ - 1)break;
							proj[index + 1] = NULL;
							index++;
							break;
						}
						index++;
					}
					if(index==MAX_PROJ-1)
					cout << "\nThe project list is FULL!" << endl;
					break;
					
				
				case 2:		
					//constructor with number of task
					while (index < MAX_PROJ)//if less then max number project allowed
					{
						if (proj[index] == NULL)//if its initlized for use as NULL
						{
							cout << "Please enter number of tasks:" << endl;
							cin >> numberOfTasks;
							proj[index] = new project(numberOfTasks);
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
							cout << "Please enter number of tasks:" << endl;
							cin >> numberOfTasks;
							proj[index] = new project(numberOfTasks, projectName);
							if (index == MAX_PROJ - 1)break;
							proj[index + 1] = NULL;
							index++;
							break;
						}
						index++;
					}
					if (index == MAX_PROJ-1)
						cout << "\nThe project list is FULL!" << endl;
				case 4:
					projectName = "default";
					
					cout << "enter the name of the project" << endl;
						cin >> projectName;
						if(!index==0)//if project list is empty
							for (i = 0; i < index; i++)//find project by its name
							{
								if (proj[i]->getProjectName() == projectName)
									proj[i] = projectMenu(*proj[i]);
							}
						else
						{
							cout << "There is no such Project!" << endl;
						}
						
					break;


				case 5:
					//exit
					flag = true;
					break;
					
				 default:
					cin.clear();
					break;
				}
				cin.clear();
				getc(stdin);
				
			};
		}
	}

		//start of a menu
		//use of switch and case
		//1.build a project -project constructor , empty project? // project with some tasks
		//2.set a name
		//3.add meeting - meeting constructor
		//4.add install -install constructor
		//5. add payment meeting -payment constructor
		//6. remove the last task from the project - operator -= lifo
		//7.find a task in the project - find a task by a task number and return the place in the project array making enable for print a task from the list, input task number output number in the array projectlist
		//8.show information of a one task from the project- enter int and get the task in the array of project list
		//9.show the whole project info- printinfo
		//10.sum of all the payments



	
	
	catch (string error)
	{
		cout << error;
	}
	catch (int error)
	{
		cout << "the value has set to:" << error;
	}
	catch (...)
	{
		cout << "***fatal error***";
	}
}

string intDateToStringDate(int day, int month, int year)
{
	if (day > 31 || day < 1)day = 31;
	if (month > 12 || month < 1)month = 12;
	if (year < 1900 || year>2100)year = 2020;


	string dayS = to_string(day);
	string monthS = to_string(month);
	string yearS = to_string(year);
	string brk = " / ";
	string dateS = dayS + brk + monthS + brk + yearS;

	return dateS;


}

project* projectMenu(project &proj)
{
	bool flag = 1;

	int choice2 , day=0, month=0, year=0,taskN;
	string pTmpSt = "default";//project tempory string for tempory use
	
	int numberOfparticipants = 0;
	
	cout << "Please enter your choice :\n1.Set\Change project name\n2.Add meeting\n3.Remove the last task from the project\n4.Find a task in project and show its information\n5.Show all the project data\n6.sum of all the payments\n0.Exit" << endl;
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
					
					proj.operator+=(*globalTaskList[globalInt]);//add the task into the task list


					if (globalInt == MAX_TOTAL_TASK - 1)break;
					globalTaskList[globalInt + 1] = NULL;
					globalInt++;
					break;
				}
			}
			

			break;

		case 3://remove the last task from the project
			cout << "\nremoving the last task in the project" << endl;
			if (proj.getIndexTask() >= 0)
				proj -= proj.getIndexTask();
			break;
		case 4:
			cout << "\nenter the number of the task:" << endl;
			cin >> taskN;

			proj.printInfo(proj.searchlist(taskN));//print info of one task
			break;
		case 5:
			cout << "\nthe info of all task:" << endl;
			proj.printInfo();//print info of one task
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 0:
			return 0;
			break;

		default: cout << "Please try again\n"<<endl;
			break;
		};
		cin.clear();
		cout << "Please enter your choice :\n1.Set\Change project name\n2.Add meeting\n3.Remove the last task from the project\n4.Find a task in project and show its information\n5.Show all the project data\n6.sum of all the payments\n0.Exit" << endl;
		cin >> choice2;
	}
	return &proj;
}

void setVarsOftasks(int globalIndex)//initilize task into a project
{
	string location, iniDate, finalDate, taskName,currency;
	int choice = 0, numberOfparticipants=0,amountOfMoney=0,resources=0;
	bool tests = 0;
	string pTmpSt = "default";
	int day, month, year;
	cout << "\nenter the name of the meeting" << endl;
	cin >> taskName;
	
	//set initial date
	
	cout << "\nenter the inital date of the meeting" << endl;
	cout << "\nenter the day "; cin >> day;
	cout << "\nenter the month "; cin >> month;
	cout << "\nenter the year "; cin >> year;
	iniDate = intDateToStringDate(day, month, year);
	
	//set final date
	cout << "\nenter the final date of the task" << endl;
	cout << "\nenter the day "; cin >> day;
	cout << "\nenter the month "; cin >> month;
	cout << "\nenter the year "; cin >> year;
	finalDate = intDateToStringDate(day, month, year);

	
	cout << "\n if its a meeting enter 1\nif its a install enter 2\nif its a payment meeting enter 3" << endl;
	cin >> choice;
		switch (choice)
		{
			case 1:
				cout << "\nenter the location place" << endl;
				cin >> location;
				cout << "\nenter the number of participants" << endl;
				cin >> numberOfparticipants;
				globalTaskList[globalIndex] = new meeting(iniDate, finalDate, location, numberOfparticipants);
				break;
			case 2:
				cout << "\nenter 1 if tests included" << endl;
				cin >> tests;
				cout << "\nenter the number of resources" << endl;
				cin >> resources;
				globalTaskList[globalIndex] = new install(iniDate, finalDate, taskName, resources);
			
				break;
			case 3:
				cout << "\nenter the location place" << endl;
				cin >> location;
				cout << "\nenter the number of participants" << endl;
				cin >> numberOfparticipants;
				cout << "\nenter the amount of money that needed to pay" << endl;
				cin >> amountOfMoney;
				cout << "\nenter the currency of the money that needed to pay" << endl;
				cin >> currency;
				globalTaskList[globalIndex] = new payment(iniDate, finalDate, taskName, currency, location, numberOfparticipants, amountOfMoney);
				break;
				
			default:
				break;
		}
}