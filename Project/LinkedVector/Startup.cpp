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
		v.push_back(18);

		Vector<int> v2;
		v2.push_back(1);
		v2.push_back(2);
		v2.push_back(3);
		v2.push_back(4);

		//v.swap(v2);
		v = v2;

		/*for (Vector<int>::Iterator it = v.begin(); it != v.end(); it++)
		{
			cout << *it << ' ';
		}

		cout << endl;

		for (Vector<int>::Iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << ' ';
		}*/

		//cout << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}

	while (true) {}
	return 0;
}