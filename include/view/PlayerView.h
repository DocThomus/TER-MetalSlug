#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <model/Player.h>
#include <view/MyDrawable.h>
#include <view/AmmoView.h>
#include <view/WeaponView.h>

using namespace std;
using namespace sf;

class WeaponView;


class PlayerView : public Player, public MyDrawable
{

	private :


	public :
		
		PlayerView(Int2 pos, Int2 siz, int z, int m, int max_h);
		PlayerView();
		~PlayerView();

		void display(RenderWindow* window);

		void animate(int dt);

		void updateIntRect();

		void walk(int way);

		virtual void shoot(list<AmmoView*>* ammos, Int2 angle = Int2(1,0), Texture* tex=NULL);
		void shootSound();
};


#endif
