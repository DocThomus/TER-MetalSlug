#ifndef AMMO_H
#define AMMO_H

#include <iostream>
#include <sstream>


#include <model/ObjetPhysique.h>

using namespace std;

class Weapon;
class Enemy;


class Ammo : public ObjetPhysique
{
	friend class Weapon;
	friend class Enemy;

	public :
	
		enum TypeAmmo {BULLET,ROCKET,GRENADE,LASER};
		enum StateAmmo{FLY,STOP,GHOST};


	protected :

		StateAmmo state_a;
		TypeAmmo type;


	public :

		Ammo(Int2 pos, Int2 siz, int m, TypeAmmo type, Float2 move);
		//Ammo(TypeAmmo type, Int2 movement);
		Ammo();
		~Ammo();

		void print(ostream& os) const;

		virtual void animate(int dt);
		virtual void die(Int2 pos);

		int getDamage();
		StateAmmo getState();

};

#endif