#include "model/Player.h"

Player::Player(Int2 pos, Int2 siz, int z, int m, int max_h)
:ObjetPhysique(pos,siz,z,m)
{
	health = Int2(max_h,max_h);
	state_p = WAIT;
	state_b = NORMAL;
}


Player::Player()
:ObjetPhysique()
{
	health = Int2(100,100);
	state_p = WAIT;
	state_b = NORMAL;
}


Player::~Player()
{
	// armes.clear();
}



void Player::print(ostream& os) const  
{  
    os << "======Player======" << endl;
    os << "=== Position  : " << position << endl;  
    os << "=== Taille    : " << size << endl;  
    os << "=== Z-index   : " << z << endl;  
    os << "=== Masse     : " << mass << endl;  
    os << "=== Mouvement : " << movement << endl;
    os << "=== Santé     : " << health << endl;
    os << "==================";
} 


void Player::decreaseHealth(int s)
{
	health.x -= s;
	if(health.x <= 0)
	{
		health.x = 0;
		die();
	}
}


void Player::increaseHealth(int s)
{
	health.x += s;
	if(health.x > health.y)
		health.x = health.y;
}


void Player::addWeapon(Weapon* w)
{
	armes.push_back(w);
	current_weapon = armes.size()-1;
}


void Player::setInvicibility(int seconds)
{
	state_b = STAR;
	star_cpt = seconds*90;
}


void Player::shoot(vector<Ammo*>* air)
{
	if(armes.size()>0)
		armes[current_weapon]->shoot(air);
}


void Player::die()
{
	state_b = DEAD;
	cout << "Je suis mort." << endl;
}


void Player::animate(int dt)
{
	
}