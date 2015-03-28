#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

/*!
 * \file Environment.h
 * \author Jules
 * \brief Déclaration de la classe Environment
 * \addtogroup Controller 
 * @{
 */

#include <iostream>
#include <list>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <view/DecorView.h>
#include <view/PlatformView.h>

using namespace std;

class Decor;
class Platform;



/*!\class Environment
 * \brief Stocke l'environnement.
 *
 * Stocke les objets de l'environnement (décors,plate-formes,destructibles).
 */
class Environment
{

	friend class Game;

	private :

		list<DecorView> decors; /*!< \brief Liste des décors de l'environnement*/
		list<PlatformView> platforms; /*!< \brief Liste des plate-formes de l'environnement*/
		//list<Destructible> destructibles; /*!< \brief Liste des éléments destructibles de l'environnement*/ // TODO
		

	public :

		/*!
	     *  \brief Constructeur
	     *
	     *  Constructeur pas défaut de la classe Environment
	     */
		Environment();

		/*!
	     *  \brief Destructeur
	     *
	     *  Destructeur de la classe Environment
	     */
		~Environment();

		/*!
	     *  \brief Affichage
	     *
	     *  Affiche tous les objets de l'environnement
	     *
	     * \param window : Fenêtre de rendu où afficher les objets
	     */
		void display(RenderWindow* window);

		/*!
	     *  \brief Ajout d'un Decor
	     *
	     *  Ajoute un Decor dans l'environnement
	     *
	     * \param siz : Taille de l'écran
	     * \param tex : Texture à appliquer au décor
	     * \param z : Indice z (pour l'effet parallaxe)
	     */
		void addDecor(Int2 siz, Texture* tex, int z);

		/*!
	     *  \brief Ajout d'une Platform
	     *
	     *  Ajoute une Platform dans l'environnement
	     *
	     * \param pos : Position de la plate-forme
	     * \param siz : Taille de la plate-forme
	     * \param wl : Hauteur du sol de la plateforme (non traité pour le moment)
	     * \param tex : Texture à appliquer à la plate-forme
	     */
		void addPlatform(Int2 pos, Int2 siz, int wl, Texture* tex=NULL);
		

		//void addDestructible(); // TODO
};

/** @}*/

#endif