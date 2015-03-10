#include "model/Ammo.h"

Ammo::Ammo(Int2 pos, Int2 siz, int z, int m, TypeAmmo type, Int2 movement)
:ObjetPhysique(pos,siz,z,m), type(type)
{
	addMovement(movement);
}


Ammo::Ammo(TypeAmmo type, Int2 move)
:ObjetPhysique(), type(type)
{
	movement = move;
}


Ammo::Ammo()
:ObjetPhysique(), type(BULLET)
{}


Ammo::~Ammo()
{}


void Ammo::print(ostream& os) const 
{
	os << "Position  : " << position << endl;
	os << "Mouvement : " << movement;
}


void Ammo::animate(int dt)
{
	position.x += movement.x;
	position.y += movement.y;
}