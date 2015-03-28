#ifndef PLATFORMVIEW_H
#define PLATFORMVIEW_H

/*!
 * \file PlateformView.h
 * \author Jules
 * \brief Déclaration de la classe PlateformView
 * \addtogroup View
 * @{
 */

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <model/Platform.h>
#include <view/MyDrawable.h>

using namespace std;
using namespace sf;



/***
* PlatformView -> Platform -> ObjetPhysique
*              -> MyDrawable
* ===========================================================
* Permet d'afficher un objet Platform. Si la plateforme a
* une hauteur nulle, on ne l'affiche pas (c'est une plateforme
* invisible).
***/



class PlatformView : public Platform, public MyDrawable
{

	private :


	public :
		
		PlatformView(Int2 pos, Int2 siz, int wl);
		PlatformView();
		~PlatformView();

		void display(RenderWindow* window);
		void updateIntRect();
		
};


/** @}*/

#endif
