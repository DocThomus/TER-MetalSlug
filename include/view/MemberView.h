#ifndef MEMBERVIEW_H
#define MEMBERVIEW_H

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <view/MyDrawable.h>

using namespace std;
using namespace sf;


class MemberView : public MyDrawable
{

	public :
		
		MemberView();
		~MemberView();

		virtual void display(RenderWindow* window);

		void setSize(Int2 siz);
		void setPosition(Int2 pos);

		Vector2f getSize();
		Vector2f getPosition();

		void setTextureRect(IntRect);

};

#endif
