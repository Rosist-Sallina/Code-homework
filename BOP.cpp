#include <iostream>
#include <fstream>

void BOP()
{
	using namespace std;
	const int strsize = 50;

	struct bop
	{
		char fullname[strsize];
		char title[strsize];
		char bopname[strsize];

		int preference;
	};

	struct bop member[5] =
	{
		{"Wimp Macho" , "Programmer" , "Wimp" , 0},
		{"Raki Rhodes" , "Junior Programmer" , "Raki" , 1},
		{"Celia Laiter" , "Programmer" , "MIPS" , 2},
		{"Hoppy Hipman" , "Analyst Trainee" , "Analyst Trainee" , 1},
		{"Pat Hand" , "Student" , "LOOPY" , 2}
	};

	cout << "a. dispaly by name ." << "     ";
	cout << "b. dispaly by title." << endl;
	cout << "c. dispaly by bopname." << "     ";
	cout << "d. dispaly by preference." << endl;
	cout << "q. quit" << endl;
	
	char choice[strsize];
	cout << "Enter your choice :";

	do
	{
		cin >> choice;
		if (*choice == 'a')
			for (int i = 0; i < 5; i++)
			{
				cout << member[i].fullname << endl;
			}

		else if (*choice == 'b')
		{
			for (int i = 0; i < 5; i++)
				cout << member[i].title << endl;
		}

		else if (*choice == 'c')
		{
			for (int i = 0; i < 5; i++)
				cout << member[i].bopname << endl;
		}

		else if (*choice == 'd')
		{
			for (int i = 0; i < 5; i++)
			{
				int choice1 = member[i].preference;
				switch (choice1)
				{
				case 1: cout << member[i].fullname << endl;
					break;

				case 2: cout << member[i].title << endl;
					break;

				case 3: cout << member[i].bopname << endl;
					break;
				}
			}
		}
		else if (*choice == 'q')
			break;
		else
			cout << "Please enter again :";
		cin.clear();
	} while (*choice != 'q');

		cout << "Bye";
	
}