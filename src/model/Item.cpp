#include "model/Item.h"



Item::Item(Int2 pos, TypeItem type_i, Weapon::TypeWeapon type_w)
:ObjetPhysique(), type(type_i), type_weapon(type_w)
{
	setPosition(pos);
	state = WAIT;

	/* TRAITEMENT EN FONCTION DU TYPE */
}



Item::Item()
:ObjetPhysique()
{}


Item::~Item()
{
}


void Item::print(ostream& os) const 
{

}


void Item::trigger(Player* p)
{
	switch(type)
	{
		case HEALTH :
			p->increaseHealth(30);
			break;

		case WEAPON :
			p->addWeapon(type_weapon);
			break;

		case INVINCIBLE :
			p->setInvicibility(6);
			break;
			
	}

	state = TAKEN;
}


void Item::setTypeWeapon(Weapon::TypeWeapon type)
{
	type_weapon = type;
}


Item::StateItem Item::getState()
{
	return state;
}