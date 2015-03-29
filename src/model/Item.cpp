#include "model/Item.h"

Item::Item(Int2 pos, Int2 siz, int m, TypeItem type)
:ObjetPhysique(pos,siz,m), type(type), type_weapon(Weapon::PISTOL)
{}



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
			p->addWeapon(new Weapon(p,type_weapon));
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