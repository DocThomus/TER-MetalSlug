#ifndef AMMO_H
#define AMMO_H

#include <iostream>
#include <sstream>


#include <model/ObjetPhysique.h>

using namespace std;

class Weapon;
class Enemy;


enum TypeAmmo {BULLET,ROCKET,GRENADE,LASER};

class Ammo : public ObjetPhysique
{
	friend class Weapon;
	friend class Enemy;

	protected :

		TypeAmmo type;


	public :

		Ammo(Int2 pos, Int2 siz, int m, TypeAmmo type, Float2 move);
		//Ammo(TypeAmmo type, Int2 movement);
		Ammo();
		~Ammo();

		void print(ostream& os) const;

		void animate(int dt);

		int getDamage();

};

#endif