#ifndef MYDRAWABLE_H
#define MYDRAWABLE_H

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <view/Animation.h>
#include <view/Frame.h>

using namespace std;
using namespace sf;


class MyDrawable
{

	private :

		vector<Animation> animations;
		int current_anim;


	public :
		
		MyDrawable();
		~MyDrawable();

		virtual void display(RenderWindow* window)=0;

		void addAnimation(Animation a);
		void changeAnimation(int i);
		Frame* getFrame();
		void setNextFrame();

};


#endif
