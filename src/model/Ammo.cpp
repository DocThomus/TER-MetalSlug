#include "model/Ammo.h"

Ammo::Ammo(Int2 pos, Int2 siz, int m, TypeAmmo type, Float2 movement)
:ObjetPhysique(pos,siz,m), type(type)
{
	addMovement(movement);
	
	if(type == BULLET)
		size = Int2(50,12);
}




Ammo::Ammo()
:ObjetPhysique(), type(BULLET)
{
	addMovement(Int2(0,0));
}


Ammo::~Ammo()
{}


void Ammo::print(ostream& os) const 
{
	os << "Position  : " << position << endl;
	os << "Mouvement : " << movement;
}


void Ammo::animate(int dt)
{
	if(type==BULLET)
	{
		position.x += movement.x*2*dt;
		position.y += movement.y*2*dt;
	}
}


int Ammo::getDamage()
{
	int d;
	switch(type)
	{
		case BULLET : 
			d = 10;
			break;
		case ROCKET :
			d = 75;
			break;
		case GRENADE :
			d = 50;
			break;
		case LASER :
			d = 5;
			break;
	}

	return d;
}