#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <list>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <model/Level.h>
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

		Level level;
		Player player;
		list<Enemy> enemies;
		list<Ammo> ammo;


	public :

		Game();
		~Game();

		void update(Time dt);
		void display(RenderWindow* window);
		void checkCollisions();

		void setLevel(Level);
		void setPlayer(Player);

};


#endif