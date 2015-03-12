#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>

#include <tools/tools.h>

using namespace std;


class Config
{
	public :

		enum Difficulty {EASY,NORMAL,HARD,HARDEST,HARDESTEST};
		Difficulty difficulty;

		bool fullscreen;
		Int2 resolution;
		int luminosity;

	
	public :

		Config();
		~Config();

		bool loadFromXML(string);
		bool saveToXML(string);

};


#endif