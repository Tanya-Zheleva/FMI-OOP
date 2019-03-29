#pragma once
#include "Grade.h"
#include "Speciality.h"

class Student
{
private:
	int m_facultyNumber;
	char* m_name;
	int m_gradesCount;
	Grade* m_grades;
	Speciality m_speciality;

	void SetFacultyNumber(int);
	void SetName(const char*);
	void SetGradesCount(int);
	void SetGrades(const Grade*, int);
	void SetSpeciality(const Speciality);

public:
	Student(int, const char*, const Grade*, int,  const Speciality);
	Student(const Student&);
	Student& operator=(const Student&);

	int GetFacultyNumber() const;
	const char* GetName() const;
	int GetGradesCount() const;
	const Grade* GetGrades() const;
	const Speciality GetSpeciality() const;

	~Student();
};
