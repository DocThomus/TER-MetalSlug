#ifndef AMMOVIEW_H
#define AMMOVIEW_H

/*!
 * \file AmmoView.h
 * \author Jules
 * \brief Déclaration de la classe AmmoView
 * \addtogroup View
 * @{
 */

#include <iostream>
#include <vector>
#include <math.h>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <model/Ammo.h>
#include <view/MyDrawable.h>

using namespace std;
using namespace sf;


/***
* AmmoView -> Ammo -> ObjetPhysique
*          -> MyDrawable
* ===========================================================
* Permet d'afficher un objet Ammo.
***/


class AmmoView : public Ammo, public MyDrawable
{

	protected :

		static vector<Texture*> textures;
		

	public :
		
		AmmoView();
		AmmoView(Ammo);
		~AmmoView();

		static void loadTextures();

		virtual void display(RenderWindow* window);
		virtual void animate(int dt);
		virtual void die(Int2 pos);

		void initPosition();

};


/** @}*/

#endif
