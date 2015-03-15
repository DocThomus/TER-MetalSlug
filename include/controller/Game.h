#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <list>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <tools/XMLtools.h>

#include <controller/Config.h>
#include <controller/Level.h>
#include <model/Enemy.h>
#include <view/Animation.h>
#include <view/Frame.h>
#include <view/PlayerView.h>
#include <view/AmmoView.h>
#include <view/WeaponView.h>

using namespace std;
using namespace sf;


class Level;
class Enemy;

class Animation;
class PlayerView;


class Game
{
	
	private :

		Config* config;

		Level level;
		PlayerView player;
		list<Enemy> enemies;
		list<AmmoView*> ammo;

		vector<Texture*> textures;


	public :

		Game();
		~Game();

		void update(Time dt);
		void display(RenderWindow* window);
		void checkEvents(RenderWindow* window);
		void checkCollisions();

		void applyConfig(RenderWindow* window);
		void setConfig(Config* c);
		void init();
		void setLevel(Level);
		void setPlayer(PlayerView);

		void loadLevel();

		vector<Animation*> loadSpriteFromFile(string filename);

};


#endif