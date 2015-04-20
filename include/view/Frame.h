#ifndef FRAME_H
#define FRAME_H

/*!
 * \file Frame.h
 * \author Jules
 * \brief Déclaration de la classe Frame
 * \addtogroup View
 * @{
 */

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <tools/tools.h>

using namespace std;
using namespace sf;



/*!\class Frame
 * \brief Une frame d'une feuille de sprite.
 *
 * Contient la position et la taille d'une frame dans une 
* texture.
 */
class Frame
{

	private :

		Int2 position; /*!< \brief Position de la frame. */
		Int2 size; /*!< \brief Taille de la frame. */


	public :
		
		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe Frame, initialisée à 0.
	     */
		Frame();

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur de la classe Animation.
	     */
		Frame(Int2 pos, Int2 siz);

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe Animation
	     */
		~Frame();

		/*!
	     * \brief Retourne la position de la frame.
	     */
		Int2 getPosition();

		/*!
	     * \brief Retourne la taille de la frame.
	     */
		Int2 getSize();

};


/** @}*/

#endif
