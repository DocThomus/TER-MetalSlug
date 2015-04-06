#include "model/Enemy.h"


Enemy::Enemy(Int2 pos, Int2 siz, int m, int max_h, bool AI, int pow)
:Character(pos,siz,m,max_h), haveAI(AI), power(pow)
{
	type = REBEL;
	orienteGauche = true; // TEST
	enDeplacement = true; // TEST
}


Enemy::Enemy()
:Character()
{
	type = REBEL;
	orienteGauche = true; // TEST
	enDeplacement = true; // TEST
}

Enemy::Enemy(Int2 pos, TypeEnemy t)
:Character()
{
	position = pos;
	type = t;

	orienteGauche = true; // TEST
	enDeplacement = true; // TEST

	switch(t)
	{
		case REBEL :
			size = Int2(64,130);
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

	if(true && enDeplacement) { // if(haveAI && enDeplacement)
		if(orienteGauche) {
			if(position.x < plateformeAParcourir.getPosition().x + 10) {
				setOrientation(false);
			} else {
				position.x -= dt*walkway/mass;
			}
		} else {
			if(position.x + size.x > plateformeAParcourir.getPosition().x + plateformeAParcourir.getSize().x - 10) {
				setOrientation(true);
			} else {
				position.x += dt*walkway/mass;
			}
		}
	}
}

void Enemy::setPlateformeAParcourir(Platform pf) {
	plateformeAParcourir = pf;
}

void Enemy::setOrientation(bool gauche) {
	orienteGauche = gauche;
}

void Enemy::setDeplacement(bool dpl) {
	enDeplacement = dpl;
}

bool Enemy::estIntelligent() {
	return true; // return haveAI;
}