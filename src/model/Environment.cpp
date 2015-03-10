#include "model/Environment.h"



Environment::Environment()
{
	decors.push_back(Decor(Int2(-10,0),Int2(2000,600),-4));
	platforms.push_back(Platform(Int2(-10,0),Int2(2000,10),0,0));
}



Environment::Environment(string filename)
{
	
}



Environment::~Environment()
{}

