#ifndef PLATFORMVIEW_H
#define PLATFORMVIEW_H

/*!
 * \file PlatformView.h
 * \author Jules
 * \brief Déclaration de la classe PlatformView
 * \addtogroup View
 * @{
 */

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <model/Platform.h>
#include <view/MyDrawable.h>

using namespace std;
using namespace sf;




/*!\class PlatformView
 * \brief Un objet Plateform affichable.
 *
 * Permet d'afficher un objet Platform. Si la plateforme a
 * une hauteur nulle, on ne l'affiche pas (c'est une plateforme
 * invisible).
 */
class PlatformView : public Platform, public MyDrawable
{

	private :


	public :
		
		/*!
	     * \brief Constructeur
	     *
	     * Constructeur de la classe PlatformView.
	     * \param pos : Position de la plate-forme.
	     * \param siz : Taille de la plate-forme.
	     * \param wl : Hauteur du sol de la plate-forme.
	     */
		PlatformView(Int2 pos, Int2 siz, int wl);

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe PlateformView.
	     */
		PlatformView();

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe PlateformView
	     */
		~PlatformView();

		/*!
	     * \brief Affichage
	     *
	     * Affiche l'objet dans une fenêtre de rendu.
	     * \param window : Fenêtre d'affichage
	     */
		void display(RenderWindow* window);

		/*!
	     * \brief Mise à jour du rectangle de selection de la texture.
	     */
		void updateIntRect();
		
};


/** @}*/

#endif
