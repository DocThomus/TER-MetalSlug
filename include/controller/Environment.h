#include <iostream>
#include <list>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <view/DecorView.h>
#include <view/PlatformView.h>

using namespace std;

class Decor;
class Platform;


class Environment
{

	friend class Game;

	private :

		list<DecorView> decors;
		list<PlatformView> platforms;
		//list<Destructible> destructibles;
		

	public :

		Environment();
		Environment(string filename);
		~Environment();

		void display(RenderWindow* window);

		void addDecor(Int2 siz, Texture* tex, int z);
		void addPlatform(Int2 pos, Int2 siz, int wl, Texture* tex=NULL);
		
};
