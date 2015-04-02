#ifndef ANIMATION_H
#define ANIMATION_H

/*!
 * \file Animation.h
 * \author Jules
 * \brief Déclaration de la classe Animation
 * \addtogroup View
 * @{
 */

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <view/Frame.h>

using namespace std;
using namespace sf;



/*!\class Animation
 * \brief Stockage d'une animation
 *
 * Stocke un ensemble de Frame formant une animation.
 * Trois type d'animations sont possible : 
 * - Animation répétée
 * - Animation non-répétée bloquante (reste bloquée sur la dernière frame)
 * - Animation non-répétée enchaînée (enchaîne sur une autre animaition)
 */
class Animation
{

	private :

		vector<Frame> frames; /*!< \brief Liste des frames de l'animation. */
		int current; /*!< \brief Frame courante lue par l'animation. */
		int speed; /*!< \brief Temps entre chaque frame en ms. */

		bool repeat; /*!< \brief Indique si l'animation doit se répèter ou non. */
		int  next_anim; /*!< \brief Indique l'animation a lire après celle-ci si repeat=true. */


	public :
		
		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe Animation, construit une animation sans aucune frame.
	     */
		Animation();

		/*!
	     * \brief Constructeur
	     *
	     * Construuit une animation contenant les frames passées en paramètre.
	     * \param v : vecteur de frames à ajouter à l'animation
	     */
		Animation(vector<Frame> v);

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe Animation
	     */
		~Animation();

		/*!
	     * \brief Retourne le nombre de frames de l'animation.
	     */
		int getNbFrames();

		/*!
	     * \brief Ajout d'une frame à l'animation
	     */
		void addFrame(Frame f);

		/*!
	     * \brief Frame suivante
	     *
	     * Indique à l'animation qu'elle doit changer de frame.
	     */
		bool setNextFrame();

		/*!
	     * \brief Changement manuel de frame.
	     */
		void changeFrame(int i);

		/*!
	     * \brief Redémarre l'animation.
	     */
		void reset();

		/*!
	     * \brief Définit si l'animation se répète ou non.
	     */
		void setRepeat(bool r);

		/*!
	     * \brief Définit l'indice de l'animation à lire ensuite.
	     */
		void setNextAnim(int i);

		/*!
	     * \brief Définit la vitesse de lecture de l'animation.
	     */
		void setSpeed(int s);

		/*!
	     * \brief Renvoie l'indice de l'animation à lire ensuite.
	     */
		int getNextAnim();

		/*!
	     * \brief Renvoie la vitesse de lesture de l'animation.
	     */
		int getSpeed();

		/*!
	     * \brief Renvoie la frame courante de l'application.
	     */
		Frame* getFrame();
		

};


/** @}*/

#endif
