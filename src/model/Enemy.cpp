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

Enemy::Enemy(Int2 pos, TypeEnemy t, bool AI)
:Character()
{
	position = pos;
	type = t;
	haveAI = AI;
	walkway = -1;

	switch(t)
	{
		case REBEL :
			size = Int2(64,130);
			mass = 10;
			health = 10;
			power = 10;
			break;

		case BOWSER :
			size = Int2(250,350);
			mass = 15;
			health = 200;
			power = 30;
			break;
	}
}


Enemy::~Enemy()
{
	// armes.clear();
}


void Enemy::print(ostream& os) const 
{
	cout << walkway;
}



void Enemy::shoot(list<Ammo*>* air, Float2 angle)
{
	state_b = SHOOT;
	cpt_shoot = 0;

	/* POSITION DES BALLES */
	Int2 pos = getPosition();
	Int2 siz = getSize();

	if(type == REBEL)
	{
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

	else if(type == BOWSER)
	{
		state_p = WAIT;

		/* POSITION */
		pos.y += size.y*0.3;

		/* CREATION BALLES */
		air->push_back(new Ammo(pos,siz,0,Ammo::FLAME,angle,this));
	}

}


bool Enemy::canShoot()
{
	if(type == REBEL)
	{
		if(cpt_shoot >= 1000)
			return true;
	}
	else if(type==BOWSER)
	{
		if(cpt_shoot >= 1000)
			return true;
	}

	return false;
}


void Enemy::die()
{
	state_b = DEAD;
	cout << "Je suis mort." << endl;
}


void Enemy::animate(int dt)
{
	Character::animate(dt);

	cpt_shoot += dt;
}


void Enemy::walk(int way)
{
    if(state_b == DEAD)
        return;

	if(way != 0)
	{
		if(state_p != KNELT)
			state_p = RUN;
		walkway = way;
	}
	else if(state_p != KNELT)
		state_p = WAIT;
}


bool Enemy::getIA()
{
	return haveAI;
}


int Enemy::getPower()
{
	return power;
}


Enemy::TypeEnemy Enemy::getType()
{
	return type;
}


Platform* Enemy::getGround()
{
	return ground;
}


void Enemy::setGround(Platform* p)
{
	ground = p;
}