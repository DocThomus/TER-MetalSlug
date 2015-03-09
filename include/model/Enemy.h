#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <sstream>
#include <vector>

#include <model/ObjetPhysique.h>
#include <model/Ammo.h>

using namespace std;

class Ammo;


class Enemy : public ObjetPhysique
{
	
	protected :

		Int2 health;
		bool haveAI;
		int power;


	public :

		enum State {DEAD,JUMP,STRIKE};
		State state;
		
		Enemy(Int2 pos, Int2 siz, int z, int m, int max_h, bool AI, int pow);
		Enemy();
		~Enemy();

		string toString();	

		void decreaseHealth(int s);
		void increaseHealth(int s);

		void animate (int dt);
		void attack(vector<Ammo*>* air);
		void die();

};

#endif