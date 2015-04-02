#ifndef WEAPON_H
#define WEAPON_H

/*!
 * \file Weapon.h
 * \author Jules
 * \brief Déclaration de la classe Weapon
 * \addtogroup Model 
 * @{
 */

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <list>
#include <ctime>
#include <sys/time.h>

#include <SFML/System.hpp>

#include <model/ObjetPhysique.h>
#include <model/Ammo.h>

using namespace std;


class Player;
class Ammo;




/*!\class Weapon
 * \brief Modélise une arme.
 *
 * Objet possédé par un Player. Il produit des Ammo lorsque son
 * propriétaire tire. Le type et le nombre de munitions généré
 * est défini en fonction de son type.
 */
class Weapon
{

	public:
		
		/*!
	     * \enum TypeWeapon
	     * \brief Énumération des différents types d'armes.
	     */
		enum TypeWeapon {PISTOL,SMG,SHOTGUN,ROCKET_LAUNCHER,GRENADE_LAUNCHER,CANARDATOR};
	
	
	protected :

		Int2 ammos; /*!< \brief Nombre de munitions restantes. */
		Int2 angle; /*!< \brief Angle dans lequel l'arme vise (inutile pour le moment...). */
		Player* owner; /*!< \brief Joueur possédant l'arme. */
		TypeWeapon type; /*!< \brief Type de l'arme. */
		Ammo::TypeAmmo type_ammo; /*!< \brief Type des projectiles générés par l'arme. */


	public :

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur de la classe Weapon.
	     * \param type : Type de l'arme
	     */
		Weapon(TypeWeapon type);

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe Weapon
	     */
		Weapon();

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe Ammo
	     */
		~Weapon();

		/*!
	     * \brief Debug
	     *
	     * Affiche des informations sur l'objet.
	     * \param os : Flux sur lequel afficher.
	     */
		void print(ostream& os) const;

		/*!
	     * \brief Tirer
	     * \param air : Vecteur dans lequel insérer les Ammo générées par l'arme.
	     * \param angle : Vecteur du/des direction du projectile à générer.
	     */
		void shoot(list<Ammo*>* air, Float2 angle);


		/*!
	     * \brief Recharger (sera sûrement retiré...)
	     */
		void reload(int nb);


		/*!
	     * \brief Définit le propriétaire de l'arme.
	     */
		void setOwner(Player* p);

		/*!
	     * \brief Retourne le type de l'arme.
	     */
		TypeWeapon getType();

};



/** @}*/

#endif