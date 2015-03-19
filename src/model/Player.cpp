#include "model/Player.h"


using namespace std;

Player::Player(Int2 pos, Int2 siz, int z, int m, int max_h)
:Character(pos,siz,z,m,max_h)
{
}


Player::Player()
:Character()
{
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



Int2 Player::getPosition()
{
	return position;
}


Int2 Player::getSize()
{
	return size;
}


void Player::addWeapon(Weapon* w)
{
	armes.push_back(w);
	current_weapon = armes.size()-1;
}



void Player::setWeapon(int w)
{
	current_weapon = (w >= int(armes.size()) ? armes.size()-1 : w);
}



void Player::shoot(list<Ammo*>* air, Float2 angle)
{
	if(armes.size()>0)
	{
		armes[current_weapon]->shoot(air,angle);
		state_b = SHOOT;
	}
}


void Player::die()
{
	state_b = DEAD;
	cout << "Je suis mort." << endl;
}

void Player::reload(int nb)
{
	armes[current_weapon]->reload(nb);
}

void Player::animate(int dt)
{
	Character::animate(dt);

	/* COURIR */
	if(state_p == RUN)
		position.x += dt*walkway/mass*2	;

}


void Player::walk(int way)
{
	if(way != 0)
	{
		state_p = RUN;
		walkway = way;
	}
	else if(state_g == GROUND)
		state_p = WAIT;
}