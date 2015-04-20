#include "controller/EventItem.h"


EventItem::EventItem()
:EventGame(), item_pos(0), item_type(Item::WEAPON), weapon_type(Weapon::SHOTGUN)
{

}


EventItem::EventItem(int pos, Int2 pos_i, Item::TypeItem t_i, Weapon::TypeWeapon t_w)
:EventGame(pos), item_pos(pos_i), item_type(t_i), weapon_type(t_w)
{

}


EventItem::~EventItem()
{

}


void EventItem::setItemType(Item::TypeItem t)
{
	item_type = t;
}


void EventItem::setItemPosition(Int2 pos)
{
	item_pos = pos;
}


void EventItem::setWeaponType(Weapon::TypeWeapon t)
{
	weapon_type = t;
}


void EventItem::trigger(Game* g)
{
	ItemView* item = new ItemView(item_pos, item_type, weapon_type);
	g->items.push_back(item);
}
