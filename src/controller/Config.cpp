#include "controller/Config.h"


/**
 * Constructeur
 */
Config::Config()
{
	musicsVolume = 50;
	soundEffectsVolume = 50;
	fullscreen = true;
	resolution = Int2(800,600);
	vsync = true;
}



Config::~Config()
{}



bool Config::loadFromXML(string filename)
{
	return false;
}



bool Config::saveToXML(string filename)
{
	return false;
}
