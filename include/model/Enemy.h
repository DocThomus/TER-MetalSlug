#ifndef ENEMY_H
#define ENEMY_H

/*!
 * \file Enemy.h
 * \author Jules
 * \brief Déclaration de la classe Enemy
 * \addtogroup Model 
 * @{
 */

#include <iostream>
#include <sstream>
#include <vector>

#include <model/Character.h>

using namespace std;



/*!\class Enemy
 * \brief Modélise un ennemi.
 *
 * Un Enemy est un Character contrôlé par la machine, opposé à 
 * celui contrôlé par le joueur (Player). Il doit soit obéir à
 * un pattern de mouvement, soit possèder une intelligence
 * très simple.
 */
class Enemy : public Character 
{

	public :

		/*!\enum TypeEnemy
		 * \brief Énumération des différents types d'ennemis.
		 */
		enum TypeEnemy{ REBEL, BOWSER, NB_TYPE_ENEMY };

	
	protected :

		TypeEnemy type; /*!< \brief Type de l'ennemi. */
		bool haveAI; /*!< \brief Indique si l'ennemi doit posséder une intelligence ou non. */
		int power; /*!< \brief Indique la puissance des attaques de l'ennemi. */
		int cpt_shoot; /*!< \brief Compteur pour la cadence de tir. */

	public :
		
		/*!
	     * \brief Constructeur
	     *
	     * Constructeur de la classe Enemy.
	     * \param pos : Position initiale de l'ennemi.
	     * \param siz : Taille initiale de l'ennemi.
	     * \param m : Masse de l'ennemi.
	     * \param max_h : Santé maximale de l'ennemi.
	     * \param AI : Indique si l'ennemi doit être "intelligent" ou non.
	     * \param pow : La puissance de l'ennemi.
	     */
		Enemy(Int2 pos, Int2 siz, int m, int max_h, bool AI, int pow);

		/*!
	     * \brief Constructeur
	     *
	     * Construit un ennemi du type indiqué.
	     * \param pos : Position initiale de l'ennemi.
	     * \param t : Type de l'ennemi.
	     * \param AI : Indique si l'ennemi doit être intelligent ou non.
	     */
		Enemy(Int2 pos, TypeEnemy t, bool AI=false);

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe Enemy
	     */
		Enemy();

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe Enemy
	     */
		~Enemy();

		/*!
	     * \brief Debug
	     *
	     * Affiche des informations sur l'objet.
	     * \param os : Flux sur lequel afficher.
	     */
		void print(ostream& os) const;	

		/*!
	     * \brief Animer
	     *
	     * Déplace l'ennemi en fonction du temps.
	     * \param dt : Temps écoulé depuis le dernier appel de la fonction.
	     */
		void animate (int dt);

		/*!
	     * \brief Courir
	     *
	     * Fait courir l'ennemi.
	     * \param way : Sens dans lequel l'ennemi doit se déplacer.
	     */
		virtual void walk(int way);

		/*!
	     * \brief Tirer
	     *
	     * L'ennemi tire.
	     * \param air : Vecteur dans lequel insérer les projectiles générés.
	     * \param angle : Vecteur de la direction dans laquelle les projectiles doivent être propulsés.
	     */
		virtual void shoot(list<Ammo*>* air, Float2 angle = Float2(1.,0.));

		/*!
	     * \brief Possibilité de tirer
	     *
	     * Indique si l'ennemi est en état de tirer ou non.
	     */
		virtual bool canShoot();

		/*!
	     * \brief Mourir
	     *
	     * L'ennemi meurt, méthode déclenchée lorsque sa santé atteint 0.
	     */
		void die();

		/*!
		 * \brief Accesseur IA
		 */
		bool getIA();

		/*!
		 * \brief Accesseur power
		 */
		int getPower();

		/*!
		 * \brief Retourne le type de l'ennemi.
		 */
		TypeEnemy getType();

};


/** @}*/

#endif