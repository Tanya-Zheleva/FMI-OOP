#include <iostream>
#include "FolkClub.h"
#include "RockClub.h"
#include "HouseClub.h"
#include "Clubs.h"

using namespace std;

int main()
{
	User u("Ivan", 15, 35, 2, 3, "Rock");
	User u2("Ivan2", 15, 35, 2, 3, "All");
	User u3("Ivan3", 15, 35, 2, 3, "All");

	Clubs clubs;
	clubs.AddFolkClub("h33", 50, 35, "Galena");
	clubs.AddFolkClub("Plazza", 50, 35, "Galena");
	clubs.AddFolkClub("555", 50, 35, "Galena");

	cout << clubs;

	while (true) { }
	return 0;
}