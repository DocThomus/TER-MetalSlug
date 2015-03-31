#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

/*!
 * \file PlayerView.h
 * \author Jules
 * \brief Déclaration de la classe PlayerView
 * \addtogroup View
 * @{
 */

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <tools/tools.h>

#include <model/Player.h>
#include <view/MyDrawable.h>
#include <view/AmmoView.h>
#include <view/WeaponView.h>
#include <view/MemberView.h>

using namespace std;
using namespace sf;

class WeaponView;



/*!\class PlayerView
 * \brief Un objet Player affichable.
 */
class PlayerView : public Player, public MyDrawable
{
	public :

		/*!
	     * \enum PlayerAnimationsBody
	     * \brief Différentes animations du corps du joueur.
	     */
		enum PlayerAnimationsBody
		{
			PISTOLRUN, PISTOLSHOOT, PISTOLSHOOTUP, PISTOLSHOOTDOWN,
			PISTOLKNEE, PISTOLKNEESHOOT, PISTOLKNEESHOOTUP
		};

		/*!
	     * \enum PlayerAnimationsLegs
	     * \brief Différentes animations des jambes du joueur.
	     */
		enum PlayerAnimationsLegs
		{
			STAND, RUN, SLOW, FALL, JUMP
		};


	private :

		static vector<Sound*> sounds; /*!< \brief Variable de classe contenant les différents son nécessaires au player. */
		static Texture* textures[2]; /*!< \brief Variable de classe contenant les différentes textures nécessaires au player. */
		static vector<Animation> animations_list[2]; /*!< \brief Variable de classe contenant les différentes animations nécessaires au player. */


	public :

		MemberView legs; /*!< \brief L'objet symbolisant les jambes du joueur. */

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur de la classe PlayerView.
	     * \param pos : Position initiale du joueur.
	     * \param siz : Taille initiale du joueur.
	     * \param m : Masse du joueur.
	     * \param max_h : Santé maximale du joueur.
	     */
		PlayerView(Int2 pos, Int2 siz, int m, int max_h);

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe PlayerView
	     */
		PlayerView();

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe PlayerView
	     */
		~PlayerView();

		/*!
	     * \brief Chargement des ressources
	     *
	     * Methode statique permettant de charger les ressources du player.
	     * ATTENTION : Cette méthode doit impérativement être appelée avant d'afficher du player !
	     */
		static void loadRessources();

		/*!
	     * \brief Initialisation
	     *
	     * Initialise l'affichage du joueur.
	     */
		void init();

		/*!
	     * \brief Affichage
	     *
	     * Affiche le joueur dans une fenêtre de rendu.
	     * \param window : Fenêtre d'affichage
	     */
		void display(RenderWindow* window);

		/*!
	     * \brief Animer
	     *
	     * Déplace le joueur en fonction du temps.
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
	     * Fait courir le joueur dans une direction passée en paramètre.
	     * Change l'animation du joueur en conséquence.
	     */
		void walk(int way);

		/*!
	     * \brief À genoux.
	     *
	     * Fait se mettre à genoux le joueur (ou se lever).
	     * Change l'animation du joueur en conséquence.
	     * \param b : Vrai si le joueur doit se mettre à genoux, Faux s'il doit se lever.
	     */
		void kneel(bool b);

		/*!
	     * \brief Tirer.
	     *
	     * \param air : Pointeur sur un vecteur d'AmmoView destiné à contenir les projectiles du jeu.
	     * \param angle : Direction dans laquelle le personnage tire.
	     */
		virtual void shoot(list<AmmoView*>* air, Int2 angle = Int2(1,0));
};


/** @}*/

#endif
