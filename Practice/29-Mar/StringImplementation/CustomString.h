#pragma once

class CustomString
{
private:
	int index;
	char* characters;

	void SetString();

public:
	CustomString(); //default
	CustomString(const CustomString&); //copy
	CustomString(const CustomString&, int, int = 4); //substring
	CustomString(const char*); //from string
	CustomString(const char*, int); //from sequence

	int Length() const;
};