#pragma once
#include <iostream>
#include "BooleanExpression.h"

class Variable : public BooleanExpression
{
private:
	char name;
	bool Evaluate();// const;
	bool TestT();

public:
	Variable(const char);
	~Variable() {}

	void Print() const;
	int CountVariables() const;
	bool IsContradiction() const;
	bool IsTautology() const;
	bool IsContingency() const;
};

Variable::Variable(const char name)
{
	this->name = name;
}

void Variable::Print() const
{
	std::cout << name;
}

int Variable::CountVariables() const
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

bool Variable::Evaluate() //const
{
	/*whenOneVar1 = true;
	whenOneVar2 = false;*/

	return true;
}


bool Variable::TestT()
{
	return true;
}