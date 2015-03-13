#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <vector>

#include <model/ObjetPhysique.h>
#include <model/Ammo.h>

using namespace std;


class Player;
class Ammo;

enum TypeWeapon {PISTOL,SMG,SHOTGUN,ROCKET_LAUNCHER,GRENADE_LAUNCHER,CANARDATOR};
enum StateWeapon {GROUND,OWNED};

class Weapon : public ObjetPhysique
{
	
	protected :

		Int2 angle;

		Player* owner;

		Int2 ammos;
		
		TypeWeapon type;
		StateWeapon state;


	public :

		
		
		
		Weapon(Int2 pos, Int2 siz, int z, int m, Player* p, TypeWeapon type, int max_mun);
		Weapon(Player* p, TypeWeapon type, int max_mun);
		Weapon();
		~Weapon();

		void print(ostream& os) const;

		void shoot(vector<Ammo*>* air);	


};

#endif