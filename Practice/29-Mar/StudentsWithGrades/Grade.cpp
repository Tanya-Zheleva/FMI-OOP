#include "Grade.h"

Grade::Grade()
{
	SetValue(2);
	SetSubject("None");
}

Grade::Grade(double value, const char* subject)
{
	SetValue(value);
	SetSubject(subject);
}

Grade::Grade(Grade& other)
{
	if (this != &other)
	{
		SetValue(other.m_value);
		SetSubject(other.m_subject);
	}
}

Grade& Grade::operator=(const Grade& other)
{
	if (this != &other)
	{
		SetValue(other.m_value);
		SetSubject(other.m_subject);
	}

	return *this;
}

double Grade::GetValue() const
{
	return m_value;
}

void Grade::SetValue(double value)
{
	if (value < 2 || value > 6)
	{
		value = 2;
	}

	m_value = value;
}

const char* Grade::GetSubject() const
{
	return m_subject;
}

void Grade::SetSubject(const char* subject)
{
	//delete[] m_subject;

	if (!subject || subject[0] == '\0')
	{
		subject = "None";
	}

	int length = strlen(subject) + 1;
	m_subject = new char[length];
	strcpy_s(m_subject, length, subject);
}

Grade::~Grade()
{
	delete[] m_subject;
}