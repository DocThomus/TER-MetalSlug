#ifndef EVENTITEM_H
#define EVENTITEM_H

/*!
 * \file EventItem.h
 * \author Jules
 * \brief Déclaration de la classe EventItem
 * \addtogroup Controller 
 * @{
 */

#include <iostream>
#include <sstream>

#include <controller/EventGame.h>

#include <controller/Game.h>
#include <model/Item.h>


using namespace std;



/*!\class EventItem
 * \brief Un EventGame déclenchant l'apparition d'un item.
 */
class EventItem : public EventGame
{

	protected :

		Int2 item_pos; /*!< \brief Position de l'item à générer. */
		Item::TypeItem item_type; /*!< \brief Type de l'item à générer. */
		Weapon::TypeWeapon weapon_type; /*!< \brief Type de l'arme que l'item à générer. */

	public :


		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe EventItem
	     */
		EventItem();

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur complet de la classe EventItem
	     * \param pos : Position de l'événement.
	     * \param pos_e : Position de l'item à générer.
	     * \param t_i : Type de l'item à générer.
	     * \param t_w : Type de l'arme que l'item doit générer.
	     */
		EventItem(int pos, Int2 pos_e, Item::TypeItem t_i, Weapon::TypeWeapon t_w=Weapon::SHOTGUN);

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe EventItem
	     */
		~EventItem();

		/*!
		 * \brief Définit le type de l'item à génèrer lors de l'événement.
		 */
		void setItemType(Item::TypeItem t);

		/*!
		 * \brief Définit le type de l'arme que l'item doit génèrer lors de l'événement.
		 */
		void setWeaponType(Weapon::TypeWeapon t);

		/*!
		 * \brief Définit la position de l'item à génèrer lors de l'événement.
		 */
		void setItemPosition(Int2 pos);

		/*!
		 * \brief Déclenche l'événement dans une partie.
		 * \param g : Jeu auquel appliquer l'événement.
		 */
		virtual void trigger(Game* g);


};



/** @}*/

#endif