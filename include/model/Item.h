#ifndef ITEM_H
#define ITEM_H

/*!
 * \file Item.h
 * \author Jules
 * \brief Déclaration de la classe Item
 * \addtogroup Model 
 * @{
 */

#include <iostream>
#include <sstream>

#include <model/ObjetPhysique.h>
#include <model/Player.h>
#include <model/Weapon.h>
#include <model/Ammo.h>

using namespace std;

class Player;
class Weapon;



/*!\class Item
 * \brief Modélise un item.
 *
 * Objet posé sur le sol qui contient un bonus, un malus ou
 * même une arme.
 */
class Item : public ObjetPhysique
{

	public :

		/*!
	     * \enum TypeItem
	     * \brief Types possibles de l'objet Item.
	     */
		enum TypeItem {HEALTH,WEAPON,INVINCIBLE,CHICKEN,INVERT,AMMO};
	
	
	protected :

		TypeItem type; /*!< \brief Type de l'item. */
		Weapon::TypeWeapon type_weapon; /*!< \brief Type de l'arme donnée par l'item. */


	public :

		
		Item(Int2 pos, Int2 siz, int m, TypeItem type);
		Item();
		~Item();

		void print(ostream& os) const;

		void trigger(Player* p);
		void setTypeWeapon(Weapon::TypeWeapon type);


};


/** @}*/

#endif