#ifndef FRAME_H
#define FRAME_H

/*!
 * \file Frame.h
 * \author Jules
 * \brief Déclaration de la classe Frame
 * \addtogroup View
 * @{
 */

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <tools/tools.h>

using namespace std;
using namespace sf;


/***
* Frame
* ===========================================================
* Contient la position et la taille d'une frame dans une 
* texture.
***/


class Frame
{

	private :

		Int2 position;
		Int2 size;


	public :
		
		Frame();
		Frame(Int2 pos, Int2 siz);
		~Frame();

		Int2 getPosition();
		Int2 getSize();

};


/** @}*/

#endif
