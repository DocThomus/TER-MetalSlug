#ifndef PLAYER_H
#define PLAYER_H

/*!
 * \file Player.h
 * \author Jules
 * \brief Déclaration de la classe Player
 * \addtogroup Model 
 * @{
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <list>

#include <model/Character.h>
#include <model/Weapon.h>
#include <model/Ammo.h>


using namespace std;


class Weapon;
class Ammo;




/*!\class Player
 * \brief Modélise le joueur.
 *
 * Un Player est un Character contrôlé par le joueur. Il peut
 * posséder différents types d'armes.
 */
class Player : public Character
{
	protected :
		
		vector<Weapon> armes; /*!< \brief Armes possédées par le joueur. */
		int current_weapon; /*!< \brief Indice de l'arme en cours d'utilisation. */


	public :
		
		/*!
	     * \brief Constructeur
	     *
	     * Constructeur de la classe Player.
	     * \param pos : Position initiale du joueur.
	     * \param siz : Taille initiale du joueur.
	     * \param m : Masse du joueur.
	     * \param max_h : Nombre maximal de points de santé.
	     */
		Player(Int2 pos, Int2 siz, int m, int max_h);

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe Player
	     */
		Player();

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe Player
	     */
		~Player();

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
	     * Déplace le joueur en fonction du temps.
	     * \param dt : Temps écoulé depuis le dernier appel de la fonction.
	     */
		virtual void animate(int dt);

		/*!
	     * \brief Courir
	     *
	     * Fait courir le joueur.
	     * \param way : Sens dans lequel le joueur doit se déplacer.
	     */
		virtual void walk(int way);

		/*!
	     * \brief À genoux.
	     *
	     * Fait se mettre à genoux le joueur (ou se lever).
	     * \param b : Vrai si le joueur doit se mettre à genoux, Faux s'il doit se lever.
	     */
		virtual void kneel(bool b);

		/*!
	     * \brief Le personnage meurt.
	     */
		virtual void die();

		/*!
	     * \brief Recharge son arme courante (sera non utilisé...).
	     */
		virtual void reload(int nb);

		/*!
	     * \brief Tirer
	     *
	     * Le joueur tire avec son arme courante.
	     * \param air : Vecteur dans lequel insérer les projectiles générés.
	     * \param angle : Vecteur de la direction dans laquelle les projectiles doivent être propulsés.
	     */
		virtual void shoot(list<Ammo*>* air, Float2 angle = Float2(1.,0.));

		/*!
	     * \brief Attaque au corps à corps.
	     */
		virtual void knife();
		
		/*!
	     * \brief Ajoute une arme au joueur.
	     * \param t : Type de l'arme à ajouter.
	     */
		void addWeapon(Weapon::TypeWeapon t);

		/*!
	     * \brief Modifie l'arme courante.
	     * \param w : Indice de l'arme à selectionner.
	     */
		virtual void setWeapon(int w);

		/*!
	     * \brief Renvoie le type de l'arme courante du joueur.
	     */
		Weapon::TypeWeapon getTypeWeapon();

		/*!
		 * \brief Lance une grenade dans la direction où le joueur va
		 */
		virtual void throwGrenade(list<Ammo*>* air);
};


/** @}*/

#endif