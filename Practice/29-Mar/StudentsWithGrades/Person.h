#pragma once
#include <iostream>

class Person
{
private:
	void CopyPerson(const Person& other);
	void Free();

protected:
	char* name;
	int id;
	int number;
	void SetName(const char*);
	void SetId(int);
	void SetNumber(int);

public:
	Person(const char*, int, int);
	Person(const Person&);
	Person& operator=(const Person&);

	const char* GetName() const;
	int GetId() const;
	int GetNumber() const;

	~Person();

	friend std::ostream& operator<<(std::ostream&, const Person&);
};