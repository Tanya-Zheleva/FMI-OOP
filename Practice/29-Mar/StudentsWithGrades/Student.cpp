#include "Grade.h"
#include "Student.h"
#include "Speciality.h"

Student::Student(int fn, const char* name, const Grade* grades, int gradesCount, const Speciality spec)
{
	SetFacultyNumber(fn);
	SetName(name);
	SetGradesCount(gradesCount);
	SetGrades(grades, gradesCount);
	SetSpeciality(spec);
}

Student::Student(const Student& other)
{
	if (this != &other)
	{
		SetFacultyNumber(other.m_facultyNumber);
		SetName(other.m_name);
		SetGradesCount(other.m_gradesCount);
		SetGrades(other.m_grades, other.m_gradesCount);
		SetSpeciality(other.m_speciality);
	}
}

Student& Student::operator=(const Student& other)
{
	if (this != &other)
	{
		SetFacultyNumber(other.m_facultyNumber);
		SetName(other.m_name);
		SetGradesCount(other.m_gradesCount);
		SetGrades(other.m_grades, other.m_gradesCount);
		SetSpeciality(other.m_speciality);
	}

	return *this;
}

int Student::GetFacultyNumber() const
{
	return m_facultyNumber;
}

void Student::SetFacultyNumber(int fn)
{
	if (fn < 10000 || fn > 99999)
	{
		fn = 10000;
	}

	m_facultyNumber = fn;
}

const char* Student::GetName() const
{
	return m_name;
}

void Student::SetName(const char* name)
{
	delete[] m_name;

	if (!name || name[0] == '\0')
	{
		name = "Unknown";
	}

	int length = strlen(name) + 1;

	m_name = new char[length];
	strcpy_s(m_name, length, name);
}

int Student::GetGradesCount() const
{
	return m_gradesCount;
}

void Student::SetGradesCount(int count)
{
	if (count < 0)
	{
		count = 0;
	}

	m_gradesCount = count;
}

const Grade* Student::GetGrades() const
{
	return m_grades;
}

void Student::SetGrades(const Grade* grades, int count)
{
	delete[] m_grades;

	m_grades = new Grade[count];

	for (int i = 0; i < count; i++)
	{
		m_grades[i] = grades[i];
	}
}

const Speciality Student::GetSpeciality() const
{
	return m_speciality;
}

void Student::SetSpeciality(const Speciality spec)
{
	m_speciality = spec;
}

Student::~Student()
{
	delete[] m_name;
	delete[] m_grades;
}

std::ostream& operator<<(std::ostream& out, const Student& student)
{
	out << student.m_name << " " << student.m_facultyNumber << " " << student.m_speciality << " Grades: ";

	int gradesCount = student.m_gradesCount;
	
	for (int i = 0; i < gradesCount; i++)
	{
		out << student.m_grades[i].GetSubject() << ": " << student.m_grades[i].GetValue() << ' ';
	}

	return out;
}

std::istream& operator>>(std::istream in, Student& student)
{


	return in;
}