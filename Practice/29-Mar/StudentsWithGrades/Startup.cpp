#include <iostream>
#include "Student.h"
#include "Speciality.h"
#include "Grade.h"

using namespace std;

int main()
{
	Grade g1;
	Grade g2;

	cin >> g1;
	cin >> g2;

	Grade grades[] = { g1, g2 };
	Grade g3(3.20, "Spanish");
	Grade grades2[] = { g1, g2, g3 };
	
	Student st("Petar", 45645, 55555, 648, grades, 2, Speciality::I);
	cout << st << endl;


	while (true) {}
	return 0;
}