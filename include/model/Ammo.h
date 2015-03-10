#ifndef AMMO_H
#define AMMO_H

#include <iostream>
#include <sstream>

#include <model/ObjetPhysique.h>
#include <model/Weapon.h>

using namespace std;

class Weapon;


enum TypeAmmo {BULLET,ROCKET,GRENADE,LASER};

class Ammo : public ObjetPhysique
{
	friend class Weapon;

	protected :

		TypeAmmo type;


	public :

		Ammo(Int2 pos, Int2 siz, int z, int m, TypeAmmo type, Int2 move);
		Ammo(TypeAmmo type, Int2 movement);
		Ammo();
		~Ammo();

		void print(ostream& os) const;

		void animate(int dt);

		//void tirer(vector<Projectile>* air);	


};

#endif