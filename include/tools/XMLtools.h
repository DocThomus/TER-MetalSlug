#ifndef XMLTOOLS_H
#define XMLTOOLS_H

/*!
 * \file XMLtools.h
 * \author Jules
 * \brief Fonction de sauvegarde et de chargement de données au format XML
 * \addtogroup Tools 
 * @{
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
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
class EventGame;
class EventEnemy;


/***
* Fonction de sauvegarde et de chargement de données au format XML
***/


/* === SPRITE MAP === */

/*!
 * \brief Construire spritemap
 *
 * Génère un fichier XML contenant le mapping d'une feuille de sprite.
 * \param filename : Nom du fichier à génèrer.
 * \param animations : Liste des animations par indices.
 * \param positions : Liste des positions des frames.
 * \param tailles : Liste des tailles des frames.
 */
bool buildSpriteMap(string filename, vector<Int2>animations, vector<Int2> positions, vector<Int2> tailles);

/*!
 * \brief Charger spritemap
 *
 * Charge le mapping d'une feuille de sprite à partir d'un fichier XML.
 * \param filename : Nom du fichier à charger.
 * \param animations : Vecteur d'animations par indice à remplir.
 * \param positions : Vecteur de positions à remplir.
 * \param tailles : Vecteur de tailles à remplir.
 */
bool loadSpriteMap(string filename, vector<Int2>*animations, vector<Int2>* positions, vector<Int2>* tailles);




/* === LEVEL === */

/*!
 * \brief Chargement d'un Level
 *
 * Charge le contenu d'un niveau décrit dans un fichier xml
 * \param filename : Nom du fichier à charger.
 * \param conf : Configuration de la fenêtre à respecter
 * \param env : Environnement à complèter
 * \param events : Liste d'événements à remplir
 * \param tex : Conteneur pour les textures
 */
bool loadLevelXML(string filename, Config* conf, Environment* env, list<EventGame*>* events, vector<Texture*>* tex);



/** @}*/

#endif