#pragma once
#include "Club.h"

class FolkClub : public Club
{
private:
	int capacity;
	char* singer;

	void CopyFrom(const FolkClub&);
	void SetSinger(const char*);

public:
	FolkClub(const char*, double, double, const char*);
	FolkClub(const Club&);
	~FolkClub();

	Club* Clone();
	void AddUser(const User&);


	void Print() const;
};

FolkClub::FolkClub(const char* name, double vodkaPrice, double whiskeyPrice, const char* singer) : Club(name, vodkaPrice, whiskeyPrice)
{
	capacity = 70;
	users = new User[capacity];
	SetSinger(singer);
}

FolkClub::FolkClub(const Club& other) : Club(other)
{
	CopyFrom(other.Clone());
}

FolkClub::~FolkClub()
{
	delete[] singer;
}

void FolkClub::CopyFrom(const FolkClub& other)
{
	SetSinger(other.singer);
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


Club* FolkClub::Clone()
{
	FolkClub* copy = new FolkClub(*this);

	return copy;
}

void FolkClub::AddUser(const User& user)
{

}


void FolkClub::Print() const
{
	std::cout << name << ' ' << vodkaPrice << ' ' << whiskeyPrice << ' ' << capacity << ' ' << singer << std::endl;
}
