#include "model/Player.h"


using namespace std;

Player::Player(Int2 pos, Int2 siz, int m, int max_h)
:Character(pos,siz,m,max_h)
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
    // os << "=== Position  : " << position << endl;  
    // os << "=== Taille    : " << size << endl;  
    // os << "=== Z-index   : " << z << endl;  
    // os << "=== Masse     : " << mass << endl;  
    // os << "=== Mouvement : " << movement << endl;
    // os << "=== Santé     : " << health << endl;
    string tmp;
    switch(state_p)
    {
        case WAIT  : tmp = "WAIT"; break;
        case RUN   : tmp = "RUN"; break;
        case KNELT : tmp = "KNELT"; break;
    }
    os << "=== State Pos  : " << tmp << endl;
    switch(state_g)
    {
        case GROUND : tmp = "GROUND"; break;
        case AIR    : tmp = "AIR"; break;
    }
    os << "=== State Grnd : " << tmp << endl;
    switch(state_b)
    {
        case NORMAL : tmp = "NORMAL"; break;
        case SHOOT  : tmp = "SHOOT"; break;
        case DEAD   : tmp = "DEAD"; break;
        case KNIFE  : tmp = "KNIFE"; break;
        case STAR   : tmp = "STAR"; break;
    }
    os << "=== State Bat : " << tmp << endl;
    os << "==================";
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
		if(state_p == KNELT && angle.x!=0)
			walkway = angle.x;
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
		if(state_p != KNELT)
		state_p = RUN;
		walkway = way;
	}
	else if(state_p != KNELT)
		state_p = WAIT;
}


void Player::kneel(bool b)
{
	Character::kneel(b);
}