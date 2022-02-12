#pragma once
#include <string>
#include "degree.h"
#include "student.h"
class NetworkStudent : public Student
{

public:
	NetworkStudent();
	NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysUntilCompletion[], DegreeType degreeType);
	DegreeType getDegreeProgram();
	void print();
	~NetworkStudent();
}; 
