#include "model/Enemy.h"


Enemy::Enemy(Int2 pos, Int2 siz, int m, int max_h, bool AI, int pow)
:Character(pos,siz,m,max_h), haveAI(AI), power(pow)
{
	type = REBEL;
}


Enemy::Enemy()
:Character()
{
	type = REBEL;
}

Enemy::Enemy(Int2 pos, TypeEnemy t)
:Character()
{
	position = pos;
	type = t;

	switch(t)
	{
		case REBEL :
			size = Int2(130,80);
			mass = 5;
			health = 10;
			haveAI = false;
			power = 10;
			break;
	}
}


Enemy::~Enemy()
{
	// armes.clear();
}


void Enemy::print(ostream& os) const 
{

}



void Enemy::shoot(list<Ammo*>* air, Float2 angle)
{
	/* POSITION DES BALLES */
	Int2 pos = getPosition();
	Int2 siz = getSize();
	
	// X
	if(angle.x > 0)
		pos.x += siz.x+10;
	else if(angle.x == 0)
		pos.x += siz.x/2;
	else
		pos.x -= 10;
	
	// Y
	if(angle.y > 0)
		pos.y += siz.y;
	else if(angle.y == 0)
		pos.y += siz.y/3;
	if(angle.x==0 && angle.y<0)
		pos.y -= 50;


	/* CREATION BALLES */
	air->push_back(new Ammo(pos,siz,0,Ammo::BULLET,angle,this));

}

void Enemy::die()
{
	state_b = DEAD;
	cout << "Je suis mort." << endl;
}


void Enemy::animate(int dt)
{
	Character::animate(dt);
}