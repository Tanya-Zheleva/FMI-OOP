#include "Grade.h"

void Grade::Free()
{
	delete[] subject;
}

void Grade::CopyFrom(const Grade& other)
{
	SetValue(other.value);
	SetSubject(other.subject);
}

Grade::Grade(double value, const char* subject)
{
	SetValue(value);
	SetSubject(subject);
}

Grade::Grade(Grade& other)
{
	CopyFrom(other);
}

Grade& Grade::operator=(const Grade& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}

	return *this;
}

double Grade::GetValue() const
{
	return value;
}

void Grade::SetValue(double value)
{
	if (value < 2 || value > 6) value = 2;

	this->value = value;
}

const char* Grade::GetSubject() const
{
	return subject;
}

void Grade::SetSubject(const char* subject)
{
	if (!subject || subject[0] == '\0') subject = "None";

	int length = strlen(subject) + 1;
	this->subject = new char[length];
	strcpy_s(this->subject, length, subject);
}

Grade::~Grade()
{
	delete[] subject;
}

std::ostream& operator<<(std::ostream& out, const Grade& grade)
{
	out << grade.subject << ": " << grade.value;

	return out;
}

std::istream& operator>>(std::istream& in, Grade& grade)
{
	double value = 0;
	char newSubj[51];

	in >> value;
	in.getline(newSubj, 50);
	grade.SetValue(value);
	grade.SetSubject(newSubj);

	return in;
}
