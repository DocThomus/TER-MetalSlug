#ifndef MENU_H
#define MENU_H

/*!
 * \file Menu.h
 * \author Jules
 * \brief Déclaration de la classe Menu
 * \addtogroup Controller 
 * @{
 */
 
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;
 
 class Menu
 {
 	private :
 		int selectedItemIndex;
 		Font font;
 		vector<Text> menu;
 	
 	public :
 	
 		/*!
	     * \enum ScreenPositions
	     * \brief Les cinq positions possibles
	     */
		enum ScreenPositions
		{
			CENTER, TOPLEFTHANDCORNER, BOTTOMLEFTHANDCORNER, BOTTOMRIGHTHANDCORNER, TOPRIGHTHANDCORNER
		};
 		
 		/*!
	     * \brief Constructeur
	     *
	     * Constructeur de la classe Game
	     */
 		Menu();
 		
 		/*!
	     * \brief Constructeur
	     *
	     * Constructeur de la classe Game
	     * \param vectItems : Vector contenant les items sous forme de String
	     * \param window : La fenêtre afin de renseigner taille et vue
	     * \param window : La fenêtre afin de renseigner taille et vue
	     */
 		Menu(vector<String> vectItems, RenderWindow* window, const Font& f, ScreenPositions screenPosition=CENTER, unsigned int size=30);
 		
 		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe Game
	     */
 		~Menu();
 		
 		/*!
	     * \brief Setter
	     *
	     * Modification du texte de l'item
	     * \param index : Indice de l'item
	     * \param texte : Nouveau texte de l'item
	     */
 		void setTextItem(int index, String texte);
 		
 		/*!
	     * \brief Sélection de l'item supérieur
	     *
	     * Sélection de l'item du dessus et modifie couleur du texte de l'item sélectionné
	     */
 		void moveUp();
 		
 		/*!
	     * \brief Sélection de l'item inférieur
	     *
	     * Sélection de l'item du dessous et modifie couleur du texte de l'item sélectionné
	     */
 		void moveDown();
 		
 		/*!
	     * \brief Item sélectionné
	     *
	     * Retourne l'indice de l'index sélectionné
	     */
 		int getSelectedItemIndex();
 		
 		/*!
	     * \brief Affichage
	     *
	     * Affiche l'objet dans une fenêtre de rendu.
	     * \param window : Fenêtre d'affichage
	     */
 		void draw(RenderWindow* window);
 
 };
 
 /** @}*/

#endif
