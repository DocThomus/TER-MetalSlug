#ifndef PLATFORMVIEW_H
#define PLATFORMVIEW_H

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <model/Platform.h>
#include <view/MyDrawable.h>

using namespace std;
using namespace sf;


class PlatformView : public Platform, public MyDrawable
{

	private :


	public :
		
		PlatformView(Int2 pos, Int2 siz, int wl);
		PlatformView();
		~PlatformView();

		void display(RenderWindow* window);

};


#endif
