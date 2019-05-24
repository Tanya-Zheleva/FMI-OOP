#pragma once
#include "FolkClub.h"

class Clubs
{
private:
	int capacity;
	int count;
	Club** clubs;

	bool ContainsClub(const char*) const;
	Club* FindByName(const char*) const;
	bool UserCanPayDrinks(const User&, const char*, double) const;
	bool UserCanEnterClub(const User&, const char*) const;

	void Resize();
	void CopyFrom(const Clubs&);
	void Free();

public:
	Clubs();
	Clubs(const Clubs&);
	Clubs& operator=(const Clubs&);
	~Clubs();

	bool AddFolkClub(const char*, double, double, const char*);
	bool AddRockClub(const char*, double, double);
	bool AddHouseClub(const char*, double, double, int);
	bool AddToClub(User&, const char*);
	bool RemoveFromClub(const char*, const char*);

	int Capacity() const;
	int Count() const;
	void Print() const;
};

Clubs::Clubs()
{
	capacity = 2;
	count = 0;
	clubs = new Club*[capacity];
}

Clubs::Clubs(const Clubs& other)
{
	CopyFrom(other);
}

Clubs& Clubs::operator=(const Clubs& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}

	return *this;
}

Clubs::~Clubs()
{
	Free();
}

void Clubs::CopyFrom(const Clubs& other)
{
	clubs = new Club*[other.capacity];
	capacity = other.capacity;
	count = other.count;

	for (size_t i = 0; i < count; i++)
	{
		clubs[i] = other.clubs[i]->Clone();
	}
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

bool Clubs::ContainsClub(const char* name) const 
{
	for (int i = 0; i < count; i++)
	{
		if (!strcmp(clubs[i]->GetName(), name))
		{
			return true;
		}
	}

	return false;
}

Club* Clubs::FindByName(const char* name) const
{
	for (int i = 0; i < count; i++)
	{
		if (!strcmp(clubs[i]->GetName(), name))
		{
			return clubs[i];
		}
	}

	return nullptr;
}

bool Clubs::UserCanPayDrinks(const User& user, const char* clubName, double currentCash) const
{
	Club* club = FindByName(clubName);

	currentCash -= club->GetVodkaPrice() * user.GetVodkas() + club->GetWhiskeyPrice() * user.GetWhiskeys();

	if (currentCash < 0)
	{
		return false;
	}

	return true;
}

bool Clubs::UserCanEnterClub(const User& user, const char* clubName) const
{
	Club* club = FindByName(clubName);
	
	if (!user.LikesMusicInClub(club->MusicType()))
	{
		return false;
	}

	if (user.GetAge() >= 18)
	{
		return true;
	}

	if (!strcmp(club->MusicType(), "Rock") || !strcmp(club->MusicType(), "House"))
	{
		return false;
	}

	if (user.GetCash() < 20)
	{
		return false;
	}

	return true;
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

bool Clubs::AddHouseClub(const char* name, double vodkaPrice, double whiskeyPrice, int djCount)
{
	if (vodkaPrice < 30 || whiskeyPrice < 40)
	{
		return false;
	}

	if (count >= capacity)
	{
		Resize();
	}

	Club* club = new HouseClub(name, vodkaPrice, whiskeyPrice, djCount);
	clubs[count] = club;
	count++;

	return true;
}

bool Clubs::AddRockClub(const char* name, double vodkaPrice, double whiskeyPrice)
{
	if (vodkaPrice < 40 || whiskeyPrice < 30)
	{
		return false;
	}

	if (count >= capacity)
	{
		Resize();
	}

	Club* club = new RockClub(name, vodkaPrice, whiskeyPrice);
	clubs[count] = club;
	count++;

	return true;
}

bool Clubs::AddToClub(User& user, const char* clubName)
{
	if (!ContainsClub(clubName) || !UserCanEnterClub(user, clubName))
	{
		return false;
	}

	Club* club = FindByName(clubName);
	double currentCash = user.GetCash();

	if (user.GetAge() < 18 && !strcmp(club->MusicType(), "Folk"))
	{
		currentCash -= 20;
	}

	if (!UserCanPayDrinks(user, clubName, currentCash))
	{
		return false;
	}

	currentCash -= club->GetVodkaPrice() * user.GetVodkas() + club->GetWhiskeyPrice() * user.GetWhiskeys();
	user.SetCash(currentCash);

	club->AddUser(user);

	return true;
}

bool Clubs::RemoveFromClub(const char* userName, const char* clubName)
{
	if (!ContainsClub(clubName))
	{
		return false;
	}

	Club* club = FindByName(clubName);

	return club->RemoveUser(userName);
}

void Clubs::Print() const
{
	std::cout << "All clubs: " << std::endl;

	for (int i = 0; i < count; i++)
	{
		std::cout << clubs[i]->MusicType() << ' ' << "club ";
		clubs[i]->Print();
	}
}