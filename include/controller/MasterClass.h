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
#include <controller/Menu.h>

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
		
		/*!
	     * \enum ScreenPositions
	     * \brief Les cinq positions possibles
	     */
		enum MasterClassState
		{
			MAINMENU, NEWGAME, GAME, SETTINGS, HIGHSCORES, EXIT
		};
		
		MasterClassState state; /*!< \brief Etat du programme. */
		MasterClassState previousState; /*!< \brief Etat du programme. */
		
		Game* game; /*!< \brief Objet de gestion du jeu. */
		Config config; /*!< \brief Stockage de la configuration. */
 
		RenderWindow* window; /*!< \brief Fenêtre de rendu. */


	public :

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe MasterClass
	     */
		MasterClass();

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe MasterClass
	     */
		~MasterClass();

		/*!
	     * \brief Initialisation
	     *
	     * Initialise le jeu et la configuration.
	     */
		void initGame();

		/*!
	     * \brief Lance le programme
	     *
	     * Méthode principale qui selon l'état de MasterClass lance le menu principal, le jeu, ...
	     */
		void playApp();
		
		/*!
	     * \brief Lance le menu principal
	     *
	     * Lance le menu principal qui va modifier le state de MasterClass selon le choix
	     */
		void playMainMenu();
		
		/*!
	     * \brief Lance le menu des réglages
	     *
	     * Lance le menu des réglages du sons uniquement pour le moment
	     */
		void playSettings();
		
		/*!
	     * \brief Jouer !
	     *
	     * Lance le jeu ! L'objet Game s'occupe de tout, MasterClass ne reprend la main que quand la partie est terminée.
	     */
		void playGame();


};

/** @}*/

#endif
