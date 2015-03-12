#ifndef FRAME_H
#define FRAME_H

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <tools/tools.h>

using namespace std;
using namespace sf;


class Frame
{

	private :

		Int2 position;
		Int2 size;


	public :
		
		Frame();
		Frame(Int2 pos, Int2 siz);
		~Frame();

		Int2 getPosition();
		Int2 getSize();

};


#endif
