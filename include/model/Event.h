#ifndef EVENT_H
#define EVENT_H

/*!
 * \file Event.h
 * \author Jules
 * \brief Déclaration de la classe Event
 * \addtogroup Model 
 * @{
 */

#include <iostream>
#include <sstream>


using namespace std;



/*!\class Event
 * \brief Un événement à déclencher à une position du niveau.
 */
class Event
{

	protected :

		int position; /*!< \brief Position à laquelle l'événement doit être déclenché. */


	public :


		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe Event
	     */
		Event();

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe Event
	     */
		~Event();

		/*!
		 * \brief Retourne la position de l'événement.
		 */
		int getPosition();

		/*!
		 * \brief Déclenche l'événement.
		 */
		virtual void trigger() = 0;

};



/** @}*/

#endif