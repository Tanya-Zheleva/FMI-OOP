#pragma once
#include "User.h"
#include <iostream>

class Club
{
private:
	void SetName(const char*);

	void CopyFrom(const Club&);
	void Free();

protected:
	char* name;
	double vodkaPrice;
	double whiskeyPrice;
	User* users;
	int userCount;

	Club(const char*, double, double);
	Club(const Club&);
	Club& operator=(const Club&);

	virtual void SetVodkaPrice(double) = 0;
	virtual void SetWhiskeyPrice(double) = 0;

public:
	virtual ~Club();

	const char* GetName() const;
	double GetVodkaPrice() const;
	double GetWhiskeyPrice() const;
	int GetUserCount() const;

	virtual Club* Clone() const = 0;
	virtual bool AddUser(const User&) = 0;
	virtual void Print() const = 0;
};

Club::Club(const char* name, double vodkaPrice, double whiskeyPrice)
{
	userCount = 0;
	SetName(name);
}

Club::Club(const Club& other)
{
	CopyFrom(other);
}

Club& Club::operator=(const Club& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}

	return *this;
}

Club::~Club()
{
	Free();
}

void Club::Free()
{
	delete[] name;
	delete[] users;
}

void Club::CopyFrom(const Club& other)
{
	SetName(other.name);
	userCount = other.userCount;
}

void Club::SetName(const char* name)
{
	if (name == "" || name == nullptr)
	{
		name = "33";
	}

	int len = strlen(name) + 1;
	this->name = new char[len];
	strcpy_s(this->name, len, name);
}

const char* Club::GetName() const
{
	return name;
}

double Club::GetVodkaPrice() const
{
	return vodkaPrice;
}

double Club::GetWhiskeyPrice() const
{
	return whiskeyPrice;
}

int Club::GetUserCount() const
{
	return userCount;
}
