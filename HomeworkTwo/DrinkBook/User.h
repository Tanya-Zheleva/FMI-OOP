#pragma once
#include <iostream>

class User
{
private:
	char* name;
	int age;
	double cash;
	int vodkas;
	int whiskeys;
	char* music;

	void SetName(const char*);
	void SetAge(int);
	void SetVodkas(int);
	void SetWhiskeys(int);
	void SetMusic(const char*);

	void CopyFrom(const User&);
	void Free();

public:
	User(const char* = "", int = 18, double = 50, int = 2, int = 2, const char* = "");
	User(const User&);
	User& operator=(const User&);
	~User();

	const char* GetName() const;
	int GetAge() const;
	void SetCash(double);
	double GetCash() const;
	const char* GetMusic() const;

	bool LikesMusicInClub(const char*);

	friend std::ostream& operator<<(std::ostream&, const User&);
};

User::User(const char* name, int age, double cash, int vodkas, int whiskeys, const char* music)
{
	SetName(name);
	SetAge(age);
	SetCash(cash);
	SetVodkas(vodkas);
	SetWhiskeys(whiskeys);
	SetMusic(music);
}

User::User(const User& other)
{
	CopyFrom(other);
}

User& User::operator=(const User& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}

	return *this;
}

User::~User()
{
	Free();
}

void User::Free()
{
	delete[] name;
	delete[] music;
}

void User::CopyFrom(const User& other)
{
	SetName(other.name);
	SetAge(other.age);
	SetCash(other.cash);
	SetVodkas(other.vodkas);
	SetWhiskeys(other.whiskeys);
	SetMusic(other.music);
}

void User::SetName(const char* name)
{
	if (name == "" || name == nullptr)
	{
		name = "Unknown";
	}

	int len = strlen(name) + 1;
	this->name = new char[len];
	strcpy_s(this->name, len, name);
}

void User::SetAge(int age)
{
	if (age <= 0)
	{
		age = 1;
	}

	this->age = age;

}

void User::SetVodkas(int vodkas)
{
	if (vodkas < 0)
	{
		vodkas = 2;
	}

	this->vodkas = vodkas;
}

void User::SetWhiskeys(int whiskeys)
{
	if (whiskeys < 0)
	{
		whiskeys = 2;
	}

	this->whiskeys = whiskeys;

}

void User::SetCash(double cash)
{
	if (cash < 0)
	{
		cash = 0;
	}

	this->cash = cash;
}

void User::SetMusic(const char* music)
{
	if (music == "" || music == nullptr)
	{
		music = "Everything";
	}

	int len = strlen(music) + 1;
	this->music = new char[len];
	strcpy_s(this->music, len, music);
}

const char* User::GetName() const
{
	return name;
}

int User::GetAge() const
{
	return age;
}

double User::GetCash() const
{
	return cash;
}

const char* User::GetMusic() const
{
	return music;
}

bool User::LikesMusicInClub(const char* music)
{
	return false;
}

std::ostream& operator<<(std::ostream& os, const User& user)
{
	std::cout << user.name << ' ' << user.age << ' ' << user.cash << ' ' << user.vodkas << ' ' << user.whiskeys << ' ' << user.music << std::endl;

	return os;
}