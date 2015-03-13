#include "model/Character.h"

Character::Character(Int2 pos, Int2 siz, int z, int m, int max_h)
:ObjetPhysique(pos,siz,z,m)
{
	health = Int2(max_h,max_h);
    walkway = 1;
    state_p = WAIT;
    state_b = NORMAL;

}


Character::Character()
{
    health = Int2(100,100);
	walkway = 1;
    state_p = WAIT;
    state_b = NORMAL;

}


Character::~Character()
{}


void Character::animate(int dt)
{
    int dx = (dt*movement.x*mass)/1000;
	int dy = (dt*movement.y*mass)/1000;
    movement.x -= dx;
    movement.y -= dy;
    position.x += dx;
    position.y += dy;
}

void Character::jump(int h) 
{
    movement.y = -500;
}


void Character::print(ostream& os) const  
{  
    os << "===Character===" << endl;
    os << "=== Position  : " << position << endl;  
    os << "=== Taille    : " << size << endl;  
    os << "=== Z-index   : " << z << endl;  
    os << "=== Masse     : " << mass << endl;  
    os << "=== Mouvement : " << movement << endl;
    os << "==================";
} 




void Character::decreaseHealth(int s)
{
    health.x -= s;
    if(health.x <= 0)
    {
        health.x = 0;
        die();
    }
}


void Character::increaseHealth(int s)
{
    health.x += s;
    if(health.x > health.y)
        health.x = health.y;
}


void Character::setInvicibility(int seconds)
{
    state_b = STAR;
    star_cpt = seconds*90;
}


void Character::shoot(vector<Ammo*>* air)
{
    
}


void Character::die()
{
    cout << "Je suis mort." << endl;
}


void Character::walk(int way)
{
    walkway = way;
}
