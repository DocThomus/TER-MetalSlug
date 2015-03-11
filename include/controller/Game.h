#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <list>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <controller/Config.h>
#include <controller/Level.h>
#include <model/Player.h>
#include <model/Enemy.h>

using namespace std;
using namespace sf;

class Level;
class Player;
class Enemy;



class Game
{
	
	private :

		Config* config;

		Level level;
		Player player;
		list<Enemy> enemies;
		list<Ammo> ammo;

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
		void setLevel(Level);
		void setPlayer(Player);

		void loadLevel();

};


#endif