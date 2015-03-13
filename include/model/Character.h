#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <sstream>
#include <vector>
#include <tools/tools.h>

#include <model/ObjetPhysique.h>
#include <model/Ammo.h>

using namespace std;

class Ammo;


enum StatePosition {WAIT,RUN,JUMP,FALL};
enum StateBattle {NORMAL,DEAD,KNIFE,STAR};


class Character : public ObjetPhysique
{

	protected :

		StatePosition state_p;
		StateBattle state_b;

		Int2 health;
		int walkway;

		int star_cpt;


	public :

		Character(Int2 pos,Int2 siz, int z, int m, int max_h);
		Character();
		~Character();

		virtual void animate(int dt);
		virtual void jump(int h);
		virtual void print(ostream& os) const;

		void decreaseHealth(int s);
		void increaseHealth(int s);

		virtual void setInvicibility(int seconds);

		virtual void shoot(vector<Ammo*>* air);
		virtual void die();
		virtual void walk(int way);
		
};



#endif