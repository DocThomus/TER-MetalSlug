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


/***
* Enemy -> Character -> ObjetPhysique
* ===============================================================
* Un Enemy est un Character contrôlé par la machine, opposé à 
* celui contrôlé par le joueur (Player). Il doit soit obéir à
* un pattern de mouvement, soit possèder une intelligence
* très simple.
***/



class Enemy : public Character 
{
	
	protected :

		Int2 health;
		bool haveAI;
		int power;


	public :
		
		Enemy(Int2 pos, Int2 siz, int m, int max_h, bool AI, int pow);
		Enemy();
		~Enemy();

		void print(ostream& os) const;	

		void animate (int dt);
		void attack(vector<Ammo*>* air);
		void die();

};


/** @}*/

#endif