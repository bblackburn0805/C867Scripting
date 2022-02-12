#include <iostream>
#include "networkStudent.h"
using namespace std;

NetworkStudent::NetworkStudent() :Student()
{
	degreeType = NETWORK;
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysUntilCompletion[], DegreeType degreeType) : Student(studentID, firstName, lastName, emailAddress, age, daysUntilCompletion)
{
	degreeType = NETWORK;
}

DegreeType NetworkStudent::getDegreeProgram()
{
	return NETWORK;
}

void NetworkStudent::print()
{
	this->Student::print();
	cout << "NETWORK" << endl;
}

NetworkStudent::~NetworkStudent()
{
	Student::~Student();
}
