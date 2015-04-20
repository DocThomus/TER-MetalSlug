#include "model/Platform.h"

Platform::Platform(Int2 pos, Int2 siz, int wl)
:ObjetPhysique(pos,siz), walkline(wl), visible(true)
{
	if(walkline > siz.y)
		walkline = siz.y;
}



Platform::Platform()
:ObjetPhysique(), visible(true)
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


void Platform::setVisible(bool b)
{
	visible = b;
}