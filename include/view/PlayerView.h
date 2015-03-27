#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <tools/tools.h>

#include <model/Player.h>
#include <view/MyDrawable.h>
#include <view/AmmoView.h>
#include <view/WeaponView.h>
#include <view/MemberView.h>

using namespace std;
using namespace sf;

class WeaponView;



class PlayerView : public Player, public MyDrawable
{
	public :

		enum PlayerAnimationsBody
		{
			PISTOLRUN, PISTOLSHOOT, PISTOLSHOOTUP, PISTOLKNEE, PISTOLKNEESHOOT
		};

		enum PlayerAnimationsLegs
		{
			STAND, RUN, SLOW, FALL, JUMP
		};


	private :


	public :

		MemberView legs;

		
		PlayerView(Int2 pos, Int2 siz, int m, int max_h);
		PlayerView();
		~PlayerView();

		void init();

		void display(RenderWindow* window);
		void animate(int dt);
		void updateIntRect();

		void walk(int way);
		void kneel(bool);
		virtual void shoot(list<AmmoView*>* ammos, Int2 angle = Int2(1,0)/*, Texture* tex=NULL*/);
};


#endif
