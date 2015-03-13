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



enum StatePosition {WAIT,RUN,SAUT,DASH,ROLL};
enum StateBattle {NORMAL,DEAD,KNIFE,STAR};

class Player : public Character
{
	
	protected :

		StatePosition state_p;
		StateBattle state_b;
		
		vector<Weapon*> armes;
		int current_weapon;

		int star_cpt;


	public :
		
		Player(Int2 pos, Int2 siz, int z, int m, int max_h);
		Player();
		~Player();

		void print(ostream& os) const;

		virtual void animate(int dt);

		void decreaseHealth(int s);
		void increaseHealth(int s);
		void addWeapon(Weapon* w);
		void setInvicibility(int seconds);

		void shoot(vector<Ammo*>* air);
		void die();
		virtual void walk(int way);

};

#endif