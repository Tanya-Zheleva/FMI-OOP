#include <iostream>
#include "Student.h"
#include "Speciality.h"
#include "Grade.h"

using namespace std;

int main()
{
	Grade g1;
	cin >> g1;

	Grade g2;
	cin >> g2;

	Grade grades[] = { g1, g2 };
	Grade g3(3.20, "Spanish");
	Grade grades2[] = { g1, g2, g3 };

	Student st(45602, "Petar", grades, 2, Speciality::IS);
	Student st2(56302, "Ivo", grades2, 3, Speciality::SI);
	st = st2;

	cout << st << endl;
	/*cout << st.GetName() << " " << st.GetFacultyNumber() << " " << st.GetSpeciality() << endl;

	for (int i = 0; i < st.GetGradesCount(); i++)
	{
		cout << st.GetGrades()[i].GetSubject() << ": " << st.GetGrades()[i].GetValue() << endl;
	}*/

	while (true) {}
	return 0;
}