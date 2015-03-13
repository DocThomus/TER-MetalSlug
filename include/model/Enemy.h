#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <sstream>
#include <vector>

#include <model/Character.h>

using namespace std;


class Enemy : public Character 
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

		void print(ostream& os) const;	

		void decreaseHealth(int s);
		void increaseHealth(int s);

		void animate (int dt);
		void attack(vector<Ammo*>* air);
		void die();

};

#endif