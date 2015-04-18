#include "controller/Level.h"



Level::Level()
{
	environment = Environment();
}




Level::~Level()
{
	for(unsigned int i = 0; i < musics.size(); i++)
		delete(musics[i]);
		
	for(unsigned int i = 0; i < textures.size(); i++)
		delete(textures[i]);
}



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
	if(musics.size() > 0)
	{
		for(unsigned int i=0; i<musics.size(); ++i)
			musics[i]->stop();

		if(int(musics.size()) >= id)
			musics[id]->play();
	}
}

void Level::setVolume(float volume)
{
	if(musics.size() > 0)
	{
		for(unsigned int i=0; i<musics.size(); ++i)
			musics[i]->setVolume(volume);
	}
}

void Level::resume()
{
	for(unsigned int i=0; i<musics.size(); ++i)
	{
		if(musics[i]->getStatus() == SoundSource::Paused)
			musics[i]->play();
	}
}

void Level::pause()
{
	for(unsigned int i=0; i<musics.size(); ++i)
	{
		if(musics[i]->getStatus() == SoundSource::Playing)
			musics[i]->pause();
	}
}
