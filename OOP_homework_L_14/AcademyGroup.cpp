#include <iostream>
#include "AcademyGroup.h"
using namespace std;

AcademyGroup::AcademyGroup(const AcademyGroup& obj)
{
	count = obj.count;
	pSt = new Student*[count];
	for (int i = 0; i < count; i++)
		*pSt[i] = *obj.pSt[i];
}

AcademyGroup::AcademyGroup(AcademyGroup&& obj) 
{
	count = obj.count;
	pSt = obj.pSt;
	obj.pSt = nullptr;
	obj.count = 0;
}

AcademyGroup::~AcademyGroup()
{
	for (int i = 0; i < count; i++)
		delete pSt[i];
	delete[] pSt;
	pSt = nullptr;
}

void AcademyGroup::AddStudents()
{
	int quantity;
	cout << "Input quantity of students to add : ";
	cin >> quantity;
	Student** new_pSt = new Student * [count + quantity];
	for (int i = 0; i < count; i++)
	{
		new_pSt[i] = pSt[i];
	}
	delete[] pSt;
	for (int i = 0; i < quantity; i++)
	{
		new_pSt[count + i] = new Student;
		cin >> *new_pSt[count + i];
	}
	pSt = new_pSt;
	new_pSt = nullptr;
	count += quantity;
}

void AcademyGroup::DeleteStudent()
{
	char name[256]{};
	cout << "Input Surname of the student : " << endl;
	cin >> name;
	int count_new_pSt = count;
	bool check = false;
	for (int i = 0; i < count; i++)
	{
		if (strcmp(pSt[i]->getSurname(), name) == 0)
		{
			check = true;
			Student** new_pSt = new Student * [count_new_pSt - 1];
			int counter = 0;
			for (int j = 0; j < count; j++)
			{
				if (pSt[i] != pSt[j])
				{
					new_pSt[counter] = pSt[j];
					counter++;
				}
				else
					continue;
			}
			delete[] pSt;
			pSt = new_pSt;
			new_pSt = nullptr;
			count--;
			cout << "Done!";
			return;
		}
	}
	if (check == false)
		cout << "Student not found !";
}

void AcademyGroup::EditStudent()
{
	char name[256]{};
	cout << "Input Surname of the student : " << endl;
	cin >> name;
	for (int i = 0; i < count; i++)
	{
		if (strcmp(pSt[i]->getSurname(), name) == 0)
		{
			cout << *pSt[i] << endl << endl;
			Student E_St;
			cin >> E_St;
			*pSt[i] = move(E_St);
		}
	}
	cout << "Done!";
}

void AcademyGroup::Print()
{
	for (int i = 0; i < count; i++)
		cout << *pSt[i];
}

void AcademyGroup::FindStudent()
{
	char name[256]{};
	cout << "Input Surname of the student : " << endl;
	cin >> name;
	for (int i = 0; i < count; i++)
	{
		if (strcmp(pSt[i]->getSurname(), name) == 0)
			cout << *pSt[i];
	}
}

void AcademyGroup::Sort()
{
	Student* temp;
		for (int i = 0; i < count - 1; i++)
			for (int j = 0; j < count - i - 1; j++)
				if (strcmp(pSt[j]->getSurname(), pSt[j + 1]->getSurname()) > 0)
				{
					temp = pSt[j];
					pSt[j] = pSt[j + 1];
					pSt[j + 1] = temp;
				}
	temp = nullptr;
}

void AcademyGroup::Save()
{
	char filename[100]{ "AcademyGroup.png" };
	//cout << "Enter file path : ";
	//cin >> filename;
	FILE* file = nullptr;
	fopen_s(&file, filename, "wb");
	if (file == nullptr)
	{
		perror(NULL);
		system("pause>>NUL");
		return;
	}
	fwrite(&count, sizeof(int), 1, file);
	for (int i = 0; i < count; i++)
	{
		int size_n = strlen(pSt[i]->getName()) + 1;
		fwrite(&size_n, sizeof(int), 1, file);
		fwrite(pSt[i]->getName(), sizeof(char), size_n, file);
		int size_Sn = strlen(pSt[i]->getSurname()) + 1;
		fwrite(&size_Sn, sizeof(int), 1, file);
		fwrite(pSt[i]->getSurname(), sizeof(char), size_Sn, file);
		int age = pSt[i]->getAge();
		fwrite(&age, sizeof(int), 1, file);
		fwrite(pSt[i]->getPhone(), sizeof(char), 14, file);
		double rating = pSt[i]->getRating();
		fwrite(&rating, sizeof(double), 1, file);
	}
	fclose(file);
}

void AcademyGroup::Load()
{
	char filename[100]{ "AcademyGroup.png" };
	//cout << "Enter file path : ";
	//cin >> filename;
	FILE* file = nullptr;
	fopen_s(&file, filename, "rb");
	if (file == nullptr)
	{
		perror(NULL);
		system("pause>>NUL");
		return;
	}
	fread(&count, sizeof(int), 1, file);
	Student** new_pSt = new Student * [count];
	for (int i = 0; i < count; i++)
	{
		int size_n;
		fread(&size_n, sizeof(int), 1, file);
		char* l_name = new char[size_n];
		fread(l_name, sizeof(char), size_n, file);
		new_pSt[i] = new Student;
		new_pSt[i]->setName(l_name);
		int size_Sn;
		fread(&size_Sn, sizeof(int), 1, file);
		char* l_sname = new char[size_Sn];
		fread(l_sname, sizeof(char), size_Sn, file);
		new_pSt[i]->setSurname(l_sname);
		int age;
		fread(&age, sizeof(int), 1, file);
		new_pSt[i]->setAge(age);
		char phone[14];
		fread(&phone, sizeof(char), 14, file);
		new_pSt[i]->setPhone(phone);
		double rating;
		fread(&rating, sizeof(double), 1, file);
		new_pSt[i]->setRating(rating);
	}
	fclose(file);
	pSt = new_pSt;
	new_pSt = nullptr;
}

AcademyGroup& AcademyGroup::operator=(const AcademyGroup& obj)
{
	this->count = obj.count;
	this->pSt = new Student * [count];
	for (int i = 0; i < count; i++)
		*pSt[i] = *obj.pSt[i];
	return *this;
}

AcademyGroup& AcademyGroup::operator=(AcademyGroup&& obj)
{
	this->count = obj.count;
	this->pSt = obj.pSt;
	obj.pSt = nullptr;
	obj.count = 0;
	return *this;
}

Student& AcademyGroup::operator[](int index)
{
	return *pSt[index];
}

std::ostream& operator<<(std::ostream& os, AcademyGroup& obj)
{
	obj.Print();
	return os;
}