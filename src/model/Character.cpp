#include "model/Character.h"

Character::Character(Int2 pos, Int2 siz, int m, int max_h)
:ObjetPhysique(pos,siz,m)
{
	initial_size = siz;
    health = Int2(max_h,max_h);
    walkway = 1;
    gunway = Int2(1,0);
    state_p = WAIT;
    state_g = GROUND;
    state_b = NORMAL;

}


Character::Character()
:ObjetPhysique()
{
    initial_size = size;
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

    /* COURIR */
    if(state_b != DEAD)
        if(state_p == RUN)
            position.x += dt*walkway/mass*2 ;

    /* GRAVITÉ */
    if(state_g == AIR)
    {
        int dy = dt*0.15*mass;
        movement.y += dy;
    }
}


void Character::jump(int h) 
{
    if(state_g==GROUND && state_b!=DEAD)
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
    if(state_b==SHOOT and gunway.y>0)
        state_b = NORMAL;
    position.y = h-size.y;
    movement.y = 0;
}



void Character::bumpTop(int h) 
{
    if(state_g == AIR) 
    {
        movement.y = 0;
        position.y = h;
    }
}


void Character::bumpLeft(int x) 
{
    // Le mur est a gauche du perso (le parametre est la droite de ce mur)
    movement.x = 0;
    position.x = x;
}



void Character::bumpRight(int x) 
{
    // Le mur est a droite du perso (le parametre est la gauche de ce mur)
    movement.x = 0;
    position.x = x - size.x; //On prend en compte la taille du perso.
}



void Character::print(ostream& os) const  
{  
    os << "===Character===" << endl;
    os << "=== Position  : " << position << endl;  
    os << "=== Taille    : " << size << endl; 
    os << "=== Masse     : " << mass << endl;  
    os << "=== Mouvement : " << movement << endl;
    os << "=== Santé     : " << health << endl;
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


int Character::getWalkway()
{
    return walkway;
}


void Character::decreaseHealth(int s)
{
    if(state_b == DEAD)
        return;

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
    if(state_b == DEAD)
        return;

    health.x += s;
    if(health.x > health.y)
        health.x = health.y;
}


void Character::setInvicibility(int seconds)
{
    if(state_b == DEAD)
        return;

    state_b = STAR;
    star_cpt = seconds*90;
}


void Character::shoot(list<Ammo*>* air, Float2 angle)
{
    if(state_b == DEAD)
        return;
}


void Character::knife()
{
    if(state_b == NORMAL || state_b == PRESHOOT)
        state_b = KNIFE;
}


void Character::die()
{
    cout << "Je suis mort." << endl;
}


void Character::walk(int way)
{
    if(state_g==GROUND && state_p!=KNELT && state_b!=DEAD)
    {
        walkway = way;
        state_p = RUN;
    }
}


void Character::kneel(bool b)
{
    if(state_b == DEAD)
        return;

    if(state_g!=AIR && b && state_p!=KNELT)
    {
        size.y = 0.5*initial_size.y;
        position.y += initial_size.y-size.y;
    }
    else if(!b)
        size.y = initial_size.y;
    
    if(state_g != AIR)
        state_p = (b ? KNELT : WAIT);
}