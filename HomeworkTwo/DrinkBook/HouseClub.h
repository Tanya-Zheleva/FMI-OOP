#pragma once
#include "Club.h"

class HouseClub : public Club
{
private:
	int djCount;
	int capacity;

	void SetVodkaPrice(double);
	void SetWhiskeyPrice(double);
	void SetDjCount(int);

	void CopyFrom(const HouseClub&);
	void Resize();

public:
	HouseClub(const char*, double, double, int);
	HouseClub(const HouseClub&);
	HouseClub& operator=(const HouseClub&);
	~HouseClub();

	const char* MusicType() const;
	int Capacity() const;
	Club* Clone() const;
	bool AddUser(const User&);

	void Print() const;
};

HouseClub::HouseClub(const char* name, double vodkaPrice, double whiskeyPrice, int djCount) : Club(name, vodkaPrice, whiskeyPrice)
{
	capacity = 2;
	users = new User[capacity];
	SetVodkaPrice(vodkaPrice);
	SetWhiskeyPrice(whiskeyPrice);
	SetDjCount(djCount);
}

HouseClub::HouseClub(const HouseClub& other) : Club(other)
{
	CopyFrom(other);
}

HouseClub& HouseClub::operator=(const HouseClub& other)
{
	if (this != &other)
	{
		Club::operator=(other);
		CopyFrom(other);
	}

	return *this;
}

HouseClub::~HouseClub()
{
}

void HouseClub::CopyFrom(const HouseClub& other)
{
	SetVodkaPrice(other.vodkaPrice);
	SetWhiskeyPrice(other.whiskeyPrice);
	SetDjCount(other.djCount);

	capacity = other.capacity;
	users = new User[capacity];

	for (int i = 0; i < other.userCount; i++)
	{
		users[i] = other.users[i];
	}
}

void HouseClub::SetVodkaPrice(double price)
{
	if (price < 30)
	{
		price = 30;
	}

	vodkaPrice = price;
}

void HouseClub::SetWhiskeyPrice(double price)
{
	if (price < 40)
	{
		price = 40;
	}

	whiskeyPrice = price;
}

void HouseClub::SetDjCount(int djCount)
{
	if (djCount <= 0)
	{
		djCount = 1;
	}

	this->djCount = djCount;
}

Club* HouseClub::Clone() const
{
	HouseClub* copy = new HouseClub(*this);

	return copy;
}

bool HouseClub::AddUser(const User& user)
{
	if (!user.LikesMusicInClub(MusicType()))
	{
		return false;
	}

	if (userCount >= capacity)
	{
		Resize();
	}

	users[userCount] = user;
	userCount++;

	return true;
}

void HouseClub::Resize()
{
	User* temp = new User[capacity * 2];

	for (int i = 0; i < capacity; i++)
	{
		temp[i] = users[i];
	}

	capacity *= 2;
	delete[] users;
	users = temp;
}

const char* HouseClub::MusicType() const
{
	return "House";
}

int HouseClub::Capacity() const
{
	return capacity;
}

void HouseClub::Print() const
{
	std::cout << name << ' ' << vodkaPrice << ' ' << whiskeyPrice << ' ' << capacity << ' ' << djCount << std::endl;
	std::cout << "Users: " << std::endl;

	for (int i = 0; i < userCount; i++)
	{
		std::cout << users[i];
	}
}