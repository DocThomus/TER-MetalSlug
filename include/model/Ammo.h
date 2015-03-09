#ifndef AMMO_H
#define AMMO_H

#include <iostream>
#include <sstream>

#include <model/ObjetPhysique.h>

using namespace std;



class Ammo : public ObjetPhysique
{
	
	protected :

		Int2 movement;


	public :

		Ammo(Int2 pos, Int2 siz, int z, int m, Int2 movement);
		Ammo();
		~Ammo();

		string toString();

		void animate(int dt);

		//void tirer(vector<Projectile>* air);	


};

#endif