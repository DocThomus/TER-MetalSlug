#ifndef EVENTGAME_H
#define EVENTGAME_H

/*!
 * \file EventGame.h
 * \author Jules
 * \brief Déclaration de la classe EventGame
 * \addtogroup Controller 
 * @{
 */

#include <iostream>
#include <sstream>

using namespace std;

class Game;


/*!\class EventGame
 * \brief Un événement à déclencher à une position du niveau.
 */
class EventGame
{

	protected :

		int position; /*!< \brief Position à laquelle l'événement doit être déclenché. */


	public :


		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe EventGame
	     */
		EventGame();

		/*!
	     * \brief Constructeur
	     *
	     * Construit un événement pour une position donnée.
	     */
		EventGame(int pos);

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe EventGame
	     */
		~EventGame();

		/*!
		 * \brief Retourne la position de l'événement.
		 */
		int getPosition();

		/*!
		 * \brief Déclenche l'événement dans une partie.
		 * \param g : Jeu auquel appliquer l'événement.
		 */
		virtual void trigger(Game* g) = 0;

};



/** @}*/

#endif