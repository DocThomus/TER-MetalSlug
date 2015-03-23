#include "model/ObjetPhysique.h"

ObjetPhysique::ObjetPhysique(Int2 pos, Int2 siz, int m)
:position(pos),size(siz),mass(m)
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
    int dx = (dt*movement.x*mass)/1000;
	int dy = (dt*movement.y*mass)/1000;
    //movement.x -= dx;
    //movement.y -= dy;
    position.x += dx;
    position.y += dy;
}


void ObjetPhysique::setPosition(Int2 pos)
{
    position.x = pos.x;
    position.y = pos.y;
}


void ObjetPhysique::setSize(Int2 siz)
{
    size.x = siz.x;
    size.y = siz.y;
}


void ObjetPhysique::setZ(int z)
{
    z = z;
}


void ObjetPhysique::setMass(int m)
{
    mass = m;
}


void ObjetPhysique::addMovement(Float2 v)
{
	movement.x += v.x;
	movement.y += v.y;
}


void ObjetPhysique::print(ostream& os) const  
{  
    os << "===ObjetPhysique===" << endl;
    os << "=== Position  : " << position << endl;  
    os << "=== Taille    : " << size << endl;  
    os << "=== Z-index   : " << z << endl;  
    os << "=== Masse     : " << mass << endl;  
    os << "=== Mouvement : " << movement << endl;
    os << "==================";
} 


ostream& operator << (ostream& os, const ObjetPhysique& obj)  
{  
    obj.print(os);  
    return os;  
} 