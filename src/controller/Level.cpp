#include "controller/Level.h"



Level::Level()
{
	environment = Environment();
}




Level::~Level()
{}



void Level::display(RenderWindow* window)
{
	environment.display(window);
}


void Level::addDecor(Int2 siz, Texture* tex, int z)
{
	environment.addDecor(siz,tex,z);
}


void Level::addPlatform(Int2 pos, Int2 siz, int wl, Texture* tex)
{
	environment.addPlatform(pos,siz,wl,tex);
}