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
		
		Enemy(Int2 pos, Int2 siz, int m, int max_h, bool AI, int pow);
		Enemy();
		~Enemy();

		void print(ostream& os) const;	

		void animate (int dt);
		void attack(vector<Ammo*>* air);
		void die();

};

#endif