#ifndef XMLTOOLS_H
#define XMLTOOLS_H

/*!
 * \file XMLtools.h
 * \author Jules
 * \brief Déclaration des outils XML
 * \addtogroup Tools 
 * @{
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

#include <SFML/Graphics.hpp>

#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_print.hpp"
#include "rapidxml/rapidxml_utils.hpp"

#include "tools.h"

using namespace std;
using namespace sf;
using namespace rapidxml;

class Config;
class Environment;


/***
* Fonction de sauvegarde et de chargement de données au format XML
***/


/* SPRITE MAP */
bool buildSpriteMap(string filename,vector<Int2>animations, vector<Int2> positions, vector<Int2> tailles);
bool loadSpriteMap(string filename,vector<Int2>*animations, vector<Int2>* positions, vector<Int2>* tailles);

/* LEVEL */
bool loadLevelXML(string filename, Config* conf, Environment* env, vector<Texture*>* tex);



/** @}*/

#endif