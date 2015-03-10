#include "model/Platform.h"

Platform::Platform(Int2 pos, Int2 siz, int z, int wl)
:ObjetPhysique(pos,siz,z), walkline(wl)
{}



Platform::Platform()
:ObjetPhysique()
{}


Platform::~Platform()
{
}


void Platform::print(ostream& os) const 
{

}

