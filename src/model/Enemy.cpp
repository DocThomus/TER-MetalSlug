#include "model/Enemy.h"


Enemy::Enemy(Int2 pos, Int2 siz, int m, int max_h, bool AI, int pow)
:Character(pos,siz,m,max_h), haveAI(AI), power(pow)
{
}


Enemy::Enemy()
:Character()
{
}


Enemy::~Enemy()
{
	// armes.clear();
}


void Enemy::print(ostream& os) const 
{

}



void Enemy::attack(vector<Ammo*>* air)
{

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