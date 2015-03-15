#ifndef WEAPONVIEW_H
#define WEAPONVIEW_H

#include <iostream>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <model/Weapon.h>
#include <view/PlayerView.h>

using namespace std;
using namespace sf;

class PlayerView;

class WeaponView : public Weapon
{

	protected :
		
		static vector<Sound*> sounds;


	public :
		
		WeaponView();
		WeaponView(PlayerView* p, TypeWeapon type, int max_mun);
		~WeaponView();

		static vector<Sound*> loadSounds();
		
		void shootSound();

};


#endif
