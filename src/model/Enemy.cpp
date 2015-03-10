#include "model/Enemy.h"


Enemy::Enemy(Int2 pos, Int2 siz, int z, int m, int max_h, bool AI, int pow)
:ObjetPhysique(pos,siz,z,m), power(pow), haveAI(AI)
{
	health = Int2(max_h,max_h);
}


Enemy::Enemy()
:ObjetPhysique()
{
	health = Int2(100,100);
}


Enemy::~Enemy()
{
	// armes.clear();
}


void Enemy::print(ostream& os) const 
{

}


void Enemy::decreaseHealth(int s)
{
	health.x -= s;
	if(health.x <= 0)
	{
		health.x = 0;
		die();
	}
}


void Enemy::increaseHealth(int s)
{
	health.x += s;
	if(health.x > health.y)
		health.x = health.y;
}



void Enemy::attack(vector<Ammo*>* air)
{

}


void Enemy::die()
{
	state = DEAD;
	cout << "Je suis mort." << endl;
}


void Enemy::animate(int dt)
{
	
}