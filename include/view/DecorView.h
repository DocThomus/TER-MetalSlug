#ifndef DECORVIEW_H
#define DECORVIEW_H

/*!
 * \file DecorView.h
 * \author Jules
 * \brief Déclaration de la classe DecorView
 * \addtogroup View
 * @{
 */

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <model/Decor.h>
#include <view/MyDrawable.h>

using namespace std;
using namespace sf;



/*!\class DecorView
 * \brief Un objet Decor affichable.
 *
 * La texture est décalée en fonction du mouvement de la vue.
 * L'indice z de Ammo est aussi utilisé pour créer un effet
 * parallaxe.
 */
class DecorView : public Decor, public MyDrawable
{

	private :

		int tex_x; /*!< \brief Décalage horizontal de la texture. */


	public :
		
		/*!
	     * \brief Constructeur
	     *
	     * Constructeur de la classe DecorView.
	     * \param pos : Position initiale du décor.
	     * \param siz : Taille initiale du décor.
	     * \param z : Indice d'éloignement du décor.
	     */
		DecorView(Int2 pos, Int2 siz, int z);

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe DecorView.
	     */
		DecorView();

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe DecorView
	     */
		~DecorView();

		/*!
	     * \brief Affichage
	     *
	     * Affiche l'objet dans une fenêtre de rendu.
	     * \param window : Fenêtre d'affichage
	     */
		void display(RenderWindow* window);

		/*!
	     * \brief Animer
	     *
	     * Déplace le décor en fonction de la distance parcourue dans le niveau.
	     * \param x : Distance parcourue depuis le début du niveau.
	     */
		void animate(int x);

		/*!
	     * \brief Mise à jour du rectangle de selection de la texture.
	     */
		void updateIntRect();

};


/** @}*/

#endif
