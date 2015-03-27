#include "model/Character.h"

Character::Character(Int2 pos, Int2 siz, int m, int max_h)
:ObjetPhysique(pos,siz,m)
{
	health = Int2(max_h,max_h);
    walkway = 1;
    gunway = Int2(1,0);
    state_p = WAIT;
    state_g = GROUND;
    state_b = NORMAL;

}


Character::Character()
{
    health = Int2(100,100);
    walkway = 1;
	gunway = Int2(1,0);
    state_p = WAIT;
    state_g = GROUND;
    state_b = NORMAL;

}


Character::~Character()
{}


void Character::animate(int dt)
{
    ObjetPhysique::animate(dt);

    /* GRAVITÉ */
    if(state_g == AIR)
    {
        int dy = dt*0.15*mass;
        movement.y += dy;
    }
}


void Character::jump(int h) 
{
    if(state_g==GROUND)
    {
        if(state_p==KNELT)
            kneel(false);
        state_g = AIR;
        movement.y = -h;
    }
}



void Character::land(int h)
{
    state_g = GROUND;
    position.y = h-size.y;
    movement.y = 0;
}



void Character::bumpTop(int plafond) {
    if(state_g == AIR) {
        movement.y = 0;
        position.y = plafond;
    }
}


void Character::bumpLeft(int posMurDroite) {
    // Le mur est a gauche du perso (le parametre est la droite de ce mur)
    movement.x = 0;
    position.x = posMurDroite;
}



void Character::bumpRight(int posMurGauche) {
    // Le mur est a droite du perso (le parametre est la gauche de ce mur)
    movement.x = 0;
    position.x = posMurGauche - size.x; //On prend en compte la taille du perso.
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


Character::StatePosition Character::getStatePosition()
{
    return state_p;
}


Character::StateGround Character::getStateGround()
{
    return state_g;
}


Character::StateBattle Character::getStateBattle()
{
    return state_b;
}


void Character::decreaseHealth(int s)
{
    if(health.x > 0)
    {
        health.x -= s;
        if(health.x <= 0)
        {
            health.x = 0;
            die();
        }
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


void Character::shoot(list<Ammo*>* air, Float2 angle)
{
    
}


void Character::die()
{
    cout << "Je suis mort." << endl;
}


void Character::walk(int way)
{
    if(state_g==GROUND && state_p!=KNELT)
        walkway = way;
}


void Character::kneel(bool b)
{
    if(state_g != AIR)
        state_p = (b ? KNELT : WAIT);
}