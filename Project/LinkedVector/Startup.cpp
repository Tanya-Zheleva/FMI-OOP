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

		v.resize(-7);
		v.print();;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}

	while (true) {}
	return 0;
}