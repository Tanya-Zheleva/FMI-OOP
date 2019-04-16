#include "Student.h"
#include "Person.h"

Person::Person(const char* name, int id, int number)
{
	SetName(name);
	SetId(id);
	SetNumber(number);
}

Person::Person(const Person& other)
{
	CopyPerson(other);
}

Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		Free();
		CopyPerson(other);
	}

	return *this;
}

void Person::CopyPerson(const Person& other)
{
	SetName(other.name);
	SetId(other.id);
	SetNumber(other.number);
}

void Person::Free()
{
	delete[] name;
}

void Person::SetName(const char* name)
{
	if (!name || name[0] == '\0')
	{
		name = "Unknown";
	}

	int length = strlen(name) + 1;

	this->name = new char[length];
	strcpy_s(this->name, length, name);
}

const char* Person::GetName() const
{
	return name;
}

void Person::SetId(int id)
{
	if (id < 100000000 || id > 999999999) id = 100000000;

	this->id = id;
}

int Person::GetId() const
{
	return id;
}

void Person::SetNumber(int number)
{
	this->number = number;
}

int Person::GetNumber() const
{
	return number;
}

Person::~Person()
{
	delete[] name;
}
