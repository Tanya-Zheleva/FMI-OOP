#pragma once
#include <iostream>
#include "BooleanExpression.h"

class Operation : public BooleanExpression
{
private:
	BooleanExpression* left;
	char operation;
	BooleanExpression* right;
	char* variableList;
	int variablesFound;

	bool Evaluate() const;
	//bool EvalueateWithOperation(bool, bool) const;
	void Fill(char*, int&);

public:
	int CountRepeatingVariables() const;
	Operation(BooleanExpression*, const char, BooleanExpression*);
	Operation(const Operation&) = delete;
	Operation& operator=(const Operation&) = delete;
	~Operation();

	void Print() const;
	int CountVariables();
	bool IsContradiction() const;
	bool IsTautology() const;
	bool IsContingency() const;
};

Operation::Operation(BooleanExpression* left, const char operation, BooleanExpression* right = nullptr)
{
	this->left = left;
	this->operation = operation;
	this->right = right;

	variablesFound = 0;
	int valiableListLength = CountRepeatingVariables() + 1;
	variableList = new char[valiableListLength];
}

Operation::~Operation()
{
	delete left;
	delete[] variableList;

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

int Operation::CountRepeatingVariables() const
{
	int count = left->CountRepeatingVariables();

	if (right)
	{
		count += right->CountRepeatingVariables();
	}

	return count;
}

void Operation::Fill(char* list, int& index)
{
	left->Fill(list, index);

	if (right)
	{
		right->Fill(list, index);
	}
}

int Operation::CountVariables() 
{
	Fill(variableList, variablesFound);
	int count = 1;

	for (int i = 1; i < variablesFound - 1; i++)
	{
		bool isCurrentFound = false;

		for (int j = i + 1; j < variablesFound; j++)
		{
			if (variableList[i] == variableList[j])
			{
				isCurrentFound = true;
				break;
			}
		}

		if (!isCurrentFound)
		{
			count++;
		}
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
	/*if (!right)
	{
		return false;
	}

	bool bothF = EvalueateWithOperation(!left->Evaluate(), !right->Evaluate());
	bool leftF = EvalueateWithOperation(!left->Evaluate(), right->Evaluate());
	bool rightF = EvalueateWithOperation(left->Evaluate(), !right->Evaluate());
	bool bothT = EvalueateWithOperation(left->Evaluate(), right->Evaluate());

	return bothF && leftF && rightF && bothT;*/

	return true;
}

bool Operation::Evaluate() const
{
	bool result = left->Evaluate();
	
	if (right)
	{
		bool secondValue = right->Evaluate();

		if (operation == '^')
		{
			result = result && secondValue;
		}
		else if (operation == '|')
		{
			result = result || secondValue;
		}
		else if (operation == '+')
		{
			result = result ^ secondValue;
		}
		else if (operation == '>')
		{
			result = !result || secondValue;
		}
		else if (operation == '=')
		{
			result = result == secondValue;
		}
	}
	else
	{
		return !result;
	}

	return result;
}

//bool Operation::EvalueateWithOperation(bool l, bool r) const
//{
//	if (!strcmp(operation, "^"))
//	{
//		return l && r;
//	}
//	else if (!strcmp(operation, "|"))
//	{
//		return l || r;
//	}
//	else if (!strcmp(operation, "+"))
//	{
//		return l ^ r;
//	}
//	else if (!strcmp(operation, "->"))
//	{
//		return !l || r;
//	}
//	else if (!strcmp(operation, "<->"))
//	{
//		return l == r;
//	}
//
//	return false;
//}