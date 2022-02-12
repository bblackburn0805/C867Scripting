#include <iostream>
#include "securityStudent.h"
using namespace std;

SecurityStudent::SecurityStudent():Student()
{
	degreeType = SECURITY;
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysUntilCompletion[], DegreeType degreeType):Student(studentID, firstName, lastName, emailAddress, age, daysUntilCompletion)
{
	degreeType = SECURITY;
}

DegreeType SecurityStudent::getDegreeProgram()
{
	return SECURITY;
}

void SecurityStudent::print()
{
	this->Student::print();
	cout << "SECURITY" << endl;
}

SecurityStudent::~SecurityStudent()
{
	Student::~Student();
}
