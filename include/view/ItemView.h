#ifndef ITEMVIEW_H
#define ITEMVIEW_H

/*!
 * \file ItemView.h
 * \author Jules
 * \brief Déclaration de la classe ItemView
 * \addtogroup View
 * @{
 */

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <model/Item.h>
#include <view/MyDrawable.h>
#include <view/PlayerView.h>

using namespace std;
using namespace sf;




/*!\class ItemView
 * \brief Un objet Item affichable.
 */
class ItemView : public Item, public MyDrawable
{

	private :

		static vector<Texture*> textures; /*!< \brief Variable de classe contenant les différentes textures des items. */
		static vector<Sound*> sounds; /*!< \brief Variable de classe contenant les sons des items. */


	public :
		
		/*!
	     * \brief Constructeur
	     *
	     * Constructeur complet de la classe ItemView
	     * \param pos : Position de l'item.
	     * \param type_i : Type de l'item.
	     * \param type_w : Type de l'arme donnée par l'item.
	     */
		ItemView(Int2 pos, TypeItem type_i, Weapon::TypeWeapon type_w=Weapon::SHOTGUN);

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe ItemView.
	     */
		ItemView();

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe ItemView
	     */
		~ItemView();

		/*!
	     * \brief Chargement des ressources
	     *
	     * Methode statique permettant de charger les ressources des items.
	     * ATTENTION : Cette méthode doit impérativement être appelée avant d'afficher des items !
	     */
		static void loadRessources();

		/*!
	     * \brief Affichage
	     *
	     * Affiche l'objet dans une fenêtre de rendu.
	     * \param window : Fenêtre d'affichage
	     */
		void display(RenderWindow* window);

		/*!
	     * \brief Déclenchement
	     *
	     * Applique l'effet de l'item sur le joueur qui le ramasse.
	     */
		void trigger(PlayerView* p);
		
};


/** @}*/

#endif
