#include "model/Ammo.h"

Ammo::Ammo(Int2 pos, Int2 siz, int m, TypeAmmo type, Float2 movement, Character* c)
:ObjetPhysique(pos,siz,m), type(type), owner(c)
{
	state_a = FLY; 

	addMovement(movement);
	
	if(type==BULLET || type==HEAVY_BULLET || type==LIGHT_BULLET)
		size = Int2(50,12);
}




Ammo::Ammo()
:ObjetPhysique(), type(BULLET)
{
	state_a = FLY; 

	addMovement(Int2(0,0));
}


Ammo::~Ammo()
{}


void Ammo::print(ostream& os) const 
{
	os << "=======Ammo=======" << endl;
	os << "=== Position  : " << position << endl;
	os << "=== Mouvement : " << movement << endl;
	string tmp;
    switch(state_a)
    {
        case FLY  : tmp = "FLY"; break;
        case STOP   : tmp = "STOP"; break;
        case GHOST : tmp = "GHOST"; break;
    }
    os << "=== State     : " << tmp << endl;
	os << "==================";
}


void Ammo::animate(int dt)
{
	if(state_a == GHOST)
		return;

	if(state_a != STOP)
		if(type==BULLET || type==HEAVY_BULLET || type==LIGHT_BULLET)
		{
			position.x += movement.x*2*dt;
			position.y += movement.y*2*dt;
		}

}


void Ammo::die(Int2 pos)
{
	position = pos;
	state_a = STOP;
}


int Ammo::getDamage()
{
	int d;
	switch(type)
	{
		case BULLET       :
		case HEAVY_BULLET : d = 10; break;
		case LIGHT_BULLET : d = 5;  break;
		case ROCKET       : d = 75; break;
		case GRENADE      : d = 50; break;
		case LASER        : d = 5;  break;
	}

	return d;
}


Ammo::StateAmmo Ammo::getState()
{
	return state_a;
}


Character* Ammo::getOwner()
{
	return owner;
}