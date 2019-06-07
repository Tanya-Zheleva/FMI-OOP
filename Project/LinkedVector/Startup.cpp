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


		cout << v2[2] << endl;
		v2[2] = 17;
		cout << v2[2] << endl;

		for (Vector<int>::Iterator it = v.begin(); it != v.end(); it++)
		{
			
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