#pragma once
#include <iostream>
using namespace std;

class Person
{
protected:
	char* name;
	char* surname;
	int age;
public:
	Person();
	Person(const char* name, const char* surname, int age);
	Person(const Person& obj);
	Person(Person&& obj);
	~Person();
	const char* getName()const;
	const char* getSurname()const;
	int getAge() const;
	void setName(const char* name);
	void setSurname(const char* surname);
	void setAge(int age);
	void Print()const;
	Person& operator=(const Person& obj);
	Person& operator=(Person&& obj);
	friend std::istream& operator>>(std::istream& is, Person& obj);
	friend std::ostream& operator<<(std::ostream& os, const Person& obj);
};