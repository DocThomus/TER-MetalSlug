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

		Environment environment; /*!< \brief Environnement du niveau (Platform, Decor, Destructible). */

	public :

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe Level
	     */
		Level();

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe Level
	     */
		~Level();

		/*!
	     * \brief Affichage
	     *
	     * Affichage des objets du niveau
	     * \param window : Fenêtre de rendu dans laquelle afficher les objets
	     */
		void display(RenderWindow* window);

		/*!
	     * \brief Ajout d'un décor
	     *
	     * Ajoute un objet Decor dans l'environnement.
	     * \param siz : Taille de la fenêtre pour que le decor la recouvre.
	     * \param tex : Texture à appliquer au décor.
	     * \param z : Indice z faculatif, utile pour l'effet parallaxe.
	     */
		void addDecor(Int2 siz, Texture* tex, int z=0);

		/*!
	     * \brief Ajout d'une plate-forme
	     *
	     * Ajoute un objet Platform dans l'environnement.
	     * \param pos : Position de la plate-forme.
	     * \param siz : Taille de la plate-forme.
	     * \param wl : Hauteur du sol de la plate-forme.
	     * \param tex : texture à appliquer à la plate-forme, facultatif.
	     */
		void addPlatform(Int2 pos, Int2 siz, int wl=0, Texture* tex=NULL);
};

/** @}*/

#endif