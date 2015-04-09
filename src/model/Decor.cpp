#include "model/Decor.h"

Decor::Decor(Int2 pos, Int2 siz, int z)
:ObjetPhysique(pos,siz),z(z)
{
	if(z==0)
		this->z = -1;
}



Decor::Decor()
:ObjetPhysique()
{
	z = -1;
}


Decor::~Decor()
{
}


void Decor::print(ostream& os) const 
{

}


void Decor::animate(int x)
{
	position.x = x;
}