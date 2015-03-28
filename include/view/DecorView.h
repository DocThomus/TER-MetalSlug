#ifndef DECORVIEW_H
#define DECORVIEW_H

/*!
 * \file DecorView.h
 * \author Jules
 * \brief Déclaration de la classe DecorView
 * \addtogroup View
 * @{
 */

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <model/Decor.h>
#include <view/MyDrawable.h>

using namespace std;
using namespace sf;



/***
* DecorView -> Decor -> ObjetPhysique
*           -> MyDrawable
* ===========================================================
* Permet d'afficher un objet Decor.
* La texture est décalée en fonction du mouvement de la vue.
* L'indice z de Ammo est aussi utilisé pour créer un effet
* parallaxe.
***/



class DecorView : public Decor, public MyDrawable
{

	private :

		int tex_x;


	public :
		
		DecorView(Int2 pos, Int2 siz, int z);
		DecorView();
		~DecorView();

		void display(RenderWindow* window);
		void updateIntRect();

		void animate(int x);

};


/** @}*/

#endif
