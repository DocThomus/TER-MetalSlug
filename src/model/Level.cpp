#include "model/Level.h"



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

