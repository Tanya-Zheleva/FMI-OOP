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

	BooleanExpression* a = new Variable('a');
	BooleanExpression* b = new Variable('a');
	BooleanExpression* c = new Variable('c');

	BooleanExpression* and1 = new Operation(b, '>', c);
	BooleanExpression* left = new Operation(a, '^', and1);

	BooleanExpression* d = new Variable('a');
	BooleanExpression* op = new Operation(left, '>', d);

	op->Print();

	cout << endl;

	cout << op->CountVariables();

	cout << endl;

	//cout << op->Evaluate();

	cout << endl;

	BooleanExpression* p = new Variable('p');
	BooleanExpression* p2 = new Variable('p');
	BooleanExpression* notP = new Operation(p2, '!');
	BooleanExpression* op2 = new Operation(p, '^', notP);

	op2->Print();

	cout << endl;

	cout << op2->CountVariables();

	cout << endl;

	delete op2;
	delete op;
	return 0;
}