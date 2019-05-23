#pragma once
#include "FolkClub.h"

class Clubs
{
private:
	int capacity;
	int count;
	Club** clubs;

	void Resize();
	void CopyFrom(const Clubs&);
	void Free();

public:
	Clubs();
	~Clubs();

	bool AddFolkClub(const char*, double, double, const char*);
	bool AddRockClub(const char*, double, double);
	bool AddHouseClub(const char*, double, double, int);

	bool AddToClub(const User&, const char*);
	bool RemoveFromClub(const char*, const char*);

	int Capacity() const;
	int Count() const;

	friend std::ostream& operator<<(std::ostream&, const Clubs&);
};

Clubs::Clubs()
{
	capacity = 2;
	count = 0;
	clubs = new Club*[capacity];
}

Clubs::~Clubs()
{
	Free();
}

void Clubs::Free()
{
	delete[] clubs;
}

void Clubs::Resize()
{
	Club** temp = new Club*[capacity * 2];

	for (int i = 0; i < count; i++)
	{
		temp[i] = clubs[i];
	}

	capacity *= 2;
	delete[] clubs;
	clubs = temp;
}

int Clubs::Capacity() const
{
	return capacity;
}

int Clubs::Count() const
{
	return count;
}

bool Clubs::AddFolkClub(const char* name, double vodkaPrice, double whiskeyPrice, const char* singer)
{
	if (vodkaPrice < 20 || whiskeyPrice < 35)
	{
		return false;
	}

	if (count >= capacity)
	{
		Resize();
	}


	Club* club = new FolkClub(name, vodkaPrice, whiskeyPrice, singer);
	clubs[count] = club;
	count++;

	return true;
}

std::ostream& operator<<(std::ostream& os, const Clubs& clubs)
{
	os << "All clubs: " << std::endl;

	for (int i = 0; i < clubs.count; i++)
	{
		os << "Club: " << clubs.clubs[i]->GetName();
		os << ", vodka price: " << clubs.clubs[i]->GetVodkaPrice();
	}

	return os;
}