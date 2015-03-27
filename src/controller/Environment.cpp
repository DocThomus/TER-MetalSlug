#include "controller/Environment.h"



Environment::Environment()
{	

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

	for (list<PlatformView>::iterator it = platforms.begin(); it != platforms.end(); it++)
		(*it).display(window);
}



void Environment::addDecor(Texture* tex)
{
	DecorView tmp(Int2(0,0),Int2(1366*10,768),-4);
	tmp.setTexture(tex,Bool2(true,false));
	decors.push_back(tmp);
}


void Environment::addPlatform(Int2 pos, Int2 siz, int wl, Texture* tex)
{
	PlatformView tmp(pos,siz,wl);
	if(tex != NULL)
		tmp.setTexture(tex,Bool2(true,true));
	platforms.push_back(tmp);
}