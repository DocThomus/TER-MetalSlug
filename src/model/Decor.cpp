#include "model/Decor.h"

Decor::Decor(Int2 pos, Int2 siz, int z)
:ObjetPhysique(pos,siz),z(z)
{}



Decor::Decor()
:ObjetPhysique()
{}


Decor::~Decor()
{
}


void Decor::print(ostream& os) const 
{

}

