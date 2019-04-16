#pragma once
#include <iostream>

class Grade
{
private:
	double value;
	char* subject;

	void SetValue(double);
	void SetSubject(const char*);
	void CopyFrom(const Grade&);
	void Free();

public:
	Grade(double = 2.0, const char* = "None");
	Grade(Grade& other);
	Grade& operator=(const Grade& other);

	double GetValue() const;
	const char* GetSubject() const;	

	~Grade();

	friend std::ostream& operator<<(std::ostream&, const Grade&);
	friend std::istream& operator>>(std::istream&, Grade&);
};