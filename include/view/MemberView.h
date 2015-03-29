#ifndef MEMBERVIEW_H
#define MEMBERVIEW_H

/*!
 * \file MemberView.h
 * \author Jules
 * \brief Déclaration de la classe MemberView
 * \addtogroup View
 * @{
 */

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <view/MyDrawable.h>

using namespace std;
using namespace sf;


/***
* MemberView -> MyDrawable
* ===========================================================
* Affichage d'un membre attaché à un Character.
* EXEMPLE : les jambes du player sont un MemberView car
* séparées du corps.
***/


/*!\class MemberView
 * \brief Un membre d'un character destiné à être affiché.
 */
class MemberView : public MyDrawable
{

	public :
		
		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe MemberView
	     */
		MemberView();

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe MemberView
	     */
		~MemberView();

		/*!
	     * \brief Affichage
	     *
	     * Affiche l'objet dans une fenêtre de rendu.
	     * \param window : Fenêtre d'affichage
	     */
		virtual void display(RenderWindow* window);

		/*!
	     * \brief Définit la taille du membre.
	     */
		void setSize(Int2 siz);

		/*!
	     * \brief Définit la position du membre.
	     */
		void setPosition(Int2 pos);

		/*!
	     * \brief Retourne la taille du membre.
	     */
		Vector2f getSize();

		/*!
	     * \brief Retourne la position du membre.
	     */
		Vector2f getPosition();

		/*!
	     * \brief Définit la zone de la texture à appliquer au rectangle.
	     */
		void setTextureRect(IntRect);

};


/** @}*/

#endif
