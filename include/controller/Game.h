#ifndef GAME_H
#define GAME_H

/*!
 * \file Game.h
 * \author Jules
 * \brief Déclaration de la classe Game
 * \addtogroup Controller 
 * @{
 */

#include <iostream>
#include <list>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <tools/XMLtools.h>

#include <controller/Config.h>
#include <controller/Level.h>
#include <view/Animation.h>
#include <view/Frame.h>
#include <view/PlayerView.h>
#include <view/EnemyView.h>
#include <view/AmmoView.h>
#include <view/WeaponView.h>

using namespace std;
using namespace sf;


class Level;

class Animation;
class PlayerView;
class EnnemyView;


/*! \class Game
 * \brief Gère le jeu lolu.
 *
 * Gère les objets du jeu : 
 * - Application de la configuration
 * - Animation des objets
 * - Gestion des collisions
 * - Gestion des événements (clavier, souris...)
 * - Destruction des objets devenus inutiles
 * - Affichage des objets 
 */
class Game
{
	
	private :

		Config* config; /*!< \brief Configuration du jeu */

		Level level; /*!< \brief Niveau en cours */

		View view; /*!< \brief Vue de la fenêtre de rendu */
		ObjetPhysique* view_target; /*!< \brief Cible de le vue */

		PlayerView player; /*!< \brief Joueur */
		list<EnemyView*> enemies; /*!< \brief Liste des ennemis à l'écran */
		list<AmmoView*> ammo; /*!< \brief Liste des projectiles à l'écran */

		vector<Texture*> textures; /*!< \brief Stockage des textures utilisée par les objets du jeu pour suppression à la fin du niveau */


	public :

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe Game
	     */
		Game();

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe Game
	     */
		~Game();


		/*!
	     * \brief Mise à jour de la scène
	     *
	     * Anime les objets en fonction du temps + supression des objets devenus inutiles
	     * \param dt : Temps écoulé depuis la dernière mise à jour.
	     */
		void update(Time dt);

		/*!
	     * \brief Mise à jour de la vue
	     *
	     * Déplace la vue en fonction de la position de la cible et du temps
	     * \param dt : Temps écoulé depuis la dernière mise à jour.
	     */
		void updateView(int dt);

		/*!
	     * \brief Affichage
	     *
	     * Affichage des objets du jeu
	     * \param window : Fenêtre de rendu dans laquelle afficher les objets
	     */
		void display(RenderWindow* window);

		/*!
	     * \brief Gestion des événements clavier
	     *
	     * Gère les événements clavier.
	     * \param window : Fenêtre de rendu pour laquelle on doit vérifier les événements
	     */
		void checkEvents(RenderWindow* window);

		/*!
	     * \brief Gestion des collisions
	     *
	     * Vérification des différentes collisions du jeu :
	     * - Character / Platform
	     * - Character / Ammo
	     * - Ammo / Platform
	     * - ...
	     */
		void checkCollisions();

		/*!
	     * \brief Vérification de l'intersection
	     *
	     * Vérifie si deux ObjetPhysique s'intersectent.
	     * \param obj1 : Objet 1
	     * \param obj2 : Objet 2
	     */
		bool checkIntersect(ObjetPhysique* obj1, ObjetPhysique* obj2);

		/*!
	     * \brief Vérification de la collision haute
	     *
	     * Vérifie la collision entre l'objet 1 et le haut de l'objet 2.
	     * \param obj1 : Objet 1
	     * \param obj2 : Objet 2
	     */
		bool checkCollisionTop(ObjetPhysique* obj1, ObjetPhysique* obj2);

		/*!
	     * \brief Vérification de la collision basse
	     *
	     * Vérifie la collision entre l'objet 1 et le bas de l'objet 2.
	     * \param obj1 : Objet 1
	     * \param obj2 : Objet 2
	     */
		bool checkCollisionBottom(ObjetPhysique* obj1, ObjetPhysique* obj2);

		/*!
	     * \brief Vérification de la collision gauche
	     *
	     * Vérifie la collision entre l'objet 1 et la gauche de l'objet 2.
	     * \param obj1 : Objet 1
	     * \param obj2 : Objet 2
	     */
		bool checkCollisionLeft(ObjetPhysique* obj1, ObjetPhysique* obj2);

		/*!
	     * \brief Vérification de la collision droite
	     *
	     * Vérifie la collision entre l'objet 1 et la droite de l'objet 2.
	     * \param obj1 : Objet 1
	     * \param obj2 : Objet 2
	     */
		bool checkCollisionRight(ObjetPhysique* obj1, ObjetPhysique* obj2);

		/*!
	     * \brief Suppression des objets obsolète
	     *
	     * Supprime les objets devenus inutiles.
	     * Exemple : Les projectiles sortis de l'écran.
	     */
		void deleteDeadObjects();

		/*!
	     * \brief Application de la configuration
	     *
	     * Applique la configuration à la fenêtre de rendu
	     * \param window : Fenêtre de rendu pour laquelle appliquer la configuration
	     */
		void applyConfig(RenderWindow* window);

		/*!
	     * \brief Définition d'une configuration
	     *
	     * Défini une configuration au Game. 
	     */
		void setConfig(Config* c);

		/*!
	     * \brief Initialisation du jeu 
	     *
	     * Initialise le jeu, complètement inutile pour le moment car appelle seulement la méthode Game::loadLevel().
	     */
		void init();

		/*!
	     * \brief Chargement d'un niveau
	     *
	     * Charge un niveau (pour l'instant il existe un unique niveau donc pas de paramètre).
	     */
		void loadLevel();

		/*!
	     * \brief Chargement d'une animation 
	     *
	     * Charge une animation à partir d'un fichier XML (cette fonction doit être déplacée dans "tools").
	     */
		vector<Animation*> loadSpriteFromFile(string filename);

};

/** @}*/

#endif