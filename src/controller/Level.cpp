#include "controller/Level.h"



Level::Level()
{
	environment = Environment();
}



Level::Level(string filename)
{
		environment = Environment(filename);
}



Level::~Level()
{}



void Level::display(RenderWindow* window)
{
	environment.display(window);
}


void Level::addDecor(Texture* tex)
{
	environment.addDecor(tex);
}


void Level::addPlatform(Int2 pos, Int2 siz, int z, int wl, Texture* tex)
{
	environment.addPlatform(pos,siz,z,wl,tex);
}