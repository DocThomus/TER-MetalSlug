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
		enum TypeItem {HEALTH, WEAPON, INVINCIBLE, CHICKEN, INVERT, AMMO};
	
	
	protected :

		TypeItem type; /*!< \brief Type de l'item. */
		Weapon::TypeWeapon type_weapon; /*!< \brief Type de l'arme donnée par l'item. */


	public :

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur complet de la classe Item
	     * \param pos : Position de l'item.
	     * \param type : TYpe de l'item.
	     */
		Item(Int2 pos, TypeItem type);

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe Item
	     */
		Item();

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe Item
	     */
		~Item();

		/*!
	     * \brief Debug
	     *
	     * Affiche des informations sur l'objet.
	     * \param os : Flux sur lequel afficher.
	     */
		void print(ostream& os) const;

		/*!
	     * \brief Déclenchement
	     *
	     * Applique l'effet de l'item sur le joueur qui le ramasse.
	     */
		void trigger(Player* p);

		/*!
	     * \brief Définit le type d'arme que donne l'item lorsqu'il est de type WEAPON.
	     */
		void setTypeWeapon(Weapon::TypeWeapon type);


};


/** @}*/

#endif