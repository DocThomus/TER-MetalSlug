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
#include <controller/Camera.h>
#include <controller/Level.h>
#include <view/Animation.h>
#include <view/Frame.h>
#include <view/PlayerView.h>
#include <view/EnemyView.h>
#include <view/AmmoView.h>
#include <view/WeaponView.h>

using namespace std;
using namespace sf;


class Level;

class Animation;
class PlayerView;
class EnnemyView;


class Game
{
	
	private :

		Config* config;

		Level level;

		View view;
		ObjetPhysique* view_target;

		PlayerView player;
		list<EnemyView*> enemies;
		list<AmmoView*> ammo;

		vector<Texture*> textures;


	public :

		Game();
		~Game();

		void update(Time dt);
		void updateView(int dt);
		void display(RenderWindow* window);
		void checkEvents(RenderWindow* window);
		void checkCollisions();
		bool checkIntersect(ObjetPhysique* obj1, ObjetPhysique* obj2);
		bool checkCollisionTop(ObjetPhysique* obj1, ObjetPhysique* obj2);
		bool checkCollisionBottom(ObjetPhysique* obj1, ObjetPhysique* obj2);
		bool checkCollisionLeft(ObjetPhysique* obj1, ObjetPhysique* obj2);
		bool checkCollisionRight(ObjetPhysique* obj1, ObjetPhysique* obj2);
		void deleteDeadObjects();

		void applyConfig(RenderWindow* window);
		void setConfig(Config* c);
		void init();
		void setLevel(Level);
		void setPlayer(PlayerView);

		void loadLevel();

		vector<Animation*> loadSpriteFromFile(string filename);

};


#endif