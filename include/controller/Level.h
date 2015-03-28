#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <controller/Environment.h>

using namespace std;

class Environment;

class Level
{

	friend class Game;

	private :

		Environment environment;

	public :

		Level();
		Level(string filename);
		~Level();

		void display(RenderWindow* window);

		void addDecor(Int2 siz, Texture* tex, int z=0);
		void addPlatform(Int2 pos, Int2 siz, int wl=0, Texture* tex=NULL);
};
