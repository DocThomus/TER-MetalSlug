#ifndef CONFIG_H
#define CONFIG_H

/*!
 * \file Config.h
 * \author Jules
 * \brief Déclaration de la classe Config
 * \addtogroup Controller 
 * @{
 */

#include <iostream>

#include <tools/tools.h>

using namespace std;


/*!\class Config
 * \brief Stocke la configuration du jeu
 */
class Config
{
	public :

		/*!\enum Difficulty
		 * \brief Enumération des difficultés 
		 */
		enum Difficulty {EASY,NORMAL,HARD,HARDEST,HARDESTEST};
		Difficulty difficulty; /*!< \brief Difficulté du jeu */

		bool fullscreen; /*!< \brief Vrai si le jeu est en plein écran */
		Int2 resolution; /*!< \brief Résolution de l'écran */

	
	public :

		/*!
	     *  \brief Constructeur
	     *
	     *  Constructeur par défaut de la classe Config
	     */
		Config();

		/*!
	     *  \brief Destructeur
	     *
	     *  Destructeur de la classe Config
	     */
		~Config();


		/*!
	     *  \brief Loader
	     *
	     *  Charger une configuration à partir d'un fichier XML.
	     *  \param filename : nom du fichier XML
	     */
		bool loadFromXML(string filename);  // TODO

		/*!
	     *  \brief Saver
	     *
	     *  Enregistre une configuration dans un fichier XML.
	     *  \param filename : nom du fichier XML
	     */
		bool saveToXML(string filename);  // TODO

};

/** @}*/

#endif