#include "Grade.h"
#include "Student.h"
#include "Speciality.h"

void Student::Free()
{
	delete[] grades;
}

void Student::CopyStudent(const Student& other)
{
	SetFacultyNumber(other.facultyNumber);
	SetGradesCount(other.gradesCount);
	SetGrades(other.grades, other.gradesCount);
	SetSpeciality(other.speciality);
}

Student::Student(const char* name, int id, int number, int fn, const Grade* grades, int gradesCount, const Speciality spec)
	: Person(name, id, number)
{
	SetFacultyNumber(fn);
	SetGradesCount(gradesCount);
	SetGrades(grades, gradesCount);
	SetSpeciality(spec);
}

Student::Student(const Student& other) : Person(other)
{
	CopyStudent(other);
}

Student& Student::operator=(const Student& other)
{
	if (this != &other)
	{
		Person::operator=(other);
		CopyStudent(other);
	}

	return *this;
}

int Student::GetFacultyNumber() const
{
	return facultyNumber;
}

void Student::SetFacultyNumber(int fn)
{
	if (fn < 10000 || fn > 99999) fn = 10000;

	facultyNumber = fn;
}

int Student::GetGradesCount() const
{
	return gradesCount;
}

void Student::SetGradesCount(int count)
{
	if (count < 0) count = 0;

	gradesCount = count;
}

const Grade* Student::GetGrades() const
{
	return grades;
}

void Student::SetGrades(const Grade* grades, int count)
{
	this->grades = new Grade[count];

	for (int i = 0; i < count; i++) this->grades[i] = grades[i];
}

const Speciality Student::GetSpeciality() const
{
	return speciality;
}

void Student::SetSpeciality(const Speciality spec)
{
	speciality = spec;
}

Student::~Student()
{
	Free();
}

std::ostream& operator<<(std::ostream& out, const Student& student)
{
	out << student.name << " " << student.facultyNumber << " " << student.speciality << " Grades: ";

	int gradesCount = student.gradesCount;

	for (int i = 0; i < gradesCount; i++)
	{
		out << student.grades[i].GetSubject() << ": " << student.grades[i].GetValue() << ' ';
	}

	return out;
}