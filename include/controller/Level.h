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

	private :

		Environment environment;

	public :

		Level();
		Level(string filename);
		~Level();

		void display(RenderWindow* window);

		void addDecor(Texture* tex);
};
