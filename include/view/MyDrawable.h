#ifndef MYDRAWABLE_H
#define MYDRAWABLE_H

#include <iostream>
#include <vector>

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

	protected :

		RectangleShape body;
		vector<Animation*> animations;
		int current_anim;
		Texture* tex;

	public :
		
		MyDrawable();
		~MyDrawable();

		virtual void display(RenderWindow* window)=0;

		void reset();
		void addAnimation(Animation* a);
		void addAnimations(vector<Animation*> v);
		bool changeAnimation(int i, bool repeat=true, int next=0);
		void changeFrame(int i);
		Frame* getFrame();
		void setNextFrame(int n=1);
		void setTexture(Texture* tex);
		virtual void updateIntRect();

};


#endif
