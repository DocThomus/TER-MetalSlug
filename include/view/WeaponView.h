#ifndef WEAPONVIEW_H
#define WEAPONVIEW_H

/*!
 * \file WeaponView.h
 * \author Jules
 * \brief Déclaration de la classe WeaponView
 * \addtogroup View
 * @{
 */

#include <iostream>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <model/Weapon.h>
#include <view/PlayerView.h>

using namespace std;
using namespace sf;

class PlayerView;



/*!\class WeaponView
 * \brief Un objet Weapon permettant de joueur des sons.
 *
 * Permet de jouer des sons lorsque on tire avec une arme.
 * TODO : déplacer la gestion des sons dans AmmoView et 
 * supprimer cette classe.... 
 */
class WeaponView : public Weapon
{

	protected :
		
		static vector<Sound*> sounds; /*!< \brief Variable de classe contenant les sons des tirs. */


	public :
		
		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe WeaponView
	     */
		WeaponView();

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur de la classe WeaponView.
	     * \param p : Joueur possèdant l'arme.
	     * \param : Type de l'arme.
	     */
		WeaponView(PlayerView* p, TypeWeapon type);

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe WeaponView
	     */
		~WeaponView();

		/*!
	     * \brief Chargement des sons
	     *
	     * Methode statique permettant de charger les sons des tirs.
	     * ATTENTION : Cette méthode doit impérativement être appelée avant de tirer avec l'arme !
	     */
		static vector<Sound*> loadSounds();
		
		/*!
	     * \brief Son du tir
	     *
	     * Lit le son du tir en fonction du type de l'arme.
	     */
		void shootSound();

};


/** @}*/

#endif
