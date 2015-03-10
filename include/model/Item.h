#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <sstream>

#include <model/ObjetPhysique.h>
#include <model/Player.h>
#include <model/Weapon.h>
#include <model/Ammo.h>

using namespace std;

class Player;
class Weapon;


enum TypeItem {HEALTH,WEAPON,INVINCIBLE,CHICKEN,INVERT,AMMO};


class Item : public ObjetPhysique
{
	
	protected :

		TypeItem type;
		TypeWeapon type_weapon;


	public :

		Item(Int2 pos, Int2 siz, int z, int m, TypeItem type);
		Item();
		~Item();

		void print(ostream& os) const;

		void trigger(Player* p);
		void setTypeWeapon(TypeWeapon type);


};

#endif