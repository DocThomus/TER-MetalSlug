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


/***
* Animation
* ===========================================================
* Stocke un ensemble de Frame.
* Trois type d'animations sont possible : 
* - Animation répétée
* - Animation non-répétée bloquante (reste bloquée sur la dernière frame)
* - Animation non-répétée enchaînée (enchaîne sur une autre animaition)
***/


class Animation
{

	private :

		vector<Frame*> frames;
		int current;

		bool repeat;
		int  next_anim;


	public :
		
		Animation();
		Animation(vector<Frame*> v);
		~Animation();

		int getNbFrames();

		void addFrame(Frame* f);
		bool setNextFrame();
		void changeFrame(int i);
		void reset();

		void setRepeat(bool r);
		void setNextAnim(int i);
		int getNextAnim();

		Frame* getFrame();
		

};


/** @}*/

#endif
