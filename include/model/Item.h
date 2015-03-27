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


class Item : public ObjetPhysique
{

	public :

		enum TypeItem {HEALTH,WEAPON,INVINCIBLE,CHICKEN,INVERT,AMMO};
	
	
	protected :

		TypeItem type;
		Weapon::TypeWeapon type_weapon;


	public :

		Item(Int2 pos, Int2 siz, int m, TypeItem type);
		Item();
		~Item();

		void print(ostream& os) const;

		void trigger(Player* p);
		void setTypeWeapon(Weapon::TypeWeapon type);


};

#endif