#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <sstream>
#include <list>
#include <tools/tools.h>

#include <model/ObjetPhysique.h>
#include <model/Ammo.h>

using namespace std;

class Ammo;


enum StatePosition {WAIT,RUN,KNELT};
enum StateGround {GROUND,AIR};
enum StateBattle {NORMAL,SHOOT,DEAD,KNIFE,STAR};


class Character : public ObjetPhysique
{

	protected :

		StatePosition state_p;
		StateGround state_g;
		StateBattle state_b;

		Int2 health;

		int walkway;
		Int2 gunway;

		int star_cpt;


	public :

		Character(Int2 pos,Int2 siz, int m, int max_h);
		Character();
		~Character();

		virtual void animate(int dt);
		virtual void print(ostream& os) const;

		StatePosition getStatePosition();
		StateGround   getStateGround();
		StateBattle getStateBattle();

		void decreaseHealth(int s);
		void increaseHealth(int s);

		virtual void setInvicibility(int seconds);

		virtual void jump(int h);
		virtual void land(int h);
		virtual void bumpTop(int plafond);
		virtual void bumpLeft(int posMurDroite);
		virtual void bumpRight(int posMurGauche);
		virtual void shoot(list<Ammo*>* air, Float2 angle = Float2(1.,0.));
		virtual void die();
		virtual void walk(int way);
		virtual void kneel(bool);
		
};



#endif