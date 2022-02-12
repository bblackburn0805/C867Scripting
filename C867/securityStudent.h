#pragma once
#include <string>
#include "degree.h"
#include "student.h"
class SecurityStudent : public Student
{

public:
	SecurityStudent();
	SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysUntilCompletion[], DegreeType degreeType);
	DegreeType getDegreeProgram();
	void print();
	~SecurityStudent();
};