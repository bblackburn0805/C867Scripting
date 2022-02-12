#include "roster.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
using namespace std;


Roster::Roster()
{
	this->rosterSize = 0;
	this->lastStudent = -1;
	this->students = nullptr;
}

Roster::Roster(int size)
{
	this->rosterSize = size;
	this->lastStudent = -1;//AGAIN; means empty
	this->students = new Student * [size];
}

Student* Roster::getStudentAt(int studentAt)
{
	return students[studentAt];
}


void Roster::makeStudent(string entity)
{
	int lSearch;
	int rSearch;
	string newID;
	string newFirst;
	string newLast;
	string newEmail;
	int newAge;
	int newCourse1;
	int newCourse2;
	int newCourse3;
	string temp;
	DegreeType newDegree;
	rosterSize = sizeof(entity) / sizeof(entity[0]);
	
		lastStudent++;

		// Find the studentID
		lSearch = 0;
		rSearch = entity.find(",");
		newID = entity.substr(lSearch, rSearch);

		// Now find first name
		lSearch = rSearch + 1;
		rSearch = entity.find(",", lSearch);
		newFirst = entity.substr(lSearch, rSearch - lSearch);

		// Find last name
		lSearch = rSearch + 1;
		rSearch = entity.find(",", lSearch);
		newLast = entity.substr(lSearch, rSearch - lSearch);

		// Email 
		lSearch = rSearch + 1;
		rSearch = entity.find(",", lSearch);
		newEmail = entity.substr(lSearch, rSearch - lSearch);

		// Age in years 
		lSearch = rSearch + 1;
		rSearch = entity.find(",", lSearch);
		newAge = stoi(entity.substr(lSearch, rSearch - lSearch));

		// Find days left in classes
		lSearch = rSearch + 1;
		rSearch = entity.find(",", lSearch);
		newCourse1 = stoi(entity.substr(lSearch, rSearch - lSearch));

		lSearch = rSearch + 1;
		rSearch = entity.find(",", lSearch);
		newCourse2 = stoi(entity.substr(lSearch, rSearch - lSearch));

		lSearch = rSearch + 1;
		rSearch = entity.find(",", lSearch);
		newCourse3 = stoi(entity.substr(lSearch, rSearch - lSearch));

		//Now find the degree type
		lSearch = rSearch + 1;
		rSearch = entity.find("\"", lSearch);
		temp = entity.substr(lSearch, rSearch - lSearch);
		if (temp == "SOFTWARE")
			newDegree = SOFTWARE;
		else if (temp == "NETWORK")
			newDegree = NETWORK;
		else if (temp =="SECURITY")
			newDegree = SECURITY;
		
		add(newID, newFirst, newLast, newEmail, newAge, newCourse1, newCourse2, newCourse3, newDegree);
}


void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeType degreeType)
{
	
	// Turn individual courses into array
	int courses[Student::daysUntilCompleteSize];
	courses[0] = daysInCourse1;
	courses[1] = daysInCourse2;
	courses[2] = daysInCourse3;

	if (degreeType == SOFTWARE)
		students[lastStudent] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, courses, degreeType);
	else if (degreeType == NETWORK)
		students[lastStudent] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, courses, degreeType);
	else if (degreeType == SECURITY)
		students[lastStudent] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, courses, degreeType);
}

void Roster::remove(string studentRemove)
{
	bool exists = false;
	for (int i = 0; i <= lastStudent; i++)
	{
		if ((this->students)[i]->getStudentID() == studentRemove)
		{
			exists = true;
			delete (this->students)[i];
			(this->students)[i] = (this->students)[lastStudent];
			lastStudent--;
		}
	}
	if (exists == true)
		cout << "Student " << studentRemove << " has been removed!" << endl;
	else
		cout << "Student not found!" << endl;

}


void Roster::printAll()
{
	for (int i = 0; i <= this->lastStudent; i++) 
		(this->students)[i]->print();
	cout << endl;
}



void Roster::printDaysInCourse(string studentID)
{
	bool exists = false;
	for (int i = 0; i <= lastStudent; i++)
	{
		if ((this->students[i])->getStudentID() == studentID) 
		{
			exists = true;
			int* days = students[i]->getDaysUntilComplete();
			cout << "The average days left in courses for " << studentID << " is " << (double)((days[0] + days[1] + days[2]) / 3) << endl;
		}
	}
	if (!exists) 
		cout << "Student not found!" << endl;
}


void Roster::printInvalidEmails()
{
	bool exists = false;
	cout << "Invalid Email Addresses: " << endl;
	string currentStudent;

	for (int i = 0; i < lastStudent + 1; i++)
	{
		currentStudent = (this->students)[i]->getEmailAddress();

		if (currentStudent.find("@") == string::npos || currentStudent.find(".") == string::npos || currentStudent.find(" ") != string::npos)
		{
			cout << (this->students)[i]->getStudentID() << " has invalid email - " << currentStudent << endl;
			exists = true;
		}
	}
	if (!exists) 
		cout << "All emails are valid!" << endl;
	cout << endl;
}

void Roster::printByDegreeProgram(int degree)
{
	cout << endl << "Current " << "SOFTWARE" << " Students: " << endl;
	for (int i = 0; i < lastStudent + 1; i++) {
		if ((this->students[i])->getDegreeProgram() == (DegreeType)degree)
			cout << this->students[i]->getFirstName() << " " << this->students[i]->getLastName() << "     ";
	}
	cout << endl << endl;
}

Roster::~Roster()
{
	int i;
	for (i = 0; i <= lastStudent; i++)
		delete (this->students[i]);
	delete students;
}

int main()
{
	int numberStudents = 5;
	const string studentList[5] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Brandon,Blackburn,bblac69@wgu.edu,28,40,50,60,SOFTWARE"
	};

	Roster* classRoster = new Roster(numberStudents);
	for (int i = 0; i < numberStudents; i++)
	{
		classRoster->makeStudent(studentList[i]);
	}


	cout << "C867: Scripting and Programming.\t C++\t 001015925\t Brandon Blackburn" << endl << endl;

	classRoster->printAll();
	classRoster->printInvalidEmails();

	for (int i = 0; i < numberStudents; i++)
		classRoster->printDaysInCourse(classRoster->getStudentAt(i)->getStudentID());

	classRoster->printByDegreeProgram(SOFTWARE);
	classRoster->remove("A3");
	classRoster->remove("A3");

	system("pause");
	return 0;
}