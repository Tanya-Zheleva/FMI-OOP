#pragma once
#include "Person.h"

class Teacher : public Person
{
private:
	char* subject;

	void SetSubject(const char*);
	void CopyFrom(const Teacher&);
	void Free();

public:
	Teacher(const char*, int, int, const char*);
	Teacher(const Teacher&);
	Teacher& operator=(const Teacher&);
	~Teacher();

	const char* GetSubject() const;

	friend std::ostream& operator<<(std::ostream&, const Teacher&);
};