#ifndef OBJETPHYSIQUE_H
#define OBJETPHYSIQUE_H

#include <iostream>
#include <tools/tools.h>

using namespace std;

class ObjetPhysique
{
	friend ostream& operator << (ostream& os, const ObjetPhysique& obj);

	protected :

		Int2 position;
		Int2 size;
		int z;

		int mass;
		Int2 movement;


	public :

		ObjetPhysique(Int2 pos,Int2 siz, int z, int m=0);
		ObjetPhysique();
		~ObjetPhysique();

		virtual void animate(int dt);

		Int2 getPosition();
		Int2 getSize();

		void setPosition(Int2 pos);
		void setPositionY(int posY);
		void setSize(Int2 siz);
		void setZ(int z);
		void setMass(int m);

		void addMovement(Int2 v);

		virtual void print(ostream& os) const;
		
};



#endif