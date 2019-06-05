#include "Operation.h"
#include "Variable.h"

using namespace std;

int main()
{
	BooleanExpression* a = new Variable('a');
	BooleanExpression* b = new Variable('a');
	BooleanExpression* c = new Variable('c');

	BooleanExpression* and1 = new Operation(b, "^", c);
	BooleanExpression* left = new Operation(a, "|", and1);

	BooleanExpression* d = new Variable('a');
	BooleanExpression* op = new Operation(left, "<->", d);

	op->Print();

	cout << endl;

	cout << op->CountVariables();

	cout << endl;

	cout << op->TestT();

	cout << endl;

	delete op;
	return 0;
}