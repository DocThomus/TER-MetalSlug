#ifndef OBJETPHYSIQUE_H
#define OBJETPHYSIQUE_H

/*!
 * \file ObjetPhysique.h
 * \author Jules
 * \brief Déclaration de la classe ObjetPhysique
 * \addtogroup Model 
 * @{
 */

#include <iostream>
#include <tools/tools.h>

using namespace std;


/***
* ObjetPhysique
* ===========================================================
* Modélise un objet physique simple sur lequel on peut 
* appliquer des forces.
***/


class ObjetPhysique
{
	friend ostream& operator << (ostream& os, const ObjetPhysique& obj);

	protected :

		Int2 position;
		Int2 size;

		int mass;
		Float2 movement;


	public :

		ObjetPhysique(Int2 pos,Int2 siz, int m=0);
		ObjetPhysique();
		~ObjetPhysique();

		virtual void animate(int dt);

		inline Int2 getPosition() {return position;};
		inline Int2 getSize() {return size;};
		inline Float2 getMovement() {return movement;};

		void setPosition(Int2 pos);
		void setSize(Int2 siz);
		void setMass(int m);

		void addMovement(Float2 v);

		virtual void print(ostream& os) const;
		
};



/** @}*/

#endif