#pragma once
#include "Grade.h"
#include "Speciality.h"
#include "Person.h"

class Student : public Person
{
private:
	int facultyNumber;
	int gradesCount;
	Grade* grades;
	Speciality speciality;

	void SetFacultyNumber(int);
	void SetGradesCount(int);
	void SetGrades(const Grade*, int);
	void SetSpeciality(const Speciality);

	void CopyStudent(const Student&);
	void Free();

public:
	Student(const char*, int, int, int, const Grade*, int,  const Speciality);
	Student(const Student&);
	Student& operator=(const Student&);

	int GetFacultyNumber() const;
	int GetGradesCount() const;
	const Grade* GetGrades() const;
	const Speciality GetSpeciality() const;

	~Student();

	friend std::ostream& operator<<(std::ostream&, const Student&);
};
