#pragma once

class User
{
private:
	char* name;
	int age;
	double cash;
	int vodkas;
	int whiskeys;
	char* music;

	void CopyFrom(const User&);
	void Free();

public:
	//User(const char* = "", int = 18, double = 50, int = 2, int = 2, const char* = "");
	//User(const User&);
	//User& operator=(const User&);
	~User();


};

User::~User()
{
	delete[] name;
	delete[] music;
}
