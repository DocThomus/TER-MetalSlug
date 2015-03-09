#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <sstream>
#include <vector>

#include <model/ObjetPhysique.h>
#include <model/Weapon.h>
#include <model/Ammo.h>

using namespace std;


class Weapon;
class Ammo;



class Player : public ObjetPhysique
{
	
	protected :

		int max_health;
		int health;
		
		vector<Weapon*> armes;
		int current_weapon;


	public :

		enum State {SAUT,INVINCIBLE,DASH,ROLL,SHOOT,DEAD,STRIKE};
		State state;
		
		Player(Int2 pos, Int2 siz, int z, int m, int max_h);
		Player();
		~Player();

		string toString();	

		void decreaseHealth(int s);
		void increaseHealth(int s);
		void addWeapon(Weapon* w);

		void animate(int dt);
		void shoot(vector<Ammo*>* air);
		void die();

};

#endif