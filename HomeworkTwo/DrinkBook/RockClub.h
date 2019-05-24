#pragma once
#include "Club.h"

class RockClub : public Club
{
private:
	int capacity;

	void SetVodkaPrice(double);
	void SetWhiskeyPrice(double);

	void CopyFrom(const RockClub&);

public:
	RockClub(const char*, double, double);
	RockClub(const RockClub&);
	RockClub& operator=(const RockClub&);
	~RockClub();

	const char* MusicType() const;
	int Capacity() const;
	Club* Clone() const;
	bool AddUser(const User&);
	void Print() const;
};

RockClub::RockClub(const char* name, double vodkaPrice, double whiskeyPrice) : Club(name, vodkaPrice, whiskeyPrice)
{
	capacity = 30;
	users = new User[capacity];
	SetVodkaPrice(vodkaPrice);
	SetWhiskeyPrice(whiskeyPrice);
}

RockClub::RockClub(const RockClub& other) : Club(other)
{
	CopyFrom(other);
}

RockClub& RockClub::operator=(const RockClub& other)
{
	if (this != &other)
	{
		Club::operator=(other);
		CopyFrom(other);
	}

	return *this;
}

RockClub::~RockClub()
{
}

void RockClub::CopyFrom(const RockClub& other)
{
	SetVodkaPrice(other.vodkaPrice);
	SetWhiskeyPrice(other.whiskeyPrice);

	capacity = 30;
	users = new User[capacity];

	for (int i = 0; i < other.userCount; i++)
	{
		users[i] = other.users[i];
	}
}

void RockClub::SetVodkaPrice(double price)
{
	if (price < 40)
	{
		price = 40;
	}

	vodkaPrice = price;
}

void RockClub::SetWhiskeyPrice(double price)
{
	if (price < 30)
	{
		price = 30;
	}

	whiskeyPrice = price;
}

Club* RockClub::Clone() const
{
	RockClub* copy = new RockClub(*this);

	return copy;
}

bool RockClub::AddUser(const User& user)
{
	if (userCount >= capacity || !user.LikesMusicInClub(MusicType()))
	{
		return false;
	}

	users[userCount] = user;
	userCount++;

	return true;
}

const char* RockClub::MusicType() const
{
	return "Rock";
}

int RockClub::Capacity() const
{
	return capacity;
}

void RockClub::Print() const
{
	std::cout << name << ' ';
	std::cout << "vodka price: " << vodkaPrice << ", ";
	std::cout << "whiskey price: " << whiskeyPrice << ", ";
	std::cout << "capacity: " << capacity << std::endl;
	std::cout << "Users: " << std::endl;

	for (int i = 0; i < userCount; i++)
	{
		std::cout << users[i];
	}

	std::cout << std::endl;
}