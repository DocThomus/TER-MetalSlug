#include "model/Weapon.h"

Weapon::Weapon(Int2 pos, Int2 siz, int z, int m, int max_mun, int mass_mun)
:ObjetPhysique(pos,siz,z,m), owner(NULL), max_munitions(max_mun), munitions(max_mun), mass_munitions(mass_mun)
{}


Weapon::Weapon(Player* p, int max_mun, int mass_mun)
:owner(p), max_munitions(max_mun), munitions(max_mun), mass_munitions(mass_mun)
{
	state = OWNED;
	p->addWeapon(this);
}


Weapon::Weapon()
:ObjetPhysique()
{}


Weapon::~Weapon()
{
	// armes.clear();
}


string Weapon::toString()
{
	stringstream ss;
	ss << "      Etat : " << (state==OWNED ? "tenue" : "à terre") << endl;
	ss << "     Angle : " << angle.x << "," << angle.y << endl;
	ss << " Munitions : " << munitions << "/" << max_munitions << endl;
	ss << "Masse Mun. : " << mass_munitions << endl; 
	return ss.str();
}




void Weapon::shoot(vector<Ammo*>* air)
{
	if(munitions>0)
	{
		munitions--;
		Ammo* a = new Ammo(position,size_munitions,z+1,0,angle);
		air->push_back(a);
	}
}