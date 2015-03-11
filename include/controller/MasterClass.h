#ifndef MASTERCLASS_H
#define MASTERCLASS_H

#include <iostream>
#include <list>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <controller/Game.h>
#include <controller/Config.h>

using namespace std;
using namespace sf;

class Game;
class Config;


class MasterClass
{
	
	private :

		Game game;
		Config config;

		RenderWindow* window;


	public :

		MasterClass();
		~MasterClass();

		void initGame();
		void playGame();


};


#endif