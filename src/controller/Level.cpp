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