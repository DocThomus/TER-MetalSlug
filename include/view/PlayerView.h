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
			PISTOLKNIFE, PISTOLKNIFE2,
			PISTOLKNEE, PISTOLKNEESHOOT, PISTOLKNEESHOOTUP,

			SHOTGUNRUN, SHOTGUNSHOOT, SHOTGUNSHOOTUP, SHOTGUNSHOOTDOWN,
			SHOTGUNKNIFE, SHOTGUNKNIFE2,
			SHOTGUNKNEE, SHOTGUNKNEESHOOT, SHOTGUNKNEESHOOTUP,

			SMGRUN, SMGSHOOT, SMGSHOOTUP, SMGSHOOTDOWN,
			SMGKNIFE, SMGKNIFE2,
			SMGKNEE, SMGKNEESHOOT, SMGKNEESHOOTUP,
		};

		/*!
	     * \enum PlayerAnimationsLegs
	     * \brief Différentes animations des jambes du joueur.
	     */
		enum PlayerAnimationsLegs
		{
			STAND, RUN, JUMP
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
	     * \brief Deletion des ressources 
	     *
	     * Methode statique permettant de libérer la mémoire allouée aux ressources de la classe.
	     */
		static void deleteRessources();

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
	     * \brief Fait sauter le personnage d'une hauteur h.
	     */
		virtual void jump(int h);

		/*!
	     * \brief Fait atterir le personnage sur une position verticale h. 
	     */
		virtual void land(int h);

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

		/*!
	     * \brief Attaque au corps à corps.
	     */
		virtual void knife();

		/*!
	     * \brief Modifie l'arme courante.
	     * \param w : Indice de l'arme à selectionner.
	     */
		virtual void setWeapon(int w);

		/*!
	     * \brief Renvoie un pointeur vers l'animation de course en fonction de l'arme tenue.
	     */
		PlayerView::PlayerAnimationsBody getAnimRun();

		/*!
	     * \brief Renvoie un pointeur vers l'animation de tir en fonction de l'arme tenue.
	     */
		PlayerView::PlayerAnimationsBody getAnimShoot();

		/*!
	     * \brief Renvoie un pointeur vers l'animation de tir vers le haut en fonction de l'arme tenue.
	     */
		PlayerView::PlayerAnimationsBody getAnimShootUp();

		/*!
	     * \brief Renvoie un pointeur vers l'animation de tir vers le bas en fonction de l'arme tenue.
	     */
		PlayerView::PlayerAnimationsBody getAnimShootDown();

		/*!
	     * \brief Renvoie un pointeur vers l'animation du corps à corps en fonction de l'arme tenue.
	     */
		PlayerView::PlayerAnimationsBody getAnimKnife();

		/*!
	     * \brief Renvoie un pointeur vers l'animation du corps à corps 2 en fonction de l'arme tenue.
	     */
		PlayerView::PlayerAnimationsBody getAnimKnife2();

		/*!
	     * \brief Renvoie un pointeur vers l'animation accroupie en fonction de l'arme tenue.
	     */
		PlayerView::PlayerAnimationsBody getAnimKnee();

		/*!
	     * \brief Renvoie un pointeur vers l'animation accroupie de tir en fonction de l'arme tenue.
	     */
		PlayerView::PlayerAnimationsBody getAnimKneeShoot();

		/*!
	     * \brief Renvoie un pointeur vers l'animation accroupie de tir vers la haut en fonction de l'arme tenue.
	     */
		PlayerView::PlayerAnimationsBody getAnimKneeShootUp();
};


/** @}*/

#endif
