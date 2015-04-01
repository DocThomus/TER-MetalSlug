#include "model/Weapon.h"




Weapon::Weapon(Player* p, TypeWeapon type)
:owner(p), type(type)
{
	p->addWeapon(this);

	switch(type)
	{
		case PISTOL :
			ammos = Int2(9999999,9999999);
			break;

		case SHOTGUN :
			ammos = Int2(12,12);
			break;

		default :
			ammos = Int2(100,100);
	}
}


Weapon::Weapon()
{}


Weapon::~Weapon()
{

}


void Weapon::print(ostream& os) const 
{
	os << "     Angle : " << angle << endl;
	os << " Munitions : " << ammos << endl;
}




void Weapon::shoot(list<Ammo*>* air, Float2 angle)
{

	/* CADENCE DE TIR */
	double cadence;

	switch(type)
	{
		case PISTOL :
			cadence = 0;
			break;

		case SHOTGUN :
			cadence = 30;
			break;

		default :
			cadence = 0;
			break;
	}

	bool cadence_ok = true;

	static clock_t start = 0;
	
	if(start == 0)
		start = clock();
	else if((double)(clock()-start)/(double)(CLOCKS_PER_SEC/double(1000.0)) >= cadence)
		start = clock();
	else
		cadence_ok = false;


	if(ammos.x>0 && cadence_ok)
	{
		/* POSITION DES BALLES */
		Int2 pos = owner->getPosition();
		Int2 siz = owner->getSize();
		
		// X
		if(angle.x > 0)
			pos.x += siz.x+10;
		else if(angle.x == 0)
			pos.x += siz.x/2;
		else
			pos.x -= 10;
		
		// Y
		if(angle.y > 0)
			pos.y += siz.y;
		else if(angle.y == 0)
			pos.y += siz.y/3;
		if(angle.x==0 && angle.y<0)
			pos.y -= 50;

		if(owner->getStatePosition() == Character::KNELT)
		{
			pos.y += siz.y/4;
		}


		/* CREATION DES BALLES */
		switch(type)
		{
			case PISTOL :
				air->push_back(new Ammo(pos,siz,0,Ammo::BULLET,angle,owner));
				ammos.x--;
				break;

			case SMG :
				air->push_back(new Ammo(pos,siz,0,Ammo::BULLET,angle,owner));
				ammos.x--;
				break;

			case SHOTGUN : //  balles 
				float disp = 0.2;
				for(float i=-disp; i<=disp && ammos.x>0; i+=disp/2)
				{
					Float2 tmp = angle;
					if(angle.x!=0)
						tmp.y+=i;
					if(angle.y!=0)
						tmp.x+=i;
					if((angle.x<0 && angle.y<0) || (angle.x>0 && angle.y>0))
						tmp.x-=i*2;
					air->push_back(new Ammo(pos,siz,0,Ammo::HEAVY_BULLET,tmp,owner));
				}
				ammos.x--;
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