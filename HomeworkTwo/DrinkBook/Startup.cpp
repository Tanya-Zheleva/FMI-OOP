#include <iostream>
#include "Club.h"
#include "FolkClub.h"

using namespace std;

int main()
{
	Club* c = new FolkClub("Plazza", 12, 10, "Galena");
	Club* c2 = new FolkClub(c->Clone());

	delete c;
	delete c2;
	while (true) { }
	return 0;
}