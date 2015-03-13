#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <sstream>
#include <vector>

#include <model/Character.h>
#include <model/Weapon.h>
#include <model/Ammo.h>


using namespace std;


class Weapon;
class Ammo;



class Player : public Character
{
	
	protected :
		
		vector<Weapon*> armes;
		int current_weapon;


	public :
		
		Player(Int2 pos, Int2 siz, int z, int m, int max_h);
		Player();
		~Player();

		void print(ostream& os) const;

		virtual void animate(int dt);

		virtual void shoot(vector<Ammo*>* air);
		virtual void die();

		void addWeapon(Weapon* w);

		virtual void walk(int way);

};

#endif