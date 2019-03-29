#include <iostream>
#include "Grade.h"

using namespace std;

int main()
{
	Grade g1;
	Grade g2(5.80, "Biology");
	g1 = g2;

	cout << g1.GetValue() << " " << g1.GetSubject() << endl;

	while (true) {}
	return 0;
}