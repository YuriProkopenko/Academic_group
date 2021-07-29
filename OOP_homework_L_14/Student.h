#pragma once
#include "Person.h"

class Student : public Person
{
	char phone[14];
	double rating;
public:
	Student();
	Student(const char* name, const char* surname, int age, const char* phone, double rating);
	Student(const Student& obj);
	Student(Student&& obj);
	double getRating() const;
	const char* getPhone() const;
	void setPhone(const char* phone);
	void setRating(double average);
	void Print() const;
	Student& operator=(const Student& obj);
	Student& operator=(Student&& obj);
	friend std::istream& operator>>(std::istream& is, Student& obj);
	friend std::ostream& operator<<(std::ostream& os, const Student& obj);
};