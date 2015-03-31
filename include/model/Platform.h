#ifndef PLATFORM_H
#define PLATFORM_H

/*!
 * \file Platform.h
 * \author Jules
 * \brief Déclaration de la classe Platform
 * \addtogroup Model 
 * @{
 */

#include <iostream>
#include <sstream>

#include <model/ObjetPhysique.h>

using namespace std;



/*!\class Platform
 * \brief Modélise une plate-forme.
 *
 * C'est un objet simple servant de sol pour les autres objets.
 * Il n'est pas soumis à la gravité.
 */
class Platform : public ObjetPhysique
{
	
	protected :

		int walkline; /*!< \brief Hauteur du sol de la plate-forme. */
		bool visible; /*!< \brief Indique si la plateforme est visible ou non. */


	public :

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur de la classe Platform.
	     * \param pos : Position de la plate-forme.
	     * \param siz : Taille de la plate-forme.
	     * \param walkline : Hauteur du sol de la plate-forme.
	     */
		Platform(Int2 pos, Int2 siz, int walkline=0);

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe Platform
	     */
		Platform();

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe Platform
	     */
		~Platform();

		/*!
	     * \brief Debug
	     *
	     * Affiche des informations sur l'objet.
	     * \param os : Flux sur lequel afficher.
	     */
		void print(ostream& os) const;

		/*!
	     * \brief Retourne la hauteur du sol de la plate-forme.
	     */
		int getWalkline();

		/*!
	     * \brief Définit si la plate-forme est visible ou non.
	     */
		void setVisible(bool b);

};


/** @}*/

#endif