#include <iostream>
#include <iomanip>
#include "Student.h"
using namespace std;

Student::Student() :Person()
{
	strcpy_s(phone, "EMPTY");
	rating = 0;
}

Student::Student(const char* name, const char* surname, int age, const char* phone,
	double rating) :Person(name, surname, age)
{
	for (int i = 0; i < 14; i++)
		this->phone[i] = phone[i];
	this->rating = rating;
}

Student::Student(const Student& obj) :Person((Person&)obj)
{
	for (int i = 0; i < 14; i++)
		phone[i] = obj.phone[i];
	rating = obj.rating;
}

Student::Student(Student&& obj) :Person((Person&&)obj) 
{
	*phone = *obj.phone;
	rating = obj.rating;
}

double Student::getRating() const
{
	return rating;
}

const char* Student::getPhone() const
{
	return phone;
}

void Student::setPhone(const char* phone)
{
	for (int i = 0; i < 14; i++)
		this->phone[i] = phone[i];
}

void Student::setRating(double average)
{
	rating = average;
}

void Student::Print() const
{
	Person::Print();
	cout << phone << '\t' << rating << endl;
}

Student& Student::operator=(const Student& obj)
{
	if (this == &obj)
		return *this;
	Person::operator=((Person&)obj);
	for (int i = 0; i < 14; i++)
		this->phone[i] = obj.phone[i];
	this->rating = obj.rating;
	return *this;
}

Student& Student::operator=(Student&& obj)
{
	if (this == &obj)
		return *this;
	Person::operator=((Person&&)obj);
	*phone = *obj.phone;
	this->rating = obj.rating;
	return *this;
}

std::istream& operator>>(std::istream& is, Student& obj)
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
	cout << "Input a phone number : ";
	is >> obj.phone;
	cout << "Input a rating : ";
	is >> obj.rating;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Student& obj)
{
	obj.Print();
	return os;
}