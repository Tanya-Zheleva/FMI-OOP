#include <iostream>
#include "Student.h"
#include "Speciality.h"
#include "Grade.h"

using namespace std;

int main()
{
	Grade g1(5.40, "English");
	Grade g2(5.80, "Biology");
	Grade grades[] = { g1, g2 };

	Student st(45602, "Petar", grades, 2, Speciality::IS);

	cout << st.GetName() << " " << st.GetFacultyNumber() << " " << st.GetSpeciality() << endl;

	for (int i = 0; i < 2; i++)
	{
		cout << st.GetGrades()[i].GetSubject() << ": " << st.GetGrades()[i].GetValue() << endl;
	}

	while (true) {}
	return 0;
}