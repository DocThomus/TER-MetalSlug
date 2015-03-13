#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <tools/tools.h>

#include <model/ObjetPhysique.h>

using namespace std;

class Character : public ObjetPhysique
{

	protected :

		Int2 health;

		int walkway;

	public :

		Character(Int2 pos,Int2 siz, int z, int m, int max_h);
		Character();
		~Character();

		virtual void animate(int dt);

		virtual void jump(int h);

		virtual void print(ostream& os) const;
		
};



#endif