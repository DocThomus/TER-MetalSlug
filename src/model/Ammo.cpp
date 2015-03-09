#include "model/Ammo.h"

Ammo::Ammo(Int2 pos, Int2 siz, int z, int m, Int2 movement)
:ObjetPhysique(pos,siz,z,m), movement(movement)
{}



Ammo::Ammo()
:ObjetPhysique()
{}


Ammo::~Ammo()
{}


string Ammo::toString()
{
	stringstream ss;
	ss << "Position  : " << position.toString() << endl;
	ss << "Mouvement : " << movement.toString();
	return ss.str();
}


void Ammo::animate(int dt)
{
	position.x += movement.x;
	position.y += movement.y;
}