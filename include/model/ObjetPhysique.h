#ifndef OBJETPHYSIQUE_H
#define OBJETPHYSIQUE_H

#include <iostream>
#include <tools.h>

using namespace std;

class ObjetPhysique
{
	protected :

		Int2 position;
		Int2 size;
		int z;

		int mass;
		Int2 movement;


	public :

		ObjetPhysique(Int2 pos,Int2 siz, int z, int m);
		ObjetPhysique();
		~ObjetPhysique();

		virtual void animate(int dt);

		void addMovement(Int2 v);



};

#endif