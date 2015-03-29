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



/*!\class ObjetPhysique
 * \brief Modélise un objet physique.
 *
 * Modélise un objet physique simple sur lequel on peut appliquer des forces.
 */
class ObjetPhysique
{
	friend ostream& operator << (ostream& os, const ObjetPhysique& obj);

	protected :

		Int2 position; /*!< \brief Position de l'objet. */
		Int2 size; /*!< \brief Taille de l'objet. */

		int mass; /*!< \brief Masse de l'objet. */
		Float2 movement; /*!< \brief Mouvement de l'objet. */


	public :

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur de la classe ObjetPhysique.
	     * \param pos : Position initiale de l'objet.
	     * \param siz : Taille initiale de l'objet.
	     * \param m : Masse de l'objet.
	     */
		ObjetPhysique(Int2 pos,Int2 siz, int m=0);

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe ObjetPhysique
	     */
		ObjetPhysique();

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe ObjetPhysique
	     */
		~ObjetPhysique();

		/*!
	     * \brief Animer
	     *
	     * Déplace l"objet en fonction du temps.
	     * \param dt : Temps écoulé depuis le dernier appel de la fonction.
	     */
		virtual void animate(int dt);

		/*!
	     * \brief Retourne la position de l'objet.
	     */
		inline Int2 getPosition() {return position;};

		/*!
	     * \brief Retourne la taille de l'objet.
	     */
		inline Int2 getSize() {return size;};

		/*!
	     * \brief Retourne le vecteur de mouvement de l'objet.
	     */
		inline Float2 getMovement() {return movement;};

		/*!
	     * \brief Redéfinit la position de l'objet.
	     */
		void setPosition(Int2 pos);

		/*!
	     * \brief Redéfinit la taille de l'objet.
	     */
		void setSize(Int2 siz);

		/*!
	     * \brief Redéfinit la masse de l'objet.
	     */
		void setMass(int m);

		/*!
	     * \brief Application d'une force.
	     *
	     * Applique une force à l'objet et modifie son vecteur de mouvement en conséquence.
	     * \param v : Vecteur de la force à appliquer.
	     */
		void addMovement(Float2 v);

		/*!
	     * \brief Debug
	     *
	     * Affiche des informations sur l'objet.
	     * \param os : Flux sur lequel afficher.
	     */
		virtual void print(ostream& os) const;
		
};



/** @}*/

#endif