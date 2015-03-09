#include "model/Player.h"

Player::Player(Int2 pos, Int2 siz, int z, int m, int max_h)
:ObjetPhysique(pos,siz,z,m), max_health(max_h), health(max_h)
{}


Player::Player()
:ObjetPhysique(), max_health(100), health(100)
{}


Player::~Player()
{
	// armes.clear();
}


string Player::toString()
{
	stringstream ss;
	ss << " Position : " << position.x << "," << position.y << endl;
	ss << "   Taille : " << size.x << "," << size.y << endl;
	ss << "  Index z : " << z << endl;
	ss << "    Santé : " << health << "/" << max_health << endl;
	ss << "    Masse : " << mass << endl;
	ss << "Mouvement : " << movement.x << "," << movement.y;
	return ss.str();
}


void Player::decreaseHealth(int s)
{
	health -= s;
	if(health <= 0)
	{
		health = 0;
		die();
	}
}


void Player::increaseHealth(int s)
{
	health += s;
	if(health > max_health)
		health = max_health;
}


void Player::addWeapon(Weapon* w)
{
	armes.push_back(w);
	current_weapon = armes.size()-1;
}


void Player::shoot(vector<Ammo*>* air)
{
	if(armes.size()>0)
		armes[current_weapon]->shoot(air);
}


void Player::die()
{
	state = DEAD;
	cout << "Je suis mort." << endl;
}


void Player::animate(int dt)
{
	
}