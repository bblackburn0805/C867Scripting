#pragma once
#include <string>
#include <iostream>
#include "student.h"

class Roster {
private:
	int lastStudent;
	int rosterSize;
	Student** students;
public:
	Roster();
	Roster(int rosterSize);

	Student* getStudentAt(int studentAt);
	void makeStudent (string data);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeType degreeType);
	void printAll();
	void remove(string studentID);
	void printDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(int degreeProgram);
	~Roster();
};