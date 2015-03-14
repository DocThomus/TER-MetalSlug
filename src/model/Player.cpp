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
	state_b = DEAD;
	cout << "Je suis mort." << endl;
}


void Player::animate(int dt)
{
	ObjetPhysique::animate(dt);

	/* COURIR */
	if(state_p == RUN)
		position.x += dt*walkway/mass*2;
	
}


void Player::walk(int way)
{
	if(way != 0)
	{
		state_p = RUN;
		walkway = way;
	}
	else
		state_p = WAIT;
}
