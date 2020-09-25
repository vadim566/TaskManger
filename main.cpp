
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



string intDateToStringDate(int day, int month, int year);
int main()
{

	try {
		bool demo;
		cout << "Welcome to Project Mangment software" << endl;
		cout << "as a start the the Project can demo 3 projects if you want a demo.\nfor demo enter 1, for skip enter 0" << endl;
		cin >> demo;

		if (demo)
		{

			task *process[4], *tasks[4], *quest[4];

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

			project *summerCpp;
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


			project *oathCpp, *winterCpp;
			oathCpp = new project(4);
			winterCpp = new project(5);
			oathCpp->setProjectName("Oath Tasks");
			*oathCpp += *tasks[1];
			*oathCpp += *tasks[2];
			*oathCpp += *tasks[3];
			*oathCpp += *tasks[4];


			winterCpp->setProjectName("Winter quest");
			*winterCpp += *quest[1];
			*winterCpp += *quest[2];
			*winterCpp += *quest[3];
			*winterCpp += *quest[4];


			summerCpp->printInfo();
			oathCpp->printInfo();
			winterCpp->printInfo();
		}//end of demo

		int choice, choice1, choice2;
		project *proj1, *proj2, *proj3;
		cout << "Do you want to open a project ? (if yes press 1, if no press 0)" << endl;
		cin >> choice;
		while ((choice != 0)&(choice != 1)) // choice  - if you want to open a project or not
		{
			cout << "Please try again\n";
			cin >> choice;
		}
		if (choice == 1) // choice1 - what do you want to do in this project
		{
			cout << "Please choose which project type do you want :\n1.Empty project\n2.Project with tasks\n3.Project with name and tasks" << endl;
			cin >> choice1;
			switch (choice1)
			{
			case 1:
			{
				proj1=new project;
				break;
			}
			case 2:
			{
				int numberOfTasks;
				cout << "Please enter project's name:" << endl;
				cin >> numberOfTasks;
				project p1(numberOfTasks);
				break;
			}
			case 3:
			{
				string projectName;
				int numberOfTasks;
				cout << "Please enter project's name:" << endl;
				cin >> projectName;
				cout << "Please enter number of tasks:" << endl;
				cin >> numberOfTasks;
				project p1(numberOfTasks, projectName);
				break;
			}

			cout << "Please enter your choice :\n1.Set\Change project name\n2.Add meeting\n3.Add install\n4. Payment for the meeting\n5. Remove the last task from the project\n6.Find a task in project\n7.Show information of task from specific project\n8.Show all the project data\n9.sum of all the payments\n0.Exit" << endl;
			cin >> choice2;
			while (choice2 != 0)// choice2  - which option do you want to chose
			{
				switch (choice2)
				{
				case 1:
				{

				};
				case 2:
				{
				};
				case 3:
				{

				};
				case 4:
				{

				};
				case 5:
				{

				};
				case 6:
				{

				};
				case 7:
				{

				};
				case 8:
				{

				};
				case 9:
				{
				};

				default: cout << "Please try again\n";
					break;
				}
				cout << "Do you want to choose another option ?";
				cout << "Please enter your choice :\n1.Set\Change project name\n2.Add meeting\n3.Add install\n4. Payment for the meeting\n5. Remove the last task from the project\n6.Find a task in project\n7.Show information of task from specific project\n8.Show all the project data\n9.sum of all the payments\n0.Exit" << endl;
				cin >> choice2;
			}
			};
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



	}
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