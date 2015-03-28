#include "controller/Config.h"


/**
 * Constructeur
 */
Config::Config()
{
	fullscreen = true;
	resolution = Int2(800,600);
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