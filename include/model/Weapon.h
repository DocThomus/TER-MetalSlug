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
#include <stdio.h>

#include <model/ObjetPhysique.h>
#include <model/Ammo.h>
#include <model/Player.h>

using namespace std;


class Player;
class Ammo;



/***
* Weapon
* ===============================================================
* Objet possédé par un Player. Il produit des Ammo lorsque son
* propriétaire tire. Le type et le nombre de munitions généré
* est défini en fonction de son type.
***/



class Weapon
{

	public:
		
		enum TypeWeapon {PISTOL,SMG,SHOTGUN,ROCKET_LAUNCHER,GRENADE_LAUNCHER,CANARDATOR};
	
	
	protected :

		Int2 ammos;
		Int2 angle;
		Player* owner;
		TypeWeapon type;


	public :

		
		
		
		Weapon(Int2 pos, Int2 siz, int m, Player* p, TypeWeapon type, int max_mun);
		Weapon(Player* p, TypeWeapon type, int max_mun);
		Weapon();
		~Weapon();

		void print(ostream& os) const;

		void shoot(list<Ammo*>* air, Float2 angle);	
		void reload(int nb);


};



/** @}*/

#endif