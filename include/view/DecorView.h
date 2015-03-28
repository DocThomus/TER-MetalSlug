#ifndef DECORVIEW_H
#define DECORVIEW_H

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <model/Decor.h>
#include <view/MyDrawable.h>

using namespace std;
using namespace sf;


class DecorView : public Decor, public MyDrawable
{

	private :

		int tex_x;


	public :
		
		DecorView(Int2 pos, Int2 siz, int z);
		DecorView();
		~DecorView();

		void display(RenderWindow* window);
		void updateIntRect();

		void animate(int x);

};


#endif
