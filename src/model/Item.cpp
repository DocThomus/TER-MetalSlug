#include "model/Item.h"

Item::Item(Int2 pos, TypeItem type)
:ObjetPhysique(), type(type), type_weapon(Weapon::PISTOL)
{
	setPosition(pos);

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
}


void Item::setTypeWeapon(Weapon::TypeWeapon type)
{
	type_weapon = type;
}