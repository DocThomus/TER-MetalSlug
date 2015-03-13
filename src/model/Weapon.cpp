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




void Weapon::shoot(list<Ammo*>* air, Float2 angle)
{
	if(ammos.x>0)
	{

		/* POSITION DES BALLES */
		Int2 pos = owner->getPosition();
		Int2 siz = owner->getSize();
		// X
		if(angle.x > 0)
			pos.x += siz.x;
		else if(angle.x == 0)
			pos.x += siz.x/2;
		// Y
		if(angle.y > 0)
			pos.y += siz.y;
		else if(angle.y == 0)
			pos.y += siz.y/2;


		/* CREATION DES BALLES */
		switch(type)
		{
			case PISTOL :
				air->push_back(new Ammo(pos,size,z+1,0,BULLET,angle));
				ammos.x--;
				break;

			case SMG :
				air->push_back(new Ammo(pos,size,z+1,0,BULLET,angle));
				ammos.x--;
				break;

			case SHOTGUN :
				float deb = -0.2;
				float fin = 0.2;
				for(float i=deb; i<=fin && ammos.x>0; i+=0.1)
				{
					Float2 tmp = angle;
					if(angle.x!=0)
						tmp.y+=i;
					if(angle.y!=0)
						tmp.x+=i;
					if(angle.x<0 && angle.y<0)
						tmp.x-=i*2;
					if(angle.x>0 && angle.y>0)
						tmp.x-=i*2;
					air->push_back(new Ammo(pos,size,z+1,0,BULLET,tmp));
					ammos.x--;
				}
				break;
		}

		//cout << "Il reste " << ammos.x << " munitions" << endl;

	}
}



void Weapon::reload(int nb)
{
	ammos.x += nb;
	if(ammos.x>ammos.y)
		ammos.x = ammos.y;
}