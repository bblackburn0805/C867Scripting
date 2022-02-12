#include <iostream>
#include "softwareStudent.h"
using namespace std;

SoftwareStudent::SoftwareStudent() :Student()
{
	degreeType = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysUntilCompletion[], DegreeType degreeType) : Student(studentID, firstName, lastName, emailAddress, age, daysUntilCompletion)
{
	degreeType = SOFTWARE;
}

DegreeType SoftwareStudent::getDegreeProgram()
{
	return SOFTWARE;
}

void SoftwareStudent::print()
{
	this->Student::print();
	cout << "SOFTWARE" << endl;
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
}