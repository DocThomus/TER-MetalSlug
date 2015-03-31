#ifndef CHARACTER_H
#define CHARACTER_H

/*!
 * \file Character.h
 * \author Jules
 * \brief Déclaration de la classe Character
 * \addtogroup Model 
 * @{
 */

#include <iostream>
#include <sstream>
#include <list>
#include <tools/tools.h>

#include <model/ObjetPhysique.h>
#include <model/Ammo.h>

using namespace std;

class Ammo;


/*!\class Character
 * \brief Modélise un personnage.
 *
 * Le personnage est caractérisé par sa jauge de santé ainsi que
 * ses mouvements : il peut courir, sauter, tirer, mourir...
 */
class Character : public ObjetPhysique
{

	public :

		/*!
	     * \enum StatePosition
	     * \brief Positions possibles du personnage.
	     */
		enum StatePosition {WAIT,RUN,KNELT};

		/*!
	     * \enum StateGround
	     * \brief États du personnage vis-a-vis du sol.
	     */
		enum StateGround {GROUND,AIR};

		/*!
	     * \enum StateBattle
	     * \brief Actions pouvant être effectuée par un personnage.
	     */
		enum StateBattle {NORMAL,SHOOT,DEAD,KNIFE,STAR};


	protected :

		StatePosition state_p; /*!< \brief Position du personnage. */
		StateGround state_g; /*!< \brief Indique si le personnage est au sol ou en l'air. */
		StateBattle state_b; /*!< \brief Indique quelle action effectue le personnage. */

		Int2 health; /*!< \brief Santé du personnage. */

		int walkway; /*!< \brief Indique le sens dans lequel le personnage se dirige. */
		Int2 gunway; /*!< \brief Indique le sens dans lequel le personnage tire. */

		int star_cpt; /*!< \brief Compteur de l'état STAR temporaire. */


	public :

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur de la classe Character.
	     * \param pos : Position initiale du personnage.
	     * \param siz : Taille initiale du personnage.
	     * \param m : Masse du personnage.
	     * \param max_h : Santé maximale du personnage.
	     */
		Character(Int2 pos, Int2 siz, int m, int max_h);

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe Character
	     */
		Character();

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe Character
	     */
		~Character();

		/*!
	     * \brief Animer
	     *
	     * Déplace le personnage en fonction du temps.
	     * \param dt : Temps écoulé depuis le dernier appel de la fonction.
	     */
		virtual void animate(int dt);

		/*!
	     * \brief Debug
	     *
	     * Affiche des informations sur l'objet.
	     * \param os : Flux sur lequel afficher.
	     */
		virtual void print(ostream& os) const;

		/*!
	     * \brief Renvoie l'état position du personnage.
	     */
		StatePosition getStatePosition();

		/*!
	     * \brief Renvoie l'état vis-a-vis du sol du personnage.
	     */
		StateGround getStateGround();

		/*!
	     * \brief Renvoie l'état d'action du personnage
	     */
		StateBattle getStateBattle();

		/*!
	     * \brief Diminution de santé
	     *
	     * Retire de la santé au personnage. Si celle-ci atteint 0, la méthode die est appelée.
	     */
		void decreaseHealth(int s);

		/*!
	     * \brief Récupération de santé.
	     *
	     * Le personnage récupère des points de santé. Sa santé ne peut pas dépasser son nombre maximal définie lors de la construction du personnage.
	     */
		void increaseHealth(int s);

		/*!
	     * \brief Rends le personnage invincible pendant quelques secondes (Non implémenté).
	     */
		virtual void setInvicibility(int seconds);

		/*!
	     * \brief Fait sauter le personnage d'une hauteur h.
	     */
		virtual void jump(int h);

		/*!
	     * \brief Fait atterir le personnage sur une position verticale h. 
	     */
		virtual void land(int h);

		/*!
	     * \brief Stoppe l'ascension du personnage lorsqu'il saute à une hauteur h.
	     */
		virtual void bumpTop(int h);

		/*!
	     * \brief Stoppe la course du personnage vers la gauche à une position x.
	     */
		virtual void bumpLeft(int x);

		/*!
	     * \brief Stoppe la course du personnage vers la droite à une position x.
	     */
		virtual void bumpRight(int x);

		/*!
	     * \brief Tirer.
	     *
	     * \param air : Pointeur sur un vecteur d'Ammo destiné à contenir les projectiles du jeu.
	     * \param angle : Direction dans laquelle le personnage tire.
	     */
		virtual void shoot(list<Ammo*>* air, Float2 angle = Float2(1.,0.));

		/*!
	     * \brief Le personnage meurt.
	     */
		virtual void die();

		/*!
	     * \brief Courir
	     *
	     * Fait courir le personnage dans une direction passée en paramètre.
	     */
		virtual void walk(int way);

		/*!
	     * \brief À genoux.
	     *
	     * Fait se mettre à genoux le personnage (ou se lever).
	     * \param b : Vrai si le personnage doit se mettre à genoux, Faux s'il doit se lever.
	     */
		virtual void kneel(bool b);
		
};



/** @}*/

#endif