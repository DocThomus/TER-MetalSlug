#ifndef ANIMATION_H
#define ANIMATION_H

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <view/Frame.h>

using namespace std;
using namespace sf;


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

		void addFrame(Frame* f);
		bool setNextFrame();
		void changeFrame(int i);
		void reset();

		void setRepeat(bool r);
		void setNextAnim(int i);
		int getNextAnim();

		Frame* getFrame();
		

};


#endif
