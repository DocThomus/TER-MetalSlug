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


	public :
		
		Animation();
		Animation(vector<Frame*> v);
		~Animation();

		void addFrame(Frame* f);
		void setNextFrame();

		Frame* getFrame();
		

};


#endif
