#include "Operation.h"
#include "Variable.h"

using namespace std;

int main()
{
	/*
		^ = AND
		| = OR
		+ = XOR
		! = Negation
		> = Implication
		= = Bi Implication
	*/

	BooleanExpression* leftA = new Variable('a');
	BooleanExpression* leftB = new Variable('b');
	BooleanExpression* leftAnd = new Operation(leftA, '^', leftB);
	BooleanExpression* leftC = new Variable('c');
	BooleanExpression* left = new Operation(leftAnd, '>', leftC);

	BooleanExpression* rightA = new Variable('a');
	BooleanExpression* rightB = new Variable('b');
	BooleanExpression* rightC = new Variable('c');
	BooleanExpression* rightImplication = new Operation(rightB, '>', rightC);
	BooleanExpression* right = new Operation(rightA, '>', rightImplication);

	BooleanExpression* op = new Operation(left, '=', right);

	op->Print();

	cout << endl;

	cout << op->CountVariables() << endl;

	cout << endl;

	BooleanExpression* p = new Variable('p');
	BooleanExpression* q = new Variable('q');
	BooleanExpression* leftExpr = new Operation(p, '^', q);
	BooleanExpression* rightExpr = new Variable('q');
	BooleanExpression* op2 = new Operation(leftExpr, '>', rightExpr);

	op2->Print();

	cout << endl;

	cout << op2->CountVariables() << endl;

	cout << op2->IsTautology();

	cout << endl;
	
	delete op2;
	delete op;
	return 0;
}