#pragma once
#include <iostream>
#include "BooleanExpression.h"

class Operation : public BooleanExpression
{
private:
	BooleanExpression* left;
	char operation[4];
	BooleanExpression* right;

	bool Evaluate();// const;
	bool TestT();
	bool EvalueateWithOperation(bool, bool);

public:
	Operation(BooleanExpression*, const char[4], BooleanExpression*);
	Operation(const Operation&) = delete;
	Operation& operator=(const Operation&) = delete;
	~Operation();

	void Print() const;
	int CountVariables() const;
	bool IsContradiction() const;
	bool IsTautology() const;
	bool IsContingency() const;
};

Operation::Operation(BooleanExpression* left, const char operation[4], BooleanExpression* right = nullptr)
{
	this->left = left;
	strcpy_s(this->operation, 4, operation);
	this->right = right;
}

Operation::~Operation()
{
	delete left;
	
	if (right)
	{
		delete right;
	}
}

void Operation::Print() const
{
	if (right == nullptr)
	{
		std::cout << '(';
		left->Print();
		std::cout << operation;
		std::cout << ')';
	}
	else
	{
		std::cout << '(';
		left->Print();
		std::cout << ' ' << operation << ' ';
		right->Print();
		std::cout << ')';
	}
}

int Operation::CountVariables() const
{
	int count = left->CountVariables();
	
	if (right)
	{
		count += right->CountVariables();
	}

	return count;
}

bool Operation::IsContradiction() const
{
	return true;
}

bool Operation::IsContingency() const
{
	return !IsTautology() && !IsContradiction();
}

bool Operation::IsTautology() const
{
	if (right)
	{
		
	}

	return false;
}

bool Operation::Evaluate() //const
{
	bool result = left->Evaluate();
	
	if (right)
	{
		bool secondValue = right->Evaluate();

		if (!strcmp(operation, "^"))
		{
			/*firstCase = !result && !secondValue;
			secondCase = !result && secondValue;
			thridCase = result && !secondValue;
			fourthCase = result && secondValue;*/
			result = result && secondValue;
		}
		else if (!strcmp(operation, "|"))
		{
			/*firstCase = !result || !secondValue;
			secondCase = !result || secondValue;
			thridCase = result || !secondValue;
			fourthCase = result || secondValue;*/
			result = result || secondValue;
		}
		else if (!strcmp(operation, "+"))
		{
			/*firstCase = !result ^ !secondValue;
			secondCase = !result ^ secondValue;
			thridCase = result ^ !secondValue;
			fourthCase = result ^ secondValue;*/
			result = result ^ secondValue;
		}
		else if (!strcmp(operation, "->"))
		{
			/*firstCase = result || !secondValue;
			secondCase = result || secondValue;
			thridCase = !result || !secondValue;
			fourthCase = !result || secondValue;*/
			result = !result || secondValue;
		}
		else if (!strcmp(operation, "<->"))
		{
			/*firstCase = result == !secondValue;
			secondCase = result == secondValue;
			thridCase = !result == !secondValue;
			fourthCase = !result == secondValue;*/
			result = result == secondValue;
		}
	}
	else
	{
		/*whenOneVar1 = false;
		whenOneVar2 = true;
		return whenOneVar1 && whenOneVar2;*/

		return !result;
	}
	//return firstCase && secondCase && thridCase && fourthCase;

	return result;
}



bool Operation::TestT() {
	if (!right)
	{
		return false;
	}

	bool bothF = EvalueateWithOperation(!left->Evaluate(), !right->Evaluate());
	bool leftF = EvalueateWithOperation(!left->Evaluate(), right->Evaluate());
	bool rightF = EvalueateWithOperation(left->Evaluate(), !right->Evaluate());
	bool bothT = EvalueateWithOperation(left->Evaluate(), right->Evaluate());

	return bothF && leftF && rightF && bothT;
}

bool Operation::EvalueateWithOperation(bool l, bool r)
{
	if (!strcmp(operation, "^"))
	{
		return l && r;
	}
	else if (!strcmp(operation, "|"))
	{
		return l || r;
	}
	else if (!strcmp(operation, "+"))
	{
		return l ^ r;
	}
	else if (!strcmp(operation, "->"))
	{
		return !l || r;
	}
	else if (!strcmp(operation, "<->"))
	{
		return l == r;
	}

	return false;
}