#ifndef ENEMYVIEW_H
#define ENEMYVIEW_H

/*!
 * \file EnemyView.h
 * \author Jules
 * \brief Déclaration de la classe EnemyView
 * \addtogroup View
 * @{
 */

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <tools/tools.h>

#include <model/Enemy.h>
#include <view/MyDrawable.h>
#include <view/AmmoView.h>

using namespace std;
using namespace sf;

class WeaponView;



/*!\class EnemyView
 * \brief Un objet Enemy affichable.
 */
class EnemyView : public Enemy, public MyDrawable
{

	private :

		static vector<Sound*> sounds; /*!< \brief Variable de classe contenant les différents son nécessaires aux ennemis. */
		static Texture* textures[NB_TYPE_ENEMY]; /*!< \brief Variable de classe contenant les différentes textures nécessaires aux ennemis. */
		static vector<Animation> animations_list[NB_TYPE_ENEMY]; /*!< \brief Variable de classe contenant les différents animations nécessaires aux ennemies. */

	public :

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur de la classe EnemyView.
	     * \param pos : Position initiale de l'ennemi.
	     * \param siz : Taille initiale de l'ennemi.
	     * \param m : Masse de l'ennemi.
	     * \param max_h : Santé maximale de l'ennemi.
	     * \param AI : Indique si l'ennemi doit être "intelligent" ou non.
	     * \param pow : La puissance de l'ennemi.
	     */
		EnemyView(Int2 pos, Int2 siz, int m, int max_h, bool AI, int pow);

		/*!
	     * \brief Constructeur
	     *
	     * Construit un ennemi du type indiqué.
	     * \param pos : Position initiale de l'ennemi.
	     * \param t : TYpe de l'ennemi.
	     */
		EnemyView(Int2 pos, TypeEnemy t);

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe EnemyView
	     */
		EnemyView();

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe EnemyView
	     */
		~EnemyView();

		/*!
	     * \brief Chargement des ressources
	     *
	     * Methode statique permettant de charger les ressources des ennemis.
	     * ATTENTION : Cette méthode doit impérativement être appelée avant d'afficher des ennemis !
	     */
		static void loadRessources(TypeEnemy t);

		/*!
	     * \brief Initialisation
	     *
	     * Initialise l'affichage de l'ennemi.
	     */
		void init();

		/*!
	     * \brief Affichage
	     *
	     * Affiche l'objet dans une fenêtre de rendu.
	     * \param window : Fenêtre d'affichage
	     */
		void display(RenderWindow* window);

		/*!
	     * \brief Animer
	     *
	     * Déplace l'ennemi en fonction du temps.
	     * \param dt : Temps écoulé depuis le dernier appel de la fonction.
	     */
		void animate(int dt);

		/*!
	     * \brief Mise à jour du rectangle de selection de la texture.
	     */
		void updateIntRect();

		/*!
	     * \brief Courir
	     *
	     * Fait courir l'ennemi dans une direction passée en paramètre.
	     */
		void walk(int way);
		
		/*!
	     * \brief Mourir
	     *
	     * L'ennemi meurt, méthode déclenchée lorsque sa santé atteint 0.
	     * Déclenchement d'une animation et d'un son.
	     */
		void die();

		/*!
	     * \brief Tirer.
	     *
	     * \param air : Pointeur sur un vecteur d'Ammo destiné à contenir les projectiles du jeu.
	     * \param angle : Direction dans laquelle le personnage tire.
	     */
		void shoot(list<AmmoView*>* air, Int2 angle = Int2(1,0));
};


/** @}*/

#endif
