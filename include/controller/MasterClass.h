#ifndef MASTERCLASS_H
#define MASTERCLASS_H

/*!
 * \file MasterClass.h
 * \author Jules
 * \brief Déclaration de la classe MasterClass
 * \addtogroup Controller 
 * @{
 */

#include <iostream>
#include <list>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <controller/Game.h>
#include <controller/Config.h>

using namespace std;
using namespace sf;

class Game;
class Config;


/*! \class MasterClass
 * \brief Initialisation du jeu
 *
 * Déclare la fenêtre de rendu, initialise et lance le jeu.
 */
class MasterClass
{
	
	private :

		Game game;
		Config config;

		RenderWindow* window;


	public :

		MasterClass();
		~MasterClass();

		void initGame();
		void playGame();


};

/** @}*/

#endif