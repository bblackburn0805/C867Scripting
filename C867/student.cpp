#pragma once
#include<iostream>
#include<iomanip>
#include "student.h"
using namespace std;

Student::Student()
{
	int x;
	this->studentID;
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (x = 0; x < daysUntilCompleteSize; x++) 
		this->daysUntilComplete[x] = 0;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysUntilComplete[])//The full constructor
{
	int x;
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (x = 0; x < daysUntilCompleteSize; x++) 
		this->daysUntilComplete[x] = daysUntilComplete[x];
}



//getters

string Student::getStudentID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmailAddress()
{
	return emailAddress;
}

int Student::getAge()
{
	return age;
}

int* Student::getDaysUntilComplete()
{
	return daysUntilComplete;
}

void getDegreeProgram()
{
	
}


//Setters

void Student::setStudentID(string studentID)
{
	this->studentID = studentID;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress)
{
	this->emailAddress = emailAddress;
}

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setDaysUntilComplete(int daysUntilComplete[])
{
	int x;
	for (x = 0; x < daysUntilCompleteSize; x++)
		this->daysUntilComplete[x] = daysUntilComplete[x];
}

void Student::print()
{
	cout << getStudentID() << "\tFirst Name: " << getFirstName() << "\tLast Name: " << getLastName();
	cout << "\tAge: " << getAge() << "\t\tdaysInCourse: {" << daysUntilComplete[0] << ", " << daysUntilComplete[1] << ", " << daysUntilComplete[2];
	cout << "}\t Degree Program: ";
}

Student::~Student()
{
}
