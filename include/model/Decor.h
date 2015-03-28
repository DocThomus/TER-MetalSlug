#ifndef DECOR_H
#define DECOR_H

/*!
 * \file Decor.h
 * \author Jules
 * \brief Déclaration de la classe Decor
 * \addtogroup Model 
 * @{
 */

#include <iostream>
#include <sstream>

#include <model/ObjetPhysique.h>

using namespace std;


/***
* Decor -> ObjetPhysique
* ===============================================================
* Objet simple modélisant un arrière-plan. Son attribut z permet
* de simuler un effet d'éloignement grâce à l'effet parallaxe.
***/



class Decor : public ObjetPhysique
{
	
	protected :

		int z;


	public :

		Decor(Int2 pos, Int2 siz, int z);
		Decor();
		~Decor();

		void print(ostream& os) const;

		virtual void animate(int x);

};



/** @}*/

#endif