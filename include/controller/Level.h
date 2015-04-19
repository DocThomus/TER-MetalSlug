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
#include <list>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <controller/Environment.h>
#include <controller/EventGame.h>

using namespace std;

class Environment;
class EventGame;


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
		list<EventGame*> events; /*!< \brief Liste des événements du niveau. */

		vector<Music*> musics; /*!< \brief Contient les musiques du niveau. */
		vector<Texture*> textures; /*!< \brief Contient les différents textures de l'environnement. */


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
		void display(RenderWindow* window, Color color = Color(0,0,0,255));

		/*!
	     * \brief Chargement
	     *
	     * Charge un niveau à partir d'un fichier.
	     */
		void loadFromFile(string filename, Config* config);

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

		/*!
	     * \brief Joue une musique du level
	     * \param id : Indice de la musique à jouer dans le vecteur musics.
	     */
		void playMusic(int id);
		
		/*!
	     * \brief Modifier volume
	     *
	     * Modifie le volume des musiques du level
	     * \param volume : Nouveau volume des musiques du level.
	     */
		void setVolume(float volume);
		
		/*!
	     * \brief Reprendre
	     *
	     * Relance la musique du Level.
	     */
		void resume();
		
		/*!
	     * \brief Pause
	     *
	     * Met en pause la musique du Level.
	     */
		void pause();

};

/** @}*/

#endif
