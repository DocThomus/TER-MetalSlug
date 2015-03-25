#include "model/Platform.h"

Platform::Platform(Int2 pos, Int2 siz, int wl)
:ObjetPhysique(pos,siz), walkline(wl)
{
	if(walkline > siz.y)
		walkline = siz.y;
}



Platform::Platform()
:ObjetPhysique()
{}


Platform::~Platform()
{
}


void Platform::print(ostream& os) const 
{

}


int Platform::getWalkline()
{
	return walkline;
}