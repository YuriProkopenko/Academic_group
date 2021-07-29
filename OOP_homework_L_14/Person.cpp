#include <iostream>
#include <iomanip>
#include "Person.h"
using namespace std;

Person::Person()
{
	name = new char[6] {"EMPTY"};
	surname = new char[6] {"EMPTY"};
	age = 0;
}

Person::Person(const char* name, const char* surname, int age)
{
	this->name = new char[sizeof(name) + 1];
	for (int i = 0; i < sizeof(name) + 1; i++)
		this->name[i] = name[i];
	this->surname = new char[sizeof(surname) + 1];
	for (int i = 0; i < sizeof(surname) + 1; i++)
		this->surname[i] = surname[i];
	this->age = age;
}

Person::Person(const Person& obj)
{
	this->name = new char[sizeof(obj.name) + 1];
	for (int i = 0; i < sizeof(obj.name) + 1; i++)
		this->name[i] = obj.name[i];
	this->surname = new char[sizeof(obj.surname) + 1];
	for (int i = 0; i < sizeof(obj.surname) + 1; i++)
		this->surname[i] = obj.surname[i];
	this->age = obj.age;
}

Person::Person(Person&& obj)
{
	name = obj.name;
	obj.name = nullptr;
	surname = obj.surname;
	obj.surname = nullptr;
	age = obj.age;
}

Person::~Person()
{
	delete[] name;
	name = nullptr;
	delete[] surname;
	surname = nullptr;
}

const char* Person::getName()const
{
	return name;
}

const char* Person::getSurname()const
{
	return surname;
}

int Person::getAge() const
{
	return age;
}

void Person::setName(const char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	for (int i = 0; i < strlen(name) + 1; i++)
		this->name[i] = name[i];
}

void Person::setSurname(const char* surname)
{
	delete[] this->surname;
	this->surname = new char[strlen(surname) + 1];
	for (int i = 0; i < strlen(surname) + 1; i++)
		this->surname[i] = surname[i];
}

void Person::setAge(int age)
{
	this->age = age;
}

void Person::Print()const
{
	cout << surname << "\t" << name << '\t' << age << '\t';
}

Person& Person::operator=(const Person& obj)
{
	if (this == &obj)
		return *this;
	delete[] name;
	this->name = new char[sizeof(obj.name) + 1];
	for (int i = 0; i < sizeof(obj.name) + 1; i++)
		this->name[i] = obj.name[i];
	delete[] surname;
	this->surname = new char[sizeof(obj.surname) + 1];
	for (int i = 0; i < sizeof(obj.surname) + 1; i++)
		this->surname[i] = obj.surname[i];
	this->age = obj.age;
	return *this;
}

Person& Person::operator=(Person&& obj)
{
	if (this == &obj)
		return *this;
	delete[] this->name;
	this->name = obj.name;
	obj.name = nullptr;
	delete[] this->surname;
	this->surname = obj.surname;
	obj.surname = nullptr;
	this->age = obj.age;
	return *this;
}

std::istream& operator>>(std::istream& is, Person& obj)
{
	char* word = new char[256]{};
	cout << "Input a name : ";
	is >> word;
	obj.setName(word);
	cout << "Input a surname : ";
	is >> word;
	obj.setSurname(word);
	cout << "Input an age : ";
	is >> obj.age;
	delete[] word;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Person& obj)
{
	obj.Print();
	return os;
}