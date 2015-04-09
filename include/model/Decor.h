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



/*!\class Decor
 * \brief Modélise un decor.
 *
 * Objet simple modélisant un arrière-plan. Son attribut z permet
 * de simuler un effet d'éloignement grâce à l'effet parallaxe.
 */
class Decor : public ObjetPhysique
{
	
	protected :

		int z; /*!< \brief Indice d'éloignement du décor. */


	public :

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur de la classe Decor.
	     * \param pos : Position initiale du décor.
	     * \param siz : Taille initiale du décor.
	     * \param z : Indice d'éloignement du décor.
	     */
		Decor(Int2 pos, Int2 siz, int z);

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe Decor
	     */
		Decor();

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe Decor
	     */
		~Decor();

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
	     * Déplace le décor en fonction de la distance parcourue dans le niveau.
	     * \param x : Distance parcourue depuis le début du niveau.
	     */
		virtual void animate(int x);

};



/** @}*/

#endif