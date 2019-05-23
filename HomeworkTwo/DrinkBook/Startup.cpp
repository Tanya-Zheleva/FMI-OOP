#include <iostream>
#include "FolkClub.h"
#include "RockClub.h"

using namespace std;

int main()
{
	User u("Ivan", 15, 35, 2, 3, "Rock");

	//Club* c = new RockClub("Force", 12, 10);
	//c->AddUser(u);
	//c->Print();

	//cout << c->GetVodkaPrice() << endl;

	//delete c;

	RockClub r("Force", 12, 10);
	r.AddUser(u);

	RockClub r2(r);
	r2.Print();

	while (true) { }
	return 0;
}