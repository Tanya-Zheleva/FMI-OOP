#include <iostream>
#include "FolkClub.h"
#include "RockClub.h"
#include "HouseClub.h"
#include "Clubs.h"

using namespace std;

int main()
{
	User u("Ivan", 19, 500, 2, 3, "Rock");
	User u2("Ivan2", 18, 300, 2, 3, "All");
	User u3("Ivan3", 18, 450, 2, 3, "All");

	Clubs clubs;
	clubs.AddFolkClub("33", 50, 35, "Galena");
	clubs.AddHouseClub("Shots", 50, 47, 3);
	clubs.AddRockClub("Force", 45, 56);

	clubs.AddToClub(u, "Force");
	clubs.AddToClub(u2, "Force");
	clubs.AddToClub(u3, "Force");

	clubs.RemoveFromClub("Ivan", "Force");

	clubs.Print();

	while (true) { }
	return 0;
}