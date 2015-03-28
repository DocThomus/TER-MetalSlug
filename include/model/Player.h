#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <sstream>
#include <vector>
#include <list>

#include <model/Character.h>
#include <model/Weapon.h>
#include <model/Ammo.h>


using namespace std;


class Weapon;
class Ammo;



/***
* Player -> Character -> ObjetPhysique
* ===============================================================
* Un Player est un Character contrôlé par le joueur. Il peut
* posséder différents types d'armes.
***/



class Player : public Character
{
	
	protected :
		
		vector<Weapon*> armes;
		int current_weapon;


	public :
		
		Player(Int2 pos, Int2 siz, int m, int max_h);
		Player();
		~Player();

		void print(ostream& os) const;

		Int2 getPosition();
		Int2 getSize();

		virtual void animate(int dt);

		virtual void walk(int way);
		virtual void kneel(bool);
		virtual void die();
		virtual void reload(int nb);
		virtual void shoot(list<Ammo*>*, Float2 angle = Float2(1,0));

		void addWeapon(Weapon* w);
		void setWeapon(int w);

};

#endif