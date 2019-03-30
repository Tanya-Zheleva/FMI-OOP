#pragma once
#include <iostream>

class Grade
{
private:
	double m_value;
	char* m_subject;

	void SetValue(double);
	void SetSubject(const char*);

public:
	Grade();
	Grade(double, const char*);
	Grade(Grade& other);
	Grade& operator=(const Grade& other);

	double GetValue() const;
	const char* GetSubject() const;	

	~Grade();

	friend std::ostream& operator<<(std::ostream&, const Grade&);
	friend std::istream& operator>>(std::istream&, Grade&);
};