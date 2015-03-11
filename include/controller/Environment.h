#include <iostream>
#include <list>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <view/DecorView.h>
#include <model/Platform.h>

using namespace std;

class Decor;
class Platform;


class Environment
{

	private :

		list<DecorView> decors;
		list<Platform> platforms;
		//list<Destructible> destructibles;
		

	public :

		Environment();
		Environment(string filename);
		~Environment();

		void display(RenderWindow* window);

		void addDecor(Texture* tex);
		
};
