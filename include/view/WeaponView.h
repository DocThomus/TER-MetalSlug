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


/***
* WeaponView -> Weapon -> ObjetPhysique
*            -> MyDrawable
* ===========================================================
* Permet de jouer des sons lorsque on tire avec une arme.
* ===========================================================
* TODO : déplacer la gestion des sons dans AmmoView et 
* supprimer cette classe....
***/



class WeaponView : public Weapon
{

	protected :
		
		static vector<Sound*> sounds;


	public :
		
		WeaponView();
		WeaponView(PlayerView* p, TypeWeapon type);
		~WeaponView();

		static vector<Sound*> loadSounds();
		
		void shootSound();

};


/** @}*/

#endif
