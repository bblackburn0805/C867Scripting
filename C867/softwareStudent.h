#pragma once
#include <string>
#include "degree.h"
#include "student.h"
class SoftwareStudent : public Student 
{

public:
	SoftwareStudent();
	SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysUntilCompletion[], DegreeType degreeType);
	DegreeType getDegreeProgram();
	void print();
	~SoftwareStudent();
};

