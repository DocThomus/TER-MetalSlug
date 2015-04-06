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


void Level::loadFromFile(string filename, Config* config)
{
	if(!loadLevelXML(filename,config,&environment,&events,&textures,&musics))
	{
		cerr << "Chargement du niveau : le fichier " << filename << " n'existe pas." << endl;
		exit(-1);
	}

	if(musics.size() > 0)
		playMusic(1);
}


void Level::addDecor(Int2 siz, Texture* tex, int z)
{
	environment.addDecor(siz,tex,z);
}


void Level::addPlatform(Int2 pos, Int2 siz, int wl, Texture* tex)
{
	environment.addPlatform(pos,siz,wl,tex);
}


void Level::playMusic(int id)
{
	for(unsigned int i=0; i<musics.size(); ++i)
		musics[i]->stop();

	if(int(musics.size()) >= id)
		musics[id]->play();
}