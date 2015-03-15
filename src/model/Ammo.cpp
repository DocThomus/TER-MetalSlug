#include "model/Ammo.h"

Ammo::Ammo(Int2 pos, Int2 siz, int z, int m, TypeAmmo type, Float2 movement)
:ObjetPhysique(pos,siz,z,m), type(type)
{
	addMovement(movement);
	
	if(type == BULLET)
		size = Int2(40,8);
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
		position.x += movement.x*30;
		position.y += movement.y*30;
	}
}

