#include "ObjetPhysique.h"

ObjetPhysique::ObjetPhysique(Int2 pos, Int2 siz, int z, int m)
:position(pos),size(siz),z(z),mass(m)
{
	movement.x = 0; movement.y = 0;
}


ObjetPhysique::ObjetPhysique()
{
	position.x = 0; position.y = 0;
	size.x = 0;     size.y = 0;
	z = 0;
	movement.x = 0; movement.y = 0;
}


ObjetPhysique::~ObjetPhysique()
{}


void ObjetPhysique::animate(int dt)
{
	// A FAIRE
}


void ObjetPhysique::addMovement(Int2 v)
{
	movement.x += v.x;
	movement.y += v.y;
}


