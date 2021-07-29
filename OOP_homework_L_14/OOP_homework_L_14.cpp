#include <iostream>
#include <conio.h>
#include "AcademyGroup.h"
using namespace std;

int main()
{
	AcademyGroup AG;
	int input = 0;
	AG.Load();
	while (input != 6)
	{
		system("cls");
		cout << "1.Add the student to the group" << endl;
		cout << "2.Delete the student from the group" << endl;
		cout << "3.Edit the student" << endl;
		cout << "4.Print the group" << endl;
		cout << "5.Search the student" << endl;
		cout << "6.Exit" << endl;
		input = _getch() - 48;
		switch (input)
		{
		case 1:
			system("cls");
			cout << "1.Add the student to the group" << endl;
			AG.AddStudents();
			AG.Sort();
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "2.Delete the student from the group" << endl;
			AG.DeleteStudent();
			system("pause");
			break;
		case 3:
			system("cls");
			cout << "3.Edit the student" << endl;
			AG.EditStudent();
			AG.Sort();
			system("pause");
			break;
		case 4:
			system("cls");
			cout << "4.Print the group" << endl;
			AG.Print();
		    system("pause");
			break;
		case 5:
			system("cls");
			cout << "5.Search the student" << endl;
			AG.FindStudent();
			system("pause");
			break;
		}
	}
	AG.Save();
	return 0;
}