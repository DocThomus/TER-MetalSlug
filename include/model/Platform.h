#ifndef PLATFORM_H
#define PLATFORM_H

#include <iostream>
#include <sstream>

#include <model/ObjetPhysique.h>

using namespace std;



class Platform : public ObjetPhysique
{
	
	protected :

		int walkline;
		


	public :

		Platform(Int2 pos, Int2 siz, int walkline=0);
		Platform();
		~Platform();

		void print(ostream& os) const;

		int getWalkline();

};

#endif