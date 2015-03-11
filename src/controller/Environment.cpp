#include "controller/Environment.h"



Environment::Environment()
{	
	//platforms.push_back(Platform(Int2(-10,0),Int2(2000,10),0,0));
}



Environment::Environment(string filename)
{
	
}



Environment::~Environment()
{}



void Environment::display(RenderWindow* window)
{
	for (list<DecorView>::iterator it = decors.begin(); it != decors.end(); it++)
		(*it).display(window);
}



void Environment::addDecor(Texture* tex)
{
	DecorView tmp(Int2(0,0),Int2(1366,768),-4);
	tmp.setTexture(tex);
	decors.push_back(tmp);
}