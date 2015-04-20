#include "model/Player.h"


using namespace std;

Player::Player(Int2 pos, Int2 siz, int m, int max_h)
:Character(pos,siz,m,max_h)
{
    addWeapon(Weapon::PISTOL);
}


Player::Player()
:Character()
{
    position = Int2(100,530);
    size = Int2(100,120);
    initial_size = size;
    mass = 5;
    health = Int2(50,50);

    addWeapon(Weapon::PISTOL);
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
    os << "=== Masse     : " << mass << endl;  
    os << "=== Mouvement : " << movement << endl;
    os << "=== Santé     : " << health << endl;
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





void Player::addWeapon(Weapon::TypeWeapon t)
{
    Weapon w(t);
    w.setOwner(this);
	armes.push_back(w);
	current_weapon = armes.size()-1;
}



void Player::setWeapon(int w)
{
    if(state_b == DEAD)
        return;
    
	current_weapon = (w >= int(armes.size()) ? armes.size()-1 : w);
}


Weapon::TypeWeapon Player::getTypeWeapon()
{
    return armes[current_weapon].getType();
}



void Player::shoot(list<Ammo*>* air, Float2 angle)
{
	if(armes.size()>0 && state_b!=KNIFE && state_b!=DEAD) // si on a une arme
	{
        if(angle.y<=0 || state_g==AIR)
        {
    		armes[current_weapon].shoot(air,angle);
    		state_b = SHOOT;
    		if(state_p == KNELT && angle.x!=0)
    			walkway = angle.x;
        }
	}
}


void Player::knife()
{
    Character::knife();
}


void Player::die()
{
    if(state_b != DEAD)
	   state_b = DEAD;
}


void Player::reload(int nb)
{
    if(state_b != DEAD)
	   armes[current_weapon].reload(nb);
}


void Player::animate(int dt)
{
	Character::animate(dt);
}


void Player::walk(int way)
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


void Player::kneel(bool b)
{
	Character::kneel(b);
}

void Player::throwGrenade(list<Ammo*>* air) {
    if(state_b != DEAD) // TODO Prendre en compte les munitions
    {
        Int2 pos = getPosition();
        Int2 siz = getSize();

        // X
        if(walkway>0)   // A droite
            pos.x += siz.x+30;
        else            // A gauche
            pos.x -= 30;

        // Y
        pos.y -=50; // A mi-hauteur
        if(getStatePosition() == Character::KNELT)
            pos.y -= siz.y*0.2;

        // CREATION DE LA GRENADE
        if(walkway>0)
            air->push_back(new Ammo(pos,siz,4,Ammo::GRENADE,Int2(1,-1),this));
        else
            air->push_back(new Ammo(pos,siz,4,Ammo::GRENADE,Int2(-1,-1),this));
    }
}
