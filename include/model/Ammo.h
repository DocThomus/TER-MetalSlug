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
class Enemy;


/***
* Ammo -> ObjetPhysique
* ===============================================================
* Objets modelisant les tirs. Selon leur type, ils peuvent ou non 
* être soumis à la gravité, être plus ou moins rapide, faire plus
* ou moins de dégâts... Leur type dépend de l'arme ou de l'ennemi 
* qui a produit l'objet.
***/


class Ammo : public ObjetPhysique
{
	friend class Weapon;
	friend class Enemy;

	public :
	
		enum TypeAmmo {BULLET,ROCKET,GRENADE,LASER};
		enum StateAmmo{FLY,STOP,GHOST};


	protected :

		StateAmmo state_a;
		TypeAmmo type;


	public :

		Ammo(Int2 pos, Int2 siz, int m, TypeAmmo type, Float2 move);
		Ammo();
		~Ammo();

		void print(ostream& os) const;

		virtual void animate(int dt);
		virtual void die(Int2 pos);

		int getDamage();
		StateAmmo getState();

};



/** @}*/

#endif