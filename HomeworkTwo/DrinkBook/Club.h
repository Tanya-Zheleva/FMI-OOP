#pragma once
#include "User.h"
#include <iostream>

class Club
{
private:
	void SetName(const char*);
	void SetVodkaPrice(double);
	void SetWhiskeyPrice(double);

	void CopyFrom(const Club&);

protected:
	char* name;
	double vodkaPrice;
	double whiskeyPrice;
	User* users;
	int userCount;


	Club(const char*, double, double);
	Club(const Club&);
	Club& operator=(const Club&);

public:
	virtual ~Club();

	const char* GetName() const;
	double GetVodkaPrice() const;
	double GetWhiskeyPrice() const;

	virtual Club* Clone() = 0;
	virtual void AddUser(const User&) = 0;
	virtual void Print() const = 0;
};

Club::Club(const char* name, double vodkaPrice, double whiskeyPrice)
{
	userCount = 0;
	SetName(name);
	SetVodkaPrice(vodkaPrice);
	SetWhiskeyPrice(whiskeyPrice);
}

Club::Club(const Club& other)
{
	CopyFrom(other);
}

Club::~Club()
{
	delete[] name;
	delete[] users;
}

void Club::CopyFrom(const Club& other)
{
	SetName(other.name);
	SetVodkaPrice(vodkaPrice);
	SetWhiskeyPrice(whiskeyPrice);
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

void Club::SetVodkaPrice(double price)
{
	if (price < 0)
	{
		price = 7;
	}

	vodkaPrice = price;
}

void Club::SetWhiskeyPrice(double price)
{
	if (price < 0)
	{
		price = 7;
	}

	whiskeyPrice = price;
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


