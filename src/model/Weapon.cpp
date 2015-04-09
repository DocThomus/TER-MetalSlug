#include "model/Weapon.h"
#include <model/Player.h>



Weapon::Weapon(TypeWeapon t)
:type(t)
{
	switch(t)
	{
		case PISTOL :
			ammos = Int2(9999999,9999999);
			type_ammo = Ammo::BULLET;
			break;

		case SHOTGUN :
			ammos = Int2(12,12);
			type_ammo = Ammo::HEAVY_BULLET;
			break;

		case SMG :
			ammos = Int2(128,128);
			type_ammo = Ammo::LIGHT_BULLET;
			break;

		case FLAMETHROWER :
			ammos = Int2(200,200);
			type_ammo = Ammo::FLAME;
			break;

		default :
			type = PISTOL;
			ammos = Int2(9999999,9999999);
			type_ammo = Ammo::BULLET;
			break;
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

	switch(type) // définir la cadence en millisecondes
	{
		case PISTOL  : cadence = 150;  break;
		case SHOTGUN : cadence = 500; break;
		case SMG     : cadence = 60;  break;
		case FLAMETHROWER : cadence = 100; break;
		default      : cadence = 0;  break;
	}

	bool cadence_ok = true;

	static int elapsed = -1;	
	static sf::Clock clock;
	
	if(cadence > 0)
	{
		if(elapsed == -1)
		{
			elapsed = 0;
			clock.restart();
		}
		else
		{	
			elapsed = clock.getElapsedTime().asMilliseconds();
			if(elapsed >= cadence)
				clock.restart();
			else
				cadence_ok = false;
		}
	}


	if(ammos.x>0 && cadence_ok)
	{
		/* POSITION DES BALLES */
		Int2 pos = owner->getPosition();
		Int2 siz = owner->getSize();
		
		// X
		if(angle.x > 0)
			pos.x += siz.x+30;
		else if(angle.x == 0)
			pos.x += siz.x*0.5;
		else
			pos.x -= 30;
		
		// Y
		if(angle.y > 0)
			pos.y += siz.y;
		else if(angle.y == 0)
			pos.y += siz.y*0.2;
		if(angle.x==0 && angle.y<0)
			pos.y -= 50;

		if(owner->getStatePosition() == Character::KNELT)
		{
			pos.y -= siz.y*0.2;
		}

		// FIX
		if(type_ammo == Ammo::FLAME)
		{
			if(angle.x != 0)
				pos.y -= siz.y*0.7;
			else
				pos.x -= siz.x*0.7;
		}


		/* CREATION DES BALLES */
		float disp;

		switch(type)
		{
			case PISTOL :
				air->push_back(new Ammo(pos,siz,0,type_ammo,angle,owner));
				ammos.x--;
				break;

			case SMG :
				disp = (rand()%2000-1000)/10000.0;
				if(angle.y==0)
					angle.y += disp;
				else
					angle.x += disp;
				air->push_back(new Ammo(pos,siz,0,type_ammo,angle,owner));
				ammos.x--;
				break;

			case SHOTGUN : //  balles 
				disp = 0.2;
				for(float i=-disp; i<=disp && ammos.x>0; i+=disp/2)
				{
					Float2 tmp = angle;
					if(angle.x!=0)
						tmp.y+=i;
					if(angle.y!=0)
						tmp.x+=i;
					if((angle.x<0 && angle.y<0) || (angle.x>0 && angle.y>0))
						tmp.x-=i*2;
					air->push_back(new Ammo(pos,siz,0,type_ammo,tmp,owner));
				}
				ammos.x--;
				break;

			case FLAMETHROWER : 
				air->push_back(new Ammo(pos,siz,0,type_ammo,angle,owner));
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



void Weapon::setOwner(Player* p)
{
	owner = p;
}



Weapon::TypeWeapon Weapon::getType()
{
	return type;
}