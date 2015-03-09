#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <list>

#include <model/Player.h>
#include <model/Enemy.h>

using namespace std;

class Player;
class Enemy;



class Game
{
	
	private :

		//Level level;
		Player player;
		list<Enemy> enemies;
		list<Ammo> ammo;


	public :

		Game();
		~Game();

		void animate();
		void display();
		void checkCollisions();

		void setPlayer(Player);

};


#endif