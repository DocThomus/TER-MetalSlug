#ifndef AMMOVIEW_H
#define AMMOVIEW_H

#include <iostream>
#include <vector>
#include <math.h>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <model/Ammo.h>
#include <view/MyDrawable.h>

using namespace std;
using namespace sf;


class AmmoView : public Ammo, public MyDrawable
{

	protected :
		

	public :
		
		AmmoView();
		AmmoView(Ammo);
		~AmmoView();

		virtual void display(RenderWindow* window);

		void initPosition();

};


#endif
