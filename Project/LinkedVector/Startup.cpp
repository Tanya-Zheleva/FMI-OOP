#include <iostream>
#include <vector>
#include "Vector.h"

using namespace std;

int main()
{
	try
	{
		Vector<int> v;
		v.push_back(5);
		v.push_back(8);
		v.push_back(13);
		v.push_back(10);
		v.push_back(7);

		//v.resize(-7);
		v.print();

		for (Vector<int>::Iterator it = v.getIterator(); !it.endReached(); it.moveNext())
		{
			cout << it.getCurrent() << ' ';
		}

		cout << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}

	while (true) {}
	return 0;
}