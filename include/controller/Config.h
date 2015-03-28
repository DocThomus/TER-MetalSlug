#ifndef CONFIG_H
#define CONFIG_H

/*!
 * \file Config.h
 * \author Jules
 * \version 0.1
 */

#include <iostream>

#include <tools/tools.h>

using namespace std;


/*! \class Config
 * \brief Stocke la configuration du jeu
 **/

class Config
{
	public :

		enum Difficulty {EASY,NORMAL,HARD,HARDEST,HARDESTEST};
		Difficulty difficulty;

		bool fullscreen;
		Int2 resolution;

	
	public :

		Config();
		~Config();

		bool loadFromXML(string);  // TODO
		bool saveToXML(string);  // TODO

};


#endif