#include <iostream>
#include <vector>
#include "Vector.h"

using namespace std;

int main()
{
	Vector<char> v(5, 'a');
	Vector<char> v2(6, 'k');
	v = v2;

	v.print();

	cout << v.size() << endl;

	while (true) {}
	return 0;
}