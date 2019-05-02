#include <iostream>
#include <vector>
#include "Vector.h"

using namespace std;

int main()
{
	Vector<int> t(5, 6);
	Vector<int> v(10, 4);
	t = v;

	t.print();
	v.print();

	return 0;
}