#pragma once
#include <string>
#include "degree.h"
using namespace std;

class Student
{



protected:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysUntilComplete[3];
	DegreeType degreeType;

public:

	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysUntilComplete[]);

	const static int daysUntilCompleteSize = 3;
	
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysUntilComplete();
	virtual DegreeType getDegreeProgram() = 0;


	void setStudentID(string studentID);
	void setFirstName(string firstname);
	void setLastName(string lastname);
	void setEmailAddress(string email);
	void setAge(int age);
	void setDaysUntilComplete(int daysUntilComplete[]);
	virtual void print() = 0;

	//The destructor
	~Student();
};