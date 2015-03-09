#include <iostream>
#include <vector>

#include <Player.h>

using namespace std;


int main()
{
	Int2 pos(5,5);
	Int2 siz(6,6);

	Player perso(pos,siz,666,10,1000);

	Weapon arme(&perso,64,0);

	// cout << "===== Perso : =====" << endl;
	// cout << perso.toString() << endl;
	// cout << "===== Arme : =====" << endl;
	// cout << arme.toString() << endl;

	vector<Ammo*> balles;

	perso.shoot(&balles);
	perso.shoot(&balles);
	perso.shoot(&balles);

	balles[0]->animate(200);
	balles[1]->animate(100);

	for(int i=0; i<balles.size(); ++i)
		cout << "===== Ammo " << i+1 << " =====" << endl << balles[i]->toString() << endl;

	return 0;
}