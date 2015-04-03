#ifndef AMMO_H
#define AMMO_H

/*!
 * \file Ammo.h
 * \author Jules
 * \brief Déclaration de la classe Ammo
 * \addtogroup Model 
 * @{
 */

#include <iostream>
#include <sstream>


#include <model/ObjetPhysique.h>

using namespace std;

class Weapon;
class Character;
class Enemy;


/*!\class Ammo
 * \brief Modélise un projectile.
 *
 * Le projectile peut être de différents type, soumis ou non à la gravité...
 */
class Ammo : public ObjetPhysique
{
	friend class Weapon;
	friend class Enemy;

	public :
	
		/*!
	     * \enum TypeAmmo
	     * \brief Types possibles de l'objet Ammo.
	     */
		enum TypeAmmo {BULLET, HEAVY_BULLET, LIGHT_BULLET, ROCKET, GRENADE, LASER,
						NB_TYPE_AMMO};

		/*!
	     * \enum StateAmmo
	     * \brief États possibles de l'objet Ammo.
	     */
		enum StateAmmo{FLY,STOP,GHOST};


	protected :

		StateAmmo state_a; /*!< \brief État du projectile. */
		TypeAmmo type; /*!< \brief Type du projectile. */
		Character* owner; /*!< \brief Character qui a tiré le projectile. */


	public :

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur de la classe Ammo.
	     * \param pos : Position initiale du projectile.
	     * \param siz : Taille initiale du projectile (inutile car l'objet est ensuite redimensionné en fonction de son type).
	     * \param m : Masse du projectile (inutile car la masse de l'objet est redéfinie en fonction de son type).
	     * \param type : Type du projectile.
	     * \param move : Vecteur de direction.
	     * \param c : Character à l'origine du projectile.
	     */
		Ammo(Int2 pos, Int2 siz, int m, TypeAmmo type, Float2 move, Character* c);

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe Ammo
	     */
		Ammo();

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe Ammo
	     */
		~Ammo();

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
	     * Déplace le projectile en fonction du temps.
	     * \param dt : Temps écoulé depuis le dernier appel de la fonction.
	     */
		virtual void animate(int dt);

		/*!
	     * \brief Projectile stoppé
	     *
	     * Le projectile "meurt" (il explose, disparait...).
	     * \param pos : Position d'arrêt de l'objet.
	     */
		virtual void die(Int2 pos);

		/*!
	     * \brief Dégâts
	     *
	     * Renvoie le nombre de point de dégâts qu'inflique le projectile en fonction de son type.
	     */
		int getDamage();

		/*!
	     * \brief État
	     *
	     * Renvoie l'état de la munition.
	     */
		StateAmmo getState();

		/*!
	     * \brief Tireur
	     *
	     * Renvoie un pointeur sur le character qui a tiré le projectile
	     */
		Character* getOwner();

};



/** @}*/

#endif