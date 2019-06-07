#pragma once
#include "User.h"
#include <iostream>

class Club
{
private:
	void SetName(const char*);
	int IndexOfRemoved(const char*);

	void CopyFrom(const Club&);
	void Free();

protected:
	char* name;
	double vodkaPrice;
	double whiskeyPrice;
	User* users;
	int userCount;
	int capacity;

	Club(const char*, double, double);
	Club(const Club&);
	Club& operator=(const Club&);

public:
	virtual ~Club();

	const char* GetName() const;
	double GetVodkaPrice() const;
	double GetWhiskeyPrice() const;
	int GetUserCount() const;
	bool ContainsUser(const char*) const;
	bool RemoveUser(const char*);

	virtual const char* MusicType() const = 0; 
	virtual int Capacity() const = 0;
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
	vodkaPrice = other.vodkaPrice;
	whiskeyPrice = other.whiskeyPrice;	
	capacity = other.capacity;

	users = new User[capacity];

	for (int i = 0; i < other.userCount; i++)
	{
		users[i] = other.users[i];
	}
}

void Club::SetName(const char* name)
{
	if (name == "" || name == nullptr)
	{
		name = "None";
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

bool Club::ContainsUser(const char* userName) const
{
	for (int i = 0; i < userCount; i++)
	{
		if (!strcmp(users[i].GetName(), userName))
		{
			return true;
		}
	}

	return false;
}

int Club::IndexOfRemoved(const char* userName)
{
	for (int i = 0; i < userCount; i++)
	{
		if (!strcmp(users[i].GetName(), userName))
		{
			return i;
		}
	}

	return -1;
}

bool Club::RemoveUser(const char* userName)
{
	if (!ContainsUser(userName))
	{
		return false;
	}

	int index = IndexOfRemoved(userName);

	for (int i = index; i < userCount - 1; i++)
	{
		users[i] = users[i + 1];
	}

	userCount--;

	return true;
}