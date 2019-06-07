#pragma once

class BooleanExpression
{
public:
	virtual void Print() const = 0;
	virtual int CountVariables() = 0;
	virtual bool IsContradiction() const = 0;
	virtual bool IsTautology() const = 0;
	virtual bool IsContingency() const = 0;
	virtual bool Evaluate() const = 0;
	virtual void Fill(char*, int&) = 0;
	virtual int CountRepeatingVariables() const = 0;

	virtual ~BooleanExpression() {}
};