#include "model/Weapon.h"

Weapon::Weapon(Int2 pos, Int2 siz, int z, int m, Player* p, TypeWeapon type, int max_mun)
:ObjetPhysique(pos,siz,z,m), owner(p), type(type)
{
	ammos = Int2(max_mun,max_mun);
	p->addWeapon(this);
}


Weapon::Weapon(Player* p, TypeWeapon type, int max_mun)
:owner(p), type(type)
{
	ammos = Int2(max_mun,max_mun);
	p->addWeapon(this);
}


Weapon::Weapon()
:ObjetPhysique()
{}


Weapon::~Weapon()
{
	// armes.clear();
}


void Weapon::print(ostream& os) const 
{
	os << "     Angle : " << angle << endl;
	os << " Munitions : " << ammos << endl;
}




void Weapon::shoot(vector<Ammo*>* air)
{
	if(ammos.x>0)
	{
		ammos.x--;

		Int2 tmp;

		switch(type)
		{
			case PISTOL :
				tmp = Int2(angle.x*10,angle.y*10);
				air->push_back(new Ammo(BULLET,tmp));
				break;

			case SMG :
				srand (time(NULL));
				tmp = Int2(angle.x*10,angle.y*10+rand()%10+1);
				air->push_back(new Ammo(BULLET,angle));
				break;

			case SHOTGUN :
				for(int i=-2; i<=2; ++i)
				{
					tmp = Int2(angle.x*10,angle.y*10+i);
					air->push_back(new Ammo(BULLET,angle));
				}
				break;
		}


	}
}

