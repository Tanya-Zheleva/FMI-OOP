#pragma once

class BooleanExpression
{
protected:
	bool whenOneVar1;
	bool whenOneVar2;
	bool firstCase;
	bool secondCase;
	bool thridCase;
	bool fourthCase;
public:
	virtual void Print() const = 0;
	virtual int CountVariables() const = 0;
	virtual bool IsContradiction() const = 0;
	virtual bool IsTautology() const = 0;
	virtual bool IsContingency() const = 0;
	virtual bool Evaluate()/* const*/ = 0;

	virtual bool TestT() = 0;

	virtual ~BooleanExpression() {}
};