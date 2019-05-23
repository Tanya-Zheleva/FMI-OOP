#pragma once
#include "Club.h"

class FolkClub : public Club
{
private:
	int capacity;
	char* singer;

	void SetSinger(const char*);
	void SetVodkaPrice(double);
	void SetWhiskeyPrice(double);

	void CopyFrom(const FolkClub&);
	void Free();

public:
	FolkClub(const char*, double, double, const char*);
	FolkClub(const FolkClub&);
	FolkClub& operator=(const FolkClub&);
	~FolkClub();

	const char* MusicType() const;
	int Capacity() const;
	Club* Clone() const;
	bool AddUser(const User&);

	friend std::ostream& operator<<(std::ostream&, const FolkClub*);
};

FolkClub::FolkClub(const char* name, double vodkaPrice, double whiskeyPrice, const char* singer) : Club(name, vodkaPrice, whiskeyPrice)
{
	capacity = 70;
	users = new User[capacity];
	SetVodkaPrice(vodkaPrice);
	SetWhiskeyPrice(whiskeyPrice);
	SetSinger(singer);
}

FolkClub::FolkClub(const FolkClub& other) : Club(other)
{
	CopyFrom(other);
}

FolkClub& FolkClub::operator=(const FolkClub& other)
{
	if (this != &other)
	{
		Club::operator=(other);
		Free();
		CopyFrom(other);
	}

	return *this;
}

FolkClub::~FolkClub()
{
	Free();
}

void FolkClub::Free()
{
	delete[] singer;
}

void FolkClub::CopyFrom(const FolkClub& other)
{
	SetSinger(other.singer);
	SetVodkaPrice(other.vodkaPrice);
	SetWhiskeyPrice(other.whiskeyPrice);

	capacity = 70;
	users = new User[capacity];

	for (int i = 0; i < other.userCount; i++)
	{
		users[i] = other.users[i];
	}
}

void FolkClub::SetSinger(const char* singer)
{
	if (singer == "" || singer == nullptr)
	{
		singer = "None";
	}

	int len = strlen(singer) + 1;
	this->singer = new char[len];
	strcpy_s(this->singer, len, singer);
}

void FolkClub::SetVodkaPrice(double price)
{
	if (price < 20)
	{
		price = 20;
	}

	vodkaPrice = price;
}

void FolkClub::SetWhiskeyPrice(double price)
{
	if (price < 35)
	{
		price = 35;
	}

	whiskeyPrice = price;
}

Club* FolkClub::Clone() const 
{
	FolkClub* copy = new FolkClub(*this);

	return copy;
}

bool FolkClub::AddUser(const User& user)
{
	if (userCount >= capacity || !user.LikesMusicInClub(MusicType()))
	{
		return false;
	}

	users[userCount] = user;
	userCount++;

	return true;
}

const char* FolkClub::MusicType() const
{
	return "Folk";
}

int FolkClub::Capacity() const
{
	return capacity;
}

//std::ostream& operator<<(std::ostream& os, const FolkClub* club)
//{
//	os << club->name << ' ' << club->vodkaPrice << ' ' << club->whiskeyPrice << ' ' << club->capacity << ' ' << club->singer << std::endl;
//	std::cout << "Users: " << std::endl;
//
//	for (int i = 0; i < club->userCount; i++)
//	{
//		std::cout << club->users[i];
//	}
//
//	return os;
//}
