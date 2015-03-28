#ifndef LEVEL_H
#define LEVEL_H

/*!
 * \file Level.h
 * \author Jules
 * \brief Déclaration de la classe Level
 * \addtogroup Controller 
 * @{
 */

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <controller/Environment.h>

using namespace std;

class Environment;



/*! \class Level
 * \brief Stocke les données du niveau.
 *
 * Stocke les objets du niveau : 
 * - Environement
 * - Event(Dialog,Enemy,Checkpoint...)
 */
class Level
{

	friend class Game;

	private :

		Environment environment;

	public :

		Level();
		~Level();

		void display(RenderWindow* window);

		void addDecor(Int2 siz, Texture* tex, int z=0);
		void addPlatform(Int2 pos, Int2 siz, int wl=0, Texture* tex=NULL);
};

/** @}*/

#endif