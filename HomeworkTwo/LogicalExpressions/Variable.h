#pragma once
#include <iostream>
#include "BooleanExpression.h"

class Variable : public BooleanExpression
{
private:
	char name;
	bool Evaluate() const;
	bool EvaluateWithFalse() const;

public:
	Variable(const char);
	~Variable() {}

	void Print() const;
	int CountVariables();
	bool IsContradiction() const;
	bool IsTautology() const;
	bool IsContingency() const;

	void Fill(char*, int&);
	int CountRepeatingVariables() const;
};

Variable::Variable(const char name)
{
	this->name = name;
}

void Variable::Print() const
{
	std::cout << name;
}

int Variable::CountVariables()
{
	return 1;
}

bool Variable::IsContradiction() const
{
	return false;
}

bool Variable::IsContingency() const
{
	return false;
}

bool Variable::IsTautology() const
{
	return true;
}

bool Variable::Evaluate() const
{
	return true;
}

bool Variable::EvaluateWithFalse() const
{
	return false;
}

void Variable::Fill(char* list, int& index)
{
	list[index] = name;
	index++;
}

int Variable::CountRepeatingVariables() const
{
	return 1;
}